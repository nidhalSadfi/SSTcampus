#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main() {
  printf("Hello parser world !\n");

   printf("list of double values :");
  FILE *freq;
  if ((freq = fopen("freaquencies.csv","r")) == NULL){
       printf("Error! opening file why ????\n==>[code=%d]%s\n",errno,strerror(errno));
       return 0;
  }
  char buffer[800];
  int _Red =fread(buffer,sizeof(char),sizeof(buffer),freq);
  if (_Red==0){
    printf("la fichier est vide !!! /n");
    return 0;
  }

//printf ("kinda works");



  char* pch;
  //float flt[80][25];
 // int i = 0 ;
  pch =strtok(buffer,"\n");
  while(pch !=NULL){
      //flt[ln][i++] = (float)*pch;
      printf("%s\n",pch);
      pch=strtok(NULL,"\n");
      //ln++;
  }
        /*
      int read = fscanf(freq, "%[^\n]",szOrbits);
      if (read<=0)
        break;
      char* pNext = szOrbits;
      do{
        flt[ln][i++] =strtof(pNext,&pNext);
      }while (*pNext);
      flt[ln][i]=-1;
      ln++;
      i=0;
      fread(szOrbits,sizeof(char),1,freq);//jump the \n
      */


//  printf("number of lines treated =>%d\n",ln);
  /*for(int j = i ; j > 0 ; j--)
    printf("%d:%.2f,",i-j, dbl[i-j]);
  printf("\n");
    float k=0;
    for (int j=0;j<ln;j++){
        float S=0;
        for (int k =0;k<25;k++){
            if (flt[j][k] < 0)
                break;
            S=S+flt[j][k];
            printf("%.2f\t",flt[j][k]);
        }
        printf("                     la somme est %f",S);
        k=k+S;
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf(" la somme totale  est %f",k);
*/
  fclose(freq);
}
