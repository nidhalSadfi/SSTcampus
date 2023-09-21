#include <stdio.h>
#include <stdlib.h>

#define NONPAYE  0  //0000
#define COMPTANT 1  //0001
#define CHEQUE   2  //0010
#define VIREMENT 4  //0100
#define CREDIT   8  //1000

typedef struct {
    unsigned char nonpaye:1;
    unsigned char comptant:1;
    unsigned char cheque:1;
    unsigned char virement:1;
    unsigned char credit:1;
    unsigned char m6:1;
    unsigned char m7:1;
    unsigned char m8:1;
}toptions;

int main() {
    printf("sizeof(otions)=%d\n",sizeof(toptions));
    unsigned char _opt = COMPTANT | CHEQUE |CREDIT;
        printf("_opt = %d\n",_opt);
    printf("1. %s comptant on stOpt\n",_opt&COMPTANT?"Par":"Sans");
    printf("1. %s crédit on stOpt\n",_opt&CREDIT?"Par":"Sans");
    printf("=========================================\n");

    toptions stOpt;
    stOpt.comptant = 1;
    stOpt.cheque = 1;
    stOpt.virement = 1;
    stOpt.credit = 0;
    stOpt.nonpaye = 0;
    stOpt.m6 =stOpt.m7 =stOpt.m8 = 0;
    printf("2. %s comptant on pOpt\n",stOpt.comptant?"Par":"Sans");
    printf("2. %s cheque on pOpt\n",stOpt.cheque?"Par":"Sans");
    printf("2. %s credit on pOpt\n",stOpt.credit?"Par":"Sans");

    unsigned char *modepayment=(unsigned char*)&stOpt;
    printf("==>save _opt = %d\n",*modepayment); //save on database !!!the value 14 !
///


///
//in order to retreive thje payemeny mode !!
    unsigned char readOpt = *modepayment;
    printf("\n==> Retreive _opt = %d\n",readOpt); //read from database !!!the value 14 !

    toptions *pOpt = (toptions*)&readOpt;

    printf("2. %s comptant on pOpt\n",pOpt->comptant?"Par":"Sans");
    printf("2. %s cheque on pOpt\n",pOpt->cheque?"Par":"Sans");
    printf("2. %s credit on pOpt\n",pOpt->credit?"Par":"Sans");

    return 0;
}
