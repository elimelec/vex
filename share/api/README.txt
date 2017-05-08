INTRODUCTION

This directory contains a few example of the use of VEX simulation APIs,
and in particular the support for memory simulation modules and simulation
of custom instruction (asm extensions).

** Cache simulation example
cachelib_api.h		The header file for the cache simulation API
cachelib.c		Example of a custom "cache library", which simply
			counts and traces every memory access
testapi.c		Program example (for which we collect traces)

** Custom instruction example
testasm.c		Example of custom instruction use
asmlib.c		Simulation plug-in for the custom instructions

LICENSE TERMS

Use of the software is subject to the terms of the 
	"Hewlett-Packard Company Software License Agreement" 
license contained in the "LICENSE.txt" file. 

Read the License carefully before using the Software. By using 
the Software you agree to the terms and conditions of the license.

BUILDING THE EXAMPLE

The Makefile contains the basic rules to compile and run the examples.
