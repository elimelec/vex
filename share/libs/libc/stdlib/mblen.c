/* 
** static char sccs_id[] = "$Id: mblen.c,v 1.1.1.1 2001/11/21 20:34:40 frb Exp $ ";
*/
#include <stdlib.h>

int
_DEFUN (mblen, (s, n), 
        const char *s _AND
        size_t n)
{
        if (s == NULL || *s == '\0')
                return 0;
        if (n == 0)
                return -1;
        return 1;
}
