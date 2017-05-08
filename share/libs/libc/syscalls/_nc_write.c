/**
*** static char sccs_id[] = "$Id: _nc_write.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
**/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

#include <machine/noncache.h>
#include <sys/errno.h>
#include <string.h>

extern long _sys_write (int fd, const void *buf, size_t cnt);
extern void _bcopy (const void *s1, void *s2, size_t n);

long 
_nc_write (int fd, _CONST void *buf, size_t cnt)
{
  int ret = 0;
  if (_noncachedp && buf)
    {
      /* Use non-cacheable memory for OS call. */
      char *bp = (char *) buf;
      while (cnt > 0)
	{
	  int actual;
	  int trycnt = (DBUFS < cnt ? DBUFS : cnt);
	  _bcopy ((void *) bp, (void *) _noncachedp->data, trycnt);
	  actual = _sys_write (fd, _noncachedp->data, trycnt);
	  if (actual <= 0)
	    {
	      if (actual < 0)
		ret = actual;
	      break;
	    }

	  ret += actual;
	  bp += actual;
	  cnt -= actual;
	}
    }
  else
    {
      /* Call OS directly. */
      ret = _sys_write (fd, buf, cnt);
    }
  return ret;
}
