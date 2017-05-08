#ifndef __int64_h__
#define __int64_h__
/**
*** Copyright (C) 2002-2009 Hewlett-Packard Company
**/


#if defined(_vex_)
# include <vexasm.h>

# if defined(_mfinline_) && !defined(_int64_debug_)
#  define _INLINE64 inline
inline_declare {
inline_module int64 {
# else
#  define _INLINE64 static
# endif

typedef union {
    struct {
# if defined(_big_endian)
        unsigned int hi, lo; 
# else
        unsigned int lo, hi; 
# endif
    } s;
    double __d; /* force 0mod64 alignment */
} __n64;

/* Private utilities */
#define __hi64(x) ((x).s.hi)
#define __lo64(x) ((x).s.lo)

/****************************************************************
** Constructors
*****************************************************************/
_INLINE64 __n64 __c64(int hi, int lo)
{
    __n64 c;
    __hi64(c) = hi;
    __lo64(c) = lo;
    return c;
}

/* Constant constructor for initializers */
#if defined(_big_endian)
# define __C64(hi,lo) { hi, lo } 
#else
# define __C64(hi,lo) { lo, hi } 
#endif

/****************************************************************
** Cast operators to/from int
*****************************************************************/
_INLINE64 __n64 __s64(int x) { return __c64((signed) x >> 31, x); }
_INLINE64 __n64 __u64(int x) { return __c64(0,x); }
_INLINE64 int __i64tol(__n64 x) { return __lo64(x); }

/****************************************************************
** Simple Arithmetic Operators
*****************************************************************/
_INLINE64 __n64 __add64(__n64 a, __n64 b)
{
#if defined (__ADDCG)
    __n64 c;
    int carry;
    __ADDCG(__lo64(c),carry,__lo64(a),__lo64(b),0);
    __ADDCG(__hi64(c),carry,__hi64(a),__hi64(b),carry);
    return c;
#else
    unsigned int ah = __hi64(a);
    unsigned int al = __lo64(a);
    unsigned int bh = __hi64(b);
    unsigned int bl = __lo64(b);
    unsigned cl = al + bl;
    unsigned ch = ah + bh + (cl < al);
    return __c64(ch,cl);
#endif
}

_INLINE64 __n64 __sub64(__n64 a, __n64 b)
{
#if defined (__ADDCG)
    __n64 c;
    int carry;
    __ADDCG(__lo64(c),carry,__lo64(a),~__lo64(b),1);
    __ADDCG(__hi64(c),carry,__hi64(a),~__hi64(b),carry);
    return c;
#else
    unsigned int ah = __hi64(a);
    unsigned int al = __lo64(a);
    unsigned int bh = ~__hi64(b);
    unsigned int bl = ~__lo64(b);
    unsigned cl = al + bl + 1;
    unsigned ch = ah + bh + (cl <= al);
    return __c64(ch,cl);
#endif
}

_INLINE64 __n64 __neg64(__n64 a)
{
    return __sub64(__u64(0),a);
}

/****************************************************************
** Bitwise Operators
*****************************************************************/
_INLINE64 __n64 __and64(__n64 a, __n64 b)
{
    return __c64(__hi64(a) & __hi64(b), __lo64(a) & __lo64(b));
}

_INLINE64 __n64 __or64(__n64 a, __n64 b)
{
    return __c64(__hi64(a) | __hi64(b), __lo64(a) | __lo64(b));
}

_INLINE64 __n64 __not64(__n64 a)
{
    return __c64(~__hi64(a), ~__lo64(a));
}

_INLINE64 __n64 __xor64(__n64 a, __n64 b)
{
    return __c64(__hi64(a) ^ __hi64(b), __lo64(a) ^ __lo64(b));
}

/****************************************************************
** Shift Operators
*****************************************************************/
_INLINE64 __n64 __shl64(__n64 a, unsigned int count)
{
    unsigned t_lo = __lo64(a);
    unsigned t_hi = __hi64(a);
    unsigned r_hi = t_hi;
    unsigned r_lo = t_lo;

    if (count) { 
        if (count < 32) {
            r_lo = t_lo << count;
            r_hi = (t_hi << count) | (t_lo >> (32 - count));
        }
        else {
            r_lo = 0;
            r_hi = t_lo << (count & 31);
        }
    }
    return __c64(r_hi,r_lo);
}

_INLINE64 __n64 __shru64(__n64 a, unsigned int count)
{
    unsigned t_lo = __lo64(a);
    unsigned t_hi = __hi64(a);
    unsigned r_hi = t_hi;
    unsigned r_lo = t_lo;

    if (count) {
        if (count < 32) {
            r_lo = (t_hi << (32 - count)) | (t_lo >> count);
            r_hi = (unsigned) t_hi >> count;
        }
        else {
            r_lo = (unsigned) t_hi >> (count & 31);
            r_hi = 0;
        }
    }
    return __c64(r_hi,r_lo);
}

_INLINE64 __n64 __shr64(__n64 a, unsigned int count)
{
    unsigned t_lo = __lo64(a);
    unsigned t_hi = __hi64(a);
    unsigned r_hi = t_hi;
    unsigned r_lo = t_lo;

    if (count) {
        if (count < 32) {
            r_lo = (t_hi << (32 - count)) | (t_lo >> count);
            r_hi = (signed) t_hi >> count;
        }
        else {
            r_lo = (signed) t_hi >> (count & 31);
            r_hi = (signed) t_hi >> 31;
        }
    }
    return __c64(r_hi,r_lo);
}

/****************************************************************
** Relational Operators
*****************************************************************/
_INLINE64 int __z64(__n64 a) { return !__lo64(a) && !__hi64(a); }
_INLINE64 int __nz64(__n64 a) { return __lo64(a) || __hi64(a); }
_INLINE64 int __lz64(__n64 a) { return (signed) __hi64(a) < 0; }
_INLINE64 int __ne64(__n64 a, __n64 b) { return __hi64(a) != __hi64(b) || __lo64(a) != __lo64(b); }
_INLINE64 int __eq64(__n64 a, __n64 b) { return __hi64(a) == __hi64(b) && __lo64(a) == __lo64(b); }

_INLINE64 int __le64(__n64 a, __n64 b)
{
    signed ah = __hi64(a);
    signed bh = __hi64(b);
    signed al = __lo64(a);
    signed bl = __lo64(b);
    return (ah < bh) || ((ah == bh) && (al <= bl));
}

_INLINE64 int __leu64(__n64 a, __n64 b)
{
    unsigned ah = __hi64(a);
    unsigned bh = __hi64(b);
    unsigned al = __lo64(a);
    unsigned bl = __lo64(b);
    return (ah < bh) || ((ah == bh) && (al <= bl));
}

_INLINE64 int __lt64(__n64 a, __n64 b)
{
    signed ah = __hi64(a);
    signed bh = __hi64(b);
    signed al = __lo64(a);
    signed bl = __lo64(b);
    return (ah < bh) || ((ah == bh) && (al < bl));
}

_INLINE64 int __ltu64(__n64 a, __n64 b)
{
    unsigned ah = __hi64(a);
    unsigned bh = __hi64(b);
    unsigned al = __lo64(a);
    unsigned bl = __lo64(b);
    return (ah < bh) || ((ah == bh) && (al < bl));
}

_INLINE64 int __ge64(__n64 a, __n64 b) { return __le64(b,a); }
_INLINE64 int __geu64(__n64 a, __n64 b) { return __leu64(b,a); }
_INLINE64 int __gt64(__n64 a, __n64 b) { return __lt64(b,a); }
_INLINE64 int __gtu64(__n64 a, __n64 b) { return __ltu64(b,a); }

/****************************************************************
** Multiplication
*****************************************************************/
_INLINE64 __n64 __mull64(unsigned int a, unsigned int b)
{
    int correct_a = ((signed)a < 0) ? b : 0;
    int correct_b = ((signed)b < 0) ? a : 0;
    int correct = correct_a + correct_b;
    unsigned int al = a & 0xffff;
    unsigned int bl = b & 0xffff;
    unsigned int ah = a >> 16;
    unsigned int bh = b >> 16;
    unsigned int zl = al * bl;
    unsigned int zh = ah * bh;
    unsigned int zm1 = al * bh;
    unsigned int zm2 = ah * bl;
    unsigned int zm = zm1 + zm2;
    unsigned int zml = zm << 16;
    unsigned int zmh = zm >> 16;
    zl += zml;
    zh += zmh + ((zm < zm1) << 16) + (zl < zml) - correct;
    return __c64(zh,zl);
}

_INLINE64 __n64 __mullu64(unsigned int a, unsigned int b)
{
    unsigned int al = a & 0xffff;
    unsigned int bl = b & 0xffff;
    unsigned int ah = a >> 16;
    unsigned int bh = b >> 16;
    unsigned int zl = al * bl;
    unsigned int zh = ah * bh;
    unsigned int zm1 = al * bh;
    unsigned int zm2 = ah * bl;
    unsigned int zm = zm1 + zm2;
    unsigned int zml = zm << 16;
    unsigned int zmh = zm >> 16;
    zl += zml;
    zh += zmh + ((zm < zm1) << 16) + (zl < zml);
    return __c64(zh,zl);
}

_INLINE64 __n64 __mul64(__n64 a, __n64 b)
{
    int al = __lo64(a);
    int ah = __hi64(a);
    int bl = __lo64(b);
    int bh = __hi64(b);
    __n64 t = __mullu64(al,bl);
    int x = al * bh + ah * bl;
    return __c64(__hi64(t) + x, __lo64(t));
}

/****************************************************************
** Division
*****************************************************************/
_INLINE64 void __divrem64(
    __n64 num, 
    __n64 den, 
    __n64 *div, 
    __n64 *rem 
)
{
    __n64 res, bit; 

    bit = __u64(1);
#pragma unroll_amount(2,1)
    while (__ltu64(den,num) && __nz64(bit) && !__lz64(den)) {
        den = __shl64(den,1);
        bit = __shl64(bit,1);
    }

    res = __u64(0);
#pragma unroll_amount(2,1)
    while (__nz64(bit)) {
        if (__leu64(den,num)) {
            num = __sub64(num,den);
            res = __or64(res,bit);
        }
        bit = __shru64(bit,1);
        den = __shru64(den,1);
    }
    *div = res;
    *rem = num;
}

_INLINE64 __n64 __div64(__n64 num, __n64 den)
{
    __n64 div,rem;
    __divrem64(num,den,&div,&rem);
    return div;
}

_INLINE64 __n64 __rem64(__n64 num, __n64 den)
{
    __n64 div,rem;
    __divrem64(num,den,&div,&rem);
    return rem;
}

# ifdef _mfinline_
}}
# endif

