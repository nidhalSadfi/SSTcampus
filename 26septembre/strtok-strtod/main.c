#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main () {
  FILE *freq;
  if ((freq = fopen("freaquencies.csv","r")) == NULL){
       printf("Error! opening file why ????\n==>[code=%d]%s\n",errno,strerror(errno));
       return 0;
  }
  char szBuff[800];
  int ret = fread(szBuff,sizeof(char),sizeof(szBuff),freq);//jump the \n character
  if (ret <= 0){
    printf("Empty file !!\n");
    fclose(freq);
    return 0;
  }
  fclose(freq);
  float flt[80][25];
  int ln = 0;
  int i = 0;
  char *pch = strtok (szBuff,"\n");//amorcer le parsing (init)
  while (pch != NULL){
      printf("line %d==>%s\n",ln,pch);
    //Treat Line
      char* pNext = pch;
      //printf("szOrbits=%s\n",szOrbits);
      do{
        flt[ln][i++] =strtof(pNext,&pNext);
        //printf("%.3f ",flt[ln][i]);
      }while (*pNext);
      flt[ln][i]=-1;
      ln++;
      i = 0;
      pch = strtok (NULL, "\n"); //continue parsing
  }
  printf("number of lines in matrix =>%d\n",ln);
  float fTot = 0;
  for(int i = 0 ; i < ln ; i++){
    printf("%d=> ",i+1);
    float fsomme = 0;
    for (int j = 0; j < 25 ; j++){
       if (flt[i][j] < 0)
          break;
       fsomme += flt[i][j];
       printf("%.2f\t",flt[i][j]);
    }
    printf("\t\t => S=%.2f\n",fsomme);
    fTot += fsomme;
  }
  printf("Total = %.2f\n",fTot);
}
