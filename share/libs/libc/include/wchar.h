/**
*** static char sccs_id[] = "$Id: wchar.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/

#ifndef _WCHAR_H
#define _WCHAR_H

#include "_ansi.h"

#define __need_wchar_t
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int _EXFUN(wcscmp, (wchar_t *__s1, wchar_t *__s2));
int _EXFUN(wcslen, (wchar_t *__s1));

#ifdef __cplusplus
}
#endif

#endif /* _WCHAR_H */
