#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "estructuras.c"

// MENUS
int menu_principal();
void menu_articulos(FILE *);
void menu_insumos(FILE *);
void menu_mercados(FILE *);
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
    printf("%20s", "Menu principal\n");
    printf("1) Articulos\n");
    printf("2) Insumos\n");
    printf("3) Mercados\n");
    printf("4) Empleados\n");
    printf("5) Proveedores\n");
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
    char agregar, agregar_insumo = 's';
    struct Articulos x_articulo;
    struct Insumo insumos;
    struct Mercado mercado;
    char *estaciones[4] = {"p", "v", "o", "i"}, agregar_mercado = 's';
    bool checar, cadena_valida, clave_valida;
    int i, cant_insumos = 0, n_mercados = 0;
    FILE *insumolocal, *mercado_local;
    float costo_produccion = 0;

    if ((insumolocal = fopen("Insumos.dat", "r")) == NULL)
        printf("No existen insumos necesarios para crear articulos.\nAgregue insumos en el menu de insumos.\n");
    else
    {
        if ((mercado_local = fopen("Mercados.dat", "r")) == NULL)
            printf("No existen mercados registrados en \"Mercados.dat\".\nAgregue mercados en el menu de mercados para continuar.\n");
        else
        {
            while (agregar != 'N' && agregar != 'n')
            {
                printf("\n%20s", "ARTICULOS\n");

                do
                {
                    printf("1) Clave del articulo: ");
                    scanf("%d", &x_articulo.clave_articulo);
                    if (x_articulo.clave_articulo > 1000 || x_articulo.clave_articulo < 1)
                        printf("Clave invalida.\nValores admitidos 1 a 1000\n");
                }while (x_articulo.clave_articulo > 1000 || x_articulo.clave_articulo < 1);

                do
                {
                    printf("2) Descripcion: ");
                    fflush(stdin);
                    gets(x_articulo.descripcion);
                    cadena_valida = cadena_minimo10(x_articulo.descripcion);
                }while (!cadena_valida);

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
                        printf("Estacion invalida.\nSolo se permite:\nP - Primavera\nV - Verano\nO - Oto\xF1o\nI - Invierno.\n");
                }while (!checar);

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
                        printf("Estacion invalida.\nSolo se permite:\nP - Primavera\nV - Verano\nO - Oto\xF1o\nI - Invierno.\n");
                }while (!checar);

                do
                {
                    printf("5) Inventario: ");
                    scanf("%d", &x_articulo.inventario);

                    if (x_articulo.inventario < 0)
                        printf("Valor invalido.\nValor minimo 0.\n");
                }while (x_articulo.inventario < 0);

                do
                {
                    printf("6) Precio de venta:");
                    scanf("%f", &x_articulo.precio_venta);

                    if (x_articulo.precio_venta < 0)
                        printf("Valor invalido.\nValor minimo 0.\n");
                }while (x_articulo.precio_venta < 0);

                x_articulo.costo_produccion = 0.0;

                // Validar que la clave del insumo este en el catalogo
                while (agregar_insumo == 's' && cant_insumos < 10)
				{
				    clave_valida = false;
                    printf("7) Clave del insumo:");
                    scanf("%d", &x_articulo.insumos_requeridos[cant_insumos]);

                    fseek(insumolocal, (x_articulo.insumos_requeridos[cant_insumos] - 1) * sizeof(struct Insumo), SEEK_SET);
                    fread(&insumos, sizeof(struct Insumo), 1, insumolocal);
                    if (insumos.clave_insumo == x_articulo.insumos_requeridos[cant_insumos])
                    {
                        clave_valida = true;
                        cant_insumos++;
                        costo_produccion += insumos.precio_compra;

                    }

                    if (!clave_valida)
                        printf("Clave del insumo no encontrada.\n");

                    do
                    {
                        printf("Quieres agregar otro insumo al articulo(s/n): \n");
                        fflush(stdin);
                        scanf("%c", &agregar_insumo);

                        if (agregar_insumo != 's' && agregar_insumo != 'n')
                            printf("Valor no valido, solo se permite (s/n) \n");

                    }while (agregar_insumo != 's' && agregar_insumo != 'n');
            	}

            	if (cant_insumos > 10)
               		printf("El maximo son 10 insumos.\n");

                //calcular el costo de produccion. update lo voy a calcular namas sumando el precio de los insumos sumandolos

                x_articulo.costo_produccion = costo_produccion;
                printf("El costo de produccion fue de %.2f \n", x_articulo.costo_produccion);
                //ya jala pero no se si tenga algo q ver con la cantidad de insumos q hay no se qpd

                // Clave de mercados
                while (n_mercados < 10 && agregar_mercado == 's')
                {
                    do
                    {
                        printf("8) Ingresa la clave de mercado %d: ", n_mercados + 1);
                        scanf("%d", &x_articulo.clave_mercados[n_mercados]);
                        if(x_articulo.clave_mercados[n_mercados] < 0)
                            printf("Clave invalida.\nValores admitidos mayores que 0\n");
                    }while(x_articulo.clave_mercados[n_mercados] < 0);

                    // Validar si esta en Mercados.dat
                    fseek(mercado_local, (x_articulo.clave_mercados[n_mercados] - 1) * sizeof(struct Mercado), SEEK_SET);
                    fread(&mercado, sizeof(struct Mercado), 1, mercado_local);
                    if (mercado.clave_mercado == x_articulo.clave_mercados[n_mercados])
                    {
                        printf("Clave del mercado encontrada. %d\n", x_articulo.clave_mercados[n_mercados]); // SOLO PARA DEBUGGEAR
                        do
                        {
                            printf("Quieres agregar otro mercado al articulo(S/N): \n");
                            fflush(stdin);
                            scanf("%c", &agregar_mercado);
                        }while (agregar_mercado != 'S' && agregar_mercado != 's' && agregar_mercado != 'N' && agregar_mercado != 'n');

                    }
                    else
                        printf("Clave del mercado no encontrada.\nIntenta con otra.\n");

                }
                // Cerrar archivos y guardar datos

                fseek(articulosf, (x_articulo.clave_articulo - 1) * sizeof(struct Articulos), SEEK_SET);
                fwrite(&x_articulo, sizeof(struct Articulos), 1, articulosf);

                do
                {
                    printf("Agregar otro articulo (S/N): ");
                    fflush(stdin);
                    scanf("%c", &agregar);
                    if (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n')
                        printf("Valor no valido.\nSolo se permite S o N.\n");
                } while (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n');
            }
            fclose(insumolocal);
        }
    }
}
void menu_insumos(FILE *insumosf)
{
    char agregar;
    struct Insumo insumos;
    int proveedores = 0;

    printf("\n%20s", "INSUMOS\n");

    while (agregar != 'N' && agregar != 'n')
    {
        do
        {
            printf("1) Clave del insumo: ");
            scanf("%d", &insumos.clave_insumo);
            if (insumos.clave_insumo > 100 || insumos.clave_insumo < 1)
                printf("Clave invalida. Valores admitidos 1 a 100. \n");

        }while (insumos.clave_insumo > 100 || insumos.clave_insumo < 1);

        do
        {
            printf("2) Descripcion: ");
            fflush(stdin);
            gets(insumos.descripcion);
            if (strlen(insumos.descripcion) < 10)
                printf("Los caracteres minimos son 10.\n");

        }while(strlen(insumos.descripcion) < 10);

        do
        {
            printf("3) Punto de reorden: ");
            scanf("%d", &insumos.punto_reorden);
            if (insumos.punto_reorden <= 0)
                printf("Clave invalida. Valores admitidos mayores que 0. \n");

        }while (insumos.punto_reorden <= 0);

        do
        {
            printf("4) Inventario: ");
            scanf("%d", &insumos.inventario);

            if (insumos.inventario < 0)
                printf("Valor invalido, minimo 0. \n");

        }while(insumos.inventario < 0);

        //hay q validar q exista en proveedores y maximo 10
        do
        {
            printf("5) Clave del proveedor: ");
            scanf("%d", &insumos.clave_proveedor);

            if (proveedores > 10)
                printf("Cantidad de proveedores maxima alcanzada");

        }while (proveedores > 10);

        proveedores++;

        do
        {
            printf("6) Precio: ");
            scanf("%f", &insumos.precio_compra);
            if (insumos.precio_compra <= 0)
                printf("Precio invalido\n");

        }while(insumos.precio_compra <= 0);

        fseek(insumosf, (insumos.clave_insumo - 1) * sizeof(struct Insumo), SEEK_SET);
        fwrite(&insumos, sizeof(struct Insumo), 1, insumosf);

        do
        {
            printf("Agregar otro insumo (S/N): ");
            fflush(stdin);
            scanf("%c", &agregar);
            if (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n')
                printf("Valor no valido.\nSolo se permite S o N.\n");

        }while (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n');
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

void menu_mercados(FILE *mercadosf)
{
    char agregar;
    struct Mercado mercados;

    printf("\n%20s", "MERCADOS\n");

    while (agregar != 'N' && agregar != 'n')
    {
        do
        {
            printf("1) Clave del mercado: ");
            scanf("%d", &mercados.clave_mercado);
            if (mercados.clave_mercado < 0)
                printf("Clave invalida.\nValores admitidos mayores que 0\n");

        }while (mercados.clave_mercado < 0);

        do
        {
            printf("2) Nombre completo: ");
            fflush(stdin);
            gets(mercados.nombre_completo);
            if (strlen(mercados.nombre_completo) < 10)
                printf("Los caracteres minimos son 10.\n");

        }while (strlen(mercados.nombre_completo) < 10);

        do //falta validar lo correspondiente
        {
            printf("3) RFC: ");
            fflush(stdin);
            gets(mercados.RFC);
            if (strlen(mercados.RFC) != 13)
                printf("Los caracteres deben ser 13.\n");

        }while (strlen(mercados.RFC) != 13);

        do //falta validar @ y punto
        {
            printf("4) Correo electronico: ");
            fflush(stdin);
            gets(mercados.correo);
            if (strlen(mercados.correo) < 0)
                printf("Falta validar.\n");

        }while (strlen(mercados.correo) < 0);

        do
        {
            printf("5) Descuento: ");
            scanf("%f", &mercados.descuento);

            if (mercados.descuento < 0 || mercados.descuento > 1)
                printf("Descuento invalido debe de estar entre 0 y 1.\n");

        }while (mercados.descuento < 0 || mercados.descuento > 1);


        do
        {
            printf("6) Año de nacimiento: ");
            scanf("%d", &mercados.anio_nacimiento);
            if (mercados.anio_nacimiento < 1950 || mercados.anio_nacimiento > 2006)
                printf("Año de nacimiento invalido, debe de estar entre 1950 y 2006\n");

        }while (mercados.anio_nacimiento < 1950 || mercados.anio_nacimiento > 2006);


        do
        {
            printf("7) Mes de nacimiento: ");
            scanf("%d", &mercados.mes_nacimiento);
            if (mercados.mes_nacimiento < 1 || mercados.mes_nacimiento > 12)
                printf("Mes de nacimiento invalido, debe de estar entre 1 y 12\n");

        }while (mercados.mes_nacimiento < 1 || mercados.mes_nacimiento > 12);

        do
        {
            printf("8) Dia de nacimiento: ");//validar q dia corresponda a mes
            scanf("%d", &mercados.dia_nacimiento);
            if (mercados.dia_nacimiento < 0)
                printf("Falta validar\n");

        }while (mercados.dia_nacimiento < 0);


        do
        {
            printf("9) Direccion: ");//validar cositas esas
            fflush(stdin);
            gets(mercados.direccion);
            if (strlen(mercados.direccion) < 0)
                printf("Falta validar.\n");

        }while (strlen(mercados.direccion) < 0);


        fwrite(&mercados, sizeof(struct Mercado), 1, mercadosf);


        do
        {
            printf("Agregar otro mercado (S/N): ");
            fflush(stdin);
            scanf("%c", &agregar);
            if (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n')
                printf("Valor no valido.\nSolo se permite S o N.\n");

        }while (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n');
    }


}
