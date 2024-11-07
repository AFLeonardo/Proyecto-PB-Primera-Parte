#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funciones.c"

// ESTO SI FUNCIONA
main()
{
    int opcion;
    bool ciclo = true;
    FILE *archivo;
    struct Articulos articuloVacio = {0, "", "", "", {0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0}, 0.0, 0, 0.0};
    struct Insumo insumoVacio = {0, "", 0, 0, {0,0,0,0,0,0,0,0,0,0}, {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}};
    struct Proveedor proveedorVacio = {0, "", "", "", 0.0, 0, 0, 0, "", {0,0,0,0,0,0,0,0,0,0}};
    struct Mercado mercadoVacio = {0, "", "", "", 0.0f, 0, 0, 0, ""};

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
                if ((archivo = fopen("Articulos.dat", "rb+")) == NULL)// hay q checar si edna nos pide lo de que se tienen q guardar para ponrelo en "a"
                    { //sino lo dejamos como "w" pq con el w si valida clave insumos
                    printf("Error al abrir el archivo\n"); 
                    crearRegistrosVacios("Articulos.dat", &articuloVacio, sizeof(struct Articulos), 100);
                    }          
                else
                {
                    menu_articulos(archivo);
                    fclose(archivo);
                }
                break;

            case 2:
                if ((archivo = fopen("Insumos.dat", "rb+")) == NULL)
                    {
                    printf("Error al abrir el archivo\n"); 
                    crearRegistrosVacios("Insumos.dat", &insumoVacio, sizeof(struct Articulos), 100);
                    }
                else
                {
                    menu_insumos(archivo);
                    fclose(archivo);
                }
                break;

            case 3:
                if ((archivo = fopen("Mercados.dat", "rb+")) == NULL)
                    {
                    printf("Error al abrir el archivo\n");
                    crearRegistrosVacios("Mercados.dat", &mercadoVacio, sizeof(struct Mercado), 100);
                    }
                else
                {
                    menu_mercados(archivo);
                    fclose(archivo);
                }
                break;

            case 4:
                if ((archivo = fopen("Empleados.dat", "rb+")) == NULL)
                    printf("Error al abrir el archivo\n");

                else
                {
                    menu_empleados(archivo);
                    fclose(archivo);
                }
                break;

            case 5:
                if((archivo = fopen("Proveedores.dat", "rb+")) == NULL)
                {
                    crearRegistrosVacios("Proveedores.dat", &proveedorVacio, sizeof(struct Proveedor), 100);
                    printf("Error al abrir el archivo\n");
                }
                else
                {
                    menu_proveedores(archivo);
                    fclose(archivo);
                }
                break;

            case 6:
                printf("%s\n", "VENTAS\n");
                break;

            case 7:
                printf("%s\n", "COMPRAS\n");
                break;

            case 8:
                printf("%s\n", "CONTROL DE INVENTARIO\n");
                break;

            case 9:
                printf("%s\n", "REPORTES\n");
                break;

            case 10:
                printf("%s\n", "HA SALIDO DEL SISTEMA.\n");
                ciclo = false;
                break;
        }

    }
    return 0;
}
