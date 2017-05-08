/**
*** Copyright (C) 2003-2007 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#ifdef JAMMED_ASM

#include "asmlib.h"

#ifndef UNROLL_ASM
#define UNROLL_ASM UNROLL
#endif

#ifdef _vex_
#include <vexasm.h>

#define FSDITHER(x,a,b,c,d) { \
    __vexasm2 _t2 = _asm2(0x1,a,b,c,d); \
    (x)=(int)_t2.n0; \
}

#define CSC1(p1,p2,p3,p4, r,g,b,p0,d1,d2 ) { \
    __vexasm4 _t4 = _asm4(0x2,r,g,b,p0,d1,d2); \
    p1 = _t4.n0; \
    p2 = _t4.n1; \
    p3 = _t4.n2; \
    p4 = _t4.n3; \
}
#define CSC2(x, r0,r1,r2,r3,r4) { \
    __vexasm3 _t3 = _asm3(0x3,r0,r1,r2,r3,r4); \
    x = _t3.n0; \
}

#else 
#define FSDITHER(x,a,b,c,d) \
    _FSDITHER(x,a,b,c,d) 
#define CSC1(p1,p2,p3,p4, r,g,b,p0,d1,d2) \
    _CSC1(p1,p2,p3,p4, r,g,b,p0,d1,d2)
#define CSC2(x, r0,r1,r2,r3,r4) \
    _CSC2(x, r0,r1,r2,r3,r4)
#endif

#include "imgpipe.h"
#include "csc.h"
#include "dither.h"

#define DIM1 17
#define DIM2 (DIM1 * DIM1)
#define DIM3 (DIM1 * DIM1 * DIM1)
#define SCALEUP(x) ((x) << 4)
#define SCALEDOWN(x) ((x) >> 4)
#define QUANT(x) ((x) > SCALEUP(127) ? 255 : 0)
#define CLIP(x,l,h) (MAX(MIN(x,h),l))

void rgb_to_cmyk_and_dither(ubyte *obuf, const ubyte *ibuf, int width)
{
    int i;
    const r_ubyte *input = ibuf;
    r_ubyte *output = obuf;

    const r_ubyte *rmap = csc_RGBLUT;
    const r_ubyte *gmap = csc_RGBLUT + DIM3;
    const r_ubyte *bmap = csc_RGBLUT + DIM3 * 2;

    const r_ubyte *cdevlut = csc_DEVLUT;
    const r_ubyte *mdevlut = csc_DEVLUT + 256;
    const r_ubyte *ydevlut = csc_DEVLUT + 512;

    const r_ubyte *ucrlut = csc_UCRLUT;

    r_short *perr = dither_error;

    int eym_c = perr[-4];
    int eym_m = perr[-3];
    int eym_y = perr[-2];
    int eym_k = perr[-1];

    int ey_c = perr[0];
    int ey_m = perr[1];
    int ey_y = perr[2];
    int ey_k = perr[3];

    int ex_c = 0;
    int ex_m = 0;
    int ex_y = 0;
    int ex_k = 0;

#pragma unroll_amount(UNROLL_ASM,1)
    for (i = 0; i < width; i++) {

	/* csc */

	int r = input[0];
	int g = input[1];
	int b = input[2];

	int R = (r == 255) ? 256 : r;
	int G = (g == 255) ? 256 : g;
	int B = (b == 255) ? 256 : b;

        int P1,P2,P3,P4;
        int x0_c,x0_m,x0_y,x0_k;
	int xC,xM,xY;
	int P0 = ((R >> 4) * DIM2) + ((G >> 4) * DIM1) + (B >> 4);
        CSC1(P1,P2,P3,P4, R,G,B,P0,DIM1,DIM2);
        {
        int r0 = rmap[P0]; int r1 = rmap[P1]; int r2 = rmap[P2]; int r3 = rmap[P3]; int r4 = rmap[P4];
        int g0 = gmap[P0]; int g1 = gmap[P1]; int g2 = gmap[P2]; int g3 = gmap[P3]; int g4 = gmap[P4];
        int b0 = bmap[P0]; int b1 = bmap[P1]; int b2 = bmap[P2]; int b3 = bmap[P3]; int b4 = bmap[P4];

        CSC2(xC, r0,r1,r2,r3,r4);
        CSC2(xM, g0,g1,g2,g3,g4);
        CSC2(xY, b0,b1,b2,b3,b4);
        }

        { 
	int xC1 = cdevlut[xC];
	int xM1 = mdevlut[xM];
	int xY1 = ydevlut[xY];

	int Gray = MIN(xC1, MIN(xM1, xY1));
	int Black = ucrlut[Gray];

	int Cyan = xC1 - Black;
	int Magenta = xM1 - Black;
	int Yellow = xY1 - Black;


	/* dither */

	x0_c = Cyan;
	x0_m = Magenta;
	x0_y = Yellow;
	x0_k = Black;
        }

        {
	int eyp_c = perr[4];
	int eyp_m = perr[5];
	int eyp_y = perr[6];
	int eyp_k = perr[7];
	int dx_c, dx_m, dx_y, dx_k; 

        FSDITHER(dx_c, ex_c,eym_c,ey_c,eyp_c);
        FSDITHER(dx_m, ex_m,eym_m,ey_m,eyp_m);
        FSDITHER(dx_y, ex_y,eym_y,ey_y,eyp_y);
        FSDITHER(dx_k, ex_k,eym_k,ey_k,eyp_k);

        {
	int r0_c = x0_c + dx_c;
	int r0_m = x0_m + dx_m;
	int r0_y = x0_y + dx_y;
	int r0_k = x0_k + dx_k;

	int q0_c = r0_c > 127 ? 255 : 0;
	int q0_m = r0_m > 127 ? 255 : 0;
	int q0_y = r0_y > 127 ? 255 : 0;
	int q0_k = r0_k > 127 ? 255 : 0;

	ex_c = (r0_c - q0_c);
	ex_m = (r0_m - q0_m);
	ex_y = (r0_y - q0_y);
	ex_k = (r0_k - q0_k);

	eym_c = ey_c;
	eym_m = ey_m;
	eym_y = ey_y;
	eym_k = ey_k;

	ey_c = eyp_c;
	ey_m = eyp_m;
	ey_y = eyp_y;
	ey_k = eyp_k;

	perr[0] = ex_c;
	perr[1] = ex_m;
	perr[2] = ex_y;
	perr[3] = ex_k;

	output[0] = q0_c;
	output[1] = q0_m;
	output[2] = q0_y;
	output[3] = q0_k;
        }
        }

	input += 3;
	output += 4;
	perr += 4;
    }
}

#endif

