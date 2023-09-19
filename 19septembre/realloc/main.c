#include <stdio.h>
#include <stdlib.h>
int main() {
   int *ptr = (int *)malloc(sizeof(int)*5);
   printf("1.ptr = %p\n",ptr);
   int i;
   //int *ptr_new;

   *ptr = 10;
   *(ptr + 1) = 20;
   ptr[2] = 30;
   ptr[3] = 40;
   ptr[4] = 50;

   ptr = (int *)realloc(ptr, sizeof(int)*3);
   printf("2.ptr = %p\n",ptr);

   ptr[3] = 40;
   printf("undefined valur in new memlory=>%d\n", *(ptr + 2));
   *(ptr+ 2) = 30;
   for(i = 0; i < 5; i++)
       printf("%d ", *(ptr + i));
   printf("press a key==>\n");
   //free(ptr);
   ptr = realloc(ptr,0);
   getchar();
   return 0;
}
