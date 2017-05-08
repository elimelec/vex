/**
*** static char sccs_id[] = "$Id: nl_ctype.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/
/**
*** We must pick up this version of nl_ctype.h.
*** We generate a warning message if the host nl_ctype.h has been included.
**/
#ifndef _HPL_PROTO_NL_CTYPE_INCLUDED
#define _HPL_PROTO_NL_CTYPE_INCLUDED

#ifdef _NL_CTYPE_INCLUDED
#define INCORRECT_NL_CTYPE_INCLUDED 0
#define INCORRECT_NL_CTYPE_INCLUDED 1
#endif

/**
*** The HP-UX version of libc.a is compiled for a clean namespace, providing
*** secondary definitions for library symbols.  Our environment does not
*** support this feature.  Hence we need to change the declarations for the
*** various library symbols to their primary definitions, and
*** use these names inside the macros.
**/
#define __1kanji	_1kanji
#define __2kanji	_2kanji
#define __sec_tab	_sec_tab
#define __status_tab	_status_tab
#include "/usr/include/nl_ctype.h"

#endif
