#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int CountryCode;
   char sTown[26];
   char street[26];
}stAddress;

typedef struct{
   int id;
   char sName[10];
   char sFamily[26];
   stAddress *pAddress; //composition relationship <=> 'Association de comosition'
}stPerson;

int main() {
    printf("Hello memory within struct world!\n");
    printf("sizeof(stAddress)=%d\n",sizeof(stAddress));
    printf("sizeof(stPerson)=%d\n",sizeof(stPerson));

    printf("sizeof(stAddress *)=%d\n",sizeof(stAddress*));

    //by default the person could not have an address
    int i = 1000;
    stPerson p1={i++,"Salah", "Ali", NULL};
    stPerson personTab[] = {p1, {i++,"Mourad", "Ali", NULL},
                                {i++,"Samir", "Ali", NULL}
                           };
    int _SZTab = sizeof(personTab)/sizeof(*personTab);

    for (int i = 0; i < _SZTab ; i++){
        printf("[%d](%s,%s)-", personTab[i].id, personTab[i].sName,personTab[i].sFamily);
        if (personTab[i].pAddress!=NULL){
            printf("@(%d %s %s)", personTab[i].pAddress->CountryCode,
                                  personTab[i].pAddress->sTown,
                                  personTab[i].pAddress->street);
        }
        printf("\n");
    }

    do{
        printf("get the order of person (from 1 to %d) to set his address (0 to quit):",_SZTab);
        int idx;
        scanf("%d",&idx);
        if (idx == 0)
          break;
        if (idx > _SZTab){
            printf("please give a valid index !!\n");
            continue;
        }
        if (personTab[idx-1].pAddress != NULL){
            printf("person already has an address !!!!\n)");
            continue;
        }
        personTab[idx-1].pAddress = malloc(sizeof(stAddress));
        personTab[idx-1].pAddress->CountryCode = 216;
        strcpy(personTab[idx-1].pAddress->sTown, "Tunis");
        strcpy(personTab[idx-1].pAddress->street,"Environnement");


    }while(1);

    for (int i = 0; i < _SZTab ; i++){
        printf("[%d](%s,%s)-", personTab[i].id, personTab[i].sName,personTab[i].sFamily);
        if (personTab[i].pAddress!=NULL){
            printf("@(%d %s %s)", personTab[i].pAddress->CountryCode,
                                  personTab[i].pAddress->sTown,
                                  personTab[i].pAddress->street);
        }
        printf("\n");
    }

    printf("cleanup memory !\n");
    int nbFree=0;
    for (int i = 0; i < _SZTab ; i++)
        if (personTab[i].pAddress!=NULL){
            free(personTab[i].pAddress);
            nbFree++;
        }
    printf("%d free of memories\n",nbFree);
}
