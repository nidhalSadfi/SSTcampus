#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayBinary(int val){
   char strInt[32];
   int i;
   for (i = 0; val != 0 ; i++,val >>= 1)//the stop criterai is val==0
     strInt[i]='0'+ (val & 1);

   strInt[i] = 0;//mark the end of the string !
   printf("%s\n",strrev(strInt));
}

int main(){
    printf("Hello numeric world!\n");

    int a = 101; //100 is a decimal constant
    int b = -100; //-100 is a decimal constant
    int c = 07356; // 0365 is interpreted as an octal constant
    int d = 0x75bC89F; // 75bC89F is interpreted as an hex constant
    int e = 0b01010;
    printf("interpret vairables as decimals : a=%d, b=%d, c=%d, d=%d, e=%d\n",a,b,c,d,e);
    printf("interpret vairables as Hexdecimals : a=0x%x, b=0x%x, c=0x%x, d=0x%x, e=0x%x\n",a,b,c,d,e);

    printf("a=");
    displayBinary(a);
    printf("e=");
    displayBinary(e);


    return 0;
}
