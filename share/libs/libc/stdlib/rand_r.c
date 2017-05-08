/* 
** static char sccs_id[] = "$Id: rand_r.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
*/
#include <stdlib.h>

int
_DEFUN (rand_r, (seed), unsigned int *seed)
{
        return (((*seed) = (*seed) * 1103515245 + 12345) & RAND_MAX);
}
