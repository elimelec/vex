/* 
** static char sccs_id[] = "$Id: divrem.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
*/

#ifdef INLINE_DIVISION

extern int _i_rem(
    int numerator, 
    int denominator
)
{
    int remainder = numerator % denominator;
    return remainder;
}

extern int _i_div(
    int numerator, 
    int denominator
)
{
    int quotient = numerator / denominator;
    return quotient;
}

extern unsigned int _i_urem(
    unsigned int numerator, 
    unsigned int denominator
)
{
    unsigned int remainder = (unsigned) numerator % denominator;
    return remainder;
}

extern unsigned int _i_udiv(
    unsigned int numerator, 
    unsigned int denominator
)
{
    unsigned int quotient = (unsigned) numerator / denominator;
    return quotient;
}

#else /* ! INLINE_DIVISION */

static unsigned int _divrem(
    int remwanted, 
    unsigned int num, 
    unsigned int den
)
{
    unsigned int bit = 1;
    unsigned int res = 0;

#pragma unroll_amount(4,1)
    while (den < num && bit && !(den & (1L << 31))) {
	den <<= 1;
	bit <<= 1;
    }

#pragma unroll_amount(4,1)
    while (bit) {
	if (num >= den) {
	    num -= den;
	    res |= bit;
	}
	bit >>= 1;
	den >>= 1;
    }

    return remwanted ? num : res;
}

extern int _i_rem(
    int numerator, 
    int denominator
)
{
    int remainder;
    int sign = 0;

    if (numerator < 0) {
	numerator = -numerator;
	sign = 1;
    }
    if (denominator < 0) {
	denominator = -denominator;
    }

    remainder = _divrem(1, numerator, denominator);

    return sign ? -remainder : remainder;
}

extern int _i_div(
    int numerator, 
    int denominator
)
{
    int sign = 0;
    int quotient;

    if (numerator < 0) {
	numerator = -numerator;
	sign = 1;
    } 
    if (denominator < 0) {
	denominator = -denominator;
	sign = 1 - sign;
    }

    quotient = _divrem(0, numerator, denominator);

    return sign ? -quotient : quotient;
}

extern unsigned int _i_urem(
    unsigned int numerator, 
    unsigned int denominator
)
{
    int remainder;
    remainder = _divrem(1, numerator, denominator);
    return remainder;
}

extern unsigned int _i_udiv(
    unsigned int numerator, 
    unsigned int denominator
)
{
    unsigned int quotient;
    quotient = _divrem(0, numerator, denominator);
    return quotient;
}
#endif
