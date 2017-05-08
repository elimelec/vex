/**
*** Copyright (C) 1996 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company.
**/

/**
*** static char sccs_id[] = "$Id: ld_ifprob.c,v 1.3 2005/02/24 11:27:13 frb Exp $ "
**/

/**
*** Author: Paolo Faraboschi
**/

#ifndef LAST_PROB_COUNT
#error LAST_PROB_COUNT is undefined
#endif

#define IFPROB_ERRCODE 100
#define BUFSIZ 128

unsigned int _Xifprob_entry_count_common[LAST_PROB_COUNT+1];
unsigned int _Xifprob_true_count_common[LAST_PROB_COUNT+1];

unsigned int *_Xifprob_entry_count = _Xifprob_entry_count_common;
unsigned int *_Xifprob_true_count = _Xifprob_true_count_common;

#include <fcntl.h>

#ifdef __linux__
# include <sys/stat.h>
#endif

static int ifp_open(void)
{
    char path[] = "ifprob.001";
    int  oflag = O_WRONLY | O_CREAT | O_EXCL;
    int  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int  fildes;
    int  i;

    if ((fildes = open("ifprob.out",oflag,mode)) >= 0)
        return fildes;

    for (i = 1; i < 1000; i++) {

        if ((fildes = open(path,oflag,mode)) >= 0)
            return fildes;

        if (++path[9] <= '9')
            continue;
        path[9] = '0';
        if (++path[8] <= '9')
            continue;
        path[8] = '0';
        if (++path[7] <= '9')
            continue;
        break;
    }

    return creat("ifprob.out",mode);
}


static int ifp_itoa(int n, char *s)
{
    char sr[BUFSIZ];
    register char *psr;
    register int   i = 0;

    /* compute ascii string (inverse order) */
    psr = sr;
    do {
        *psr++ = '0' + (n%10);
    } while ((n /= 10) > 0);

    /* reverse string */
    while (psr != sr)
        s[i++] = *(--psr);
    s[i] = 0;

    return i;
}


extern void sim_dump_ifprob_data()
{
    int fildes;
    int i;

    if ((fildes = ifp_open()) >= 0) {

        for (i = 0; i < LAST_PROB_COUNT; i++) {
            char s[BUFSIZ];
            register int n;
            n = ifp_itoa(_Xifprob_entry_count_common[i],s);
            write(fildes,s,n);
            write(fildes," ",1);
            n = ifp_itoa(_Xifprob_true_count_common[i],s);
            write(fildes,s,n);
            write(fildes,"\n",1);
        }

        close(fildes);
    }
}
