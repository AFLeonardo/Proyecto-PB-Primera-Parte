#include <stdio.h>
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

int main() {
    FILE *archivo;
    struct Proveedor proveedor_vacio;

    // Inicializa el registro vacío con valores predeterminados
    proveedor_vacio.numero_proveedor = 0;
    strcpy(proveedor_vacio.nombre_completo, "");
    strcpy(proveedor_vacio.RFC, "");
    strcpy(proveedor_vacio.correo, "");
    proveedor_vacio.descuento = 0.0;
    proveedor_vacio.anio_nacimiento = 0;
    proveedor_vacio.mes_nacimiento = 0;
    proveedor_vacio.dia_nacimiento = 0;
    strcpy(proveedor_vacio.direccion, "");
    for (int i = 0; i < 10; i++) {
        proveedor_vacio.articulos_produce[i] = 0;
    }

    // Abre el archivo en modo escritura binaria ("wb")
    archivo = fopen("..\\Proveedores.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo 'Proveedores.dat'.\n");
        return 1;
    }

    // Escribir 10 registros vacíos en el archivo
    for (int i = 0; i < 100; i++) {
        fwrite(&proveedor_vacio, sizeof(struct Proveedor), 1, archivo);
    }

    fclose(archivo);  // Cierra el archivo después de escribir
    printf("Se han escrito 10 registros vacíos en 'Proveedores.dat'.\n");

    return 0;
}
