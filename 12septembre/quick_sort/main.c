#include <stdio.h>
#include <stdlib.h>

void display(int pTab[], int szTab){
   for (int i = 0; i < szTab ; i++)
     printf("%d-",pTab [i]);  
   printf("\n");
}

int cmp(const void *a , const void *b){
   return (*(int*)a<*(int*)b)?-1:1;
}
int main() {
    printf("Hello Quick sorting world!\n");
    int simpleTab[]={12,78,6,43,2,90,67,10,23,77};
    int _sz = sizeof(simpleTab)/sizeof(simpleTab[0]);
    display(simpleTab, _sz);

    qsort(simpleTab,_sz,sizeof(int),cmp);
    display(simpleTab, _sz);
    return 0;
}
