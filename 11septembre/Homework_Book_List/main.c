#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int length=0;

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

void Initialize_adressBook(struct Telephone *pABook[]){
    printf("going to fill the address book!\n");
    char sName[24], surName[24];
    int i = 0;
    do{
        if(i<length){
        printf("give name (\"x\"to exit)=>");
        scanf("%s", sName);
        printf("give surname (\"x\"to exit)=>");
        scanf("%s", surName);
        pABook[i]=malloc(sizeof(struct Telephone));
        strcpy(pABook[i] -> Nom ,sName);
        strcpy(pABook[i] -> Prenom ,surName);
        Attribute(pABook[i]);
        i++;
        }else{
            printf("depassement memoire !!!");
            break;}
    }while(1);

}



int main()  {
    int i=0;
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
    printf("please enter the size of the addressBook \n");
    scanf("%d",&length);
    struct Telephone *AddressBook[length];//a static array of pointers on Telkephone struct
    Initialize_adressBook(AddressBook);
    //afficher le tableau
    do{
       Display(AddressBook[i]);
        i++;
        if (i>=length)
            break;
    }while(1);
    i=0;
    //Liberer la memoire apres affichage
    do{
       free(AddressBook[i]);
       AddressBook[i]=NULL;
        i++;
        if (i>=length)
            break;
    }while(1);


    return 0;
  }