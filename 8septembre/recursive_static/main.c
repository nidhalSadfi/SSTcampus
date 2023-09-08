#include <stdio.h>
#include <stdlib.h>


void printd(int n, char sInt[])
{//printd:print n in decimal
   static int i = 0;
   if (n < 0) {
      sInt[i++]='-';
      n = -n;
   }
   if (n / 10)
     printd(n / 10,sInt);
   sInt[i++] = n % 10 + '0';
}


int main()
{
    printf("Hello Recursive world!\n");
    int k = -1987;
    char sInt[12];
    printd(k,sInt);
    printf("k=%d, sInt=%s\n",k,sInt);
    return 0;
}
