
# CC = ../build.cs/image/be/bin/cc
CC = gcc
CFLAGS = -O -g
LDFLAGS = -O -g
YACC = bison --yacc
YFLAGS = -d
LEX = flex
VEX = /opt/vex

OBJS = grammar.o lex.o main.o

vexasm: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

grammar.c: grammar.y

grammar.o: grammar.y vextypes.h

lex.c: lex.l

lex.o: grammar.o lex.l grammar.y vextypes.h vexopc.h

main.o: grammar.y vextypes.h main.c

clean:
	rm -f $(OBJS) grammar.[ch] lex.c vexasm

test: vexasm test.s
	./vexasm test.s

test.s: grammar.c
	$(RM) test.s; \
	$(VEX)/bin/cc -o test.s -O -S $<


.y.c:
	$(YACC) $(YFLAGS) $<
	mv -f y.tab.c $*.c
	mv -f y.tab.h $*.h

.l.c:
	$(LEX) $<
	mv -f lex.yy.c $*.c

.c.o:
	$(CC) $(CFLAGS) $(DEFS) $(INCLUDES) -c $<

