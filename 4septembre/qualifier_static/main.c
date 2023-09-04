#include <stdio.h>
#include <stdlib.h>

int gVal;

void comptage(int nVal) {
    int iLocal = 15;
    static sArray[]={10,20,30};
    static int nbCall=0, iCumul=0;
    nbCall += 1;
    iCumul += nVal;
    printf("nbCall[0x%x]=%d, iCumul[0x%x]=%d\n", &nbCall,nbCall,
                                               &iCumul,iCumul);
    iLocal++;
    printf("iLocal[0x%x]=%d\n",&iLocal,iLocal);

    gVal++;
    for (int i = 0 ; i < 3 ; i++)
        sArray[i]++;

    for (int i = 0 ; i < 3 ; i++)
        printf("sArray[%d][0x%x]=%d\n",i, &sArray[i],sArray[i]);

}


int main() {
    printf("Hello static qualifier world!\n");
    printf("1. gVal[0x%x]=%d\n",&gVal,gVal);
    comptage(10);
    printf("2. gVal[0x%x]=%d\n",&gVal,gVal);
    comptage(10);
    printf("3. gVal[0x%x]=%d\n",&gVal,gVal);
    comptage(10);
    printf("4. gVal[0x%x]=%d\n",&gVal,gVal);

    return 0;
}
