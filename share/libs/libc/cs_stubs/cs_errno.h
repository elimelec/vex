/* 
** static char sccs_id[] = "$Id: cs_errno.h,v 1.1 2005/01/19 15:57:17 frb Exp $
*/

#ifndef CS_ERRNO_INCLUDED
#define CS_ERRNO_INCLUDED
#include <errno.h>

/* We use the errno variable set by the system dependent layer.  */
extern int *__vex_errnoptr (void);
#define cs_errno (*__vex_errnoptr())

#endif
