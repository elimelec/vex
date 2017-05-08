/**
*** Copyright (C) 1995-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#ifndef CSC_H_INCLUDED
#define CSC_H_INCLUDED

#include "imgpipe.h"

extern ubyte csc_RGBLUT[];
extern ubyte csc_DEVLUT[];
extern ubyte csc_UCRLUT[];

extern void rgb_to_cmyk(ubyte *obuf, const ubyte *ibuf, int width);
extern void rgb_to_cmyk_and_dither(ubyte *obuf, const ubyte *ibuf, int width);
extern void rgb_to_cmyk_init();
#endif
