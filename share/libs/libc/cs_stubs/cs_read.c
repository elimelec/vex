/**
*** static char sccs_id[] = "$Id: cs_read.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
**/

#include <unistd.h>
#include <_syslist.h>
#include "cs_errno.h"

long
read (int fd, void *buf, size_t cnt)
{
    int retval = _read(fd,buf,cnt);
    errno = cs_errno;
    return retval;
}
