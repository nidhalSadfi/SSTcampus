#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
int i = 10;
int j = 11;
int *p = 12;
*p = i+j;
printf("%d\n",*p);
return 0;
}