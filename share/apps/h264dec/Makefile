###
###     Makefile for H.264/AVC decoder
###
###             generated for UNIX/LINUX environments
###             by H. Schwarz, Limin Wang
###

NAME=   ldecod

### include debug information: 1=yes, 0=no
DBG?= 0
### Generate 32 bit executable : 1=yes, 0=no
M32?= 0
### include O level optimization : 0-3
OPT?= 3
### Static Compilation
STC?= 0

DEPEND= dependencies

BINDIR= .
INCDIR= inc
SRCDIR= src
OBJDIR= obj

# CC=/home/opt/vex/vex-3.42/bin/cc
CC=/home/frb/vex/build/image/be/bin/cc
CFLAGS= -O3 -mfinline -ms -mP1COPT_inline_limit=1000000 -mas_G -ms -mas_g
# CFLAGS= -O3 -mas_G -ms -mas_g
# CC = gcc
# CFLAGS = -O2 -g
LIBS= -lm
FLAGS=  $(CFLAGS) -I$(INCDIR)

OPT_FLAG = -O$(OPT)
ifeq ($(DBG),1)
SUFFIX= .dbg
FLAGS+= -g
else
SUFFIX=
FLAGS+= $(OPT_FLAG)
endif

OBJSUF= .o$(SUFFIX)

SRC=    $(wildcard $(SRCDIR)/*.c) 
ADDSRC= $(wildcard $(ADDSRCDIR)/*.c)
OBJ=    $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o$(SUFFIX)) $(ADDSRC:$(ADDSRCDIR)/%.c=$(OBJDIR)/%.o$(SUFFIX)) 
BIN=    $(BINDIR)/$(NAME)$(SUFFIX).exe

.PHONY: default distclean clean depend

default: messages objdir_mk depend bin 

messages:
ifeq ($(M32),1)
	@echo 'Compiling with M32 support...'
endif
ifeq ($(DBG),1)
	@echo 'Compiling with Debug support...'
	@echo 'Note static compilation not supported in this mode.'
endif
ifeq ($(STC),1)
	@echo 'Compiling with -static support...'
endif

clean:
	@echo remove all objects
	@rm -rf $(OBJDIR) *.s *.cs.c ta.log.* $(BIN)

bin:    $(OBJ)
	@echo
	@echo 'creating binary "$(BIN)"'
	@$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LIBS)
	@echo '... done'
	@echo

depend:
	echo 'checking dependencies'; \
	$(SHELL) -ec '$(CC) $(AFLAGS) -MM $(CFLAGS) -I$(INCDIR) $(SRC) $(ADDSRC)                  \
         | sed '\''s@\(.*\)\.o[ :]@$(OBJDIR)/\1.o$(SUFFIX):@g'\''               \
         >$(DEPEND)'; \

$(OBJDIR)/%.o$(SUFFIX): $(SRCDIR)/%.c
	@echo 'compiling object file "$@" ...'
	$(CC) -c -o $@ $(FLAGS) $<

$(OBJDIR)/%.o$(SUFFIX): $(ADDSRCDIR)/%.c
	@echo 'compiling object file "$@" ...'
	$(CC) -c -o $@ $(FLAGS) $<

objdir_mk:
	@echo 'Creating $(OBJDIR) ...'
	@mkdir -p $(OBJDIR)

test: $(BIN)
	cd test; ../$(BIN) tiny.cfg

-include $(DEPEND)

