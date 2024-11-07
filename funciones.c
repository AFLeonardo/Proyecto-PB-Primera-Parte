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
void menu_empleados(FILE *);
void menu_proveedores(FILE *);
void menu_control_ventas(FILE *);
void menu_control_compras(FILE *);
void menu_control_inventario();
void menu_reportes();

// FUNCIONES
char *convertir_a_minusculas(char *);
bool cadena_minimo10(char *);
bool validar_rfc(char *);
bool validar_correo(char *);
bool validarDiaMes(int, int, int);



int menu_principal()
{
    int opcion;
    printf("\nMenu principal\n");
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
    bool checar, cadena_valida, clave_valida = false;
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
                printf("%s\n", "ARTICULOS\n");

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
                while (cant_insumos < 10 && agregar_insumo == 's')
                {
                    clave_valida = false;
                    do
				    {
                        printf("7) Clave del insumo:");
                        scanf("%d", &x_articulo.insumos_requeridos[cant_insumos]);

                        fseek(insumolocal, (x_articulo.insumos_requeridos[cant_insumos] - 1) * sizeof(struct Insumo), SEEK_SET);
                        fread(&insumos, sizeof(struct Insumo), 1, insumolocal);
                        if (insumos.clave_insumo == x_articulo.insumos_requeridos[cant_insumos])
                        {
                            clave_valida = true;
<<<<<<< Updated upstream
                            cant_insumos++;
                            costo_produccion += insumos.precio_compra[cant_insumos];
=======
                            costo_produccion += LecturaInsumo.precio_compra[cant_insumos];
                            cant_insumos++;
>>>>>>> Stashed changes
                        }

                        if (!clave_valida)
                            printf("Clave del insumo no encontrada\n");

                    }while (clave_valida = false);
                    do
                    {
                        printf("Quieres agregar otro insumo al articulo(s/n): \n");
                        fflush(stdin);
                        scanf("%c", &agregar_insumo);

                        if (agregar_insumo != 's' && agregar_insumo != 'n') //hay q ver como hacer para que acepte mayus
                            printf("Valor no valido, solo se permite (s/n) \n");
                    }while(agregar_insumo != 's' && agregar_insumo != 'n');
                }

            	if (cant_insumos > 10)
               		printf("El maximo son 10 insumos.\n");

                //calcular el costo de produccion
                x_articulo.costo_produccion = costo_produccion;
                printf("El costo de produccion fue de %.2f \n", x_articulo.costo_produccion);
                //ya jala pero no se si tenga algo q ver con la cantidad de insumos q hay no se qpd

                // Clave de mercados *******************************************************************************************
                while (n_mercados < 10 && agregar_mercado == 's')
                {
<<<<<<< Updated upstream
                    fseek(mercado_local, (x_articulo.clave_mercados[n_mercados] - 1) * sizeof(struct Mercado), SEEK_SET);
=======
>>>>>>> Stashed changes

                    do
                    {
                        printf("8) Ingresa la clave de mercado %d: ", n_mercados + 1);
                        scanf("%d", &x_articulo.clave_mercados[n_mercados]);

                        // Validar si esta en Mercados.dat
                        fread(&mercado, sizeof(struct Mercado), 1, mercado_local);

                        if (mercado.clave_mercado == x_articulo.clave_mercados[n_mercados])
                        {
                            clave_valida = true;
                            n_mercados++;
                        }

                        if(!clave_valida)
                            printf("Clave del mercado no encontrada.\nIntenta con otra.\n");

                    } while (!clave_valida);// me falta comprobar si si jala **********************************************************

                    do
                    {
                        printf("Quieres agregar otro mercado al articulo?(s/n): \n");
                        fflush(stdin);
                        scanf("%c", &agregar_mercado);

                        if (agregar_mercado != 'S' && agregar_mercado != 's' && agregar_mercado != 'N' && agregar_mercado != 'n')
                            printf("Valor no vlido, solo se permite (s/n) \n");

                    } while (agregar_mercado != 'S' && agregar_mercado != 's' && agregar_mercado != 'N' && agregar_mercado != 'n');

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
                        printf("Valor no valido. Solo se permite S o N.\n");
                } while (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n');
            }
            fclose(insumolocal);
            fclose(mercado_local);
        }
    }
}
void menu_insumos(FILE *insumosf)
{
    char agregar, agregar_proveedor = 's';
    struct Insumo insumos;
    struct Proveedor proveedores;
    FILE *proveedorlocal;
    int cant_proveedores = 0;
    bool clave_valida = false;

    printf("%s\n", "INSUMOS\n");

    if((proveedorlocal = fopen("Proveedores.dat", "r")) == NULL)
        printf("Error.\nNo existen proveedores.\nAgrega en el menu correspondiente.\n");
    else
    {
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

            }while(insumos.inventario < 0 && cant_proveedores < 10);

            //hay q validar q exista en proveedores y maximo 10 checarlo pq esta mal**************************************************
            while(agregar_proveedor == 's' && cant_proveedores < 10)
            {
                do
                {
                    printf("5) Clave del proveedor: ");
                    scanf("%d", &insumos.clave_proveedor[cant_proveedores]);

                    fseek(proveedorlocal, (insumos.clave_proveedor[cant_proveedores] -1) * sizeof(struct Proveedor), SEEK_SET);
                    fread(&proveedores, sizeof(struct Proveedor), 1, proveedorlocal);

                    if(proveedores.numero_proveedor == insumos.clave_proveedor[cant_proveedores])
                    {
                        clave_valida = true;
                        cant_proveedores++;

                    }

                    if(!clave_valida)
                        printf("Clave del proveedor invalida\n");

                } while (!clave_valida);

                do
                {
                    printf("6) Precio: ");
                    scanf("%f", &insumos.precio_compra[cant_proveedores]);
                    if (insumos.precio_compra <= 0)
                        printf("Precio invalido\n");

                }while(insumos.precio_compra <= 0);

                do
                {
                    printf("Quieres agregar otro proveedor al insumo?(s/n): \n");
                    fflush(stdin);
                    scanf("%c", &agregar_proveedor);

                    if (agregar_proveedor != 's' && agregar_proveedor != 'n') //hay q ver como hacer para que acepte mayus
                        printf("Valor no valido, solo se permite (s/n) \n");

                }while (agregar_proveedor != 's' && agregar_proveedor != 'n');
            }

            if(cant_proveedores > 10)
                printf("El maximo son 10 proveedores \n");


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
        fclose(proveedorlocal);
    }

}

