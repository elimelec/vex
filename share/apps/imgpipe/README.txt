INTRODUCTION

This distribution contains the imaging pipeline (imgpipe) benchmark
developed for VEX. The code implements a color printing pipeline 
that transforms a JPEG RGB input image to a PPM output image containing
CMYK halftoned (binary) pixels. 

LICENSE TERMS

Use of the imgpipe software is subject to the terms of the 
	"Hewlett-Packard Company Software License Agreement" 
license contained in the "LICENSE.txt" file. 

Read the License carefully before using the Software. By using 
the Software you agree to the terms and conditions of the license.

The 'jpeg' subdirectory contains a release (release 6b of 27-Mar-1998)
of the Independent JPEG Group's free JPEG software. The 'jpeg' software 
is copyright (C) 1991-1998, Thomas G. Lane. Read the 'jpeg/README' file
("LEGAL ISSUES" section) for details on the licensing terms of the JPEG 
library.

BUILDING THE BENCHMARK

The Makefile contains the basic rules to compile and run the benchmark.
Make sure to edit the makefile and change the location of the VEX
variable to the path where the VEX root was installed in your system
(default is /opt/vex).

Configuration options in the makefile are triggered by adding or removing
the following definitions from the CFLAGS variable

	-DVEX_RESTRICT: Enables VEX-specific aliasing directives

	-DJAMMED:       Uses the loop-fused version of the pipeline 
                        (jammed.c)

RUNNING THE BENCHMARK

Executing 'make' runs the imgpipe benchmark (previously built) on a
simple input and verifies its correctness. Any JPEG image can be passed
to imgpipe.

