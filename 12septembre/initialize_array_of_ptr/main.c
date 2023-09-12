#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZBOOK 24

struct Telephone {
  char Nom[30+1];
  char Prenom[30+1];
  int Numero;
};
void Affiche(struct Telephone t ){
    printf("Nom : %s\n" , t.Nom);
    printf("Prenom : %s\n" , t.Prenom );
    printf("Numero : %d\n" , t.Numero );
    t.Numero = 98997525;
}

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

void Initialize_addressBook(struct Telephone *pABook[],int sz){

}
void Provisionning_adressBook(struct Telephone *pABook[], int *nbTel){
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
        pABook[i] = malloc(sizeof(struct Telephone));
        strcpy(pABook[i]->Nom, sName);
        strcpy(pABook[i]->Prenom, surName);
        Attribute(pABook[i]);
        i++;
        if (i >= 24)
            break;
    }while(1);
    *nbTel = i;
    memset(&pABook[i],0, (SZBOOK-i)*sizeof(*pABook));
    while (i < SZBOOK)
        pABook[i++] = NULL;
}
void free_adressBook(struct Telephone *pABook[], int _sz){
    for (int i = 0; i < _sz ; i++)
        if (pABook!= NULL)
           free(pABook[i]);
}

void Initialize_AddressBook(struct Telephone *pABook[],int _sz){
    for (int i = 0; i < _sz ; i++)
        pABook[i] = NULL;
    //<==> equive to =>
    memset(pABook,0, sizeof(*pABook) * _sz);
}
int main()  {
    int nbmois[SZBOOK];//static allocation of 12 int memories in contigious way
    printf("sizeof(nbmois)=%d\n",sizeof(nbmois));
    int *nbSalary[SZBOOK];//static allocation of 12 int pointers
    printf("sizeof(nbSalary)=%d\n",sizeof(nbSalary));
    printf("==============================");
    struct Telephone tel;
    strcpy(tel.Nom, "Mabrouk ");
    strcpy(tel.Prenom, " Mohamed ");
    tel.Numero= 71452452;
    Affiche(tel);
    printf("1.tel.Numero=%d\n",tel.Numero);
    Display(&tel);
    printf("2.tel.Numero=%d\n",tel.Numero);

    printf("================================\n");
    Attribute(&tel);
    Display(&tel);
    struct Telephone *pTel2 = malloc(sizeof(struct Telephone));
    strcpy(pTel2->Nom, "Salam ");
    strcpy(pTel2->Prenom, "Ali");
    Attribute(pTel2);
    Display(pTel2);
    free(pTel2);
    printf("================================\n");
    struct Telephone *AddressBook[SZBOOK];//={NULL};//a static array of pointers on Telkephone struct;
    for (int i = 0 ; i < SZBOOK ; i++)
        AddressBook[i] = NULL;
    //equivalent to ==>
    printf("sizeof(AddressBook) = %d\n",sizeof(AddressBook));
    printf("sizeof(AddressBook) = %d\n",SZBOOK*sizeof(*AddressBook));
    memset(AddressBook,0,sizeof(AddressBook));
    Initialize_AddressBook(AddressBook, SZBOOK);

    //////////////////////////////////////
    int nbTel;
    Provisionning_adressBook(AddressBook,&nbTel);
    printf("provisionning of %d telephones \n", nbTel);

    for (int i = 0; i < SZBOOK ; i++){
        if (AddressBook[i]!=NULL){
          Display(AddressBook[i]);
          printf("=================\n");
        }else
           break;
    }

    free_adressBook(AddressBook,SZBOOK);

    return 0;
  }
