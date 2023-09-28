#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void concatenation (char * destination,
                    size_t taille_maxi, ...){
    va_list arguments;
    char *source;
    va_start(arguments, taille_maxi);
    while (1) {
        source = va_arg(arguments, char *);
        if (source == NULL)/* fin des arguments */
           break;
        printf("source = %s\n",source);
        strncat(destination,source, taille_maxi-strlen(destination)-1);
        printf("=>dest=%s\n",destination);
    }
    destination[taille_maxi-1]=0;
    va_end(arguments);
}

void concatenate (char * destination, ...){
    va_list arguments;
    char *source;
    va_start(arguments, destination);
    int taille_maxi = va_arg(arguments, int);
    int nbArg = (int)atoi(va_arg(arguments, char *));
    int i = 0;
    while (i < nbArg) {
        source = va_arg(arguments, char *);
        printf("source = %s\n",source);
        strncat(destination,source, taille_maxi-strlen(destination)-1);
        printf("=>dest=%s\n",destination);
        i++;
    }
    destination[taille_maxi-1]=0;
    va_end(arguments);
}

int  main (void){
    char chaine[20]="";
    concatenation(chaine, 20, "123", "456", "7890", "1x", NULL);
    printf("%s\n", chaine);
    chaine[0]=0;
    concatenation(chaine, 20, "1234567890", "abcdefg","1234567890","1234567890", "123", NULL);
    printf("%s\n", chaine);
    printf("=============================================\n");
    chaine[0]=0;
    concatenate(chaine, 20, "4", "123", "456", "7890", "1x");
    printf("%s\n", chaine);
    chaine[0]=0;
    concatenate(chaine, 20, "5", "1234567890", "abcdefg","1234567890","1234567890");
    printf("%s\n", chaine);

    return 0;
}
