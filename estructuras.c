// ESTRUCTURAS
struct Articulos
{
    int clave_articulo;
    char descripcion[150];
    char temp_siembra[50];
    char temp_cosecha[50];
    int clave_mercados[10];
    int insumos_requeridos[10]; //POR QUE SON MAXIMO 10 INSUMOS POR ARTICULO
    float costo_produccion;
    int inventario;
    float precio_venta;
};
struct Insumo
{
    int clave_insumo;
    char descripcion[100];
    int punto_reorden;
    int inventario;
    int clave_proveedor[10]; // Hasta 10 claves de proveedores
    float precio_compra[10];
};
struct Proveedor
{
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
struct Empleado
{
    int numero_empleado;
    char nombre_completo[100];
    char RFC[14];
    char correo[100];
    float comision;
    int anio_contratacion;
    int mes_contratacion;
    int dia_contratacion;
    char direccion[200];
};
struct Mercado
{
    int clave_mercado;
    char nombre_completo[100];
    char RFC[14];
    char correo[100];
    float descuento;
    int anio_nacimiento;
    int mes_nacimiento;
    int dia_nacimiento;
    char direccion[200];
};
struct Venta
{
    int numero_mercado;
    int numero_articulo;
    int cantidad;
    float precio_total;
    int numero_empleado;
    int factura;
};
struct Compra
{
    int numero_proveedor;
    int numero_insumo;
    int cantidad;
    float precio_total;
};