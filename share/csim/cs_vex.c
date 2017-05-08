/*
** Copyright (C) 1994 - 2005 Hewlett-Packard Company.
**
*/

/*
** You can redistribute this file it and/or modify it under the terms 
** of the GNU Library General Public License as published by the Free 
** Software Foundation; either version 2 of the License, or (at your 
** option) any later version.
**
** You should have received a copy of the GNU Library General Public
** License along with the GNU C Library; see the file COPYING.LIB.  If not,
** write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
** Boston, MA 02111-1307, USA.
*/

/* $Id: cs_vex.c,v 1.4 2005/02/24 16:24:01 frb Exp $ */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <fcntl.h>

#include "cs_header.h"
#include "cs_vex.h"

#define ERROR(s) { char msg[]=s; _write(2,msg,sizeof(msg)); _exit(1); }

/*-----------------------------------------------------------------------------------*/
/* Public Variables */

unsigned long long sim_bundle_index[MAX_BUNDLE_SIZE];
unsigned long long sim_bnt_counter = 0;
unsigned long long sim_btc_counter = 0;
unsigned long long sim_btu_counter = 0;
unsigned long long sim_nop_counter = 0;

unsigned long long sim_cycle_counter = 0;
unsigned long long sim_stall_counter = 0;
unsigned long long sim_dcache_stall_counter = 0;
unsigned long long sim_icache_stall_counter = 0;

unsigned long long sim_branch_stall = 1;

/* Private */

typedef unsigned char t_env;

static unsigned int sim_stack_base = 0;
static unsigned int sim_stack_end;
static unsigned int sim_stack_size;

/*******************************************************/
/* 	Memory Allocation for simulation routines      */
/*******************************************************/

extern unsigned int sim_calloc(unsigned int size, unsigned int align)
{
    unsigned char *ptr1 = (unsigned char *) _sbrk(0);
    unsigned int size1 =
	size + ((((int) ptr1 + align - 1) & ~(align - 1)) - (int) ptr1);
    unsigned char *ptr = (unsigned char *) _sbrk(size1);
    unsigned int i;

    if (!ptr) {
	ERROR("***Run-time error: can't allocate memory");
    }

    ptr = (unsigned char *) (((int) ptr + align - 1) & ~(align - 1));

    for (i = 0; i < size; ++i)
	*(ptr + i) = 0;

    return (unsigned int) ptr;
}

/*******************************************************/
/* 	Speculative Memory Access Routines             */
/*******************************************************/

/*
** Require the host-dependent sim_mem_probe() function
*/

extern unsigned char sim_mem_access8(unsigned int a)
{
    if (sim_mem_probe(a))
	return *((volatile unsigned char *) a);
    return 0;
}

extern unsigned short sim_mem_access16(unsigned int a)
{
    if ((a & 1) == 0 && sim_mem_probe(a))
	return *((volatile unsigned short *) a);
    return 0;
}

extern unsigned int sim_mem_access32(unsigned int a)
{
    if ((a & 3) == 0 && sim_mem_probe(a))
	return *((volatile unsigned int *) a);
    return 0;
}

#define TEMP_STACK 16384
static void sim_create_temp_stack()
{
/**
*** Create a temp stack and assign it to the stack pointer.
*** It'd be nice to know the SP in a better way, but this is a hack 
*** anyway, so for the moment we punt.
**/
    static int temp_stack[TEMP_STACK];
    static int temp_stack_created = 0;
    if (!temp_stack_created) {
	unsigned stack_base = (unsigned) temp_stack + TEMP_STACK - 32;
	reg_r0_1 = stack_base;
	temp_stack_created = 1;	/* to avoid recursion, keep it here! */
	/* sim_ta_init(0); */
    }
}

/****************************************************************/
/*		stack management 				*/
/****************************************************************/

extern void sim_bad_label(int indicator)
{
#ifdef SYSTEM_HOOKS
    (void) kill(getpid(), SIGILL);
#endif
    ERROR("***Run-time error: bogus label indicator\n");
}

extern unsigned int sim_create_stack(unsigned int size, unsigned int stackptr)
{
    if (sim_stack_base != 0)
	return stackptr;

    sim_stack_base = sim_calloc(size, 32);
    sim_stack_end = sim_stack_base + size;
    sim_stack_size = size;

    return sim_stack_base + size - 32;
}

extern void sim_check_stack(unsigned int stackvalue, unsigned int framesize)
{
    if (sim_stack_base == 0) {
	/** 
	*** This means that we're calling a CS-compiled function
	*** before sim_create_stack(), i.e. before the CS main.
	*** It can happen if the system wants to use some libc function
	*** during loading or program initialization.
	*** In this case, we create a temp stack, cross our fingers
	*** and hope for the best...
	**/
	sim_create_temp_stack(framesize);
	return;
    }

    if (stackvalue < sim_stack_base ||
	stackvalue >= sim_stack_end ||
	stackvalue + framesize < sim_stack_base ||
	stackvalue + framesize >= sim_stack_end) {
#ifdef SYSTEM_HOOKS
	(void) kill(getpid(), SIGSEGV);
#else
	ERROR("***Run-time error: memory stack overflow/underflow\n");
#endif
    }
}

/****************************************************************/
/*		longjmp/setjmp support                    	*/
/****************************************************************/

static unsigned int *jmpbuf[] = {
    &reg_r0_1,			/* sp */
    &reg_l0_0,			/* rp */
    &reg_r0_57,			/* pre1 */
    &reg_r0_58,			/* pre2 */
    &reg_r0_59,			/* pre3 */
    &reg_r0_60,			/* pre4 */
    &reg_r0_61,			/* pre5 */
    &reg_r0_62,			/* pre6 */
    &reg_r0_63,			/* pre7 */
    0
};

extern void *sim_sys_setjmp_save(void *env)
{
    unsigned int *envp = (unsigned int *) env;
    unsigned int **regp = jmpbuf;
    while (*regp) {
	*envp++ = **regp++;
    }
#ifdef DEBUG
    _fprintf(stderr, "save to 0x%p (%d)\n", env, (int) envp - (int) env);
#endif
    /* align to a double to be safe */
    envp = (unsigned int *) (((unsigned int) envp + 0x7) & ~0x7);
    return ((void *) envp);
}

extern void *sim_sys_longjmp_restore(void *env)
{
    unsigned int *envp = (unsigned int *) env;
    unsigned int **regp = jmpbuf;
    while (*regp) {
	**regp++ = *envp++;
    }
#ifdef DEBUG
    _fprintf(stderr, "restore from 0x%p (%d)\n", env, (int) envp - (int) env);
#endif
    /* align to a double to be safe */
    envp = (unsigned int *) (((unsigned int) envp + 0x7) & ~0x7);
    return ((void *) envp);
}

