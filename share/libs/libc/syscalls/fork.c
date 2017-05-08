/* 
** static char sccs_id[] = "$Id: fork.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
*/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>
#include <sys/errno.h>

pid_t
fork (void)
{
  errno = ENOSYS; /* Not implemented on vex */
  return -1;
}
