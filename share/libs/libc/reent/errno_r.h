/* 
** static char sccs_id[] = "$Id: errno_r.h,v 1.1 2005/01/19 15:57:17 frb Exp $
*/

#ifndef REENT_ERRNO_INCLUDED
#define REENT_ERRNO_INCLUDED

/* We use the errno variable set by the system dependent layer.  */
#ifdef errno
# undef errno
#endif
extern int *__vex_errnoptr (void);
#define errno (*__vex_errnoptr())

#endif
