/* 
** static char sccs_id[] = "$Id: mstats.c,v 1.1.1.1 2001/11/21 20:34:40 frb Exp $ ";
*/
/* VxWorks provides its own version of malloc, and we can't use this
   one because VxWorks does not provide sbrk.  So we have a hook to
   not compile this code.  */

#ifdef MALLOC_PROVIDED

int _dummy_mstats = 1;

#else

#include <_ansi.h>
#include <reent.h>
#include <stdlib.h>
#include "malloc.h"

/* ****************************************************************
 * mstats - print out statistics about malloc
 *
 * Prints two lines of numbers, one showing the length of the free list
 * for each size category, the second showing the number of mallocs -
 * frees for each size category.
 */

void
_DEFUN (_mstats_r, (ptr, s),
	struct _reent *ptr _AND
	char *s)
{
  register int i, j;
  register mptr p;
  int totfree = 0, totused = 0;

  fiprintf (_stderr_r (ptr), "Memory allocation statistics %s\nfree:\t", s);
  for (i = 0; i < _N_LISTS; i++)
    {
      p = ptr->_nextf[i];

      for (j = 0; p; j++)
	p = *(mptr *) p;
      fiprintf (_stderr_r (ptr), " %d", j);
      totfree += j * (1 << (i + 3));
    }
  fiprintf (_stderr_r (ptr), "\nused:\t");
  for (i = 0; i < _N_LISTS; i++)
    {
      fiprintf (_stderr_r (ptr), " %d", ptr->_nmalloc[i]);
      totused += ptr->_nmalloc[i] * (1 << (i + 3));
    }
  fiprintf (_stderr_r (ptr), "\n\tTotal in use: %d, total free: %d\n");
}

#ifndef _REENT_ONLY
void
_DEFUN (mstats, (s),
	char *s)
{
  _mstats_r (_REENT, s);
}

#endif
#endif /* ! defined (MALLOC_PROVIDED) */

