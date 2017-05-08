/**
*** static char sccs_id[] = "$Id: limits.h,v 1.1.1.1 2001/11/21 20:35:06 frb Exp $ ";
**/

/**
*** We must pick up this version of limits.h.
*** We generate a warning message if the host limits.h has been included.
**/
#ifdef _LIMITS_INCLUDED
#define INCORRECT_LIMITS_INCLUDED 0
#define INCORRECT_LIMITS_INCLUDED 1
#endif

#ifndef _VEX_LIMITS_INCLUDED
#define _VEX_LIMITS_INCLUDED

#define CHAR_BIT	8	    		/* Number of bits in a char */
#define CHAR_MAX	127	    		/* Max integer value of a char */
#define CHAR_MIN        (-128)      		/* Min integer value of a char */
#define MB_LEN_MAX	4	    		/* Max bytes in a multibyte character */
#define INT_MAX	        2147483647  		/* Max decimal value of an int */
#define INT_MIN	        (-2147483647 - 1)  	/* Min decimal value of an int */
#define LONG_MAX	2147483647L 	   	/* Max decimal value of a long */
#define LONG_MIN	(-2147483647L - 1) 	/* Min decimal value of a long */
#define SCHAR_MAX       127        		/* max value of a signed char */
#define SCHAR_MIN       (-128)     		/* Min value of a signed char */
#define SHRT_MAX        32767      		/* max decimal value of a short */
#define SHRT_MIN        (-32768)   		/* Min decimal value of a short */
#define UCHAR_MAX       255        		/* max value of unsigned char */
#define UINT_MAX	(4294967295U) 		/* max value of an unsigned integer */
#define ULONG_MAX	(4294967295UL)		/* max value of a unsigned long int */
#define USHRT_MAX       (65535U) 		/* max value of a unsigned short int */


#if defined(_INCLUDE_POSIX_SOURCE) || defined(_INCLUDE_POSIX2_SOURCE)
#  define _POSIX_ARG_MAX  	4096	/* The length of the arguments for 
					   one of the exec functions in bytes, 
					   including environment data. */
#  define _POSIX_CHILD_MAX	6	/* The number of simultaneous
					   processes per real user ID */
#  define _POSIX_LINK_MAX	8	/* The value of a files link count */
#  define _POSIX_MAX_CANON  	255     /* Max number of bytes in a terminal 
					   canonical input line */
#  define _POSIX_MAX_INPUT	255	/* The number of bytes for which space 
					   will be available in a terminal 
					   input queue */
#  define _POSIX_NAME_MAX	14	/* The number of bytes in a filename */
#  define _POSIX_NGROUPS_MAX	0	/* The number of simultaneous 
					   supplementary group IDs per
					   process. */
#  define _POSIX_OPEN_MAX	16	/* The number of files that one process
					   can have open at one time */
#  define _POSIX_PATH_MAX	255 	/* The number of bytes in a pathname */
#  define _POSIX_PIPE_BUF	512	/* The number of bytes that can be 
					   written atomically when writing to 
					   a pipe. */
#  define _POSIX_SSIZE_MAX	32767	/* The value that can be stored in
					   an object of type ssize_t */
#  define _POSIX_TZNAME_MAX	3	/* The maximum number of bytes
					   supported for the name of a time
					   zone (not of the TZ variable). */
#  define _POSIX_STREAM_MAX	8	/* The number of streams that one 
					   process can have open at one
					   time */
#  define _POSIX_CLOCKRES_MIN	20000000 /* The CLOCK_REALTIME clock
					    resolution, in nanoseconds */

/*
 * The following limit is also available using the sysconf() function.
 * Use of sysconf() is advised over use of the constant value defined
 * here, since it should pose fewer portability and forward-compatability
 * problems.
 */
#  define NGROUPS_MAX		20	/* Maximum number of simultaneous
					   supplementary group IDs per 
					   process */

#  if !defined(_POSIX1_1988) && !defined(_XPG3) || defined(_XPG4_EXTENDED)
#    define SSIZE_MAX		INT_MAX /* The maximum value that can be
					   stored in an object of type 
					   ssize_t */

/*
 * The following limit is also available using the sysconf() function.
 * Use of sysconf() is advised over use of the constant value defined
 * here, since it should pose fewer portability and forward-compatability
 * problems.
 */
#    define TZNAME_MAX		19	/* Maximum number of bytes
					   supported for the name of the 
					   time zone (not of the TZ 
					   variable). */
#  endif /* !defined(_POSIX1_1988) && !defined(_XPG3) || defined(_XPG4_EXTENDED) */

#endif /* defined(_INCLUDE_POSIX_SOURCE) || defined(_INCLUDE_POSIX2_SOURCE) */

#if defined(_INCLUDE_POSIX4_SOURCE)
/* the following limits are from POSIX 1003.4 (draft 14) section 2.8-2.9 */
#    define _POSIX_DELAYTIMER_MAX	32
#    define DELAYTIMER_MAX		_POSIX_DELAYTIMER_MAX
#    define _POSIX_TIMER_MAX		32
#    define TIMER_MAX			_POSIX_TIMER_MAX

