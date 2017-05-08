/*
** Copyright (C) 1997-2007 Hewlett-Packard Company.
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

#include <sys/types.h>
#include <sys/file.h>
#include <sys/uio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

#include "cs_header.h"
#include "cs_vex.h"
#include "gprof_vex.h"
#include "gmon.h"
#include "gmon_out.h"

/* Imported */


extern int _init, _etext; 
#define TEXT_START (& _init)
#define TEXT_END   (& _etext)
#define MCOUNT mcount

#ifndef HOST_CLK_TCK
#if defined(CLK_TCK)
#define HOST_CLK_TCK CLK_TCK
#elif defined(CLOCKS_PER_SEC)
#define HOST_CLK_TCK CLOCKS_PER_SEC
#endif
#endif
#define TFACTOR (1)

/* Public */

struct __bb *__bb_head;         /*  Head of basic-block list or NULL. */
struct gmonparam _gmonparam = {GMON_PROF_OFF};
int sim_gprof_active = 0;

/* Private */

static double *sim_gprof_funct_tacount = 0;
static double *sim_gprof_funct_cscount = 0;
static double *sim_gprof_funct_dcache_count = 0;
static double *sim_gprof_funct_icache_count = 0;
static int *sim_gprof_funct_pc = 0;
static int *sim_gprof_glob_pc_stack = 0;
static int sim_gprof_funct_number = 0;
static char **sim_gprof_funct_names = 0;
static double sim_gprof_last_cstime = 0.0;
static double sim_gprof_last_tatime = 0.0;
static double sim_gprof_last_dcache_time = 0.0;
static double sim_gprof_last_icache_time = 0.0;
static int sim_gprof_glob_pc_stack_p = 0;
static int sim_gprof_glob_pc_stack_size = 0;
static int sim_gprof_count_size = 0;
static int sim_gprof_glob_pc = 0;
static int s_scale;

/* Forward Decl */

static void monstartup(u_long lowpc, u_long highpc);
static void _mcleanup(char *, double *,double);
static void moncontrol(int mode);
static void write_hist(int, double);
static void write_call_graph(int fd);
static void write_bb_counts(int fd);

/* Macros */

#define SCALE_1_TO_1            0x10000L
#define GPROF_MAX_FUNCTIONS     4096
#define GPROF_MAX_STACKSIZE     4096

#define PCTOINDEX(frompc,lowpc,scale,idx) {                             \
		  unsigned long long __idx_ull = 								\
		      ((unsigned)(frompc) - (unsigned)(lowpc)) / 2 ;            \
		  __idx_ull = (__idx_ull * (unsigned)(scale))/65536ULL;			\
		  idx = __idx_ull;												\
}

#define PCT(a,b) ((a)*100.0/(b))

/* Exported Functions */

