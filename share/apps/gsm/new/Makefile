CC = /opt/vex/bin/cc
HOST_CC = gcc
ENDIAN = big


ifeq ("$(MM)","vex-base")
CFLAGS =
LFLAG = 
ASMLIB =
endif

ifeq ("$(MM)","vex-opt")
CFLAGS = -mfinline -DBASIC_OP_INLINE
LFLAG = 
ASMLIB =
endif

ifeq ("$(MM)","vex-asm")
CFLAGS = -mfinline -DBASIC_OP_INLINE -DVEX_ASM_BASICOP
LFLAG = 
ASMLIB = vex_asm_simlib.o
endif

CFLAGS += -O3 -ms -mas_G
#CFLAGS += -O3 -ms

ifeq ("$(MM)","gcc")
CC = gcc
CFLAGS = -O3 -pg
ASMLIB =
ENDIAN = little
endif

CFLAGS += $(XCFLAGS)

# Objects
OBJ =  coder.o cod_12k2.o az_lsp.o autocorr.o convolve.o c1035pf.o basicop2.o \
       pitch_ol.o pitch_f6.o enc_lag6.o g_pitch.o residu.o count.o weight_a.o \
       q_gains.o g_code.o pred_lt6.o copy.o levinson.o lag_wind.o prm2bits.o \
       syn_filt.o int_lpc.o q_plsf_5.o set_zero.o log2.o pow2.o oper_32b.o \
       lsp_lsf.o reorder.o lsp_az.o inv_sqrt.o inter_6.o pre_proc.o n_proc.o \
       vad.o dtx.o e_homing.o \
       $(ASMLIB)

DOBJ = decoder.o dec_12k2.o basicop2.o pstfilt2.o pred_lt6.o dec_lag6.o \
       int_lpc.o count.o weight_a.o agc.o set_zero.o preemph.o residu.o \
       syn_filt.o copy.o bits2prm.o reorder.o lsp_az.o inv_sqrt.o d_plsf_5.o \
       d_gains.o d1035pf.o log2.o pow2.o oper_32b.o lsp_lsf.o n_proc.o dtx.o \
       d_homing.o \
       $(ASMLIB)

ED_IOBJ = ed_iface.o dtx.o count.o basicop2.o $(ASMLIB)

all:    coder decoder ed_iface

test:   all
	cd ../run; ./tst $(ENDIAN)

#######################################################
# Explicit Rules
#######################################################
coder:    $(OBJ)
	$(CC) $(LFLAG) -o coder $(CFLAGS) $(OBJ)
decoder:  $(DOBJ)
	$(CC) $(LFLAG) -o decoder $(CFLAGS) $(DOBJ)
ed_iface: $(ED_IOBJ)
	$(CC) $(LFLAG) -o ed_iface $(CFLAGS) $(ED_IOBJ)

#######################################################
## Custom ASM simulation library 
#######################################################
vex_asm_simlib.o: vex_asm_simlib.c
	$(HOST_CC) -c $<

.c.o:
	$(CC) $(CFLAGS)  -c  $<

clean:
	$(RM) coder decoder ed_iface
	$(RM) *.[os] *.cs.*

cleanall: clean
	$(RM) ta.log.* gmon.*


depend:
	makedepend -Y -I. *.[ch]


# DO NOT DELETE

