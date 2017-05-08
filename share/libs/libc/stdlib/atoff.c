/* 
** static char sccs_id[] = "$Id: atoff.c,v 1.1.1.1 2001/11/21 20:34:40 frb Exp $ ";
*/
#include <stdlib.h>
#include <_ansi.h>

float
_DEFUN (atoff, (s),
	_CONST char *s)
{
  return strtodf (s, NULL);
}
