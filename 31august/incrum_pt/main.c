#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello increment pointers world!\n");
    int aTab[] = {17,23,27,89,0};
    int *p = aTab;
    int v = *p++; //incrementation postfoixed of address
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
    for (i = 0, p = aTab; *p!=0 ; p++, i++){
        printf("%d=>%d/",i, *p);
        printf("aTab[%d]=>%d ",i, aTab[i]);
    }
    printf("\n");

    printf("p=0x%x , aTab+sizeof(aTab)=0x%x\n",p, aTab+(sizeof(aTab)/sizeof(int)));
    return 0;
}
