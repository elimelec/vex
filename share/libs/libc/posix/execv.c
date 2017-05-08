/* 
** static char sccs_id[] = "$Id: execv.c,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
*/
/* execv.c */

/* This and the other exec*.c files in this directory require 
   the target to provide the _execve syscall.  */

#include <_ansi.h>
#include <unistd.h>

int
_DEFUN (execv, (path, argv), 
	const char *path _AND
	char * const argv[])
{
  return _execve (path, (char * _CONST *) argv, environ);
}
