# SCCS-info %W% %E%
#
# /*--------------------------------------------------------------------*/
# /*                                                                    */
# /*              VCG : Visualization of Compiler Graphs                */
# /*              --------------------------------------                */
# /*                                                                    */
# /*   file:         Makefile                                           */
# /*   version:      1.00.00                                            */
# /*   creation:     1.4.1993                                           */
# /*   author:       I. Lemke  (...-Version 0.99.99)                    */
# /*                 G. Sander (Version 1.00.00-...)                    */  
# /*                 Universitaet des Saarlandes, W-66041 Saarbruecken  */
# /*                 ESPRIT Project #5399 Compare                       */
# /*   description:  Makefile for vcg                                   */
# /*   status:       in work                                            */
# /*                                                                    */
# /*--------------------------------------------------------------------*/
# 
# $Id: Makefile,v 1.3 2009/12/17 17:16:31 frb Exp $
#
# $Log: Makefile,v $
# Revision 1.3  2009/12/17 17:16:31  frb
# *** empty log message ***
#
# Revision 1.2  2009/12/17 17:07:29  frb
# Update to patched debian version
#
# Revision 1.1  2009/12/17 11:36:37  frb
# add vcg sources
#
# Revision 2.2  1994/01/21  19:39:53  sander
# Some portabitility problems solved for IBM R6000, Silicon Graphics IRIX
# and Sun 3/60 K&R C.
#
# Revision 2.1  1993/12/08  21:23:15  sander
# Reasonable fast and stable version
#
#

#========================= CHANGE AREA =========================

# Please update the change area according to your system, if you
# want to call this Makefile directly

# where the binaries go
BINDIR = /opt/vex/bin

# how the VCG tool should be called
# For the Sunview version I use the name vcg. 
# For the X11 version I prefer the name xvcg. 
# VCGTOOL = vcg
VCGTOOL = xvcg

#-------------------------- Flags ------------------------------

# Flags for the C compiler 
# Important: Do not use -Dlint with gcc. This causes confusion
# during linking (!!!), e.g. some undefined messages. 
CFLAGS 	 = -c -O2 -g -static
# CFLAGS 	 = -c -O2 -static

# Flags for debugging
DFLAGS 	 =

# Flags for linking
#CLINKFLAGS = -o
CLINKFLAGS = -g -o

# Include directories
# If you use gcc, it may happen that not all ANSI header files
# are on the right place. Example: we often have problems to
# find stdarg.h. Look for this file and add the directory here,
# e.g.:
# INCLUDES = /usr/local/include/gnuansi/
#
# For Sunview, this should be enough, because on Suns, Sunview
# is normally installed in standard directories:
# INCLUDES = 
#
# For X11, it depends where it is installed. Look for Xlib.h,
# Xproto.h or Xutil.h. 
# For instance, if you find /usr/local/X11/include/X11/Xlib.h
# then please use
# INCLUDES = -I/usr/local/X11/include/
INCLUDES = 

# Library directories
# For Sunview, this should be enough, because on Suns, Sunview
# is normally installed in standard directories:
# LIBPATH = 
#
# For X11, it depends where it is installed. Look for libX.a,
# or libX11.so.<version_number>, or libXext.a, etc. 
# For instance, if you find /usr/local/X11/lib/libX11.a
# then please use
# INCLUDES = -I/usr/local/X11/lib/
LIBPATH = 


# Libraries
# Libraries for SunView
# LIBRARIES = -lsuntool -lsunwindow -lpixrect -lm 
#
# Libraries for X11 
# LIBRARIES = -lXext -lX11 -lm  -ldl -lxcb -lpthread -lXau -lXdmcp
LIBRARIES = -lX11 -lm
# LIBRARIES = -L/usr/lib/debug/usr/lib -lXext /usr/lib/debug/usr/lib/libX11.so.6.2.0 -lm 

#-------------------------- Tools ------------------------------

# C compiler
##### DOES NOT WORK WITH gcc-4.x !!! ######
CC 	= gcc

# C linker 
CCLINK  = $(CC)

# If you use gcc and the sun driver, you need the normal sun
# preprocessor because of incompatibilities of the system libraries
CPP     = cc -E

# If you dont need a special preprocessor, change the .c.o rule or
# define this:
#CPP    = cat

# Install software. You can use /bin/cp instead of /bin/install.
# I prefer that binaries are stripped.
# For directories:
INSTALLDIR = /bin/install -d -m 755

# For binary files:
# Assume that you want to install s file called dummy.
INSTALL = /bin/install -s -m 755 dummy $(BINDIR)/dummy

# RCS check out shellscript
CHECKOUT = co

# RCS check edit shellscript
CHECKEDIT = ce

# RCS check in shellscript
CHECKIN  = ci 

# parser pregenerator. If the files grammar.y and grammar.l
# are available, you don't need this.
PARSEGEN = parsegen

# lex-compatible scanner generator
# LEX	= flex

# yacc-compatible parser generator. Currently, it does not work 
# with yacc because some bison features are used directly.
# YACC     = bison -ydvt

# MakeDepend (should understand the -f option)
DEPEND   = makedepend

# Streameditor
# SED = /bin/sed
SED = /bin/sed

# Move File
MV       = /bin/mv

#Copy File
CP       = /bin/cp

# Remove File
RM       = /bin/rm 

#==================== END OF CHANGE AREA ======================

#-------------------------- Files ------------------------------

