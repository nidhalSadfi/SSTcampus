#include <stdio.h>
#include <stdlib.h>

void my_int_func(int x) {
    printf( "my int value %d\n", x );
}

void another_int_func(int x) {
    printf( "the Other value is %d\n", 2*x );
}

void wrapperFunction(char *sName, void (*action)(int) ){
    printf("Hello %s\n",sName);
    printf("give a value from 1 to 19==>");
    int v;
    scanf("%d",&v);
    action(v);
    printf("==================================\n");
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

    foo = another_int_func;

    foo(78);

    foo = NULL; //Set poniter to NULL
    if (foo != NULL) //trest on the validity of pointer
      foo(780);
    printf("calling to wrapperfunctiuon...\n");
    //callback nature $$$$
    wrapperFunction("Mohamed Ali", &another_int_func);
 }
