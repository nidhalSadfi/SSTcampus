#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main () {
  char str[] ="campus- 123;786;900.15 This is a sample string.";
  char tokens[]= ";,-";
  char * pch;  char *sRes[20];
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str,tokens);//amorcer le parsing (init)
  int i = 0;
  while (pch != NULL) {
    sRes[i] = (char*)malloc(sizeof(char)*strlen(pch)+1);
    sprintf (sRes[i++],"%s",pch);
    pch = strtok (NULL, tokens); //continue parsing
  }

  printf("parser result ==>\n");
  for (int j = 0; j < i ; j++){
    printf ("sRes[%d]=>%s\n",j, sRes[j]);
    free(sRes[j]);
  }
}
