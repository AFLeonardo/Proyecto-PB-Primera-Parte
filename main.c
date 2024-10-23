#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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
char *convertir_a_minusculas(char *);


// ESTRUCTURAS
struct Articulos
{
    int Clave_articulo;
    char Descripcion[150];
    char Temp_siembra[20];
    char Temp_cosecha[20];
    int Clave_mercados;
    int Insumos[10];
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
                    printf("Error al abrir el archivo");
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
    char agregar_articulo = 'S', agregar_insumo = 'S';
    struct Articulos x_articulo;
    char estaciones[4][15] = {"primavera", "verano", "otoño", "invierno"};
    bool checar, insumo = true;
    int i, n_insumo = 0;

    while (agregar_articulo != 'N' && agregar_articulo != 'n')
    {
        printf("\n\%20s", "ARTICULOS\n");
        // VALIDAR QUE SOLO SE PUEDAN INGRESAR NUMEROS
        do
        {
            printf("1) Clave del articulo: ");
            scanf("%d", &x_articulo.Clave_articulo);
            if (x_articulo.Clave_articulo > 1000 || x_articulo.Clave_articulo < 1)
                printf("Clave invalida.\nValores admitidos 1 a 1000\n");

        } while (x_articulo.Clave_articulo > 1000 || x_articulo.Clave_articulo < 1);

        do
        {
            printf("2) Descripcion: ");
            fflush(stdin);
            gets(x_articulo.Descripcion);
            if (strlen(x_articulo.Descripcion) < 10)
                printf("Los caracteres minimos son 10.\n\n");

        } while (strlen(x_articulo.Descripcion) < 10);

        do
        {
            
            printf("3) Temporada de siembra: ");
            fflush(stdin);
            gets(x_articulo.Temp_siembra);

            //CONVERTIR LA CADENA DADA A MINUSCULAS PARA COMPRAR CON EL ARREGLO DE ESTACIONES
            strcpy(x_articulo.Temp_siembra, convertir_a_minusculas(x_articulo.Temp_siembra));
            checar = false;

            for(i = 0; i < 4; i++)
            {
                if(strcmp(x_articulo.Temp_siembra, estaciones[i]) == 0)
                    checar = true;
            }

            if(!checar)
                printf("Estacion invalida.\nSolo se permite primavera, verano, otoño, invierno.\n");
        } while (!checar);

        do
        {
            printf("4) Temporada de cosecha: ");
            fflush(stdin);
            gets(x_articulo.Temp_cosecha);

            //CONVERTIR LA CADENA DADA A MINUSCULAS PARA COMPRAR CON EL ARREGLO DE ESTACIONES
            strcpy(x_articulo.Temp_cosecha, convertir_a_minusculas(x_articulo.Temp_cosecha));
            checar = false;
            for(i = 0; i < 4; i++)
            {
                if(strcmp(x_articulo.Temp_cosecha, estaciones[i]) == 0)
                    checar = true;
            }
            if(!checar)
                printf("Estacion invalida.\nSolo se permite primavera, verano, otoño, invierno.\n");
        } while (!checar);

        do
        {
            printf("5) Inventario: ");
            scanf("%d", &x_articulo.Inventario);

            if(x_articulo.Inventario < 0)
                printf("Valor invalido.\nMinimo 0.");
        } while (x_articulo.Inventario < 0);

        do
        {
            printf("6) Precio de venta: ");
            scanf("%f", &x_articulo.Precio_venta);

            if(x_articulo.Precio_venta < 0)
                printf("Valor invalido.\nMinimo 0.");
        } while (x_articulo.Precio_venta < 0);

        while (insumo && n_insumo < 10)
        {
            do
            {
                printf("7) Clave del insumo (VALIDAR QUE EXISTE LA CLAVE DE INSUMO): ");
                scanf("%d", &x_articulo.Insumos[i]);

                if (x_articulo.Insumos[i] < 0)
                    printf("Valor invalido.\nMinimo 0.\n");
            } while (x_articulo.Insumos[i] < 0);


            // Validar que la clave del insumo este en el catalogo. CATALOGOS SON ARCHIVOS DIRECTOS.
            //
            //
            //
            //

            do
            {
                printf("Quieres agregar otro insumo al articulo(S/N): ");
                fflush(stdin);
                scanf("%c", &agregar_insumo);
                if (agregar_insumo != 'S' && agregar_insumo != 's' && agregar_insumo != 'N' && agregar_insumo != 'n')
                    printf("Valor no valido.\nSolo se permite S o N.\n");

            } while (agregar_insumo != 'S' && agregar_insumo != 's' && agregar_insumo != 'N' && agregar_insumo != 'n');

            if (agregar_insumo == 'S' || agregar_insumo == 's')
                n_insumo++;
            else
                insumo = false;
            
        }
        
        if (n_insumo == 10)
            printf("SOLO PERMITEN 10 INSUMOS COMO MAXIMO.");

        // GUARDAR LOS DATOS EN UN ARCHIVO DIRECTO.
        fseek(articulosf, x_articulo.Clave_articulo * sizeof(struct Articulos), SEEK_SET);
        fwrite(&x_articulo, sizeof(struct Articulos), 1, articulosf);
        mostrar_articulo(x_articulo);

        //Preguntas si quiere agregar mas
        do
        {
            printf("Agregar otro articulo (S/N): ");
            fflush(stdin);
            scanf("%c", &agregar_articulo);
            if (agregar_articulo != 'S' && agregar_articulo != 's' && agregar_articulo != 'N' && agregar_articulo != 'n')
                printf("Valor no valido.\nSolo se permite S o N.\n");

        } while (agregar_articulo != 'S' && agregar_articulo != 's' && agregar_articulo != 'N' && agregar_articulo != 'n');
    }
}

char * convertir_a_minusculas(char *cadena)
{
    int i;
    for (i = 0; cadena[i]; i++) {
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}

// FUNCION TEMPORAL
void mostrar_articulo(struct Articulos articulo) 
{
    printf("\nDATOS DEL ARTICULO:\n\n\n");
    printf("Clave del articulo: %d\n", articulo.Clave_articulo);
    printf("Descripcion: %s\n", articulo.Descripcion);
    printf("Temporada de siembra: %s\n", articulo.Temp_siembra);
    printf("Temporada de cosecha: %s\n", articulo.Temp_cosecha);
    printf("Clave de mercados: %d\n", articulo.Clave_mercados);
    printf("Insumos requeridos: %i\n", articulo.Insumos);
    printf("Costo de produccion: %.2f\n", articulo.Costo_produccion);
    printf("Inventario: %d\n", articulo.Inventario);
    printf("Precio de venta: %.2f\n", articulo.Precio_venta);
}

// CONTENIDO DE RELLENO PARA VER COMO FUCNIONA GITHUB DESKTOP 
