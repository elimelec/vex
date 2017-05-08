/**
*** Copyright (C) 2003-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

/**
*** Floyd-Steinberg error diffusion
**/

#include <stdio.h>
#include <stdlib.h>
#include "imgpipe.h"
#include "dither.h"
#define SCALEUP(x) ((x) << 4)
#define SCALEDOWN(x) ((x) >> 4)
#define QUANT(x) ((x) > SCALEUP(127) ? 255 : 0)
#define CLIP(x,l,h) (MAX(MIN(x,h),l))

short *dither_error = NULL;

#define COMPS 4

#define OPTLEV 1

extern void dither_init(int width)
{
    dither_error = (short *) calloc(sizeof(short),(width + 2) * COMPS);
    dither_error += COMPS;
}

extern void dither_finish()
{
    free(dither_error - COMPS);
}

#if OPTLEV == 0

extern void dither(ubyte * obuf, const ubyte * ibuf, int width)
{
    int component;
    for (component = 0; component < COMPS; ++component) {

	const r_ubyte *psrc = ibuf + component;
	r_ubyte *pdst = obuf + component;
	r_short *perr = dither_error + component;

	int eym = *(perr - COMPS);
	int ey = *perr;
	int ex = 0;
	int i;

	for (i = 0; i < width; ++i) {

	    int eyp = perr[COMPS];
	    int x0 = psrc[0];
	    int dx = (ex * 7 + eym + ey * 5 + eyp * 3) / 16;
	    int r0 = x0 + dx;
	    int q0 = r0 > 127 ? 255 : 0;

	    ex = (r0 - q0);
	    eym = ey;
	    ey = eyp;

	    perr[0] = ex;
	    pdst[0] = q0;

	    perr += COMPS;
	    pdst += COMPS;
	    psrc += COMPS;
	}
    }
}

#elif OPTLEV == 1

extern void dither(ubyte * obuf, const ubyte * ibuf, int width)
{
    int i;

    const r_ubyte *psrc = ibuf;
    r_ubyte *pdst = obuf;
    r_short *perr = dither_error;

    int eym_c = *(perr - COMPS);
    int eym_m = *(perr - COMPS + 1);
    int eym_y = *(perr - COMPS + 2);
    int eym_k = *(perr - COMPS + 3);

    int ey_c = *perr;
    int ey_m = *(perr + 1);
    int ey_y = *(perr + 2);
    int ey_k = *(perr + 3);

    int ex_c = 0;
    int ex_m = 0;
    int ex_y = 0;
    int ex_k = 0;

#pragma unroll_amount(UNROLL,1)
    for (i = 0; i < width; ++i) {

	int eyp_c = *(perr + COMPS);
	int eyp_m = *(perr + COMPS + 1);
	int eyp_y = *(perr + COMPS + 2);
	int eyp_k = *(perr + COMPS + 3);

	int x0_c = *psrc;
	int x0_m = *(psrc + 1);
	int x0_y = *(psrc + 2);
	int x0_k = *(psrc + 3);

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

	*perr = ex_c;
	*(perr + 1) = ex_m;
	*(perr + 2) = ex_y;
	*(perr + 3) = ex_k;

	*pdst = q0_c;
	*(pdst + 1) = q0_m;
	*(pdst + 2) = q0_y;
	*(pdst + 3) = q0_k;

	perr += COMPS;
	pdst += COMPS;
	psrc += COMPS;
    }
}
#endif
