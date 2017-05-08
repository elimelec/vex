#ifndef VEX_ASM_BASICOP_INCLUDED
#define VEX_ASM_BASICOP_INCLUDED

#include <vexasm.h>

#define __VEX_LMAC_ASMOP  0x01
#define __VEX_LMSU_ASMOP  0x02
#define __VEX_LMULT_ASMOP 0x03
#define __VEX_LADD_ASMOP  0x04
#define __VEX_LSUB_ASMOP  0x05
#define __VEX_LSHL_ASMOP  0x06
#define __VEX_LSHR_ASMOP  0x07
#define __VEX_MULT_ASMOP  0x08

#define _VEX_BASICOP_MAC

#define __LMAC(out,overflow,a,b,c) {                  \
    __vexasm2 __mac_r;                                \
    __mac_r = _asm2(__VEX_LMAC_ASMOP,(a),(b),(c));   \
     (out) = __mac_r.n0;                              \
     (overflow) = __mac_r.n1;                         \
}

#define __LMSU(out,overflow,a,b,c) {                  \
    __vexasm2 __msu_r;                                \
    __msu_r = _asm2(__VEX_LMSU_ASMOP,(a),(b),(c));    \
     (out) = __msu_r.n0;                              \
     (overflow) = __msu_r.n1;                         \
}

#define __LMULT(out,overflow,a,b) {                   \
    __vexasm2 __mult_r;                               \
    __mult_r = _asm2(__VEX_LMULT_ASMOP,(a),(b));      \
     (out) = __mult_r.n0;                             \
     (overflow) = __mult_r.n1;                        \
}

#define __LADD(out,overflow,a,b) {                   \
    __vexasm2 __add_r;                               \
    __add_r = _asm2(__VEX_LADD_ASMOP,(a),(b));       \
     (out) = __add_r.n0;                             \
     (overflow) = __add_r.n1;                        \
}

#define __LSUB(out,overflow,a,b) {                   \
    __vexasm2 __sub_r;                               \
    __sub_r = _asm2(__VEX_LSUB_ASMOP,(a),(b));       \
     (out) = __sub_r.n0;                             \
     (overflow) = __sub_r.n1;                        \
}

#define __LSHL(out,overflow,a,b) {                   \
    __vexasm2 __shl_r;                               \
    __shl_r = _asm2(__VEX_LSHL_ASMOP,(a),(b));       \
     (out) = __shl_r.n0;                             \
     (overflow) = __shl_r.n1;                        \
}

#define __LSHR(out,overflow,a,b) {                   \
    __vexasm2 __shr_r;                               \
    __shr_r = _asm2(__VEX_LSHR_ASMOP,(a),(b));       \
     (out) = __shr_r.n0;                             \
     (overflow) = __shr_r.n1;                        \
}

#define __MULT(out,overflow,a,b) {                   \
    __vexasm2 __mult_r;                              \
    __mult_r = _asm2(__VEX_MULT_ASMOP,(a),(b));      \
     (out) = __mult_r.n0;                            \
     (overflow) = __mult_r.n1;                       \
}

#endif
