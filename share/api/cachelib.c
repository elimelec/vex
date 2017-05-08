/**
*** Copyright (C) 2001-2002 Hewlett-Packard Company.
**/

/**
*** This file shows how to create a simple API to  keep track 
*** of load and stores in VEX simulation. For example, it can 
*** be used to plug-in a standalone simulator of the memory 
*** hierarchy
**/

/**
*** Note 1: we can't call system libraries. We can only use the 
*** ones that are explicitly redefined in the API header.
*** Calling a system library will cause the VEX-compiled function
*** to be called, most likely with unpredictable results.
**/

/**
*** Note 2: it's better not to export any symbol except the ones
*** that can be redefined, as described in the API header.
*** Defining other extern functions increases name space pollution
*** and the probability to conflict with names in the simulated code
**/

/* $Id: cachelib.c,v 1.7 2006/07/14 10:41:06 frb Exp $ */

#include <stdio.h>
#include "cachelib_api.h"

static int nld = 0;
static int nst = 0;

static FILE *ftrace = NULL;

static int api_active = 0;
static fileinfo_t *cur_fileinfo = NULL;

/**
***     Initialization routine
*** (could be called multiple times)
**/
extern int sim_ta_init(int status)
{
    static int done_once = 0;
    int start = 0;
    switch (status) {
        case 0:
	    /* Turn accounting off */
	    api_active = 0;
            break;

        case 1:
	    /* Turn accounting on */
	    if (!done_once)
	        start = 1;
            break;
    }

    if (start) {
        ftrace = _linux_fopen("trace.txt","w");
        _linux_fprintf(ftrace, "+++++ Here we go...(%d)\n", status);
        nld = nst = 0;
        done_once = 1;
	api_active = 1; /* Must do this at the very end! */
    }
}

/**
***     Finalization routine
*** (could be called multiple times)
**/
extern int sim_ta_finish(void)
{
    static int done_once = 0;
    if (done_once) 
	return;
    done_once = 1;

    if (api_active) {
        _linux_fprintf(ftrace, "+++++ nld = %d\n",nld);
        _linux_fprintf(ftrace, "+++++ nst = %d\n",nst);
        _linux_fprintf(ftrace, "+++++ Done...\n");
        _linux_fclose(ftrace);
    }
    api_active = 0;
}

/**
***     Memory Tracing Callbacks
**/
extern int mem_trace_ld(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ LOAD%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    ++nld;
    return address;
}

extern int mem_trace_st(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ STORE%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    ++nst;
    return address;
}

extern int mem_trace_pf(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ PREFETCH%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    return address;
}

extern int mem_trace_lds(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ STREAM LOAD%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    return address;
}

extern int mem_trace_sts(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ STREAM STORE%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    return address;
}

extern int mem_trace_pfs(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ STREAM PREFETCH%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    return address;
}

extern int mem_trace_ldl(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ LOCAL LOAD%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    return address;
}

extern int mem_trace_stl(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ LOCAL STORE%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    return address;
}

extern int mem_trace_pfl(unsigned int address, int cluster, int size)
{
    if (!api_active) 
        return address;
    _linux_fprintf(ftrace, "+++++ LOCAL PREFETCH%d %x (t=%llu)\n", 
        size, address, sim_cycle_counter);
    return address;
}

extern void sim_icache_fetch(int address, int length)
{
    char *fname = "?"; 
    if (!api_active) 
        return;
    if (cur_fileinfo)
	fname = cur_fileinfo->name;
    _linux_fprintf(ftrace, "+++++ INSTRUCTION obj %s, addr %d (%dw, t=%llu)\n", 
        fname, address, length, sim_cycle_counter);
}

extern void sim_ta_mark(int id)
{
    if (!api_active) 
        return;
    _linux_fprintf(ftrace, "+++++ MARK %d (t=%llu)\n", id, sim_cycle_counter);
}

/**
***  FILEINFO
***  The sim_init_fileinfo() function is called every time CS enters a function.
***  Its main purpose is to assign (dynamically) initial addresses to the instructions
***  of each compilation unit. This mimics a "dynamic loading" mechanism where object
***  files are loaded into memory as the functions in them are executed.
***  The sample code below shows the simplest form of assignment (things are loaded 
***  sequentially).
**/

extern void sim_init_fileinfo(fileinfo_t *p)
{
    static int last_offset = 0;
    if (p && !p->init) {
	int length = p->length;
	p->offset = last_offset;
	last_offset += length;
	p->init = 1;
    }
    cur_fileinfo = p;
}

