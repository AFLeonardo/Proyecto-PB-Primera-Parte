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
    char agregar = 'S', agregar_insumo = 'S';
    struct Articulos x_articulo;
    struct Insumo insumos;
    struct Mercado mercado;
    char *estaciones[4] = {"p", "v", "o", "i"}, agregar_mercado = 's';
    bool checar, cadena_valida, clave_valida;
    int i, cant_proveedores = 0, n_mercados = 0;
    FILE *insumolocal, *mercado_local;

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

                // Validar que la clave del insumo este en el catalogo
                while (cant_proveedores < 10) 
				{
					clave_valida = false;
					do
					{
                        printf("7) Clave del insumo:");
                        scanf("%d", &x_articulo.insumos_requeridos[cant_proveedores]);

						fseek(insumolocal, (x_articulo.insumos_requeridos[cant_proveedores] - 1) * sizeof(struct Insumo), SEEK_SET);
                   		fread(&insumos, sizeof(struct Insumo), 1, insumolocal);
                        if (insumos.clave_insumo == x_articulo.insumos_requeridos[cant_proveedores]) 
						{
                            clave_valida = true;
                        	cant_proveedores++;
                        }
    
                        if (!clave_valida)
                            printf("Clave del insumo no encontrada.\n");
    
                        do 
                        {
                            printf("Quieres agregar otro insumo al articulo(S/N): \n");
                            fflush(stdin);
                            scanf("%c", &agregar_insumo);
    
                            if ( (agregar_insumo != 'S' && agregar_insumo != 'N'))
                                printf("Valor no valido.\nSolo se permite S o N.\n");

                        }while ( (agregar_insumo != 'S' && agregar_insumo != 'N') );
                    
                    }while(!clave_valida);
            	}
            	
            	if (cant_proveedores > 10) 
				{
               		printf("El maximo son 10 proveedores.\n");
                    clave_valida = false;
                }
    
                    // Clave de mercados
                while (n_mercados < 10 && agregar_mercado == 's')
                { 
                    do
                    {
                        printf("8) Ingresa la clave de mercado %d: ", n_mercados);
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
                
                fseek(articulosf, x_articulo.clave_articulo * sizeof(struct Articulos), SEEK_SET);
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
void menu_insumos(FILE *articulosf)
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
                printf("Clave invalida.\nValores admitidos 1 a 100\n");

        }while (insumos.clave_insumo > 100 || insumos.clave_insumo < 1);

        do 
        {
            printf("2) Descripcion: ");
            fflush(stdin);
            gets(insumos.descripcion);
            if (strlen(insumos.descripcion) < 10)
                printf("Los caracteres minimos son 10.\n");

        }while (strlen(insumos.descripcion) < 10);

        do 
        {
            printf("3) Punto de reorden: ");
            scanf("%d", &insumos.punto_reorden);
            if (insumos.punto_reorden < 0)
                printf("Clave invalida.\nValores admitidos mayores que 0\n");

        }while (insumos.punto_reorden < 0);

        do 
        {
            printf("4) Inventario: ");
            scanf("%d", &insumos.inventario);

            if (insumos.inventario < 0)
                printf("Valor invalido.\nMinimo 0.");

        }while (insumos.inventario < 0);

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
            scanf("%d", &insumos.precio_compra);
            if (insumos.precio_compra < 0)
                printf("Precio invalido\n");

        }while (insumos.precio_compra < 0);

        fwrite(&insumos, sizeof(struct Insumo), 1, articulosf);

        do 
        {
            printf("Agregar otro articulo (S/N): ");
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