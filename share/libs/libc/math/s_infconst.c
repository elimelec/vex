/* 
** static char sccs_id[] = "$Id: s_infconst.c,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
*/
/* Infinity as a constant value.   This is used for HUGE_VAL.
 * Added by Cygnus Support.
 */

#include "fdlibm.h"

#ifndef _DOUBLE_IS_32BITS
#ifdef __IEEE_BIG_ENDIAN
const union __dmath __infinity = { 0x7ff00000, 0 };
#else
const union __dmath __infinity = { 0, 0x7ff00000 };
#endif
#else /* defined (_DOUBLE_IS_32BITS) */
const union __dmath __infinity = { 0x7f800000, 0 };
#endif /* defined (_DOUBLE_IS_32BITS) */
