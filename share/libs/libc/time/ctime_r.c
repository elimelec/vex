/* 
** static char sccs_id[] = "$Id: ctime_r.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
*/
/*
 * ctime_r.c
 */

#include <time.h>

char *
_DEFUN (ctime_r, (tim_p, result),
	_CONST time_t * tim_p _AND
        char * result)

{
  struct tm tm;
  return asctime_r (localtime_r (tim_p, &tm), result);
}
