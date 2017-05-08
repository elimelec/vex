/**
*** Copyright (C) 1995-2003 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#include <stdlib.h>
#include <stdio.h>

#include "resize.h"

static short *rowBuf, *curRow, *nextRow, *dzBuf;
static int yPos;

#define COMPS 3


static void alloc_resize_memory(int npixels)
{
    int rowsize = npixels * 4 + 1;
    rowBuf = (short *) calloc(sizeof(short), 3 * rowsize);
    if (rowBuf == NULL) {
	fprintf(stderr, "Can't allocate resize buffers");
	exit(1);
    }
    curRow = rowBuf;
    nextRow = curRow + rowsize;
    dzBuf = nextRow + rowsize;
}

static void free_resize_memory(void)
{
    free((void *) rowBuf);
}

static void start_resize(const ubyte * ibuf, int in_width, int scale)
{
    int i, comp;
    const ubyte *ip = ibuf;
    short *pc = curRow;
    short *pn = nextRow;
    short *dzp = dzBuf;
    for (i = 0; i < in_width; ++i) {
	for (comp = 0; comp < COMPS; ++comp) {
	    pn[comp] = ip[comp] << 7;
	    pc[comp] = 0;
	    dzp[comp] = 0;
	}
	pn += 3;
	pc += 3;
	ip += 3;
	dzp += 3;
    }
    yPos = scale - 1;
}

static int interpolate_y(short **rowbuf, const ubyte *ibuf, int in_width, int scale)
{
    int i, comp;
    int num = scale;
    int den = 1;
    short _yPos = yPos;

    if (num == den) {
	short *tmp = curRow;
	curRow = nextRow;
	nextRow = tmp;
	for (i = 0; i < in_width * 3; ++i)
	    nextRow[i] = ibuf[i] << 7;
	*rowbuf = curRow;
	return 1;
    }

    _yPos += den;
    if (_yPos >= num) {
	const r_ubyte *inbp = ibuf;
	r_short *pcur = nextRow;
        r_short *pnxt = curRow;
	r_short *dzp = dzBuf;
	r_short *tmp = curRow;

	curRow = nextRow;
	nextRow = tmp;
	_yPos -= num;

#pragma unroll_amount(UNROLL,1)
	for (i = 0; i < in_width; ++i) {
	    for (comp = 0; comp < COMPS; ++comp) {
	        int t = inbp[comp];
	        int pix = t << 7;
	        int tx = pcur[comp];
	        int dz = (pix - t) >> 7;
	        tx += _yPos * (dz << 8);
	        pcur[comp] = tx;
	        pnxt[comp] = pix;
	        dzp[comp] = dz;
	    }
	    inbp += 3;
	    pcur += 3;
	    pnxt += 3;
	    dzp += 3;
	}
    }
    else {
	r_short *pcur = curRow;
	r_short *dzp = dzBuf;
#pragma unroll_amount(UNROLL,1)
	for (i = 0; i < in_width; ++i) {
	    for (comp = 0; comp < COMPS; ++comp) {
	        int dz = dzp[comp];
	        int t0 = pcur[comp];
	        t0 += dz << 15;
	        pcur[comp] = t0;
	    }
	    pcur += 3;
	    dzp += 3;
	}
    }
    *rowbuf = curRow;
    yPos = _yPos;
    return (_yPos + den >= num);
}

static void interpolate_x(ubyte *dst, const short *src, int in_width, int scale)
{
    int i;
    int num = scale;
    int den = 1;
    int out_width = in_width * scale;
    const r_short *sp = src;
    r_ubyte *dp = dst;

    int xpos = num - den;
    int x1_0 = sp[0];
    int x1_1 = sp[1];
    int x1_2 = sp[2];

#pragma unroll_amount(UNROLL,1)
    for (i = 0; i < out_width; ++i) {
	int dx_0 = 0, dx_1 = 0, dx_2 = 0;
        int x_0 = 0, x_1 = 0, x_2 = 0;
	xpos += den;
	if (xpos < num) {
	    x_0 += dx_0 << 8;
	    x_1 += dx_1 << 8;
	    x_2 += dx_2 << 8;
	}
	else {
	    xpos -= num;
	    sp += 3;

	    x_0 = x1_0;
	    x_1 = x1_1;
	    x_2 = x1_2;

	    x1_0 = sp[0];
	    x1_1 = sp[1];
	    x1_2 = sp[2];

	    dx_0 = (x1_0 - x_0) << 1;
	    dx_1 = (x1_1 - x_1) << 1;
	    dx_2 = (x1_2 - x_2) << 1;

	    x_0 += xpos * dx_0;
	    x_1 += xpos * dx_1;
	    x_2 += xpos * dx_2;
	}
	dp[0] = x_0 >> 7;
	dp[1] = x_1 >> 7;
	dp[2] = x_2 >> 7;
	dp += 3;
    }
}

extern void resize_init(const ubyte *ibuf, int in_width, int scale)
{
    yPos = 0;
    curRow = nextRow = dzBuf = NULL;;
    alloc_resize_memory(in_width * scale);
    start_resize(ibuf, in_width, scale);
}

extern void resize_finish()
{
    free_resize_memory();
}

extern int resize(ubyte *obuf, const ubyte *ibuf, int in_width, int scale)
{
    short *rowbuf = NULL;
    int new_row = interpolate_y(&rowbuf, ibuf, in_width, scale);
    interpolate_x(obuf, rowbuf, in_width, scale);
    return new_row;
}

