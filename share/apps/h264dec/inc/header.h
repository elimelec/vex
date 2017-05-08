/*!
 *************************************************************************************
 * \file header.h
 *
 * \brief
 *    Prototypes for header.c
 *************************************************************************************
 */

#ifndef _HEADER_H_
#define _HEADER_H_

int FirstPartOfSliceHeader(Slice *currSlice);
int RestOfSliceHeader     (Slice *currSlice);

void dec_ref_pic_marking(Bitstream *currStream);

void decode_poc(ImageParameters *img);
int dumppoc(ImageParameters *img);

#endif

