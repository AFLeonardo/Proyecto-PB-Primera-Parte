#include <stdio.h>

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

int main() {
    FILE *archivo;
    struct Proveedor proveedor;

    archivo = fopen("..\\Proveedores.dat", "rb");  // Abre el archivo en modo lectura binaria
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo 'Proveedores.dat'.\n");
        return 1;
    }

    // Leer y mostrar la información de cada proveedor en el archivo
    while (fread(&proveedor, sizeof(struct Proveedor), 1, archivo) == 1) {
        printf("Numero de Proveedor: %d\n", proveedor.numero_proveedor);
        printf("Nombre Completo: %s\n", proveedor.nombre_completo);
        printf("RFC: %s\n", proveedor.RFC);
        printf("Correo: %s\n", proveedor.correo);
        printf("Descuento: %.2f%%\n", proveedor.descuento);
        printf("Fecha de Nacimiento: %02d-%02d-%04d\n",
               proveedor.dia_nacimiento, proveedor.mes_nacimiento, proveedor.anio_nacimiento);
        printf("Direccion: %s\n", proveedor.direccion);

        printf("Articulos que Produce:\n");
        for (int i = 0; i < 10; i++) {
            if (proveedor.articulos_produce[i] != 0) {  // Para evitar mostrar artículos vacíos
                printf("  Articulo [%d]: %d\n", i + 1, proveedor.articulos_produce[i]);
            }
        }
        printf("\n");
    }

    fclose(archivo);  // Cierra el archivo después de leerlo
    return 0;
}