#    define _POSIX_AIO_LISTIO_MAX	2  /* max I/O ops in a list I/O call */
#    define _POSIX_AIO_MAX		1  /* max outstanding async I/O ops */
#    define _POSIX_MQ_OPEN_MAX		8  /* max open msg Qs per process */
#    define _POSIX_MQ_PRIO_MAX		32 /* max message priorities */
#    define _POSIX_RTSIG_MAX		8  /* # of realtime signals */
#    define _POSIX_SEM_NSEMS_MAX	256 /* max open semas per process */
#    define _POSIX_SEM_VALUE_MAX	32767 /* max semaphore value */
#    define _POSIX_SIGQUEUE_MAX		32 /* max queued sigs pending/sender */
#endif /* defined(_INCLUDE_POSIX4_SOURCE) */

/* the following limits are from POSIX 1003.2 (draft 8) section 2.14 */
#if defined ( _INCLUDE_POSIX2_SOURCE ) || defined ( _XPG4 )

#  define BC_BASE_MAX		99	/* largest ibase and obase for bc */
#  define BC_DIM_MAX		2048	/* max no. of elems in bc array */
#  define BC_SCALE_MAX		99	/* maximum scale value for bc */
#  define BC_STRING_MAX		1000 	/* max length of string constant 
				  	   accepted by bc */
#  define COLL_WEIGHTS_MAX	4	/* max number of weights that can be 
					   assigned to an entry of the 
					   LC_COLLATE order keyword in the 
					   locale definition file   */
#  define EXPR_NEST_MAX		32	/* max no. of expressions nested 
					   within parentheses in expr */
#  define LINE_MAX		2048	/* Expected length in bytes of a 
					   utility's input line when input
					   is from text files */
#  define RE_DUP_MAX		255	/* Max no. of repeated occurrences
					   of an RE when using \{m,n\}
					   notation */

#  define _POSIX2_BC_BASE_MAX	99	/* The maximum ibase and obase values
				   	   allowed by the bc utility */
#  define _POSIX2_BC_DIM_MAX	2048	/* The maximum number of elements 
					   permitted in an array by the bc 
					   utility. */
#  define _POSIX2_BC_SCALE_MAX	99	/* The maximum scale value allowed 
					   by the bc utility. */
#  define _POSIX2_BC_STRING_MAX 1000	/* The maximum length of a string 
					   constant accepted by the bc 
					   utility. */
#  define _POSIX2_COLL_WEIGHTS_MAX 2	/* The maximum number of weights that 
					   can be assigned to an entry of the 
					   LC_COLLATE order keyword in the 
					   locale definition file. */
#  define _POSIX2_EXPR_NEST_MAX	32	/* The maximum number of expressions 
					   that can be nested within 
					   parentheses by the expr utility. */
#  define _POSIX2_LINE_MAX	2048	/* Unless otherwise noted, the maximum 
					   length, in bytes, of a utility's 
					   input line (either standard input or 
					   another file), when the utility is 
					   described as processing text files.
					   The length includes room for the 
					   trailing newline. */
# define _POSIX2_RE_DUP_MAX	255	/* The maximum number of repeated 
					   occurrences of a regular expression 
					   permitted when using the interval 
					   notation \{m,n\}. */

#endif /* defined ( _INCLUDE_POSIX2_SOURCE ) || defined ( _XPG4 ) */


#ifdef _INCLUDE_XOPEN_SOURCE
#  if !defined (_AES_SOURCE) && !defined (_XPG4)
#     ifndef DBL_MIN
#       define DBL_MIN   2.2250738585072014e-308   /* Min decimal value of a 
							double */
#     endif /* DBL_MIN */

#     ifndef FLT_MIN 
#       define FLT_MIN   ((float)1.17549435e-38) /* Min decimal value of a float */
#     endif /* FLT_MIN */
#  endif  /* !defined (_AES_SOURCE) && !defined (_XPG4) */

#  ifndef _AES_SOURCE
#     ifndef DBL_DIG
#       define DBL_DIG   15	/* Digits of precision of a double */  
#     endif /* DBL_DIG */

#     ifndef DBL_MAX
#       define DBL_MAX   1.7976931348623157e+308   /* Max decimal value of a 
						      double */
#     endif /* DBL_MAX */

#     ifndef FLT_DIG
#       define FLT_DIG   6		/* Digits of precision of a float */  
#     endif /* FLT_DIG */

#     ifndef FLT_MAX
#       define FLT_MAX   ((float)3.40282347e+38) /*Max decimal value of a float */
#     endif /* FLT_MAX */

#     ifndef TMP_MAX
#       define TMP_MAX     17576  /* min number of unique names generated by 
				     tmpnam() */
#     endif /* TMP_MAX */
#  endif /* _AES_SOURCE */


