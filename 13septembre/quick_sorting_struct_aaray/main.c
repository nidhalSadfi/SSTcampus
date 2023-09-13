#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZBOOK 24

struct Telephone {
  char Nom[30+1];
  char Prenom[30+1];
  int Numero;
};


void Display(const struct Telephone *pt ){//passage du ptr en lecture seule$$
    printf("Nom : %s\n" , pt->Nom);
    printf("Prenom : %s\n" , pt->Prenom );
    printf("Numero : %d\n" , pt->Numero );
   // pt->Numero = 98997525;
}

void Attribute(struct Telephone *pt ){//passage du ptr en lecture seule$$
    static int number = 98100100;
    pt->Numero = number++;
}

void Provisionning_adressBook(struct Telephone *pABook, int *nbTel){
    printf("going to fill the address book!\n");
    char sName[24], surName[24];
    int i = 0;
    do{
        printf("give name (\"x\"to exit)=>");
        scanf("%s", sName);
        if (!strcmp(sName, "x"))
            break;
        printf("give surname =>");
        scanf("%s", surName);
        strcpy(pABook[i].Nom, sName);
        strcpy((*(pABook+i)).Prenom, surName);
        strcpy((pABook+i)->Prenom, surName);
        Attribute(&pABook[i]);
        i++;
        if (i >= SZBOOK)
            break;
    }while(1);
    *nbTel = i;
}
int cmp(const void *a , const void *b){
    struct Telephone *pa=(struct Telephone *)a;
    struct Telephone *pb=(struct Telephone *)b;
    int ret;
    if((ret=strcmp(pa->Nom,pb->Nom))!=0){
        return ret;
    }
    else{
        if((ret=strcmp(pa->Prenom,pb->Prenom))!=0)
            return ret;
    }
}
int main()  {
    //struct Telephone AddressBook[SZBOOK]; //a satic array(on Stack) of Telephone struct;

    struct Telephone *AddressBook;//a dynamic array(on Heap) of Telephone struct;
    AddressBook = malloc(sizeof(struct Telephone)*SZBOOK);
    int nbEntries = 0;
    //////////////////////////////////////
    Provisionning_adressBook(AddressBook,&nbEntries);
    printf("provisionning of %d telephones \n", nbEntries);
    qsort(AddressBook,nbEntries,sizeof(struct Telephone),cmp);
    for (int i = 0; i < nbEntries ; i++){
          Display(&AddressBook[i]);
          printf("=================\n");
     }

    free(AddressBook);

    return 0;
  }
