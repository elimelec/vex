/** 
*** static char sccs_id[] = "$Id: _nc_unlink.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
**/

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

#include <machine/noncache.h>
#include <sys/errno.h>
#include <string.h>

extern int _sys_unlink (_CONST char *file);
extern int _nc_strcpy (char *dst, _CONST char *src, unsigned int len);

int 
_nc_unlink (_CONST char *file)
{
  int ret;
  if (_noncachedp && file)
    {
      /* Use non-cacheable memory for OS call. */
      if (_nc_strcpy (_noncachedp->path1, file, PATH_MAX_PLUS_1) < 0)
	ret = -ENAMETOOLONG;
      else
	ret = _sys_unlink (_noncachedp->path1);
    }
  else
    {
      /* Call OS directly. */
      ret = _sys_unlink (file);
    }
  return ret;
}
