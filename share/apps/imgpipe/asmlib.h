/**
*** Copyright (C) 2003-2007 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#ifndef _ASMLIB_H_
#define _ASMLIB_H_

#define _FSDITHER(x,a,b,c,d) { \
    x = (a * 7 + b + c * 5 + d * 3) / 16; \
}

#define _CSC1(p1,p2,p3,p4, r,g,b,p0,d1,d2) { \
     p1 = p0 + (((r & 1) == 1) ? d2 : 0) + (((g & 1) == 1) ? d1 : 0) + (b & 1); \
     p2 = p0 + (((r & 2) == 2) ? d2 : 0) + (((g & 2) == 2) ? d1 : 0) + ((b & 2) >> 1); \
     p3 = p0 + (((r & 4) == 4) ? d2 : 0) + (((g & 4) == 4) ? d1 : 0) + ((b & 4) >> 2); \
     p4 = p0 + (((r & 8) == 8) ? d2 : 0) + (((g & 8) == 8) ? d1 : 0) + ((b & 8) >> 3); \
}

#define _CSC2(x, r0,r1,r2,r3,r4) { \
     x = (r0 + r1 + (r2 << 1) + (r3 << 2) + (r4 << 3) + 8) >> 4; \
}

#endif
