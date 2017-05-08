/**
*** static char sccs_id[] = "$Id: cs_write.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
**/

#include <unistd.h>
#include <_syslist.h>
#include "cs_errno.h"

long
write (int fd, _CONST void* buf, size_t cnt)
{
    int retval = _write(fd,buf,cnt);
    errno = cs_errno;
    return retval;
}
