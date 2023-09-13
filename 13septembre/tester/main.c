#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef int (*DynamicFunction)(int,int);

int main() {
    FILE *file;
    char functionCode[1000];
    char text[1000]; 
    file = fopen("function_code.txt", "w");
    printf("Enter text (type 'exit' on a line to exit):\n");

    while (1) {
        fgets(text, sizeof(text), stdin);

        if (strcmp(text, "exit\n") == 0) {
            break;
        }
        fputs(text, file);
    }
    fclose(file);
    file = fopen("function_code.txt", "r");

    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    fgets(functionCode, sizeof(functionCode), file);

    fclose(file);


    printf("Read function code:\n%s\n", functionCode);


    FILE *tempFile = fopen("temp_function.c", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        return 1;
    }
    fprintf(tempFile, "#include <stdio.h>\nint dynamic_function(int n1,int n2) { %s }\n", functionCode);
    fclose(tempFile);

    if (system("gcc -shared -o dynamic_function.dll temp_function.c") != 0) {
        perror("Error compiling the dynamic function");
        return 1;
    }

    HMODULE libraryHandle = LoadLibrary("dynamic_function.dll");
    if (libraryHandle == NULL) {
        fprintf(stderr, "Error loading dynamic library\n");
        return 1;
    }

    DynamicFunction dynamicFunction = (DynamicFunction)GetProcAddress(libraryHandle, "dynamic_function");
    if (dynamicFunction == NULL) {
        fprintf(stderr, "Error getting function pointer\n");
        return 1;
    }
    int n1,n2;
    printf("give first number:\n");
    scanf("%d",&n1);
    printf("give second number:\n");
    scanf("%d",&n2);
    printf("resultat de function dynamic =%d",dynamicFunction(n1,n2));

    FreeLibrary(libraryHandle);

    return 0;
}
