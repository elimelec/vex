/* 
** static char sccs_id[] = "$Id: cs_fstat.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
*/

#include <unistd.h>
#include <_syslist.h>
#include "cs_errno.h"

int fstat(int fd, struct stat *pstat)
{
    int retval = _fstat(fd,pstat);
    errno = cs_errno;
    return retval;
}

int lstat(int fd, struct stat *pstat)
{
    int retval = _lstat(fd,pstat);
    errno = cs_errno;
    return retval;
}

int stat(char *fp, struct stat *pstat)
{
    int retval = _vex_stat(fp,pstat);
    errno = cs_errno;
    return retval;
}

