#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    //Ox désigne l'ecriture d'un nombre Héxa
    //"%d" désigne l'affichage d'un nombre en décimal
    int a = 0x018;
    int b = 0x10;
    printf("%d",a&b);
}   