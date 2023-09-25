#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Hello parser world !\n");
  char szOrbits[80];// = "365.24 29.53 3.0 12.89 21.0 21.0";
  printf("list of double values :");
  scanf("%[^\n]",szOrbits);
  char* pNext = szOrbits;
  double dbl[25];
  int i = 0;
  do{
    dbl[i] =strtod(pNext,&pNext);
    i++;
  }while (*pNext);

  for(int j = i ; j > 0 ; j--)
    printf("%d:%.2f,",i-j, dbl[i-j]);
  printf("\n");
}
