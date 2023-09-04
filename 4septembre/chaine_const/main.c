#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Hello world!\n");
  int a=5;     // initial value: 5
  int c = {2}; // initial value: 2
  int result;  // initial value undetermined
  a = a + c;
  result = a - c;
  char *chaine = "Salam Monde!"; //a string ! a char pointer on the first charcter
  char *chaine2 = "Salam Africa! \
                Salam Tunisia";
  char *chaine3 = "Salam Africa! "
                  "Salam Tunisia";

  printf("chaine2= %s\n",chaine2);
  printf("chaine3= %s\n",chaine3);

  int days[]={31,28,31,30,31,30,31,31,30,31,30,31};

  printf("\\n=%d, \\t=%d, \\0=%d\n",'\n','\t','\0');
  char pattern[] = { 'o','0',  'u', 'l', 0, 'd', '\0' };
  char pattern2[] = "ould"; //a shorthand

  printf("pattern(sizeof=%d, len=%d) =%s\n", sizeof(pattern), strlen(pattern), pattern);
  printf("pattern2 (sizeof=%d,len=%d) =%s\n", sizeof(pattern2), strlen(pattern2), pattern2);
  return 0;
}
