/* 
** static char sccs_id[] = "$Id: _toupper.c,v 1.1.1.1 2001/11/21 20:34:38 frb Exp $ ";
*/
#include <_ansi.h>
#include <ctype.h>

#undef _toupper
int
_DEFUN(_toupper,(c),int c)
{
  return islower(c) ? c - 'a' + 'A' : c;
}
