#include <stdio.h>
#include <stdlib.h>
int main(){printf("Hello world!\n");int x;do{printf("give value of x (0 to exit) :");scanf("%d",&x);int n = (x >1 && x<10) ? 100+x : (x >11 && x<100) ? 200+x : 300+x ; /*ternaire $$$*/printf("n = %d\n",n);}while (x!=0);return 0;}
