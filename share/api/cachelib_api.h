/**
*** Copyright (C) 2001 Hewlett-Packard Company.
**/

/**
*** Headers for the API  that the VEX simulator expects when
*** running VEX code. The functions can be overridden 
*** by linking a natively compiled library that redefines them.
**/

#ifndef CACHELIB_API_INCLUDED
#define CACHELIB_API_INCLUDED

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#undef  __P
#ifdef __STDC__
# define __P(args) args /* ANSI */
#else
# define __P(args) () /* K+R */
#endif


/****************************************************************************
** Functions (can be overloaded)
****************************************************************************/

/* Initialization and Finalization */
/**
*** These two functions are called at the beginning and end of the simulation
*** They have to be designed so that they can be called multiple times 
*** without harm. Also, these functions must initialize a variable that 
*** indicates that the API is active. Until sim_ta_init() is called, all
*** other API functions must simply return, since the _linux_<function> 
*** interface may not have been yet initialized.
**/

extern int sim_ta_init __P((int enable));
extern int sim_ta_finish __P((void));


/* Data Tracing (normal, streaming, local) */
/**
*** These functions are called at every data memory operation (load, store,
*** or prefetch, of the appropriate category). They return the address 
*** that the simulation uses to perform the memory access.
**/

extern int mem_trace_ld __P((unsigned int address, int cluster, int size));
extern int mem_trace_st __P((unsigned int address, int cluster, int size));
extern int mem_trace_pf __P((unsigned int address, int cluster, int size));

extern int mem_trace_lds __P((unsigned int address, int cluster, int size));
extern int mem_trace_sts __P((unsigned int address, int cluster, int size));
extern int mem_trace_pfs __P((unsigned int address, int cluster, int size));

extern int mem_trace_ldl __P((unsigned int address, int cluster, int size));
extern int mem_trace_stl __P((unsigned int address, int cluster, int size));
extern int mem_trace_pfl __P((unsigned int address, int cluster, int size));


/* Instruction Tracing */
/**
*** The sim_icache_fetch function is called every time the simulator thinks 
*** that we have to load a new block of instructions from a given address 
*** and length. The sim_init_fileinfo function is called the first time a new 
*** compilation unit (ie, ".o" file) is "loaded" into the simulation.
***
*** The address is determined by a simulated dynamic loading process, 
*** where object file offsets are assigned sequentially the first time we
*** access an object within the compilation unit
**/

/**
*** Properties of a compilation unit
**/
typedef struct { 
    char *name; 	/* Name */
    int length; 	/* Length (operations) */
    int init;   	/* Init flag */
    int offset;		/* Dynamically assigned offset */
    int linesize;	/* Icache line size */
    int rta;            /* ABI identifier */
} fileinfo_t;

extern void sim_icache_fetch(int address, int length);
extern void sim_init_fileinfo(fileinfo_t *p);

/* Time Functions */

extern double __tCK __P((void));	 /* Returns the core ck in MHz */
extern double __cstime __P((void));	 /* Returns the elapsed time in usec */


/****************************************************************************
** Utility functions
****************************************************************************/
/**
*** These functions are the only allowed library functions to be called 
*** within the cache library. Calling normal library functions is not allowed.
*** The usage of these functions is the same of the equivalent libc functions
*** without the "_linux_" prefix
**/

extern FILE* _linux_fopen __P((const char *, const char *));
extern int _linux_fclose __P((FILE *));
extern int _linux_fflush __P((FILE *));
extern int _linux_fprintf __P((FILE *, const char *, ...));
extern int _linux_fscanf __P((FILE *, const char *, ...));
extern int _linux_sprintf __P((char *, const char *, ...));
extern int _linux_sscanf __P((char *, const char *, ...));

extern char * _linux_getenv __P((const char *));
extern char * _linux_strncpy __P((char *, const char *, size_t));
extern int  _linux_strncmp __P((const char *, const char *, size_t));
extern void * _linux_memcpy __P((void *, const void *, size_t));
extern void * _linux_memset __P((void *, int, size_t));

extern int _linux_sbrk __P((const void *));


/****************************************************************************
** Variables (can be read or updated)
****************************************************************************/

/* Cycles and Stalls */
extern unsigned long long sim_cycle_counter; 	/* Variable for the cycle counter */
extern unsigned long long sim_stall_counter; 	/* Variable for the stall counter */

/* Statistics */
extern unsigned long long sim_bundle_index[];	/* ILP histogram counters */
extern unsigned long long sim_oper_counter;		/* Operation counter */
extern unsigned long long sim_bnt_counter;		/* Not-taken conditional branch counter */
extern unsigned long long sim_btc_counter;		/* Taken conditional branch counter */
extern unsigned long long sim_btu_counter;		/* Taken unconditional branch counter */
extern unsigned long long sim_nop_counter;		/* Nop counter */


#ifdef __cplusplus
}
#endif

#endif /* CACHELIB_API_INCLUDED */
