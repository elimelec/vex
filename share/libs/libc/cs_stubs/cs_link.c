/**
*** static char sccs_id[] = "$Id: cs_link.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
**/

#include <unistd.h>
#include <_syslist.h>
#include "cs_errno.h"

int link(_CONST char *old, _CONST char *new)
{
    int retval = _link(old, new);
    errno = cs_errno;
    return retval;
}

int unlink (_CONST char *file)
{
    int retval = _unlink(file);
    errno = cs_errno;
    return retval;
}
