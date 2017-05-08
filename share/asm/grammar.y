%{
/**
*** Copyright (C) 1994 - 2002 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
**/

/**
*** Author:  Geoffrey Brown, Paolo Faraboschi
**/

static char sccs_id[] = "$Id: grammar.y,v 1.6 2003/10/09 09:49:11 frb Exp $";

#include <stdlib.h>
#include <stdio.h>

#ifdef YYBISON
# ifdef __hpux
#  include <alloca.h>
# endif
#endif

#include "vextypes.h"

enum { LOCAL = 0, GLOBAL = 1 };
static char *vexscope[] = {"local","global"};

void yyerror (char *s);
void yywarn (char *s);
int yywrap ();

static void print_exp(vexexp *exp);
static vexexp *build_binexp(char op, vexexp *s1, vexexp *s2);
static vexexp *build_unexp(char op, vexexp *s1);
static vexexp *build_strexp(char *s);
static vexexp *build_numexp(int x);

static int fcycle = 0;

%}

%start asm_file

%union
{
   int       val;
   char      *text;
   vexopc    *opc;
   vexexp    *exp;
   vexfun    fun;
}

%token            _ALIGN
%token            _ASCII
%token            _BSS
%token <opc>      _CALL_JMP
%token            _COMMENT
%token            _COMMON
%token            _DATA
%token            _DATA1
%token            _DATA2
%token            _DATA4
%token            _ENDP
%token            _ENTRY
%token            _EQU
%token            _IMPORT
%token            _PROC
%token            _REAL4
%token            _REAL8
%token            _RETURN
%token            _RTA
%token            _SECTION
%token            _SKIP
%token            _SVERSION
%token            _TEXT
%token            _TRACE
%token            _TYPE

%token <text>     CLUST
%token <text>     NAME
%token <val>      NUMBER
%token <opc>      OPCODE
%token <opc>      XNOP
%token <text>     QUOTE_STRING
%token <text>     REGNAME

%type   <text>    call_jmp_tgt
%type   <text>    name
%type   <text>    arg
%type   <text>    ret

%type   <val>     data_size
%type   <val>     scope
%type   <val>     .dup

%type   <exp>     data_val
%type   <exp>     expr

%type   <fun>     entry_dir

%left '+' '-' 
%left USIGN

%left INIT
%left _SKIP

%left ARGS
%left CLUST

/* dummy tokens, used outside yacc */
%token            BLOCK
%token            BUNDLE
%token            EQU
%token            LABEL

%%

/********************************************************************************
 **     File structure
 ********************************************************************************/

asm_file        :       asm_section
                |       asm_file asm_section 
                ;

asm_section     :       _SECTION data_section
                |       _SECTION bss_section
                |       _SECTION text_section
                |       _COMMENT QUOTE_STRING {
                            fprintf(yyout, "/* %s */\n", $2); 
                        }
                |       _SVERSION name
                |       _RTA NUMBER
                ;

        /*------------------------------------------------------*/
        /*              data section                            */
        /*------------------------------------------------------*/

data_section    :       _DATA .data_dir_list 
                ;


.data_dir_list  :       /* empty */
                |       data_dir_list
                ;

data_dir_list   :       data_dir
                |       data_dir_list data_dir
                ;


data_dir        :       _ALIGN NUMBER                   { 
                            printf("data align: %d\n", $2);
                        }
                |       _SKIP NUMBER                    { 
                            printf("data skip: %d\n", $2);
                        }
                |       name scope  {
                            printf("data item: %s (%s)\n",
                                $1, vexscope[$2]);
                        }
                        init_list %prec INIT            { }
                |       equ_dir                         { }
                |       common_dir                      { }
                |       data_global_dir                 { }
                |       type_dir                        { }
                ;

init_list       :       init_dir
                |       init_list init_dir
                ;

init_dir        :       data_size data_val .dup {
                            printf("    init: ");
                            print_exp($2);
                            printf(" (size: %d", $1);
                            if ($3)
                                printf(", dup: %d)\n", $3);
                            else
                                printf(")\n");
                        }
                |       _SKIP NUMBER { 
                            printf("    init: skip %d\n", $2);
                        }
                |       _ASCII QUOTE_STRING { 
                            printf("    init: string \"%s\"\n", $2);
                        }
                ;

data_val        :       expr               { $$ = $1; }
                |       NUMBER ',' NUMBER  { $$ = build_numexp($1); }

data_size       :       _DATA1          { $$ = 1; }
                |       _DATA2          { $$ = 2; }
                |       _DATA4          { $$ = 4; }
                |       _REAL4          { $$ = 4; }
                |       _REAL8          { $$ = 8; }
                ;

.dup            :       /* empty */     { $$ = 0;  }
                |       ':' NUMBER      { $$ = $2; }
                ;


data_global_dir :       _IMPORT name    { 
                             printf("data import: %s\n", $2);
                         }
                ;

        /*------------------------------------------------------*/
        /*              bss section                             */
        /*------------------------------------------------------*/

