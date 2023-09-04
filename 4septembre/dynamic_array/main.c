#include <stdio.h>
#include <stdlib.h>

#define NBELT(tab) sizeof(tab)/sizeof(*tab)

int main()
{
    printf("Hello dynamic array world!\n"); //mutable data structure
    int v;
    int staticArray[] = {12,78,89,76,90,7}; //memory has bee allocated to be 24bytes
                                           //since compile
    staticArray[0]++;
    (*staticArray)++;
    printf("Number of elements of staticArray=%d, valu of"
           " fist elemenet (%d or %d)\n",
           NBELT(staticArray),staticArray[0],*staticArray);

    printf("at runtime please give the number of elemnts=>");
    int nbElt;
    scanf("%d",&nbElt);
    int * const pDynamicArray = malloc(nbElt * sizeof(int));//the size in memory depends on
                                              //nbElt Variable ...

    for (int i= 0; i < nbElt ; i++)
        pDynamicArray[i] = i + 1;

    pDynamicArray[0]++;
    pDynamicArray[1]++;
    pDynamicArray[2]++;
    pDynamicArray[3]++;
    printf("Number of elements of pDynamicArray=%d, valu of"
           " fist elemenet (%d or %d)\n",
           nbElt,pDynamicArray[0],*pDynamicArray);

     //pDynamicArray = &v;

    free(pDynamicArray);
    return 0;
}
