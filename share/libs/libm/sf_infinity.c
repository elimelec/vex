/*
** static char sccs_id[] = "$Id: sf_infinity.c,v 1.1.1.1 2001/11/21 20:34:46 frb Exp $ ";
*/

/*
 * infinityf () returns the representation of infinity.
 * Added by Cygnus Support.
 */

#include "fdlibm.h"

	float infinityf()
{
	float x;

	SET_FLOAT_WORD(x,0x7f800000);
	return x;
}

#ifdef _DOUBLE_IS_32BITS

	double infinity()
{
	return (double) infinityf();
}

#endif /* defined(_DOUBLE_IS_32BITS) */
