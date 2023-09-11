#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    static number = 98100100;
    pt->Numero = number++;
}

void Initialize_adressBook(struct Telephone *pABook[]){
    printf("going to fill the address book!\n");
    char sName[24], surName[24];
    int i = 0;
    do{
        printf("give name (\"x\"to exit)=>");
        scanf("%s", sName);
        if (!strcmp(sName, "x"))
            break;
        printf("give surname (\"x\"to exit)=>");
        scanf("%s", surName);
        
 }while(1);

}
void librate_memory(){
    
    
}

int main()  {
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

    struct Telephone *AddressBook[24];//a static array of pointers on Telkephone struct
    Initialize_adressBook(AddressBook);
    return 0;
  }
