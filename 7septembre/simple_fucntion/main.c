#include <stdio.h>
#include <stdlib.h>

void Remise (int Code) {
    float tva = 19;
    printf("get the code=%d\n",Code);
    printf("pourcentage=%.3f%% \n", Code *(100.f+tva)/100);
    Code = Code *(100+tva)/100;
    printf("code =%d\n",Code);
}
int main(int argc, char* argv[]) {
      int i = 1990;
      Remise(i); //passage de la valeur de i=1990 $$$$
      Remise(1990); //passage de la valeur de i=1990 $$$$
      printf("la Valeur de i demeure :%d\n",i) ;
      return 0;
  }