bss_section     :       _BSS .bss_dir_list
                ;

.bss_dir_list   :       /* empty */
                |       bss_dir_list
                ;

bss_dir_list    :       bss_dir
                |       bss_dir_list bss_dir
                ;

bss_dir         :       bss_label_decl
                |       common_dir
                |       equ_dir
                |       _ALIGN NUMBER {
                            printf("bss align: %d\n", $2);
                        }
                |       _SKIP NUMBER {
                            printf("bss skip: %d\n", $2);
                        }
                ;

bss_label_decl  :       name scope { 
                            printf("bss item: %s (%s)\n",
                                $1, vexscope[$2]);
                        }
                ;

common_dir      :       _COMMON name ',' NUMBER ',' NUMBER 
                ;

        /*------------------------------------------------------*/
        /*              text section                            */
        /*------------------------------------------------------*/

text_section    :       _TEXT .text_inst_list
                ;

.text_inst_list :       /* empty */
                |       text_inst_list
                ;

text_inst_list  :       text_inst                   
                |       text_inst_list text_inst
                ;

text_inst       :       proc_inst     
                |       equ_dir
                |       text_global_dir
                |       type_dir
                |       label_decl
                |       _ALIGN NUMBER {
                            printf("text align: %d\n", $2);
                        }
                ;

proc_inst       :       proc entry_dir  {
                            printf("++ begin function: %s (%s)\n",
                                $2.str, vexscope[$2.scope]);
                        }
                        code_list _ENDP {
                            printf("++ end function: %s\n", $2.str);
                        }
                |       proc name scope _ENDP {
                            printf("empty function: %s (%s)\n",
                                $2, vexscope[$3]);
                        }
                |       proc _ENDP
                ;

proc            :       _PROC { fcycle = 0; }
                ;

code_list       :       code_item
                |       code_list code_item 
                ;

code_item       :       bundle 
                |       call_jmp_dir   
                |       equ_dir        
                |       label_decl     
                |       return_dir     
                |       trace_dir      
                ;

trace_dir       :       _TRACE NUMBER
                |       _TRACE NUMBER ',' NUMBER 
                ;

label_decl      :       name scope  { 
                            printf("    label: %s (%s)\n",
                                $1, vexscope[$2]);
                        }
                ;

call_jmp_dir    :       _CALL_JMP call_jmp_tgt ',' callc ',' { }
                        arg '(' .arg_list ')' ','            { }
                        ret '(' .arg_list ')'                { }
                ;

call_jmp_tgt    :       name          { $$ = $1; }
                |       REGNAME       { $$ = $1; }
                |       /* empty */   { $$ = "(empty)"; }
                ;

entry_dir       :       _ENTRY callc ',' regloclist ',' arg '(' .arg_list ')' name scope { 
                            $$.str = $10;
                            $$.scope = $11;
                        }
                |       name scope  {
                            $$.str = $1;
                            $$.scope = $2;
                        }
                ;

callc           :       NAME  { }
                ;

return_dir      :       _RETURN  ret '(' .arg_list ')'  { }
                ;

arg             :       NAME  { $$ = $1; }
                ;

ret             :       NAME  { $$ = $1; }
                ;

text_global_dir :       _IMPORT name  {
                            printf("text import: %s\n", $2);
                        }
                ;

equ_dir         :       _EQU name ',' expr {
                            printf("equ: %s = ", $2);
                            print_exp($4);
                            printf("\n");
                        }
                ;

scope           :       ':'          { $$ = LOCAL; }
                |       ':'':'       { $$ = GLOBAL; }
                ;

type_dir        :       _TYPE name ',' '@' NAME
                ;

/**********************************************************************************
 **     Pseudo-instruction argument list (call, return, entry)
 **********************************************************************************/

.arg_list       :       /* empty */
                |       arg_list 
                |       stackexp arg_list 
                ;

stackexp        :       expr ',' NUMBER ';'  { }
                ;

arg_list        :       arg_desc              
                |       arg_list ',' arg_desc 
                ;

arg_desc        :       expr ':' arg_type               { }
                |       expr ':' expr ':' arg_type      { }
                |       ':' expr ':' arg_type           { }
                ;

arg_type        :       name            { }
                |       '[' NUMBER ']'  { }
                ;

regloclist      :       regloc         
                |       regloclist ',' regloc 
                ;

regloc          :       NAME '=' expr  { }
                ;

/**********************************************************************************
 **     BUNDLE structure and MOP opcodes
 **********************************************************************************/

bundle          :      .mop_list  end_bundle  { 
                           printf("%5d]  -------------------------\n",
                               fcycle);
                           fcycle++;
                       }
                ;

end_bundle      :       ';'';' 
                ;

.mop_list       :       /* empty */   { printf("              nop\n"); }
                |       mop_list     
                ;

mop_list        :       mop         
                |       mop_list mop 
                ;

