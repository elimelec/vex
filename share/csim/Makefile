# Generated automatically from Makefile.in by configure.
###
### Copyright (C) 1992-2004 Hewlett-Packard Company.
###

### $Id: Makefile.in,v 1.6 2009/12/16 16:15:35 frb Exp $

#####################################
## VEX installation root

srcdir = .

prefix = /home/frb/rpmbuild/BUILDROOT/vex-3.43-1.i386/opt/vex
exec_prefix = ${prefix}
libdir = ${exec_prefix}/lib
bindir = ${exec_prefix}/bin

SH = /bin/sh
INSTALL = /usr/bin/install -c

#####################################
CRT0 = crt0_linux.o
LIBC = $(shell ls /lib/libc.so.*| tail -1)
CSOBJS = cs_vex.o gprof_vex.o linux_support.o
CSHEADERS = cs_header.h cs_vex.h gmon.h gmon_out.h gprof_vex.h
INCLUDES = -I.
CFLAGS = -m32 -O3 -static -fomit-frame-pointer

#####################################
.PHONY: all install clean distclean

all:	ldcs.a as ld $(CRT0)

ldcs.a: $(CSOBJS)
	$(AR) $(ARFLAGS) $@ $(CSOBJS)

as: as.sh
	$(RM) $@; sed -e"s,@shell@,$(SH),g" $(srcdir)/as.sh > $@

ld: ld.sh
	$(RM) $@; sed -e"s,@shell@,$(SH),g" $(srcdir)/ld.sh > $@

cs_vex.o: cs_vex.c $(CSHEADERS)

gprof_vex.o: gprof_vex.c $(CSHEADERS) gmon.h gmon_out.h
	$(CC) $(CFLAGS) $(DEFS) $(INCLUDES) -c $(srcdir)/gprof_vex.c

linux_support.o: linux_support.c
	$(CC) $(CFLAGS) -DLIBC_NAME="\"$(LIBC)\"" -c $(srcdir)/linux_support.c

crt0_linux.o: crt0_linux.c

#####################################
### Install

install: ldcs.a $(CRT0) as ld
	mkdir -p $(libdir) $(bindir)
	$(INSTALL) -m 755 as $(bindir)
	$(INSTALL) -m 755 ld $(bindir)
	$(INSTALL) -m 644 ldcs.a $(libdir)
	$(INSTALL) -m 644 $(CRT0) $(libdir)/crt0.o

clean:
	$(RM) as ld ldcs.a $(CRT0) *.o

distclean: clean
	$(RM) Makefile config.* 

#####################################
#### Rules

.c.o:
	@$(RM) $@; $(CC) $(CFLAGS) $(DEFS) $(INCLUDES) -c $<

