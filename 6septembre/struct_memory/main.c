#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int CountryCode;
   char sTown[26];
   char street[26];
}stAddress;

typedef struct{
   int id;
   char sName;
   char sFamilt[26];
   stAddress *pAddress; //composition relationship <=> 'Association de comosition'
}stPerson;

int main() {
    printf("Hello memory within struct world!\n");
    printf("sizeof(stAddress)=%d\n",sizeof(stAddress));
    printf("sizeof(stPerson)=%d\n",sizeof(stPerson));

    printf("sizeof(stAddress *)=%d\n",sizeof(stAddress*));

    //by default the person could not have an address
    stPerson p1={1000,"Salah", "Ali", NULL};
    stPerson personTab[] = {p1, {1000,"Mourad", "Ali", NULL},
                                {1000,"Samir", "Ali", NULL}
                           };

    return 0;
}