# C - Files
CFILES	= main.c options.c alloc.c step0.c step1.c step2.c step3.c step4.c\
	  prepare.c folding.c draw.c drawlib.c usrsignal.c \
	  grprint.c grprint2.c sunvdev.c X11dev.c X11devpb.c\
	  X11devla.c X11devcl.c X11devti.c X11devfs.c PSdev.c\
	  tree.c timelim.c fisheye.c infobox.c X11devfe.c \
	  X11devvw.c drawstr.c PSdevstr.c grprintstr.c X11devst.c \
	  streedebug.c

# Generated C - Files
GCFILES	 = y.tab.c lex.yy.c

# Header - Files
HFILES 	= main.h options.h alloc.h steps.h folding.h draw.h drawlib.h \
	  usrsignal.h grprint.h timing.h X11devpb.h X11devla.h\
	  X11devcl.h X11devti.h X11devfs.h PSdev.h timelim.h fisheye.h \
	  infobox.h X11devfe.h X11devvw.h drawstr.h drawchr.h

# Generated Header - Files
GHFILES	= y.tab.h grammar.h 

# Generated Other - Files
GOFILES  = grammar.l grammar.y
 
# Object - Files
OFILES	= y.tab.o lex.yy.o main.o options.o alloc.o step0.o folding.o  \
	  step1.o step2.o step3.o step4.o prepare.o draw.o             \
	  drawlib.o usrsignal.o grprint.o grprint2.o        \
	  sunvdev.o X11dev.o X11devpb.o X11devla.o X11devcl.o  \
	  X11devti.o X11devfs.o PSdev.o tree.o \
	  timelim.o fisheye.o infobox.o X11devfe.o X11devvw.o \
	  drawstr.o PSdevstr.o grprintstr.o X11devst.o

# These files are generated, but included into a distribution.
# They are in the directory preconf.
GEN_DISTFILES = $(GCFILES) $(GHFILES) $(GOFILES)


# Files we want to install by `make install'
INSTALLBINARIES = $(VCGTOOL) 


SOURCES	= grammar.pgs globals.h.tpl ultrixpreconf $(CFILES) $(HFILES)


#-------------------------- Rules ------------------------------

all: $(VCGTOOL) 

$(VCGTOOL): $(OFILES)
	$(CCLINK) $(CLINKFLAGS) $(VCGTOOL) $(OFILES) $(LIBPATH) $(LIBRARIES)  

.SUFFIXES: .c .o 

# Standard rule:
#
# If an explicit preprocessor CPP is needed
#.c.o:
#	$(CPP) $(CFLAGS) $(DFLAGS) $(INCLUDES) -DBINDIR=\"$(BINDIR)\"  \
#	  $< > tmp.c
#	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDES) tmp.c
#	$(MV) tmp.o $*.o
#	$(RM) -f tmp.c

# If no explicit preprocessor CPP is needed
.c.o:  
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDES) -DBINDIR=\"$(BINDIR)\" \
         $<

# y.tab.c \
# y.tab.h : grammar.y
# 	$(YACC) grammar.y

# lex.yy.c: grammar.l
# 	$(LEX) grammar.l \
# 	|| $(CP) preconf/lex.yy.c .


# grammar.l \
# grammar.y \
# grammar.h : grammar.pgs
# 	$(PARSEGEN) -s -t grammar.pgs \
# 	|| $(CP) preconf/grammar.l preconf/grammar.y preconf/grammar.h .

# pref:	grammar.y grammar.l grammar.h y.tab.c y.tab.h lex.yy.c
# 	$(CP) grammar.y grammar.l grammar.h y.tab.c y.tab.h lex.yy.c preconf

$(SOURCES):
	$(CHECKOUT) $@

globals.h:
	@ echo "You must configure first. See ../README."
	@ echo " "
	exit 1

# We do not install everything but only the useful tools
#
install: $(INSTALLBINARIES)
	-$(INSTALLDIR) $(BINDIR)
	for i in $(INSTALLBINARIES) ;\
	do \
	m=`echo $(INSTALL) | $(SED) -e "s/dummy/$$i/g"`; \
	$$m; \
	done

makefiles: Makefile

# Cleanup rules
#
clean: makefiles
	$(RM) -f $(OFILES) xvcg

depend: Makefile $(CFILES) $(HFILES) $(GCFILES) $(GHFILES) globals.h
	$(DEPEND) $(INCLUDES) -fMakefile $(CFILES) $(GCFILES) 

checkout: Makefile $(SOURCES)

checkedit: Makefile
	$(CHECKEDIT) $(SOURCES)

checkin: Makefile
	$(CHECKIN) $(SOURCES)

