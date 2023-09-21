#include <stdio.h>
int main() {
  int k=18;
  int &pk = i;
  pk+=10;
  printf("%d\n", *pk);
}