extern void sim_gprof_enter(int *index, char *fname)
{
    int i;

    if (*index == 0) {
        if (sim_gprof_funct_number >= sim_gprof_count_size) {
            double *p;
            char **f;
            int *pi;

            p = (double *) sim_calloc((sim_gprof_count_size +
                       GPROF_MAX_FUNCTIONS) * sizeof(double), sizeof(double));
            _memcpy(p, sim_gprof_funct_tacount, sim_gprof_count_size * sizeof(double));
            sim_gprof_funct_tacount = p;

            p = (double *) sim_calloc((sim_gprof_count_size +
                       GPROF_MAX_FUNCTIONS) * sizeof(double), sizeof(double));
            _memcpy(p, sim_gprof_funct_cscount, sim_gprof_count_size * sizeof(double));
            sim_gprof_funct_cscount = p;

            p = (double *) sim_calloc((sim_gprof_count_size +
                       GPROF_MAX_FUNCTIONS) * sizeof(double), sizeof(double));
            _memcpy(p, sim_gprof_funct_dcache_count, sim_gprof_count_size * sizeof(double));
            sim_gprof_funct_dcache_count = p;

            p = (double *) sim_calloc((sim_gprof_count_size +
                       GPROF_MAX_FUNCTIONS) * sizeof(double), sizeof(double));
            _memcpy(p, sim_gprof_funct_icache_count, sim_gprof_count_size * sizeof(double));
            sim_gprof_funct_icache_count = p;

            pi = (int *) sim_calloc((sim_gprof_count_size +
                             GPROF_MAX_FUNCTIONS) * sizeof(int), sizeof(int));
            _memcpy(pi, sim_gprof_funct_pc, sim_gprof_count_size * sizeof(int));
            sim_gprof_funct_pc = pi;

            f = (char **) sim_calloc((sim_gprof_count_size +
                       GPROF_MAX_FUNCTIONS) * sizeof(char *), sizeof(char *));
            _memcpy(f, sim_gprof_funct_pc, sim_gprof_count_size * sizeof(char *));
            sim_gprof_funct_names = f;

            sim_gprof_count_size += GPROF_MAX_FUNCTIONS;
        }
        i = ++sim_gprof_funct_number;
        sim_gprof_funct_tacount[i] = 0;
        sim_gprof_funct_cscount[i] = 0;
        sim_gprof_funct_dcache_count[i] = 0;
        sim_gprof_funct_icache_count[i] = 0;
        sim_gprof_funct_pc[i] = sim_gprof_glob_pc;
        sim_gprof_funct_names[i] = fname;
        *index = i;
    }
    sim_gprof_start(index);
    if (sim_gprof_glob_pc_stack_p >= sim_gprof_glob_pc_stack_size) {
        int *pi;
        pi = (int *) sim_calloc((sim_gprof_glob_pc_stack_size +
                             GPROF_MAX_STACKSIZE) * sizeof(int), sizeof(int));
        _memcpy(pi, sim_gprof_glob_pc_stack, sim_gprof_glob_pc_stack_size * sizeof(int));
        sim_gprof_glob_pc_stack = pi;
        sim_gprof_glob_pc_stack_size += GPROF_MAX_STACKSIZE;
    }
    sim_gprof_glob_pc_stack[sim_gprof_glob_pc_stack_p++] = sim_gprof_glob_pc;
}

extern void sim_gprof_start(int *index)
{
    sim_gprof_last_cstime = __cstime() * TFACTOR;
    sim_gprof_last_tatime = __tatime() * TFACTOR;
    sim_gprof_last_dcache_time = __tatime_d() * TFACTOR;
    sim_gprof_last_icache_time = __tatime_i() * TFACTOR;
}

extern void sim_gprof_stop(int *index)
{
    double newtime, newcstime, newdtime, newitime;
    newcstime = __cstime() * TFACTOR;
    newtime = __tatime() * TFACTOR;
    newdtime = __tatime_d() * TFACTOR;
    newitime = __tatime_i() * TFACTOR;
    sim_gprof_funct_tacount[*index] += (newtime - sim_gprof_last_tatime);
    sim_gprof_funct_cscount[*index] += (newcstime - sim_gprof_last_cstime);
    sim_gprof_funct_dcache_count[*index] += (newdtime - sim_gprof_last_dcache_time);
    sim_gprof_funct_icache_count[*index] += (newitime - sim_gprof_last_icache_time);
}

extern void sim_gprof_exit(int *index)
{
    sim_gprof_stop(index);
    sim_gprof_glob_pc_stack_p--;
}

extern void sim_gprof_mcleanup(gprof_mode mode, double granularity)
{
    double clk_tck = HOST_CLK_TCK * granularity;
    switch (mode) {
    case GPROF_DCACHE:
        _mcleanup("gmon-dcache.out", sim_gprof_funct_dcache_count,clk_tck);
        return;
    case GPROF_ICACHE:
        _mcleanup("gmon-icache.out", sim_gprof_funct_icache_count,clk_tck);
        return;
    case GPROF_NOCACHE:
        _mcleanup("gmon-nocache.out", sim_gprof_funct_cscount,clk_tck);
        return;
    case GPROF_TOTAL:
        _mcleanup("gmon.out", sim_gprof_funct_tacount,clk_tck);
        return;
    }
}

