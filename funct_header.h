#include "structures.h"

#ifndef FUNCT_HEADER_H_INCLUDED
#define FUNCT_HEADER_H_INCLUDED

char *find_sfid(long sfid_indx, int *chArryPtr);            /* Find the SFID field using integer search. */
char *find_sfid_char(long sfid_indx, char *chArryPtr);      /* Find the SFID field using character search. */
long find_i_dat_len(long i_dat_len_indx, char *chArryPtr);  /* Find i data length. */
int chkZhdrMtch(char *zHdr); /* Check if we have Z header. */
char *findZlenStr(char *chArryPtr, int z_sfdu_dat_len_indx); /* Find the z packet length. */
int chkConfSfid(char *i_sfid_ptr);  /* Check if sfid is CONF. */
int chkCh1Sfid(char *i_sfid_ptr);   /* Check if sfid is CH1. */
int chkCh2Sfid(char *i_sfid_ptr);   /* Check if sfid is CH2. */
int chkChxSfid(char *i_sfid_ptr, int ch); /* Generic check for Channel sfid. */
long saveChxDat(char *chArry, long i_dat_indx, long i_dat_len, FILE *msoChxFptr, long i); /* Save channel 1 data and returns i. */
/* Takes care of MSO packets. */
long chkMsoSfid(char *i_sfid_ptr, char *chArry, long i_dat_indx, long i_dat_len, FILE *confFptr, FILE *msoCh1Fptr, FILE *msoCh2Fptr, FILE *msoCh3Fptr, FILE *msoCh4Fptr, long i);
iPktParms findIPktParms(long i_hdr_indx, char *chArry, long i);

//spwData *saveRumhDat(char *chArry, long i_dat_indx, long i_dat_len, long i); /* Save space wire RUMH data for later use. */
char *find_rumh_data(long sfid_indx, char *chArryPtr); /* Find RUMH data. */
int chkRumhSfid(char *i_sfid_ptr); /* Check for space wire RUMH sfid. */
char *capIntrpSpwSfid(char *i_sfid_ptr); /* Check space wire sfid and interpret message. */
spwData saveRumhDat(char *chArry, long i_dat_indx, long i_dat_len, long i); /* Save RUMH Data. */
/* Takes care of space wire packets. */
spwData chkSpwDat(char *i_sfid_ptr, char *chArry, long i_dat_indx, long i_dat_len, FILE *spwFptr, long i, long zCnt);


#endif // FUNCT_HEADER_H_INCLUDED
