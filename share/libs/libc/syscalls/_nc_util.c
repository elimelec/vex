/**
*** static char sccs_id[] = "$Id: _nc_util.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
**/

#include <_ansi.h>

int 
_nc_strcpy (
	     char *dst,
	     _CONST char *src,
	     unsigned int maxlen)
{
  unsigned int len = 0;
  _CONST char *ps = src;
  char *pd = dst;
  while (len < maxlen && *ps)
    *pd++ = *ps++, len++;
  if (len >= maxlen)
    return -1;
  *pd = 0;
  return len;
}