extern void sim_gprof_dump_flat(FILE * flog)
{
    unsigned int *sort_idx;
    int f, i;
    double tCK = 1.0 / __tCK();

    double ta_sum = __tatime() * TFACTOR;
    double cs_sum = __cstime() * TFACTOR;
    double d_sum = __tatime_d() * TFACTOR;
    double i_sum = __tatime_i() * TFACTOR;

    sort_idx = (unsigned int *) sim_calloc((1 + sim_gprof_funct_number) * sizeof(int),
                                           sizeof(int));

    for (f = 0; f <= sim_gprof_funct_number; f++)
        sort_idx[f] = f;

    for (f = 1; f <= sim_gprof_funct_number; f++) {
        for (i = sim_gprof_funct_number; i >= f; i--) {
            if (sim_gprof_funct_tacount[sort_idx[i]] >
                sim_gprof_funct_tacount[sort_idx[i - 1]]) {
                unsigned int tmp = sort_idx[i];
                sort_idx[i] = sort_idx[i - 1];
                sort_idx[i - 1] = tmp;
            }
        }
    }

    double ta0 = ta_sum * tCK;
    double cs0 = cs_sum * tCK;
    double d0 = d_sum * tCK;
    double i0 = i_sum * tCK;

    _fprintf(flog, "%12s %8s %12s %8s %12s %8s %12s %8s %s\n", 
        "Total", "Total%",
        "Insts", "Insts%",
        "Dcache", "Dcache%",
        "Icache", "Icache%",
        "Function");

    for (f = 0; f < sim_gprof_funct_number; f++) {
        int ix = sort_idx[f];
        double tt = tCK * sim_gprof_funct_tacount[ix];
        double tc = tCK * sim_gprof_funct_cscount[ix];
        double td = tCK * (sim_gprof_funct_dcache_count[ix] - sim_gprof_funct_cscount[ix]);
        double ti = tCK * (sim_gprof_funct_icache_count[ix] - sim_gprof_funct_cscount[ix]);

        _fprintf(flog, "%12.0lf %8.2lf %12.0lf %8.2lf %12.0lf %8.2lf %12.0lf %8.2lf %s\n", 
            tt, PCT(tt,ta0), tc, PCT(tc,cs0), td, PCT(td,d0), ti, PCT(ti,i0), sim_gprof_funct_names[ix]);

        ta_sum -= sim_gprof_funct_tacount[sort_idx[f]];
        cs_sum -= sim_gprof_funct_cscount[sort_idx[f]];
        d_sum -= sim_gprof_funct_dcache_count[sort_idx[f]];
        i_sum -= sim_gprof_funct_icache_count[sort_idx[f]];
    }

    _fprintf(flog, "%12.0lf  %12.0lf  %12.0lf  %s\n",
             ta_sum * tCK,
             (d_sum - cs_sum) * tCK,
             (i_sum - cs_sum) * tCK,
             "(others not profiled)");
}

/* Private Functions */

/**
*** Control profiling
***      profiling is what mcount() checks to see if
***      all the data structures are ready.
**/
static void moncontrol(int mode)
{
    struct gmonparam *p = &_gmonparam;

    if (mode) {
        /* start */
        /*profil((void *) p->kcount, p->kcountsize, p->lowpc, s_scale); */
        p->state = GMON_PROF_ON;
    }
    else {
        /* stop */
        /*profil((void *) 0, 0, 0, 0); */
        p->state = GMON_PROF_OFF;
    }
}

