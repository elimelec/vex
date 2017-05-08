/**
*** Copyright (C) 1995-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#include "imgpipe.h"
#include "csc.h"

#define DIM1 17
#define DIM2 (DIM1 * DIM1)
#define DIM3 (DIM1 * DIM1 * DIM1)

ubyte csc_RGBLUT[DIM3 * 3];
ubyte csc_DEVLUT[256 * 3];
ubyte csc_UCRLUT[256];

extern void rgb_to_cmyk_init()
{
    /**
    *** Dummy RGB->CMYK colorspace conversion tables
    ***
    *** The RGBLUT implements:
    *** 	c = 255 - r
    *** 	m = 255 - g
    *** 	y = 255 - k
    *** (In reality, it should be derived by an ICC (color) profile
    *** to match the acquisition device with the rendering device)
    ***
    *** The DEVLUT implements a linear gamma correction (out = in)
    ***
    *** The UCRLUT extracts black for just a part of the gamut
    *** (In reality, it should compensate the black nonlinearity)
    **/
    int R, G, B;
    for (R = 0; R < 17; R++) {
	for (G = 0; G < 17; G++) {
	    for (B = 0; B < 17; B++) {
		ubyte r = R < 16 ? R << 4 : 255;
		ubyte g = G < 16 ? G << 4 : 255;
		ubyte b = B < 16 ? B << 4 : 255;
		ubyte c = 255 - r;
		ubyte m = 255 - g;
		ubyte y = 255 - b;
		csc_RGBLUT[0 * DIM3 + R * DIM2 + G * DIM1 + B] = c;
		csc_RGBLUT[1 * DIM3 + R * DIM2 + G * DIM1 + B] = m;
		csc_RGBLUT[2 * DIM3 + R * DIM2 + G * DIM1 + B] = y;
	    }
	}
    }
    for (R = 0; R < 256; R++) {
	csc_DEVLUT[R] = R;
	csc_DEVLUT[R + 256] = R;
	csc_DEVLUT[R + 512] = R;
	csc_UCRLUT[R] = R < 192 ? 0 : R;
    }
}

extern void rgb_to_cmyk(ubyte *obuf, const ubyte *ibuf, int width)
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

    /**
    *** ILP-optimized 3d-cube interpolation (pruned)
    **/
#pragma unroll_amount(UNROLL,1)
    for (i = 0; i < width; i++) {

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

	output[0] = xC1 - Black;
	output[1] = xM1 - Black;
	output[2] = xY1 - Black;
	output[3] = Black;

	input += 3;
	output += 4;
    }
}

