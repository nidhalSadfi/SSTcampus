#include <stdio.h>
#include <stdlib.h>

#define FOO 1
#define BAR
#if FOO
    int TVA1;
#endif

#ifdef FOO
  int REMISE;
#endif
int main() {
    printf("Hello world precompiler .............!\n");
#if FOO
    printf("Hello code in #if FOO!\n");
#endif
#ifdef FOO
  // will compile this ?
  printf("Hello code in #ifdef FOO!\n");
#endif
#if defined(FOO2) // will compile this ?
   printf("Hello code in #ifdef FOO!\n");
#endif
#if (defined(BAR) && !defined(FOO))
  // will compile this ?
  printf("Hello code in #if defined TAR!\n");
#endif
#if defined(ARM)
  // will compile this ?
  printf("Hello code in case of ARM target #if defined ARM in compiler opttions !\n");
#else// will compile this ?
  printf("Hello code in for a cadr not ARM #if defined TAR! in compiler options\n");
#endif
    return 0;
}
