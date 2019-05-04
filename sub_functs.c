#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funct_header.h"

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
      *(i_sfid_str + r) = *(chArryPtr + sfid_indx + r); /* Fill up i_sfid word. */
      //printf("chArryPtr: %d\n", *(chArryPtr + sfid_indx + r));
      //printf("i_sfid_int: %d\n", *(i_sfid_int + r));
   }
   //printf("i_sfid_str inside: %s\n", i_sfid_str);
   return i_sfid_str;
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
   char *chnl;

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
long chkSfid(char *i_sfid_ptr, char *chArry, long i_dat_indx, long i_dat_len, FILE *confFptr, FILE *msoCh1Fptr, FILE *msoCh2Fptr, FILE *msoCh3Fptr, FILE *msoCh4Fptr, long i)
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
