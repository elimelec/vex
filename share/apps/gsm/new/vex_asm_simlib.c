#include <stdio.h>
#include <stdarg.h>

#define MAX_32 ((int)0x7fffffffL)
#define MIN_32 ((int)0x80000000L)
#define MAX_16 ((short)0x7fff)
#define MIN_16 ((short)0x8000)

#define saturate(x,v) ( \
    v = ((int)(x) != (short)(x)), \
        (((int)(x) > (short)(x)) ? MAX_16 : \
        ((int)(x) < (short)(x)) ? MIN_16 : (short)(x)) \
)

#define __VEX_LMAC_ASMOP  0x01
#define __VEX_LMSU_ASMOP  0x02
#define __VEX_LMULT_ASMOP 0x03
#define __VEX_LADD_ASMOP  0x04
#define __VEX_LSUB_ASMOP  0x05
#define __VEX_LSHL_ASMOP  0x06
#define __VEX_LSHR_ASMOP  0x07
#define __VEX_MULT_ASMOP  0x08

typedef unsigned int                       __vexasm1;
typedef struct {unsigned int n0,n1;}       __vexasm2;
typedef struct {unsigned int n0,n1,n2;}    __vexasm3;
typedef struct {unsigned int n0,n1,n2,n3;} __vexasm4;


static void sim_asm_LMAC(int*,int*,int,int,int);
static void sim_asm_LMSU(int*,int*,int,int,int);
static void sim_asm_LMULT(int*,int*,int,int);
static void sim_asm_LADD(int*,int*,int,int);
static void sim_asm_LSUB(int*,int*,int,int);
static void sim_asm_LSHL(int*,int*,int,int);
static void sim_asm_LSHR(int*,int*,int,int);
static void sim_asm_MULT(int*,int*,int,int);

extern __vexasm1 sim_asm_op1(unsigned int opcode, ...)
{
    va_list ap;
    unsigned int t, s1, s2;
    va_start(ap, opcode);
    switch (opcode) {
    default:
	_linux_fprintf(stderr, 
	    "Error: ASM opcode %d not supported\n", opcode);
	_linux_exit(1);
    }
    va_end(ap);
    return t;
}

extern __vexasm2 sim_asm_op2(unsigned int opcode, ...)
{
    va_list ap;
    __vexasm2 t;
    unsigned int s1, s2, s3;
    va_start(ap, opcode);
    switch (opcode) {

    case __VEX_LMAC_ASMOP:
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	s3 = va_arg(ap, unsigned int);
	sim_asm_LMAC(&(t.n0),&(t.n1),s1,s2,s3);
	break;

    case __VEX_LMSU_ASMOP:
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	s3 = va_arg(ap, unsigned int);
	sim_asm_LMSU(&(t.n0),&(t.n1),s1,s2,s3);
	break;

    case __VEX_LMULT_ASMOP:
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	sim_asm_LMULT(&(t.n0),&(t.n1),s1,s2);
	break;

    case __VEX_LADD_ASMOP:
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	sim_asm_LADD(&(t.n0),&(t.n1),s1,s2);
	break;

    case __VEX_LSUB_ASMOP:
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	sim_asm_LSUB(&(t.n0),&(t.n1),s1,s2);
	break;

    case __VEX_LSHL_ASMOP:
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	sim_asm_LSHL(&(t.n0),&(t.n1),s1,s2);
	break;

    case __VEX_LSHR_ASMOP:
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	sim_asm_LSHR(&(t.n0),&(t.n1),s1,s2);
	break;

    case __VEX_MULT_ASMOP:
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	sim_asm_MULT(&(t.n0),&(t.n1),s1,s2);
	break;

    default:
	_linux_fprintf(stderr, 
	    "Error: ASM opcode %d not supported\n", opcode);
	_linux_exit(1);
    }
    va_end(ap);
    return t;
}

/*
 * Implementations
 */

