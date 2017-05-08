#include <stdio.h>

#ifdef _c99inline_
# define __inline inline
#else
# define __inline /**/
#endif

#if defined(_vex_) && defined(USE_ASM)
# include <vexasm.h>
# define count_ones(a) ((int)_asm1(0x2,(a)))
#else
__inline int count_ones(unsigned int v)
{
    v = v - ((v >> 1) & 0x55555555);
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
#endif

#define SIZE 100000

int c[SIZE];

#pragma prefetch(8)
typedef int pft_int;

int main()
{
	int i;
	pft_int *pc = c;
	#pragma unroll_amount(20,1)
	#pragma ivdep
    for(i=0; i<SIZE; ++i) {
	    pc[i] += count_ones(i);
	}
}

/* vi: ts=4 
*/
