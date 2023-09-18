#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool search(const int * const begin,const int*const end,const int w){
    const int *p=begin;
    while(p!=(end)){
        if(w==*p)
            return true;
        p++;
    }
    return false;
}
int main(void) {
  int v[] = { 32,13,19,56,17,42,89,43 };
  const size_t size = sizeof v / sizeof v[0];
  const int * begin = &v[0];// = v
  const int * end = &v[size];// = (v + size)
  int w;
  do{
    printf("give me searched for element (0 to leave)\n");
    scanf("%d",&w);
    bool found = search(begin, end, w);
    printf("%d %s", w, (found ? "found\n" : "not found\n"));
  }while(w!=0);
  return 0;
}
