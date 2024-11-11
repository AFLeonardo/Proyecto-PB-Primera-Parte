#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fechas
{
    int anio;
    int mes;
    int dia;
};

struct Direcciones
{
    char calle[50];
    char numero[30];
    char colonia[50];
    char municipio[50];
    char estado[50];
};

struct Proveedor
{
    int numero_proveedor;
    char nombre_completo[100];
    char RFC[14];
    char correo[100];
    float descuento;
    struct Fechas fecha;
    struct Direcciones direccion;
    int articulos_produce[10]; // Claves de los artículos que produce
};

// Función para mostrar la información de los proveedores
void mostrar_proveedores(FILE *proveedorlocal) {
    struct Proveedor proveedor;

    // Verificar si el archivo de proveedores está abierto
    if (proveedorlocal == NULL) {
        printf("Error al abrir el archivo de proveedores.\n");
        return;
    }

    // Leer cada proveedor y mostrar su información
    printf("\n--- Lista de Proveedores ---\n");
    while (fread(&proveedor, sizeof(struct Proveedor), 1, proveedorlocal) == 1) {
        printf("Numero de Proveedor: %d\n", proveedor.numero_proveedor);
        printf("Nombre Completo: %s\n", proveedor.nombre_completo);
        printf("RFC: %s\n", proveedor.RFC);
        printf("Correo: %s\n", proveedor.correo);
        printf("Descuento: %f\n", proveedor.descuento);
        printf("Fecha de Nacimiento: %02d/%02d/%d\n", proveedor.fecha.dia, proveedor.fecha.mes, proveedor.fecha.anio);
        printf("Direccion:");
        printf("Calle: %s\n", proveedor.direccion.calle);
        printf("Numero: %s\n", proveedor.direccion.numero);
        printf("Colonia: %s\n", proveedor.direccion.colonia);
        printf("Municipio: %s\n", proveedor.direccion.municipio);
        printf("Estado: %s\n", proveedor.direccion.estado);


        printf("Articulos que Produce: ");
        
        // Mostrar las claves de los artículos que produce
        for (int i = 0; i < 10; i++) {
                printf("%d", proveedor.articulos_produce[i]);
            }
        
        printf("\n\n");
    }
}

int main() {
    FILE *proveedorlocal;

    // Abrir el archivo de proveedores
    proveedorlocal = fopen("..\\Proveedores.dat", "r");

    // Mostrar la información de los proveedores
    mostrar_proveedores(proveedorlocal);

    // Cerrar el archivo
    fclose(proveedorlocal);

    return 0;
}