INTRODUCTION

This directory contains a simplified VEX assembler parser, and a simple 
example of how to use it to parse a VEX ".s" file and reconstruct 
information of each VEX operation and instruction.

grammar.y	The yacc grammar for VEX assmebler format
lex.l		The lexical analyzer for VEX assembler format
main.c		Simple driver to collect basic statistics
vexopc.h	Header file with VEX opcode definitions
vextypes.h	Basic types

test.s		VEX assembly file for testing

LICENSE TERMS 

Use of the software is subject to the terms of the 
	"Hewlett-Packard Company Software License Agreement" 
license contained in the "LICENSE.txt" file. 

Read the License carefully before using the Software. By using 
the Software you agree to the terms and conditions of the license.

BUILDING THE EXAMPLE

The Makefile contains the basic rules to compile and run the parser
