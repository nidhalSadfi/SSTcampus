#include <stdio.h>
#include <stdlib.h>

int main () {
  int m,d,y;
  char sday[16];
  printf("introduce your birth day => (pls respect day mon year dayofweek)");
  scanf("%d %d %d %s",&d,&m,&y,sday);

  char slongdate[36];
  sprintf(slongdate,"%d/%d/%d (%s)\n",d,m,y,sday);
  printf("your date is => %s\n",slongdate);
  sscanf (slongdate,"%d %d %d %s",&d,&m,&y,sday);
  printf("the date is %d-%d-%d\n",d,m,y);

  printf("introduce your name surname country =>");
  char sidentity[3][26];//allocation satique
  char *pidentity[3];
  
  for (int i = 0; i < 3 ; i++)
     pidentity[i] = malloc(26);
  scanf("%s %s %s",sidentity[0],sidentity[1],sidentity[2]);
  printf("identity=> %s %s, your country is%s\n",sidentity[0],sidentity[1],sidentity[2]);

  scanf("%s %s %s",pidentity[0],pidentity[1],pidentity[2]);
  printf("identity=> %s %s, your country is%s\n",pidentity[0],pidentity[1],pidentity[2]);

  for (int i = 0; i < 3 ; i++)
     free(pidentity[i]);

  char sentence []="Anis is 12 years old";
  char str [20],str2[20];
  int i;
  sscanf (sentence,"%s %s %d",str,str2,&i);
  printf ("scanf result ===> %s/%s-> %d\n",str,str2,i);
  return 0;
}
