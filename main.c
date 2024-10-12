#include <stdio.h>

int menu();

int main()
{
    int opcion;
    do
    {
        opcion = menu();
    } while (opcion < 0 || opcion > 5);
    
    printf("Opcion: %d", opcion);

    return 0;
}

int menu()
{
    int opcion;
    printf("Menu\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    scanf("%d", &opcion);

    return opcion;
}