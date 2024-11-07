#include <stdio.h>
#include <stdlib.h>

struct Insumo {
    int clave_insumo;
    char descripcion[100];
    int punto_reorden;
    int inventario;
    int clave_proveedor[10]; // Hasta 10 claves de proveedores
    float precio_compra;
};

void mostrar_datos_insumos(const char *nombre_archivo) {
    FILE *archivo = fopen("Insumos.dat", "rb"); // Abrir el archivo en modo binario
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    struct Insumo insumo;

    // Leer y mostrar cada registro
    while (fread(&insumo, sizeof(struct Insumo), 1, archivo) == 1) {
        printf("Clave de Insumo: %d\n", insumo.clave_insumo);
        printf("Descripción: %s\n", insumo.descripcion);
        printf("Punto de Reorden: %d\n", insumo.punto_reorden);
        printf("Inventario: %d\n", insumo.inventario);

        printf("Claves de Proveedor: ");
        for (int i = 0; i < 10; i++) {
            if (insumo.clave_proveedor[i] != 0) { // Muestra solo claves válidas
                printf("%d", insumo.clave_proveedor[i]);
            }
        }
        printf("\n");

        printf("Precio de Compra: %.2f\n\n", insumo.precio_compra);
    }

    fclose(archivo); // Cerrar el archivo
}

int main() {
    const char *nombre_archivo = "Insumos.dat";
    mostrar_datos_insumos(nombre_archivo);
    return 0;
}
