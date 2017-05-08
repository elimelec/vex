/**
*** static char sccs_id[] = "$Id: fcntl.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/

#ifndef	_FCNTL_
#ifdef __cplusplus
extern "C" {
#endif
#define	_FCNTL_
#include <_ansi.h>
#define	_FOPEN		(-1)	/* from sys/file.h, kernel use only */
#define	_FREAD		0x0001	/* read enabled */
#define	_FWRITE		0x0002	/* write enabled */
#define	_FNDELAY	0x0004	/* non blocking I/O (4.2 style) */
#define	_FAPPEND	0x0008	/* append (writes guaranteed at the end) */
#define	_FMARK		0x0010	/* internal; mark during gc() */
#define	_FDEFER		0x0020	/* internal; defer for next gc pass */
#define	_FASYNC		0x0040	/* signal pgrp when data ready */
#define	_FSHLOCK	0x0080	/* BSD flock() shared lock present */
#define	_FEXLOCK	0x0100	/* BSD flock() exclusive lock present */
#define	_FCREAT		0x0200	/* open with file create */
#define	_FTRUNC		0x0400	/* open with truncation */
#define	_FEXCL		0x0800	/* error on open if file exists */
#define	_FNBIO		0x1000	/* non blocking I/O (sys5 style) */
#define	_FSYNC		0x2000	/* do all writes synchronously */
#define	_FNONBLOCK	0x4000	/* non blocking I/O (POSIX style) */
#define	_FNOCTTY	0x8000	/* don't assign a ctty on this open */


#if defined(__hpux) || (defined(_vex_) && !defined(__WINNT__) && !defined(__linux))
#define O_RDONLY    00000000     /* Open for reading only */
#define O_WRONLY    00000001     /* Open for writing only */
#define O_RDWR      00000002     /* Open for reading or writing */
#define O_ACCMODE   00000003     /* Mask for file access modes */
#define O_NDELAY    00000004     /* Non-blocking open and/or I/O */
#define O_APPEND    00000010     /* Append (all writes happen at end of file) */
#define O_BLKSEEK   00000100     /* Interpret file offsets as block offsets. */
#define O_CREAT     00000400     /* Open with file create (uses third open arg) */
#define O_TRUNC     00001000     /* Open with truncation */
#define O_EXCL      00002000     /* Refuse to create if it already exists */
#define O_LARGEFILE 00004000     /* large file open flag */
#define O_NONBLOCK  00200000     /* Non-blocking open and/or I/O; POSIX-style */
#define O_NOCTTY    00400000     /* Don't assign controlling tty */

#ifdef _vex_
#define O_BINARY    01000000     /* Binary */
#define O_TEXT      02000000     /* Text */
#else
#define O_DSYNC     01000000     /* Synchronized IO data integrity completion */
#define O_RSYNC     02000000     /* Synchronized IO read */
#endif

#define O_SYNCIO    O_SYNC      /* Backward compatibility */
#define FBLKSEEK    O_BLKSEEK   /* Internal equivalent of O_BLKSEEK. */
#define FDSYNC      O_DSYNC     /* Synchronized IO data integrity completion */
#define FLARGEFILE  O_LARGEFILE /* large file open flag */
#define FRSYNC      O_RSYNC     /* Synchronized IO read */

#elif defined(__linux__)

#define O_ACCMODE          0003
#define O_RDONLY             00
#define O_WRONLY             01
#define O_RDWR               02
#define O_CREAT            0100 /* not fcntl */
#define O_EXCL             0200 /* not fcntl */
#define O_NOCTTY           0400 /* not fcntl */
#define O_TRUNC           01000 /* not fcntl */
#define O_APPEND          02000
#define O_NONBLOCK        04000
#define O_NDELAY        O_NONBLOCK
#define O_SYNC           010000
#define O_FSYNC          O_SYNC
#define O_ASYNC          020000

#else

/*
 * Flag values for open(2) and fcntl(2)
 * The kernel adds 1 to the open modes to turn it into some
 * combination of FREAD and FWRITE.
 */

#define	O_ACCMODE	(O_RDONLY|O_WRONLY|O_RDWR)

#define	O_RDONLY	0		/* +1 == FREAD */
#define	O_WRONLY	1		/* +1 == FWRITE */
#define	O_RDWR		2		/* +1 == FREAD|FWRITE */
#define	O_APPEND	_FAPPEND
#define	O_CREAT		_FCREAT
#define	O_TRUNC		_FTRUNC
#define	O_EXCL		_FEXCL
/*	O_SYNC		_FSYNC		not posix, defined below */
/*	O_NDELAY	_FNDELAY 	set in include/fcntl.h */
/*	O_NDELAY	_FNBIO 		set in 5include/fcntl.h */
#define	O_NONBLOCK	_FNONBLOCK
#define	O_NOCTTY	_FNOCTTY

#endif


/* For machines which care - */
#ifdef _WIN32
#define _FBINARY        0x10000
#define _FTEXT          0x20000
#undef  O_BINARY
#undef  O_TEXT
#define O_BINARY	_FBINARY
#define O_TEXT		_FTEXT

