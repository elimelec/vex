/**
*** Copyright (C) 1998-2004 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company.
***
*** Permission to use, copy, modify, and distribute this
*** software is freely granted, provided that this notice 
*** is preserved.
***
**/

static char sccs_id[] = "$Id: vexbcopy.c,v 1.2 2004/01/13 16:26:58 frb Exp $ ";

/**
*** Author: Paolo Faraboschi
**/

/**
*** Optimized bcopy, assuming no overlap.
**/

#include <stdlib.h>

/* Test mode */
typedef unsigned int   uint32;
typedef unsigned short uint16;

void _bcopy(char * restrict source, char * restrict target, size_t n)
{
    /* precompute some stuff */
    char * restrict s = source;
    char * restrict t = target;
    uint32 align_s = (4 - ((uint32) s)) & 0x3;
    uint32 align_t = (4 - ((uint32) t)) & 0x3;
    uint32 k;

    if (n >= 8 && align_s == align_t) {
        uint32 * restrict p = (uint32 *)(s + align_s);
        uint32 * restrict q = (uint32 *)(t + align_t);

	/* align to word boundary */
	n -= align_s;
        #pragma unroll_amount(1,1)
	for (k = 0; k < align_s; k++)
	    *t++ = *s++;

	/* bulk move */
        #pragma unroll_amount(8,1)
	for (k = 0; k < (n >> 2); k++)
	    *q++ = *p++;

	s = (char *) p;
	t = (char *) q;

	/* leftover bytes */
        #pragma unroll_amount(1,1)
	while (n & 3) {
	    *t++ = *s++;
	    n--;
	}
    }
    else {
        #pragma unroll_amount(4,1)
        for (k = 0; k < n; k++)
	    *t++ = *s++;
    }
    return;
}

