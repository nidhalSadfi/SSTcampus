#include <stdio.h>
#include <stdlib.h>

void my_int_func(int x) {
    printf( "%d\n", x );
}

void  main() {
    void (*foo)(int); //a variable pointer on a
                 // function accpeting int returning void

    //staic call => a jump on the beginning on function code
    my_int_func(56);
    //==========================

    //a valid assign (having same signature) of
     // the function pointer on the variable pointerpointer==>
    foo = &my_int_func;
    ///////
    printf("my_int_func=0x%x foo=0x%x\n",&my_int_func, foo);
  /* call to my_int_func viu foo variable functyion pointer*/
    foo( 27 );

 }
