#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*return 0: *p valid ocntent
return -1: site entry error
*/

int valboursiere (const char *site, int *pv){
    if (!strcmp (site, "Tunis"))
       *pv = 19;
    else if (strcmp (site, "Alger")==0)
        *pv = 37;
    else if (strcmp (site, "Casa")==0)
        *pv = 46;
    else //errur d'entrÃ©e
       return -1;

    //printf ("to return :%d\n",*pv);
    return 0;
}

int valboursiere2 (const char *site, int **pv){//retreive a vailid address from heap
    printf("entry static address given of pv=0x%x\n",pv);
    printf("its content *pv now is 0x%x\n",*pv);
    if (*pv == NULL)
        *pv = malloc(sizeof(int));
    printf("its content *pv after malloc is 0x%x\n",*pv);

    if (!strcmp (site, "Tunis"))
       **pv = 19;
    else if (strcmp (site, "Alger")==0)
        **pv = 37;
    else if (strcmp (site, "Casa")==0)
        **pv = 46;
    else if (strcmp (site, "Triploi")==0)
        **pv = 51;
    else //errur d'entrÃ©e
       return -1;
    printf("content of malloc address is %d\n",**pv);
    return 0;
}
void anFct(int *i){
    printf("entry address given =0x%x\n",i);
   *i = 19;
}
int main(){
    int k = 45;
    printf("address of K =0x%x\n",&k);
    anFct(&k);
    printf("%d\n",k);

    printf("Hello para;m pointer world!\n");
    char sTown[12];
    do{
        printf("give town (\"x\"to exit)=>");
        scanf("%s", sTown);
        if (!strcmp(sTown, "x"))
            break;
        int vBourse = 0;//allocation memoire statique dans la pile $$
        int ret = valboursiere(sTown, &vBourse);
        if (ret < 0){
            printf("value given to service is invalid !!!<ret=%d>\n",ret);
            continue;
        }
        printf("bourse value of %s is %d\n",sTown, vBourse);
    }while(1);


    int *pBourse = NULL;//No memory allocation
    pBourse = malloc(sizeof(int));
    strcpy(sTown,"Casa");
    int ret = valboursiere(sTown, pBourse);
    if (ret < 0){
        printf("value given to service is invalid !!!<ret=%d>\n",ret);
        return 0;
    }

    printf("bourse value of %s is %d\n", sTown, *pBourse);
    free(pBourse);
    pBourse = NULL; //pBourse is address variable having it is own static address &pBourse
    printf("=======================================\n");
    strcpy(sTown,"Triploi");
    printf("pBourse is address variable on int having it is own static address &pBourse\n");
    printf("address of &pBourse=Â°x%x, it scontent is andd addres on int:0x%x\n",&pBourse, pBourse);
    ret = valboursiere2(sTown, &pBourse);
    if (ret < 0){
        printf("value given to service is invalid !!!<ret=%d>\n",ret);
        return 0;
    }

    printf("bourse value of %s is %d\n", sTown, *pBourse);
    printf("the free will be done on pBourse=0x%x\n",pBourse);
    free(pBourse);
    pBourse = NULL;
    return 0;
}
