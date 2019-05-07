#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funct_header.h"
#include "structures.h"

int main()
{
   //printf("Hello world!\n");
   //return 0;

   //	File pointer
   FILE *fptr;
   //fptr = fopen("C:/EGSE_Instrument_Control/vasa_cmd/scripts/program.txt","w");
   fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/obsplan_1_nowait_3_2019043232904_mso56_2019043233418.dat", "r");
   FILE *confFptr; /* For Tek CONF file. */
   confFptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_conf.txt", "w");
   FILE *msoCh1Fptr; /* For Tek Ch1 file. */
   //msoCh1Fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch1.txt", "w");
   FILE *msoCh2Fptr; /* For Tek Ch2 file. */
   //msoCh2Fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch2.txt", "w");
   FILE *msoCh3Fptr; /* For Tek Ch3 file. */
   //msoCh3Fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch3.txt", "w");
   FILE *msoCh4Fptr; /* For Tek Ch4 file. */
   //msoCh4Fptr = fopen("C:/Users/vdtruong/Desktop/Europa/REASON/Goddard/obsplan_1_nowait_3_2019043232904/pass/mso_ch4.txt", "w");

   char fileType[5];          /* Indicates file type to be parsed, ie, SCD, mso, spectrum analyzer or archive. */
   long i = 0;                /* Go through the data array. */
   int j = 0;                 /* Go through the z header word. */
   int m = 0;                 /* Go through the zHdr word. */
   //int p = 0;                 /* Go through the Z header length word. */
   char chArry[TOTCHRS];      /* Store characters from a file. */
   char zHdr[ZHDRWDTH];       /* Holder for Z header with 12 characters. */
   int zHdrIndx;              /* Holder for z header index. */
   int z_sfdu_dat_len_indx;   /* Z data length index. */
   long z_len_dec = 0;        /* z length in long decimal. */
   int first_i_hdr_flg = 1;   /* Indicates the first I header. */
   int i_pkts_not_done = 1;   /* Indicates if I packets are done for each Z packet. */
   long i_hdr_indx = 0;       /* I header index. */
   long sfid_indx = 0;        /* I header SFID index. */
   //int r = 0;                 /* Go through the I sfid word. */
   //char i_sfid[] = "ABCD";    /* This is a string. */
   char *i_sfid_ptr;          /* I SFID char pointer */
   long i_dat_len_indx = 0;   /* I data length index. */
   long i_dat_len = 0;        /* I data length. */
   long i_dat_indx = 0;       /* I data index. */
   long tot_dat_bytes = 0;    /* Total data bytes for entire file. */
   const char MSO[] = "mso";  /* Tektronix mso56 oscilloscope file type. */
   int msoMtchCnt = 0;        /* Indicates file type is mso56 in counts. */
   int fin_1_pkt = 0;         /* Indicates that we have finished 1 Z packet. */
                              /* After finishing one Z packet, the next character
                                 should be 'C' for the next Z packet. */
   int end_of_file = 0;       /* End of chArry. */
   iPktParms iPktParmsRet;    /* i packet parameters return */

   printf("Please enter file type.\n");
   printf("spw for space wire.\n");
   printf("speca for spectrum analyzer.\n");
   printf("mso for Tektronix MSO56 oscilloscope.\n");
   printf("arc for Archived.\n");
   printf("Please enter file type: ");
   scanf("%s", fileType);
   printf("\nFile type is: %s\n", fileType);
   /*for (i = 0; i < 6; i++){
      printf("%c", *(fileType+i));
   }*/
   printf("\n");

   /*int ch;

   ch = getc(fptr);
   printf("ch: %d\n", ch);
   ch = getc(fptr);
   printf("ch: %d\n", ch);
   ch = getc(fptr);
   printf("ch: %d\n", ch);
   */

   // Create a loop to retrieve one number at a time.
   // getc() returns an integer not a character.
   // If this is a text file, each number represents
   // an ascii character.  For example, C is represented
   // by the number 67.
   /*for (i = 0; i < TOTCHRS; i++){
      ch = getc(fptr);
      printf("%d", ch);
      *(chArry+i) = ch; /* Place ch value into chArry. */
   //}

   /* Fill the array with the file data, one character at a time. */
   for (i = 0; i < TOTCHRS; i++){
      *(chArry + i) = getc(fptr); /* Fill up chArry. */
      //printf("chArry: %c\n", *(chArry+i));
   }

   i = 0;
   while(!end_of_file){
      /* Check for the 'C' character of the Z header word. */
      if(*(chArry + i) == 'C'){
      //if(getc(fptr) == 'C')
         zHdrIndx = i; /* Fill out where we found the z header index. */
         for(j = 0; j < ZHDRWDTH; j++){
            *(zHdr + j) = *(chArry + i); /* Fill rest of z header word. */
            ++i; /* Counts up i. */
         }
         printf("i after filling z header word: %d\n", i);
         /* Check to see if we have the Z header word. */
         if(chkZhdrMtch(zHdr)){ /* If Z header is matched. */
            z_sfdu_dat_len_indx = zHdrIndx + ZHDRWDTH;
            z_len_dec = atol(findZlenStr(chArry, z_sfdu_dat_len_indx));
            printf("z_len_dec: %d\n", z_len_dec);
            /* After finding the I data length, i should advance 8 more elements. */
            i = i + DATFIELDWDTH;
            printf("i after finding z length: %d\n\n", i);

            /* If we are not done with the I packets for each Z packet,
               keep going through other I packets. */
            while(i_pkts_not_done){
               /* Grab I header index. */
               if(first_i_hdr_flg){
                  i_hdr_indx = zHdrIndx + ZHDRWDTH + DATFIELDWDTH;
                  //printf("1st i_hdr_indx: %d\n", i_hdr_indx);
                  first_i_hdr_flg = 0; /* Reset */
               }
               else{
                  /* If not first I header index, find next I header index
                  by adding previous data starting index and previous data length. */
                  i_hdr_indx = iPktParmsRet.i_dat_indx + iPktParmsRet.i_dat_len;
                  //printf("i_hdr_indx: %d\n", i_hdr_indx);
               }
               printf("i_hdr_indx: %d\n", i_hdr_indx);

               iPktParmsRet = findIPktParms(i_hdr_indx, chArry, i);
               /* Check to see what type of file we have. */
               /* Check if we have mso56. */
               for(m = 0; m < 3; m++){
                  if(*(fileType + m) == *(MSO + m)){
                     msoMtchCnt =  msoMtchCnt + 1;
                  }
               }
               printf("msoMtchCnt: %d\n", msoMtchCnt);

               /* If we have Tek. mso56 scope. */
               if(msoMtchCnt == 3){
                  printf("\nFile type is MSO56.\n");
                  /* Check for the SFID type we have and return i. */
                  /* Also save data if necessary. */
                  i = chkSfid(iPktParmsRet.i_sfid_ptr, chArry, iPktParmsRet.i_dat_indx,
                              iPktParmsRet.i_dat_len, confFptr, msoCh1Fptr, msoCh2Fptr,
                              msoCh3Fptr, msoCh4Fptr, iPktParmsRet.i);
               } /* If we have Tek. mso56 scope. */
               msoMtchCnt =  0;  /* Need to reset. */

               /* Find out if we are done with all the I packets within one Z packet. */
               tot_dat_bytes = tot_dat_bytes + IHDRWDTH + SFIDWDTH + DATFIELDWDTH + iPktParmsRet.i_dat_len;
               printf("tot_dat_bytes: %d\n\n", tot_dat_bytes);
               if (tot_dat_bytes >= z_len_dec){
                  i_pkts_not_done = 0; /* Done with I packets. */
                  printf("i_pkts_not_done: %d\n", i_pkts_not_done);
                  fin_1_pkt = 1; /* Indicates that we have finished 1 Z packet. */
               }
            } /* while i packets are not done. */
         } // if(zHdrMtchCnt == ZHDRWDTH){ /* If Z header is matched. */
         else{ /* If we don't have the Z header match. */
            ++i;
            printf("i: %d\n", i);
         }
      } /* If character 'C' is found. */
      else{ /* If character 'C' is not found. */
         /* If we have done one Z packet and the next character is not 'C' then exit. */
         if(fin_1_pkt){
            end_of_file = 1; /* Exit */
         }
         else{
            /* If 'C' is not found and we haven't finished any Z packet,
               move to the next element. */
            ++i;
            printf("i: %d\n", i);
         }
      }
   } /* while(!end_of_file) */

   fclose(fptr);
   fclose(confFptr);
   fclose(msoCh1Fptr);
   fclose(msoCh2Fptr);
   fclose(msoCh3Fptr);
   fclose(msoCh4Fptr);

   return 0;
}
