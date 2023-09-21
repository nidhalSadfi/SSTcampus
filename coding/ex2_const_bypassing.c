#include <stdio.h>
int main() {
  const float PI = 3.14;
  float *q = &PI;
  *q = PI*10;
  printf("%.2f\n",PI);
}