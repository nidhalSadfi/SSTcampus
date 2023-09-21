 int callFunct(int *i){
   (*i)+=10;
   return 10;
 }

 int main() {
   int j = 14;
   callFunct(j);
   printf( "%d\n", j);
 }