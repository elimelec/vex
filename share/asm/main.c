/**
*** Copyright (C) 2002 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
**/

/**
*** Author:  Paolo Faraboschi
**/

static char sccs_id[] = "$Id: main.c,v 1.2 2002/08/06 18:45:05 frb Exp $";

#include <stdio.h>

#include "vextypes.h"
#include "grammar.h"

FILE *yyin;
FILE *yyout;

int main(int argc, char **argv)
{
#ifdef YYDEBUG
    yydebug = 1;
#endif

    if (argc < 2) {
	fprintf(stderr,"Usage: %s <vex_file.s>\n", argv[0]);
	exit(1);
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
	fprintf(stderr, "Error: can't open input file %s\n", argv[1]);
	exit(1);
    }

    yyout = stdout;

    yyparse();

    return 0;
}
