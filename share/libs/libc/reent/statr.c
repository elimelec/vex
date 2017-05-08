/* 
** static char sccs_id[] = "$Id: statr.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
*/
/* Reentrant versions of stat system call.  This implementation just
   calls the stat system call.  */

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

/* Some targets provides their own versions of these functions.  Those
   targets should define REENTRANT_SYSCALLS_PROVIDED in
   TARGET_CFLAGS.  */

#ifdef _REENT_ONLY
#ifndef REENTRANT_SYSCALLS_PROVIDED
#define REENTRANT_SYSCALLS_PROVIDED
#endif
#endif

#ifdef REENTRANT_SYSCALLS_PROVIDED

int _dummy_stat_syscalls = 1;

#else

#include "errno_r.h"

/*
FUNCTION
	<<_stat_r>>---Reentrant version of stat
	
INDEX
	_stat_r

ANSI_SYNOPSIS
	#include <reent.h>
	int _stat_r(struct _reent *<[ptr]>,
		    const char *<[file]>, struct stat *<[pstat]>);

TRAD_SYNOPSIS
	#include <reent.h>
	int _stat_r(<[ptr]>, <[file]>, <[pstat]>)
	struct _reent *<[ptr]>;
	char *<[file]>;
	struct stat *<[pstat]>;

DESCRIPTION
	This is a reentrant version of <<stat>>.  It
	takes a pointer to the global data block, which holds
	<<errno>>.
*/

int
_stat_r (ptr, file, pstat)
     struct _reent *ptr;
     _CONST char *file;
     struct stat *pstat;
{
  int ret;

  errno = 0;
  if ((ret = _stat (file, pstat)) == -1 && errno != 0)
    ptr->_errno = errno;
  return ret;
}

#endif /* ! defined (REENTRANT_SYSCALLS_PROVIDED) */