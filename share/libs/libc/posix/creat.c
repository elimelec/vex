/* 
** static char sccs_id[] = "$Id: creat.c,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
*/
/* creat() "system call" */

/* This is needed by f2c and therefore the SPEC benchmarks.  */

#include <fcntl.h>

int
creat (const char *path, mode_t mode)
{
  return open (path, O_WRONLY | O_CREAT | O_TRUNC, mode);
}
