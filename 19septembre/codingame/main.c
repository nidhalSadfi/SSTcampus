#include <stdio.h>
#include <string.h>
#include <assert.h>
int main() {
char *thestar = "sun.milkyway.com";
char themoon[] = "ganymed.jupiter.com";
int x=NULL;
assert(x!=NULL);
printf( "%s-%s\n", thestar, themoon);
 strcpy(thestar,"sun@milkyway.com");
  printf( "%s", thestar);
 themoon[7] = '@';
  printf("%s", themoon);
 }