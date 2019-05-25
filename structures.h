#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct {
   char *i_sfid_ptr; /* I SFID char pointer */
   long i_dat_indx; /* I data index. */
   long i_dat_len;   /* I data length. */
   long i;           /* Go through the data array. */
}iPktParms;
typedef struct{
   char *rumhData;   /* RUMH Data from SPW. */
   long i;           /* Go through the data array. */
}spwData;
typedef struct{
   char *retMsg;     /* Interpreted message for SPW SFID code. */
   int msgLngth;     /* Length of that message. */
}sfidIntrpMsg;


#endif // STRUCTURES_H_INCLUDED
