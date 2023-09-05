int main() {
    printf("Hello pointers on structure world!\n");

    int i; //integer variable
    int *p = NULL; //pointer variable

   printf("Address of the symbol i=0x%x, of the symbol p=0x%x\n", &i, &p);

   printf("Address on heap pointed by p is=>0x%x\n", p);
   p = malloc(sizeof(int));
   printf("Address on heap pointed by p is=>0x%x\n", p);
   *p=156;
   printf("*p=%d\n",*p);
   free(p);
   p = &i;
   printf("Now Address on heap pointed by p is=>0x%x <=>&i:0x%x\n",
                                            p,&i);
}
