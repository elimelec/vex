#ifdef _vex_
#include <vexasm.h>
#endif

/**
*** Example of an _asm1 returning 1 value
**/

#if defined(_vex_) && defined(USE_ASM)
# define AVG(a,b) ((int)_asm1(0x1,(a),(b)))
#else
# define AVG(a,b) (((a)+(b))/2)
#endif


/**
*** Example of an _asm2() returning 2 values
**/
#ifdef _vex_
#define ADDSUB(a,b,t,q) { \
    __vexasm2 _t2 = _asm2(0x2,a,b); \
    (t)=(int)_t2.n0; \
    (q)=(int)_t2.n1; \
}
#else
#define ADDSUB(a,b,t,q) { (t)=(a)+(b); (q)=(a)-(b); }
#endif


void average(int *c, int *a, int *b, int size)
{
    int p;
    #pragma ivdep
    #pragma unroll_amount(8,1)
    for (p = 0; p < size; p++) {
	*c++ = AVG(*a++, *b++);
    }
}

int x[10], y[10], z[10];
main()
{
    int i;
    for(i=0; i < 10; ++i) {
        int t1,t2;
	ADDSUB(i,100,t1,t2);
	x[i] = t1+20;
	y[i] = t2;
    }
    average(z,x,y,10);
    for(i=0; i < 10; ++i)
         printf("%d\n",z[i]);
}
