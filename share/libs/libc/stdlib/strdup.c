/* 
** static char sccs_id[] = "$Id: strdup.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
*/
#include <stdlib.h>
#include <string.h>

char *
_DEFUN (strdup, (str), _CONST char *str)
{
  size_t len = strlen (str) + 1;
  char *copy = malloc (len);
  if (copy)
    {
      memcpy (copy, str, len);
    }
  return copy;
}
