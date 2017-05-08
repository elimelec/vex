/**
*** static char sccs_id[] = "$Id: setjmp.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/

#ifndef _MACHINE_SETJMP_H
#define _MACHINE_SETJMP_H
#ifdef _vex_

 /*
  * To be kept in sync with <machine/reg_usage.h>:
  *
  * 0: stack pointer
  * 1: link register
  * 2-8: preserved regs
  *
  */
#define _JBLEN (2 + 7)

#define _JB_STACK_PTR  0
#define _JB_LINK       4
#define _JB_PRE(n)     (8+(n)<<2)

#ifndef _ASM

#include <sys/signal.h>
#include <_ansi.h>

typedef	int __jmp_buf[_JBLEN];

typedef struct __jmp_buf_tag {
    __jmp_buf __jmpbuf;		/* Environment */
    int __mask_was_saved;	/* Saved the signal mask? */
    sigset_t __saved_mask; 	/* Saved signal mask */
} jmp_buf[1];

typedef jmp_buf sigjmp_buf;

int _EXFUN(__sigjmp_save,(sigjmp_buf env, int savemask));
void _EXFUN(__longjmp,(__jmp_buf env, int val));

#endif /* !_ASM */

#endif /* _vex_ */
#endif /* _MACHINE_SETJMP_H */