static void monstartup(u_long lowpc, u_long highpc)
{
    int o;
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
        /* if HASHFRACTION is a power of two, mcount() can use shifting
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

    cp = (char *) sim_calloc(p->kcountsize + p->fromssize + p->tossize, sizeof(double));
    if (!cp) {
        _fprintf(stderr, "monstartup: out of memory\n");
        return;
    }
    /*bzero(cp, p->kcountsize + p->fromssize + p->tossize); */
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

static void write_hist(int fd, double clk_tck)
{
    u_char tag = GMON_TAG_TIME_HIST;
    struct gmon_hist_hdr thdr;
    char buff[256];

    if (_gmonparam.kcountsize > 0) {
        struct iovec iov[3];
        iov[0].iov_base = &tag;
        iov[0].iov_len = sizeof(tag);
        iov[1].iov_base = (char *) &thdr;
        iov[1].iov_len = sizeof(struct gmon_hist_hdr);
        iov[2].iov_base = (char *) _gmonparam.kcount;
        iov[2].iov_len = _gmonparam.kcountsize;

		{
		int sz = _gmonparam.kcountsize / sizeof(HISTCOUNTER);
		int rt = HOST_CLK_TCK;
		_memcpy(&thdr.low_pc[0],&_gmonparam.lowpc,sizeof(thdr.low_pc));
		_memcpy(&thdr.high_pc[0],&_gmonparam.highpc,sizeof(thdr.high_pc));
		_memcpy(&thdr.hist_size[0],&sz,sizeof(thdr.hist_size));
		_memcpy(&thdr.prof_rate[0],&rt,sizeof(thdr.prof_rate));
		}

        _sprintf(buff, "%1.0e sec", (double) HOST_CLK_TCK / clk_tck);
        _strncpy(thdr.dimen, buff, sizeof(thdr.dimen));
        thdr.dimen_abbrev = 's';

        _writev(fd, iov, 3);
    }
}

static void write_call_graph(int fd)
{
    static u_char tag = GMON_TAG_CG_ARC;
    static struct gmon_cg_arc_record raw_arc[4];
    int from_index, to_index, from_len;
    u_long frompc;

    struct iovec iov[8];
    int nfilled = 0;

    iov[0].iov_base = &tag;
    iov[0].iov_len = sizeof(tag);
    iov[1].iov_base = (char *) &raw_arc[0];
    iov[1].iov_len = sizeof(struct gmon_cg_arc_record);
    iov[2].iov_base = &tag;
    iov[2].iov_len = sizeof(tag);
    iov[3].iov_base = (char *) &raw_arc[1];
    iov[3].iov_len = sizeof(struct gmon_cg_arc_record);
    iov[4].iov_base = &tag;
    iov[4].iov_len = sizeof(tag);
    iov[5].iov_base = (char *) &raw_arc[2];
    iov[5].iov_len = sizeof(struct gmon_cg_arc_record);
    iov[6].iov_base = &tag;
    iov[6].iov_len = sizeof(tag);
    iov[7].iov_base = (char *) &raw_arc[3];
    iov[7].iov_len = sizeof(struct gmon_cg_arc_record);

    from_len = _gmonparam.fromssize / sizeof(*_gmonparam.froms);
    for (from_index = 0; from_index < from_len; ++from_index) {
        if (_gmonparam.froms[from_index] == 0)
            continue;

        frompc = _gmonparam.lowpc;
        frompc += (from_index * _gmonparam.hashfraction
                   * sizeof(*_gmonparam.froms));
        for (to_index = _gmonparam.froms[from_index];
             to_index != 0;
             to_index = _gmonparam.tos[to_index].link
		) {
            if (nfilled > 3) {
                _writev(fd, iov, 2 * nfilled);
                nfilled = 0;
            }
            _memcpy(&raw_arc[nfilled].from_pc[0], &frompc, sizeof(char*));
            _memcpy(&raw_arc[nfilled].self_pc[0], &_gmonparam.tos[to_index].selfpc, sizeof(char*));
			_memcpy(&raw_arc[nfilled].count[0], &_gmonparam.tos[to_index].count, 4);
            ++nfilled;
        }
    }
    _writev(fd, iov, 2 * nfilled);
}

static void write_bb_counts(int fd)
{
    struct __bb *grp;
    u_char tag = GMON_TAG_BB_COUNT;
    int ncounts;
    int i;

    struct iovec bbhead[2] =
    {
        {&tag, sizeof(tag)},
        {&ncounts, sizeof(ncounts)}
    };
    struct iovec bbbody[8];
    int nfilled;

    for (i = 0; i < (sizeof(bbbody) / sizeof(bbbody[0])); i += 2) {
        bbbody[i].iov_len = sizeof(grp->addresses[0]);
        bbbody[i + 1].iov_len = sizeof(grp->counts[0]);
    }

    /* Write each group of basic-block info (all basic-blocks in a
     * compilation unit form a single group). */

    nfilled = 0;
    for (grp = __bb_head; grp; grp = grp->next) {
        ncounts = grp->ncounts;
        _writev(fd, bbhead, 2);
        for (i = 0; i < ncounts; ++i) {
            if (nfilled > (sizeof(bbbody) / sizeof(bbbody[0])) - 2) {
                _writev(fd, bbbody, nfilled);
                nfilled = 0;
            }

            bbbody[nfilled++].iov_base = (char *) &grp->addresses[i];
            bbbody[nfilled++].iov_base = (char *) &grp->counts[i];
        }
    }
    _writev(fd, bbbody, nfilled);
}

static void _mcleanup(char *gmon_name, double *counts, double clk_tck)
{
    struct gmon_hdr ghdr;
    int fd;
    struct gmonparam *p = &_gmonparam;
    int f, s_lowpc = p->lowpc;
    unsigned short *sbuf = p->kcount;
    unsigned int ssiz = p->kcountsize;

    /* convert internal Lx cycle counts to gprof clock ticks */

    if (clk_tck < 1.0) {
        double max_count = 0.0;
        for (f = 0; f <= sim_gprof_funct_number; f++)
            max_count = (max_count < counts[f] ? counts[f] : max_count);
        /* clk_tck = (double)(1 << 16) / max_count; */
        /* automaticly determine the clk_tck granularity between 1e2 1e+7 
         * as a power of 10 (1 to 1e-9 sec of granularity)
         * that allows for up to 65536 seconds of accumulated time per function 
         * or down to 65536*1e-9 =.000065536 sec per function
         */
        clk_tck = 128;
		while (clk_tck < 1e9) {
            clk_tck *= 2.0;
            if (clk_tck > (65536.0 / max_count))
                break;
        }
        clk_tck /= 2.0;
#ifdef DEBUG
        _fprintf(stderr, "cleanup %s: clk_tck = %g max_count=%g, max=%g\n", 
		    gmon_name, clk_tck, max_count, (double)(1 << 16) / max_count);
#endif
    }
    for (f = 0; f <= sim_gprof_funct_number; f++) {
	    double cntf = counts[f];
        size_t idx;
        PCTOINDEX(sim_gprof_funct_pc[f], s_lowpc, s_scale, idx);
#ifdef DEBUG2
        _fprintf(stderr,"[sim_gprof_mcleanup] pc=%x\n", sim_gprof_funct_pc[f]);
#endif
        if (idx < ssiz) {
            sbuf[idx] = (unsigned short) (cntf * clk_tck + 0.5);
#ifdef DEBUG
            _fprintf(stderr,"[sim_gprof_mcleanup] pc=%x idx=%d n=%f \n", 
			    sim_gprof_funct_pc[f],idx,cntf*clk_tck);
#endif
		}
        else {
            if (sim_gprof_funct_pc[f] > 0)
                _fprintf(stderr, "ERROR[gprof_vex]: index out of range pc=%d lowpc=%d highpc=%d idx=%d\n",
                         sim_gprof_funct_pc[f], s_lowpc, p->highpc, idx);
        }
        if ((cntf * clk_tck) > (double)(1 << 16)) {
            _fprintf(stderr, "Warning: profile overflow occurred, decrease ProfGranularity in vex.cfg");
            _fprintf(stderr, "[f=%u, counts=%f, clk_tck=%f]\n",f,cntf,clk_tck);
        }
    }

    moncontrol(0);
    fd = _open(gmon_name, O_CREAT | O_TRUNC | O_WRONLY ,0666);
    if (fd < 0) {
        _fprintf(stderr, "_mcleanup: can't open file %s for writing", gmon_name);
        return;
    }

    /* write gmon.out header: */
	{
	int gmon_version = GMON_VERSION;
    _memset(&ghdr, 0, sizeof(struct gmon_hdr));
    _memcpy(&ghdr.cookie[0], GMON_MAGIC, sizeof(ghdr.cookie));
    _memcpy(&ghdr.version[0],&gmon_version, sizeof(ghdr.version));
    _write(fd, (void*)&ghdr, sizeof(struct gmon_hdr));
	}

    /* write PC histogram: */
    write_hist(fd,clk_tck);

    /* write call-graph: */
    write_call_graph(fd);

    /* write basic-block execution counts: */
    write_bb_counts(fd);

    _close(fd);

    /* free the memory. */
    /*free (_gmonparam.tos); */
}

extern void MCOUNT(unsigned char *_frompc, char *_selfpc, long **cntp)
{
    u_short *frompcindex;
    struct tostruct *top, *prevtop;
    struct gmonparam *p;
    long toindex;
    int i;
    char *selfpc;
    unsigned char *frompc;

    selfpc = __builtin_return_address(0);
    frompc = __builtin_return_address(1);
    if (!sim_gprof_active) {
        sim_gprof_active = 1;
        monstartup((u_long) TEXT_START, (u_long) TEXT_END);
    }
    p = &_gmonparam;
    /*
     * check that we are profiling
     * and that we aren't recursively invoked.
     */
    if (p->state != GMON_PROF_ON)
        return;
    p->state = GMON_PROF_BUSY;
    /*
     * check that frompcindex is a reasonable pc value.
     * for example: signal catchers get called from the stack,
     *              not from text space.  too bad.
     */

    /* 
     * since we are not using the standard gprof pc sampling technique for lx
     * we have to trick gprof into believing that all functions called within the same parent
     * come from the same frompc, to do this we use a stack of pcs and we
     * replace frompc with the recorded one at any given depth in the call stack
     */

    if (sim_gprof_glob_pc_stack_p)
        frompc = (unsigned char *) sim_gprof_glob_pc_stack[sim_gprof_glob_pc_stack_p - 1];

    /* make sure we are inside the calling fraction with the selfpc when it will be sampled
     * later for Lx only we align the selfpc with the next HISTFRACTION boundary within the 
     * function
     */

    selfpc = (char *) (((int) selfpc + (HISTFRACTION - 1)) & ~(HISTFRACTION - 1));

    /* 
     * we record the last selfpc for sim_gprof_enter to associate it to a function
     * name and dense index
     * this solution is portable across different implementations of mcount() calls
     * in different platform
     */
    sim_gprof_glob_pc = (int) selfpc;
#ifdef DEBUG2
    _fprintf(stderr,"[mcount] frompc=%x\tselfpc=%x\n", frompc, selfpc);
#endif
    frompc -= p->lowpc;
    if ((u_long) frompc > p->textsize)
        goto done;

    /* avoid integer divide if possible: */
    if (p->log_hashfraction >= 0) {
        i = (u_long) frompc >> p->log_hashfraction;
    }
    else {
        i = (u_long) frompc / (p->hashfraction * sizeof(*p->froms));
    }
    frompcindex = &p->froms[i];
    toindex = *frompcindex;
    if (toindex == 0) {
        /*
         *    first time traversing this arc
         */
        toindex = ++p->tos[0].link;
        if (toindex >= p->tolimit)
            /* halt further profiling */
            goto overflow;

        *frompcindex = toindex;
        top = &p->tos[toindex];
        top->selfpc = (u_long) selfpc;
        top->count = 1;
        top->link = 0;
        goto done;
    }
    top = &p->tos[toindex];
    if (top->selfpc == (u_long) selfpc) {
        /*
         * arc at front of chain; usual case.
         */
        top->count++;
        goto done;
    }
    /*
     * have to go looking down chain for it.
     * top points to what we are looking at,
     * prevtop points to previous top.
     * we know it is not at the head of the chain.
     */
    for (; /* goto done */ ;) {
        if (top->link == 0) {
            /*
             * top is end of the chain and none of the chain
             * had top->selfpc == selfpc.
             * so we allocate a new tostruct
             * and link it to the head of the chain.
             */
            toindex = ++p->tos[0].link;
            if (toindex >= p->tolimit)
                goto overflow;

            top = &p->tos[toindex];
            top->selfpc = (u_long) selfpc;
            top->count = 1;
            top->link = *frompcindex;
            *frompcindex = toindex;
            goto done;
        }
        /*
         * otherwise, check the next arc on the chain.
         */
        prevtop = top;
        top = &p->tos[top->link];
        if (top->selfpc == (u_long) selfpc) {
            /*
             * there it is.
             * increment its count
             * move it to the head of the chain.
             */
            top->count++;
            toindex = prevtop->link;
            prevtop->link = top->link;
            top->link = *frompcindex;
            *frompcindex = toindex;
            goto done;
        }

    }
  done:
    p->state = GMON_PROF_ON;
    return;
  overflow:
    p->state = GMON_PROF_ERROR;
    return;
}
