/* 
** static char sccs_id[] = "$Id: bzero.c,v 1.2 2003/05/21 12:25:29 frb Exp $ ";
*/
/*
FUNCTION
<<bzero>>---initialize memory to zero

INDEX
	bzero

ANSI_SYNOPSIS
	#include <string.h>
	void bzero(char *<[b]>, size_t <[length]>);

TRAD_SYNOPSIS
	#include <string.h>
	void bzero(<[b]>, <[length]>)
	char *<[b]>;
	size_t <[length]>;

DESCRIPTION
<<bzero>> initializes <[length]> bytes of memory, starting at address
<[b]>, to zero.

RETURNS
<<bzero>> does not return a result.

PORTABILITY
<<bzero>> is in the Berkeley Software Distribution.
Neither ANSI C nor the System V Interface Definition (Issue 2) require
<<bzero>>.

<<bzero>> requires no supporting OS subroutines.
*/

#include <string.h>

_VOID
_DEFUN_WRAP (bzero, (b, length),
	char *b _AND
	size_t length)
{
  while (length--)
    *b++ = 0;
}
