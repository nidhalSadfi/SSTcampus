#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*return 0: *p valid ocntent
return -1: site entry error
*/

int valboursiere (const char *site, int *pv)
{
    if (!strcmp (site, "Tunis"))
       *pv = 19;
    else if (strcmp (site, "Alger")==0)
        *pv = 37;
    else //errur d'entrÃ©e
       return -1;

    //printf ("to return :%d\n",*pv);
    return 0;
}

int main()
{
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
    return 0;
}
