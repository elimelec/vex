/**
*** Copyright (C) 2003-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#ifndef JAMMED_ASM

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

#pragma unroll_amount(UNROLL,1)
    for (i = 0; i < width; i++) {

	/* csc */

	int r = input[0];
	int g = input[1];
	int b = input[2];

	int R = (r == 255) ? 256 : r;
	int G = (g == 255) ? 256 : g;
	int B = (b == 255) ? 256 : b;

	int P0 = ((R >> 4) * DIM2) + ((G >> 4) * DIM1) + (B >> 4);
	int P1 = P0 + (((R & 1) == 1) ? DIM2 : 0) + (((G & 1) == 1) ? DIM1 : 0) + (B & 1);
	int P2 = P0 + (((R & 2) == 2) ? DIM2 : 0) + (((G & 2) == 2) ? DIM1 : 0) + ((B & 2) >> 1);
	int P3 = P0 + (((R & 4) == 4) ? DIM2 : 0) + (((G & 4) == 4) ? DIM1 : 0) + ((B & 4) >> 2);
	int P4 = P0 + (((R & 8) == 8) ? DIM2 : 0) + (((G & 8) == 8) ? DIM1 : 0) + ((B & 8) >> 3);

	int xC = (rmap[P0] + rmap[P1] + (rmap[P2] << 1) + (rmap[P3] << 2) + (rmap[P4] << 3) + 8) >> 4;
	int xM = (gmap[P0] + gmap[P1] + (gmap[P2] << 1) + (gmap[P3] << 2) + (gmap[P4] << 3) + 8) >> 4;
	int xY = (bmap[P0] + bmap[P1] + (bmap[P2] << 1) + (bmap[P3] << 2) + (bmap[P4] << 3) + 8) >> 4;

	int xC1 = cdevlut[xC];
	int xM1 = mdevlut[xM];
	int xY1 = ydevlut[xY];

	int Gray = MIN(xC1, MIN(xM1, xY1));
	int Black = ucrlut[Gray];

	int Cyan = xC1 - Black;
	int Magenta = xM1 - Black;
	int Yellow = xY1 - Black;

	/* dither */

	int x0_c = Cyan;
	int x0_m = Magenta;
	int x0_y = Yellow;
	int x0_k = Black;

	int eyp_c = perr[4];
	int eyp_m = perr[5];
	int eyp_y = perr[6];
	int eyp_k = perr[7];

	int dx_c = (ex_c * 7 + eym_c + ey_c * 5 + eyp_c * 3) / 16;
	int dx_m = (ex_m * 7 + eym_m + ey_m * 5 + eyp_m * 3) / 16;
	int dx_y = (ex_y * 7 + eym_y + ey_y * 5 + eyp_y * 3) / 16;
	int dx_k = (ex_k * 7 + eym_k + ey_k * 5 + eyp_k * 3) / 16;

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

	#ifdef PACKBYTES
	((int *)output)[0] = (q0_c << 24) | (q0_m << 16) | (q0_y << 8) | q0_k;
	#else
	output[0] = q0_c;
	output[1] = q0_m;
	output[2] = q0_y;
	output[3] = q0_k;
	#endif

	input += 3;
	output += 4;
	perr += 4;
    }
}

#endif
