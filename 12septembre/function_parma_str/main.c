#include <stdio.h>
#include <string.h>

#define MAXSTR 50

void displayString(const char str[]);
void displayString2(const char *str);
void manipString(char str[],int max);
void manipString(char *str,int max);

int main()
{
    int k = 25;
    //char str[MAXSTR+1];
    int _Max;
    printf("give the max of your string:");
    scanf("%d",&_Max);
    char *str = malloc(_Max * sizeof(char));
    k++;
    printf("Enter string (max of %d): ", _Max * sizeof(*str));
    //gets(str); 
    scanf("%s",str);
    displayString(str);     // Passing string c to function.
    displayString2(str);     // Passing string c to function.
    str[0] = str[0]+'A'-'a'; //mutable $$
    displayString(str);     // Passing string c to function.
    displayString2(str);     // Passing string c to function.
    manipString(str,_Max); //can call with manipString(&str);
    manipString2(str,_Max); //can call with manipString2(&str);
    printf("k=%d\n",k);
    free(str);
    return 0;
}
void displayString(const char str[]){
    printf("String Output: ");
    puts(str); //printf("%s",str);
}
void displayString2(const char *str){
    printf("String Output: ");
    puts(str);//printf("%s",str);
}

void manipString(char str[],int maxstr){
    printf("Manip Output: ");
    if (str[1] >='a' && str[1] <= 'z')
       str[1]=str[1]+'A'-'a';//Mutable
    else if (str[1] >='A' && str[1] <= 'Z')
       str[1]=str[1]+'a'-'A';//Mutable
    puts(str); //printf("%s",str);
    printf("len = %d on a memory size=%d\n",strlen(str),sizeof(*str)*maxstr);
}
void manipString2(char *str,int maxstr){
    printf("Manip2 Output: ");
   if (str[1] >='a' && str[1] <= 'z')
       str[1]=str[1]+'A'-'a';//Mutable
    else if (str[1] >='A' && str[1] <= 'Z')
       str[1]=str[1]+'a'-'A';//Mutable
    puts(str);//printf("%s",str);
    printf("len = %d on a memory size=%d\n",strlen(str),sizeof(*str)*maxstr);
}

