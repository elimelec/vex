/**
*** static char sccs_id[] = "$Id: _nc_open.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
**/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

#include <machine/noncache.h>
#include <sys/errno.h>
#include <string.h>

extern int _sys_open (_CONST char *file, int flags, int mode);
extern int _nc_strcpy (char *dst, _CONST char *src, unsigned int len);

int 
_nc_open (_CONST char *file, int flags, int mode)
{
  int ret;
  if (_noncachedp && file)
    {
      /* Use non-cacheable memory for OS call. */
      if (_nc_strcpy (_noncachedp->path1, file, PATH_MAX_PLUS_1) < 0)
	ret = -ENAMETOOLONG;
      else
	ret = _sys_open (_noncachedp->path1, flags, mode);
    }
  else
    {
      /* Call OS directly. */
      ret = _sys_open (file, flags, mode);
    }
  return ret;
}
