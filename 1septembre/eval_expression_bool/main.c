#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fct(int val){
    printf(" ==>Recours �  l'Appel �  la fonction fct\n");
    if (val >= 10)
        return true; //true
    return false; //false
}
int main() {
    printf("Hello world lhs & rhs!\n");

    int a = 10;
    do{
        printf ("entrer votre valeur de a (a== 0 exit):");
        scanf("%d",&a);
        printf ("1. Premier test avec ET logique......\n");
        if ((a == 19) && (fct(a)==1))
            printf ("expression �  true !\n");
        else
            printf ("expression �  false !\n");

        printf ("2.second test avec OU logique......\n");
        if ((a == 10) || (fct(a)==1))
            printf ("expression �  true !\n");
        else
            printf ("expression �  false !\n");
    }while (a != 0);

    return 0;
}
