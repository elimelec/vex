#ifndef _SETJMP_CS_H
#define _SETJMP_CS_H

#define _JB_HOST_LEN (40 + 74)
#define _JB_LEN  (2 + 7)
#define _JB_STACK_PTR 0
#define _JB_LINK      4
#define _JB_PRE(n)    (8+((n)<<2))

typedef int __jmp_buf[_JB_LEN];

typedef struct __jmp_buf_tag {
        __jmp_buf __jmpbuf;
	double __hostbuf[(_JB_HOST_LEN * sizeof(long))/sizeof(double)];
} jmp_buf[1];

#endif /* _SETJMP_CS_H */
