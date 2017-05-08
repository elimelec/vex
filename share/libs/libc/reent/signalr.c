/* 
** static char sccs_id[] = "$Id: signalr.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
*/
/* Reentrant versions of syscalls need to support signal/raise.
   These implementations just call the usual system calls.  */

#include <reent.h>
#include <_syslist.h>

/* Some targets provides their own versions of these functions.  Those
   targets should define REENTRANT_SYSCALLS_PROVIDED in TARGET_CFLAGS.  */

#ifdef _REENT_ONLY
#ifndef REENTRANT_SYSCALLS_PROVIDED
#define REENTRANT_SYSCALLS_PROVIDED
#endif
#endif

#ifdef REENTRANT_SYSCALLS_PROVIDED

int _dummy_link_syscalls = 1;

#else

#include "errno_r.h"

/*
FUNCTION
	<<_kill_r>>---Reentrant version of kill
	
INDEX
	_kill_r

ANSI_SYNOPSIS
	#include <reent.h>
	int _kill_r(struct _reent *<[ptr]>, int <[pid]>, int <[sig]>);

TRAD_SYNOPSIS
	#include <reent.h>
	int _kill_r(<[ptr]>, <[pid]>, <[sig]>)
	struct _reent *<[ptr]>;
	int <[pid]>;
	int <[sig]>;

DESCRIPTION
	This is a reentrant version of <<kill>>.  It
	takes a pointer to the global data block, which holds
	<<errno>>.
*/

int
_kill_r (ptr, pid, sig)
     struct _reent *ptr;
     int pid;
     int sig;
{
  int ret;

  errno = 0;
  if ((ret = _kill (pid, sig)) == -1 && errno != 0)
    ptr->_errno = errno;
  return ret;
}

/*
FUNCTION
	<<_getpid_r>>---Reentrant version of getpid
	
INDEX
	_getpid_r

ANSI_SYNOPSIS
	#include <reent.h>
	int _getpid_r(struct _reent *<[ptr]>);

TRAD_SYNOPSIS
	#include <reent.h>
	int _getpid_r(<[ptr]>)
	struct _reent *<[ptr]>;

DESCRIPTION
	This is a reentrant version of <<getpid>>.  It
	takes a pointer to the global data block, which holds
	<<errno>>.

	We never need <<errno>>, of course, but for consistency we
	still must have the reentrant pointer argument.
*/

int
_getpid_r (ptr)
     struct _reent *ptr;
{
  int ret;
  ret = _getpid ();
  return ret;
}

#endif /* ! defined (REENTRANT_SYSCALLS_PROVIDED) */
