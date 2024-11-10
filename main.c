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
    struct Articulos articuloVacio = {0, "", "", "", {0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0}, 0, 0, 0};
    struct Insumo insumoVacio = {0, "", 0, 0, {0,0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0,0}};
    struct Proveedor proveedorVacio = {0, "", "", "", 0, 0, 0, 0, "", {0,0,0,0,0,0,0,0,0,0}};
    struct Mercado mercadoVacio = {0, "", "", "", 0, 0, 0, 0, ""};
    struct Venta ventavacia = {0, 0, 0, 0, 0, 0};
    struct Empleado empleadoVacio = {0, "", "", "", 0.0, {0, 0, 0}, {"", 0, "", "", ""}};
    struct Compra comprasvacia = {0, 0, 0, 0};

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
            case 1: // ✅ LISTO
                if((archivo = fopen("Articulos.dat", "r+")) == NULL)
                {
                    printf("ERROR.\nSe esta creando el archvio intenta de nuevo.\n");
                    crearRegistrosVacios("Articulos.dat", &articuloVacio, sizeof(struct Articulos), 1000);
                }
                else
                {
                    menu_articulos(archivo);
                    fclose(archivo);
                }
                break;

            case 2: // ✅ LISTO
                if ((archivo = fopen("Insumos.dat", "rb+")) == NULL)
                    {
                    printf("ERROR.\nSe esta creando el archivo intenta de nuevo.\n");
                    crearRegistrosVacios("Insumos.dat", &insumoVacio, sizeof(struct Insumo), 100);
                    }
                else
                {
                    menu_insumos(archivo);
                    fclose(archivo);
                }
                break;

            case 3:
                if ((archivo = fopen("Mercados.dat", "r+")) == NULL)
                    {
                    printf("ERROR.\nSe esta creando el archvio intenta de nuevo.\n");
                    crearRegistrosVacios("Mercados.dat", &mercadoVacio, sizeof(struct Mercado), 100);
                    }
                else
                {
                    menu_mercados(archivo);
                    fclose(archivo);
                }
                break;

            case 4:
                if ((archivo = fopen("Empleados.dat", "r+")) == NULL)
                {
                    printf("ERROR.\nSe esta creando el archvio intenta de nuevo.\n");
					crearRegistrosVacios("Empleados.dat", &empleadoVacio, sizeof(struct Empleado), 1000);
				}
                else
                {
                    menu_empleados(archivo);
                    fclose(archivo);
                }
                break;

            case 5: // ✅ LISTO
                if((archivo = fopen("Proveedores.dat", "r+")) == NULL)
                {
                    printf("ERROR.\nSe esta creando el archvio intenta de nuevo.\n");
                    crearRegistrosVacios("Proveedores.dat", &proveedorVacio, sizeof(struct Proveedor), 100);
                }
                else
                {
                    menu_proveedores(archivo);
                    fclose(archivo);
                }
                break;

            case 6:
                printf("%s\n", "VENTAS\n");
                if((archivo = fopen("Ventas.txt", "r+")) == NULL)
                {
                    printf("ERROR.\nSe esta creando el archivo intenta de nuevo.\n");
                    crearRegistrosVacios("Ventas.txt", &ventavacia, sizeof(struct Venta), 100);
                }

                else
                {
                    menu_control_ventas(archivo);
                    fclose(archivo);
                }
                break;

            case 7:
                printf("%s\n", "COMPRAS\n");
                if ((archivo = fopen("Compras.txt", "r+")) == NULL)
                {
                    printf("ERROR \nSe esta creando el archivo intenta de nuevo\n");
                    crearRegistrosVacios("Compras.txt", &comprasvacia, sizeof(struct Compra), 100);
                }

                else
                {
                    menu_control_compras(archivo);
                    fclose(archivo);
                }

                break;

            case 8:
                printf("%s\n", "CONTROL DE INVENTARIO\n");
                if((archivo = fopen("Proveedores.dat", "r+")) == NULL)
                    printf("ERROR.\nSe esta creando el archvio intenta de nuevo.\n"); // no se si tengo q agregar registros vacios segun yo no vdd pq no hay estructura
                else
                {
                    menu_control_inventario(archivo);
                    fclose(archivo);
                }
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
