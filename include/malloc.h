/**
*** static char sccs_id[] = "$Id: malloc.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/
/* malloc.h -- header file for memory routines.

   This header file only exists for easier compatibility with other
   systems that provide one.  */

#ifndef _INCLUDE_MALLOC_H_
#define _INCLUDE_MALLOC_H_

#include <_ansi.h>
#include <sys/reent.h>

#define __need_size_t
#include <stddef.h>

#ifdef __cplusplus
   extern "C" {
#endif

extern _PTR malloc _PARAMS ((size_t));
extern _PTR realloc _PARAMS ((_PTR, size_t));
extern _VOID free _PARAMS ((_PTR));

extern _PTR _malloc_r _PARAMS ((struct _reent *, size_t));
extern _PTR _realloc_r _PARAMS ((struct _reent *, _PTR, size_t));
extern _VOID _free_r _PARAMS ((struct _reent *, _PTR));

extern _VOID mstats _PARAMS ((char *));
extern _VOID _mstats_r _PARAMS ((struct _reent *, char *));

#ifdef __hpux
#ifndef _STRUCT_MALLINFO
#define _STRUCT_MALLINFO
  struct mallinfo  {
        int arena;      /* total space in arena */
        int ordblks;    /* number of ordinary blocks */
        int smblks;     /* number of small blocks */
        int hblks;      /* number of holding blocks */
        int hblkhd;     /* space in holding block headers */
        int usmblks;    /* space in small blocks in use */
        int fsmblks;    /* space in free small blocks */
        int uordblks;   /* space in ordinary blocks in use */
        int fordblks;   /* space in free ordinary blocks */
        int keepcost;   /* cost of enabling keep option */
  };
#endif /* _STRUCT_MALLINFO */
extern struct mallinfo mallinfo();
#endif /* __hpux */

#ifdef __cplusplus
   }
#endif

#endif /* _INCLUDE_MALLOC_H_ */
