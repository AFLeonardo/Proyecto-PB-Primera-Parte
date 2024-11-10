#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fechas {
    int anio;
    int mes;
    int dia;
};

struct Direcciones {
    char calle[100];
    char numero[10];
    char colonia[50];
    char municipio[50];
    char estado[50];
};

struct Mercado {
    int clave_mercado;
    char nombre_completo[100];
    char RFC[14];
    char correo[100];
    float descuento;
    struct Fechas fecha;
    struct Direcciones direccion;
};

// Función para mostrar la información de los mercados
void mostrar_mercados(FILE *mercado_local) {
    struct Mercado mercado;

    // Verificar si el archivo de mercados está abierto
    if (mercado_local == NULL) {
        printf("Error al abrir el archivo de mercados.\n");
        return;
    }

    // Leer cada mercado y mostrar su información
    printf("\n--- Lista de Mercados ---\n");
    while (fread(&mercado, sizeof(struct Mercado), 1, mercado_local) == 1) {
        printf("Clave del Mercado: %d\n", mercado.clave_mercado);
        printf("Nombre Completo: %s\n", mercado.nombre_completo);
        printf("RFC: %s\n", mercado.RFC);
        printf("Correo: %s\n", mercado.correo);
        printf("Descuento: %f\n", mercado.descuento);
        printf("Fecha: %02d/%02d/%d\n", mercado.fecha.dia, mercado.fecha.mes, mercado.fecha.anio);
        printf("Direccion: %s %d, %s, %s, %s\n", 
               mercado.direccion.calle, 
               mercado.direccion.numero, 
               mercado.direccion.colonia, 
               mercado.direccion.municipio, 
               mercado.direccion.estado);
        printf("\n");
    }
}

int main() {
    FILE *mercado_local;

    // Abrir el archivo de mercados
    mercado_local = fopen("..\\Mercados.dat", "rb");

    // Mostrar la información de los mercados
    mostrar_mercados(mercado_local);

    // Cerrar el archivo
    fclose(mercado_local);

    return 0;
}