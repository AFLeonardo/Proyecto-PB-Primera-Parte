#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Empleado
{
    int numero_empleado;
    char nombre_completo[100];
    char RFC[14];
    char correo[100];
    float comision;
    struct Fechas fecha;
    struct Direcciones direccion;
};

void mostrarEmpleados(FILE *file) {
    struct Empleado empleado;

    printf("\n--- Empleados ---\n");
    while (fread(&empleado, sizeof(struct Empleado), 1, file)) {
        printf("Número Empleado: %d\n", empleado.numero_empleado);
        printf("Nombre Completo: %s\n", empleado.nombre_completo);
        printf("RFC: %s\n", empleado.RFC);
        printf("Correo: %s\n", empleado.correo);
        printf("Comisión: %.2f\n", empleado.comision);
        printf("Fecha de Nacimiento: %d-%d-%d\n", empleado.fecha.anio, empleado.fecha.mes, empleado.fecha.dia);
        printf("Dirección:\n");
        printf("  Calle: %s\n", empleado.direccion.calle);
        printf("  Número: %d\n", empleado.direccion.numero);
        printf("  Colonia: %s\n", empleado.direccion.colonia);
        printf("  Municipio: %s\n", empleado.direccion.municipio);
        printf("  Estado: %s\n", empleado.direccion.estado);
        
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("..\\Empleados.dat", "rb"); // Asegúrate de que el nombre del archivo sea correcto

    if (file == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    mostrarEmpleados(file);

    fclose(file);
    return EXIT_SUCCESS;
}