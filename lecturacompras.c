#include <stdio.h>
#include "estructuras.c"
#include <stdio.h>

int main() {
    FILE *farchivo = fopen("Compras.txt", "r");
    FILE *archivo_insumo = fopen("insumos.dat", "r");

    if (farchivo == NULL || archivo_insumo == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    int id_compras = 0, num_proveedor, clave_insumo, cantidad;
    float precio, total, acumulado = 0;
    int auxiliar_id = -1;

    // Imprime el encabezado de la tabla
    printf("+--------------------+--------------------+------------------------------------------+--------------------+\n");
    printf("| %-18s | %-18s | %-40s | %-18s |\n", "ID Compra", "Insumo", "Descripcion", "Cantidad");
    printf("+--------------------+--------------------+------------------------------------------+--------------------+\n");

    // Leemos el archivo de compras
    while (!feof(farchivo)) {
        fscanf(farchivo, "ID compra: %d\n", &id_compras);
        fscanf(farchivo, "Numero de proveedor: %d\n", &num_proveedor);
        fscanf(farchivo, "Numero de insumo: %d\n", &clave_insumo);
        fscanf(farchivo, "Cantidad: %d\n", &cantidad);
        fscanf(farchivo, "Precio: %f\n", &precio);
        fscanf(farchivo, "Total: %f\n", &total);

        // Busca el insumo correspondiente
        fseek(archivo_insumo, (clave_insumo - 1) * sizeof(struct Insumo), SEEK_SET);
        struct Insumo insumos;
        fread(&insumos, sizeof(struct Insumo), 1, archivo_insumo);

        // Si cambia el ID de compra, imprime el acumulado y resetear
        if (id_compras != auxiliar_id) {
            if (auxiliar_id != -1) {
                printf("Total: %.2f\n", acumulado);
                printf("+--------------------+--------------------+------------------------------------------+--------------------+\n");
            }

            auxiliar_id = id_compras;
            acumulado = 0;

            // Imprime la información de la compra
            if (clave_insumo == insumos.clave_insumo) {
                printf("| %-18d | %-18d | %-40s | %-18d |\n", id_compras, clave_insumo, insumos.descripcion, cantidad);
            }

            // Acumula el total de la compra
            acumulado += total;
        }
    }

    // Imprime el total final si es necesario
    if (auxiliar_id != -1) {
        printf("Total: %.2f\n", acumulado);
    }

    printf("+--------------------+--------------------+------------------------------------------+--------------------+\n");

    fclose(farchivo);
    fclose(archivo_insumo);

    return 0;
}
