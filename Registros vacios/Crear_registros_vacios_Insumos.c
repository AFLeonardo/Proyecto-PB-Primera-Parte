#include <stdio.h>
#include <string.h>

struct Insumo {
    int clave_insumo;
    char descripcion[100];
    int punto_reorden;
    int inventario;
    int clave_proveedor[10];
    float precio_compra[10];
};

int main() {
    FILE *archivo;
    struct Insumo insumo_vacio;

    // Inicializa el registro vacío con valores predeterminados
    insumo_vacio.clave_insumo = 0;
    strcpy(insumo_vacio.descripcion, "");
    insumo_vacio.punto_reorden = 0;
    insumo_vacio.inventario = 0;
    for (int i = 0; i < 10; i++) {
        insumo_vacio.clave_proveedor[i] = 0;
        insumo_vacio.precio_compra[i] = 0.0;
    }

    // Abre el archivo en modo escritura binaria ("wb")
    archivo = fopen("..\\Insumos.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo 'Insumos.dat'.\n");
        return 1;
    }

    // Escribir 10 registros vacíos en el archivo
    for (int i = 0; i < 10; i++) {
        fwrite(&insumo_vacio, sizeof(struct Insumo), 1, archivo);
    }

    fclose(archivo);  // Cierra el archivo después de escribir
    printf("Se han escrito 10 registros vacíos en 'Insumos.dat'.\n");

    return 0;
}
