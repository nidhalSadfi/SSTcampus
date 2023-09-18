#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isClone(int sizeArray,int array[],int sizeArray2, int array2[]){
    if (sizeArray2 != sizeArray)
        return false;
    int i=0;
    for(int i=0;i<sizeArray2;i++){
        if (array[i]!=array2[i])
            return false;
    }



    return true;

}
int main() {
  int array[] = { 5,2,2,4 };
  int clone[] = { 5,2,2,4 };
  bool b = isClone(4,array,4,clone);
  printf("%s\n",(b ? "same" : "different"));

  return 0;
}
