/* 
** static char sccs_id[] = "$Id: _tolower.c,v 1.1.1.1 2001/11/21 20:34:38 frb Exp $ ";
*/
#include <_ansi.h>
#include <ctype.h>

#undef _tolower
int
_DEFUN(_tolower,(c),int c)
{
	return isupper(c) ? (c) - 'A' + 'a' : c;
}
