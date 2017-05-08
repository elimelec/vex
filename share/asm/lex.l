/**
*** Copyright (C) 1998,2000,2002 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
**/

/**
*** Author:  Geoffrey Brown 
***     based upon previous work by Paolo Faraboschi
**/

%{

static char sccs_id[] = "$Id: lex.l,v 1.3 2002/08/06 21:03:38 frb Exp $";

#include <stdio.h>
#include <string.h>

#include "vextypes.h"
#include "grammar.h"

/* opcode definitions */
#include "vexopc.h"

int yylineno = 1;

static int mkreg(char *);
static int mkcluster(char *);
static int mkquoted(char *);
static int check_reserved(char *);
static void print_token(int);

#define Token(n) return(n)

%}
 
hex         "0x"[0-9a-f]+ 
dec         [0-9]+
quotetext   \"([^\"]|\\\")*\"
comtext     "#".*$
stabtext    \.stab[snd].*$
regname     \$(r|b|l)[0-9]\.[0-9]+
cl1    	    c[0-9](\.[0-9])?
cl2	    c[0-9](\.[0-9])?"="c[0-9](\.[0-9])?
symbolname  [0-9a-zA-Z\._\$\?]+
operator    [=\-\+\[\]~,\(\):;@]
wspace      [ \t]+


%%
{comtext}       { }
{stabtext}      { }
{hex}|{dec}     { yylval.val = strtol(yytext,0,0); Token(NUMBER);    }
{quotetext}     { return mkquoted(yytext);                           }
{regname}       { return mkreg(yytext);                              }
{cl1}|{cl2}     { return mkcluster(yytext);                          }
{symbolname}    { return check_reserved(yytext);                     }
\n              { yylineno++;                                        }
{wspace}        { /* ignore white space */                           }
{operator}      { Token(yytext[0]);                                  }

.               { 
                    fprintf(stderr,"error: unexpected %c at %d \n", 
		        yytext[0],  yylineno);
		     exit(2);
                }
%%

/* check list of reserved words       */

static int check_reserved(char *buf)
{
    int i;
    yylval.opc = NULL;
    for (i = 0; optab[i].as_op; i++) {
	if (strcmp(buf, optab[i].as_op) == 0) {
	    yylval.opc = &optab[i];
	    Token(yylval.opc->tok);
	}
    }
    yylval.text = strdup(buf);
    Token(NAME);
}

static int mkcluster(char *buf)
{
    yylval.text = strdup(buf);
    Token(CLUST);
}

static int mkreg(char *buf)
{
    yylval.text = strdup(buf);
    Token(REGNAME);
}

/*  count new lines in quoted string  */

static int mkquoted(char *buf)
{
    yylval.text = strdup(buf);
    Token(QUOTE_STRING);
}

static void print_token(int n)
{
    char *s;
    switch (n) {
    case NUMBER:
	s = "number";
	break;
    case NAME:
	s = "name";
	break;
    case CLUST:
	s = "clust";
	break;
    case REGNAME:
	s = "register";
	break;
    default:
	s = 0;
	break;
    }
    if (s)
	fprintf(stderr, "%s -- %s \n", s, yytext);
    else
	fprintf(stderr, "%d -- %s \n", n, yytext);
}

