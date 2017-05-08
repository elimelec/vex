/* 
** static char sccs_id[] = "$Id: closer.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
*/
/* Reentrant version of close system call.  */

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

/* Some targets provides their own versions of this functions.  Those
   targets should define REENTRANT_SYSCALLS_PROVIDED in TARGET_CFLAGS.  */

#ifdef _REENT_ONLY
#ifndef REENTRANT_SYSCALLS_PROVIDED
#define REENTRANT_SYSCALLS_PROVIDED
#endif
#endif

#ifndef REENTRANT_SYSCALLS_PROVIDED

#include "errno_r.h"

/*
FUNCTION
	<<_close_r>>---Reentrant version of close
	
INDEX
	_close_r

ANSI_SYNOPSIS
	#include <reent.h>
	int _close_r(struct _reent *<[ptr]>, int <[fd]>);

TRAD_SYNOPSIS
	#include <reent.h>
	int _close_r(<[ptr]>, <[fd]>)
	struct _reent *<[ptr]>;
	int <[fd]>;

DESCRIPTION
	This is a reentrant version of <<close>>.  It
	takes a pointer to the global data block, which holds
	<<errno>>.
*/

int
_close_r (ptr, fd)
     struct _reent *ptr;
     int fd;
{
  int ret;

  errno = 0;
  if ((ret = _close (fd)) == -1 && errno != 0)
    ptr->_errno = errno;
  return ret;
}

#endif /* ! defined (REENTRANT_SYSCALLS_PROVIDED) */
