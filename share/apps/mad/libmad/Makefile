CFLAGS += $(XCFLAGS) -DFPM_DEFAULT -DASO_ZEROCHECK

LIB=bit.o decoder.o fixed.o frame.o huffman.o layer12.o layer3.o stream.o synth.o timer.o version.o
libmad.a: $(LIB)
	ar r libmad.a $(LIB)

clean:
	/bin/rm -f *.a *.s *.o
