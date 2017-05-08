/**
*** Copyright (C) 1996-2001 Hewlett-Packard Company.
***

/**
*** static char sccs_id[] = "$Id: varargs.h,v 1.1.1.1 2001/11/21 20:35:06 frb Exp $ ";
**/

/**
*** Author:  Paolo Faraboschi
**/

#ifndef _VARARGS_INCLUDED
#define _VARARGS_INCLUDED

#ifndef _VA_LIST
#define _VA_LIST
    typedef void *va_list;
#endif

#define va_dcl int va_alist;

#define __va_align(ptr,align) 						\
    ( ((int) (ptr) + (align) - 1) & ~((align) - 1) )

#define __va_sizeof(TYPE) 						\
    __va_align(sizeof(TYPE),4)

#ifdef _STDARG_INCLUDED
#define va_start(AP,__parmN)                                            \
    ( AP = (va_list) (((int)__builtin_va_start(__parmN)) + sizeof(__parmN)) )
#else
#define va_start(AP)                                                    \
    ( AP = (va_list)__builtin_va_start(va_alist) )
#endif

#ifdef _little_endian
#define va_arg(AP,TYPE)                                                 \
    ( AP = (va_list) (  sizeof(TYPE) > 4                                \
                      ? __va_align((int) AP + __va_sizeof(TYPE), 8)	\
                      : __va_align((int) AP + __va_sizeof(TYPE), 4)),	\
      *((TYPE *) ((int) (AP) - __va_sizeof(TYPE))))

#else /* _big_endian */
#define va_arg(AP,TYPE)                                                 \
    ( AP = (va_list) (  sizeof(TYPE) > 4                                \
                      ? __va_align((int) AP + __va_sizeof(TYPE), 8)	\
                      : __va_align((int) AP + __va_sizeof(TYPE), 4)),	\
      *((TYPE *) ((int) (AP) -						\
                  (   sizeof(TYPE) < 4 && !__is_aggregate(TYPE)		\
		    ? sizeof(TYPE)					\
		    : __va_sizeof(TYPE)))) )

#endif /* _little_endian */

#define va_end(AP) ((void)0)

#endif /* _VARARGS_INCLUDED */