static void sim_asm_LMAC(int *outp, int *ovfp, int var3, int var2, int var1)
{
    int product, var_out;
    sim_asm_LMULT(&product, ovfp, var1, var2);
    sim_asm_LADD(outp, ovfp, var3, product);
}

static void sim_asm_LMSU(int *outp, int *ovfp, int var3, int var2, int var1)
{
    int product, var_out;
    sim_asm_LMULT(&product, ovfp, var1, var2);
    sim_asm_LSUB(outp, ovfp, var3, product);
}

static void sim_asm_LMULT(int *outp, int *ovfp, int var1, int var2)
{
    int var_out = var1 * var2;
    int v = *ovfp;

    if (var_out != 0x40000000L) {
	var_out *= 2;
    }
    else {
	v = 1;
	var_out = MAX_32;
    }
    *ovfp = v;
    *outp = var_out;
}

static void sim_asm_LADD(int *outp, int *ovfp, int var1, int var2)
{
    int var_out = var1 + var2;
    int v = *ovfp;
    if (((var1 ^ var2) & MIN_32) == 0) {
	if ((var_out ^ var1) & MIN_32) {
	    var_out = (var1 < 0) ? MIN_32 : MAX_32;
	    v = 1;
	}
    }
    *ovfp = v;
    *outp = var_out;
}

static void sim_asm_LSUB(int *outp, int *ovfp, int var1, int var2)
{
    int var_out = var1 - var2;
    int v = *ovfp;
    if (((var1 ^ var2) & MIN_32) != 0) {
	if ((var_out ^ var1) & MIN_32) {
	    var_out = (var1 < 0L) ? MIN_32 : MAX_32;
	    v = 1;
	}
    }
    *ovfp = v;
    *outp = var_out;
}

static void sim_asm_LSHL(int *outp, int *ovfp, int var1, int var2)
{
    int var_out = 0;
    int v = 0;
    if (var2 <= 0) {
	int nvar2 = -var2;
	if (nvar2 >= 31) {
	    var_out = (var1 < 0L) ? -1 : 0;
	}
	else {
	    if (var1 < 0) {
		var_out = ~((~var1) >> nvar2);
	    }
	    else {
		var_out = var1 >> nvar2;
	    }
	}
    }
    else {
	for (; var2 > 0; var2--) {
	    if (var1 > (int) 0X3fffffffL) {
		v = 1;
		var_out = MAX_32;
		break;
	    }
	    else {
		if (var1 < (int) 0xc0000000L) {
		    v = 1;
		    var_out = MIN_32;
		    break;
		}
	    }
	    var1 *= 2;
	    var_out = var1;
	}
    }
    *ovfp = v;
    *outp = var_out;
}

static void sim_asm_LSHR(int *outp, int *ovfp, int var1, int var2)
{
    int var_out = 0;
    int v = 0;
    if (var2 < 0) {
	int nvar2 = -var2;
	for (; nvar2 > 0; nvar2--) {
	    if (var1 > (int) 0X3fffffffL) {
		v = 1;
		var_out = MAX_32;
		break;
	    }
	    else {
		if (var1 < (int) 0xc0000000L) {
		    v = 1;
		    var_out = MIN_32;
		    break;
		}
	    }
	    var1 *= 2;
	    var_out = var1;
	}
    }
    else {
	if (var2 >= 31) {
	    var_out = (var1 < 0L) ? -1 : 0;
	}
	else {
	    if (var1 < 0) {
		var_out = ~((~var1) >> var2);
	    }
	    else {
		var_out = var1 >> var2;
	    }
	}
    }
    *ovfp |= v;
    *outp  = var_out;
}

static void sim_asm_MULT(int *outp, int *ovfp, int var1, int var2)
{
    int var_out, v;
    int L_product = var1 * var2;
    L_product = (L_product & (int) 0xffff8000L) >> 15;
    if (L_product & (int) 0x00010000L)
        L_product = L_product | (int) 0xffff0000L;
    var_out = saturate(L_product, v);
    *ovfp = v;
    *outp = var_out;
}