agc.o: typedef.h basic_op.h basic_op_inline.h count.h sig_proc.h cnst.h
autocorr.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h cnst.h
az_lsp.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h cnst.h
az_lsp.o: grid.tab
bits2prm.o: typedef.h basic_op.h basic_op_inline.h count.h
c1035pf.o: typedef.h basic_op.h basic_op_inline.h sig_proc.h count.h
cod_12k2.o: typedef.h basic_op.h basic_op_inline.h sig_proc.h count.h codec.h
cod_12k2.o: cnst.h window2.tab vad.h dtx.h
coder.o: typedef.h basic_op.h basic_op_inline.h sig_proc.h count.h codec.h
coder.o: cnst.h n_stack.h e_homing.h dtx.h
convolve.o: typedef.h basic_op.h basic_op_inline.h count.h
copy.o: typedef.h basic_op.h basic_op_inline.h count.h
count.o: typedef.h count.h
d1035pf.o: typedef.h basic_op.h basic_op_inline.h count.h
dec_12k2.o: typedef.h basic_op.h basic_op_inline.h sig_proc.h count.h codec.h
dec_12k2.o: cnst.h dtx.h
dec_lag6.o: typedef.h basic_op.h basic_op_inline.h count.h
decoder.o: typedef.h n_stack.h basic_op.h basic_op_inline.h sig_proc.h
decoder.o: count.h codec.h cnst.h d_homing.h
d_gains.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
d_gains.o: sig_proc.h gains_tb.h cnst.h dtx.h
d_homing.o: typedef.h cnst.h dtx.h codec.h d_homing.h q_plsf_5.tab
d_plsf_5.o: typedef.h basic_op.h basic_op_inline.h count.h sig_proc.h
d_plsf_5.o: q_plsf_5.tab cnst.h dtx.h
dtx.o: typedef.h basic_op.h basic_op_inline.h cnst.h sig_proc.h count.h dtx.h
ed_iface.o: typedef.h cnst.h dtx.h
e_homing.o: typedef.h cnst.h vad.h dtx.h codec.h sig_proc.h e_homing.h
enc_lag6.o: typedef.h basic_op.h basic_op_inline.h count.h
g_code.o: typedef.h basic_op.h basic_op_inline.h count.h cnst.h
g_pitch.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
g_pitch.o: sig_proc.h
inter_6.o: typedef.h basic_op.h basic_op_inline.h count.h
int_lpc.o: typedef.h basic_op.h basic_op_inline.h count.h sig_proc.h
inv_sqrt.o: typedef.h basic_op.h basic_op_inline.h count.h inv_sqrt.tab
lag_wind.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
lag_wind.o: lag_wind.tab
levinson.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
log2.o: typedef.h basic_op.h basic_op_inline.h count.h log2.tab
lsp_az.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
lsp_az.o: sig_proc.h
lsp_lsf.o: typedef.h basic_op.h basic_op_inline.h count.h lsp_lsf.tab
oper_32b.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
pitch_f6.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
pitch_f6.o: sig_proc.h codec.h
pitch_ol.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
pitch_ol.o: sig_proc.h
pow2.o: typedef.h basic_op.h basic_op_inline.h count.h pow2.tab
pred_lt6.o: typedef.h basic_op.h basic_op_inline.h count.h
preemph.o: typedef.h basic_op.h basic_op_inline.h count.h
pre_proc.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
prm2bits.o: typedef.h basic_op.h basic_op_inline.h count.h
pstfilt2.o: typedef.h basic_op.h basic_op_inline.h sig_proc.h count.h codec.h
pstfilt2.o: cnst.h
q_gains.o: typedef.h basic_op.h basic_op_inline.h oper_32b.h count.h
q_gains.o: sig_proc.h gains_tb.h cnst.h dtx.h
q_plsf_5.o: typedef.h basic_op.h basic_op_inline.h count.h sig_proc.h cnst.h
q_plsf_5.o: dtx.h q_plsf_5.tab
reorder.o: typedef.h basic_op.h basic_op_inline.h count.h
residu.o: typedef.h basic_op.h basic_op_inline.h count.h
set_zero.o: typedef.h basic_op.h basic_op_inline.h count.h
syn_filt.o: typedef.h basic_op.h basic_op_inline.h count.h
vad.o: typedef.h cnst.h basic_op.h basic_op_inline.h oper_32b.h count.h vad.h
weight_a.o: typedef.h basic_op.h basic_op_inline.h count.h
