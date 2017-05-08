/*
** static char sccs_id[] = "$Id: wf_pow.c,v 1.1.1.1 2001/11/21 20:34:47 frb Exp $ ";
*/

/* wf_pow.c -- float version of w_pow.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

/* 
 * wrapper powf(x,y) return x**y
 */

#include "fdlibm.h"

#ifdef __STDC__
	float powf(float x, float y)	/* wrapper powf */
#else
	float powf(x,y)			/* wrapper powf */
	float x,y;
#endif
{
#ifdef _IEEE_LIBM
	return  __ieee754_powf(x,y);
#else
	float z;
	z=__ieee754_powf(x,y);
	if(_LIB_VERSION == _IEEE_|| isnanf(y)) return z;
	if(isnanf(x)) {
	    if(y==(float)0.0) 
	        /* powf(NaN,0.0) */
	        return (float)__kernel_standard((double)x,(double)y,142);
	    else 
		return z;
	}
	if(x==(float)0.0){ 
	    if(y==(float)0.0)
	        /* powf(0.0,0.0) */
	        return (float)__kernel_standard((double)x,(double)y,120);
	    if(finitef(y)&&y<(float)0.0)
	        /* powf(0.0,negative) */
	        return (float)__kernel_standard((double)x,(double)y,123);
	    return z;
	}
	if(!finitef(z)) {
	    if(finitef(x)&&finitef(y)) {
	        if(isnanf(z))
		    /* powf neg**non-int */
	            return (float)__kernel_standard((double)x,(double)y,124);
	        else 
		    /* powf overflow */
	            return (float)__kernel_standard((double)x,(double)y,121);
	    }
	} 
	if(z==(float)0.0&&finitef(x)&&finitef(y))
	    /* powf underflow */
	    return (float)__kernel_standard((double)x,(double)y,122);
	return z;
#endif
}

#ifdef _DOUBLE_IS_32BITS

#ifdef __STDC__
	double pow(double x, double y)
#else
	double pow(x,y)
	double x,y;
#endif
{
	return (double) powf((float) x, (float) y);
}

#endif /* defined(_DOUBLE_IS_32BITS) */