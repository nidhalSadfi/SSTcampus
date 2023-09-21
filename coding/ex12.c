#include <stdio.h>
#include <stdlib.h>
void compute(int val){
  extern int _cnt;
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
int _cnt = 2;