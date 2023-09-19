#include <stdio.h>
#include <stdlib.h>
int main() {
   printf("Endianess !\n");
   int a;
   char *x;
   x = (char *) &a;
   a = 1500;
   unsigned char b;
   for(int i = 0; i < 4;i++){
     b =x[i];
     printf("x[%d]=%02x - ",i,b);
   }
   printf("\n");
   for(int i = 0; i < 4;i++){
     unsigned char b =*(((char *)&a) + i);
     printf("((char *)&a) + %d)=%02x - ",i,(unsigned char)*(((char *)&a) + i));
   }
   printf("val x=%08X\n",a);
   return 0;
}
