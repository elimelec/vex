/* 
** static char sccs_id[] = "$Id: callocr.c,v 1.1.1.1 2001/11/21 20:34:40 frb Exp $ ";
*/
/*
Doc in calloc.c

Split out of calloc.c so that calloc can be redefined without causing link errors when
using other library routines which call calloc_r.
*/ 

#include <string.h>
#include <stdlib.h>

#ifdef CALLOC_PROVIDED

_PTR
_DEFUN (_calloc_r, (ptr, n, size),
	struct _reent * ptr _AND
	size_t n _AND
	size_t size)
{
    return calloc(n,size);
}

#else

_PTR
_DEFUN (_calloc_r, (ptr, n, size),
	struct _reent * ptr _AND
	size_t n _AND
	size_t size)
{
  register char *cp;

  n *= size;
  cp = _malloc_r (ptr, n);
  if (cp == 0)
    return 0;
  memset (cp, '\0', n);
  return (_PTR)cp;
}

#endif /* CALLOC_PROVIDED */
