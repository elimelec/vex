/*
** static char sccs_id[] = "$Id: sf_nan.c,v 1.1.1.1 2001/11/21 20:34:46 frb Exp $ ";
*/

/*
 * nanf () returns a nan.
 * Added by Cygnus Support.
 */

#include "fdlibm.h"

	float nanf()
{
	float x;

	SET_FLOAT_WORD(x,0x7fc00000);
	return x;
}

#ifdef _DOUBLE_IS_32BITS

	double nan()
{
	return (double) nanf();
}

#endif /* defined(_DOUBLE_IS_32BITS) */
