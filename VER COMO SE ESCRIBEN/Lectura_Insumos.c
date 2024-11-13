#include <stdio.h>
#include <stdlib.h>

struct Fechas
{
    int anio;
    int mes;
    int dia;
};

struct Direcciones
{
    char calle[50];
    int numero;
    char colonia[50];
    char municipio[50];
    char estado[50];
};

struct Insumo
{
    int clave_insumo;
    char descripcion[100];
    int punto_reorden;
    int inventario;
    int clave_proveedor[10]; // Hasta 10 claves de proveedores
    float precio_compra[10];
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

// Función para mostrar la información de los insumos
void mostrar_insumos(FILE *insumosf, FILE *proveedorlocal) {
    struct Insumo insumos;
    struct Proveedor proveedores;
    int i;

    // Verificar si el archivo de insumos está abierto
    if (insumosf == NULL) {
        printf("Error al abrir el archivo de insumos.\n");
        return;
    }

    // Leer cada insumo y mostrar su información
    printf("\n--- Lista de Insumos ---\n");
    while (fread(&insumos, sizeof(struct Insumo), 1, insumosf) == 1) {
        printf("Clave del Insumo: %d\n", insumos.clave_insumo);
        printf("Descripcion: %s\n", insumos.descripcion);
        printf("Punto de Reorden: %d\n", insumos.punto_reorden);
        printf("Inventario: %d\n", insumos.inventario);
        printf("Proveedores: \n");

        // Leer la información de los proveedores
        for (i = 0; i < 10; i++) {
            
                fseek(proveedorlocal, (insumos.clave_proveedor[i] - 1) * sizeof(struct Proveedor), SEEK_SET);
                fread(&proveedores, sizeof(struct Proveedor), 1, proveedorlocal);
                printf(" [%d] Proveedor Clave: %d, Precio: %.2f\n", i,insumos.clave_proveedor[i], insumos.precio_compra[i]);
            }
        
        printf("\n");
    }
}

int main() {
    FILE *insumosf;
    FILE *proveedorlocal;

    // Abrir el archivo de insumos
    insumosf = fopen("..\\Insumos.dat", "rb");
    // Abrir el archivo de proveedores
    proveedorlocal = fopen("..\\Proveedores.dat", "rb");

    // Mostrar la información de los insumos
    mostrar_insumos(insumosf, proveedorlocal);

    // Cerrar los archivos
    fclose(insumosf);
    fclose(proveedorlocal);

    return 0;
}