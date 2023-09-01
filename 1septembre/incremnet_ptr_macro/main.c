#include <stdio.h>
#include <stdlib.h>

#define SZTAB(ptab) sizeof(ptab)/sizeof(*ptab)
typedef unsigned char TypeVal;

int main()
{
    printf("Hello increment pointers world!\n");
    TypeVal aTab[] = {17,23,27,89,0};
    aTab[1] += 12;
    TypeVal *p = aTab;
    TypeVal v = *p++; //incrementation postfoixed of address
    printf("v = %d, *p=%d\n",v, *p);
    printf("1. aTab[0]=%d\n",aTab[0]);

    p = aTab;
    v = (*p)++; //content postfixed increment !
    printf("v = %d, *p=%d\n",v, *p);
    printf("2. aTab[0]=%d\n",aTab[0]);

    p = aTab;
    v = ++(*p); //content prefixed increment !
    printf("v = %d, *p=%d\n",v, *p);
    printf("3. aTab[0]=%d\n",aTab[0]);

    int i;
    TypeVal *nil = aTab+SZTAB(aTab);
    for (i = 0, p = aTab; p!=nil ; p++, i++){
        printf("%d=>%d/",i, *p);
        printf("aTab[%d]=>%d ",i, aTab[i]);
    }
    printf("\n");
    printf("p=0x%x , nil=0x%x\n",p, nil);

    printf("Reverse...\n");
    for (i = SZTAB(aTab)-1, p = nil-1; p >= aTab ; p--, i--){
        printf("%d=>%d/",i, *p);
        printf("aTab[%d]=>%d ",i, aTab[i]);
    }
    printf("\n");
    printf("p=0x%x , nil=0x%x\n",p, nil);

    return 0;
}
