/*
** crt0.c version for linux
*/

/*
** Author: Paolo Faraboschi
*/

/* $Id: crt0_linux.c,v 1.2 2009/12/16 17:28:19 frb Exp $ */

/* Force loading the simulated exit() - this is never called */
extern void exit(int);
extern void __dummy__crt0_linux__()
{
    exit(1);
}
