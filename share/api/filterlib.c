/**
*** Copyright (C) 2004 Hewlett-Packard Company.
**/

/**
*** This file shows how to create a simple PC tracker, that
*** works together with an assembler filter to capture some 
*** events in CS simulation. In this case, we capture and print
*** PC "locations", and branches. 
***
*** See "as-filter" for the companion script, and the makefile
*** for the compiler invocation
**/

/* $Id: filterlib.c,v 1.1 2004/10/15 16:55:58 frb Exp $ */

#include <stdio.h>

extern void sim_icache_fetch(int, int);

static int filter_active = 0;
static FILE *tracefile = NULL;

static void init_filter()
{
    filter_active = 1;
    tracefile = (FILE*)_linux_fopen("filter.txt","w");
}

extern void sim_icache_fetch_filter(int pc, int len)
{
    if (!filter_active)
        init_filter();
    _linux_fprintf(tracefile, "PC = %d, len %d\n", pc, len);
    sim_icache_fetch(pc, len);
}

void sim_branch_filter(int type, char *s)
{
    if (!filter_active)
        init_filter();

    _linux_fprintf(tracefile, "\t\t");
    switch (type) {
        case 0: /* GOTO */
             _linux_fprintf(tracefile, "goto %s\n", s);
            break;
        case 1: /* BRANCH */
             _linux_fprintf(tracefile, "br %s\n", s);
            break;
        case 2: /* BRANCHF */
             _linux_fprintf(tracefile, "brf %s\n", s);
            break;
        case 3: /* CALL */
             _linux_fprintf(tracefile, "call %s\n", s);
            break;
        case 4: /* RETURN */
             _linux_fprintf(tracefile, "return %s\n", s);
            break;
        case 5: /* ENTRY */
             _linux_fprintf(tracefile, "entry %s\n", s);
            break;
        case 6: /* LABEL */
             _linux_fprintf(tracefile, "label %s\n", s);
            break;
        default:
            break;
    }
}
