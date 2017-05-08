/**
*** static char sccs_id[] = "$Id: float.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/

/**
*** We must pick up this version of float.h.
*** We generate a warning message if the host float.h has been included.
**/
#ifdef _FLOAT_INCLUDED
#define INCORRECT_FLOAT_INCLUDED 0
#define INCORRECT_FLOAT_INCLUDED 1
#endif

#ifndef _HPL_PROTO_FLOAT_INCLUDED
#define _HPL_PROTO_FLOAT_INCLUDED

#define FLT_RADIX		2
#define FLT_ROUNDS		1

#  define FLT_RADIX		2
#  define FLT_ROUNDS		1

#  define FLT_MANT_DIG		24
#  define FLT_EPSILON		((float)1.19209290E-07)

#  ifndef FLT_DIG
#    define FLT_DIG		6
#  endif /* FLT_DIG */
#  define FLT_MIN_EXP		(-125)
#  ifndef FLT_MIN
#    define FLT_MIN		((float)1.17549435E-38)
#  endif /* FLT_MIN */
#  define FLT_MIN_10_EXP	(-37)
#  define FLT_MAX_EXP		128
#  ifndef FLT_MAX
#    define FLT_MAX		((float)3.40282347E+38)
#  endif /* FLT_MAX */
#  define FLT_MAX_10_EXP	38

#  define DBL_MANT_DIG		53
#  define DBL_EPSILON		2.2204460492503131E-16
#  ifndef DBL_DIG
#    define DBL_DIG		15
#  endif /* DBL_DIG */
#  define DBL_MIN_EXP		(-1021)
#  ifndef DBL_MIN
#    define DBL_MIN		2.2250738585072014E-308
#  endif /* DBL_MIN */
#  define DBL_MIN_10_EXP	(-307)
#  define DBL_MAX_EXP		1024
#  ifndef DBL_MAX
#    define DBL_MAX		1.7976931348623157E+308
#  endif /* DBL_MAX */
#  define DBL_MAX_10_EXP	308

#  define LDBL_MANT_DIG		DBL_MANT_DIG
#  define LDBL_EPSILON		DBL_EPSILON
#  define LDBL_DIG		DBL_DIG
#  define LDBL_MIN_EXP		DBL_MIN_EXP
#  define LDBL_MIN		DBL_MIN
#  define LDBL_MIN_10_EXP	DBL_MIN_10_EXP
#  define LDBL_MAX_EXP		DBL_MAX_EXP
#  define LDBL_MAX		DBL_MAX
#  define LDBL_MAX_10_EXP	DBL_MAX_10_EXP

#endif /* _HPL_PROTO_FLOAT_INCLUDED */
