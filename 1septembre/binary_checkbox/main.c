#include <stdio.h>
#define UINT unsigned int
#define UCHAR unsigned char

#define NONPAYE  0  //0000
#define COMPTANT 1  //0001
#define CHEQUE   2  //0010
#define VIREMENT 4  //0100
#define CREDIT   8  //1000

int saisirPaiement(){
  int rep;
  UCHAR mode_paiement = NONPAYE;
  printf("donner le mode de paiement avec réponse 0/1==> \n");

  printf("comptant ?");
  scanf("%d",&rep);
  if (rep==1)
     mode_paiement|= COMPTANT;

  printf("\ncheque ?");
  scanf("%d",&rep);
  if (rep==1)
     mode_paiement|= CHEQUE;

  printf("\nvirement ?");
  scanf("%d",&rep);
  if (rep==1)
     mode_paiement|= VIREMENT;

  printf("\ncrédit ?");
  scanf("%d",&rep);
  if (rep==1)
    mode_paiement|= CREDIT;

  printf("mode_paiemnt = %d\n", mode_paiement);
  return mode_paiement;
}

void displayPaiement(Somme,mode_paiement){
    printf("la somme %d a ete payée : ",Somme);
    if (mode_paiement & COMPTANT )
         printf ("comptant ");
    if (mode_paiement & CHEQUE)
         printf ("-cheqe ");
    if (mode_paiement & VIREMENT)
         printf ("virement ");
    if (mode_paiement & CREDIT)
         printf ("-credit ");
    printf ("\n");

}
int main(int argc, char* argv[]) {
     UINT Somme = 1200;
     do {
       UCHAR mode_paiement =saisirPaiement();
       if (mode_paiement == 0)
         break;
       displayPaiement(Somme,mode_paiement);
     }while (1);

    return 0;
}
