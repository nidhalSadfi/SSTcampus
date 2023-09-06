#include <stdio.h>
#include <string.h>
union item {
  int i;
  float f;
  char c;
} vcode;

void main() {
    printf("sizeof Unions is : %d\n", sizeof(vcode));
    vcode.i=1919;
    printf("result of Unions member <i> in use : %d\n", vcode.i);

    vcode.f=456.78;

    printf("result of Unions member <i> no more in use : %d\n", vcode.i);
    printf("result of Unions member used in last : %.3f\n", vcode.f);
}
