/* alarm "system call" */

/* This is needed by the nullstone test suite  */

#include <unistd.h>
#include <sys/time.h>

unsigned int alarm(unsigned int sec)
{
struct itimerval in_val,out_val;

in_val.it_value.tv_sec = sec;
in_val.it_value.tv_usec = 0;
in_val.it_interval.tv_sec = 0;
in_val.it_interval.tv_usec = 0;

out_val.it_interval.tv_sec = 0;
out_val.it_interval.tv_usec = 0;

if (setitimer(ITIMER_REAL,&in_val,&out_val) == 0)
	return out_val.it_value.tv_sec;
return 0;
}