mop             :       normal_mop  
		|	xnop_mop
                |       asm_mop    
                ;

normal_mop      :       CLUST OPCODE { 
                            printf("        %-5s %s", $1, $2->as_op);
                        }
                        .mop_arglist { 
                            printf("\n"); 
                        }
                ;

xnop_mop	:	XNOP NUMBER {
                            printf("        xnop %d\n", $2);
		        }
	 	;

asm_mop         :       CLUST OPCODE ',' NUMBER {
                            printf("        %-5s %s,%d ", 
                                $1, $2->as_op, $4);
                        }
                        .mop_arglist { 
                            printf("\n"); 
                        }
                ;

/**********************************************************************************
 **     MOP argument list
 **********************************************************************************/

.mop_arglist    :       /* empty */   %prec ARGS    
                |       mop_arglist '=' { printf("<="); } mop_arglist 
                |       mop_arglist '=' { printf("<="); } %prec ARGS 
                |       mop_arglist 
                ;


mop_arglist     :       mop_arg                   
                |       mop_arglist ',' mop_arg   
                ;

mop_arg         :       expr { 
                            printf(" ");
                            print_exp($1);
                            printf(" ");
                        }
                |       '[' REGNAME ']' {
                            printf(" [%s] ",$2);
                        }
                |       expr '[' REGNAME ']' {
                            printf(" ");
                            print_exp($1);
                            printf("[%s] ",$3);
                        }
                ;

/**********************************************************************************
 **     General add/sub arithmetic expression
 **********************************************************************************/

expr            :       '(' expr ')'          { $$ = $2; }
                |       expr '+' expr         { $$ = build_binexp('+', $1, $3); }
                |       expr '-' expr         { $$ = build_binexp('-', $1, $3); }
                |       '-' expr %prec USIGN  { $$ = build_unexp('-', $2); }
                |       '+' expr %prec USIGN  { $$ = build_unexp('+', $2); }
                |       '~' expr %prec USIGN  { $$ = build_unexp('~', $2); }
                |       name                  { $$ = build_strexp($1); }
                |       REGNAME               { $$ = build_strexp($1); }
                |       NUMBER                { $$ = build_numexp($1); }
                ;

/**********************************************************************************
 **     Generic name (could be NAME or OPCODE)
 **********************************************************************************/
name            :       NAME                  { $$ = $1; }
                |       OPCODE                { $$ = $1->as_op; }
                |       CLUST                 { $$ = $1; }
                ;
/**********************************************************************************/
/**********************************************************************************/

%%

static void print_exp(vexexp *exp)
{
    int x = exp->val;
    char *s = exp->str;

    if (x && s)
        printf("(");
    if (s) {
        printf("%s", s);
        if (x > 0)
            printf(" + %d", x);
        if (x < 0)
            printf(" - %d", -x);
    }
    else
        printf("%d", x);
    if (x && s)
        printf(")");
}

static vexexp *build_binexp(char op, vexexp *s1, vexexp *s2)
{
    int nval;
    int v1 = s1->val;
    int v2 = s2->val;
    vexexp *exp = (vexexp*) malloc(sizeof(vexexp));
    switch (op) {
        case '-': nval = v1 - v2; break;
        case '+': nval = v1 + v2; break;
        default:
            fprintf(stderr,"illegal binary op (`%c') at line %d\n", 
                op, yylineno);
            exit(3);
    }
    if (s1->str && s2->str) {
        fprintf(stderr,"illegal binary exp (%s, %s) at line %d\n", 
            s1->str, s2->str, yylineno);
    }
    exp->str = s1->str ? s1->str : s2->str;
    exp->val = nval;
    return exp;
}

static vexexp *build_unexp(char op, vexexp *s1)
{
    int nval;
    vexexp *exp = (vexexp*) malloc(sizeof(vexexp));
    int v1 = s1->val;
    switch (op) {
        case '-': nval = -v1; break;
        case '+': nval = +v1; break;
        case '~': nval = ~v1; break;
        default:
            fprintf(stderr,"illegal unary op (`%c') at line %d\n", 
                op, yylineno);
            exit(3);
    }
    if (s1->str) {
        fprintf(stderr,"illegal unary exp (%s) at line %d\n", 
            s1->str, yylineno);
    }
    exp->val = nval;
    return exp;
}

static vexexp *build_strexp(char *s)
{
    vexexp *exp = (vexexp*) malloc(sizeof(vexexp));
    exp->str = s;
    exp->val = 0;
    return exp;
}

static vexexp *build_numexp(int x)
{
    vexexp *exp = (vexexp*) malloc(sizeof(vexexp));
    exp->str = NULL;
    exp->val = x;
    return exp;
}

void yyerror (char *s)
{
   fprintf (stderr,"[FATAL] %s at line %d\n", s, yylineno);
   exit(100);
}

void yywarn (char *s)
{
   fprintf (stderr,"[WARN] %s at line %d\n", s, yylineno);
}


int yywrap ()
{
  return 1;
}

