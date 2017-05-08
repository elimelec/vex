/**
*** static char sccs_id[] = "$Id: outbyte.c,v 1.1.1.1 2001/11/21 20:34:41 frb Exp $ ";
**/
#include <stdio.h>

void
outbyte(int arg1)
{
  putchar((char)(arg1 & 0xff));
  fflush(stdout);
}
