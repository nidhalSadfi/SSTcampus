#include <stdio.h>
#define UINT unsigned int
#define UCHAR unsigned char

#define NONPAYE  0  //0000
#define COMPTANT 1  //0001
#define CHEQUE   2  //0010
#define VIREMENT 4  //0100
#define CREDIT   8  //1000

int main(int argc, char* argv[])
{
     UCHAR mode_paiement = NONPAYE;

     printf("Choisir votre mode de paiement (opération de) ==>\n");
     mode_paiement = mode_paiement | COMPTANT ;
     mode_paiement |= VIREMENT;
     mode_paiement |= CREDIT;
    UINT Somme = 1200;
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

    return 0;
}
