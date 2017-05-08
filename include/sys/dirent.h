/**
*** static char sccs_id[] = "$Id: dirent.h,v 1.2 2002/06/20 17:25:47 frb Exp $ ";
**/

#ifndef _SYS_DIRENT_INCLUDED
#define _SYS_DIRENT_INCLUDED

#define _MAXNAMLEN 255

#include "_ansi.h"
#include <sys/types.h>

   /* directory entry structure */
#ifdef __linux__
    struct dirent {
        long d_ino;
        long d_off;
        unsigned short int d_reclen;
        unsigned char d_type;
        char d_name[256];
    };
#else
   struct dirent {
      ino_t d_ino;			/* file number of entry */
      short d_reclen;			/* length of this record */
      short d_namlen;			/* length of string in d_name */
      char  d_name[_MAXNAMLEN + 1];	/* name must be no longer than this */
   };
#endif

   /* DIR (directory stream) structure */
   typedef struct __dirdesc {
      int   dd_fd;		/* file descriptor */
      long  dd_loc;
      long  dd_size;
      long  dd_bbase;
      long  dd_entno;		/* directory entry number */
      long  dd_len;		/* buffer size */
      char  *dd_buf;		/* malloc'ed buffer */
      void  *dd_lock;
      long  dd_seek;
   } DIR;

#ifdef __cplusplus
   extern "C" {
#endif /* __cplusplus */

     extern DIR *           _EXFUN(opendir,(const char *));
     extern struct dirent * _EXFUN(readdir,(DIR *));
     extern void            _EXFUN(rewinddir,(DIR *));
     extern int             _EXFUN(closedir,(DIR *));
     extern long            _EXFUN(telldir,(DIR *));
     extern void            _EXFUN(seekdir,(DIR *, long int));
     extern int             _EXFUN(scandir,(const char *,
			                    struct dirent ***,
			                    int (*)(const struct dirent *),
			                    int (*)(const struct dirent **,
				            const struct dirent **)));
     extern int 	    _EXFUN(alphasort,(const struct dirent **, 
                                              const struct dirent **));
     extern int 	    _EXFUN(getdirentries,(int, struct direct *, size_t, off_t *));

#ifdef __cplusplus
   }
#endif /* __cplusplus */

#endif /* _SYS_DIRENT_INCLUDED */
