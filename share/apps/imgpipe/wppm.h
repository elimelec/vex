/**
*** Copyright (C) 2003-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#ifndef WPPM_H_INCLUDED
#define WPPM_H_INCLUDED

#include <stdio.h>
#include "imgpipe.h"

extern void open_ppm(int width, int height, FILE * fp);
extern void write_ppm_row(ubyte * linedata, int width, FILE * fp);
extern void close_ppm(FILE * fp);

#endif
