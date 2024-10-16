#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    int Insumos_requeridos;|
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
    struct Articulos x_articulo;
    
    /* 1)	Clave del artículo:
    2)	Descripción:
    3)	Temporada de siembra:
    4)	Temporada de cosecha: 
    5)	Inventario: 
    6)	Precio de venta:
    7)	Clave del Insumo: Validar que  */


    while (agregar)
    {
        printf("\n\%20s", "ARTICULOS\n");
        //Validacion clave entre 1-1000
        do
        {
            printf("1)	Clave del artículo: ");
            scanf("%d", &x_articulo.Clave_articulo);
            if (x_articulo.Clave_articulo > 1000 || x_articulo.Clave_articulo < 1)
                printf("Clave invalida.\nValores admitidos 1 a 1000\n");
            
        } while (x_articulo.Clave_articulo > 1000 || x_articulo.Clave_articulo < 1);

        //Validacion Descripcion Mimino 10 caracteres.
        do
        {
            printf("2) Descripción: ");
            scanf("%d", &x_articulo.Descripcion);
            if (strlen(x_articulo.Descripcion) < 10)
                printf("Los caracteres minimos son 10.\n");
            
        } while (strlen(x_articulo.Descripcion) < 10);
        
        // Las temporadas se manejan de acuerdo a los meses. 1-12
        // Validar a que la temporada ingresa sea entre 1-12.
        do
        {
            printf("3) Temporada de siembra: ");
            scanf("%d", &x_articulo.Temp_siembra);

            if(x_articulo.Temp_siembra < 1 || x_articulo.Temp_siembra > 12)
                printf("Temporada no valida.\nValores admitidos: 1 a 12");
        } while (x_articulo.Temp_siembra < 1 || x_articulo.Temp_siembra > 12);
        
        
        
        
    }
    
    
    
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}