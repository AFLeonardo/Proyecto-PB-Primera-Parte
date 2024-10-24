#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// MENUS
int menu_principal();
void menu_articulos(FILE *);
void menu_insumos();
void menu_mercados();
void menu_empleados();
void menu_proveedores();
void menu_control_ventas();
void menu_control_compras();
void menu_control_inventario();
void menu_reportes();

// ESTRUCTURAS
struct Articulos
{
    int Clave_articulo;
    char Descripcion[150];
    int Temp_siembra; 
    int Temp_cosecha;
    int Clave_mercados;
    int Insumos_requeridos;
    float Costo_produccion;
    int Inventario;
    float Precio_venta;
};
struct Insumo 
{
    int clave_insumo;
    char descripcion[100];
    int punto_reorden;
    int inventario;
    int clave_proveedor[10]; // Hasta 10 claves de proveedores
    float precio_compra;
};
struct Proveedor 
{
    int numero_proveedor;
    char nombre_completo[100];
    char RFC[14];
    char correo[100];
    float descuento;
    int anio_nacimiento;
    int mes_nacimiento;
    int dia_nacimiento;
    char direccion[200];  // Calle, número, colonia, municipio y estado
    int articulos_produce[10]; // Claves de los artículos que produce
};
struct Empleado 
{
    int numero_empleado;
    char nombre_completo[100];
    char RFC[14];
    char correo[100];
    float comision;
    int anio_contratacion;
    int mes_contratacion;
    int dia_contratacion;
    char direccion[200];
};
struct Mercado 
{
    int clave_mercado;
    char nombre_completo[100];
    char RFC[14];
    char correo[100];
    float descuento;
    int anio_nacimiento;
    int mes_nacimiento;
    int dia_nacimiento;
    char direccion[200];
};
struct Venta 
{
    int numero_mercado;
    int numero_articulo;
    int cantidad;
    float precio_total;
    int numero_empleado;
    int factura;
};
struct Compra 
{
    int numero_proveedor;
    int numero_insumo;
    int cantidad;
    float precio_total;
};

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
                if ((archivo = fopen("Archivo.dat", "a")) == NULL)
                    archivo = fopen("Archivo.dat", "w");
                else
                {
                    menu_articulos(archivo);
                    fclose(archivo);
                }
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
    return 0;
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

void menu_articulos(FILE *articulosf)
{
    char agregar = 'S';
    struct Articulos x_articulo;

    while (agregar != 'N' && agregar != 'n')
    {
        printf("\n\%20s", "ARTICULOS\n");
        //Validacion clave entre 1-1000
        do
        {
            printf("1) Clave del articulo: ");
            scanf("%d", &x_articulo.Clave_articulo);
            if (x_articulo.Clave_articulo > 1000 || x_articulo.Clave_articulo < 1)
                printf("Clave invalida.\nValores admitidos 1 a 1000\n");
            
        } while (x_articulo.Clave_articulo > 1000 || x_articulo.Clave_articulo < 1);

        //Validacion Descripcion Mimino 10 caracteres.
        do
        {
            printf("2) Descripcion: ");
            fflush(stdin);
            gets(x_articulo.Descripcion);
            if (strlen(x_articulo.Descripcion) < 10)
                printf("Los caracteres minimos son 10.\n");
            
        } while (strlen(x_articulo.Descripcion) < 10);
        
        // Las temporadas se manejan de acuerdo a los meses. 1-12
        do
        {
            printf("3) Temporada de siembra: ");
            scanf("%d", &x_articulo.Temp_siembra);

            if(x_articulo.Temp_siembra < 1 || x_articulo.Temp_siembra > 12)
                printf("Temporada no valida.\nValores admitidos: 1 a 12\n");
        } while (x_articulo.Temp_siembra < 1 || x_articulo.Temp_siembra > 12);
        
        do
        {
            printf("3) Temporada de cosecha: ");
            scanf("%d", &x_articulo.Temp_cosecha);

            if(x_articulo.Temp_cosecha < 1 || x_articulo.Temp_cosecha > 12)
                printf("Temporada no valida.\nValores admitidos: 1 a 12\n");
        } while (x_articulo.Temp_cosecha < 1 || x_articulo.Temp_cosecha > 12);
        
        do
        {
            printf("5) Inventario: ");
            scanf("%d", &x_articulo.Inventario);

            if(x_articulo.Inventario < 0)
                printf("Valor invalido.\nMinimo 0.");
        } while (x_articulo.Inventario < 0);

        do
        {
            printf("6) Precio de venta:");
            scanf("%f", &x_articulo.Precio_venta);

            if(x_articulo.Precio_venta < 0)
                printf("Valor invalido.\nMinimo 0.");
        } while (x_articulo.Precio_venta < 0);
        
        // Validar que la clave del insumo este en el catalogo. CATALOGOS SON ARCHIVOS DIRECTOS.
        do
        {
            printf("7) Clave del insumo:");
            scanf("%d", &x_articulo.Clave_mercados);

            if(x_articulo.Clave_mercados < 0)
                printf("Valor invalido.\nMinimo 0.");
        } while (x_articulo.Clave_mercados < 0);

        // GUARDAR LOS DATOS EN UN ARCHIVO DIRECTO.
        fseek(articulosf, x_articulo.Clave_articulo * sizeof(struct Articulos), SEEK_SET);
        fwrite(&x_articulo, sizeof(struct Articulos), 1, articulosf);

        //Preguntas si quiere agregar mas
        do
        {
            printf("Agregar otro articulo (S/N): ");
            fflush(stdin);
            scanf(" %c", &agregar);
            if (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n')
                printf("Valor no valido.\nSolo se permite S o N.\n");
            
        } while (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n');
    }
}