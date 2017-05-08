/*-
 * Copyright (c) 1983, 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
*** static char sccs_id[] = "$Id: gmon.c,v 1.1.1.1 2001/11/21 20:34:38 frb Exp $ ";
**/

#include <sys/param.h>
#include <sys/time.h>
#include <gmon.h>
#include <gmon_out.h>
#include <sys/uio.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#if 0
#define PDEBUG(s) write(1,s,strlen(s))
#else
#define PDEBUG(s)
#endif

#define IOV_INIT(iovp,base,len) \
 ((iovp)->iov_base = (_PTR)(base), (iovp)->iov_len = (len), (iovp)++)

extern int __profile_frequency(void);

struct gmonparam _gmonparam =
{GMON_PROF_OFF};

/*
 * See profil(2) where this is described:
 */
static int s_scale;
#define		SCALE_1_TO_1	0x10000L

#define ERR(s) write(2, s, sizeof(s) - 1)

void moncontrol(int mode);
static void write_hist(int fd);
static void write_call_graph(int fd);

/*
 * Control profiling
 *      profiling is what mcount checks to see if
 *      all the data structures are ready.
 */
void moncontrol(int mode)
{
    struct gmonparam *p = &_gmonparam;

    if (mode) {
	/* start */
	profil((void *) p->kcount, p->kcountsize, p->lowpc, s_scale);
	p->state = GMON_PROF_ON;
    }
    else {
	/* stop */
	profil((void *) 0, 0, 0, 0);
	p->state = GMON_PROF_OFF;
    }
}

void monstartup(u_long lowpc, u_long highpc)
{
    register int o;
    char *cp;
    struct gmonparam *p = &_gmonparam;

    /*
     * round lowpc and highpc to multiples of the density we're using
     * so the rest of the scaling (here and in gprof) stays in ints.
     */
    p->lowpc = ROUNDDOWN(lowpc, HISTFRACTION * sizeof(HISTCOUNTER));
    p->highpc = ROUNDUP(highpc, HISTFRACTION * sizeof(HISTCOUNTER));
    p->textsize = p->highpc - p->lowpc;
    p->kcountsize = p->textsize / HISTFRACTION;
    p->hashfraction = HASHFRACTION;
    p->log_hashfraction = -1;
    if ((HASHFRACTION & (HASHFRACTION - 1)) == 0) {
	/* if HASHFRACTION is a power of two, mcount can use shifting
	 * instead of integer division.  Precompute shift amount. */
	p->log_hashfraction = ffs(p->hashfraction * sizeof(*p->froms)) - 1;
    }
    p->fromssize = p->textsize / HASHFRACTION;
    p->tolimit = p->textsize * ARCDENSITY / 100;
    if (p->tolimit < MINARCS)
	p->tolimit = MINARCS;
    else if (p->tolimit > MAXARCS)
	p->tolimit = MAXARCS;
    p->tossize = p->tolimit * sizeof(struct tostruct);

    cp = malloc(p->kcountsize + p->fromssize + p->tossize);
    if (!cp) {
	ERR("monstartup: out of memory\n");
	return;
    }
    bzero(cp, p->kcountsize + p->fromssize + p->tossize);
    p->tos = (struct tostruct *) cp;
    cp += p->tossize;
    p->kcount = (u_short *) cp;
    cp += p->kcountsize;
    p->froms = (u_short *) cp;

    p->tos[0].link = 0;

    o = p->highpc - p->lowpc;
    if (p->kcountsize < (u_long) o) {
	/* avoid floating point operations */
	int quot = o / p->kcountsize;

	if (quot >= 0x10000)
	    s_scale = 1;
	else if (quot >= 0x100)
	    s_scale = 0x10000 / quot;
	else if (o >= 0x800000)
	    s_scale = 0x1000000 / (o / (p->kcountsize >> 8));
	else
	    s_scale = 0x1000000 / ((o << 8) / p->kcountsize);
    }
    else
	s_scale = SCALE_1_TO_1;

    moncontrol(1);
}

