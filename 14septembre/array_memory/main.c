#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* pchar;

void func2(char *string) {
   strcpy(string, "lune");
}
char *func1() {
   char string[10];
   strcpy(string, "terre");
   printf("=>func1 (a):[0x%x] %s\n", string, string);
   func2(string);
   printf("=>func1 (b):[0x%x] %s\n", string, string);
   return string;
}

char *func3(){
   char *ps = malloc(10);
   strcpy(ps,"Venus");
   printf("=> func3: [0x%x] s=%s\n",ps, ps);
   return  ps;
}

void func4(char **ps){
   *ps = malloc(10);
   strcpy(*ps,"Mercure");
   printf("=> func4: [0x%x] s=%s\n",*ps, *ps);
   printf("=> func4: [%c,%c] =>%d\n",**ps,(*ps)[1],(*ps)[strlen(*ps)]);
}

void func5(pchar *ps){
   *ps = malloc(10);
   strcpy(*ps,"Saturn");
   printf("=> func5: [0x%x] s=%s\n",*ps, *ps);
   printf("=> func5: [%c,%c] =>%d\n",**ps,(*ps)[1],(*ps)[strlen(*ps)]);
}


void func6(char **ps){
   static char string[10];
   *ps = string;
   strcpy(string,"Uranus");
   printf("=> func6: [0x%x] s=%s\n",*ps, *ps);
   printf("=> func6: [%c,%c] =>%d\n",**ps,(*ps)[1],string[strlen(*ps)]);
}


int main(void) {
    const int L = 3;
    const int C = 2;
    int Echiquier[L][C] ;
    // initialisation premiÃ¨re ligne
    Echiquier[0][0] = 2;
    Echiquier[0][1] = 3;
    // initialisation deuxiÃ¨me ligne
    Echiquier[1][0] = 4;
    Echiquier[1][1] = 5;
    // initialisation troisiÃ¨me ligne
    Echiquier[2][0] = 6;
    Echiquier[2][1] = 7;

    for (int i = 0 ; i < L ; i++){
        printf("%d=>",i+1);
        for (int j = 0 ; j < C ; j++)
           printf("%d ",Echiquier[i][j]);
        printf("\n");
    }
    printf("=============================\n");

   //char s[10] = "Jupiter";//RW stack memrory (defined as array of char)
   char *s = malloc(10);//s is variable pointer on char in heap memory
   //const char *s="Jupiter"; //RO Memory
   strcpy(s,"Jupiter");
   printf("1. s=%s\n",s);
   strcpy(s,"Mars");
   printf("2. s=%s\n",s);
   func2(s);
   printf("3. s=%s\n",s);
   free(s);

   s = func1();
   printf("main: [0x%x] s=%s\n",s, s);

   s = func3();
   printf("main: [0x%x] s=%s\n",s, s);
   free(s);
   s = NULL;
   //s a varibale pointer on char on the stack !
   printf("main: [s=0x%x] [&s=0x%x]\n",s, &s);//mercure
   func4(&s);
   printf("main: [0x%x] s=%s\n",s, s);//mercure
   free(s);
   s = NULL;

   printf("main: [0x%x] s=%s\n",s, s);//mercure
   func5(&s);
   printf("main: [0x%x] s=%s\n",s, s);//saturn
   free(s);
   s = NULL;

   printf("main: [s=0x%x] [&s=0x%x]\n",s, &s);
   func6(&s);
   printf("main: [0x%x] s=%s\n",s, s);//mercure
   //free(s);
   s = NULL;

   return 0;
}
