/* 
** static char sccs_id[] = "$Id: dup.c,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
*/
/* dup() and dup2() "system call" */

/* This is needed by the web server  */

#include <unistd.h>

int dup2(int fildes, int fildes2)
{
return _dup2(fildes,fildes2);
}

int dup(int fildes)
{
return _dup(fildes);
}

