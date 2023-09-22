#include <stdio.h>
#include <stdlib.h>

//créatiuon d'un nouveau type mytTab t
typedef short mytTab;
typedef unsigned int UINT;

int main() {
    printf("Hello arrays world!\n");
    mytTab subs[] = {156,189,678,434,600, 879};
    printf("sizeof of subs array = %d\n", sizeof(subs));

    UINT nb_subs = sizeof(subs) /sizeof(subs[0]);
    printf("1. nb subscriber(sizeof(subs[0])) = %d\n",nb_subs);
    nb_subs = sizeof(subs) /sizeof(*subs);
    printf("2. nb subscriber(sizeof(*subs)) = %d\n",nb_subs);

    printf("ptr of subs array=0x%x\n",subs);
    printf("content of subs array=%d\n",*subs);
    for (UINT i = 0 ; i < nb_subs ; i++){
        printf("subs[%d](0x%x)=%d ",i, &subs[i], subs[i]);
    }
    printf("\n");

    mytTab *p = subs;
    printf("addres of p =0x%x\n",p);
    printf("addres of p+1 =0x%x\n",p+1);
    printf("content of p (p = subs) *p=%d\n",*p);
    printf("content of *(p+0) *p=%d\n",*(p+0));
    printf("content of p[0] (p = subs)=%d\n",p[0]);

    printf("content of p[1] (p = subs)=%d\n",p[1]);
    printf("content of *(p+1) (p = subs)=%d\n",*(p+1));

    int i = 4;
    printf("subs[%d]=%d\n",i,subs[i]);
    printf("*(p+%d)=%d\n",i,*(p+i));
    printf("*(subs+%d)=%d\n",i,*(subs+i));
    return 0;
}
