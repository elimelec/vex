/* 
** static char sccs_id[] = "$Id: floatlib.c,v 1.2 2003/01/13 22:27:46 frb Exp $ ";
*/
/*
===============================================================================

This C source file is modified from the SoftFloat IEC/IEEE Floating-point
Arithmetic Package, Release 2.

Written by John R. Hauser.  This work was made possible in part by the
International Computer Science Institute, located at Suite 600, 1947 Center
Street, Berkeley, California 94704.  Funding was partially provided by the
National Science Foundation under grant MIP-9311980.  The original version
of this code was written as part of a project to build a fixed-point vector
processor in collaboration with the University of California at Berkeley,
overseen by Profs. Nelson Morgan and John Wawrzynek.  More information
is available through the web page `http://HTTP.CS.Berkeley.EDU/~jhauser/
arithmetic/softfloat.html'.

THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort
has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT
TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO
PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY
AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.

Derivative works are acceptable, even for commercial purposes, so long as
(1) they include prominent notice that the work is derivative, and (2) they
include prominent notice akin to these three paragraphs for those parts of
this code that are retained.

===============================================================================
*/

#include <signal.h>
#include <ieeefp.h>

typedef int flag;
typedef int uint8;
typedef int int8;
typedef int uint16;
typedef int int16;
typedef unsigned int uint32;
typedef signed int int32;

typedef unsigned char bits8;
typedef signed char sbits8;
typedef unsigned short int bits16;
typedef signed short int sbits16;
typedef unsigned int bits32;
typedef signed int sbits32;

typedef unsigned int float32;

typedef struct {
    unsigned int high, low;
}
float64;

typedef union {
    double d;
    float64 f64;
}
double_float64;

typedef union {
    float f;
    float32 f32;
}
float_float32;

typedef struct {
    flag sign;
    bits32 high, low;
}
commonNaNT;

enum {
    float_tininess_after_rounding = 0,
    float_tininess_before_rounding = 1
};

enum {
    float_round_to_zero = FP_RZ,
    float_round_nearest_even = FP_RN,
    float_round_up = FP_RP,
    float_round_down = FP_RM
};

enum {
    float_flag_inexact = FP_X_IMP,
    float_flag_divbyzero = FP_X_DX,
    float_flag_underflow = FP_X_UFL,
    float_flag_overflow = FP_X_OFL,
    float_flag_invalid = FP_X_INV
};

enum {
    float32_default_nan = 0x7FFFFFFF
};

static int8 float_detect_tininess = float_tininess_after_rounding;
static int8 float_rounding_mode = float_round_nearest_even;
static int8 float_exception_flags = 0;
static int8 float_exception_mask = 0;

static void float_raise(int x);
extern float32 _r_ilfloat(int32 x);
extern float64 _d_ilfloat(int32 x);
extern float32 _r_ufloat(uint32 x);
extern float64 _d_ufloat(uint32 x);
static int32 float32_to_int32(float32 x);
static int32 float32_to_int32_round_to_zero(float32 x, flag is_signed);
extern float64 _d_r(float32 x);
static float32 float32_round_to_int(float32 x);
extern float32 _r_add(float32 x, float32 y);
extern float32 _r_sub(float32 x, float32 y);
extern float32 _r_mul(float32 x, float32 y);
extern float32 _r_div(float32 x, float32 y);
static float32 float32_rem(float32 x, float32 y);
extern int _r_eq(float32 x, float32 y);
extern int _r_le(float32 x, float32 y);
extern int _r_lt(float32 x, float32 y);
static int float32_eq_signaling(float32 x, float32 y);
static int float32_le_quiet(float32 x, float32 y);
static int float32_lt_quiet(float32 x, float32 y);
static int float32_is_signaling_nan(float32 x);
static int float64_to_int32(float64 x);
static int float64_to_int32_round_to_zero(float64 x, flag is_signed);
extern float32 _r_d(float64 x);
static float64 float64_round_to_int(float64 x);
extern float64 _d_add(float64 x, float64 y);
extern float64 _d_sub(float64 x, float64 y);
extern float64 _d_mul(float64 x, float64 y);
extern float64 _d_div(float64 x, float64 y);
static float64 float64_rem(float64 x, float64 y);
extern int _d_eq(float64 x, float64 y);
extern int _d_le(float64 x, float64 y);
extern int _d_lt(float64 x, float64 y);
static int float64_eq_signaling(float64 x, float64 y);
static int float64_le_quiet(float64 x, float64 y);
static int float64_lt_quiet(float64 x, float64 y);
static int float64_is_signaling_nan(float64 x);

