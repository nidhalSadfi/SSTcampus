#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int *p;
  int i = 10;
  i++;
  *p = i;
  printf("%d\n",i);
  return 0;
}