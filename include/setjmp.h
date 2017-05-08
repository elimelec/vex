/**
*** static char sccs_id[] = "$Id: setjmp.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/

#ifndef _SETJMP_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SETJMP_H_

#include "_ansi.h"
#include <machine/setjmp.h>

int	_EXFUN(setjmp,(jmp_buf __jmpb));
int	_EXFUN(_setjmp,(jmp_buf __jmpb));

void	_EXFUN(longjmp,(jmp_buf __jmpb, int __retval));
void	_EXFUN(_longjmp,(jmp_buf __jmpb, int __retval));

int	_EXFUN(sigsetjmp,(jmp_buf __jmpb, int savemask));
void	_EXFUN(siglongjmp,(jmp_buf __jmpb, int __retval));

#ifdef __cplusplus
}
#endif
#endif /* _SETJMP_H_ */

