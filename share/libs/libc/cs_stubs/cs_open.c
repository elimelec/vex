/**
*** static char sccs_id[] = "$Id: cs_open.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
**/

#include <unistd.h>
#include <_syslist.h>
#include "cs_errno.h"

int
open (char *file, int flags, int mode)
{
  int retval = _open (file, flags, mode);
  errno = cs_errno;
  return retval;
}
