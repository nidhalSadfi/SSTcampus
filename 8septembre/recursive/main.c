#include <stdio.h>
#include <stdlib.h>


void printd(int n)
{//printd:print n in decimal
   if (n < 0) {
      putchar('-');
      n = -n;
   }
   if (n / 10)
     printd(n / 10);
   putchar(n % 10 + '0');
}


int main()
{
    printf("Hello Recursive world!\n");
    int k = -1987;
    printf("k=%d\n",k);
    printd(k);
    return 0;
}
