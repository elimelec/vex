/* 
** static char sccs_id[] = "$Id: mbstowcs.c,v 1.1.1.1 2001/11/21 20:34:40 frb Exp $ ";
*/
#include <stdlib.h>

size_t
_DEFUN (mbstowcs, (pwcs, s, n),
        wchar_t *pwcs _AND
        const char *s _AND
        size_t n)
{
        int count = 0;

        if (n != 0) {
                do {
                        if ((*pwcs++ = (wchar_t) *s++) == 0)
                                break;
                        count++;
                } while (--n != 0);
        }

        return count;
}
