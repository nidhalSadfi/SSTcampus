#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>

char *strndup(const char *str, int chars) {
    char *buffer;
    int n;
    buffer = (char *) malloc(chars +1);
    if (buffer) {
        for (n = 0; ((n < chars) && (str[n] != 0)) ; n++) buffer[n] = str[n];
        buffer[n] = 0;
    }
    return buffer;
}
int main(void) {
    const char *s1 = "String";
    char *s2 = strndup(s1, 2);
    printf("strndup(\"String\", 2) == %s\n", s2);
    free(s2);
    /////////////////////////////////
    //char *s2 = s1; //pointers copy !!!
    //s2[0]='x';//plantage !!
    s2 = strdup(s1);
    assert(s1 != s2);//2 different pointers !!
    assert(strcmp(s1, s2) == 0);
    s2[0]='X'; //s2 is a heap memory $$$
    printf("strdup(s1) s2== %s\n", s2);

    char *s3 = strdup(s2);
    assert(s2 != s3);
    assert(strcmp(s2, s3) == 0);
    s3[0]='Y'; //s3  is also a heap memory $$$
    printf("strdup(s2) s3== %s\n", s3);
    free(s2);

    char *s4,*s5,*s6;

    s6 = strdup(s5 = strdup(s4 = strdup(s3)));

    printf("s6=%s\n",s6);
    free(s3);
    free(s4);
    free(s5);
    free(s6);
    return 0;
}
