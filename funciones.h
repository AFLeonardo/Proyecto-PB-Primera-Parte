#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ESTRUCTURAS_H

// MENUS
int menu_principal();
void menu_articulos(FILE *);
void menu_insumos(FILE *);
void menu_mercados(FILE *);
void menu_empleados(FILE *);
void menu_proveedores(FILE *);
void menu_control_ventas(FILE *);
void menu_control_compras(FILE *);
void menu_control_inventario(FILE *);
void menu_reportes(FILE *);

// FUNCIONES
char *convertir_a_minusculas(char *);
bool validar_rfc(char *);
bool validar_correo(char *);
bool validarDiaMes(int, int, int);
void crearRegistrosVacios(const char *, void *, size_t , int );
bool validarmercado(int);
bool validararticulo(int);
bool validarcantidad(int, int );
float precio(int);
bool validarempleado(int );
float descuento(int );
bool validarchar(char *);
bool validarnumerodireccion(char *);
void imprimir_factura(int, int, int, float, int, float);
bool validarproveedor(int );
bool validarnumeroinsumo(int );
float precioinsumo(int);
float descuento_proveedor(int );
float generar_comision(int, float);
//********************************** */


