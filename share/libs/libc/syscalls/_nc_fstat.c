/* 
** static char sccs_id[] = "$Id: _nc_fstat.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
*/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

#include <machine/noncache.h>
#include <sys/errno.h>
#include <string.h>

extern int _sys_fstat (int fd,
		      struct stat *pstat);

int
_nc_fstat (fd, pstat)
     int fd;
     struct stat *pstat;
{
  int ret;

  if (_noncachedp)
    {
      /* Use non-cacheable memory for OS call. */
      ret = _sys_fstat(fd, &_noncachedp->sbuf);

      /* Only store to user buffer if success. */
      if(ret >= 0)
	*pstat = _noncachedp->sbuf;
    }
  else
    {
      /* Call OS directly. */
      ret = _sys_fstat(fd, pstat);
    }
  return ret;
}
