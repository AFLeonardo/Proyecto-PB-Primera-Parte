#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funciones.c"

// ESTO SI FUNCIONA
int main()
{
    int opcion;
    bool ciclo = true;
    FILE *archivo;

    while (ciclo)
    {

        do
        {
            opcion = menu_principal();
            if (opcion < 0 || opcion > 10)
                printf("Opcion no valida. Intenta de nuevo\n");

        } while (opcion < 0 || opcion > 10);

        switch (opcion)
        {
            case 1:
                if ((archivo = fopen("Articulos.dat", "w")) == NULL)// hay q checar si edna nos pide lo de que se tienen q guardar para ponrelo en "a"
                    printf("Error al abrir el archivo");            //sino lo dejamos como "w" pq con el w si valida clave insumos
                else
                {
                    menu_articulos(archivo);
                    fclose(archivo);
                }
                break;

            case 2:
                if ((archivo = fopen("Insumos.dat", "w")) == NULL)
                    printf("Error al abrir el archivo");
                else
                {
                    menu_insumos(archivo);
                    fclose(archivo);
                }
                break;

            case 3:
                if ((archivo = fopen("Mercados.dat", "w")) == NULL)
                    printf("Error al abrir el archivo");
                else
                {
                    menu_mercados(archivo);
                    fclose(archivo);
                }
                break;

            case 4:
                printf("\n\%20s", "EMPLEADOS\n");
                break;

            case 5:
                printf("\n\%20s", "PROVEEDORES\n");
                break;

            case 6:
                printf("\n\%20s", "VENTAS\n");
                break;

            case 7:
                printf("\n\%20s", "COMPRAS\n");
                break;

            case 8:
                printf("\n\%20s", "CONTROL DE INVENTARIO\n");
                break;

            case 9:
                printf("\n\%20s", "REPORTES\n");
                break;

            case 10:
                printf("\n\%20s", "HA SALIDO DEL SISTEMA.\n");
                ciclo = false;
                break;
        }

    }
    return 0;
}
