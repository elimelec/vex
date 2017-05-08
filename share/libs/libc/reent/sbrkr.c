/* 
** static char sccs_id[] = "$Id: sbrkr.c,v 1.2 2005/01/19 15:57:17 frb Exp $ ";
*/
/* Reentrant versions of sbrk system call.  This implementation just
   calls the stat system call.  */

#include <reent.h>
#include <unistd.h>
#include <_syslist.h>

/* Some targets provides their own versions of these functions.  Those
   targets should define REENTRANT_SYSCALLS_PROVIDED in TARGET_CFLAGS.  */

#ifdef _REENT_ONLY
#ifndef REENTRANT_SYSCALLS_PROVIDED
#define REENTRANT_SYSCALLS_PROVIDED
#endif
#endif

/* If MALLOC_PROVIDED is defined, we don't need this function.  */

#if defined (REENTRANT_SYSCALLS_PROVIDED) || defined (MALLOC_PROVIDED)

int _dummy_sbrk_syscalls = 1;

#else

#include "errno_r.h"

/*
FUNCTION
	<<_sbrk_r>>---Reentrant version of sbrk
	
INDEX
	_sbrk_r

ANSI_SYNOPSIS
	#include <reent.h>
	void *_sbrk_r(struct _reent *<[ptr]>, size_t <[incr]>);

TRAD_SYNOPSIS
	#include <reent.h>
	void *_sbrk_r(<[ptr]>, <[incr]>)
	struct _reent *<[ptr]>;
	size_t <[incr]>;

DESCRIPTION
	This is a reentrant version of <<sbrk>>.  It
	takes a pointer to the global data block, which holds
	<<errno>>.
*/
void *
_sbrk_r (ptr, incr)
     struct _reent *ptr;
     size_t incr;
{
  char *ret;
  void *_sbrk(size_t);

  errno = 0;
  if ((ret = (char *)(_sbrk (incr))) == (void *) -1 && errno != 0)
    ptr->_errno = errno;
  return (void*)ret;
}

#endif /* ! defined (REENTRANT_SYSCALLS_PROVIDED) */
