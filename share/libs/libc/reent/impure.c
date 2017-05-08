/* 
** static char sccs_id[] = "$Id: impure.c,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
*/
#include <reent.h>

#ifndef __ATTRIBUTE_IMPURE_PTR__
#define __ATTRIBUTE_IMPURE_PTR__
#endif

#ifndef __ATTRIBUTRE_IMPURE_DATA__
#define __ATTRIBUTRE_IMPURE_DATA__
#endif

static struct _reent __ATTRIBUTRE_IMPURE_DATA__ impure_data = _REENT_INIT (impure_data);
struct _reent *__ATTRIBUTE_IMPURE_PTR__ _IMPURE_PTR = &impure_data;
