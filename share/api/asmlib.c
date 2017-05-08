/**
*** Copyright (C) 2001-2002 Hewlett-Packard Company.
**/

/**
*** This file shows how to create simple 
*** implementations of _asm*() extensions.
**/

/* $Id: asmlib.c,v 1.4 2007/02/13 14:11:18 frb Exp $ */

#include <stdio.h>
#include <stdarg.h>

typedef unsigned int                       __vexasm1;
typedef struct {unsigned int n0,n1;}       __vexasm2;
typedef struct {unsigned int n0,n1,n2;}    __vexasm3;
typedef struct {unsigned int n0,n1,n2,n3;} __vexasm4;


extern __vexasm1 sim_asm_op1(unsigned int opcode, ...)
{
    va_list ap;
    unsigned int t, s1, s2;
    va_start(ap, opcode);
    switch (opcode) {
    case 0x1:			/* AVG(s1,s2) */
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	t = (s1 + s2) / 2;
	break;

    case 0x2:			/* COUNT_ONES(s1) */
	s1 = va_arg(ap, unsigned int);
        s1 = s1 - ((s1 >> 1) & 0x55555555);
        s1 = (s1 & 0x33333333) + ((s1 >> 2) & 0x33333333);
        t =  ((s1 + (s1 >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
	break;

    default:
	_linux_fprintf(stderr, 
	    "Error: opcode %d not supported\n", opcode);
	_linux_exit(1);
    }
    return t;
}

extern __vexasm2 sim_asm_op2(unsigned int opcode, ...)
{
    va_list ap;
    __vexasm2 t;
    unsigned int s1, s2;
    va_start(ap, opcode);
    switch (opcode) {
    case 0x2:			/* ADDSUB(s1,s2) */
	s1 = va_arg(ap, unsigned int);
	s2 = va_arg(ap, unsigned int);
	t.n0 = (s1 + s2);
	t.n1 = (s1 - s2);
	break;

    default:
	_linux_fprintf(stderr, 
	    "Error: opcode %d not supported\n", opcode);
	_linux_exit(1);
    }
    return t;
}

/* vi: ts=8 
*/