#  define LONG_BIT    32	/* Number of bits in a long */
#  define WORD_BIT    32	/* number of bits in a "word" (int) */
#  define NL_LANGMAX  (3*_POSIX_NAME_MAX+2)  /* Max number of bytes in a LANG name */
#  define NL_ARGMAX   9     	/* max value of "digit" in calls to the NLS
				   printf() and scanf() functions */

/* message catologue limits */
#  define NL_MSGMAX     65534	/* max message number */
#  define NL_NMAX       2	/* max number of bytes in N-to-1 mapping 
				   characters */
#  ifndef NL_SETMAX
#    define NL_SETMAX     255	/* max set number */
#  endif /* NL_SETMAX */
#  define NL_TEXTMAX    8192	/* max number of bytes in a message string */
#  define NZERO		20	/* default process priority */
#  define PASS_MAX      8	/* max number of significant characters in a 
				   password (not including terminating null) */

#  define _SYS_NMLN	9	/* length of strings returned by
				   uname(OS) */
#  define CHARCLASS_NAME_MAX	255	/* max length of character class */

#  if defined(_XPG2) || defined(_SVID3) || defined(_XPG4_EXTENDED)
/*
 * The following limits are not actually invariant, but are configurable.
 * The correct values can be determined using the sysconf() function.
 * The default values are provided here because the constants are specified
 * by several publications including XPG (X/Open Portability Guide) Issue 2
 * and SVID (System V Interface Definition) Issue 2.
 */
#    define ARG_MAX		20478	/* Maximum length of arguments for the 
					   exec function in bytes, including 
					   environment data */
#    define CHILD_MAX	   	25	/* Maximum number of simultaneous
					   processes per real user ID */
#    define OPEN_MAX	   	60	/* Maximum number of files that one 
					   process can have open at any given 
					   time */

/*
 * The following limits are not actually invariant, but can vary by file
 * system or device.  the correct values can be determined using the 
 * pathconf() function.  The default values are provided here because the
 * constants are specified by several publications including XPG Issue 2
 * and SVID Issue 2.
 */
#    define LINK_MAX   	32767	/* Max number of links to a single file */
#    define MAX_CANON  	512     /* Max number of bytes in a terminal canonical 
			   	   input line */
#    define MAX_INPUT  	512 	/* Max number of bytes allowed in a terminal 
				   input queue */ 
#    if !defined(NAME_MAX)	/* Conditionally defined in <stdio.h> */
#      define NAME_MAX   14	/* Max number of characters in a filename
				   (not including terminating null) */
#    endif /* !defined(NAME_MAX) */
#    define PATH_MAX   	1023	/* max number of characters in a pathname (not 
				   including terminating null) */
#    define PIPE_BUF   	8192	/* max number bytes that is guaranteed
				   to be atomic when writing to a pipe */ 
#  endif /* _XPG2 || defined(_SVID3) || _XPG4_EXTENDED */

# if defined(_XPG2) || defined(_SVID3)
/*
 * The following limits are not actually invariant, but are configurable.
 * The values are not generally useful for portable applications due to
 * the system-wide nature of these limits.  The default values are provided
 * here because the constants are specified by several publications
 * including XPG Issue 2 and SVID Issue 2.
 */
#    define LOCK_MAX	32	/* max number of entries in system lock table */
#    define PROC_MAX	84	/* max number of simultaneous processes on 
				   system */
#    define SYS_OPEN	120	/* max number of files open on system */

/* 
 * The following limits are obsolescent.  Some are not generally
 * useful for portable applications.  Some have been replaced by 
 * limits with different names defined by industry standards.  Some
 * have values that can vary.  The values (defaults for variable limits)
 * are provided here because the constants are specified by several 
 * publications including XPG Issue 2 and SVID Issue 2.
 */
#    define FCHR_MAX	INT_MAX		/*max file offset in bytes */
#    define MAX_CHAR	MAX_INPUT	/* max size of a character input 
					   buffer */
#    define SYS_NMLN	_SYS_NMLN	/* length of strings returned by
					   uname(OS) */
#    define SYSPID_MAX	4		/* max pid of system processes */
#    define USI_MAX	UINT_MAX	/* max decimal value of an unsigned 
					   int */
#  endif /* defined(_XPG2) || defined(_SVID3) */

#endif /* _INCLUDE_XOPEN_SOURCE */


#ifdef _INCLUDE_AES_SOURCE
#  define ATEXIT_MAX	32	/* Max # of functions that can be called by
				   atexit() */
#endif /* _INCLUDE_AES_SOURCE */

#ifdef _INCLUDE_XOPEN_SOURCE_EXTENDED 
#  define _XOPEN_IOV_MAX	16
#  define IOV_MAX		_XOPEN_IOV_MAX
#  define PAGESIZE              4096
#  define PAGE_SIZE             PAGESIZE
#  define STREAM_MAX            60      /* same as FOPEN_MAX in <stdio.h> */
#endif /* _INCLUDE_XOPEN_SOURCE_EXTENDED */


#endif /* _VEX_LIMITS_INCLUDED */
