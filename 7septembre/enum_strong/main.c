#include <stdio.h>
#include <stdlib.h>
#include "animals.h"
#include "session.h"
//typedef enum {dog, cat, horse, mouse, parrot} Animal;
//typedef enum {automn, winter, spring, summer} Season;
int main() {
    printf("Hello enuy strong solution!\n");

    Animal a1, a2;
    a1 = mouse;
    a2 = dog;
//    a1++; //=>NOK !
  //  a2+= 20;// =>NOK !
    Animal *pa = &a2;

    Season s1 = spring;
    Season s2 = summer;
    Season s;
    s =s1;
    //s = a1;// => NOK NOK NOK !

    return 0;
}
