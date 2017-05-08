/* 
 * Low-level statistical profiling support function.  Mostly POSIX.1 version.
 * Copyright (C) 1996 Free Software Foundation, Inc.
 * This file is part of the GNU C Library.
 * 
 * The GNU C Library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 * 
 * The GNU C Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 * 
 * You should have received a copy of the GNU Library General Public
 * License along with the GNU C Library; see the file COPYING.LIB.  If
 * not, write to the Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.  
 */

/**
*** static char sccs_id[] = "$Id: profil.c,v 1.1.1.1 2001/11/21 20:34:38 frb Exp $ ";
**/

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>
#include <machine/ptregs.h>

static u_short *samples = NULL;
static size_t nsamples;
static size_t pc_offset;
static u_int pc_scale;

static void profil_count(int signr, struct sigcontext_struct *sc)
{
    int *pc = (int*) sc->regs->pc;
    size_t i = (pc - pc_offset - ((int *) 0)) / 2;

    if (sizeof(unsigned long int) > sizeof(size_t))
        i = (unsigned long int) i *pc_scale / 65536;
    else
	i = i / 65536 * pc_scale + i % 65536 * pc_scale / 65536;

    if (i < nsamples)
	++samples[i];
}

/* 
 * Enable statistical profiling, writing samples of the PC into at most
 * SIZE bytes of SAMPLE_BUFFER; every processor clock tick while profiling
 * is enabled, the system examines the user PC and increments
 * SAMPLE_BUFFER[((PC - OFFSET) / 2) * SCALE / 65536].  If SCALE is zero,
 * disable profiling.  Returns zero on success, -1 on error.  
 */

extern int profil(u_short* sample_buffer, size_t size, size_t offset, u_int scale)
{
    static struct sigaction act, oact;
    static struct itimerval timer, otimer;

    if (sample_buffer == NULL) {
	/* Disable profiling.  */
	if (samples == NULL)
	    /* Wasn't turned on.  */
	    return 0;

	if (setitimer(ITIMER_PROF, &otimer, NULL) < 0)
	    return -1;
	samples = NULL;
	return sigaction(SIGPROF, &oact, NULL);
    }

    if (samples) {
	/* Was already turned on.  Restore old timer and handler first. */
	if (   setitimer(ITIMER_PROF, &otimer, NULL) < 0
	    || sigaction(SIGPROF, &oact, NULL) < 0)
	    return -1;
    }

    samples = sample_buffer;
    nsamples = size / sizeof *samples;
    pc_offset = offset;
    pc_scale = scale;

    act.sa_handler = (void (*)(int)) profil_count;
    act.sa_flags = 0; /* SA_RESTART */
    sigfillset(&act.sa_mask);
    if (sigaction(SIGPROF, &act, &oact) < 0)
	return -1;

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 1;
    timer.it_interval = timer.it_value;
    return setitimer(ITIMER_PROF, &timer, &otimer);
}

extern int __profile_frequency (void)
{
    return 1000000; /* Per second */
}
