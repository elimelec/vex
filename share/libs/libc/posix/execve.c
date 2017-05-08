/* 
** static char sccs_id[] = "$Id: execve.c,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
*/
/* execve.c */

/* This and the other exec*.c files in this directory require 
   the target to provide the _execve syscall.  */

int
execve (const char *path, char * const argv[], char * const envp[])
{
  return _execve (path, argv, envp);
}
