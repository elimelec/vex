/**
*** Copyright (C) 2003-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#ifndef IMGPIPE_H_INCLUDED
#define IMGPIPE_H_INCLUDED

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef unsigned char ubyte;

#ifdef _vex_
# ifdef VEX_RESTRICT
#  pragma restrict
# endif
#endif
typedef ubyte r_ubyte;

#ifdef _vex_
# ifdef VEX_RESTRICT
#  pragma restrict
# endif
#endif
typedef short r_short;

#ifndef UNROLL
#define UNROLL 4
#endif

#endif
