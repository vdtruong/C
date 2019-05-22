#include "structures.h"

#ifndef FUNCT_HEADER_H_INCLUDED
#define FUNCT_HEADER_H_INCLUDED

#define TOTCHRS 800000  /* This is the number of characters we want from the data file. */
#define ZHDRWDTH 12     /* Z header word width. */
#define DATFIELDWDTH 8  /* Data field width. */
#define IHDRWDTH 8      /* I header width. */
#define SFIDWDTH 4      /* SFID width. */
#define CONF "CONF"     /* MSO CONF sfid. */
#define CH1 " CH1"      /* MSO Ch1 sfid. */
#define CH2 " CH2"      /* MSO Ch2 sfid. */
#define CH3 " CH3"      /* MSO Ch3 sfid. */
#define CH4 " CH4"      /* MSO Ch4 sfid. */
#define C0EF "C0ef"     /* SPW Msg Success+(ACK) */
#define C0EFMSG ", Msg Success+(ACK), "
#define C034 "C034"     /* SPW AXI Read Response+ */
#define C034MSG ", AXI Read Response+, "
#define C056 "C056"     /* SPW Msg Failure+(NACK) */
#define C056MSG ", Msg Failure+(NACK), "
#define C000 "C000"     /* SPW H&S Telemetry */
#define C000MSG ", H&S Telemetry, "
#define C001 "C001"     /* SPW Mem Read */
#define C001MSG ", Mem Read, "
#define C002 "C002"     /* SPW Engineering Telemetry A */
#define C002MSG ", Engineering Telemetry A, "
#define C019 "C019"     /* SPW Mem Readback */
#define C019MSG ", Mem Readback, "
#define UNDEFMSG ", Undefined Packet Type, "
#define RUMH "RUMH"     /* Space wire RUMH sfid. */

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
int chkRumhSfid(char *i_sfid_ptr); /* Check for space wire RUMH sfid. */
/* Takes care of space wire packets. */
long chkSpwDat(char *i_sfid_ptr, char *chArry, long i_dat_indx, long i_dat_len, FILE *confFptr, FILE *msoCh1Fptr, FILE *msoCh2Fptr, FILE *msoCh3Fptr, FILE *msoCh4Fptr, long i, long zCnt);
char *capIntrpSpwSfid(char *i_sfid_ptr); /* Check space wire sfid and interpret message. */
#endif // FUNCT_HEADER_H_INCLUDED
