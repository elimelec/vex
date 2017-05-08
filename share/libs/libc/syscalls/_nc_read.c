/** 
*** static char sccs_id[] = "$Id: _nc_read.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
**/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

#include <machine/noncache.h>
#include <sys/errno.h>
#include <string.h>

extern long _sys_read (int fd, void *buf, size_t cnt);
extern int _sys_isatty (int fd);
extern void _bcopy (const void *s1, void *s2, size_t n);

long 
_nc_read (int fd, void *buf, size_t cnt)
{
  int ret = 0;
  if (_noncachedp && buf)
    {
      /* Use non-cacheable memory for OS call. */
      char *bp = (char *) buf;
      while (cnt > 0)
	{
	  int trycnt = (DBUFS < cnt ? DBUFS : cnt);
	  int actual = _sys_read (fd, _noncachedp->data, trycnt);

	  /* Skip out if read did not return anything */
	  if (actual <= 0)
	    {
	      if (actual < 0)
		ret = actual;	/* So error is seen */
	      break;
	    }

	  /* Copy to user buffer and advance buffer pointer */
	  _bcopy ((void *) _noncachedp->data, (void *) bp, actual);
	  ret += actual;
	  bp += actual;
	  cnt -= actual;
	  if (_sys_isatty (fd))
	    break;
	}
    }
  else
    {
      /* Call OS directly. */
      ret = _sys_read (fd, buf, cnt);
    }
  return ret;
}
