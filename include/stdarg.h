/**
*** static char sccs_id[] = "@(#)stdarg.h	1.5 04/16/98 10:58:10";
**/
/**
*** Copyright (C) 1996-1998 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
**/

/**
*** static char sccs_id[] = "@(#)stdarg.h	1.7 06/04/98 10:54:16";
**/

/**
*** Author:  Paolo Faraboschi
**/

#ifndef _STDARG_INCLUDED
#ifndef __need___va_list
#define _STDARG_INCLUDED
#endif
#undef __need___va_list

#ifndef _VA_LIST
#define _VA_LIST
    typedef void *va_list;
#endif

#ifdef __cplusplus
extern "C" {
    const char * __builtin_va_start(const char *);
}
#endif

#ifdef _STDARG_INCLUDED 
#include <varargs.h>
#endif /* _STDARG_INCLUDED */

#endif /* _STDARG_INCLUDED */

