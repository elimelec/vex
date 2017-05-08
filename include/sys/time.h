/**
*** static char sccs_id[] = "$Id: time.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/
/* Define the structures used by the gettimeofday() syscall. */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

struct timeval {
  long tv_sec;
  long tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};


#ifndef _STRUCT_TM
#define _STRUCT_TM
struct tm
{
  int   tm_sec;
  int   tm_min;
  int   tm_hour;
  int   tm_mday;
  int   tm_mon;
  int   tm_year;
  int   tm_wday;
  int   tm_yday;
  int   tm_isdst;
};
#endif


/* Cygwin32 needs itimer headers */
#if defined(__CYGWIN32__) || defined(_vex_) 
#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

struct  itimerval {
  struct  timeval it_interval;
  struct  timeval it_value;
};
#endif /* __CYGWIN32__ || _vex_ */

#ifdef _vex_

#ifndef _POSIX_SOURCE
#ifndef _SYS_SELECT_H
#include <sys/types.h>
#include "_ansi.h"
int _EXFUN(select, (int, fd_set *, fd_set *, fd_set *, struct timeval *));
#endif
#endif /* ! _POSIX_SOURCE */

#ifndef _STRUCT_TIMESPEC
#define _STRUCT_TIMESPEC
#include <sys/types.h>
#include "_ansi.h"
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};
typedef struct timespec timestruc_t;
typedef enum {
    CLOCK_INVALID = 0,
    CLOCK_REALTIME = 1,
    CLOCK_VIRTUAL = 2,
    CLOCK_PROFILE = 4
} clockid_t;
int _EXFUN(clock_settime, (clockid_t, const struct timespec *));
int _EXFUN(clock_gettime, (clockid_t, struct timespec *));
#endif

int _EXFUN(gettimeofday, (struct timeval *__p, struct timezone *__z));
int _EXFUN(settimeofday, (const struct timeval *, const struct timezone *));

#endif /* _vex_ */

#ifdef __cplusplus
}
#endif
#endif
