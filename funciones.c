#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "estructuras.c"

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

// FUNCIONES
char *convertir_a_minusculas(char *);
bool cadena_minimo10(char *);

int menu_principal()
{
    int opcion;
    printf("\n%20s", "Menu principal\n");
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
    char agregar = 'S', agregar_insumo = 'S';
    struct Articulos x_articulo;
    char *estaciones[4] = {"primavera", "verano", "otoño", "invierno"};
    bool checar, cadena_valida, insumo= true;
    int i, n_insumo = 0;

    while (agregar != 'N' && agregar != 'n')
    {
        printf("\n\%20s", "ARTICULOS\n");

        do
        {
            printf("1) Clave del articulo: ");
            scanf("%d", &x_articulo.clave_articulo);
            if (x_articulo.clave_articulo > 1000 || x_articulo.clave_articulo < 1)
                printf("Clave invalida.\nValores admitidos 1 a 1000\n");

        } while (x_articulo.clave_articulo > 1000 || x_articulo.clave_articulo < 1);

        do
        {
            printf("2) Descripcion: ");
            fflush(stdin);
            gets(x_articulo.descripcion);
            cadena_valida = cadena_minimo10(x_articulo.descripcion);

        } while (!cadena_valida);

        do
        {
            checar = false;
            printf("3) Temporada de siembra: ");
            fflush(stdin);
            gets(x_articulo.temp_siembra);

            for (i = 0; i < 4; i++)
            {
                if (strcmp(convertir_a_minusculas(x_articulo.temp_siembra), estaciones[i]) == 0)
                    checar = true;
            }

            if (!checar)
                printf("Estacion invalida.\n");
        } while (!checar);

        do
        {
            checar = false;
            printf("4) Temporada de cosecha: ");
            fflush(stdin);
            gets(x_articulo.temp_cosecha);

            for (i = 0; i < 4; i++)
            {
                if (strcmp(convertir_a_minusculas(x_articulo.temp_cosecha), estaciones[i]) == 0)
                    checar = true;
            }
            if (!checar)
                printf("Estacion invalida\n");
        } while (!checar);

        do
        {
            printf("5) Inventario: ");
            scanf("%d", &x_articulo.inventario);

            if (x_articulo.inventario < 0)
                printf("Valor invalido.\nMinimo 0.");
        } while (x_articulo.inventario < 0);

        do
        {
            printf("6) Precio de venta:");
            scanf("%f", &x_articulo.precio_venta);

            if (x_articulo.precio_venta < 0)
                printf("Valor invalido.\nMinimo 0.");
        } while (x_articulo.precio_venta < 0);

        // Validar que la clave del insumo este en el catalogo. CATALOGOS SON ARCHIVOS DIRECTOS.
        while (insumo && n_insumo < 10)
        {
            do
            {
                printf("7) Clave del insumo (VALIDAR QUE EXISTE LA CLAVE DE INSUMO): ");
                scanf("%d", &x_articulo.insumos_requeridos[i]);

                if (x_articulo.insumos_requeridos[i] < 0)
                    printf("Valor invalido.\nMinimo 0.\n");
            } while (x_articulo.insumos_requeridos[i] < 0);


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
        fseek(articulosf, x_articulo.clave_articulo * sizeof(struct Articulos), SEEK_SET);
        fwrite(&x_articulo, sizeof(struct Articulos), 1, articulosf);

        //Preguntas si quiere agregar mas
        do
        {
            printf("Agregar otro articulo (S/N): ");
            fflush(stdin);
            scanf("%c", &agregar);
            if (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n')
                printf("Valor no valido.\nSolo se permite S o N.\n");

        } while (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n');
    }
}

void menu_insumos(FILE *articulosf)
{
    char agregar;
    struct Insumo insumos;
    int proveedores = 0;
    // bool checar;  ESTA CHINGADERA LA VA A HACER ALEXIS

    printf("\n\%20s", "INSUMOS\n");

    while (agregar != 'N' && agregar != 'n')
    {
        do
        {
            printf("1) Clave del insumo: ");
            scanf("%d", &insumos.clave_insumo);
            if (insumos.clave_insumo > 100 || insumos.clave_insumo < 1)
                printf("Clave invalida.\nValores admitidos 1 a 100\n");

        } while (insumos.clave_insumo > 100 || insumos.clave_insumo < 1);

        do
        {
            printf("2) Descripcion: ");
            fflush(stdin);
            gets(insumos.descripcion);
            if (strlen(insumos.descripcion) < 10)
                printf("Los caracteres minimos son 10.\n");

        } while (strlen(insumos.descripcion) < 10);

        do
        {
            printf("3) Punto de reorden: ");
            scanf("%d", &insumos.punto_reorden);
            if (insumos.punto_reorden < 0)
                printf("Clave invalida.\nValores admitidos mayores que 0\n");

        } while (insumos.punto_reorden < 0);

        do
        {
            printf("4) Inventario: ");
            scanf("%d", &insumos.inventario);

            if (insumos.inventario < 0)
                printf("Valor invalido.\nMinimo 0.");
        } while (insumos.inventario < 0);

        do
        {
            printf("5) Clave del proveedor: ");
            scanf("%d", &insumos.clave_proveedor);

            if (proveedores > 10)
                printf("Cantidad de proveedores maxima alcanzada");
        } while (proveedores > 10);

        proveedores++;

        do
        {
            printf("6) Precio: ");
            scanf("%d", &insumos.precio_compra);
            if (insumos.precio_compra < 0)
                printf("Precio invalido\n");

        } while (insumos.precio_compra < 0);

        fwrite(&insumos, sizeof(struct Insumo), 1, articulosf);

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

char *convertir_a_minusculas(char *cadena)
{
    int i;
    for (i = 0; cadena[i]; i++)
        cadena[i] = tolower(cadena[i]);
    return cadena;
}

bool cadena_minimo10(char *descripcion)
{
    if (strlen(descripcion) < 10)
    {
        printf("Los caracteres minimos son de 10.\n");
        return false;
    }
    return true;
}