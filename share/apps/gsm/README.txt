INTRODUCTION

This distribution contains the VEX-specific modifications to the ANSI-C
code for the GSM (Global System for Mobile communications) Enhanced
Full Rate (EFR) speech codec (GSM 06.53 version 8.0.1 Release 1999)
developed as part of the Digital cellular telecommunications system
(Phase 2+), and available for download from http://www.etsi.org as

    	European Standard (Telecommunications series) 
	ETSI EN 300 724 V8.0.1 (2000-11)

This European Standard (Telecommunications series) has been produced
by ETSI Technical Committee Special Mobile Group (SMG). 

The ETSI standard provides the bit exact definition of the Enhanced
Full Rate (EFR) speech traffic codec for the digital cellular
telecommunications system. An electronic attachment accompanies the
ETSI document, containing clause 5, the bit-exact ANSI-C code for
the Enhanced Full Rate speech transcoder.

The full specification document, together with the ANSI-C code, can 
be downloaded from http://www.etsi.org

LICENSE TERMS

Use of the VEX modifications to the GSM codecs are subject to the 
terms of the 
	"Hewlett-Packard Company Software License Agreement" 
license contained in the "LICENSE.txt" file. 

Read the License carefully before using the Software. By using 
the Software you agree to the terms and conditions of the license.

HOW TO INSTALL SOURCES

The 'makesrc' shell script creates and installs the 'src' distribution, 
through the following steps:

1. download the ETSI bit-exact ANSI-C code for the EFR codec from
	http://WEBAPP.ETSI.ORG/exchangefolder/en_300724v080001p0.zip
2. install the VEX-specific sources, libraries and makefiles
3. apply VEX-specific modifications to the ETSI sources

If step 1 (download) fails (for example, if 'wget' is not supported), it
is possible to manually download the "en_300724v080001p0.zip" from the
http://www.etsi.org website and manually copy it to the 'vex/apps/gsm'
directory. If the script finds a conformant version of the ETSI code, it
continues the installation with it.

BUILDING THE BENCHMARK

Once sources are downloaded, installed and patched to the 'src' directory,
the Makefile contains the basic rules to compile and run the benchmark.
Make sure to edit the makefile and change the location of the CC variable
to the path where the VEX 'cc' compiler was installed in your system
(default is /opt/vex/bin/cc).

The Makefile supports the following compilation configurations:
(1) make MM=vex-base
    Build the codecs without VEX-specific optimizations
(2) make MM=vex-opt
    Build the codecs with VEX-specific optimizations
(3) make MM=vex-asm
    Build the codecs with VEX-specific assembler extensions

RUNNING THE BENCHMARK

Executing 'make test' runs the encoder and decoder (previously built)
on a simple set of test inputs. Other tests can be obtained by ETSI. 
Execution results and statistics are in the 'run' directory.

