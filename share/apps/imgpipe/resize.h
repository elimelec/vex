/**
*** Copyright (C) 1995-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#ifndef RESIZE_H_INCLUDED
#define RESIZE_H_INCLUDED

#include "imgpipe.h"

extern void resize_init(const ubyte *inbuf, int in_width, int scale);
extern int resize(ubyte *oubuf, const ubyte *inbuf, int in_width, int scale);
extern void resize_finish();

#endif
