#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    //Ox désigne l'ecriture d'un nombre Héxa
    //"%d" désigne l'affichage d'un nombre en décimal
    int a = 0x16;
    int b = 6;
    int c = 0x10;
    printf("%d",a|b&c);
}