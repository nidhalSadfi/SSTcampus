#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello conversion worlds!\n");

    int x = 1;
    int y = 2;
    float z = 2;

    float f= x/y;
    printf("1. f = %.3f (=> division entière)\n",f);

    f = x / z;
    printf("2. f = %.3f (=> division flottante)\n",f);

    f = 1 / 2.0f; //constante flottante 2.0 sur 4 bytes
    printf("3. f = %.3f (=> division flottante)\n",f);

    f = (float)1/2;
    printf("4. f = %.3f (=> division flottante )\n",f);

    f = (float)(1 / 2);
    printf("5. f = %.3f (=> division entière)\n",f);

    f = (float)(1.f / 2);
    printf("6. f = %.3f (=> division flottante� \n",f);

    f = (float)(1.f - x/y);
    printf("7. f = %.3f (=> division entière)\n",f);

    double xx = 1.2;
    // Explicit conversion from double to int
    double sum = (int)xx + 1;
    printf("sum = %.3f\n", sum);

    return 0;
}
