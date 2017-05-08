#ifndef __VEXASM_H_INCLUDED
#define __VEXASM_H_INCLUDED

#ifdef __CPLUSPLUS__
extern "C" {
#endif

typedef unsigned int __vexasm1;
typedef struct { unsigned int n0, n1; } __vexasm2;
typedef struct { unsigned int n0, n1, n2; } __vexasm3;
typedef struct { unsigned int n0, n1, n2, n3; } __vexasm4;

#if defined(__STDC__) || defined(__STDCPP__)
void     _asm0(int,...);
__vexasm1 _asm1(int,...);
__vexasm2 _asm2(int,...);
__vexasm3 _asm3(int,...);
__vexasm4 _asm4(int,...);
#else
void   _asm0();
__vexasm1 _asm1();
__vexasm2 _asm2();
__vexasm3 _asm3();
__vexasm4 _asm4();
#endif

/**
*** Last user-defined ASMOP
**/
#define __VEX_MAX_USER_ASMOP 127

/**
*** VEX "special" operations
**/
#define __VEX_PREFETCH_ASMOP 255
#define __VEX_ADDCG_ASMOP    254
#define __VEX_DIVS_ASMOP     253


#define __PREFETCH(addr,offset)   (			\
    _asm0(__VEX_PREFETCH_ASMOP,addr,offset)		\
)

#define __ADDCG(sum,cout,a,b,cin) {  			\
    __vexasm2 __addcg_r;  				\
    __addcg_r = _asm2(__VEX_ADDCG_ASMOP,(a),(b),(cin));  \
    (sum) = __addcg_r.n0; 				\
    (cout) = __addcg_r.n1; 				\
}

#define __DIVS(sum,cout,a,b,cin) {  			\
    __vexasm2 __divs_r;  				\
    __divs_r = _asm2(__VEX_DIVS_ASMOP,(a),(b),(cin));  	\
    (sum) = __divs_r.n0; 				\
    (cout) = __divs_r.n1; 				\
}

#ifdef __CPLUSPLUS__
}
#endif

#endif /* __VEXASM_H_INCLUDED */

