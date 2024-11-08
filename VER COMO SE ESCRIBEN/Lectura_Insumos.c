#include <stdio.h>
#include <stdlib.h>

struct Insumo
{
    int clave_insumo;
    char descripcion[100];
    int punto_reorden;
    int inventario;
    int clave_proveedor[10]; // Hasta 10 claves de proveedores
    float precio_compra[10]; // Hasta 10 precios de compra
};

void mostrar_datos_insumos(const char *nombre_archivo) {
    FILE *archivo = fopen("..\\Insumos.dat", "r"); // Abrir el archivo en modo binario
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
                if (i < 9 && insumo.clave_proveedor[i + 1] != 0) {
                    printf(", ");
                }
            }
        }
        printf("\n");

        printf("Precios de Compra: ");
        for (int i = 0; i < 10; i++) {
            if (insumo.precio_compra[i] != 0.0f) { // Muestra solo precios válidos
                printf("%.2f", insumo.precio_compra[i]);
                if (i < 9 && insumo.precio_compra[i + 1] != 0.0f) {
                    printf(", ");
                }
            }
        }
        printf("\n\n");
    }

    fclose(archivo); // Cerrar el archivo
}

int main() {
    const char *nombre_archivo = "..\\Insumos.dat";
    mostrar_datos_insumos(nombre_archivo);
    return 0;
}
