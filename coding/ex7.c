int main() {
    int num = 1500;
    if (num >= 0)
        if (num >= 1600)
            printf("a");
        else if (num >= 1500)
            printf("b");
        else if (num >= 1000)
            printf("*c");
    if (num >= 100)
        printf("d");
    if (num >= 10)
        printf("e");
    else
        printf("f");
    printf("g");
    return 0;
}