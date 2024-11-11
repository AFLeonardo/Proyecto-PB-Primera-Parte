#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Proveedor {
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
        printf("Número de Proveedor: %d\n", proveedor.numero_proveedor);
        printf("Nombre Completo: %s\n", proveedor.nombre_completo);
        printf("RFC: %s\n", proveedor.RFC);
        printf("Correo: %s\n", proveedor.correo);
        printf("Descuento: %.2f%%\n", proveedor.descuento);
        printf("Fecha de Nacimiento: %02d/%02d/%d\n", proveedor.dia_nacimiento, proveedor.mes_nacimiento, proveedor.anio_nacimiento);
        printf("Dirección: %s\n", proveedor.direccion);
        printf("Artículos que Produce: ");
        
        // Mostrar las claves de los artículos que produce
        for (int i = 0; i < 10; i++) {
            if (proveedor.articulos_produce[i] != 0) { // Suponiendo que 0 indica que no produce un artículo
                printf("%d ", proveedor.articulos_produce[i]);
            }
        }
        printf("\n\n");
    }
}

int main() {
    FILE *proveedorlocal;

    // Abrir el archivo de proveedores
    proveedorlocal = fopen("Proveedores.dat", "rb");

    // Mostrar la información de los proveedores
    mostrar_proveedores(proveedorlocal);

    // Cerrar el archivo
    fclose(proveedorlocal);

    return 0;
}