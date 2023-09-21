#include <stdio.h>
int main() {
  int i=104;
  i++;
  int *p = malloc(sizeof(int));
  *p = i;
  printf("=>%d\n",p);
  free(p);
}