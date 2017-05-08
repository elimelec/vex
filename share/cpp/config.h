/**
*** static char sccs_id[] = "@(#)config.h	1.2 03/30/99 17:54:59";
**/

#define HAVE_STRERROR 1
#define HAVE_STDDEF_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_STRINGS_H 1
#define HAVE_TIME_H 1
#define HAVE_UNISTD_H 1

#define GCC_INCLUDE_DIR ""
#define GPLUSPLUS_INCLUDE_DIR ""
#define OLD_GPLUSPLUS_INCLUDE_DIR ""

#define FALSE 0
#define TRUE 1

#define HOST_BITS_PER_CHAR 8
#define HOST_BITS_PER_SHORT 16
#define HOST_BITS_PER_INT 32
#define HOST_BITS_PER_LONG 32
#define HOST_BITS_PER_LONGLONG 64

#define SUCCESS_EXIT_CODE 0
#define FATAL_EXIT_CODE 33

#define TARGET_BELL 007
#define TARGET_BS 010
#define TARGET_TAB 011
#define TARGET_NEWLINE 012
#define TARGET_VT 013
#define TARGET_FF 014
#define TARGET_CR 015

#define BITS_PER_UNIT 8
#define BITS_PER_WORD 32
#define UNITS_PER_WORD 4
#define POINTER_SIZE 32

#define SIZE_TYPE "unsigned int"

#ifdef __hpux
#include <alloca.h>
#endif
