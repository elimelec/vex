/**
*** static char sccs_id[] = "$Id: _nc_link.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
**/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

#include <machine/noncache.h>
#include <sys/errno.h>
#include <string.h>

extern int _sys_link (_CONST char *old, _CONST char *new);
extern int _nc_strcpy (char *dst, _CONST char *src, unsigned int len);

int 
_nc_link (_CONST char *old, _CONST char *new)
{
  int ret;
  if (_noncachedp && old && new)
    {
      /* Use non-cacheable memory for OS call. */
      if (   (_nc_strcpy (_noncachedp->path1, old, PATH_MAX_PLUS_1) < 0)
	  || (_nc_strcpy (_noncachedp->path2, new, PATH_MAX_PLUS_1) < 0))
	ret = -ENAMETOOLONG;
      else
	ret = _sys_link (_noncachedp->path1, _noncachedp->path2);
    }
  else
    {
      /* Call OS directly. */
      ret = _sys_link (old, new);
    }
  return ret;
}
