/**
*** Copyright (C) 2001-2007 Hewlett-Packard Company.
**/

/**
*** This file shows how to create simple 
*** implementations of _asm*() extensions.
**/

/* $Id */

#include <stdio.h>
#include <stdarg.h>

#include "asmlib.h"

typedef unsigned int                       __vexasm1;
typedef struct {unsigned int n0,n1;}       __vexasm2;
typedef struct {unsigned int n0,n1,n2;}    __vexasm3;
typedef struct {unsigned int n0,n1,n2,n3;} __vexasm4;

extern __vexasm2 sim_asm_op2(unsigned int opcode, ...)
{
    va_list ap;
    __vexasm2 t;
    unsigned int ex, eym, ey, eyp;
    va_start(ap, opcode);
    switch (opcode) {
    case 0x1: /* Floyd-Steinberg dithering */ {
	int ex = va_arg(ap, int);
	int eym = va_arg(ap, int);
	int ey = va_arg(ap, int);
	int eyp = va_arg(ap, int);
        _FSDITHER(t.n0, ex,eym,ey,eyp);
	t.n1 = 0;
	break;
    }

    default:
	_linux_fprintf(stderr, 
	    "Error: opcode %d not supported\n", opcode);
	_linux_exit(1);
    }
    return t;
}

extern __vexasm3 sim_asm_op3(unsigned int opcode, ...)
{
    va_list ap;
    __vexasm3 t;
    va_start(ap, opcode);
    switch (opcode) {
    case 0x3: { /* interpolation */
        int x;
	int p0  = va_arg(ap, int);
	int p1  = va_arg(ap, int);
	int p2  = va_arg(ap, int);
	int p3  = va_arg(ap, int);
	int p4  = va_arg(ap, int);
        _CSC2(x, p0,p1,p2,p3,p4);
	t.n0 = x;
	t.n1 = 0;
	t.n2 = 0;
	break;
    }

    default:
	_linux_fprintf(stderr, 
	    "Error: opcode %d not supported\n", opcode);
	_linux_exit(1);
    }
    return t;
}


extern __vexasm4 sim_asm_op4(unsigned int opcode, ...)
{
    va_list ap;
    __vexasm4 t;
    va_start(ap, opcode);
    switch (opcode) {
    case 0x2: /* 3D interpolation lookup */ {
        int p1,p2,p3,p4;
	int r  = va_arg(ap, int);
	int g  = va_arg(ap, int);
	int b  = va_arg(ap, int);
	int p0 = va_arg(ap, int);
	int d1 = va_arg(ap, int);
	int d2 = va_arg(ap, int);
        _CSC1(p1,p2,p3,p4, r,g,b,p0,d1,d2);
	t.n0 = p1;
	t.n1 = p2;
	t.n2 = p3;
	t.n3 = p4;
	break;
    }

    default:
	_linux_fprintf(stderr, 
	    "Error: opcode %d not supported\n", opcode);
	_linux_exit(1);
    }
    return t;
}

