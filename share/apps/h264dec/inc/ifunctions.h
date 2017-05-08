
/*!
 ************************************************************************
 *  \file
 *     ifunctions.h
 *
 *  \brief
 *     define some inline functions that are used within the encoder.
 *
 *  \author
 *      Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Karsten Sühring                 <suehring@hhi.de>
 *      - Alexis Tourapis                 <alexismt@ieee.org>
 *
 ************************************************************************
 */
#ifndef _IFUNCTIONS_H_
#define _IFUNCTIONS_H_

#include <math.h>

#if defined(_vex_) && defined(_mfinline_) && !defined(_int64_debug_)
inline_declare {
inline_module ifunctions {
#define VEXINLINE inline
#else
#define VEXINLINE static
#endif

VEXINLINE int imin(int a, int b)
{
  return ((a) < (b)) ? (a) : (b);
}

VEXINLINE int imax(int a, int b)
{
  return ((a) > (b)) ? (a) : (b);
}

VEXINLINE double dmin(double a, double b)
{
  return ((a) < (b)) ? (a) : (b);
}

VEXINLINE double dmax(double a, double b)
{
  return ((a) > (b)) ? (a) : (b);
}

#ifdef _vex_

VEXINLINE int get_bit(int64 x,int n)
{
  return (int)((n<32 ? __lo64(x) >> n : __hi64(x) >> (n-32)) & 1);
}

VEXINLINE int64 i64min(int64 a, int64 b)
{
  return __lt64(a,b) ? a : b ;
}

VEXINLINE int64 i64max(int64 a, int64 b)
{
  return __gt64(a,b) ? a : b ;
}

VEXINLINE int64 i64abs(int64 x)
{
  return __lz64(x) ? __neg64(x): x;
}

VEXINLINE int64 i64abs2(int64 x)
{
  return __mul64(x,x);
}

#else

VEXINLINE int get_bit(int64 x,int n)
{
  return (int)(((x >> n) & 1));
}

VEXINLINE int64 i64min(int64 a, int64 b)
{
  return ((a) < (b)) ? (a) : (b);
}

VEXINLINE int64 i64max(int64 a, int64 b)
{
  return ((a) > (b)) ? (a) : (b);
}

VEXINLINE int64 i64abs(int64 x)
{
  return ((x) < 0) ? -(x) : (x);
}

VEXINLINE int64 i64abs2(int64 x)
{
  return (x) * (x);
}
#endif

VEXINLINE int sabs(short x)
{
  return ((x) < 0) ? -(x) : (x);
}

VEXINLINE int iabs(int x)
{
  return ((x) < 0) ? -(x) : (x);
}

VEXINLINE double dabs(double x)
{
  return ((x) < 0) ? -(x) : (x);
}

VEXINLINE double dabs2(double x)
{
  return (x) * (x);
}

VEXINLINE int iabs2(int x) 
{
  return (x) * (x);
}

VEXINLINE int isign(int x)
{
  return ((x) < 0) ? -1 : 1;
}

VEXINLINE int isignab(int a, int b)
{
  return ((b) < 0) ? -iabs(a) : iabs(a);
}

VEXINLINE int rshift_rnd(int x, int a)
{
  return (a > 0) ? ((x + (1 << (a-1) )) >> a) : (x << (-a));
}

VEXINLINE int rshift_rnd_sign(int x, int a)
{
  return (x > 0) ? ( ( x + (1 << (a-1)) ) >> a ) : (-( ( iabs(x) + (1 << (a-1)) ) >> a ));
}

VEXINLINE unsigned int rshift_rnd_us(unsigned int x, unsigned int a)
{
  return (a > 0) ? ((x + (1 << (a-1))) >> a) : x;
}

VEXINLINE int rshift_rnd_sf(int x, int a)
{
  return ((x + (1 << (a-1) )) >> a);
}

VEXINLINE unsigned int rshift_rnd_us_sf(unsigned int x, unsigned int a)
{
  return ((x + (1 << (a-1))) >> a);
}

VEXINLINE int iClip1(int high, int x)
{
  x = imax(x, 0);
  x = imin(x, high);

  return x;
}

VEXINLINE int iClip3(int low, int high, int x)
{
  x = imax(x, low);
  x = imin(x, high);

  return x;
}

VEXINLINE double dClip3(double low, double high, double x)
{
  x = dmax(x, low);
  x = dmin(x, high);

  return x;
}

VEXINLINE int RSD(int x)
{
 return ((x&2)?(x|1):(x&(~1)));
}

VEXINLINE int power2(int x) 
{
  return 1 << (x);
}

VEXINLINE int float2int (float x)
{
  return (int)((x < 0) ? (x - 0.5f) : (x + 0.5f));
}

#if ZEROSNR
VEXINLINE float psnr(int max_sample_sq, int samples, float sse_distortion ) 
{
  return (float) (10.0 * log10(max_sample_sq * (double) ((double) samples / (sse_distortion == 0.0 ? 1.0 : sse_distortion))));
}
#else
VEXINLINE float psnr(int max_sample_sq, int samples, float sse_distortion ) 
{
  return (float) (sse_distortion == 0.0 ? 0.0 : (10.0 * log10(max_sample_sq * (double) ((double) samples / sse_distortion))));
}
#endif


#if defined(_vex_) && defined(_mfinline_) && !defined(_int64_debug_)
}}
#endif

#endif

