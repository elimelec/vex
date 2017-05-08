/**
*** Copyright (C) 1994 - 2002 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
**/

/**
*** Author:  Geoffrey Brown 
***     based upon previous work by Paolo Faraboschi and Bill Ackerman
**/

/**
*** static char sccs_id[] = "$Id: vexopc.h,v 1.3 2003/02/19 16:18:57 frb Exp $";
**/

/**
*** Definition of VEX Opcodes
**/

#ifndef __VEX_INCLUDED__
#define __VEX_INCLUDED__

#include "vextypes.h"
#include "grammar.h"

vexopc optab[] = {
/*----------------------------------------------*/
/*  as_opc            tok     flags     opctype */
/*----------------------------------------------*/
/* MEM */
   {"ldb",         OPCODE,   0,         opLDB},
   {"ldb.d",       OPCODE,   SPEC,      opLDB},
   {"ldbu",        OPCODE,   0,        opLDBU},
   {"ldbu.d",      OPCODE,   SPEC,     opLDBU},
   {"ldh",         OPCODE,   0,         opLDH},
   {"ldh.d",       OPCODE,   SPEC,      opLDH},
   {"ldhu",        OPCODE,   0,        opLDHU},
   {"ldhu.d",      OPCODE,   SPEC,     opLDHU},
   {"ldw",         OPCODE,   0,         opLDW},
   {"ldw.d",       OPCODE,   SPEC,      opLDW},
   {"pft",         OPCODE,   0,         opPFT},
   {"stb",         OPCODE,   0,         opSTB},
   {"sth",         OPCODE,   0,         opSTH},
   {"stw",         OPCODE,   0,         opSTW},

/* STREAM  */
   {"ldb.s",       OPCODE,   STREAM,    opLDB},
   {"ldb.s.d",     OPCODE,   SSPEC,     opLDB},
   {"ldbu.s",      OPCODE,   STREAM,    opLDBU},
   {"ldbu.s.d",    OPCODE,   SSPEC,     opLDBU},
   {"ldh.s",       OPCODE,   STREAM,    opLDH},
   {"ldh.s.d",     OPCODE,   SSPEC,     opLDH},
   {"ldhu.s",      OPCODE,   STREAM,    opLDHU},
   {"ldhu.s.d",    OPCODE,   SSPEC,     opLDHU},
   {"ldw.s",       OPCODE,   STREAM,    opLDW},
   {"ldw.s.d",     OPCODE,   SSPEC,     opLDW},
   {"pft.s",       OPCODE,   STREAM,    opPFT},
   {"stb.s",       OPCODE,   STREAM,    opSTB},
   {"sth.s",       OPCODE,   STREAM,    opSTH},
   {"stw.s",       OPCODE,   STREAM,    opSTW},

/* LOCK */
   {"ldb.l",       OPCODE,   LOCK,      opLDB},
   {"ldb.l.d",     OPCODE,   LSPEC,     opLDB},
   {"ldbu.l",      OPCODE,   LOCK,      opLDBU},
   {"ldbu.l.d",    OPCODE,   LSPEC,     opLDBU},
   {"ldh.l",       OPCODE,   LOCK,      opLDH},
   {"ldh.l.d",     OPCODE,   LSPEC,     opLDH},
   {"ldhu.l",      OPCODE,   LOCK,      opLDHU},
   {"ldhu.l.d",    OPCODE,   LSPEC,     opLDHU},
   {"ldw.l",       OPCODE,   LOCK,      opLDW},
   {"ldw.l.d",     OPCODE,   LSPEC,     opLDW},
   {"pft.l",       OPCODE,   LOCK,      opPFT},
   {"stb.l",       OPCODE,   LOCK,      opSTB},
   {"sth.l",       OPCODE,   LOCK,      opSTH},
   {"stw.l",       OPCODE,   LOCK,      opSTW},

/* ALU */
   {"add",        OPCODE,    0,         opADD},
   {"and",        OPCODE,    0,         opAND},
   {"andc",       OPCODE,    0,         opANDC},
   {"andl",       OPCODE,    0,         opANDL},
   {"cmpeq",      OPCODE,    0,         opCMPEQ},
   {"cmpge",      OPCODE,    0,         opCMPGE},
   {"cmpgeu",     OPCODE,    0,         opCMPGEU},
   {"cmpgt",      OPCODE,    0,         opCMPGT},
   {"cmpgtu",     OPCODE,    0,         opCMPGTU},
   {"cmple",      OPCODE,    0,         opCMPLE},
   {"cmpleu",     OPCODE,    0,         opCMPLEU},
   {"cmplt",      OPCODE,    0,         opCMPLT},
   {"cmpltu",     OPCODE,    0,         opCMPLTU},
   {"cmpne",      OPCODE,    0,         opCMPNE},
   {"max",        OPCODE,    0,         opMAX },
   {"maxu",       OPCODE,    0,         opMAXU },
   {"min",        OPCODE,    0,         opMIN},
   {"minu",       OPCODE,    0,         opMINU},
   {"mpy",        OPCODE,    0,         opMUL},
   {"mpyl",       OPCODE,    0,         opMULL},
   {"mpylu",      OPCODE,    0,         opMULLU},
   {"mpyh",       OPCODE,    0,         opMULH},
   {"mpyhu",      OPCODE,    0,         opMULHU},
   {"mpyhs",      OPCODE,    0,         opMULHS},
   {"mpyll",      OPCODE,    0,         opMULLL},
   {"mpyllu",     OPCODE,    0,         opMULLLU},
   {"mpylh",      OPCODE,    0,         opMULLH},
   {"mpylhu",     OPCODE,    0,         opMULLHU},
   {"mpyhh",      OPCODE,    0,         opMULHH},
   {"mpyhhu",     OPCODE,    0,         opMULHHU},
   {"nandl",      OPCODE,    0,         opNANDL},
   {"nop",        OPCODE,    0,         opNOP},
   {"norl",       OPCODE,    0,         opNORL},
   {"or",         OPCODE,    0,         opOR},
   {"orc",        OPCODE,    0,         opORC},
   {"orl",        OPCODE,    0,         opORL},
   {"sbit",       OPCODE,    0,         opSBIT},
   {"sbitf",      OPCODE,    0,         opSBITF},
   {"sh1add",     OPCODE,    0,         opSH1ADD},
   {"sh2add",     OPCODE,    0,         opSH2ADD},
   {"sh3add",     OPCODE,    0,         opSH3ADD},
   {"sh4add",     OPCODE,    0,         opSH4ADD},
   {"shl",        OPCODE,    0,         opSHL},
   {"shr",        OPCODE,    0,         opSHR},
   {"shru",       OPCODE,    0,         opSHRU},
   {"slct",       OPCODE,    0,         opSLCT},
   {"slctf",      OPCODE,    0,         opSLCTF},
   {"sub",        OPCODE,    0,         opSUB},
   {"sxtb",       OPCODE,    0,         opSXTB},
   {"sxth",       OPCODE,    0,         opSXTH},
   {"tbit",       OPCODE,    0,         opTBIT},
   {"tbitf",      OPCODE,    0,         opTBITF},
   {"xor",        OPCODE,    0,         opXOR},
   {"zxtb",       OPCODE,    0,         opZXTB},
   {"zxth",       OPCODE,    0,         opZXTH},

/* DIV/CARRY */
   {"divs",	  OPCODE,    0,         opDIVS},
   {"addcg",      OPCODE,    0,         opADDCG},

/* MOV */
   {"mov",	  OPCODE,    0,         opMOV},
   {"mfl",	  OPCODE,    0,         opMFL},
   {"mtl",	  OPCODE,    0,         opMTL},
   {"mfb",	  OPCODE,    0,         opMFB},
   {"mtb",	  OPCODE,    0,         opMTB},
   {"mtbf",	  OPCODE,    0,         opMTBINV},

/* BRANCH */
   {"goto",       OPCODE,    CTLFLOW,   opGOTO},
   {"call",       OPCODE,    CTLFLOW,   opCALL},
   {"return",     OPCODE,    CTLFLOW,   opRETURN},
   {"br",         OPCODE,    CTLFLOW,   opBRANCH},
   {"brf",        OPCODE,    CTLFLOW,   opBRANCHF},

/* ASM */
   {"asm",        OPCODE,    0,         opASM},

/* XNOP */
   {"xnop",       XNOP,      0,         opXNOP},

/**************** PSEUDO  OPCODES *************************/

   {".call",      _CALL_JMP,  0,        opCALLDIR},
   {".longjmp",   _CALL_JMP,  0,        opLONGJMPDIR},
   {"._longjmp",  _CALL_JMP,  0,        opLONGJMPDIR},
   {".__longjmp", _CALL_JMP,  0,        opLONGJMPDIR},
   {".setjmp",    _CALL_JMP,  0,        opSETJMPDIR},
   {"._setjmp",   _CALL_JMP,  0,        opSETJMPDIR},
   {".__setjmp",  _CALL_JMP,  0,        opSETJMPDIR},

/*************  ASSEMBLER DIRECTIVES **********************/

   {".align",      _ALIGN,    0,         opASMDIR},
   {".ascii",      _ASCII,    0,         opASMDIR},
   {".bss",        _BSS,      0,         opASMDIR},
   {".section",    _SECTION,  0,         opASMDIR},
   {".comment",    _COMMENT,  0,         opASMDIR},
   {".comm",       _COMMON,   0,         opASMDIR},
   {".data",       _DATA,     0,         opASMDIR},
   {".data1",      _DATA1,    0,         opASMDIR},
   {".data2",      _DATA2,    0,         opASMDIR},
   {".data4",      _DATA4,    0,         opASMDIR},
   {".endp",       _ENDP,     0,         opASMDIR},
   {".entry",      _ENTRY,    0,         opASMDIR},
   {".equ",        _EQU,      0,         opASMDIR},
   {".import",     _IMPORT,   0,         opASMDIR},
   {".proc",       _PROC,     0,         opASMDIR},
   {".real4",      _REAL4,    0,         opASMDIR},
   {".real8",      _REAL8,    0,         opASMDIR},
   {".return",     _RETURN,   0,         opASMDIR},
   {".rta",        _RTA,      0,         opASMDIR},
   {".skip",       _SKIP,     0,         opASMDIR},
   {".sversion",   _SVERSION, 0,         opASMDIR},
   {".text",       _TEXT,     0,         opASMDIR},
   {".trace",      _TRACE,    0,         opASMDIR},
   {".type",       _TYPE,     0,         opASMDIR},

   {NULL}
};

#endif

