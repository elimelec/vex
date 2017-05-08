/* 
** static char sccs_id[] = "$Id: memchr.c,v 1.2 2003/05/21 12:25:29 frb Exp $ ";
*/
/*
FUNCTION
	<<memchr>>---find character in memory

INDEX
	memchr

ANSI_SYNOPSIS
	#include <string.h>
	void *memchr(const void *<[src]>, int <[c]>, size_t <[length]>);

TRAD_SYNOPSIS
	#include <string.h>
	void *memchr(<[src]>, <[c]>, <[length]>)
	void *<[src]>;
	void *<[c]>;
	size_t <[length]>;

DESCRIPTION
	This function searches memory starting at <<*<[src]>>> for the
	character <[c]>.  The search only ends with the first
	occurrence of <[c]>, or after <[length]> characters; in
	particular, <<NULL>> does not terminate the search.

RETURNS
	If the character <[c]> is found within <[length]> characters
	of <<*<[src]>>>, a pointer to the character is returned. If
	<[c]> is not found, then <<NULL>> is returned.

PORTABILITY
<<memchr>>> is ANSI C.

<<memchr>>  requires no supporting OS subroutines.

QUICKREF
	memchr ansi pure
*/

#include <_ansi.h>
#include <string.h>

_PTR
_DEFUN_WRAP (memchr, (src_void, c, length),
	_CONST _PTR src_void _AND
	int c _AND
	size_t length)
{
  _CONST unsigned char *src = (_CONST unsigned char *) src_void;
  unsigned char uc = c;

  while (length--)
    {
      if (*src == uc)
	return (_PTR) src;
      src++;
    }
  return NULL;
}
