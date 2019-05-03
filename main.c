#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funct_header.h"

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
   int p = 0;                 /* Go through the Z header length word. */
   char chArry[TOTCHRS];      /* Store characters from a file. */
   char zHdr[ZHDRWDTH];       /* Holder for Z header with 12 characters. */
   int zHdrIndx;              /* Holder for z header index. */
   int z_sfdu_dat_len_indx;   /* Z data length index. */
   long z_len_dec = 0;        /* z length in long decimal. */
   int first_i_hdr_flg = 1;   /* Indicates the first I header. */
   int i_pkts_not_done = 1;   /* Indicates if I packets are done for each Z packet. */
   long i_hdr_indx = 0;       /* I header index. */
   long sfid_indx = 0;        /* I header SFID index. */
   int r = 0;                 /* Go through the I sfid word. */
   char i_sfid[] = "ABCD";    /* This is a string. */
   char *i_sfid_ptr;          /* I SFID char pointer */
   long i_dat_len_indx = 0;   /* I data length. */
   long i_dat_len = 0;        /* I data length. */
   long i_dat_indx = 0;       /* I data index. */
   long tot_dat_bytes = 0;    /* Total data bytes for entire file. */
   const char MSO[] = "mso";  /* Tektronix mso56 oscilloscope file type. */
   int msoMtchCnt = 0;        /* Indicates file type is mso56 in counts. */
   int fin_1_pkt = 0;         /* Indicates that we have finished 1 Z packet. */
                              /* After finishing one Z packet, the next character
                                 should be 'C' for the next Z packet. */
   int end_of_file = 0;       /* End of chArry. */

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
                  i_hdr_indx = i_dat_indx + i_dat_len;
                  //printf("i_hdr_indx: %d\n", i_hdr_indx);
               }
               printf("i_hdr_indx: %d\n", i_hdr_indx);

               /* Grab sfid. */
               sfid_indx = i_hdr_indx + IHDRWDTH;
               //printf("sfid_indx: %d\n", sfid_indx);
               /* Function returns char pointer. */
               i_sfid_ptr = find_sfid_char(sfid_indx, chArry);
               /* After finding the SFID, i should advance 4 more elements. */
               i = i + SFIDWDTH;
               printf("i after finding sfid: %d\n", i);
               //for(r = 0; r < SFIDWDTH; r++){
                 // *(i_sfid + r) = *(i_sfid_ptr + r);
                  //printf("i_sfid: %s\n", *(i_sfid_ptr + r));
               //}
               //printf("i_sfid: %s\n", i_sfid);

               /* Grab I data length. */
               i_dat_len_indx = sfid_indx + SFIDWDTH;
               //printf("i_dat_len_indx outside: %d\n", i_dat_len_indx);
               /* I data length in integer form. */
               i_dat_len = find_i_dat_len(i_dat_len_indx, chArry);
               /* After finding the I data length, i should advance 8 more elements. */
               i = i + DATFIELDWDTH;
               printf("i after finding i data length: %d\n", i);
               printf("i_dat_len outside: %d\n", i_dat_len);
               //i_pkts_not_done = 0;

               /* Grab I data index. */
               i_dat_indx = i_dat_len_indx + DATFIELDWDTH;
               printf("i_dat_indx outside: %d\n", i_dat_indx);

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
               } /* If we have Tek. mso56 scope. */
               msoMtchCnt =  0;  /* Need to reset. */

               /* Find out if we are done with all the I packets within one Z packet. */
               tot_dat_bytes = tot_dat_bytes + IHDRWDTH + SFIDWDTH + DATFIELDWDTH + i_dat_len;
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