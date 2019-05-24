#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funct_header.h"
#include "structures.h"
#include "define.h"

char *find_sfid(long sfid_indx, int *chArryPtr)
{
   int i_sfid_int[4] = {1,2,3,4};      /* Integer version. */
   static char i_sfid_str[] = "RUMH";  /* String version. */
   int r = 0;

   //printf("sfid_indx inside funct.: %d\n", sfid_indx);

   for(r = 0; r < SFIDWDTH; r++){
      //printf("r: %d\n", r);
      *(i_sfid_int + r) = *(chArryPtr + sfid_indx + r); /* Fill up i_sfid word. */
      //printf("chArryPtr: %d\n", *(chArryPtr + sfid_indx + r));
      //printf("i_sfid_int: %d\n", *(i_sfid_int + r));
      /* Convert integer into ascii string. */
      switch(*(i_sfid_int + r)){
         case 32: *(i_sfid_str + r) = ' ';
            break;
         case 48: *(i_sfid_str + r) = '0';
            break;
         case 49: *(i_sfid_str + r) = '1';
            break;
         case 50: *(i_sfid_str + r) = '2';
            break;
         case 51: *(i_sfid_str + r) = '3';
            break;
         case 52: *(i_sfid_str + r) = '4';
            break;
         case 53: *(i_sfid_str + r) = '5';
            break;
         case 54: *(i_sfid_str + r) = '6';
            break;
         case 55: *(i_sfid_str + r) = '7';
            break;
         case 56: *(i_sfid_str + r) = '8';
            break;
         case 57: *(i_sfid_str + r) = '9';
            break;
         case 65: *(i_sfid_str + r) = 'A';
            break;
         case 66: *(i_sfid_str + r) = 'B';
            break;
         case 67: *(i_sfid_str + r) = 'C';
            break;
         case 68: *(i_sfid_str + r) = 'D';
            break;
         case 69: *(i_sfid_str + r) = 'E';
            break;
         case 70: *(i_sfid_str + r) = 'F';
            break;
         case 71: *(i_sfid_str + r) = 'G';
            break;
         case 72: *(i_sfid_str + r) = 'H';
            break;
         case 73: *(i_sfid_str + r) = 'I';
            break;
         case 74: *(i_sfid_str + r) = 'J';
            break;
         case 75: *(i_sfid_str + r) = 'K';
            break;
         case 76: *(i_sfid_str + r) = 'L';
            break;
         case 77: *(i_sfid_str + r) = 'M';
            break;
         case 78: *(i_sfid_str + r) = 'N';
            break;
         case 79: *(i_sfid_str + r) = 'O';
            break;
         case 80: *(i_sfid_str + r) = 'P';
            break;
         case 81: *(i_sfid_str + r) = 'Q';
            break;
         case 82: *(i_sfid_str + r) = 'R';
            break;
         case 83: *(i_sfid_str + r) = 'S';
            break;
         case 84: *(i_sfid_str + r) = 'T';
            break;
         case 85: *(i_sfid_str + r) = 'U';
            break;
         case 86: *(i_sfid_str + r) = 'V';
            break;
         case 87: *(i_sfid_str + r) = 'W';
            break;
         case 88: *(i_sfid_str + r) = 'X';
            break;
         case 89: *(i_sfid_str + r) = 'Y';
            break;
         case 90: *(i_sfid_str + r) = 'Z';
            break;
         default:
            break;
      }
   }
   //printf("i_sfid_str inside: %s\n", i_sfid_str);
   return i_sfid_str;
}
char *find_sfid_char(long sfid_indx, char *chArryPtr)
{
   //int i_sfid_int[4] = {1,2,3,4};      /* Integer version. */
   static char i_sfid_str[] = "RUMH";  /* String version. */
   int r = 0;

   //printf("sfid_indx inside funct.: %d\n", sfid_indx);

   for(r = 0; r < SFIDWDTH; r++){
      //printf("r: %d\n", r);
      printf("chArryPtr: %c\n", *(chArryPtr + sfid_indx + r));
      *(i_sfid_str + r) = *(chArryPtr + sfid_indx + r); /* Fill up i_sfid word. */
      printf("*(i_sfid_str + r) = %c\n", *(i_sfid_str + r));
      //printf("i_sfid_int: %d\n", *(i_sfid_int + r));
   }
   //printf("i_sfid_str inside: %s\n", i_sfid_str);
   return i_sfid_str; /* Returns pointer to array. */
}
long find_i_dat_len(long i_dat_len_indx, char *chArryPtr)
{
   //int i_dat_len_int[DATFIELDWDTH] = {1,2,3,4,5,6,7,8};
   int s = 0;
   char i_dat_len_str[] = "12345678";
   static long i_dat_len = 0;

   //printf("i_dat_len_indx inside: %d\n", i_dat_len_indx);

   for(s = 0; s < DATFIELDWDTH; s++){
      //printf("chArryPtr: %d\n", *(chArryPtr + i_dat_len_indx + s));
      /* Fill up I data length word. */
      *(i_dat_len_str + s) = *(chArryPtr + i_dat_len_indx + s);
      //printf("i_dat_len_int: %d\n", *(i_dat_len_int + s));
      //printf("i_dat_len_str: %s\n", i_dat_len_str);
   }
   i_dat_len = atol(i_dat_len_str);

   return i_dat_len;
}
int chkZhdrMtch(char *zHdr)
{
   int zHdrMtchCnt = 0; /* Count up to check for zHdr match. */
   int m = 0;
   /* Z header in integer array, CCSD3ZA00001. */
   const int ZHEADER[ZHDRWDTH] = {67,67,83,68,51,90,65,48,48,48,48,49};

   /* Check to see if we have the Z header word. */
   for(m = 0; m < ZHDRWDTH; m++){
      if(*(zHdr + m) == *(ZHEADER + m)){
         zHdrMtchCnt =  zHdrMtchCnt + 1;
      }
   }
   if(zHdrMtchCnt == ZHDRWDTH){ /* If Z header is matched. */
      return 1;
   }
   else{
      return 0;
   }
 }
