/* 
** static char sccs_id[] = "$Id: _nc_gettimeofday.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
*/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

#include <machine/noncache.h>
#include <sys/errno.h>
#include <string.h>

extern int _sys_gettimeofday (struct timeval *ptimeval,
			     struct timezone *ptimezone);

int
_nc_gettimeofday (ptimeval, ptimezone)
     struct timeval *ptimeval;
     struct timezone *ptimezone;
{
  int ret;

  if (_noncachedp)
    {
      /* Use non-cacheable memory for OS call. */
      ret = _sys_gettimeofday(&(_noncachedp->tvbuf),
			     &(_noncachedp->tzbuf));
      if(ptimeval)
          *ptimeval = _noncachedp->tvbuf;

      if(ptimezone)
          *ptimezone = _noncachedp->tzbuf;
    }
  else
    {
      /* Call OS directly. */
      ret = _sys_gettimeofday(ptimeval, ptimezone);
    }
  return ret;
}
