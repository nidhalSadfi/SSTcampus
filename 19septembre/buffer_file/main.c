#include <stdio.h>
#include <stdlib.h>


#define MIN(S1,S2) (S1<S2)?S1:S2
#define CAPCITE 80

struct threeNum{
   int n1, n2, n3;
};


int main()
{
   int n;
   struct threeNum num;
   FILE *fptr;
   if ((fptr = fopen("c:/temp/program.bin","wb")) == NULL){
       printf("Error! opening file in write mode");
       exit(1);
   }
   for(n = 0; n < 5; n++)   {
      num.n1 = n+0x12345678;
      num.n2 = 5*n+0x12345678;
      num.n3 = 5*n +0x12345678;
      fwrite(&num, sizeof(struct threeNum), 1, fptr);
   }
   fclose(fptr);
   char buffer[CAPCITE];
   if ((fptr = fopen("c:/temp/program.bin","rb")) == NULL){
       printf("Error! opening file in read mode");
       exit(1);
   }
   int iRead = fread(buffer,sizeof(char),CAPCITE,fptr);
   printf ("1. nb bytes read read:%d sizeof(struct threeNum):%d, sizeof(int):%d\n", iRead,sizeof(struct threeNum),sizeof(int));
   fclose(fptr);

   printf("=================================================\n");
   if ((fptr = fopen("c:/temp/program.bin","rb")) == NULL){
       printf("Error! opening file in read mode");
       exit(1);
   }
   char buff[14];
   int curseur = 0;
   do{
      iRead = fread(buff,sizeof(char),14,fptr);
      printf ("1. nb bytes read read:%d sizeof(struct threeNum):%d, sizeof(int):%d\n", iRead,sizeof(struct threeNum),sizeof(int));
      if (iRead){
        int append = MIN(CAPCITE-curseur,iRead);
        memcpy(buffer+curseur, buff,append);
        curseur += append;
      }
   }while(iRead && (curseur < CAPCITE));
   fclose(fptr);
   printf ("Tot nb bytes read read:%d\n",curseur);

   int i ;
   printf("1. walking throw the buffer as struct threeNum memories:\n");
   struct threeNum *pNum;
   for (i = 0 ; i < curseur/sizeof(struct threeNum) ; i++){
     pNum = ((struct threeNum *)buffer)+i;
     printf("buff[%d].n1 = 0x%x -buff[%d].n2 = 0x%x -buff[%d].n3 = 0x%x \n",i,
                                  pNum->n1,i,pNum->n2,i,pNum->n3);
   }

   printf("2. walking throw the buffer as integers memories:\n");
   int *pInt;
   for (i = 0 ; i < curseur/sizeof(int) ; i++){
     pInt = (int *)buffer+i;
     printf("buff[%d] = 0x%x \n",i,*pInt);
   }
   printf("3. walking throw the buffer as bytes memories:\n");
   char *pChar;
   for (i = 0 ; i < curseur/sizeof(char) ; i++){
     pChar = ((char *)buffer)+i;
     printf("buff[%d] = %x-",i,*pChar);
   }
   fclose(fptr);
   return 0;
}
