#include <stdio.h>
#include <stdlib.h>

struct Articulos {
    int clave_articulo;
    char descripcion[150];
    char temp_siembra[50];
    char temp_cosecha[50];
    int clave_mercados[10];
    int insumos_requeridos[10];
    float costo_produccion;
    int inventario;
    float precio_venta;
};

void mostrar_datos_articulos(const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "rb"); // Abrir el archivo en modo binario
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    struct Articulos articulo;

    // Leer y mostrar cada registro
    while (fread(&articulo, sizeof(struct Articulos), 1, archivo) == 1) {
        printf("Clave de Artículo: %d\n", articulo.clave_articulo);
        printf("Descripción: %s\n", articulo.descripcion);
        printf("Temporada de Siembra: %s\n", articulo.temp_siembra);
        printf("Temporada de Cosecha: %s\n", articulo.temp_cosecha);

        printf("Claves de Mercados: ");
        for (int i = 0; i < 10; i++) {
            if (articulo.clave_mercados[i] != 0) {
                printf("%d ", articulo.clave_mercados[i]);
            }
        }
        printf("\n");

        printf("Insumos Requeridos: ");
        for (int i = 0; i < 10; i++) {
            if (articulo.insumos_requeridos[i] != 0) {
                printf("%d ", articulo.insumos_requeridos[i]);
            }
        }
        printf("\n");

        printf("Costo de Producción: %.2f\n", articulo.costo_produccion);
        printf("Inventario: %d\n", articulo.inventario);
        printf("Precio de Venta: %.2f\n\n", articulo.precio_venta);
    }

    fclose(archivo); // Cerrar el archivo
}

int main() {
    const char *nombre_archivo = "..\\Articulos.dat";
    mostrar_datos_articulos(nombre_archivo);
    return 0;
}