static void write_hist(int fd)
{
    u_char tag = GMON_TAG_TIME_HIST;
    struct gmon_hist_hdr thdr;

    if (_gmonparam.kcountsize > 0) {
	struct iovec iov[3], *iovp = iov;
	IOV_INIT(iovp, &tag, sizeof(tag));
	IOV_INIT(iovp, &thdr, sizeof(struct gmon_hist_hdr));
	IOV_INIT(iovp, _gmonparam.kcount, _gmonparam.kcountsize);

	*(char **) thdr.low_pc = (char *) _gmonparam.lowpc;
	*(char **) thdr.high_pc = (char *) _gmonparam.highpc;
	*(int *) thdr.hist_size = _gmonparam.kcountsize / sizeof(HISTCOUNTER);
	*(int *) thdr.prof_rate = __profile_frequency();
	strncpy(thdr.dimen, "seconds", sizeof(thdr.dimen));
	thdr.dimen_abbrev = 's';

	__writev(fd, iov, 3);
    }
}

static void write_call_graph(int fd)
{
    u_char tag = GMON_TAG_CG_ARC;
    struct gmon_cg_arc_record raw_arc[4];
    int from_index, to_index, from_len;
    u_long frompc;
    int nfilled = 0;

    struct iovec iov[8], *iovp = iov;
    IOV_INIT(iovp, &tag, sizeof(tag));
    IOV_INIT(iovp, &raw_arc[0], sizeof(struct gmon_cg_arc_record));
    IOV_INIT(iovp, &tag, sizeof(tag));
    IOV_INIT(iovp, &raw_arc[1], sizeof(struct gmon_cg_arc_record));
    IOV_INIT(iovp, &tag, sizeof(tag));
    IOV_INIT(iovp, &raw_arc[2], sizeof(struct gmon_cg_arc_record));
    IOV_INIT(iovp, &tag, sizeof(tag));
    IOV_INIT(iovp, &raw_arc[3], sizeof(struct gmon_cg_arc_record));

    from_len = _gmonparam.fromssize / sizeof(*_gmonparam.froms);
    for (from_index = 0; from_index < from_len; ++from_index) {
	if (_gmonparam.froms[from_index] == 0)
	    continue;

	frompc = _gmonparam.lowpc;
	frompc += (from_index * _gmonparam.hashfraction
		   * sizeof(*_gmonparam.froms));
	for (to_index = _gmonparam.froms[from_index];
	     to_index != 0;
	     to_index = _gmonparam.tos[to_index].link) {
	    if (nfilled > 3) {
		__writev(fd, iov, 2 * nfilled);
		nfilled = 0;
	    }
	    *(char **) raw_arc[nfilled].from_pc = (char *) frompc;
	    *(char **) raw_arc[nfilled].self_pc =
		(char *) _gmonparam.tos[to_index].selfpc;
	    *(int *) raw_arc[nfilled].count = _gmonparam.tos[to_index].count;
	    ++nfilled;
	}
    }
    __writev(fd, iov, 2 * nfilled);
}

static int
open_unique(const char *s)
{
    char buf[256], *ps;
    int i0,i1,i2;
    strcpy(buf,s);
    ps = buf + strlen(buf);
    *ps = '.';
    *(ps+4) = 0;

    for (i2 = 0; i2 < 10; ++i2)
        for (i1 = 0; i1 < 10; ++i1)
           for (i0 = 0; i0 < 10; ++i0) {
	       int f;
	       *(ps+1) = '0' + i2;
	       *(ps+2) = '0' + i1;
	       *(ps+3) = '0' + i0;
	       f = open(buf, 
	                O_WRONLY | O_CREAT | O_EXCL | O_TRUNC,
		        S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	       if (f >= 0) {
	           return f;
	       }
           }
}

void _mcleanup()
{
    struct gmon_hdr ghdr;
    int fd;

    moncontrol(0);
#if 1
    fd = open_unique("gmon.out");
#else
    fd = _open("gmon.out", O_CREAT | O_TRUNC | O_WRONLY, 0666);
#endif
    if (fd < 0) {
	perror("_mcleanup: gmon.out");
	return;
    }

    /* write gmon.out header: */
    memset(&ghdr, 0, sizeof(struct gmon_hdr));
    memcpy(&ghdr.cookie[0], GMON_MAGIC, sizeof(ghdr.cookie));
    *(int *) ghdr.version = GMON_VERSION;
    _write(fd, &ghdr, sizeof(struct gmon_hdr));

    /* write PC histogram: */
    PDEBUG("write_hist\n");
    write_hist(fd);
    PDEBUG("done\n");

    /* write call-graph: */
    PDEBUG("write_call_graph\n");
    write_call_graph(fd);
    PDEBUG("done\n");

    _close(fd);

    /* free the memory. */
    free(_gmonparam.tos);
}
