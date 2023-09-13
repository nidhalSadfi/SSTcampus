#include <stdio.h>
#include <stdlib.h>

//#undef _UT
int gAsc= 1;
void display(int pTab[], int szTab){
   for (int i = 0; i < szTab ; i++)
     printf("%d-",pTab [i]);
   printf("\n");
}

int cmp(const void *a , const void *b){
#ifdef _UT
ddd
    static int cpt = 0;
    printf("%d. cmp a=%d, b=%d\n", cpt++,*(int*)a, *(int*)b);
    /*return gAsc * ((*(int*)a<*(int*)b)?-1:1);*/
#endif
    return gAsc * (*(int*)a - *(int*)b);
}

int main() {
    printf("Hello Quick sorting world!\n");
    int simpleTab[]={12,78,6,43,2,90,67,10,23,77};
    int _sz = sizeof(simpleTab)/sizeof(simpleTab[0]);
    display(simpleTab, _sz);
#ifdef _UT
    int x = 12, y = 67;
    int cp = cmp(&x,&y);
    printf("==> cp =%d\n",cp);
#endif // 0    ;
    printf("asccendant =>\n");
    qsort(simpleTab,_sz,sizeof(int),cmp);
    display(simpleTab, _sz);

    printf("descendant =>\n");
    gAsc = -1;
    qsort(simpleTab,_sz,sizeof(int),cmp);
    display(simpleTab, _sz);
    return 0;
}
