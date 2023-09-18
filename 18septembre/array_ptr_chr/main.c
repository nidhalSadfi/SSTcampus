#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcpy (char * dst, const char * src) {
  char *p = dst;
  while (*dst++ = *src++) ;
  return p;
}
void *voidstrcpy (void * dst, const void * src) {
  void * destination = dst;
  char *cDst = (char*)dst;
  const char *cSrc = (const char*)src;
  while (*cDst++ = *cSrc++) ;
  return destination;
}

int main() {
    char nom[26];
    strcpy(nom,"Salah");
    const char *famille = "BenABC";
    char *kabila = famille;
    //famille[0]='F'; COMPILE NOK
    // kabila[0]='F'; PLANTAGE  !!!!
    printf("address de nom:%p (%s)\n",nom,nom);
    char *s = mystrcpy(nom,"Mohamed");
    printf("address de nom:%p (%s)\n",nom,nom);
    printf("address de s:%p (%s)\n",s,s);

    char *t = strcpy(nom,"Ali");
    printf("address de t:%p (%s)\n",t,t);
    strcpy(t,"Amine");
    printf("address de s:%p (%s)\n",s,s);
    printf("address de nom:%p (%s)\n",nom,nom);

    printf("address de famille:%p (%s)\n",famille,famille);
    famille = nom;
    ///////////////////////////////////////
    //diffÃ©rence entre tableu et pointeur:
    //===>   nom = famille; lâ€™adr de tab est invaraible !
    //////////////////////////////////////
    famille = &nom[0];
    printf("address de nom:%p (%s)\n",famille,famille);

    voidstrcpy((void*)famille,(const void*)"Slim");
    printf("with voidstrcpy address de nom:%p (%s)\n",famille,famille);
    return 0;
}
