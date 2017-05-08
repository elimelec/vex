/**
*** static char sccs_id[] = "$Id: cs_time.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
**/

#include <unistd.h>
#include <_syslist.h>
#include <time.h>
#include <sys/times.h>
#include "cs_errno.h"

clock_t
times(struct tms *ptms)
{
    return _times(ptms);
}

int
gettimeofday (struct timeval *ptimeval, struct timezone *ptimezone)
{
    int retval = _gettimeofday(ptimeval,ptimezone);
    errno = cs_errno;
    return retval;
}
