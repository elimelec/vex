
/*!
 ************************************************************************
 * \file vlc.h
 *
 * \brief
 *    header for (CA)VLC coding functions
 *
 * \author
 *    Karsten Suehring
 *
 ************************************************************************
 */

#ifndef _VLC_H_
#define _VLC_H_

int se_v (char *tracestring, Bitstream *bitstream);
int ue_v (char *tracestring, Bitstream *bitstream);
Boolean u_1 (char *tracestring, Bitstream *bitstream);
int u_v (int LenInBits, char *tracestring, Bitstream *bitstream);
int i_v (int LenInBits, char *tracestring, Bitstream *bitstream);

// UVLC mapping
void linfo_ue(int len, int info, int *value1, int *dummy);
void linfo_se(int len, int info, int *value1, int *dummy);

void linfo_cbp_intra(int len,int info,int *cbp, int *dummy);
void linfo_cbp_inter(int len,int info,int *cbp, int *dummy);
void linfo_levrun_inter(int len,int info,int *level,int *irun);
void linfo_levrun_c2x2(int len,int info,int *level,int *irun);

int  uvlc_startcode_follows(Slice *currSlice, int dummy);

int  readSyntaxElement_VLC (SyntaxElement *sym, Bitstream *currStream);
int  readSyntaxElement_UVLC(SyntaxElement *sym, ImageParameters *img, struct datapartition *dp);
int  readSyntaxElement_Intra4x4PredictionMode(SyntaxElement *sym, ImageParameters *img, Bitstream   *currStream);

int  GetVLCSymbol (byte buffer[],int totbitoffset,int *info, int bytecount);
int  GetVLCSymbol_IntraMode (byte buffer[],int totbitoffset,int *info, int bytecount);

int readSyntaxElement_FLC                         (SyntaxElement *sym, Bitstream *currStream);
int readSyntaxElement_NumCoeffTrailingOnes(SyntaxElement *sym,  Bitstream *currStream,
                                           char *type);
int readSyntaxElement_NumCoeffTrailingOnesChromaDC(SyntaxElement *sym, Bitstream *currStream);
int readSyntaxElement_Level_VLC0                  (SyntaxElement *sym, Bitstream *currStream);
int readSyntaxElement_Level_VLCN                  (SyntaxElement *sym, int vlc, Bitstream *currStream);
int readSyntaxElement_TotalZeros                  (SyntaxElement *sym, Bitstream *currStream);
int readSyntaxElement_TotalZerosChromaDC          (SyntaxElement *sym, Bitstream *currStream);
int readSyntaxElement_Run                         (SyntaxElement *sym, Bitstream *currStream);
int GetBits (byte buffer[],int totbitoffset,int *info, int bitcount,
             int numbits);
int ShowBits (byte buffer[],int totbitoffset,int bitcount, int numbits);

int more_rbsp_data (byte buffer[],int totbitoffset,int bytecount);


#endif

