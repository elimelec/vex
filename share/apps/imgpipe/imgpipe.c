/**
*** Copyright (C) 1995-2005 Hewlett-Packard Company.
*** See "LICENSE.txt" for license terms
**/

#include <stdio.h>
#include <stdlib.h>

#include "jpeg/jpeglib.h"
#include "imgpipe.h"
#include "dither.h"
#include "wppm.h"
#include "csc.h"
#include "resize.h"

#define NLINES 8

static int imgpipe(FILE *, FILE *, int);
static void* xmalloc(size_t, char *);

/**/

static void* xmalloc(size_t size, char *msg)
{
    void *ptr = calloc(4,(size+3)/4);
    if (!ptr) {
        fprintf(stderr, "Error: can't allocate %s (%d)\n", msg, size);
	exit(1);
    }
    return ptr;
}

static int imgpipe(FILE *infile, FILE *outfile, int scale)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    ubyte *outrow_buffer1 = NULL;
    ubyte *outrow_buffer2 = NULL;
    ubyte **inrow_buffer = NULL;
    int in_width, in_height, out_width, out_height, in_size;
    int in_components, out_components;
    int row, i;

    out_components = 4; /* CMYK always */

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    in_width = cinfo.output_width;
    in_height = cinfo.output_height;
    in_components = cinfo.output_components;

    in_size = in_width * in_components;
    inrow_buffer = (ubyte **) xmalloc(NLINES * sizeof(ubyte*),"inrow_buffer");
    for (i = 0; i < NLINES; ++i) {
        inrow_buffer[i] = (ubyte *) xmalloc(in_size * sizeof(ubyte),
		                            "inrow_buffer[]");
    }

    out_width = in_width * scale;
    out_height = in_height * scale;

    outrow_buffer1 = (ubyte *) xmalloc(out_width * out_components * sizeof(ubyte), 
	                               "outrow_buffer1");
    outrow_buffer2 = (ubyte *) xmalloc(out_width * out_components * sizeof(ubyte),
	                               "outrow_buffer2");

    /*****************************************************************************************/
    row = 0;
    open_ppm(out_width, out_height, outfile);
    dither_init(out_width);
    rgb_to_cmyk_init();
    while (cinfo.output_scanline < in_height) {
	int scanlines = jpeg_read_scanlines(&cinfo, inrow_buffer, NLINES);
	int line = 0;
        if (row == 0) 
	    resize_init(inrow_buffer[0], in_width, scale);
	for (; line < scanlines; ++line) {
	    ubyte *inbuf = inrow_buffer[line];
	    int more_scanlines;
	    do {
                more_scanlines = resize(outrow_buffer1, inbuf, in_width, scale);
#ifdef JAMMED
	        rgb_to_cmyk_and_dither(outrow_buffer2, outrow_buffer1, out_width);
	        write_ppm_row(outrow_buffer2, out_width, outfile);
#else
	        rgb_to_cmyk(outrow_buffer2, outrow_buffer1, out_width);
		dither(outrow_buffer1, outrow_buffer2, out_width);
	        write_ppm_row(outrow_buffer1, out_width, outfile);
#endif
		row++;
	    } while (more_scanlines == 0);
	}
    }
    resize_finish();
    dither_finish();

    close_ppm(outfile);
    /*****************************************************************************************/

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    for (i = 0; i < NLINES; ++i) {
        free(inrow_buffer[i]);
    }
    free(inrow_buffer);
    free(outrow_buffer1);
    free(outrow_buffer2);

    return 0;
}

static void usage(const char *progname)
{
    fprintf(stderr,
	    "Usage: %s [-o fileout.ppm] [-s int_scale] filein.jpg\n",
	    progname);
    exit(1);
}

extern int main(int argc, char **argv)
{
    FILE *infile = NULL;
    FILE *outfile = stdout;
    int status;
    int scale = 1;
    int arg = 1;

    if (argc < 2)
        usage(argv[0]);

    while (arg < argc) {
	int c = argv[arg][0];
	if (c == '-') {
	    c = argv[arg][1];
	    switch (c) {
	    case 's':
		sscanf(argv[++arg], "%d", &scale);
		break;
	    case 'o': {
		    const char *fileout = argv[++arg];
		    if ((outfile = fopen(fileout, "wb")) == NULL) {
			fprintf(stderr, "can't open %s\n", fileout);
			return 1;
		    }
		}
		break;
	    default:
		break;
	    }
	}
	else if (!infile) {
	    const char *filein = argv[arg];
	    if ((infile = fopen(filein, "rb")) == NULL) {
		fprintf(stderr, "can't open %s\n", filein);
		return 1;
	    }
	}
	else 
            usage(argv[0]);
	++arg;
    }

    status = imgpipe(infile, outfile, scale);

    fclose(infile);
    fclose(outfile);
    return status;
}
