VEX = /opt/vex
CC = $(VEX)/bin/cc

CFLAGS = -ms -mas_g -DUSE_ASM -prefetch -fmm=vex16.mm
#CFLAGS = -ms -mas_g -c99inline -prefetch -fmm=vex16.mm

HOST_CC = gcc

all: testapi testasm testfilter count_ones

###############################################################
APIOBJS = testapi.o cachelib.o

testapi: $(APIOBJS)
	$(CC) $(CFLAGS) -o $@ $(APIOBJS)

testapi.o: testapi.c

cachelib.o: cachelib.c
	$(HOST_CC) -c -g $<

###############################################################
FILTEROBJS = testfilter.o filterlib.o

testfilter: $(FILTEROBJS)
	$(CC) $(CFLAGS) -o $@ $(FILTEROBJS)

as-filter: as-filter.sh
	sed -e 's:@VEXROOT@:$(VEX):' as-filter.sh > as-filter; \
	chmod +x as-filter

testfilter.o: testfilter.c as-filter
	$(CC) $(CFLAGS) -Taas-filter -c -o $@ $<

filterlib.o: filterlib.c
	$(HOST_CC) -c -g $<

###############################################################
ASMOBJS = testasm.o asmlib.o

testasm: $(ASMOBJS)
	$(CC) $(CFLAGS) -o $@ $(ASMOBJS)

testasm.o: testasm.c

asmlib.o: asmlib.c
	$(HOST_CC) -c -g $<

ASMOBJS = testasm.o asmlib.o

###############################################################
COUNTOBJS = count_ones.o asmlib.o 

count_ones.o: count_ones.c

count_ones: $(COUNTOBJS)
	$(CC) $(CFLAGS) -o $@ $(COUNTOBJS)

###############################################################
test: testasm testapi testfilter
	@echo "Running testasm..."; ./testasm > testasm.log 2>&1
	@echo "Running testapi..."; ./testapi > testapi.log 2>&1
	@echo "Running testfilter..."; ./testfilter > testfilter.log 2>&1

###############################################################
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(ASMOBJS) $(APIOBJS) $(FILTEROBJS) $(COUNTOBJS) testfilter testapi testasm 
	rm -f trace.txt filter.txt as-filter
	rm -f *.s test *.cs.* gmon* *.log ta.log.*
