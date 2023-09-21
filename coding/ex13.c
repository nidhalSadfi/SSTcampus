#include <stdio.h>
#include <stdlib.h>
void compute(int val) {
   static int _cnt = 0;
   _cnt += 2;
   if (_cnt > 4)
     printf("Greater!\n");
}
int main() {
  compute(1);
  compute(2);
  compute(3);
  return 0;
}