/* The windows header files define versions with a leading underscore.  */
#define _O_RDONLY	O_RDONLY
#define _O_WRONLY	O_WRONLY
#define _O_RDWR		O_RDWR
#define _O_APPEND	O_APPEND
#define _O_CREATE	O_CREAT
#define _O_TRUNC	O_TRUNC
#define _O_EXCL		O_EXCL
#define _O_TEXT		O_TEXT
#define _O_BINARY	O_BINARY
#define _O_RAW		O_BINARY
#endif

#ifndef	_POSIX_SOURCE

#ifdef __hpux
#define O_SYNC      00100000     /* Synchronized IO file integrity completion */
#elif !defined(__linux__)
#define	O_SYNC		_FSYNC
#endif

/*
 * Flags that work for fcntl(fd, F_SETFL, FXXXX)
 */
#define	FAPPEND		_FAPPEND
#define	FSYNC		_FSYNC
#define	FASYNC		_FASYNC
#define	FNBIO		_FNBIO
#define	FNONBIO		_FNONBLOCK	/* XXX fix to be NONBLOCK everywhere */
#define	FNDELAY		_FNDELAY

/*
 * Flags that are disallowed for fcntl's (FCNTLCANT);
 * used for opens, internal state, or locking.
 */
#define	FREAD		_FREAD
#define	FWRITE		_FWRITE
#define	FMARK		_FMARK
#define	FDEFER		_FDEFER
#define	FSHLOCK		_FSHLOCK
#define	FEXLOCK		_FEXLOCK

/*
 * The rest of the flags, used only for opens
 */
#define	FOPEN		_FOPEN
#define	FCREAT		_FCREAT
#define	FTRUNC		_FTRUNC
#define	FEXCL		_FEXCL
#define	FNOCTTY		_FNOCTTY

#endif	/* !_POSIX_SOURCE */

/* XXX close on exec request; must match UF_EXCLOSE in user.h */
#define	FD_CLOEXEC	1	/* posix */

/* fcntl(2) requests */
#define	F_DUPFD		0	/* Duplicate fildes */
#define	F_GETFD		1	/* Get fildes flags (close on exec) */
#define	F_SETFD		2	/* Set fildes flags (close on exec) */
#define	F_GETFL		3	/* Get file flags */
#define	F_SETFL		4	/* Set file flags */
#ifndef	_POSIX_SOURCE
#define	F_GETOWN 	5	/* Get owner - for ASYNC */
#define	F_SETOWN 	6	/* Set owner - for ASYNC */
#endif	/* !_POSIX_SOURCE */
#define	F_GETLK  	7	/* Get record-locking information */
#define	F_SETLK  	8	/* Set or Clear a record-lock (Non-Blocking) */
#define	F_SETLKW 	9	/* Set or Clear a record-lock (Blocking) */
#ifndef	_POSIX_SOURCE
#define	F_RGETLK 	10	/* Test a remote lock to see if it is blocked */
#define	F_RSETLK 	11	/* Set or unlock a remote lock */
#define	F_CNVT 		12	/* Convert a fhandle to an open fd */
#define	F_RSETLKW 	13	/* Set or Clear remote record-lock(Blocking) */
#endif	/* !_POSIX_SOURCE */

/* fcntl(2) flags (l_type field of flock structure) */
#define	F_RDLCK		1	/* read lock */
#define	F_WRLCK		2	/* write lock */
#define	F_UNLCK		3	/* remove lock(s) */
#ifndef	_POSIX_SOURCE
#define	F_UNLKSYS	4	/* remove remote locks for a given system */
#endif	/* !_POSIX_SOURCE */

/*#include <sys/stdtypes.h>*/

/* file segment locking set data type - information passed to system by user */
struct flock {
	short	l_type;		/* F_RDLCK, F_WRLCK, or F_UNLCK */
	short	l_whence;	/* flag to choose starting offset */
	long	l_start;	/* relative offset, in bytes */
	long	l_len;		/* length, in bytes; 0 means lock to EOF */
	short	l_pid;		/* returned with F_GETLK */
	short	l_xxx;		/* reserved for future use */
};

#ifndef	_POSIX_SOURCE
/* extended file segment locking set data type */
struct eflock {
	short	l_type;		/* F_RDLCK, F_WRLCK, or F_UNLCK */
	short	l_whence;	/* flag to choose starting offset */
	long	l_start;	/* relative offset, in bytes */
	long	l_len;		/* length, in bytes; 0 means lock to EOF */
	short	l_pid;		/* returned with F_GETLK */
	short	l_xxx;		/* reserved for future use */
	long	l_rpid;		/* Remote process id wanting this lock */
	long	l_rsys;		/* Remote system id wanting this lock */
};
#endif	/* !_POSIX_SOURCE */


#include <sys/types.h>
#include <sys/stat.h>		/* sigh. for the mode bits for open/creat */

extern int open _PARAMS ((const char *, int, ...));
extern int creat _PARAMS ((const char *, mode_t));
extern int fcntl _PARAMS ((int, int, ...));

#ifdef __cplusplus
}
#endif
#endif	/* !_FCNTL_ */