tar: Makefile $(SOURCES) $(GEN_DISTFILES)
	$(RM) -f preconf/*
	$(CP) $(GEN_DISTFILES) preconf
	tar -cf vcg.tar Makefile $(SOURCES) preconf

dist: tar


# DO NOT DELETE THIS LINE -- make depend depends on it.

main.o: /usr/include/stdio.h /usr/include/features.h
main.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
main.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
main.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
main.o: /usr/include/bits/typesizes.h /usr/include/libio.h
main.o: /usr/include/_G_config.h /usr/include/wchar.h
main.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
main.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
main.o: /usr/include/endian.h /usr/include/bits/endian.h
main.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
main.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
main.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
main.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
main.o: /usr/include/string.h /usr/include/xlocale.h globals.h
main.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
main.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
main.o: /usr/include/bits/posix2_lim.h grammar.h y.tab.h alloc.h usrsignal.h
main.o: folding.h steps.h timelim.h main.h options.h grprint.h PSdev.h
main.o: timing.h /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
main.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h /usr/include/unistd.h
main.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
main.o: /usr/include/getopt.h /usr/include/sys/time.h
main.o: /usr/include/X11/Xarch.h /usr/include/X11/Xlib.h /usr/include/X11/X.h
main.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
main.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
main.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
main.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
main.o: /usr/include/ctype.h /usr/include/math.h /usr/include/bits/huge_val.h
main.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
main.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
main.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h X11devpb.h
options.o: /usr/include/stdio.h /usr/include/features.h
options.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
options.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
options.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
options.o: /usr/include/bits/typesizes.h /usr/include/libio.h
options.o: /usr/include/_G_config.h /usr/include/wchar.h
options.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
options.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
options.o: /usr/include/endian.h /usr/include/bits/endian.h
options.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
options.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
options.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
options.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
options.o: /usr/include/string.h /usr/include/xlocale.h /usr/include/ctype.h
options.o: globals.h /usr/include/limits.h /usr/include/bits/posix1_lim.h
options.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
options.o: /usr/include/bits/posix2_lim.h main.h alloc.h fisheye.h options.h
alloc.o: /usr/include/stdio.h /usr/include/features.h
alloc.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
alloc.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
alloc.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
alloc.o: /usr/include/bits/typesizes.h /usr/include/libio.h
alloc.o: /usr/include/_G_config.h /usr/include/wchar.h
alloc.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
alloc.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
alloc.o: /usr/include/endian.h /usr/include/bits/endian.h
alloc.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
alloc.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
alloc.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
alloc.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h globals.h
alloc.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
alloc.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
alloc.o: /usr/include/bits/posix2_lim.h grammar.h y.tab.h main.h options.h
alloc.o: alloc.h folding.h
step0.o: /usr/include/stdio.h /usr/include/features.h
step0.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
step0.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
step0.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
step0.o: /usr/include/bits/typesizes.h /usr/include/libio.h
step0.o: /usr/include/_G_config.h /usr/include/wchar.h
step0.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
step0.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
step0.o: /usr/include/endian.h /usr/include/bits/endian.h
step0.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
step0.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
step0.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
step0.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
step0.o: /usr/include/string.h /usr/include/xlocale.h globals.h
step0.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
step0.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
step0.o: /usr/include/bits/posix2_lim.h grammar.h y.tab.h alloc.h main.h
step0.o: options.h folding.h fisheye.h steps.h timing.h
step1.o: /usr/include/stdio.h /usr/include/features.h
step1.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
step1.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
step1.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
step1.o: /usr/include/bits/typesizes.h /usr/include/libio.h
step1.o: /usr/include/_G_config.h /usr/include/wchar.h
step1.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
step1.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
step1.o: /usr/include/endian.h /usr/include/bits/endian.h
step1.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
step1.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
step1.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
step1.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
step1.o: /usr/include/string.h /usr/include/xlocale.h globals.h
step1.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
step1.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
step1.o: /usr/include/bits/posix2_lim.h alloc.h main.h options.h timelim.h
step1.o: folding.h steps.h timing.h
step2.o: /usr/include/stdio.h /usr/include/features.h
step2.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
step2.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
step2.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
step2.o: /usr/include/bits/typesizes.h /usr/include/libio.h
step2.o: /usr/include/_G_config.h /usr/include/wchar.h
step2.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
step2.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
step2.o: /usr/include/endian.h /usr/include/bits/endian.h
step2.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
step2.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
step2.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
step2.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
step2.o: /usr/include/string.h /usr/include/xlocale.h /usr/include/math.h
step2.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
step2.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
step2.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
step2.o: /usr/include/bits/mathcalls.h globals.h /usr/include/limits.h
step2.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
step2.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h alloc.h
step2.o: main.h options.h folding.h steps.h timelim.h timing.h
step3.o: /usr/include/stdio.h /usr/include/features.h
step3.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
step3.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
step3.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
step3.o: /usr/include/bits/typesizes.h /usr/include/libio.h
step3.o: /usr/include/_G_config.h /usr/include/wchar.h
step3.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
step3.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
step3.o: /usr/include/endian.h /usr/include/bits/endian.h
step3.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
step3.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
step3.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
step3.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
step3.o: /usr/include/string.h /usr/include/xlocale.h globals.h
step3.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
step3.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
step3.o: /usr/include/bits/posix2_lim.h alloc.h main.h options.h folding.h
step3.o: drawlib.h steps.h timelim.h timing.h
step4.o: /usr/include/stdio.h /usr/include/features.h
step4.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
step4.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
step4.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
step4.o: /usr/include/bits/typesizes.h /usr/include/libio.h
step4.o: /usr/include/_G_config.h /usr/include/wchar.h
step4.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
step4.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
step4.o: /usr/include/endian.h /usr/include/bits/endian.h
step4.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
step4.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
step4.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
step4.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
step4.o: /usr/include/string.h /usr/include/xlocale.h /usr/include/math.h
step4.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
step4.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
step4.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
step4.o: /usr/include/bits/mathcalls.h globals.h /usr/include/limits.h
step4.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
step4.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h alloc.h
step4.o: main.h options.h folding.h steps.h timelim.h timing.h
prepare.o: /usr/include/stdio.h /usr/include/features.h
prepare.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
prepare.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
prepare.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
prepare.o: /usr/include/bits/typesizes.h /usr/include/libio.h
prepare.o: /usr/include/_G_config.h /usr/include/wchar.h
prepare.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
prepare.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
prepare.o: /usr/include/endian.h /usr/include/bits/endian.h
prepare.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
prepare.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
prepare.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
prepare.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
prepare.o: /usr/include/string.h /usr/include/xlocale.h globals.h
prepare.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
prepare.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
prepare.o: /usr/include/bits/posix2_lim.h alloc.h main.h options.h folding.h
prepare.o: drawlib.h steps.h timing.h
folding.o: /usr/include/stdio.h /usr/include/features.h
folding.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
folding.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
folding.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
folding.o: /usr/include/bits/typesizes.h /usr/include/libio.h
folding.o: /usr/include/_G_config.h /usr/include/wchar.h
folding.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
folding.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
folding.o: /usr/include/endian.h /usr/include/bits/endian.h
folding.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
folding.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
folding.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
folding.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
folding.o: /usr/include/string.h /usr/include/xlocale.h globals.h
folding.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
folding.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
folding.o: /usr/include/bits/posix2_lim.h grammar.h y.tab.h alloc.h main.h
folding.o: options.h timelim.h drawlib.h folding.h steps.h
draw.o: /usr/include/stdio.h /usr/include/features.h
draw.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
draw.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
draw.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
draw.o: /usr/include/bits/typesizes.h /usr/include/libio.h
draw.o: /usr/include/_G_config.h /usr/include/wchar.h
draw.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
draw.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
draw.o: /usr/include/endian.h /usr/include/bits/endian.h
draw.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
draw.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
draw.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
draw.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h globals.h
draw.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
draw.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
draw.o: /usr/include/bits/posix2_lim.h main.h options.h alloc.h drawstr.h
draw.o: drawlib.h draw.h timing.h
drawlib.o: /usr/include/stdio.h /usr/include/features.h
drawlib.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
drawlib.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
drawlib.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
drawlib.o: /usr/include/bits/typesizes.h /usr/include/libio.h
drawlib.o: /usr/include/_G_config.h /usr/include/wchar.h
drawlib.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
drawlib.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
drawlib.o: /usr/include/endian.h /usr/include/bits/endian.h
drawlib.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
drawlib.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
drawlib.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
drawlib.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
drawlib.o: /usr/include/math.h /usr/include/bits/huge_val.h
drawlib.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
drawlib.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
drawlib.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
drawlib.o: globals.h /usr/include/limits.h /usr/include/bits/posix1_lim.h
drawlib.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
drawlib.o: /usr/include/bits/posix2_lim.h main.h options.h alloc.h grprint.h
drawlib.o: fisheye.h drawstr.h drawlib.h
usrsignal.o: /usr/include/stdio.h /usr/include/features.h
usrsignal.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
usrsignal.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
usrsignal.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
usrsignal.o: /usr/include/bits/typesizes.h /usr/include/libio.h
usrsignal.o: /usr/include/_G_config.h /usr/include/wchar.h
usrsignal.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
usrsignal.o: /usr/include/stdlib.h /usr/include/sys/types.h
usrsignal.o: /usr/include/time.h /usr/include/endian.h
usrsignal.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
usrsignal.o: /usr/include/sys/select.h /usr/include/bits/select.h
usrsignal.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
usrsignal.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
usrsignal.o: /usr/include/alloca.h globals.h /usr/include/limits.h
usrsignal.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
usrsignal.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
usrsignal.o: grammar.h y.tab.h alloc.h main.h options.h draw.h usrsignal.h
usrsignal.o: /usr/include/signal.h /usr/include/bits/signum.h
usrsignal.o: /usr/include/bits/siginfo.h /usr/include/bits/sigaction.h
usrsignal.o: /usr/include/bits/sigcontext.h /usr/include/bits/sigstack.h
usrsignal.o: /usr/include/bits/sigthread.h /usr/include/unistd.h
usrsignal.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
usrsignal.o: /usr/include/getopt.h
grprint.o: /usr/include/stdio.h /usr/include/features.h
grprint.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
grprint.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
grprint.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
grprint.o: /usr/include/bits/typesizes.h /usr/include/libio.h
grprint.o: /usr/include/_G_config.h /usr/include/wchar.h
grprint.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
grprint.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
grprint.o: /usr/include/endian.h /usr/include/bits/endian.h
grprint.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
grprint.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
grprint.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
grprint.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
grprint.o: /usr/include/string.h /usr/include/xlocale.h globals.h
grprint.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
grprint.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
grprint.o: /usr/include/bits/posix2_lim.h main.h options.h alloc.h folding.h
grprint.o: steps.h fisheye.h grprint.h
grprint2.o: /usr/include/stdio.h /usr/include/features.h
grprint2.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
grprint2.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
grprint2.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
grprint2.o: /usr/include/bits/typesizes.h /usr/include/libio.h
grprint2.o: /usr/include/_G_config.h /usr/include/wchar.h
grprint2.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
grprint2.o: /usr/include/stdlib.h /usr/include/sys/types.h
grprint2.o: /usr/include/time.h /usr/include/endian.h
grprint2.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
grprint2.o: /usr/include/sys/select.h /usr/include/bits/select.h
grprint2.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
grprint2.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
grprint2.o: /usr/include/alloca.h globals.h /usr/include/limits.h
grprint2.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
grprint2.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h draw.c
grprint2.o: main.h options.h alloc.h drawstr.h drawlib.h draw.h timing.h
grprint2.o: drawlib.c /usr/include/math.h /usr/include/bits/huge_val.h
grprint2.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
grprint2.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
grprint2.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
grprint2.o: grprint.h fisheye.h
sunvdev.o: /usr/include/stdio.h /usr/include/features.h
sunvdev.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
sunvdev.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
sunvdev.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
sunvdev.o: /usr/include/bits/typesizes.h /usr/include/libio.h
sunvdev.o: /usr/include/_G_config.h /usr/include/wchar.h
sunvdev.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
sunvdev.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
sunvdev.o: /usr/include/endian.h /usr/include/bits/endian.h
sunvdev.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
sunvdev.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
sunvdev.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
sunvdev.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
sunvdev.o: /usr/include/string.h /usr/include/xlocale.h globals.h
sunvdev.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
sunvdev.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
sunvdev.o: /usr/include/bits/posix2_lim.h
X11dev.o: /usr/include/stdio.h /usr/include/features.h
X11dev.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11dev.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11dev.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11dev.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11dev.o: /usr/include/_G_config.h /usr/include/wchar.h
X11dev.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11dev.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
X11dev.o: /usr/include/endian.h /usr/include/bits/endian.h
X11dev.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
X11dev.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
X11dev.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
X11dev.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
X11dev.o: /usr/include/string.h /usr/include/xlocale.h globals.h
X11dev.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
X11dev.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
X11dev.o: /usr/include/bits/posix2_lim.h /usr/include/X11/Xos.h
X11dev.o: /usr/include/X11/Xosdefs.h /usr/include/fcntl.h
X11dev.o: /usr/include/bits/fcntl.h /usr/include/unistd.h
X11dev.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
X11dev.o: /usr/include/getopt.h /usr/include/sys/time.h
X11dev.o: /usr/include/X11/Xarch.h /usr/include/X11/Xlib.h
X11dev.o: /usr/include/X11/X.h /usr/include/X11/Xfuncproto.h
X11dev.o: /usr/include/X11/Xutil.h /usr/include/X11/keysym.h
X11dev.o: /usr/include/X11/keysymdef.h /usr/include/X11/cursorfont.h
X11dev.o: /usr/include/X11/Xproto.h /usr/include/X11/Xmd.h
X11dev.o: /usr/include/X11/Xprotostr.h /usr/include/ctype.h
X11dev.o: /usr/include/math.h /usr/include/bits/huge_val.h
X11dev.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
X11dev.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
X11dev.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h main.h
X11dev.o: options.h alloc.h steps.h drawlib.h infobox.h draw.h folding.h
X11dev.o: grprint.h usrsignal.h fisheye.h X11devpb.h X11devla.h X11devcl.h
X11dev.o: X11devti.h X11devfe.h X11devfs.h X11devvw.h
X11devpb.o: /usr/include/stdio.h /usr/include/features.h
X11devpb.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11devpb.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11devpb.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11devpb.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11devpb.o: /usr/include/_G_config.h /usr/include/wchar.h
X11devpb.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11devpb.o: /usr/include/stdlib.h /usr/include/sys/types.h
X11devpb.o: /usr/include/time.h /usr/include/endian.h
X11devpb.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
X11devpb.o: /usr/include/sys/select.h /usr/include/bits/select.h
X11devpb.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
X11devpb.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
X11devpb.o: /usr/include/alloca.h /usr/include/string.h
X11devpb.o: /usr/include/xlocale.h globals.h /usr/include/limits.h
X11devpb.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
X11devpb.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
X11devpb.o: /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
X11devpb.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
X11devpb.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
X11devpb.o: /usr/include/bits/confname.h /usr/include/getopt.h
X11devpb.o: /usr/include/sys/time.h /usr/include/X11/Xarch.h
X11devpb.o: /usr/include/X11/Xlib.h /usr/include/X11/X.h
X11devpb.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
X11devpb.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
X11devpb.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
X11devpb.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
X11devpb.o: /usr/include/ctype.h /usr/include/math.h
X11devpb.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
X11devpb.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
X11devpb.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
X11devpb.o: /usr/include/bits/mathcalls.h main.h options.h X11devpb.h
X11devla.o: /usr/include/stdio.h /usr/include/features.h
X11devla.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11devla.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11devla.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11devla.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11devla.o: /usr/include/_G_config.h /usr/include/wchar.h
X11devla.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11devla.o: /usr/include/stdlib.h /usr/include/sys/types.h
X11devla.o: /usr/include/time.h /usr/include/endian.h
X11devla.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
X11devla.o: /usr/include/sys/select.h /usr/include/bits/select.h
X11devla.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
X11devla.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
X11devla.o: /usr/include/alloca.h /usr/include/string.h
X11devla.o: /usr/include/xlocale.h globals.h /usr/include/limits.h
X11devla.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
X11devla.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
X11devla.o: /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
X11devla.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
X11devla.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
X11devla.o: /usr/include/bits/confname.h /usr/include/getopt.h
X11devla.o: /usr/include/sys/time.h /usr/include/X11/Xarch.h
X11devla.o: /usr/include/X11/Xlib.h /usr/include/X11/X.h
X11devla.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
X11devla.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
X11devla.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
X11devla.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
X11devla.o: /usr/include/ctype.h /usr/include/math.h
X11devla.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
X11devla.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
X11devla.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
X11devla.o: /usr/include/bits/mathcalls.h main.h options.h grammar.h y.tab.h
X11devla.o: alloc.h steps.h X11devla.h
X11devcl.o: /usr/include/stdio.h /usr/include/features.h
X11devcl.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11devcl.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11devcl.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11devcl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11devcl.o: /usr/include/_G_config.h /usr/include/wchar.h
X11devcl.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11devcl.o: /usr/include/stdlib.h /usr/include/sys/types.h
X11devcl.o: /usr/include/time.h /usr/include/endian.h
X11devcl.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
X11devcl.o: /usr/include/sys/select.h /usr/include/bits/select.h
X11devcl.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
X11devcl.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
X11devcl.o: /usr/include/alloca.h /usr/include/string.h
X11devcl.o: /usr/include/xlocale.h globals.h /usr/include/limits.h
X11devcl.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
X11devcl.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
X11devcl.o: /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
X11devcl.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
X11devcl.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
X11devcl.o: /usr/include/bits/confname.h /usr/include/getopt.h
X11devcl.o: /usr/include/sys/time.h /usr/include/X11/Xarch.h
X11devcl.o: /usr/include/X11/Xlib.h /usr/include/X11/X.h
X11devcl.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
X11devcl.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
X11devcl.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
X11devcl.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
X11devcl.o: /usr/include/ctype.h /usr/include/math.h
X11devcl.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
X11devcl.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
X11devcl.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
X11devcl.o: /usr/include/bits/mathcalls.h main.h options.h grammar.h y.tab.h
X11devcl.o: alloc.h folding.h X11devcl.h
X11devti.o: /usr/include/stdio.h /usr/include/features.h
X11devti.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11devti.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11devti.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11devti.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11devti.o: /usr/include/_G_config.h /usr/include/wchar.h
X11devti.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11devti.o: /usr/include/stdlib.h /usr/include/sys/types.h
X11devti.o: /usr/include/time.h /usr/include/endian.h
X11devti.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
X11devti.o: /usr/include/sys/select.h /usr/include/bits/select.h
X11devti.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
X11devti.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
X11devti.o: /usr/include/alloca.h /usr/include/string.h
X11devti.o: /usr/include/xlocale.h globals.h /usr/include/limits.h
X11devti.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
X11devti.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
X11devti.o: /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
X11devti.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
X11devti.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
X11devti.o: /usr/include/bits/confname.h /usr/include/getopt.h
X11devti.o: /usr/include/sys/time.h /usr/include/X11/Xarch.h
X11devti.o: /usr/include/X11/Xlib.h /usr/include/X11/X.h
X11devti.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
X11devti.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
X11devti.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
X11devti.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
X11devti.o: /usr/include/ctype.h /usr/include/math.h
X11devti.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
X11devti.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
X11devti.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
X11devti.o: /usr/include/bits/mathcalls.h main.h options.h grammar.h y.tab.h
X11devti.o: alloc.h steps.h X11devti.h
X11devfs.o: /usr/include/stdio.h /usr/include/features.h
X11devfs.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11devfs.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11devfs.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11devfs.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11devfs.o: /usr/include/_G_config.h /usr/include/wchar.h
X11devfs.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11devfs.o: /usr/include/stdlib.h /usr/include/sys/types.h
X11devfs.o: /usr/include/time.h /usr/include/endian.h
X11devfs.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
X11devfs.o: /usr/include/sys/select.h /usr/include/bits/select.h
X11devfs.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
X11devfs.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
X11devfs.o: /usr/include/alloca.h /usr/include/string.h
X11devfs.o: /usr/include/xlocale.h globals.h /usr/include/limits.h
X11devfs.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
X11devfs.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
X11devfs.o: /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
X11devfs.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
X11devfs.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
X11devfs.o: /usr/include/bits/confname.h /usr/include/getopt.h
X11devfs.o: /usr/include/sys/time.h /usr/include/X11/Xarch.h
X11devfs.o: /usr/include/X11/Xlib.h /usr/include/X11/X.h
X11devfs.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
X11devfs.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
X11devfs.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
X11devfs.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
X11devfs.o: /usr/include/ctype.h /usr/include/sys/stat.h
X11devfs.o: /usr/include/bits/stat.h /usr/include/sys/param.h
X11devfs.o: /usr/include/linux/param.h /usr/include/asm/param.h
X11devfs.o: /usr/include/dirent.h /usr/include/bits/dirent.h
X11devfs.o: /usr/include/grp.h /usr/include/pwd.h /usr/include/math.h
X11devfs.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
X11devfs.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
X11devfs.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
X11devfs.o: /usr/include/bits/mathcalls.h options.h main.h grammar.h y.tab.h
X11devfs.o: X11devfs.h
PSdev.o: /usr/include/stdio.h /usr/include/features.h
PSdev.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
PSdev.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
PSdev.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
PSdev.o: /usr/include/bits/typesizes.h /usr/include/libio.h
PSdev.o: /usr/include/_G_config.h /usr/include/wchar.h
PSdev.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
PSdev.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
PSdev.o: /usr/include/endian.h /usr/include/bits/endian.h
PSdev.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
PSdev.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
PSdev.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
PSdev.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
PSdev.o: /usr/include/math.h /usr/include/bits/huge_val.h
PSdev.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
PSdev.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
PSdev.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h globals.h
PSdev.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
PSdev.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
PSdev.o: /usr/include/bits/posix2_lim.h draw.c main.h options.h alloc.h
PSdev.o: drawstr.h drawlib.h draw.h timing.h drawlib.c grprint.h fisheye.h
PSdev.o: PSdev.h
tree.o: /usr/include/stdio.h /usr/include/features.h
tree.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
tree.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
tree.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
tree.o: /usr/include/bits/typesizes.h /usr/include/libio.h
tree.o: /usr/include/_G_config.h /usr/include/wchar.h
tree.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
tree.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
tree.o: /usr/include/endian.h /usr/include/bits/endian.h
tree.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
tree.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
tree.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
tree.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
tree.o: /usr/include/string.h /usr/include/xlocale.h globals.h
tree.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
tree.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
tree.o: /usr/include/bits/posix2_lim.h alloc.h main.h options.h folding.h
tree.o: steps.h timing.h
timelim.o: /usr/include/stdio.h /usr/include/features.h
timelim.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
timelim.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
timelim.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
timelim.o: /usr/include/bits/typesizes.h /usr/include/libio.h
timelim.o: /usr/include/_G_config.h /usr/include/wchar.h
timelim.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
timelim.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
timelim.o: /usr/include/endian.h /usr/include/bits/endian.h
timelim.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
timelim.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
timelim.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
timelim.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h globals.h
timelim.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
timelim.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
timelim.o: /usr/include/bits/posix2_lim.h /usr/include/sys/time.h timelim.h
fisheye.o: /usr/include/stdio.h /usr/include/features.h
fisheye.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
fisheye.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
fisheye.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
fisheye.o: /usr/include/bits/typesizes.h /usr/include/libio.h
fisheye.o: /usr/include/_G_config.h /usr/include/wchar.h
fisheye.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
fisheye.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
fisheye.o: /usr/include/endian.h /usr/include/bits/endian.h
fisheye.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
fisheye.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
fisheye.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
fisheye.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
fisheye.o: /usr/include/math.h /usr/include/bits/huge_val.h
fisheye.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
fisheye.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
fisheye.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
fisheye.o: globals.h /usr/include/limits.h /usr/include/bits/posix1_lim.h
fisheye.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
fisheye.o: /usr/include/bits/posix2_lim.h grammar.h y.tab.h main.h options.h
fisheye.o: alloc.h steps.h fisheye.h
infobox.o: /usr/include/stdio.h /usr/include/features.h
infobox.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
infobox.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
infobox.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
infobox.o: /usr/include/bits/typesizes.h /usr/include/libio.h
infobox.o: /usr/include/_G_config.h /usr/include/wchar.h
infobox.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
infobox.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
infobox.o: /usr/include/endian.h /usr/include/bits/endian.h
infobox.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
infobox.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
infobox.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
infobox.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
infobox.o: /usr/include/math.h /usr/include/bits/huge_val.h
infobox.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
infobox.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
infobox.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
infobox.o: globals.h /usr/include/limits.h /usr/include/bits/posix1_lim.h
infobox.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
infobox.o: /usr/include/bits/posix2_lim.h main.h options.h alloc.h grprint.h
infobox.o: fisheye.h drawlib.h infobox.h
X11devfe.o: /usr/include/stdio.h /usr/include/features.h
X11devfe.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11devfe.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11devfe.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11devfe.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11devfe.o: /usr/include/_G_config.h /usr/include/wchar.h
X11devfe.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11devfe.o: /usr/include/stdlib.h /usr/include/sys/types.h
X11devfe.o: /usr/include/time.h /usr/include/endian.h
X11devfe.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
X11devfe.o: /usr/include/sys/select.h /usr/include/bits/select.h
X11devfe.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
X11devfe.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
X11devfe.o: /usr/include/alloca.h /usr/include/string.h
X11devfe.o: /usr/include/xlocale.h globals.h /usr/include/limits.h
X11devfe.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
X11devfe.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
X11devfe.o: /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
X11devfe.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
X11devfe.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
X11devfe.o: /usr/include/bits/confname.h /usr/include/getopt.h
X11devfe.o: /usr/include/sys/time.h /usr/include/X11/Xarch.h
X11devfe.o: /usr/include/X11/Xlib.h /usr/include/X11/X.h
X11devfe.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
X11devfe.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
X11devfe.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
X11devfe.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
X11devfe.o: /usr/include/ctype.h /usr/include/math.h
X11devfe.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
X11devfe.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
X11devfe.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
X11devfe.o: /usr/include/bits/mathcalls.h main.h options.h grammar.h y.tab.h
X11devfe.o: alloc.h steps.h X11devfe.h
X11devvw.o: /usr/include/stdio.h /usr/include/features.h
X11devvw.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11devvw.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11devvw.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11devvw.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11devvw.o: /usr/include/_G_config.h /usr/include/wchar.h
X11devvw.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11devvw.o: /usr/include/stdlib.h /usr/include/sys/types.h
X11devvw.o: /usr/include/time.h /usr/include/endian.h
X11devvw.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
X11devvw.o: /usr/include/sys/select.h /usr/include/bits/select.h
X11devvw.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
X11devvw.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
X11devvw.o: /usr/include/alloca.h /usr/include/string.h
X11devvw.o: /usr/include/xlocale.h globals.h /usr/include/limits.h
X11devvw.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
X11devvw.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
X11devvw.o: /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
X11devvw.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
X11devvw.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
X11devvw.o: /usr/include/bits/confname.h /usr/include/getopt.h
X11devvw.o: /usr/include/sys/time.h /usr/include/X11/Xarch.h
X11devvw.o: /usr/include/X11/Xlib.h /usr/include/X11/X.h
X11devvw.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
X11devvw.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
X11devvw.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
X11devvw.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
X11devvw.o: /usr/include/ctype.h /usr/include/math.h
X11devvw.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
X11devvw.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
X11devvw.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
X11devvw.o: /usr/include/bits/mathcalls.h main.h options.h grammar.h y.tab.h
X11devvw.o: alloc.h steps.h fisheye.h X11devvw.h
drawstr.o: /usr/include/stdio.h /usr/include/features.h
drawstr.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
drawstr.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
drawstr.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
drawstr.o: /usr/include/bits/typesizes.h /usr/include/libio.h
drawstr.o: /usr/include/_G_config.h /usr/include/wchar.h
drawstr.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
drawstr.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
drawstr.o: /usr/include/endian.h /usr/include/bits/endian.h
drawstr.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
drawstr.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
drawstr.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
drawstr.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
drawstr.o: /usr/include/math.h /usr/include/bits/huge_val.h
drawstr.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
drawstr.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
drawstr.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
drawstr.o: globals.h /usr/include/limits.h /usr/include/bits/posix1_lim.h
drawstr.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
drawstr.o: /usr/include/bits/posix2_lim.h main.h options.h alloc.h grprint.h
drawstr.o: fisheye.h drawlib.h drawstr.h drawchr.h
PSdevstr.o: /usr/include/stdio.h /usr/include/features.h
PSdevstr.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
PSdevstr.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
PSdevstr.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
PSdevstr.o: /usr/include/bits/typesizes.h /usr/include/libio.h
PSdevstr.o: /usr/include/_G_config.h /usr/include/wchar.h
PSdevstr.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
PSdevstr.o: /usr/include/stdlib.h /usr/include/sys/types.h
PSdevstr.o: /usr/include/time.h /usr/include/endian.h
PSdevstr.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
PSdevstr.o: /usr/include/sys/select.h /usr/include/bits/select.h
PSdevstr.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
PSdevstr.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
PSdevstr.o: /usr/include/alloca.h /usr/include/math.h
PSdevstr.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
PSdevstr.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
PSdevstr.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
PSdevstr.o: /usr/include/bits/mathcalls.h globals.h /usr/include/limits.h
PSdevstr.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
PSdevstr.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
PSdevstr.o: drawstr.c main.h options.h alloc.h grprint.h fisheye.h drawlib.h
PSdevstr.o: drawstr.h drawchr.h PSdev.h
grprintstr.o: /usr/include/stdio.h /usr/include/features.h
grprintstr.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
grprintstr.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
grprintstr.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
grprintstr.o: /usr/include/bits/typesizes.h /usr/include/libio.h
grprintstr.o: /usr/include/_G_config.h /usr/include/wchar.h
grprintstr.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
grprintstr.o: /usr/include/stdlib.h /usr/include/sys/types.h
grprintstr.o: /usr/include/time.h /usr/include/endian.h
grprintstr.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
grprintstr.o: /usr/include/sys/select.h /usr/include/bits/select.h
grprintstr.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
grprintstr.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
grprintstr.o: /usr/include/alloca.h globals.h /usr/include/limits.h
grprintstr.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
grprintstr.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
grprintstr.o: drawstr.c /usr/include/math.h /usr/include/bits/huge_val.h
grprintstr.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
grprintstr.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
grprintstr.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
grprintstr.o: main.h options.h alloc.h grprint.h fisheye.h drawlib.h
grprintstr.o: drawstr.h drawchr.h
X11devst.o: /usr/include/stdio.h /usr/include/features.h
X11devst.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
X11devst.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
X11devst.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
X11devst.o: /usr/include/bits/typesizes.h /usr/include/libio.h
X11devst.o: /usr/include/_G_config.h /usr/include/wchar.h
X11devst.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
X11devst.o: /usr/include/stdlib.h /usr/include/sys/types.h
X11devst.o: /usr/include/time.h /usr/include/endian.h
X11devst.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
X11devst.o: /usr/include/sys/select.h /usr/include/bits/select.h
X11devst.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
X11devst.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
X11devst.o: /usr/include/alloca.h /usr/include/string.h
X11devst.o: /usr/include/xlocale.h globals.h /usr/include/limits.h
X11devst.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
X11devst.o: /usr/include/linux/limits.h /usr/include/bits/posix2_lim.h
X11devst.o: /usr/include/X11/Xos.h /usr/include/X11/Xosdefs.h
X11devst.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
X11devst.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
X11devst.o: /usr/include/bits/confname.h /usr/include/getopt.h
X11devst.o: /usr/include/sys/time.h /usr/include/X11/Xarch.h
X11devst.o: /usr/include/X11/Xlib.h /usr/include/X11/X.h
X11devst.o: /usr/include/X11/Xfuncproto.h /usr/include/X11/Xutil.h
X11devst.o: /usr/include/X11/keysym.h /usr/include/X11/keysymdef.h
X11devst.o: /usr/include/X11/cursorfont.h /usr/include/X11/Xproto.h
X11devst.o: /usr/include/X11/Xmd.h /usr/include/X11/Xprotostr.h
X11devst.o: /usr/include/ctype.h /usr/include/math.h
X11devst.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
X11devst.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
X11devst.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
X11devst.o: /usr/include/bits/mathcalls.h main.h options.h alloc.h grprint.h
X11devst.o: drawlib.h fisheye.h drawchr.h
y.tab.o: /usr/include/string.h /usr/include/features.h
y.tab.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
y.tab.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
y.tab.o: /usr/include/gnu/stubs-32.h /usr/include/xlocale.h
y.tab.o: /usr/include/stdio.h /usr/include/bits/types.h
y.tab.o: /usr/include/bits/typesizes.h /usr/include/libio.h
y.tab.o: /usr/include/_G_config.h /usr/include/wchar.h
y.tab.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
y.tab.o: /usr/include/ctype.h /usr/include/endian.h
y.tab.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
y.tab.o: /usr/include/math.h /usr/include/bits/huge_val.h
y.tab.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
y.tab.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
y.tab.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h globals.h
y.tab.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
y.tab.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
y.tab.o: /usr/include/bits/posix2_lim.h main.h options.h
y.tab.o: /usr/include/malloc.h
lex.yy.o: /usr/include/stdio.h /usr/include/features.h
lex.yy.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
lex.yy.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
lex.yy.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
lex.yy.o: /usr/include/bits/typesizes.h /usr/include/libio.h
lex.yy.o: /usr/include/_G_config.h /usr/include/wchar.h
lex.yy.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
lex.yy.o: /usr/include/string.h /usr/include/xlocale.h y.tab.h
lex.yy.o: /usr/include/ctype.h /usr/include/endian.h
lex.yy.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lex.yy.o: /usr/include/math.h /usr/include/bits/huge_val.h
lex.yy.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
lex.yy.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
lex.yy.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h globals.h
lex.yy.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
lex.yy.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
lex.yy.o: /usr/include/bits/posix2_lim.h main.h options.h
lex.yy.o: /usr/include/malloc.h