char *findZlenStr(char *chArryPtr, int z_sfdu_dat_len_indx)
{

   int p = 0;
   static char z_len_wrd_str[] = "12345678"; /* z_len_wrd in string format. */

   /* Extract the z header length from the character array. */
   for (p = 0; p < DATFIELDWDTH; p++){
      *(z_len_wrd_str + p) = *(chArryPtr + z_sfdu_dat_len_indx + p); /* Fill up z_len_wrd_str. */
      //printf("z_len_wrd_str: %s\n", z_len_wrd_str);
   }
   //printf("i after z header length: %d\n", i);
   printf("z_len_wrd_str: %s\n", z_len_wrd_str);

   return z_len_wrd_str;
}
int chkConfSfid(char *i_sfid_ptr)
{
   int m;
   int confCnt = 0;

   /* Check for CONF sfid. */
   for(m = 0; m < SFIDWDTH; m++){
      printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
      printf("CONF: %c\n", *(CONF + m));
      if(*(CONF + m) == *(i_sfid_ptr + m)){
         confCnt = confCnt + 1;
      }
   }
   if(confCnt == SFIDWDTH){ /* If we have config. data. */
      return 1;
   }
   else {
      return 0;
   }
 }
int chkCh1Sfid(char *i_sfid_ptr)
{
   int m;
   int msoCh1Cnt = 0;

   /* Check for CH1 sfid. */
   for(m = 0; m < SFIDWDTH; m++){
      printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
      printf(" CH1: %c\n", *(CH1 + m));
      if(*(CH1 + m) == *(i_sfid_ptr + m)){
         msoCh1Cnt = msoCh1Cnt + 1;
      }
   }
   printf("msoCh1Cnt: %d\n", msoCh1Cnt);
   if(msoCh1Cnt == SFIDWDTH){ /* If we have CH1 data. */
      return 1;
   }
   else {
      return 0;
   }
 }
