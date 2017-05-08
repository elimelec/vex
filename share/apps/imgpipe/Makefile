VPATH = jpeg
VEX = /opt/vex
# VEX = /home/frb/vex/build/image/be

CC = $(VEX)/bin/cc

ifeq ("$(MM)","vex-base")
CFLAGS =
LFLAG = 
ASMLIB =
endif

ifeq ("$(MM)","vex-opt")
CFLAGS = -DVEX_RESTRICT -DJAMMED -DUNROLL=4 -autoinline
LFLAG = 
ASMLIB =
endif

ifeq ("$(MM)","vex-asm")
CFLAGS = -DVEX_RESTRICT -DJAMMED -DJAMMED_ASM -DUNROLL_ASM=8 -DUNROLL=4
LFLAG = 
ASMLIB = jammed_asm.o asmlib.o
endif

CFLAGS += -O3 -H2 -ms -mas_G

ifeq ("$(MM)","gcc")
CC = gcc
CFLAGS = -O3 -pg
ASMLIB =
ENDIAN = little
endif

IMGPIPE_OBJS = imgpipe.o csc.o resize.o dither.o wppm.o jammed.o $(ASMLIB)

JPEG_LIB =  \
    jpeg/jcapimin.o \
    jpeg/jcapistd.o \
    jpeg/jccoefct.o \
    jpeg/jccolor.o \
    jpeg/jcdctmgr.o \
    jpeg/jchuff.o \
    jpeg/jcinit.o \
    jpeg/jcmainct.o \
    jpeg/jcmarker.o \
    jpeg/jcmaster.o \
    jpeg/jcomapi.o \
    jpeg/jcparam.o \
    jpeg/jcphuff.o \
    jpeg/jcprepct.o \
    jpeg/jcsample.o \
    jpeg/jctrans.o \
    jpeg/jdapimin.o \
    jpeg/jdapistd.o \
    jpeg/jdatadst.o \
    jpeg/jdatasrc.o \
    jpeg/jdcoefct.o \
    jpeg/jdcolor.o \
    jpeg/jddctmgr.o \
    jpeg/jdhuff.o \
    jpeg/jdinput.o \
    jpeg/jdmainct.o \
    jpeg/jdmarker.o \
    jpeg/jdmaster.o \
    jpeg/jdmerge.o \
    jpeg/jdphuff.o \
    jpeg/jdpostct.o \
    jpeg/jdsample.o \
    jpeg/jdtrans.o \
    jpeg/jerror.o \
    jpeg/jfdctflt.o \
    jpeg/jfdctfst.o \
    jpeg/jfdctint.o \
    jpeg/jidctflt.o \
    jpeg/jidctfst.o \
    jpeg/jidctint.o \
    jpeg/jidctred.o \
    jpeg/jmemmgr.o \
    jpeg/jmemnobs.o \
    jpeg/jquant1.o \
    jpeg/jquant2.o \
    jpeg/jutils.o


.PHONY: test

imgpipe: $(JPEG_LIB) $(IMGPIPE_OBJS) 
	$(CC) $(CFLAGS) -o $@ $(IMGPIPE_OBJS) $(JPEG_LIB)

test: imgpipe
	./imgpipe -s 2 -o pasta-thin.ppm pasta-thin.jpg; \
	$(VEX)/bin/runreport ta.log.* > report.html

test2: imgpipe
	./imgpipe -s 2 -o pasta.ppm pasta.jpg; \
	$(VEX)/bin/runreport ta.log.* > report.html

report:	
	$(VEX)/bin/runreport ta.log.* > report.html

clean_pipe:
	$(RM) $(IMGPIPE_OBJS)

clean:
	$(RM) $(JPEG_LIB) $(IMGPIPE_OBJS) imgpipe *.o *.s gmon* pasta.ppm

depend:
	makedepend -Y -I. *.[ch] jpeg/*.[ch]

#################################################################
# DO NOT DELETE

csc.o: imgpipe.h csc.h
csc.o: imgpipe.h
dither.o: imgpipe.h dither.h
dither.o: imgpipe.h
imgpipe.o: jpeg/jpeglib.h jpeg/jconfig.h jpeg/jmorecfg.h imgpipe.h wppm.h
imgpipe.o: csc.h
jammed.o: jammed.c imgpipe.h csc.h dither.h
jammed_asm.o: imgpipe.h csc.h dither.h asmlib.h
resize.o: resize.h imgpipe.h
resize.o: imgpipe.h
wppm.o: imgpipe.h wppm.h
wppm.o: imgpipe.h
jpeg/jcapimin.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jcapimin.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jcapistd.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jcapistd.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jccoefct.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jccoefct.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jccolor.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jccolor.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jcdctmgr.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jcdctmgr.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jchuff.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jchuff.o: jpeg/jpegint.h jpeg/jerror.h jpeg/jchuff.h
jpeg/jcinit.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jcinit.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jcmainct.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jcmainct.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jcmarker.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jcmarker.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jcmaster.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jcmaster.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jcomapi.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jcomapi.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jcparam.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jcparam.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jcphuff.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jcphuff.o: jpeg/jpegint.h jpeg/jerror.h jpeg/jchuff.h
jpeg/jcprepct.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jcprepct.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jcsample.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jcsample.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jctrans.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jctrans.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jdapimin.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdapimin.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdapistd.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdapistd.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdatadst.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdatadst.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdatasrc.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdatasrc.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdcoefct.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdcoefct.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdcolor.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jdcolor.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jddctmgr.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jddctmgr.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jdhuff.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jdhuff.o: jpeg/jpegint.h jpeg/jerror.h jpeg/jdhuff.h
jpeg/jdinput.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jdinput.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jdmainct.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdmainct.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdmarker.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdmarker.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdmaster.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdmaster.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdmerge.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jdmerge.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jdphuff.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jdphuff.o: jpeg/jpegint.h jpeg/jerror.h jpeg/jdhuff.h
jpeg/jdpostct.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdpostct.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdsample.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jdsample.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h
jpeg/jdtrans.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jdtrans.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jerror.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jerror.o: jpeg/jpegint.h jpeg/jerror.h jpeg/jversion.h
jpeg/jfdctflt.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jfdctflt.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jfdctfst.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jfdctfst.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jfdctint.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jfdctint.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jidctflt.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jidctflt.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jidctfst.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jidctfst.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jidctint.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jidctint.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jidctred.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jidctred.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jdct.h
jpeg/jinclude.o: jpeg/jconfig.h
jpeg/jmemmgr.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jmemmgr.o: jpeg/jpegint.h jpeg/jerror.h jpeg/jmemsys.h
jpeg/jmemnobs.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h
jpeg/jmemnobs.o: jpeg/jmorecfg.h jpeg/jpegint.h jpeg/jerror.h jpeg/jmemsys.h
jpeg/jpeglib.o: jpeg/jconfig.h jpeg/jmorecfg.h
jpeg/jquant1.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jquant1.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jquant2.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jquant2.o: jpeg/jpegint.h jpeg/jerror.h
jpeg/jutils.o: jpeg/jinclude.h jpeg/jconfig.h jpeg/jpeglib.h jpeg/jmorecfg.h
jpeg/jutils.o: jpeg/jpegint.h jpeg/jerror.h

## Custom assembler simulation library
asmlib.o: asmlib.c asmlib.h
	gcc -O -c asmlib.c

