/* 
** static char sccs_id[] = "$Id: wcstombs.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
*/
#include <stdlib.h>

size_t
_DEFUN (wcstombs, (s, pwcs, n),
        char *s _AND
        const wchar_t *pwcs _AND
        size_t n)
{
        int count = 0;

        if (n != 0) {
                do {
                        if ((*s++ = (char) *pwcs++) == 0)
                                break;
                        count++;
                } while (--n != 0);
        }

        return count;
}