#else

/******************************************************************************
** Compatibility implementation for compilers with 'long long' support
******************************************************************************/

#ifdef __GNUC__
# define _INLINE64 __inline
#endif

#ifndef _INLINE64
# define _INLINE64 static
#endif

typedef unsigned long long __n64;

_INLINE64 __n64 __c64(unsigned int hi, unsigned int lo)
{
    return ((__n64) hi << 32) | (__n64) lo;
}

#define __C64(hi,lo) ( ((__n64)(hi) << 32) | (lo) )

_INLINE64 __n64 __s64(unsigned int x)
{
    return (signed long long)x;
}

_INLINE64 __n64 __u64(unsigned int x)
{
    return (unsigned long long)x;
}

_INLINE64 int __i64tol(__n64 x)
{
    return (int) x;
}

_INLINE64 __n64 __add64(__n64 a, __n64 b)
{
    return a + b;
}

_INLINE64 __n64 __sub64(__n64 a, __n64 b)
{
    return a - b;
}

_INLINE64 __n64 __and64(__n64 a, __n64 b)
{
    return a & b;
}

_INLINE64 __n64 __or64(__n64 a, __n64 b)
{
    return a | b;
}

_INLINE64 __n64 __xor64(__n64 a, __n64 b)
{
    return a ^ b;
}

