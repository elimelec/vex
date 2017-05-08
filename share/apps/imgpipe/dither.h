/**
*** Copyright (C) 2003-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#ifndef DITHER_H_INCLUDED
#define DITHER_H_INCLUDED

#include "imgpipe.h"

extern short *dither_error;

extern void dither_init(int width);
extern void dither(ubyte *oubuf, const ubyte *inbuf, int width);
extern void dither_finish();

#endif
