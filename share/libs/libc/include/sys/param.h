/**
*** static char sccs_id[] = "$Id: param.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/

#ifndef _SYS_PARAM_H
# define _SYS_PARAM_H

#include <time.h>
#include <limits.h>

# define HZ (CLOCKS_PER_SEC / 1000)
# define NOFILE	(60)
# define PATHSIZE (1024)
# define MAX_ALARM   (ULONG_MAX / (HZ * 2))
# define MAX_VTALARM (ULONG_MAX / (HZ * 2))
# define MAX_PROF    (ULONG_MAX / (HZ * 2))

#endif