_INLINE64 __n64 __not64(__n64 a)
{
    return ~a;
}

_INLINE64 __n64 __neg64(__n64 a)
{
    return -a;
}

_INLINE64 __n64 __shl64(__n64 a, int n)
{
    return a << n;
}

_INLINE64 __n64 __shr64(__n64 a, int n)
{
    return (signed long long)a >> n;
}

_INLINE64 __n64 __shru64(__n64 a, int n)
{
    return (unsigned long long)a >> n;
}

_INLINE64 int __z64(__n64 a)
{
    return a == 0;
}

_INLINE64 int __nz64(__n64 a)
{
    return a != 0;
}

_INLINE64 int __lz64(__n64 a)
{
    return a < 0;
}

_INLINE64 int __eq64(__n64 a, __n64 b)
{
    return a == b;
}

_INLINE64 int __ne64(__n64 a, __n64 b)
{
    return a != b;
}

_INLINE64 int __le64(__n64 a, __n64 b)
{
    return (signed long long) a <= b;
}

_INLINE64 int __leu64(__n64 a, __n64 b)
{
    return (unsigned long long) a <= b;
}

_INLINE64 int __lt64(__n64 a, __n64 b)
{
    return (signed long long) a < b;
}

_INLINE64 int __ltu64(__n64 a, __n64 b)
{
    return (unsigned long long) a < b;
}

_INLINE64 int __ge64(__n64 a, __n64 b)
{
    return (signed long long) a >= b;
}

_INLINE64 int __geu64(__n64 a, __n64 b)
{
    return (unsigned long long) a >= b;
}

_INLINE64 int __gt64(__n64 a, __n64 b)
{
    return (signed long long) a > b;
}

_INLINE64 int __gtu64(__n64 a, __n64 b)
{
    return (unsigned long long) a > b;
}

_INLINE64 __n64 __mull64(int a, int b)
{
    return (signed long long) a * b;
}

_INLINE64 __n64 __mullu64(unsigned int a, unsigned int b)
{
    return (unsigned long long) a * b;
}

_INLINE64 __n64 __mul64(__n64 a, __n64 b)
{
    return a * b;
}

_INLINE64 void __divrem64(__n64 a, __n64 b, __n64 *div, __n64 *rem)
{
    *div = a / b;
    *rem = a % b;
}

_INLINE64 __n64 __div64(__n64 a, __n64 b)
{
    return a / b;
}

_INLINE64 __n64 __rem64(__n64 a, __n64 b)
{
    return a % b;
}

#endif /* _vex_ */
#endif /* __int64_h__ */

