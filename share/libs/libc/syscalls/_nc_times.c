/* 
** static char sccs_id[] = "$Id: _nc_times.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
*/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

#include <machine/noncache.h>
#include <sys/errno.h>
#include <string.h>

extern _CLOCK_T_ _sys_times (struct tms *ptms);

_CLOCK_T_
_nc_times (ptms)
     struct tms *ptms;
{
  int ret;

  if (_noncachedp)
    {
      /* Use non-cacheable memory for OS call. */
      ret = _sys_times(&(_noncachedp->tbuf));
      if (ptms)
          *ptms = _noncachedp->tbuf;
    }
  else
    {
      /* Call OS directly. */
      ret = _sys_times(ptms);
    }
  return ret;
}