static bits32 estimateDiv64To32(bits32 a0, bits32 a1, bits32 b)
{
    bits32 b0, b1;
    bits32 rem0, rem1, term0, term1;
    bits32 z;

    if (b <= a0)
	return 0xFFFFFFFF;
    b0 = b >> 16;
    z = (b0 << 16 <= a0) ? 0xFFFF0000 : (a0 / b0) << 16;
    {
	bits32 *_z0Ptr = (&term0);
	bits32 *_z1Ptr = (&term1);
	bits32 _a = (b);
	bits32 _b = (z);
	bits16 _aLow = _a;
	bits16 _aHigh = _a >> 16;
	bits16 _bLow = _b;
	bits16 _bHigh = _b >> 16;
	bits32 _z1 = ((bits32) _aLow) * _bLow;
	bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	_zMiddleA += _zMiddleB;
	_z0 += (((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	_zMiddleA <<= 16;
	_z1 += _zMiddleA;
	_z0 += (_z1 < _zMiddleA);
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    {
	bits32 *_z0Ptr = (&rem0);
	bits32 *_z1Ptr = (&rem1);
	bits32 _a0 = (a0);
	bits32 _a1 = (a1);
	bits32 _b0 = (term0);
	bits32 _b1 = (term1);
	*(_z1Ptr) = _a1 - _b1;
	*(_z0Ptr) = _a0 - _b0 - (_a1 < _b1);
    }
    while (((sbits32) rem0) < 0) {
	z -= 0x10000;
	b1 = b << 16;
	{
	    bits32 *_z0Ptr = (bits32 *) (&rem0);
	    bits32 *_z1Ptr = (bits32 *) (&rem1);
	    bits32 _a0 = (rem0);
	    bits32 _a1 = (rem1);
	    bits32 _b0 = (b0);
	    bits32 _b1 = (b1);
	    bits32 _z1 = _a1 + _b1;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	}
    }
    rem0 = (rem0 << 16) | (rem1 >> 16);
    z |= (b0 << 16 <= rem0) ? 0xFFFF : rem0 / b0;
    return z;
}

static int8 countLeadingZeros32(bits32 a)
{
    static const int8 countLeadingZerosHigh[] = {
	8, 7, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    int8 shiftCount = 0;

    if (a < 0x10000) {
	shiftCount += 16;
	a <<= 16;
    }
    if (a < 0x1000000) {
	shiftCount += 8;
	a <<= 8;
    }
    shiftCount += countLeadingZerosHigh[a >> 24];
    return shiftCount;
}

static void float_raise(int8 flags)
{
    float_exception_flags |= flags;

    if (float_exception_flags & float_exception_mask)
	raise(SIGFPE);
}

static commonNaNT float32ToCommonNaN(float32 a)
{
    commonNaNT z;

#pragma if_prob(1,1000)

    if ((((((a) >> 22) & 0x1FF) == 0x1FE) && ((a) & 0x003FFFFF)))
	float_raise(float_flag_invalid);
    z.sign = a >> 31;
    z.low = 0;
    z.high = a << 9;
    return z;
}

static float32 propagateFloat32NaN(float32 a, float32 b)
{
    flag aIsNaN, aIsSignalingNaN, bIsNaN, bIsSignalingNaN;

    aIsNaN = ((0xFF000000 < (bits32) ((a) << 1)));
    aIsSignalingNaN = (((((a) >> 22) & 0x1FF) == 0x1FE) && ((a) & 0x003FFFFF));
    bIsNaN = ((0xFF000000 < (bits32) ((b) << 1)));
    bIsSignalingNaN = (((((b) >> 22) & 0x1FF) == 0x1FE) && ((b) & 0x003FFFFF));
    a |= 0x00400000;
    b |= 0x00400000;

#pragma if_prob(1,1000)

    if (aIsSignalingNaN | bIsSignalingNaN)
	float_raise(float_flag_invalid);
    return bIsSignalingNaN ? b : aIsSignalingNaN ? a : bIsNaN ? b : a;
}

enum
{
    float64_default_nan_high = 0x7FFFFFFF,
    float64_default_nan_low = 0xFFFFFFFF
};

static commonNaNT float64ToCommonNaN(float64 a)
{
    commonNaNT z;

#pragma if_prob(1,1000)

    if ((((((a).high >> 19) & 0xFFF) == 0xFFE)
	 && ((a).low || ((a).high & 0x0007FFFF))))
	float_raise(float_flag_invalid);
    z.sign = a.high >> 31;
    {
	bits32 *_z0Ptr = (&z.high);
	bits32 *_z1Ptr = (&z.low);
	bits32 _a0 = (a.high);
	bits32 _a1 = (a.low);
	int16 _count = (12);
	*_z1Ptr = _a1 << _count;
	*_z0Ptr =
	    (_count == 0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
    }
    return z;
}

static float64 commonNaNToFloat64(commonNaNT a)
{
    float64 z;

    {
	bits32 _a0 = a.high;
	bits32 _a1 = a.low;
	bits16 _count = 12;
	bits32 _z0, _z1;
	bits32 *_z0Ptr = (&z.high);
	bits32 *_z1Ptr = (&z.low);
	int8 negCount = (-_count) & 31;
	if (_count == 0) {
	    _z1 = _a1;
	    _z0 = _a0;
	}
	else if (_count < 32) {
	    _z1 = (_a0 << negCount) | (_a1 >> _count);
	    _z0 = _a0 >> _count;
	}
	else {
	    _z1 = (_count < 64) ? (_a0 >> (_count & 31)) : 0;
	    _z0 = 0;
	}
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    z.high |= (((bits32) a.sign) << 31) | 0x7FF80000;
    return z;
}

static float64 propagateFloat64NaN(float64 a, float64 b)
{
    flag aIsNaN, aIsSignalingNaN, bIsNaN, bIsSignalingNaN;

    aIsNaN = ((0xFFE00000 <= (bits32) ((a).high << 1))
	      && ((a).low || ((a).high & 0x000FFFFF)));
    aIsSignalingNaN = (((((a).high >> 19) & 0xFFF) == 0xFFE)
		       && ((a).low || ((a).high & 0x0007FFFF)));
    bIsNaN = ((0xFFE00000 <= (bits32) ((b).high << 1))
	      && ((b).low || ((b).high & 0x000FFFFF)));
    bIsSignalingNaN = (((((b).high >> 19) & 0xFFF) == 0xFFE)
		       && ((b).low || ((b).high & 0x0007FFFF)));
    a.high |= 0x00080000;
    b.high |= 0x00080000;

#pragma if_prob(1,1000)

    if (aIsSignalingNaN | bIsSignalingNaN)
	float_raise(float_flag_invalid);
    return bIsSignalingNaN ? b : aIsSignalingNaN ? a : bIsNaN ? b : a;
}

static float32 roundAndPackFloat32(flag zSign, int16 zExp, bits32 zSig)
{
    int8 roundingMode;
    flag roundNearestEven;
    int8 roundIncrement, roundBits;
    flag isTiny;

    roundingMode = float_rounding_mode;
    roundNearestEven = roundingMode == float_round_nearest_even;
    roundIncrement = 0x40;

#pragma if_prob(1,10000)

    if (!roundNearestEven) {
	if (roundingMode == float_round_to_zero) {
	    roundIncrement = 0;
	}
	else {
	    roundIncrement = 0x7F;
	    if (zSign) {
		if (roundingMode == float_round_up)
		    roundIncrement = 0;
	    }
	    else {
		if (roundingMode == float_round_down)
		    roundIncrement = 0;
	    }
	}
    }
    roundBits = zSig & 0x7F;

#pragma if_prob(1,1000)

    if (0xFD <= (bits16) zExp) {
	if ((0xFD < zExp)
	    || ((zExp == 0xFD)
		&& ((sbits32) (zSig + roundIncrement) < 0))
	    ) {
	    float_raise(float_flag_overflow | float_flag_inexact);
	    return ((((bits32) (zSign)) << 31) + (((bits32) (0xFF)) << 23) +
		    (0)) - (roundIncrement == 0);
	}
	if (zExp < 0) {
	    isTiny = (float_detect_tininess == float_tininess_before_rounding)
		|| (zExp < -1)
		|| (zSig + roundIncrement < 0x80000000);
	    {
		int16 _count = (-zExp);
		bits32 _a = (zSig);
		bits32 _z;
		bits32 *_zPtr = (&zSig);
		if (_count == 0) {
		    _z = _a;
		}
		else if (_count < 32) {
		    _z = (_a >> _count) | ((_a << ((-_count) & 31)) != 0);
		}
		else {
		    _z = (_a != 0);
		}
		*(_zPtr) = _z;
	    }
	    zExp = 0;
	    roundBits = zSig & 0x7F;
	    if (isTiny && roundBits)
		float_raise(float_flag_underflow);
	}
    }
    if (roundBits)
	float_exception_flags |= float_flag_inexact;
    zSig = (zSig + roundIncrement) >> 7;
    zSig &= ~(((roundBits ^ 0x40) == 0) & roundNearestEven);
    if (zSig == 0)
	zExp = 0;
    return ((((bits32) (zSign)) << 31) + (((bits32) (zExp)) << 23) + (zSig));
}

static float32 normalizeRoundAndPackFloat32(flag zSign, int16 zExp, bits32 zSig)
{
    int8 shiftCount = countLeadingZeros32(zSig) - 1;
    return roundAndPackFloat32(zSign, zExp - shiftCount, zSig << shiftCount);
}

static void normalizeFloat64Subnormal(bits32 aSig0,
				      bits32 aSig1,
				      int16 * zExpPtr,
				      bits32 * zSig0Ptr, bits32 * zSig1Ptr)
{
    int8 shiftCount;
    bits32 t0, t1;

    if (aSig0 == 0) {
	shiftCount = countLeadingZeros32(aSig1) - 11;
	
	if (shiftCount < 0) {
	    t0 = aSig1 >> (-shiftCount);
	    t1 = aSig1 << (shiftCount & 31);
	}
	else {
	    t0 = aSig1 << shiftCount;
	    t1 = 0;
	}
	*zSig0Ptr = t0;
	*zSig1Ptr = t1;
	*zExpPtr = -shiftCount - 31;
    }
    else {
	shiftCount = countLeadingZeros32(aSig0) - 11;
	{
	    bits32 *_z0Ptr = (zSig0Ptr);
	    bits32 *_z1Ptr = (zSig1Ptr);
	    bits32 _a0 = (aSig0);
	    bits32 _a1 = (aSig1);
	    int16 _count = (shiftCount);
	    *_z1Ptr = _a1 << _count;
	    *_z0Ptr =
		(_count ==
		 0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
	}
	*zExpPtr = 1 - shiftCount;
    }
}

static float64 packFloat64(flag zSign, int16 zExp, bits32 zSig0, bits32 zSig1)
{
    float64 z;

    z.low = zSig1;
    z.high = (((bits32) zSign) << 31) + (((bits32) zExp) << 20) + zSig0;
    return z;
}

static float64
roundAndPackFloat64(flag zSign, int16 zExp, bits32 zSig0, bits32 zSig1,
		    bits32 zSig2)
{
    int8 roundingMode;
    flag roundNearestEven, increment, isTiny;

    roundingMode = float_rounding_mode;
    roundNearestEven = (roundingMode == float_round_nearest_even);
    increment = ((sbits32) zSig2 < 0);
    if (!roundNearestEven) {
	if (roundingMode == float_round_to_zero) {
	    increment = 0;
	}
	else {
	    if (zSign) {
		increment = (roundingMode == float_round_down) && zSig2;
	    }
	    else {
		increment = (roundingMode == float_round_up) && zSig2;
	    }
	}
    }

#pragma if_prob(1,1000)

    if (0x7FD <= (bits16) zExp) {
	if ((0x7FD < zExp)
	    || ((zExp == 0x7FD)
		&& (((0x001FFFFF) == (zSig0)) && ((0xFFFFFFFF) == (zSig1)))
		&& increment)
	    ) {
	    float_raise(float_flag_overflow | float_flag_inexact);
	    if ((roundingMode == float_round_to_zero)
		|| (zSign && (roundingMode == float_round_up))
		|| (!zSign && (roundingMode == float_round_down))
		) {
		return packFloat64(zSign, 0x7FE, 0x000FFFFF, 0xFFFFFFFF);
	    }
	    return packFloat64(zSign, 0x7FF, 0, 0);
	}
	if (zExp < 0) {
	    isTiny = (float_detect_tininess == float_tininess_before_rounding)
		|| (zExp < -1)
		|| !increment
		|| (((zSig0) < (0x001FFFFF))
		    || (((zSig0) == (0x001FFFFF)) && ((zSig1) < (0xFFFFFFFF))));
	    {
		bits32 _a0 = (zSig0);
		bits32 _a1 = (zSig1);
		bits32 _a2 = (zSig2);
		int16 _count = (-zExp);
		int8 negCount = (-_count) & 31;
		bits32 _z0, _z1, _z2;
		bits32 *_z0Ptr = (&zSig0);
		bits32 *_z1Ptr = (&zSig1);
		bits32 *_z2Ptr = (&zSig2);
		if (_count == 0) {
		    _z0 = _a0;
		    _z1 = _a1;
		    _z2 = _a2;
		}
		else {
		    if (_count < 32) {
			_z2 = _a1 << negCount;
			_z1 = (_a0 << negCount) | (_a1 >> _count);
			_z0 = _a0 >> _count;
		    }
		    else {
			if (_count == 32) {
			    _z2 = _a1;
			    _z1 = _a0;
			}
			else {
			    _a2 |= _a1;
			    if (_count < 64) {
				_z2 = _a0 << negCount;
				_z1 = _a0 >> (_count & 31);
			    }
			    else {
				_z2 = (_count == 64) ? _a0 : (_a0 != 0);
				_z1 = 0;
			    }
			}
			_z0 = 0;
		    }
		    _z2 |= (_a2 != 0);
		}
		*(_z2Ptr) = _z2;
		*(_z1Ptr) = _z1;
		*(_z0Ptr) = _z0;
	    }
	    zExp = 0;
	    if (isTiny && zSig2)
		float_raise(float_flag_underflow);
	    if (roundNearestEven) {
		increment = ((sbits32) zSig2 < 0);
	    }
	    else {
		if (zSign) {
		    increment = (roundingMode == float_round_down) && zSig2;
		}
		else {
		    increment = (roundingMode == float_round_up) && zSig2;
		}
	    }
	}
    }
    if (zSig2)
	float_exception_flags |= float_flag_inexact;
    if (increment) {
	{
	    bits32 *_z0Ptr = (bits32 *) (&zSig0);
	    bits32 *_z1Ptr = (bits32 *) (&zSig1);
	    bits32 _a0 = (zSig0);
	    bits32 _a1 = (zSig1);
	    bits32 _b0 = (0);
	    bits32 _b1 = (1);
	    bits32 _z1 = _a1 + _b1;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	}
	zSig1 &= ~((zSig2 + zSig2 == 0) & roundNearestEven);
    }
    else {
	if ((zSig0 | zSig1) == 0)
	    zExp = 0;
    }
    return packFloat64(zSign, zExp, zSig0, zSig1);
}

static float64
normalizeRoundAndPackFloat64(flag zSign, int16 zExp, bits32 zSig0, bits32 zSig1)
{
    int8 shiftCount;
    bits32 zSig2;

    if (zSig0 == 0) {
	zSig0 = zSig1;
	zSig1 = 0;
	zExp -= 32;
    }
    shiftCount = countLeadingZeros32(zSig0) - 11;
    if (0 <= shiftCount) {
	zSig2 = 0;
	{
	    bits32 *_z0Ptr = (&zSig0);
	    bits32 *_z1Ptr = (&zSig1);
	    bits32 _a0 = (zSig0);
	    bits32 _a1 = (zSig1);
	    int16 _count = (shiftCount);
	    *_z1Ptr = _a1 << _count;
	    *_z0Ptr =
		(_count ==
		 0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
	}
    }
    else {
	{
	    bits32 _a0 = (zSig0);
	    bits32 _a1 = (zSig1);
	    bits32 _a2 = (0);
	    int16 _count = (-shiftCount);
	    int8 negCount = (-_count) & 31;
	    bits32 _z0, _z1, _z2;
	    bits32 *_z0Ptr = (&zSig0);
	    bits32 *_z1Ptr = (&zSig1);
	    bits32 *_z2Ptr = (&zSig2);
	    if (_count == 0) {
		_z0 = _a0;
		_z1 = _a1;
		_z2 = _a2;
	    }
	    else {
		if (_count < 32) {
		    _z2 = _a1 << negCount;
		    _z1 = (_a0 << negCount) | (_a1 >> _count);
		    _z0 = _a0 >> _count;
		}
		else {
		    if (_count == 32) {
			_z2 = _a1;
			_z1 = _a0;
		    }
		    else {
			_a2 |= _a1;
			if (_count < 64) {
			    _z2 = _a0 << negCount;
			    _z1 = _a0 >> (_count & 31);
			}
			else {
			    _z2 = (_count == 64) ? _a0 : (_a0 != 0);
			    _z1 = 0;
			}
		    }
		    _z0 = 0;
		}
		_z2 |= (_a2 != 0);
	    }
	    *(_z2Ptr) = _z2;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
    }
    zExp -= shiftCount;
    return roundAndPackFloat64(zSign, zExp, zSig0, zSig1, zSig2);
}

extern float32 _r_ilfloat(int32 a)
{
    if (a == 0 || a == 0x80000000)
	return a == 0 ? 0 : ((((bits32) (1)) << 31) + (((bits32) (0x9E)) << 23) + (0));
    return normalizeRoundAndPackFloat32(a < 0, 0x9C, a < 0 ? -a : a);
}

extern float32 _r_ufloat(uint32 a)
{
    if (a == 0)
	return 0;
    return normalizeRoundAndPackFloat32(0, 0x9C, a);
}

extern float64 _d_ilfloat(int32 a)
{
    flag zSign;
    bits32 absA;
    int8 shiftCount;
    bits32 zSig0, zSig1;

    if (a == 0)
	return packFloat64(0, 0, 0, 0);
    zSign = (a < 0);
    absA = zSign ? -a : a;
    shiftCount = countLeadingZeros32(absA) - 11;
    if (0 <= shiftCount) {
	zSig0 = absA << shiftCount;
	zSig1 = 0;
    }
    else {
	{
	    bits32 _a0 = absA;
	    bits32 _a1 = 0;
	    bits16 _count = -shiftCount;
	    bits32 _z0, _z1;
	    bits32 *_z0Ptr = (&zSig0);
	    bits32 *_z1Ptr = (&zSig1);
	    int8 negCount = (-_count) & 31;
	    if (_count == 0) {
		_z1 = _a1;
		_z0 = _a0;
	    }
	    else if (_count < 32) {
		_z1 = (_a0 << negCount) | (_a1 >> _count);
		_z0 = _a0 >> _count;
	    }
	    else {
		_z1 = (_count < 64) ? (_a0 >> (_count & 31)) : 0;
		_z0 = 0;
	    }
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
    }
    return packFloat64(zSign, 0x412 - shiftCount, zSig0, zSig1);
}

extern float64 _d_ufloat(uint32 a)
{
    int8 shiftCount;
    bits32 zSig0, zSig1;

    if (a == 0)
	return packFloat64(0, 0, 0, 0);

    shiftCount = countLeadingZeros32(a) - 11;
    if (0 <= shiftCount) {
	zSig0 = a << shiftCount;
	zSig1 = 0;
    }
    else {
	{
	    bits32 _a0 = a;
	    bits32 _a1 = 0;
	    bits16 _count = -shiftCount;
	    bits32 _z0, _z1;
	    bits32 *_z0Ptr = (&zSig0);
	    bits32 *_z1Ptr = (&zSig1);
	    int8 negCount = (-_count) & 31;
	    if (_count == 0) {
		_z1 = _a1;
		_z0 = _a0;
	    }
	    else if (_count < 32) {
		_z1 = (_a0 << negCount) | (_a1 >> _count);
		_z0 = _a0 >> _count;
	    }
	    else {
		_z1 = (_count < 64) ? (_a0 >> (_count & 31)) : 0;
		_z0 = 0;
	    }
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
    }
    return packFloat64(0, 0x412 - shiftCount, zSig0, zSig1);
}

static int32 float32_to_int32_round_to_zero(float32 a, flag is_signed)
{
    flag aSign;
    int16 aExp, shiftCount;
    bits32 aSig;
    int32 z;

    aSig = ((a) & 0x007FFFFF);
    aExp = (((a) >> 23) & 0xFF);
    aSign = ((a) >> 31);
    shiftCount = aExp - 0x9E;

#pragma if_prob(1,1000)

    if (0 <= shiftCount) {
	if (a == 0xCF000000)
	    return is_signed ? 0x80000000 : 0;
	float_raise(float_flag_invalid);
	if (!aSign || ((aExp == 0xFF) && aSig))
	    return is_signed ? 0x7FFFFFFF : 0xFFFFFFFF;
	return is_signed ? 0x80000000 : 0;
    }
    else if (aExp <= 0x7E) {
	if (aExp | aSig)
	    float_exception_flags |= float_flag_inexact;
	return 0;
    }
    aSig = (aSig | 0x00800000) << 8;
    z = aSig >> (-shiftCount);
    if ((bits32) (aSig << (shiftCount & 31))) {
	float_exception_flags |= float_flag_inexact;
    }
    return aSign ? -z : z;
}

extern float64 _d_r(float32 a)
{
    flag aSign;
    int16 aExp;
    bits32 aSig, zSig0, zSig1;

    aSig = ((a) & 0x007FFFFF);
    aExp = (((a) >> 23) & 0xFF);
    aSign = ((a) >> 31);

#pragma if_prob(1,1000)

    if (aExp == 0xFF) {
	if (aSig)
	    return commonNaNToFloat64(float32ToCommonNaN(a));
	return packFloat64(aSign, 0x7FF, 0, 0);
    }

#pragma if_prob(1,1000)

    if (aExp == 0) {
	if (aSig == 0)
	    return packFloat64(aSign, 0, 0, 0);
	{
	    int8 shiftCount = countLeadingZeros32(aSig) - 8;
	    *(&aSig) = (aSig) << shiftCount;
	    *(&aExp) = 1 - shiftCount;
	}
	--aExp;
    }
    {
	bits32 _a0 = aSig;
	bits32 _a1 = 0;
	bits16 _count = 3;
	bits32 _z0, _z1;
	bits32 *_z0Ptr = (&zSig0);
	bits32 *_z1Ptr = (&zSig1);
	int8 negCount = (-_count) & 31;
	if (_count == 0) {
	    _z1 = _a1;
	    _z0 = _a0;
	}
	else if (_count < 32) {
	    _z1 = (_a0 << negCount) | (_a1 >> _count);
	    _z0 = _a0 >> _count;
	}
	else {
	    _z1 = (_count < 64) ? (_a0 >> (_count & 31)) : 0;
	    _z0 = 0;
	}
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    return packFloat64(aSign, aExp + 0x380, zSig0, zSig1);
}

static float32 addFloat32Sigs(float32 a, float32 b, flag zSign)
{
    int16 aExp, bExp, zExp;
    bits32 aSig, bSig, zSig;
    int16 expDiff;

    aSig = ((a) & 0x007FFFFF);
    aExp = (((a) >> 23) & 0xFF);
    bSig = ((b) & 0x007FFFFF);
    bExp = (((b) >> 23) & 0xFF);
    expDiff = aExp - bExp;
    aSig <<= 6;
    bSig <<= 6;
    if (0 < expDiff) {

#pragma if_prob(1,1000)

	if (aExp == 0xFF) {
	    if (aSig)
		return propagateFloat32NaN(a, b);
	    return a;
	}
	if (bExp == 0) {
	    --expDiff;
	}
	else {
	    bSig |= 0x20000000;
	}
	{
	    int16 _count = (expDiff);
	    bits32 _a = (bSig);
	    bits32 _z;
	    bits32 *_zPtr = (&bSig);
	    if (_count == 0) {
		_z = _a;
	    }
	    else if (_count < 32) {
		_z = (_a >> _count) | ((_a << ((-_count) & 31)) != 0);
	    }
	    else {
		_z = (_a != 0);
	    }
	    *(_zPtr) = _z;
	}
	zExp = aExp;
    }
    else if (expDiff < 0) {

#pragma if_prob(1,1000)

	if (bExp == 0xFF) {
	    if (bSig)
		return propagateFloat32NaN(a, b);
	    return ((((bits32) (zSign)) << 31) + (((bits32) (0xFF)) << 23) +
		    (0));
	}
	if (aExp == 0) {
	    ++expDiff;
	}
	else {
	    aSig |= 0x20000000;
	}
	{
	    int16 _count = (-expDiff);
	    bits32 _a = (aSig);
	    bits32 _z;
	    bits32 *_zPtr = (&aSig);
	    if (_count == 0) {
		_z = _a;
	    }
	    else if (_count < 32) {
		_z = (_a >> _count) | ((_a << ((-_count) & 31)) != 0);
	    }
	    else {
		_z = (_a != 0);
	    }
	    *(_zPtr) = _z;
	}
	zExp = bExp;
    }
    else {

#pragma if_prob(1,1000)

	if (aExp == 0xFF) {
	    if (aSig | bSig)
		return propagateFloat32NaN(a, b);
	    return a;
	}
	if (aExp == 0)
	    return ((((bits32) (zSign)) << 31) + (((bits32) (0)) << 23) +
		    ((aSig + bSig) >> 6));
	zSig = 0x40000000 + aSig + bSig;
	zExp = aExp;
	goto roundAndPack;
    }
    aSig |= 0x20000000;
    zSig = (aSig + bSig) << 1;
    --zExp;
    if ((sbits32) zSig < 0) {
	zSig = aSig + bSig;
	++zExp;
    }
  roundAndPack:
    return roundAndPackFloat32(zSign, zExp, zSig);
}

static float32 subFloat32Sigs(float32 a, float32 b, flag zSign)
{
    int16 aExp, bExp, zExp;
    bits32 aSig, bSig, zSig;
    int16 expDiff;

    aSig = ((a) & 0x007FFFFF);
    aExp = (((a) >> 23) & 0xFF);
    bSig = ((b) & 0x007FFFFF);
    bExp = (((b) >> 23) & 0xFF);
    expDiff = aExp - bExp;
    aSig <<= 7;
    bSig <<= 7;
    if (0 < expDiff)
	goto aExpBigger;
    if (expDiff < 0)
	goto bExpBigger;

#pragma if_prob(1,1000)

    if (aExp == 0xFF) {
	if (aSig | bSig)
	    return propagateFloat32NaN(a, b);
	float_raise(float_flag_invalid);
	return float32_default_nan;
    }
    if (aExp == 0) {
	aExp = 1;
	bExp = 1;
    }
    if (bSig < aSig)
	goto aBigger;
    if (aSig < bSig)
	goto bBigger;
    return ((((bits32) (float_rounding_mode == float_round_down)) << 31) +
	    (((bits32) (0)) << 23) + (0));
  bExpBigger:

#pragma if_prob(1,1000)

    if (bExp == 0xFF) {
	if (bSig)
	    return propagateFloat32NaN(a, b);
	return ((((bits32) (zSign ^ 1)) << 31) + (((bits32) (0xFF)) << 23) +
		(0));
    }
    if (aExp == 0) {
	++expDiff;
    }
    else {
	aSig |= 0x40000000;
    }
    {
	int16 _count = (-expDiff);
	bits32 _a = (aSig);
	bits32 _z;
	bits32 *_zPtr = (&aSig);
	if (_count == 0) {
	    _z = _a;
	}
	else if (_count < 32) {
	    _z = (_a >> _count) | ((_a << ((-_count) & 31)) != 0);
	}
	else {
	    _z = (_a != 0);
	}
	*(_zPtr) = _z;
    }
    bSig |= 0x40000000;
  bBigger:
    zSig = bSig - aSig;
    zExp = bExp;
    zSign ^= 1;
    goto normalizeRoundAndPack;
  aExpBigger:

#pragma if_prob(1,1000)

    if (aExp == 0xFF) {
	if (aSig)
	    return propagateFloat32NaN(a, b);
	return a;
    }
    if (bExp == 0) {
	--expDiff;
    }
    else {
	bSig |= 0x40000000;
    }
    {
	int16 _count = (expDiff);
	bits32 _a = (bSig);
	bits32 _z;
	bits32 *_zPtr = (&bSig);
	if (_count == 0) {
	    _z = _a;
	}
	else if (_count < 32) {
	    _z = (_a >> _count) | ((_a << ((-_count) & 31)) != 0);
	}
	else {
	    _z = (_a != 0);
	}
	*(_zPtr) = _z;
    }
    aSig |= 0x40000000;
  aBigger:
    zSig = aSig - bSig;
    zExp = aExp;
  normalizeRoundAndPack:
    --zExp;
    return normalizeRoundAndPackFloat32(zSign, zExp, zSig);
}

extern float32 _r_add(float32 a, float32 b)
{
    flag aSign, bSign;

    aSign = ((a) >> 31);
    bSign = ((b) >> 31);
    if (aSign == bSign) {
	return addFloat32Sigs(a, b, aSign);
    }
    else {
	return subFloat32Sigs(a, b, aSign);
    }
}

extern float32 _r_sub(float32 a, float32 b)
{
    flag aSign, bSign;

    aSign = ((a) >> 31);
    bSign = ((b) >> 31);
    if (aSign == bSign) {
	return subFloat32Sigs(a, b, aSign);
    }
    else {
	return addFloat32Sigs(a, b, aSign);
    }
}

extern float32 _r_mul(float32 a, float32 b)
{
    flag aSign, bSign, zSign;
    int16 aExp, bExp, zExp;
    bits32 aSig, bSig, zSig0, zSig1, z1, z2;

    aSig = ((a) & 0x007FFFFF);
    aExp = (((a) >> 23) & 0xFF);
    aSign = ((a) >> 31);
    bSig = ((b) & 0x007FFFFF);
    bExp = (((b) >> 23) & 0xFF);
    bSign = ((b) >> 31);
    zSign = aSign ^ bSign;

#pragma if_prob(1,1000)

    if (aExp == 0xFF) {
	if (aSig || ((bExp == 0xFF) && bSig)) {
	    return propagateFloat32NaN(a, b);
	}
	if ((bExp | bSig) == 0) {
	    float_raise(float_flag_invalid);
	    return float32_default_nan;
	}
	return ((((bits32) (zSign)) << 31) + (((bits32) (0xFF)) << 23) + (0));
    }

#pragma if_prob(1,1000)

    if (bExp == 0xFF) {
	if (bSig)
	    return propagateFloat32NaN(a, b);
	if ((aExp | aSig) == 0) {
	    float_raise(float_flag_invalid);
	    return float32_default_nan;
	}
	return ((((bits32) (zSign)) << 31) + (((bits32) (0xFF)) << 23) + (0));
    }

#pragma if_prob(1,1000)

    if (aExp == 0) {
	if (aSig == 0)
	    return ((((bits32) (zSign)) << 31) + (((bits32) (0)) << 23) + (0));
	{
	    int8 shiftCount = countLeadingZeros32(aSig) - 8;
	    *(&aSig) = (aSig) << shiftCount;
	    *(&aExp) = 1 - shiftCount;
	}
    }

#pragma if_prob(1,1000)

    if (bExp == 0) {
	if (bSig == 0)
	    return ((((bits32) (zSign)) << 31) + (((bits32) (0)) << 23) + (0));
	{
	    int8 shiftCount = countLeadingZeros32(bSig) - 8;
	    *(&bSig) = (bSig) << shiftCount;
	    *(&bExp) = 1 - shiftCount;
	}
    }
    zExp = aExp + bExp - 0x7F;
    aSig = (aSig | 0x00800000) << 7;
    bSig = (bSig | 0x00800000) << 8;

    {
	bits32 *_z0Ptr = (&z1);
	bits32 *_z1Ptr = (&z2);
	bits32 _a = (aSig);
	bits32 _b = (bSig);
	bits16 _aLow = _a;
	bits16 _aHigh = _a >> 16;
	bits16 _bLow = _b;
	bits16 _bHigh = _b >> 16;
	bits32 _z1 = ((bits32) _aLow) * _bLow;
	bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	_zMiddleA += _zMiddleB;
	_z0 += (((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	_zMiddleA <<= 16;
	_z1 += _zMiddleA;
	_z0 += (_z1 < _zMiddleA);
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    zSig0 = z1;
    zSig1 = z2;
    zSig0 |= (zSig1 != 0);

    if (0 <= (sbits32) (zSig0 << 1)) {
	zSig0 <<= 1;
	--zExp;
    }
    return roundAndPackFloat32(zSign, zExp, zSig0);
}

extern float32 _r_div(float32 a, float32 b)
{
    flag aSign, bSign, zSign;
    int16 aExp, bExp, zExp;
    bits32 aSig, bSig, zSig;
    bits32 rem0, rem1;
    bits32 term0, term1;

    aSig = ((a) & 0x007FFFFF);
    aExp = (((a) >> 23) & 0xFF);
    aSign = ((a) >> 31);
    bSig = ((b) & 0x007FFFFF);
    bExp = (((b) >> 23) & 0xFF);
    bSign = ((b) >> 31);
    zSign = aSign ^ bSign;

#pragma if_prob(1,1000)

    if (aExp == 0xFF) {
	if (aSig)
	    return propagateFloat32NaN(a, b);
	if (bExp == 0xFF) {
	    if (bSig)
		return propagateFloat32NaN(a, b);
	    float_raise(float_flag_invalid);
	    return float32_default_nan;
	}
	return ((((bits32) (zSign)) << 31) + (((bits32) (0xFF)) << 23) + (0));
    }

#pragma if_prob(1,1000)

    if (bExp == 0xFF) {
	if (bSig)
	    return propagateFloat32NaN(a, b);
	return ((((bits32) (zSign)) << 31) + (((bits32) (0)) << 23) + (0));
    }

#pragma if_prob(1,1000)

    if (bExp == 0) {
	if (bSig == 0) {
	    if ((aExp | aSig) == 0) {
		float_raise(float_flag_invalid);
		return float32_default_nan;
	    }
	    float_raise(float_flag_divbyzero);
	    return ((((bits32) (zSign)) << 31) + (((bits32) (0xFF)) << 23) +
		    (0));
	}
	{
	    int8 shiftCount = countLeadingZeros32(bSig) - 8;
	    *(&bSig) = (bSig) << shiftCount;
	    *(&bExp) = 1 - shiftCount;
	}
    }

#pragma if_prob(1,1000)

    if (aExp == 0) {
	if (aSig == 0)
	    return ((((bits32) (zSign)) << 31) + (((bits32) (0)) << 23) + (0));
	{
	    int8 shiftCount = countLeadingZeros32(aSig) - 8;
	    *(&aSig) = (aSig) << shiftCount;
	    *(&aExp) = 1 - shiftCount;
	}
    }
    zExp = aExp - bExp + 0x7D;
    aSig = (aSig | 0x00800000) << 7;
    bSig = (bSig | 0x00800000) << 8;
    if (bSig <= (aSig + aSig)) {
	aSig >>= 1;
	++zExp;
    }
    zSig = estimateDiv64To32(aSig, 0, bSig);
    if ((zSig & 0x3F) <= 2) {
	{
	    bits32 *_z0Ptr = (&term0);
	    bits32 *_z1Ptr = (&term1);
	    bits32 _a = (bSig);
	    bits32 _b = (zSig);
	    bits16 _aLow = _a;
	    bits16 _aHigh = _a >> 16;
	    bits16 _bLow = _b;
	    bits16 _bHigh = _b >> 16;
	    bits32 _z1 = ((bits32) _aLow) * _bLow;
	    bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	    bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	    bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	    _zMiddleA += _zMiddleB;
	    _z0 +=
		(((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	    _zMiddleA <<= 16;
	    _z1 += _zMiddleA;
	    _z0 += (_z1 < _zMiddleA);
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
	{
	    bits32 *_z0Ptr = (&rem0);
	    bits32 *_z1Ptr = (&rem1);
	    bits32 _a0 = (aSig);
	    bits32 _a1 = (0);
	    bits32 _b0 = (term0);
	    bits32 _b1 = (term1);
	    *(_z1Ptr) = _a1 - _b1;
	    *(_z0Ptr) = _a0 - _b0 - (_a1 < _b1);
	}
	while ((sbits32) rem0 < 0) {
	    --zSig;
	    {
		bits32 *_z0Ptr = (bits32 *) (&rem0);
		bits32 *_z1Ptr = (bits32 *) (&rem1);
		bits32 _a0 = (rem0);
		bits32 _a1 = (rem1);
		bits32 _b0 = (0);
		bits32 _b1 = (bSig);
		bits32 _z1 = _a1 + _b1;
		*(_z1Ptr) = _z1;
		*(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	    }
	}
	zSig |= (rem1 != 0);
    }
    return roundAndPackFloat32(zSign, zExp, zSig);
}

extern flag _r_eq(float32 a, float32 b)
{

#pragma if_prob(1,1000)

    if ((((((a) >> 23) & 0xFF) == 0xFF) && ((a) & 0x007FFFFF))
	|| (((((b) >> 23) & 0xFF) == 0xFF) && ((b) & 0x007FFFFF))
	) {
	if ((((((a) >> 22) & 0x1FF) == 0x1FE) && ((a) & 0x003FFFFF))
	    || (((((b) >> 22) & 0x1FF) == 0x1FE) && ((b) & 0x003FFFFF))) {
	    float_raise(float_flag_invalid);
	}
	return 0;
    }
    return (a == b) || ((bits32) ((a | b) << 1) == 0);
}

extern flag _r_le(float32 a, float32 b)
{
    flag aSign, bSign;

#pragma if_prob(1,1000)

    if ((((((a) >> 23) & 0xFF) == 0xFF) && ((a) & 0x007FFFFF))
	|| (((((b) >> 23) & 0xFF) == 0xFF) && ((b) & 0x007FFFFF))
	) {
	float_raise(float_flag_invalid);
	return 0;
    }
    aSign = ((a) >> 31);
    bSign = ((b) >> 31);
    if (aSign != bSign)
	return aSign || ((bits32) ((a | b) << 1) == 0);
    return (a == b) || (aSign ^ (a < b));
}

extern flag _r_lt(float32 a, float32 b)
{
    flag aSign, bSign;

#pragma if_prob(1,1000)

    if ((((((a) >> 23) & 0xFF) == 0xFF) && ((a) & 0x007FFFFF))
	|| (((((b) >> 23) & 0xFF) == 0xFF) && ((b) & 0x007FFFFF))
	) {
	float_raise(float_flag_invalid);
	return 0;
    }
    aSign = ((a) >> 31);
    bSign = ((b) >> 31);
    if (aSign != bSign)
	return aSign && ((bits32) ((a | b) << 1) != 0);
    return (a != b) && (aSign ^ (a < b));
}

static int32 float64_to_int32_round_to_zero(float64 a, flag is_signed)
{
    flag aSign;
    int16 aExp, shiftCount;
    bits32 aSig0, aSig1, absZ, zExtra;
    int32 z;
    int8 roundingMode;

    aSig1 = ((a).low);
    aSig0 = ((a).high & 0x000FFFFF);
    aExp = (((a).high >> 20) & 0x7FF);
    aSign = ((a).high >> 31);
    shiftCount = aExp - 0x413;
    if (0 <= shiftCount) {
	if (11 < shiftCount) {
	    if ((aExp == 0x7FF) && (aSig0 | aSig1))
		aSign = 0;
	    absZ = is_signed ? 0xC0000000 : 0xFFFFFFFF;
	}
	else {
	    {
		bits32 *_z0Ptr = (&absZ);
		bits32 *_z1Ptr = (&zExtra);
		bits32 _a0 = (aSig0 | 0x00100000);
		bits32 _a1 = (aSig1);
		int16 _count = (shiftCount);
		*_z1Ptr = _a1 << _count;
		*_z0Ptr =
		    (_count ==
		     0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
	    }
	}
    }
    else {
	if (aExp < 0x3FE) {
	    zExtra = aExp | aSig0 | aSig1;
	    absZ = 0;
	}
	else {
	    aSig0 |= 0x00100000;
	    zExtra = (aSig0 << (shiftCount & 31)) | aSig1;
	    absZ = aSig0 >> (-shiftCount);
	}
    }
    z = aSign ? -absZ : absZ;

#pragma if_prob(1,1000)

    if ((aSign ^ (z < 0)) && z) {
	if (is_signed || aSign) {
	    float_raise(float_flag_invalid);
	    if (is_signed)
		return aSign ? 0x80000000 : 0x7FFFFFFF;
	    else
		return aSign ? 0x0 : 0xFFFFFFFF;
	}
    }
    if (zExtra)
	float_exception_flags |= float_flag_inexact;
    return z;
}

extern float32 _r_d(float64 a)
{
    flag aSign;
    int16 aExp;
    bits32 aSig0, aSig1, zSig;
    bits32 allZero;

    aSig1 = ((a).low);
    aSig0 = ((a).high & 0x000FFFFF);
    aExp = (((a).high >> 20) & 0x7FF);
    aSign = ((a).high >> 31);
    if (aExp == 0x7FF) {
	if (aSig0 | aSig1) {
	    return ((((bits32) (float64ToCommonNaN(a)).
		      sign) << 31) | 0x7FC00000 | ((float64ToCommonNaN(a)).
						   high >> 9));
	}
	return ((((bits32) (aSign)) << 31) + (((bits32) (0xFF)) << 23) + (0));
    }
    {
	bits32 _a0 = (aSig0);
	bits32 _a1 = (aSig1);
	int16 _count = (22);
	bits32 _z0, _z1;
	int32 negCount = (-_count) & 31;
	bits32 *_z0Ptr = (&allZero);
	bits32 *_z1Ptr = (&zSig);
	if (_count == 0) {
	    _z1 = _a1;
	    _z0 = _a0;
	}
	else if (_count < 32) {
	    _z1 =
		(_a0 << negCount) | (_a1 >> _count) | ((_a1 << negCount) != 0);
	    _z0 = _a0 >> _count;
	}
	else {
	    if (_count == 32) {
		_z1 = _a0 | (_a1 != 0);
	    }
	    else if (_count < 64) {
		_z1 = (_a0 >> (_count & 31)) | (((_a0 << negCount) | _a1) != 0);
	    }
	    else {
		_z1 = ((_a0 | _a1) != 0);
	    }
	    _z0 = 0;
	}
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    if (aExp)
	zSig |= 0x40000000;
    return roundAndPackFloat32(aSign, aExp - 0x381, zSig);
}

static float64 addFloat64Sigs(float64 a, float64 b, flag zSign)
{
    int16 aExp, bExp, zExp;
    bits32 aSig0, aSig1, bSig0, bSig1, zSig0, zSig1, zSig2;
    int16 expDiff;

    aSig1 = ((a).low);
    aSig0 = ((a).high & 0x000FFFFF);
    aExp = (((a).high >> 20) & 0x7FF);
    bSig1 = ((b).low);
    bSig0 = ((b).high & 0x000FFFFF);
    bExp = (((b).high >> 20) & 0x7FF);
    expDiff = aExp - bExp;
    if (0 < expDiff) {
	if (aExp == 0x7FF) {
	    if (aSig0 | aSig1)
		return propagateFloat64NaN(a, b);
	    return a;
	}
	if (bExp == 0) {
	    --expDiff;
	}
	else {
	    bSig0 |= 0x00100000;
	}
	{
	    bits32 _a0 = (bSig0);
	    bits32 _a1 = (bSig1);
	    bits32 _a2 = (0);
	    int16 _count = (expDiff);
	    int8 negCount = (-_count) & 31;
	    bits32 _z0, _z1, _z2;
	    bits32 *_z0Ptr = (&bSig0);
	    bits32 *_z1Ptr = (&bSig1);
	    bits32 *_z2Ptr = (&zSig2);
	    if (_count == 0) {
		_z0 = _a0;
		_z1 = _a1;
		_z2 = _a2;
	    }
	    else {
		if (_count < 32) {
		    _z2 = _a1 << negCount;
		    _z1 = (_a0 << negCount) | (_a1 >> _count);
		    _z0 = _a0 >> _count;
		}
		else {
		    if (_count == 32) {
			_z2 = _a1;
			_z1 = _a0;
		    }
		    else {
			_a2 |= _a1;
			if (_count < 64) {
			    _z2 = _a0 << negCount;
			    _z1 = _a0 >> (_count & 31);
			}
			else {
			    _z2 = (_count == 64) ? _a0 : (_a0 != 0);
			    _z1 = 0;
			}
		    }
		    _z0 = 0;
		}
		_z2 |= (_a2 != 0);
	    }
	    *(_z2Ptr) = _z2;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
	zExp = aExp;
    }
    else if (expDiff < 0) {
	if (bExp == 0x7FF) {
	    if (bSig0 | bSig1)
		return propagateFloat64NaN(a, b);
	    return packFloat64(zSign, 0x7FF, 0, 0);
	}
	if (aExp == 0) {
	    ++expDiff;
	}
	else {
	    aSig0 |= 0x00100000;
	}
	{
	    bits32 _a0 = (aSig0);
	    bits32 _a1 = (aSig1);
	    bits32 _a2 = (0);
	    int16 _count = (-expDiff);
	    int8 negCount = (-_count) & 31;
	    bits32 _z0, _z1, _z2;
	    bits32 *_z0Ptr = (&aSig0);
	    bits32 *_z1Ptr = (&aSig1);
	    bits32 *_z2Ptr = (&zSig2);
	    if (_count == 0) {
		_z0 = _a0;
		_z1 = _a1;
		_z2 = _a2;
	    }
	    else {
		if (_count < 32) {
		    _z2 = _a1 << negCount;
		    _z1 = (_a0 << negCount) | (_a1 >> _count);
		    _z0 = _a0 >> _count;
		}
		else {
		    if (_count == 32) {
			_z2 = _a1;
			_z1 = _a0;
		    }
		    else {
			_a2 |= _a1;
			if (_count < 64) {
			    _z2 = _a0 << negCount;
			    _z1 = _a0 >> (_count & 31);
			}
			else {
			    _z2 = (_count == 64) ? _a0 : (_a0 != 0);
			    _z1 = 0;
			}
		    }
		    _z0 = 0;
		}
		_z2 |= (_a2 != 0);
	    }
	    *(_z2Ptr) = _z2;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
	zExp = bExp;
    }
    else {
	if (aExp == 0x7FF) {
	    if (aSig0 | aSig1 | bSig0 | bSig1) {
		return propagateFloat64NaN(a, b);
	    }
	    return a;
	}
	{
	    bits32 *_z0Ptr = (bits32 *) (&zSig0);
	    bits32 *_z1Ptr = (bits32 *) (&zSig1);
	    bits32 _a0 = (aSig0);
	    bits32 _a1 = (aSig1);
	    bits32 _b0 = (bSig0);
	    bits32 _b1 = (bSig1);
	    bits32 _z1 = _a1 + _b1;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	}
	if (aExp == 0)
	    return packFloat64(zSign, 0, zSig0, zSig1);
	zSig2 = 0;
	zSig0 |= 0x00200000;
	zExp = aExp;
	goto shiftRight1;
    }
    aSig0 |= 0x00100000;
    {
	bits32 *_z0Ptr = (bits32 *) (&zSig0);
	bits32 *_z1Ptr = (bits32 *) (&zSig1);
	bits32 _a0 = (aSig0);
	bits32 _a1 = (aSig1);
	bits32 _b0 = (bSig0);
	bits32 _b1 = (bSig1);
	bits32 _z1 = _a1 + _b1;
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
    }
    --zExp;
    if (zSig0 < 0x00200000)
	goto roundAndPack;
    ++zExp;
  shiftRight1:
    {
	bits32 _a0 = (zSig0);
	bits32 _a1 = (zSig1);
	bits32 _a2 = (zSig2);
	int16 _count = (1);
	int8 negCount = (-_count) & 31;
	bits32 _z0, _z1, _z2;
	bits32 *_z0Ptr = (&zSig0);
	bits32 *_z1Ptr = (&zSig1);
	bits32 *_z2Ptr = (&zSig2);
	if (_count == 0) {
	    _z0 = _a0;
	    _z1 = _a1;
	    _z2 = _a2;
	}
	else {
	    if (_count < 32) {
		_z2 = _a1 << negCount;
		_z1 = (_a0 << negCount) | (_a1 >> _count);
		_z0 = _a0 >> _count;
	    }
	    else {
		if (_count == 32) {
		    _z2 = _a1;
		    _z1 = _a0;
		}
		else {
		    _a2 |= _a1;
		    if (_count < 64) {
			_z2 = _a0 << negCount;
			_z1 = _a0 >> (_count & 31);
		    }
		    else {
			_z2 = (_count == 64) ? _a0 : (_a0 != 0);
			_z1 = 0;
		    }
		}
		_z0 = 0;
	    }
	    _z2 |= (_a2 != 0);
	}
	*(_z2Ptr) = _z2;
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
  roundAndPack:
    return roundAndPackFloat64(zSign, zExp, zSig0, zSig1, zSig2);
}

static float64 subFloat64Sigs(float64 a, float64 b, flag zSign)
{
    int16 aExp, bExp, zExp;
    bits32 aSig0, aSig1, bSig0, bSig1, zSig0, zSig1;
    int16 expDiff;
    float64 z;

    aSig1 = ((a).low);
    aSig0 = ((a).high & 0x000FFFFF);
    aExp = (((a).high >> 20) & 0x7FF);
    bSig1 = ((b).low);
    bSig0 = ((b).high & 0x000FFFFF);
    bExp = (((b).high >> 20) & 0x7FF);
    expDiff = aExp - bExp;
    {
	bits32 *_z0Ptr = (&aSig0);
	bits32 *_z1Ptr = (&aSig1);
	bits32 _a0 = (aSig0);
	bits32 _a1 = (aSig1);
	int16 _count = (10);
	*_z1Ptr = _a1 << _count;
	*_z0Ptr =
	    (_count == 0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
    }
    {
	bits32 *_z0Ptr = (&bSig0);
	bits32 *_z1Ptr = (&bSig1);
	bits32 _a0 = (bSig0);
	bits32 _a1 = (bSig1);
	int16 _count = (10);
	*_z1Ptr = _a1 << _count;
	*_z0Ptr =
	    (_count == 0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
    }
    if (0 < expDiff)
	goto aExpBigger;
    if (expDiff < 0)
	goto bExpBigger;

#pragma if_prob(1,1000)

    if (aExp == 0x7FF) {
	if (aSig0 | aSig1 | bSig0 | bSig1) {
	    return propagateFloat64NaN(a, b);
	}
	float_raise(float_flag_invalid);
	z.low = float64_default_nan_low;
	z.high = float64_default_nan_high;
	return z;
    }
    if (aExp == 0) {
	aExp = 1;
	bExp = 1;
    }
    if (bSig0 < aSig0)
	goto aBigger;
    if (aSig0 < bSig0)
	goto bBigger;
    if (bSig1 < aSig1)
	goto aBigger;
    if (aSig1 < bSig1)
	goto bBigger;
    return packFloat64(float_rounding_mode == float_round_down, 0, 0, 0);
  bExpBigger:
    if (bExp == 0x7FF) {
	if (bSig0 | bSig1)
	    return propagateFloat64NaN(a, b);
	return packFloat64(zSign ^ 1, 0x7FF, 0, 0);
    }
    if (aExp == 0) {
	++expDiff;
    }
    else {
	aSig0 |= 0x40000000;
    }
    {
	bits32 _a0 = (aSig0);
	bits32 _a1 = (aSig1);
	int16 _count = (-expDiff);
	bits32 _z0, _z1;
	int32 negCount = (-_count) & 31;
	bits32 *_z0Ptr = (&aSig0);
	bits32 *_z1Ptr = (&aSig1);
	if (_count == 0) {
	    _z1 = _a1;
	    _z0 = _a0;
	}
	else if (_count < 32) {
	    _z1 =
		(_a0 << negCount) | (_a1 >> _count) | ((_a1 << negCount) != 0);
	    _z0 = _a0 >> _count;
	}
	else {
	    if (_count == 32) {
		_z1 = _a0 | (_a1 != 0);
	    }
	    else if (_count < 64) {
		_z1 = (_a0 >> (_count & 31)) | (((_a0 << negCount) | _a1) != 0);
	    }
	    else {
		_z1 = ((_a0 | _a1) != 0);
	    }
	    _z0 = 0;
	}
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    bSig0 |= 0x40000000;
  bBigger:
    {
	bits32 *_z0Ptr = (&zSig0);
	bits32 *_z1Ptr = (&zSig1);
	bits32 _a0 = (bSig0);
	bits32 _a1 = (bSig1);
	bits32 _b0 = (aSig0);
	bits32 _b1 = (aSig1);
	*(_z1Ptr) = _a1 - _b1;
	*(_z0Ptr) = _a0 - _b0 - (_a1 < _b1);
    }
    zExp = bExp;
    zSign ^= 1;
    goto normalizeRoundAndPack;
  aExpBigger:
    if (aExp == 0x7FF) {
	if (aSig0 | aSig1)
	    return propagateFloat64NaN(a, b);
	return a;
    }
    if (bExp == 0) {
	--expDiff;
    }
    else {
	bSig0 |= 0x40000000;
    }
    {
	bits32 _a0 = (bSig0);
	bits32 _a1 = (bSig1);
	int16 _count = (expDiff);
	bits32 _z0, _z1;
	int32 negCount = (-_count) & 31;
	bits32 *_z0Ptr = (&bSig0);
	bits32 *_z1Ptr = (&bSig1);
	if (_count == 0) {
	    _z1 = _a1;
	    _z0 = _a0;
	}
	else if (_count < 32) {
	    _z1 =
		(_a0 << negCount) | (_a1 >> _count) | ((_a1 << negCount) != 0);
	    _z0 = _a0 >> _count;
	}
	else {
	    if (_count == 32) {
		_z1 = _a0 | (_a1 != 0);
	    }
	    else if (_count < 64) {
		_z1 = (_a0 >> (_count & 31)) | (((_a0 << negCount) | _a1) != 0);
	    }
	    else {
		_z1 = ((_a0 | _a1) != 0);
	    }
	    _z0 = 0;
	}
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    aSig0 |= 0x40000000;
  aBigger:
    {
	bits32 *_z0Ptr = (&zSig0);
	bits32 *_z1Ptr = (&zSig1);
	bits32 _a0 = (aSig0);
	bits32 _a1 = (aSig1);
	bits32 _b0 = (bSig0);
	bits32 _b1 = (bSig1);
	*(_z1Ptr) = _a1 - _b1;
	*(_z0Ptr) = _a0 - _b0 - (_a1 < _b1);
    }
    zExp = aExp;
  normalizeRoundAndPack:
    --zExp;
    return normalizeRoundAndPackFloat64(zSign, zExp - 10, zSig0, zSig1);
}

extern float64 _d_add(float64 a, float64 b)
{
    flag aSign, bSign;

    aSign = ((a).high >> 31);
    bSign = ((b).high >> 31);
    return aSign == bSign ? addFloat64Sigs(a, b, aSign) : subFloat64Sigs(a, b, aSign);
}

extern float64 _d_sub(float64 a, float64 b)
{
    flag aSign, bSign;

    aSign = ((a).high >> 31);
    bSign = ((b).high >> 31);
    return aSign == bSign ?  subFloat64Sigs(a, b, aSign) : addFloat64Sigs(a, b, aSign);
}

extern float64 _d_mul(float64 a, float64 b)
{
    flag aSign, bSign, zSign;
    int16 aExp, bExp, zExp;
    bits32 aSig0, aSig1, bSig0, bSig1, zSig0, zSig1, zSig2, zSig3;
    float64 z;

    aSig1 = ((a).low);
    aSig0 = ((a).high & 0x000FFFFF);
    aExp = (((a).high >> 20) & 0x7FF);
    aSign = ((a).high >> 31);
    bSig1 = ((b).low);
    bSig0 = ((b).high & 0x000FFFFF);
    bExp = (((b).high >> 20) & 0x7FF);
    bSign = ((b).high >> 31);
    zSign = aSign ^ bSign;

#pragma if_prob(1,1000)

    if (aExp == 0x7FF) {
	if ((aSig0 | aSig1)
	    || ((bExp == 0x7FF) && (bSig0 | bSig1))) {
	    return propagateFloat64NaN(a, b);
	}
	if ((bExp | bSig0 | bSig1) == 0)
	    goto invalid;
	return packFloat64(zSign, 0x7FF, 0, 0);
    }

#pragma if_prob(1,1000)

    if (bExp == 0x7FF) {
	if (bSig0 | bSig1)
	    return propagateFloat64NaN(a, b);
	if ((aExp | aSig0 | aSig1) == 0) {
	  invalid:
	    float_raise(float_flag_invalid);
	    z.low = float64_default_nan_low;
	    z.high = float64_default_nan_high;
	    return z;
	}
	return packFloat64(zSign, 0x7FF, 0, 0);
    }

#pragma if_prob(1,1000)

    if (aExp == 0) {
	if ((aSig0 | aSig1) == 0)
	    return packFloat64(zSign, 0, 0, 0);
	normalizeFloat64Subnormal(aSig0, aSig1, &aExp, &aSig0, &aSig1);
    }

#pragma if_prob(1,1000)

    if (bExp == 0) {
	if ((bSig0 | bSig1) == 0)
	    return packFloat64(zSign, 0, 0, 0);
	normalizeFloat64Subnormal(bSig0, bSig1, &bExp, &bSig0, &bSig1);
    }
    zExp = aExp + bExp - 0x400;
    aSig0 |= 0x00100000;
    {
	bits32 *_z0Ptr = (&bSig0);
	bits32 *_z1Ptr = (&bSig1);
	bits32 _a0 = (bSig0);
	bits32 _a1 = (bSig1);
	int16 _count = (12);
	*_z1Ptr = _a1 << _count;
	*_z0Ptr =
	    (_count == 0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
    }
    {
	bits32 *_z0Ptr = (&zSig0);
	bits32 *_z1Ptr = (&zSig1);
	bits32 *_z2Ptr = (&zSig2);
	bits32 *_z3Ptr = (&zSig3);
	bits32 __a0 = (aSig0);
	bits32 __a1 = (aSig1);
	bits32 __b0 = (bSig0);
	bits32 __b1 = (bSig1);
	bits32 _zz0, _zz1, _zz2, _zz3;
	bits32 _more1, _more2; {
	    bits32 *_z0Ptr = (&_zz2);
	    bits32 *_z1Ptr = (&_zz3);
	    bits32 _a = (__a1);
	    bits32 _b = (__b1);
	    bits16 _aLow = _a;
	    bits16 _aHigh = _a >> 16;
	    bits16 _bLow = _b;
	    bits16 _bHigh = _b >> 16;
	    bits32 _z1 = ((bits32) _aLow) * _bLow;
	    bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	    bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	    bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	    _zMiddleA += _zMiddleB;
	    _z0 +=
		(((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	    _zMiddleA <<= 16;
	    _z1 += _zMiddleA;
	    _z0 += (_z1 < _zMiddleA);
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	} {
	    bits32 *_z0Ptr = (&_zz1);
	    bits32 *_z1Ptr = (&_more2);
	    bits32 _a = (__a1);
	    bits32 _b = (__b0);
	    bits16 _aLow = _a;
	    bits16 _aHigh = _a >> 16;
	    bits16 _bLow = _b;
	    bits16 _bHigh = _b >> 16;
	    bits32 _z1 = ((bits32) _aLow) * _bLow;
	    bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	    bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	    bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	    _zMiddleA += _zMiddleB;
	    _z0 +=
		(((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	    _zMiddleA <<= 16;
	    _z1 += _zMiddleA;
	    _z0 += (_z1 < _zMiddleA);
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	} {
	    bits32 *_z0Ptr = (bits32 *) (&_zz1);
	    bits32 *_z1Ptr = (bits32 *) (&_zz2);
	    bits32 _a0 = (_zz1);
	    bits32 _a1 = (_more2);
	    bits32 _b0 = (0);
	    bits32 _b1 = (_zz2);
	    bits32 _z1 = _a1 + _b1;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	} {
	    bits32 *_z0Ptr = (&_zz0);
	    bits32 *_z1Ptr = (&_more1);
	    bits32 _a = (__a0);
	    bits32 _b = (__b0);
	    bits16 _aLow = _a;
	    bits16 _aHigh = _a >> 16;
	    bits16 _bLow = _b;
	    bits16 _bHigh = _b >> 16;
	    bits32 _z1 = ((bits32) _aLow) * _bLow;
	    bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	    bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	    bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	    _zMiddleA += _zMiddleB;
	    _z0 +=
		(((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	    _zMiddleA <<= 16;
	    _z1 += _zMiddleA;
	    _z0 += (_z1 < _zMiddleA);
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	} {
	    bits32 *_z0Ptr = (bits32 *) (&_zz0);
	    bits32 *_z1Ptr = (bits32 *) (&_zz1);
	    bits32 _a0 = (_zz0);
	    bits32 _a1 = (_more1);
	    bits32 _b0 = (0);
	    bits32 _b1 = (_zz1);
	    bits32 _z1 = _a1 + _b1;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	} {
	    bits32 *_z0Ptr = (&_more1);
	    bits32 *_z1Ptr = (&_more2);
	    bits32 _a = (__a0);
	    bits32 _b = (__b1);
	    bits16 _aLow = _a;
	    bits16 _aHigh = _a >> 16;
	    bits16 _bLow = _b;
	    bits16 _bHigh = _b >> 16;
	    bits32 _z1 = ((bits32) _aLow) * _bLow;
	    bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	    bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	    bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	    _zMiddleA += _zMiddleB;
	    _z0 +=
		(((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	    _zMiddleA <<= 16;
	    _z1 += _zMiddleA;
	    _z0 += (_z1 < _zMiddleA);
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	} {
	    bits32 *_z0Ptr = (bits32 *) (&_more1);
	    bits32 *_z1Ptr = (bits32 *) (&_zz2);
	    bits32 _a0 = (_more1);
	    bits32 _a1 = (_more2);
	    bits32 _b0 = (0);
	    bits32 _b1 = (_zz2);
	    bits32 _z1 = _a1 + _b1;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	} {
	    bits32 *_z0Ptr = (bits32 *) (&_zz0);
	    bits32 *_z1Ptr = (bits32 *) (&_zz1);
	    bits32 _a0 = (_zz0);
	    bits32 _a1 = (_zz1);
	    bits32 _b0 = (0);
	    bits32 _b1 = (_more1);
	    bits32 _z1 = _a1 + _b1;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	}
	*(_z3Ptr) = _zz3;
	*(_z2Ptr) = _zz2;
	*(_z1Ptr) = _zz1;
	*(_z0Ptr) = _zz0;
    }
    {
	bits32 *_z0Ptr = (bits32 *) (&zSig0);
	bits32 *_z1Ptr = (bits32 *) (&zSig1);
	bits32 _a0 = (zSig0);
	bits32 _a1 = (zSig1);
	bits32 _b0 = (aSig0);
	bits32 _b1 = (aSig1);
	bits32 _z1 = _a1 + _b1;
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
    }
    zSig2 |= (zSig3 != 0);
    if (0x00200000 <= zSig0) {
	{
	    bits32 _a0 = (zSig0);
	    bits32 _a1 = (zSig1);
	    bits32 _a2 = (zSig2);
	    int16 _count = (1);
	    int8 negCount = (-_count) & 31;
	    bits32 _z0, _z1, _z2;
	    bits32 *_z0Ptr = (&zSig0);
	    bits32 *_z1Ptr = (&zSig1);
	    bits32 *_z2Ptr = (&zSig2);
	    if (_count == 0) {
		_z0 = _a0;
		_z1 = _a1;
		_z2 = _a2;
	    }
	    else {
		if (_count < 32) {
		    _z2 = _a1 << negCount;
		    _z1 = (_a0 << negCount) | (_a1 >> _count);
		    _z0 = _a0 >> _count;
		}
		else {
		    if (_count == 32) {
			_z2 = _a1;
			_z1 = _a0;
		    }
		    else {
			_a2 |= _a1;
			if (_count < 64) {
			    _z2 = _a0 << negCount;
			    _z1 = _a0 >> (_count & 31);
			}
			else {
			    _z2 = (_count == 64) ? _a0 : (_a0 != 0);
			    _z1 = 0;
			}
		    }
		    _z0 = 0;
		}
		_z2 |= (_a2 != 0);
	    }
	    *(_z2Ptr) = _z2;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
	++zExp;
    }
    return roundAndPackFloat64(zSign, zExp, zSig0, zSig1, zSig2);
}

extern float64 _d_div(float64 a, float64 b)
{
    flag aSign, bSign, zSign;
    int16 aExp, bExp, zExp;
    bits32 aSig0, aSig1, bSig0, bSig1, zSig0, zSig1, zSig2;
    bits32 rem0, rem1, rem2, rem3, term0, term1, term2, term3;
    float64 z;

    aSig1 = ((a).low);
    aSig0 = ((a).high & 0x000FFFFF);
    aExp = (((a).high >> 20) & 0x7FF);
    aSign = ((a).high >> 31);
    bSig1 = ((b).low);
    bSig0 = ((b).high & 0x000FFFFF);
    bExp = (((b).high >> 20) & 0x7FF);
    bSign = ((b).high >> 31);
    zSign = aSign ^ bSign;

#pragma if_prob(1,1000)

    if (aExp == 0x7FF) {
	if (aSig0 | aSig1)
	    return propagateFloat64NaN(a, b);
	if (bExp == 0x7FF) {
	    if (bSig0 | bSig1)
		return propagateFloat64NaN(a, b);
	    goto invalid;
	}
	return packFloat64(zSign, 0x7FF, 0, 0);
    }

#pragma if_prob(1,1000)

    if (bExp == 0x7FF) {
	if (bSig0 | bSig1)
	    return propagateFloat64NaN(a, b);
	return packFloat64(zSign, 0, 0, 0);
    }

#pragma if_prob(1,1000)

    if (bExp == 0) {
	if ((bSig0 | bSig1) == 0) {
	    if ((aExp | aSig0 | aSig1) == 0) {
	      invalid:
		float_raise(float_flag_invalid);
		z.low = float64_default_nan_low;
		z.high = float64_default_nan_high;
		return z;
	    }
	    float_raise(float_flag_divbyzero);
	    return packFloat64(zSign, 0x7FF, 0, 0);
	}
	normalizeFloat64Subnormal(bSig0, bSig1, &bExp, &bSig0, &bSig1);
    }

#pragma if_prob(1,1000)

    if (aExp == 0) {
	if ((aSig0 | aSig1) == 0)
	    return packFloat64(zSign, 0, 0, 0);
	normalizeFloat64Subnormal(aSig0, aSig1, &aExp, &aSig0, &aSig1);
    }
    zExp = aExp - bExp + 0x3FD;
    {
	bits32 *_z0Ptr = (&aSig0);
	bits32 *_z1Ptr = (&aSig1);
	bits32 _a0 = (aSig0 | 0x00100000);
	bits32 _a1 = (aSig1);
	int16 _count = (11);
	*_z1Ptr = _a1 << _count;
	*_z0Ptr =
	    (_count == 0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
    }
    {
	bits32 *_z0Ptr = (&bSig0);
	bits32 *_z1Ptr = (&bSig1);
	bits32 _a0 = (bSig0 | 0x00100000);
	bits32 _a1 = (bSig1);
	int16 _count = (11);
	*_z1Ptr = _a1 << _count;
	*_z0Ptr =
	    (_count == 0) ? _a0 : (_a0 << _count) | (_a1 >> ((-_count) & 31));
    }
    if ((((bSig0) < (aSig0)) || (((bSig0) == (aSig0)) && ((bSig1) <= (aSig1))))) {
	{
	    bits32 _a0 = aSig0;
	    bits32 _a1 = aSig1;
	    bits16 _count = 1;
	    bits32 _z0, _z1;
	    bits32 *_z0Ptr = (&aSig0);
	    bits32 *_z1Ptr = (&aSig1);
	    int8 negCount = (-_count) & 31;
	    if (_count == 0) {
		_z1 = _a1;
		_z0 = _a0;
	    }
	    else if (_count < 32) {
		_z1 = (_a0 << negCount) | (_a1 >> _count);
		_z0 = _a0 >> _count;
	    }
	    else {
		_z1 = (_count < 64) ? (_a0 >> (_count & 31)) : 0;
		_z0 = 0;
	    }
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
	++zExp;
    }
    zSig0 = estimateDiv64To32(aSig0, aSig1, bSig0);
    {
	bits32 *_z0Ptr = (&term0);
	bits32 *_z1Ptr = (&term1);
	bits32 *_z2Ptr = (&term2);
	bits32 __a0 = (bSig0);
	bits32 __a1 = (bSig1);
	bits32 __b = (zSig0);
	bits32 zz0, zz1, zz2, more1; {
	    bits32 *_z0Ptr = (&zz1);
	    bits32 *_z1Ptr = (&zz2);
	    bits32 _a = (__a1);
	    bits32 _b = (__b);
	    bits16 _aLow = _a;
	    bits16 _aHigh = _a >> 16;
	    bits16 _bLow = _b;
	    bits16 _bHigh = _b >> 16;
	    bits32 _z1 = ((bits32) _aLow) * _bLow;
	    bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	    bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	    bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	    _zMiddleA += _zMiddleB;
	    _z0 +=
		(((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	    _zMiddleA <<= 16;
	    _z1 += _zMiddleA;
	    _z0 += (_z1 < _zMiddleA);
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	} {
	    bits32 *_z0Ptr = (&zz0);
	    bits32 *_z1Ptr = (&more1);
	    bits32 _a = (__a0);
	    bits32 _b = (__b);
	    bits16 _aLow = _a;
	    bits16 _aHigh = _a >> 16;
	    bits16 _bLow = _b;
	    bits16 _bHigh = _b >> 16;
	    bits32 _z1 = ((bits32) _aLow) * _bLow;
	    bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
	    bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
	    bits32 _z0 = ((bits32) _aHigh) * _bHigh;
	    _zMiddleA += _zMiddleB;
	    _z0 +=
		(((bits32) (_zMiddleA < _zMiddleB)) << 16) + (_zMiddleA >> 16);
	    _zMiddleA <<= 16;
	    _z1 += _zMiddleA;
	    _z0 += (_z1 < _zMiddleA);
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	} {
	    bits32 *_z0Ptr = (bits32 *) (&zz0);
	    bits32 *_z1Ptr = (bits32 *) (&zz1);
	    bits32 _a0 = (zz0);
	    bits32 _a1 = (more1);
	    bits32 _b0 = (0);
	    bits32 _b1 = (zz1);
	    bits32 _z1 = _a1 + _b1;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	}
	*(_z2Ptr) = zz2;
	*(_z1Ptr) = zz1;
	*(_z0Ptr) = zz0;
    }
    {
	bits32 _a0 = (aSig0);
	bits32 _a1 = (aSig1);
	bits32 _a2 = (0);
	bits32 _b0 = (term0);
	bits32 _b1 = (term1);
	bits32 _b2 = (term2);
	bits32 _z2 = _a2 - _b2;
	bits32 _borrow1 = (_a2 < _b2);
	bits32 _z1 = _a1 - _b1;
	bits32 _borrow0 = (_a1 < _b1);
	bits32 _z0 = _a0 - _b0;
	bits32 *_z0Ptr = (&rem0);
	bits32 *_z1Ptr = (&rem1);
	bits32 *_z2Ptr = (&rem2);
	_z0 -= (_z1 < _borrow1);
	_z1 -= _borrow1;
	_z0 -= _borrow0;
	*(_z2Ptr) = _z2;
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    while ((sbits32) rem0 < 0) {
	--zSig0;
	{
	    bits32 *_z0Ptr = (&rem0);
	    bits32 *_z1Ptr = (&rem1);
	    bits32 *_z2Ptr = (&rem2);
	    bits32 _a0 = (rem0);
	    bits32 _a1 = (rem1);
	    bits32 _a2 = (rem2);
	    bits32 _b0 = (0);
	    bits32 _b1 = (bSig0);
	    bits32 _b2 = (bSig1);
	    bits32 _z2 = _a2 + _b2;
	    bits32 _carry1 = (_z2 < _a2);
	    bits32 _z1 = _a1 + _b1;
	    bits32 _carry0 = (_z1 < _a1);
	    bits32 _z0 = _a0 + _b0;
	    _z1 += _carry1;
	    _z0 += (_z1 < _carry1);
	    _z0 += _carry0;
	    *(_z2Ptr) = _z2;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
    }
    zSig1 = estimateDiv64To32(rem1, rem2, bSig0);
    if ((zSig1 & 0x3FF) <= 4) {
	{
	    bits32 *_z0Ptr = (&term1);
	    bits32 *_z1Ptr = (&term2);
	    bits32 *_z2Ptr = (&term3);
	    bits32 __a0 = (bSig0);
	    bits32 __a1 = (bSig1);
	    bits32 __b = (zSig1);
	    bits32 zz0, zz1, zz2, more1; {
		bits32 *_z0Ptr = (&zz1);
		bits32 *_z1Ptr = (&zz2);
		bits32 _a = (__a1);
		bits32 _b = (__b);
		bits16 _aLow = _a;
		bits16 _aHigh = _a >> 16;
		bits16 _bLow = _b;
		bits16 _bHigh = _b >> 16;
		bits32 _z1 = ((bits32) _aLow) * _bLow;
		bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
		bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
		bits32 _z0 = ((bits32) _aHigh) * _bHigh;
		_zMiddleA += _zMiddleB;
		_z0 +=
		    (((bits32) (_zMiddleA < _zMiddleB)) << 16) +
		    (_zMiddleA >> 16);
		_zMiddleA <<= 16;
		_z1 += _zMiddleA;
		_z0 += (_z1 < _zMiddleA);
		*(_z1Ptr) = _z1;
		*(_z0Ptr) = _z0;
	    } {
		bits32 *_z0Ptr = (&zz0);
		bits32 *_z1Ptr = (&more1);
		bits32 _a = (__a0);
		bits32 _b = (__b);
		bits16 _aLow = _a;
		bits16 _aHigh = _a >> 16;
		bits16 _bLow = _b;
		bits16 _bHigh = _b >> 16;
		bits32 _z1 = ((bits32) _aLow) * _bLow;
		bits32 _zMiddleA = ((bits32) _aLow) * _bHigh;
		bits32 _zMiddleB = ((bits32) _aHigh) * _bLow;
		bits32 _z0 = ((bits32) _aHigh) * _bHigh;
		_zMiddleA += _zMiddleB;
		_z0 +=
		    (((bits32) (_zMiddleA < _zMiddleB)) << 16) +
		    (_zMiddleA >> 16);
		_zMiddleA <<= 16;
		_z1 += _zMiddleA;
		_z0 += (_z1 < _zMiddleA);
		*(_z1Ptr) = _z1;
		*(_z0Ptr) = _z0;
	    } {
		bits32 *_z0Ptr = (bits32 *) (&zz0);
		bits32 *_z1Ptr = (bits32 *) (&zz1);
		bits32 _a0 = (zz0);
		bits32 _a1 = (more1);
		bits32 _b0 = (0);
		bits32 _b1 = (zz1);
		bits32 _z1 = _a1 + _b1;
		*(_z1Ptr) = _z1;
		*(_z0Ptr) = _a0 + _b0 + (_z1 < _a1);
	    }
	    *(_z2Ptr) = zz2;
	    *(_z1Ptr) = zz1;
	    *(_z0Ptr) = zz0;
	}
	{
	    bits32 _a0 = (rem1);
	    bits32 _a1 = (rem2);
	    bits32 _a2 = (0);
	    bits32 _b0 = (term1);
	    bits32 _b1 = (term2);
	    bits32 _b2 = (term3);
	    bits32 _z2 = _a2 - _b2;
	    bits32 _borrow1 = (_a2 < _b2);
	    bits32 _z1 = _a1 - _b1;
	    bits32 _borrow0 = (_a1 < _b1);
	    bits32 _z0 = _a0 - _b0;
	    bits32 *_z0Ptr = (&rem1);
	    bits32 *_z1Ptr = (&rem2);
	    bits32 *_z2Ptr = (&rem3);
	    _z0 -= (_z1 < _borrow1);
	    _z1 -= _borrow1;
	    _z0 -= _borrow0;
	    *(_z2Ptr) = _z2;
	    *(_z1Ptr) = _z1;
	    *(_z0Ptr) = _z0;
	}
	while ((sbits32) rem1 < 0) {
	    --zSig1;
	    {
		bits32 *_z0Ptr = (&rem1);
		bits32 *_z1Ptr = (&rem2);
		bits32 *_z2Ptr = (&rem3);
		bits32 _a0 = (rem1);
		bits32 _a1 = (rem2);
		bits32 _a2 = (rem3);
		bits32 _b0 = (0);
		bits32 _b1 = (bSig0);
		bits32 _b2 = (bSig1);
		bits32 _z2 = _a2 + _b2;
		bits32 _carry1 = (_z2 < _a2);
		bits32 _z1 = _a1 + _b1;
		bits32 _carry0 = (_z1 < _a1);
		bits32 _z0 = _a0 + _b0;
		_z1 += _carry1;
		_z0 += (_z1 < _carry1);
		_z0 += _carry0;
		*(_z2Ptr) = _z2;
		*(_z1Ptr) = _z1;
		*(_z0Ptr) = _z0;
	    }
	}
	zSig1 |= ((rem1 | rem2 | rem3) != 0);
    }
    {
	bits32 _a0 = (zSig0);
	bits32 _a1 = (zSig1);
	bits32 _a2 = (0);
	int16 _count = (11);
	int8 negCount = (-_count) & 31;
	bits32 _z0, _z1, _z2;
	bits32 *_z0Ptr = (&zSig0);
	bits32 *_z1Ptr = (&zSig1);
	bits32 *_z2Ptr = (&zSig2);
	if (_count == 0) {
	    _z0 = _a0;
	    _z1 = _a1;
	    _z2 = _a2;
	}
	else {
	    if (_count < 32) {
		_z2 = _a1 << negCount;
		_z1 = (_a0 << negCount) | (_a1 >> _count);
		_z0 = _a0 >> _count;
	    }
	    else {
		if (_count == 32) {
		    _z2 = _a1;
		    _z1 = _a0;
		}
		else {
		    _a2 |= _a1;
		    if (_count < 64) {
			_z2 = _a0 << negCount;
			_z1 = _a0 >> (_count & 31);
		    }
		    else {
			_z2 = (_count == 64) ? _a0 : (_a0 != 0);
			_z1 = 0;
		    }
		}
		_z0 = 0;
	    }
	    _z2 |= (_a2 != 0);
	}
	*(_z2Ptr) = _z2;
	*(_z1Ptr) = _z1;
	*(_z0Ptr) = _z0;
    }
    return roundAndPackFloat64(zSign, zExp, zSig0, zSig1, zSig2);
}

extern flag _d_eq(float64 a, float64 b)
{

#pragma if_prob(1,1000)

    if ((((((a).high >> 20) & 0x7FF) == 0x7FF)
	 && (((a).high & 0x000FFFFF) | ((a).low)))
	|| (((((b).high >> 20) & 0x7FF) == 0x7FF)
	    && (((b).high & 0x000FFFFF) | ((b).low)))
	) {
	if ((((((a).high >> 19) & 0xFFF) == 0xFFE)
	     && ((a).low || ((a).high & 0x0007FFFF)))
	    || (((((b).high >> 19) & 0xFFF) == 0xFFE)
		&& ((b).low || ((b).high & 0x0007FFFF)))) {
	    float_raise(float_flag_invalid);
	}
	return 0;
    }
    return (a.low == b.low)
	&& ((a.high == b.high)
	    || ((a.low == 0)
		&& ((bits32) ((a.high | b.high) << 1) == 0))
	);
}

extern flag _d_le(float64 a, float64 b)
{
    flag aSign, bSign;

#pragma if_prob(1,1000)

    if ((((((a).high >> 20) & 0x7FF) == 0x7FF)
	 && (((a).high & 0x000FFFFF) | ((a).low)))
	|| (((((b).high >> 20) & 0x7FF) == 0x7FF)
	    && (((b).high & 0x000FFFFF) | ((b).low)))
	) {
	float_raise(float_flag_invalid);
	return 0;
    }
    aSign = ((a).high >> 31);
    bSign = ((b).high >> 31);
    if (aSign != bSign) {
	return aSign || ((((bits32) ((a.high | b.high) << 1)) | a.low | b.low)
			 == 0);
    }
    return
	aSign ? (((b.high) < (a.high))
		 || (((b.high) == (a.high)) && ((b.low) <= (a.low))))
	: (((a.high) < (b.high))
	   || (((a.high) == (b.high)) && ((a.low) <= (b.low))));
}

extern flag _d_lt(float64 a, float64 b)
{
    flag aSign, bSign;

#pragma if_prob(1,1000)

    if ((((((a).high >> 20) & 0x7FF) == 0x7FF)
	 && (((a).high & 0x000FFFFF) | ((a).low)))
	|| (((((b).high >> 20) & 0x7FF) == 0x7FF)
	    && (((b).high & 0x000FFFFF) | ((b).low)))
	) {
	float_raise(float_flag_invalid);
	return 0;
    }
    aSign = ((a).high >> 31);
    bSign = ((b).high >> 31);
    if (aSign != bSign) {
	return aSign && ((((bits32) ((a.high | b.high) << 1)) | a.low | b.low)
			 != 0);
    }
    return
	aSign ? (((b.high) < (a.high))
		 || (((b.high) == (a.high)) && ((b.low) < (a.low))))
	: (((a.high) < (b.high))
	   || (((a.high) == (b.high)) && ((a.low) < (b.low))));
}

extern float32 _r_neg(float32 a)
{
    return a ^ 0x80000000;
}

extern float32 _r_recip(float32 a)
{
    float_float32 z;
    z.f = 1.0f;
    return _r_div(z.f32, a);
}

extern int _r_ne(float32 a, float32 b)
{
    return !_r_eq(a, b);
}

extern int _r_gt(float32 a, float32 b)
{
    return _r_lt(b, a);
}

extern int _r_ge(float32 a, float32 b)
{
    return _r_le(b, a);
}

extern float64 _d_neg(float64 a)
{
    a.high = a.high ^ 0x80000000;
    return a;
}

extern float64 _d_recip(float64 a)
{
    double_float64 z;
    z.d = 1.0;
    return _d_div(z.f64, a);
}

extern int _d_ne(float64 a, float64 b)
{
    return !_d_eq(a, b);
}

extern int _d_gt(float64 a, float64 b)
{
    return _d_lt(b, a);
}

extern int _d_ge(float64 a, float64 b)
{
    return _d_le(b, a);
}

extern int32 _r_fix(float32 a)
{
    return float32_to_int32_round_to_zero(a, 1);
}

extern uint32 _r_ufix(float32 a)
{
    return float32_to_int32_round_to_zero(a, 0);
}

extern int32 _d_fix(float64 a)
{
    return float64_to_int32_round_to_zero(a, 1);
}

extern uint32 _d_ufix(float64 a)
{
    return float64_to_int32_round_to_zero(a, 0);
}

extern int fpgetround(void)
{
    return float_rounding_mode;
}

extern int fpsetround(int mode)
{
    float_rounding_mode = mode;
    return mode;
}

extern int fpgetmask(void)
{
    return float_exception_mask;
}

extern int fpsetmask(int mode)
{
    float_exception_mask = mode;
    return mode;
}

extern int fpgetsticky(void)
{
    return float_exception_flags;
}

extern int fpsetsticky(int mode)
{
    float_exception_flags = mode;
    return mode;
}
