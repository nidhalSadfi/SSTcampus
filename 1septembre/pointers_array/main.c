#include <stdio.h>
#include <stdlib.h>

#define NBMONTHS 12
int main()
{
    printf("Hello Pointers & Array world!\n");
    int i =90;
    int j = 900;
    printf("&i =%p, i=%d\n",&i,i);
    int tMonths[12]; //static memory allocation of 12 int positions
                     // => 12 * sizeof(int) : 48 bytes
    printf("tMonths=%p of size= %d\n",tMonths, sizeof(tMonths));

    tMonths[0] = 10;
    tMonths[1] = 20;
    tMonths[2] = 30;
    tMonths[3] = 40;
    for (int k = 0; k < NBMONTHS ; k++)
        tMonths[k] = (k+1)*10;

    printf("tMOnths[5]=%d\n", tMonths[5]);
    tMonths[4] = tMonths[4]+1;
    tMonths[5]++; //incrémentation
    tMonths[6] = tMonths[6] + 100;
    tMonths[7]+=100; //opération composée $$
    tMonths[8] = tMonths[8]-3;
    tMonths[9]-=3;
    tMonths[10]*=5;
    tMonths[11]%=3;

    for (int k = 0; k < NBMONTHS ; k++)
        printf("tMonths[%d]=%d ",k,tMonths[k]);
    printf("\n");

    int n = 13;
    printf("give your index of the month (0..11):");
    scanf("%d",&n);
    n++;
    if (n < NBMONTHS){//test de blindage
        printf("tMonths[%d]=%d ",n,tMonths[n]);
        tMonths[n]=0;
        printf("tMonths[%d]=%d ",n,tMonths[n]);
    }else
       printf("Please give a valid index !!!!\n");
    return 0;
}
