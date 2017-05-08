/**
*** Copyright (C) 1994 - 2002 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
**/

/**
*** Author: Paolo Faraboschi
**/

/**
*** static char sccs_id[] = "$Id: vextypes.h,v 1.2 2002/08/06 18:45:05 frb Exp $";
**/

/**
*** Definition of VEX Opcodes
**/

#ifndef __MACHINE_INCLUDED__
#define __MACHINE_INCLUDED__

typedef enum {
        opASM, 
	opADD,
	opADDCG, 
	opAND, 
	opANDC, 
	opANDL, 
	opASMDIR,
	opBRANCH,  
	opBRANCHF,  
	opCALL, 
	opCALLDIR, 
	opCMPEQ, 
	opCMPGE, 
	opCMPGEU, 
	opCMPGT,
	opCMPGTU, 
	opCMPLE, 
	opCMPLEU, 
	opCMPLT, 
	opCMPLTU, 
	opCMPNE, 
	opDIVS,
	opGOTO, 
	opLDB, 
	opLDBU, 
	opLDH, 
	opLDHU, 
	opLDW, 
	opLONGJMPDIR,
	opMAX , 
	opMAXU ,
	opMFB, 
	opMFL, 
	opMIN, 
	opMINU, 
	opMOV, 
	opMTB, 
	opMTBINV, 
	opMTL, 
	opMUL,
	opMULL,
	opMULLU,
	opMULH,
	opMULHU,
	opMULHS,
	opMULLL,
	opMULLLU,
	opMULLH,
	opMULLHU,
	opMULHH,
	opMULHHU,
	opNANDL, 
	opNOP,
	opNORL,
	opOR,
	opORC,
	opORL,
	opPFT,
	opRETURN,
	opSBIT,
	opSBITF,
	opSETJMPDIR,
	opSH1ADD,
	opSH2ADD,
	opSH3ADD,
	opSH4ADD,
	opSHL,
	opSHR,
	opSHRU,
        opSLCT,
        opSLCTF,
	opSTB,
	opSTH,
	opSTW,
	opSUB,
	opSXTB,
	opSXTH,
	opTBIT,
	opTBITF,
	opXNOP,
	opXOR,
	opZXTB,
	opZXTH
} VEX_tok;

typedef enum {
       SPEC = 1,
       LOCK = 2,
       STREAM = 4,
       CTLFLOW = 8,
       SSPEC = (SPEC | STREAM),
       LSPEC = (SPEC | LOCK),
} VEX_flags;

typedef struct {
    char *as_op;     /* opcode string      */
    VEX_tok tok;     /* yacc token         */
    VEX_flags flags; /* flags (e.g. SPEC)  */
    int op;          /* operation type     */
} vexopc;

typedef struct {
    int val;
    char *str;
} vexexp;

typedef struct {
    char *str;
    int scope;
} vexfun;

extern FILE *yyout;
extern int yydebug;
extern int yylineno;
extern vexopc optab[];

#endif

