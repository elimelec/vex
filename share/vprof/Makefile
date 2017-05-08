#   static and dynamic profiling information on VEX execution 
#              in terms of number of operations
#   developer: MARCO PAOLIERI (marco.paolieri@gmail.com)
#   last update: 12-02-07

VEX = /opt/vex
CC = $(VEX)/bin/cc
CFLAGS = -ms -mas_g
HOST_CC = gcc
HOST_G++ = g++

all: testfilter
FILTEROBJS = testfilter.o filterlib.o

testfilter: $(FILTEROBJS)
	$(CC) $(CFLAGS) -o $@ $(FILTEROBJS)

as-filter: as-filter.sh add_profiling.lex
	sed -e 's:@VEXROOT@:$(VEX):' as-filter.sh > as-filter; \
	chmod +x as-filter
	flex add_profiling.lex
	$(HOST_G++) lex.yy.c -o add_profiling
	chmod +x add_profiling 

testfilter.o: testfilter.c as-filter
	$(CC) $(CFLAGS) -Ta./as-filter -c -o $@ $<

filterlib.o: filterlib.c
	$(HOST_CC) -c -g $<
###############################################################
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(FILTEROBJS) testfilter 
	rm -f trace.txt filter.txt as-filter add_profiling
	rm -f *.s test *.cs.* gmon* *.log ta.log.*
	rm -f lex.yy.c
	rm -f dyn_prof_*
	rm -f static_prof_*