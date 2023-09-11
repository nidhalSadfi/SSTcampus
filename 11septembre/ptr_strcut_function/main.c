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

int main()  {
    struct Telephone tel;
    strcpy(tel.Nom, "Mabrouk ");
    strcpy(tel.Prenom, " Mohamed ");
    tel.Numero= 71452452;
    Affiche(tel);
    printf("1.tel.Numero=%d\n",tel.Numero);
    Display(&tel);
    printf("2.tel.Numero=%d\n",tel.Numero);
    return 0;
  }
