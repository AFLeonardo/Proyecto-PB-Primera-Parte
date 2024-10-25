# PIA de Edna Alch

## Descripción General
En una granja de la localidad, se dedican a cultivar una gran variedad de frutas y verduras, las cuales, en su tiempo, son vendidas en los mercados locales. Últimamente han aumentado sus ventas, por lo que requieren un sistema automático que los ayude a: llevar el control de sus ventas, empleados, artículos, clientes, proveedores e inventario tanto del producto terminado, así como los insumos para producirlos (semillas, fertilizante, etc.), para lo cual, se ha iniciado un análisis de los datos para poder automatizar dicha información.

## Artículo
Para cada artículo se cuenta con la siguiente información:
- Clave del artículo
- Descripción
- Temporada de siembra
- Temporada de cosecha
- Claves de los mercados al que los surten
- Insumos (Material Prima) requeridos
- Costo de producción
- Inventario
- Precio de venta

### Validaciones:
- Clave de artículo, número entre 1 y 1,000, el usuario podrá capturar cualquier número.
- Descripción, al menos 10 caracteres.
- Clave de mercados, a lo más son 10 y debe existir en el catálogo de mercados.
- Insumos requeridos, debe incluir la clave de los insumos.
- Costo y precio, mayor que cero.
- Inventario, igual o mayor a cero.

## Insumo
Para cada insumo se cuenta con la siguiente información:
- Clave del insumo
- Descripción
- Punto de reorden
- Inventario
- Número de cada proveedor
- Precio al que los surten

### Validaciones:
- Clave del insumo, número entre 1 y 100.
- Descripción, al menos 10 caracteres.
- Punto de reorden, mayor que cero.
- Inventario, igual o mayor a cero.
- Número de proveedor, debe existir en el catálogo de proveedores.
- Precio mayor a 0.

## Proveedor
Para cada proveedor:
- Número de proveedor
- Nombre completo
- RFC
- Correo electrónico
- Descuento
- Año, mes y día de nacimiento
- Dirección

### Validaciones:
- Número de proveedor, número entre 1 y 100.
- Nombre, al menos tenga 10 caracteres.
- RFC, validar que sean 13 caracteres.
- Correo electrónico, validar que contenga la @ y un punto después de ella.
- Descuento, este entre 0 y 1.
- Año, que se encuentre entre 1950 y 2006.
- Mes, que se encuentre entre 1 y 12.
- Día, que corresponda a los días del mes.
- Dirección, que incluya calle, número, colonia, municipio y Estado.

## Mercado
Para cada mercado:
- Clave del mercado
- Nombre completo
- RFC
- Correo electrónico
- Descuento
- Año, mes y día de nacimiento
- Dirección

### Validaciones:
- Clave del mercado, mayor que cero.
- Nombre, al menos tenga 10 caracteres.
- RFC, validar que sean 13 caracteres.
- Correo electrónico, validar que contenga la @ y un punto después de ella.
- Descuento, este entre 0 y 1.
- Año, que se encuentre entre 1950 y 2006.
- Mes, que se encuentre entre 1 y 12.
- Día, que corresponda a los días del mes.
- Dirección, que incluya calle, número, colonia, municipio y Estado.

## Empleado
Para cada empleado:
- Número de empleado
- Nombre completo
- RFC
- Correo electrónico
- Porcentaje de comisión recibida
- Año, mes y día de contratación
- Dirección

### Validaciones:
- Número de empleado, valor entre 1 y 1,000.
- Nombre completo, al menos tenga 20 caracteres.
- RFC, validar que sean 13 caracteres.
- Correo electrónico, validar que contenga la @ y un punto con letras antes y después de él.
- Año, que se encuentre entre 1990 y año actual.
- Mes, que se encuentre entre 1 y 12.
- Día, que corresponda a los días del mes.
- Dirección, que incluya calle, número, colonia, municipio y Estado.

## Venta
Para cada venta que se realice a los mercados, se tendrá lo siguiente:
- Número de mercado (cliente)
- Número de artículo
- Cantidad
- Precio
- Factura

### Validaciones:
- Número de mercado, validar que existe en el catálogo de mercados.
- Número de artículo, validar que existe en el catálogo de artículos.
- Cantidad, validar que sea mayor a cero y que tenga el inventario suficiente para la venta.
- Precio, traerlo del catálogo de artículos.
- Número de empleado, validar que exista en el catálogo de empleados.
- Factura, se le preguntará al usuario si desea factura.

## Compra
Para cada compra que se realice a los proveedores, se tendrá lo siguiente:
- Número de proveedor
- Número de insumo
- Cantidad
- Precio

### Validaciones:
- Número de proveedor, validar que existe en el catálogo de proveedores.
- Número de insumo, validar que existe en el catálogo de insumos.
- Cantidad, validar que sea mayor a cero.
- Precio, traerlo del catálogo de insumos.

## Control de Inventario
Para el control de inventarios, se utiliza para llevar un registro de las compras de insumos que se hicieron y que ya se recibieron en nuestra granja.
- Número de proveedor, validar que exista en el catálogo.
