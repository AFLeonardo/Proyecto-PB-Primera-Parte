#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// FUNCIONES
int menu();
int menu_articulos();

// ESTRUCTURAS
struct Articulos
{
    int Clave_articulo;
    char Descripcion[150];
    int Temp_siembra; // VALIDAR SI SE PUEDE USAR COMO VALOR DE 1 a 12. CORRESPONDIENDO AL MES DEL ANIO
    int Temp_cosecha; // VALIDAR SI SE PUEDE USAR COMO VALOR DE 1 a 12. CORRESPONDIENDO AL MES DEL ANIO
    int Clave_mercados;
    int Insumos_requeridos;
    float Costo_produccion;
    int Inventario;
    float Precio_venta;
};


main()
{
    int opcion;
    bool ciclo = true;

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
                printf("\n\%20s", "ARTICULOS\n");
                break;
            
            case 2:
                printf("\n\%20s", "INSUMOS\n");
                break;

            case 3:
                printf("\n\%20s", "MERCADOS\n");
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
}

int menu_principal()
{
    int opcion;
    printf("\n\%20s", "Menu principal\n");
    printf("1) Articulos\n");
    printf("2) Insumos\n");
    printf("3) Mercados\n");
    printf("4) Empleados\n");
    printf("5) Provedores\n");
    printf("6) Ventas\n");
    printf("7) Compras\n");
    printf("8) Control de Inventario\n");
    printf("9) Reportes\n");
    printf("10) Salir\n");
    
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int menu_articulos()
{
    int opcion;
    bool agregar = true;
    
    while (agregar)
    {
        printf("\n\%20s", "ARTICULOS\n");
    }
    
    
    
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}