int chkCh2Sfid(char *i_sfid_ptr)
{
   int m;
   int msoCh2Cnt = 0;

   /* Check for CH2 sfid. */
   for(m = 0; m < SFIDWDTH; m++){
      printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
      printf(" CH2: %c\n", *(CH2 + m));
      if(*(CH2 + m) == *(i_sfid_ptr + m)){
         msoCh2Cnt = msoCh2Cnt + 1;
      }
   }
   printf("msoCh2Cnt: %d\n", msoCh2Cnt);
   if(msoCh2Cnt == SFIDWDTH){ /* If we have CH2 data. */
      return 1;
   }
   else {
      return 0;
   }
 }
int chkChxSfid(char *i_sfid_ptr, int ch)
{
   int m;
   int msoChxCnt = 0;
   //char chnl[] = " CH1"; /* Use this as a switch. */
   char *chnl = "1234";

   switch(ch){
      case 1: chnl = CH1; /* Points to the constant so we can walk through it. */
         break;
      case 2: chnl = CH2;
         break;
      case 3: chnl = CH3;
         break;
      case 4: chnl = CH4;
         break;
      default:
         break;
   }

   /* Check for CHx sfid. */
   for(m = 0; m < SFIDWDTH; m++){
      printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
      printf(" CHx: %c\n", *(chnl + m));
      if(*(chnl + m) == *(i_sfid_ptr + m)){
         msoChxCnt = msoChxCnt + 1;
      }
   }
   printf("msoChxCnt: %d\n", msoChxCnt);
   if(msoChxCnt == SFIDWDTH){ /* If we have CH1 data. */
      return 1;
   }
   else {
      return 0;
   }
}
long saveChxDat(char *chArry, long i_dat_indx, long i_dat_len, FILE *msoChxFptr, long i)
{
   int p = 0;

   /*switch(ch){
      case 0: msoChxFptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_conf.txt", "w");
         break;
      case 1: msoChxFptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch1.txt", "w");
         break;
      case 2: msoChxFptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch2.txt", "w");
         break;
      case 3: msoChxFptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch3.txt", "w");
         break;
      case 4: msoChxFptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch4.txt", "w");
         break;
      default:
         break;
   }*/

   /* Save data to the Chx file. */
   for (p = 0; p < i_dat_len; p++){
      /* Write to file. */
      putc(*(chArry + i_dat_indx + p), msoChxFptr);
      ++i;
   }
   /* After filling up the data, i should be at i + i_dat_len. */
   printf("i after mso chx: %d\n", i);

   return i;
}
long chkMsoSfid(char *i_sfid_ptr, char *chArry, long i_dat_indx, long i_dat_len, FILE *confFptr, FILE *msoCh1Fptr, FILE *msoCh2Fptr, FILE *msoCh3Fptr, FILE *msoCh4Fptr, long i)
{
   /* Check for CONF sfid. */
   if(chkConfSfid(i_sfid_ptr)){
      /* Save data to the CONF file. */
      i = saveChxDat(chArry, i_dat_indx, i_dat_len, confFptr, i);
      /* After filling up the data, i should be at i + i_dat_len. */
      printf("i after configuration: %d\n", i);
   }
   else{ /* If not MSO Config. data. */
      /* Check for CH1 sfid. */
      //if(chkCh1Sfid(i_sfid_ptr)){
      if(chkChxSfid(i_sfid_ptr, 1)){
         msoCh1Fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch1.txt", "w");
         /* Save data to the Ch1 file. */
         /* After filling up the data, i should be at i + i_dat_len. */
         i = saveChxDat(chArry, i_dat_indx, i_dat_len, msoCh1Fptr, i);
         printf("i after mso ch1: %d\n", i);
      } /* If mso ch1 data. */
      else{ /* If not mso ch1 data. */
         /* Check for CH2 sfid. */
         if(chkChxSfid(i_sfid_ptr, 2)){
            msoCh2Fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch2.txt", "w");
            /* Save data to the Ch2 file. */
            /* After filling up the data, i should be at i + i_dat_len. */
            i = saveChxDat(chArry, i_dat_indx, i_dat_len, msoCh2Fptr, i);
            printf("i, after mso ch2: %d\n", i);
         } /* If mso ch2 data. */
         else{ /* If not mso ch2 data. */
            /* Check for CH3 sfid. */
            if(chkChxSfid(i_sfid_ptr, 3)){
               msoCh3Fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch3.txt", "w");
               /* Save data to the Ch3 file. */
               /* After filling up the data, i should be at i + i_dat_len. */
               i = saveChxDat(chArry, i_dat_indx, i_dat_len, msoCh3Fptr, i);
               printf("i after mso ch3: %d\n", i);
            } /* If mso ch3 data. */
            else{ /* If not mso ch3 data. */
               /* Check for CH4 sfid. */
               if(chkChxSfid(i_sfid_ptr, 4)){
                  msoCh4Fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch4.txt", "w");
                  /* Save data to the Ch4 file. */
                  /* After filling up the data, i should be at i + i_dat_len. */
                  i = saveChxDat(chArry, i_dat_indx, i_dat_len, msoCh4Fptr, i);
                  printf("i after mso ch4: %d\n", i);
               } /* If mso ch4 data. */
            } /* If not mso ch3 data. */
         } /* If not mso ch2 data. */
      } /* If not mso ch1 data. */
   } /* If not MSO Config. file. */

   return i;
}
iPktParms findIPktParms(long i_hdr_indx, char *chArry, long i)
{
   long sfid_indx = 0;        /* I header SFID index. */
   long i_dat_len_indx = 0;   /* I data length index. */
   static iPktParms getIPktParms;

   /* Grab sfid. */
   sfid_indx = i_hdr_indx + IHDRWDTH;
   //printf("sfid_indx: %d\n", sfid_indx);
   /* Function returns char pointer. */
   getIPktParms.i_sfid_ptr = find_sfid_char(sfid_indx, chArry);
   printf("i_sfid_ptr: %c\n", *getIPktParms.i_sfid_ptr);
   /* After finding the SFID, i should advance 4 more elements. */
   getIPktParms.i = i + SFIDWDTH;
   printf("i after finding sfid: %d\n", getIPktParms.i);

   /* Grab I data length. */
   i_dat_len_indx = sfid_indx + SFIDWDTH;
   //printf("i_dat_len_indx outside: %d\n", i_dat_len_indx);
   /* I data length in integer form. */
   getIPktParms.i_dat_len = find_i_dat_len(i_dat_len_indx, chArry);

   /* After finding the I data length, i should advance 8 more elements. */
   getIPktParms.i = i + DATFIELDWDTH;
   printf("i after finding i data length: %d\n", getIPktParms.i);
   printf("i_dat_len inside findIPktParms: %d\n", getIPktParms.i_dat_len);
   //i_pkts_not_done = 0;

   /* Grab I data index. */
   getIPktParms.i_dat_indx = i_dat_len_indx + DATFIELDWDTH;
   printf("i_dat_indx inside findIPktParms: %d\n", getIPktParms.i_dat_indx);

   return getIPktParms;
}
char *find_rumh_data(long sfid_indx, char *chArryPtr)
{
   static char rumh_str[] = "7777"; /* String version. */
   int r = 0;

   for(r = 0; r < SFIDWDTH; r++){
      printf("chArryPtr: %x\n", *(chArryPtr + sfid_indx + r));
      *(rumh_str + r) = *(chArryPtr + sfid_indx + r); /* Fill up i_sfid word. */
      printf("*(rumh_str + r) = %x\n", *(rumh_str + r));
   }
   return rumh_str; /* Returns pointer to array. */
}
spwData saveRumhDat(char *chArry, long i_dat_indx, long i_dat_len, long i)
{
   int p = 0;
   static spwData rumhDat;

   printf("Entering saveRumhDat.\n");
   printf("Check for freeze.\n");

   rumhDat.i = i;
   printf("rumhDat.i: %d\n", rumhDat.i);

   /* Save RUMH data. */
   rumhDat.rumhData = find_rumh_data(i_dat_indx, chArry);
   for (p = 0; p < i_dat_len; p++){
      printf("rumhData: %d\n", *(rumhDat.rumhData+p));
      rumhDat.i = rumhDat.i + 1;
   }

   return rumhDat; /* Return a structure. */
}
int chkRumhSfid(char *i_sfid_ptr)
{
   int m;
   int rumhCnt = 0;

   /* Check for RUMH sfid. */
   for(m = 0; m < SFIDWDTH; m++){
      printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
      printf("RUMH: %c\n", *(RUMH + m));
      if(*(RUMH + m) == *(i_sfid_ptr + m)){
         rumhCnt = rumhCnt + 1;
      }
   }
   printf("rumhCnt = %d\n", rumhCnt);

   if(rumhCnt == SFIDWDTH){ /* If we have space wire RUMH data. */
      return 1;
   }
   else {
      return 0;
   }
}
char *capIntrpSpwSfid(char *i_sfid_ptr)
{
   int m;
   int c0efCnt = 0;
   int c034Cnt = 0;
   int c056Cnt = 0;
   int c000Cnt = 0;
   int c001Cnt = 0;
   int c002Cnt = 0;
   int c019Cnt = 0;

   /* Check for C0ef sfid. */
   for(m = 0; m < SFIDWDTH; m++){
      printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
      printf(" C0ef: %c\n", *(C0EF + m));
      if(*(C0EF + m) == *(i_sfid_ptr + m)){
         c0efCnt = c0efCnt + 1;
      }
   }
   printf("c0efCnt: %d\n", c0efCnt);
   if(c0efCnt == SFIDWDTH){ /* If we have C0ef sfid. */
      return C0EFMSG;
   }
   else {
      /* Check for C034 sfid. */
      for(m = 0; m < SFIDWDTH; m++){
         printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
         printf(" C034: %c\n", *(C034 + m));
         if(*(C034 + m) == *(i_sfid_ptr + m)){
            c034Cnt = c034Cnt + 1;
         }
      }
      printf("c034Cnt: %d\n", c034Cnt);
      if(c034Cnt == SFIDWDTH){ /* If we have C034 sfid. */
         return C034MSG;
      }
      else{
         /* Check for C056 sfid. */
         for(m = 0; m < SFIDWDTH; m++){
            printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
            printf(" C056: %c\n", *(C056 + m));
            if(*(C056 + m) == *(i_sfid_ptr + m)){
               c056Cnt = c056Cnt + 1;
            }
         }
         printf("c056Cnt: %d\n", c056Cnt);
         if(c056Cnt == SFIDWDTH){ /* If we have C056 sfid. */
            return C056MSG;
         }
         else{
            /* Check for C000 sfid. */
            for(m = 0; m < SFIDWDTH; m++){
               printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
               printf(" C000: %c\n", *(C000 + m));
               if(*(C000 + m) == *(i_sfid_ptr + m)){
                  c000Cnt = c000Cnt + 1;
               }
            }
            printf("c000Cnt: %d\n", c000Cnt);
            if(c000Cnt == SFIDWDTH){ /* If we have C000 sfid. */
               return C000MSG;
            }
            else{
               /* Check for C001 sfid. */
               for(m = 0; m < SFIDWDTH; m++){
                  printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
                  printf(" C001: %c\n", *(C001 + m));
                  if(*(C001 + m) == *(i_sfid_ptr + m)){
                     c001Cnt = c001Cnt + 1;
                  }
               }
               printf("c001Cnt: %d\n", c001Cnt);
               if(c001Cnt == SFIDWDTH){ /* If we have C001 sfid. */
                  return C001MSG;
               }
               else{
                  /* Check for C002 sfid. */
                  for(m = 0; m < SFIDWDTH; m++){
                     printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
                     printf(" C002: %c\n", *(C002 + m));
                     if(*(C002 + m) == *(i_sfid_ptr + m)){
                        c002Cnt = c002Cnt + 1;
                     }
                  }
                  printf("c002Cnt: %d\n", c002Cnt);
                  if(c002Cnt == SFIDWDTH){ /* If we have C002 sfid. */
                     return C002MSG;
                  }
                  else{
                     /* Check for C019 sfid. */
                     for(m = 0; m < SFIDWDTH; m++){
                        printf("i_sfid_ptr: %c\n", *(i_sfid_ptr + m));
                        printf(" C019: %c\n", *(C019 + m));
                        if(*(C019 + m) == *(i_sfid_ptr + m)){
                           c019Cnt = c019Cnt + 1;
                        }
                     }
                     printf("c019Cnt: %d\n", c019Cnt);
                     if(c019Cnt == SFIDWDTH){ /* If we have C019 sfid. */
                        return C019MSG;
                     }
                     else{
                        return UNDEFMSG;
                     }
                  }
               }
            }
         }
      }
   }
}
spwData chkSpwDat(char *i_sfid_ptr, char *chArry, long i_dat_indx, long i_dat_len, FILE *spwFPtr, long i, long zCnt)
{
   static spwData spwDataRet;   /* Data from SPW. */
   //spwData spwDataRet;

   char *rumhDatRet, *sfidMsg, *savData, *zToStr;
   int p = 0;

   /* Check for RUMH sfid.
      If it exists, save the RUMH data. */
   if(chkRumhSfid(i_sfid_ptr)){
      /* Store RUMH data. */
      spwDataRet = saveRumhDat(chArry, i_dat_indx, i_dat_len, i);
      for(p = 0; p < SFIDWDTH; p++){
         *(rumhDatRet + p) = *(spwDataRet.rumhData + p);
         //printf("*(rumhDatRet + p): %d\n", *(rumhDatRet + p));
      }
      for(p = 0; p < SFIDWDTH; p++){
         printf("*(spwDatRet.rumhData + p): %d\n", *(spwDataRet.rumhData + p));
      }

      /* After filling up the data, i should be at i + i_dat_len. */
      //printf("i after space wire sfid: %d\n", spwDataRet->i);
   }
   else{ /* If not RUMH data, integrate z counter, sfid message, RUMH string, and data then save to a file. */
      spwFPtr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/spw_file.txt", "w");
      /* Check for space wire sfid other than RUMH. */
      printf("zCnt: %d\n", zCnt);
      sprintf(zToStr, "%d", zCnt); /* Convert zCnt to string. */
      /* Save z string to file. */
      spwFPtr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/spw_file.txt", "a");
      for (p = 0; p < strlen(zToStr); p++){
         /* Write to file. */
         putc(*(zToStr + p), spwFPtr);
      }
      /* Concatenate with the corresponding sfid message. */
      sfidMsg = capIntrpSpwSfid(i_sfid_ptr);
      for (p = 0; p < strlen(sfidMsg); p++){
         /* Write to file. */
         putc(*(sfidMsg + p), spwFPtr);
      }
      /* Concatenate with the RUMH data. */
      for (p = 0; p < strlen(rumhDatRet); p++){
         /* Write to file. */
         putc(*(spwDataRet.rumhData + p), spwFPtr);
      }
      printf("i after RUMH data: %d\n", spwDataRet.i);

      spwDataRet.i = saveChxDat(chArry, i_dat_indx, i_dat_len, spwFPtr, spwDataRet.i);
      printf("i after mso ch1: %d\n", spwDataRet.i);

   }

   return spwDataRet;
}
