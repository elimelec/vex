CC=/home/opt/vex/vex-3.42/bin/cc 
CFLAGS=-DHAVE_CONFIG_H -I. -Ilibmad -Iintl -O3 -ms -mas_G -autoinline

# CC=gcc
# CFLAGS=-DHAVE_CONFIG_H -I. -Ilibmad -Iintl -O2

# madtime.o \
# minimad.o \
#
# mad123.o \
# madmix.o \

OBJS= \
    audio.o \
    audio_hex.o \
    audio_null.o \
    audio_raw.o \
    audio_snd.o \
    audio_wave.o \
    equalizer.o \
    filter.o \
    getopt.o \
    getopt1.o \
    id3.o \
    id3v2.o \
    madplay.o \
    player.o \
    resample.o \
    version.o

madplay: $(OBJS) libmad/libmad.a
	$(CC) -o madplay $(OBJS) libmad/libmad.a -lm

libmad/libmad.a:
	cd libmad; make CC="$(CC)" XCFLAGS="$(CFLAGS)"

clean:
	/bin/rm -f *.a *.s *.o ta.log.* gmon* gflat* madplay ; \
	cd libmad; make clean

test: madplay
	./madplay -v test.mp3 -s 10 -t 0:0:10 -o test.out.pcm; \
	diff test.out.pcm test.pcm