void menu_empleados(FILE *fempleados)
{
    struct Empleado empleados;
    bool rfc_valido = true, correo_correcto = true, validardia = true;
    char agregar = 's';

    printf("%s\n", "EMPLEADOS\n");

    while(agregar != 'n' && agregar != 'N')
    {
        do
        {
            printf("1) Ingrese su numero de empleado: ");
            scanf("%d", &empleados.numero_empleado);

            if(empleados.numero_empleado < 1 || empleados.numero_empleado > 1000)
                printf("Numero de empleado invalido\n");

        }while(empleados.numero_empleado < 1 || empleados.numero_empleado > 1000);

        do
        {
            printf("2) Nombre completo: ");
            fflush(stdin);
            gets(empleados.nombre_completo);
            if (strlen(empleados.nombre_completo) < 20)
                printf("Los caracteres minimos son 20 \n");

        }while (strlen(empleados.nombre_completo) < 20);

        do //falta validar lo correspondiente primero lo checamos y luego ya lo pegamos***********************************
        {
            printf("3) RFC: ");
            fflush(stdin);
            gets(empleados.RFC);

            if (strlen(empleados.RFC) != 13)
            {
                printf("Los caracteres deben de ser 13.\n");
                rfc_valido = false;
            }
            else
                rfc_valido = validar_rfc(empleados.RFC);

            if (rfc_valido == false)
                printf("RFC invalido. No cumple con la estructurada adecuada\n");

        }while(rfc_valido == false);//*********************************************************************************

        do
        {
            printf("4) Correo electronico: ");
            fflush(stdin);
            gets(empleados.correo);

            correo_correcto = validar_correo(empleados.correo);

            if (correo_correcto == false)
                printf("El correo no cumple con el formato\n");

        }while(correo_correcto == false);//******************************************************************

        do
        {
            printf("5) Comision recibida: ");
            scanf("%f", &empleados.comision);

            if(empleados.comision < 0)
                printf("Comision invalida");

        }while(empleados.comision < 0);

        do
        {
            printf("6) Año de nacimiento: ");
            scanf("%d", &empleados.anio_contratacion);

            if (empleados.anio_contratacion < 1990 || empleados.anio_contratacion > 2024)
                printf("Año de nacimiento invalido, debe de estar entre 1950 y 2006\n");

        }while (empleados.anio_contratacion < 1990 || empleados.anio_contratacion > 2024);

        do
        {
            printf("7) Mes de nacimiento: ");
            scanf("%d", &empleados.mes_contratacion);
            if (empleados.mes_contratacion < 1 || empleados.mes_contratacion > 12)
                printf("Mes de nacimiento invalido, debe de estar entre 1 y 12\n");

        }while (empleados.mes_contratacion < 1 || empleados.mes_contratacion > 12);

        do
        {
            printf("8) Dia de nacimiento: ");//validar q dia corresponda a mes***************************
            scanf("%d", &empleados.dia_contratacion);
            validardia = validarDiaMes(empleados.dia_contratacion, empleados.mes_contratacion, empleados.anio_contratacion);
            if (!validardia)
                printf("Ingrese un dia valido correspondiente al mes\n");

        }while (!validardia);//**********************************************************


        do
        {
            printf("9) Direccion: ");//validar cositas esas************************************************
            fflush(stdin);
            gets(empleados.direccion);
            if (strlen(empleados.direccion) < 0)
                printf("Falta validar.\n");

        }while (strlen(empleados.direccion) < 0);//*****************************************************************

        fseek(fempleados, (empleados.numero_empleado - 1) * sizeof(struct Empleado), SEEK_SET);
        fwrite(&empleados, sizeof(struct Empleado), 1, fempleados);

        do
        {
            printf("Agregar otro empleado? (S/N): ");
            fflush(stdin);
            scanf("%c", &agregar);
            if (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n')
                printf("Valor no valido.\nSolo se permite S o N.\n");

        }while (agregar != 'S' && agregar != 's' && agregar != 'N' && agregar != 'n');
    }
}

void menu_proveedores(FILE *fproveedores)
{
    struct Proveedor proveedores;
    char agregar = 's';
    bool rfc_valido = true, correo_correcto = true, validardia = true;

    printf("%s", "\nPROVEEDORES\n");

    while(agregar != 'n' && agregar != 'N')
    {
        do
        {
            printf("1) Ingrese su numero de proveedor: ");
            scanf("%d", &proveedores.numero_proveedor);

            if(proveedores.numero_proveedor < 1 || proveedores.numero_proveedor > 100)
                printf("Numero de proveedor invalido\n");

        }while(proveedores.numero_proveedor < 1 || proveedores.numero_proveedor > 100);

        do
        {
            printf("2) Nombre completo: ");
            fflush(stdin);
            gets(proveedores.nombre_completo);
            if (strlen(proveedores.nombre_completo) < 10)
                printf("Los caracteres minimos son 10 \n");

        }while (strlen(proveedores.nombre_completo) < 10);

        do
        {
            printf("3) RFC: ");
            fflush(stdin);
            gets(proveedores.RFC);

            if (strlen(proveedores.RFC) != 13)
            {
                printf("Los caracteres deben ser 13.\n");
                rfc_valido = false;
            }

            else
                rfc_valido = validar_rfc(proveedores.RFC);

            if (!rfc_valido)
                printf("RFC invalido. No cumple con la estructurada adecuada\n");

        }while(!rfc_valido);


        do //falta validar @ y punto
        {
            printf("4) Correo electronico: ");
            fflush(stdin);
            gets(proveedores.correo);

            correo_correcto = validar_correo(proveedores.correo);

            if (correo_correcto == false)
                printf("El correo no cumple con el formato\n");

        }while(correo_correcto == false);


        do
        {
            printf("5) Descuento: ");
            scanf("%f", &proveedores.descuento);

            if (proveedores.descuento < 0 || proveedores.descuento > 1)
                printf("Descuento invalido debe de estar entre 0 y 1.\n");

        }while (proveedores.descuento < 0 || proveedores.descuento > 1);

        do
        {
            printf("6) Anio de nacimiento: ");
            scanf("%d", &proveedores.anio_nacimiento);
            if (proveedores.anio_nacimiento < 1950 || proveedores.anio_nacimiento > 2006)
                printf("Año de nacimiento invalido, debe de estar entre 1950 y 2006\n");

        }while (proveedores.anio_nacimiento < 1950 || proveedores.anio_nacimiento > 2006);

        do
        {
            printf("7) Mes de nacimiento: ");
            scanf("%d", &proveedores.mes_nacimiento);
            if (proveedores.mes_nacimiento < 1 || proveedores.mes_nacimiento > 12)
                printf("Mes de nacimiento invalido, debe de estar entre 1 y 12\n");

        }while (proveedores.mes_nacimiento < 1 || proveedores.mes_nacimiento > 12);

        do
        {
            printf("8) Dia de nacimiento: ");//validar q dia corresponda a mes
            scanf("%d", &proveedores.dia_nacimiento);
            validardia = validarDiaMes(proveedores.dia_nacimiento, proveedores.mes_nacimiento, proveedores.anio_nacimiento);
            if (!validardia)
                printf("Ingrese un dia valido correspondiente al mes\n");

        }while (!validardia);


        do
        {
            printf("9) Direccion: ");//validar cositas esas
            fflush(stdin);
            gets(proveedores.direccion);
            if (strlen(proveedores.direccion) < 0)
                printf("Falta validar.\n");

        }while (strlen(proveedores.direccion) < 0);

        fseek(fproveedores, (proveedores.numero_proveedor - 1) * sizeof(struct Proveedor), SEEK_SET);
        fwrite(&proveedores, sizeof(struct Proveedor), 1, fproveedores);

        do
        {
            printf("Agregar otro proveedor (S/N): ");
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

bool validar_rfc(char *frfc) {
    int i;

    // Verificar longitud
    if (strlen(frfc) != 13) {
        return false;
    }

    // Validar las primeras 4 letras
    for (i = 0; i < 4; i++) {
        if (!((frfc[i] >= 'A' && frfc[i] <= 'Z') || (frfc[i] >= 'a' && frfc[i] <= 'z'))) {
            return false; // Si uno no es letra, retorna falso
        }
    }

    // Validar los siguientes 6 dígitos
    for (i = 4; i < 10; i++) {
        if (frfc[i] < '0' || frfc[i] > '9') {
            return false; // Si uno no es dígito, retorna falso
        }
    }

    // Validar los últimos 3 caracteres (alfanuméricos)
    for (i = 10; i < 13; i++) {
        if (!((frfc[i] >= 'A' && frfc[i] <= 'Z') || (frfc[i] >= 'a' && frfc[i] <= 'z') || (frfc[i] >= '0' && frfc[i] <= '9'))) {
            return false; // Si uno no es alfanumérico, retorna falso
        }
    }

    return true; // Si todos cumplen, retorna verdadero
}

void menu_mercados(FILE *mercadosf)
{
    char agregar;
    struct Mercado mercados;
    bool correo_correcto = true, rfc_valido=true, validardia=true; //checar si se puede inicializar o no

    printf("%s\n", "MERCADOS\n");

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
            {
                printf("Los caracteres deben ser 13.\n");
                rfc_valido = false;
            }

            else
                rfc_valido = validar_rfc(mercados.RFC);

            if (!rfc_valido)
                printf("RFC invalido. No cumple con la estructurada adecuada\n");

        }while(!rfc_valido);

        do
        {
            printf("4) Correo electronico: ");
            fflush(stdin);
            gets(mercados.correo);

            correo_correcto = validar_correo(mercados.correo);

            if (correo_correcto == false)
                printf("El correo no cumple con el formato\n");

        }while(correo_correcto == false);

        do
        {
            printf("5) Descuento: ");
            scanf("%f", &mercados.descuento);

            if (mercados.descuento < 0 || mercados.descuento > 1)
                printf("Descuento invalido debe de estar entre 0 y 1.\n");

        }while (mercados.descuento < 0 || mercados.descuento > 1);


        do
        {
            printf("6) Anio de nacimiento: ");
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
            validardia = validarDiaMes(mercados.dia_nacimiento, mercados.mes_nacimiento, mercados.anio_nacimiento);
            if (!validardia)
                printf("Ingrese un dia valido correspondiente al mes\n");
        }while (!validardia);


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

bool validar_correo(char * fcorreo)
{
    int arroba = 0, punto = 0, i;

    for(i = 0; fcorreo[i] != '\0'; i++)
    {
        if(fcorreo[i] == '@')
            arroba = i;

        else if(fcorreo[i] == '.')
            punto = i;
    }

    if(arroba < punto)
        return true;

    else
        return false;
}

bool validarDiaMes(int dia, int mes, int anio)
{
    int diasEnMes;

    switch (mes)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasEnMes = 31;
            break;
        case 4: case 6: case 9: case 11:
            diasEnMes = 30;
            break;
        case 2:
            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
                diasEnMes = 29;
            else
                diasEnMes = 28;
            break;
    }
    return dia >= 1 && dia <= diasEnMes;
}

/*void menu_control_ventas() // archivos secuenciales
{
    FILE *mercadolocal;
    struct Mercado mercados;
    int mercado, articulo, cantidad, empleado;
    float precio;
    char factura;


    //imprimir numero de mercado debe existir en mercados, devolver bool
    if((mercadolocal = fopen("Mercados.dat", "r")) == NULL)
        printf("Error con el archivo de mercados\n");

    else
        {
            printf("Numero de mercados: \n");

            while (!feof(stdin))
            {
                fread()
            }

        }

        fclose(Mercadolocal);

        printf("Ingrese la clave de mercado: \n");
        scanf("%d", &mercado);

        //lo correspondiente

    //numero de articulo debe existir en articulos, devolver bool

    printf("Ingrese el numero de articulo: \n");
    scanf("%d", &mercado);

    //cantidad maor a 0 y suficiente inventario para la venta y bool COMO RAYOS ES ESO DE Q TIENE Q SUFICIENTE PARA LA VENTA?
    do
    {
        printf("Ingrese la cantidad: \n");
        scanf("%d", &cantidad);

        if (cantidad < 0)
            printf("Cantidad invalida \n");

    } while (cantidad < 0);


    //precio del catalago de articulos para el calculo a pagar traerlo para aca

    //numero de empleado debe existir en empleados

    //factura preguntar si desea y si si imprimirlo

    do
    {
        printf("Deseas recibir una factura?: \n");
        fflush(stdin);
        scanf("%c", &factura);
        if (factura != 'S' && factura != 's' && factura != 'N' && factura != 'n')
            printf("Valor no valido.\nSolo se permite S o N.\n");

    }while (factura != 'S' && factura != 's' && factura != 'N' && factura != 'n');




}*/
<<<<<<< Updated upstream
=======

void crearRegistrosVacios(const char *nombreArchivo, void *registroVacio, size_t tamanoRegistro, int cantidad) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (!archivo) {
        printf("Error al abrir el archivo");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        fwrite(registroVacio, tamanoRegistro, 1, archivo);
    }

    fclose(archivo);
}
>>>>>>> Stashed changes
