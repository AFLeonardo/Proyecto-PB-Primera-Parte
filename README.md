# ESTO ES EL PIA DE EDNA ALCH ESTA BIEN LARGOTE Y PURAS MAMADAS QUE SE INVENTA LA SEÑORA

En una granja de la localidad, se dedican a cultivar una gran variedad de frutas y verduras, las cuales, en su tiempo, son vendidas en los mercados locales. Últimamente han aumentado sus ventas, por lo que requieren un sistema automático que los ayude a: llevar el control de sus ventas, empleados, artículos, clientes, proveedores e inventario tanto del producto terminado, así como los insumos para producirlos (semillas, fertilizante, etc.), para lo cual, se ha iniciado un análisis de los datos para poder automatizar dicha información. 

Una vez llevado a cabo el análisis, se encontró lo siguiente:

# ARTICULO
Para cada artículo se cuenta con la siguiente información: clave del artículo, descripción, temporada de siembra, temporada de cosecha, claves de los mercados al que los surten, insumos (Material Prima) requeridos, costo de producción (Se calcula de acuerdo a los insumos), inventario y precio de venta. Se detectó que se tiene que validar:
•	clave de artículo, número entre 1 y 1,000, el usuario podrá capturar cualquier número, es decir, no llevan una secuencia.
•	Descripción, al menos 10 caracteres. Puede contener letras, números y espacios.
•	clave de mercados, A lo mas son 10 y debe existir en el catálogo de mercados.
•	Insumos requeridos, debe incluir la clave de los insumos (debe existir). A lo más son 10
•	Costo y precio, mayor que cero.
•	Inventario, igual o mayor a cero.
Crear una estructura para los datos del artículo

# INSUMO
Para cada insumo se cuenta con la siguiente información: clave del insumo (Se maneja el mismo número que tiene el proveedor), descripción, punto de reorden (es la cantidad mínima de existencia de un artículo, de modo que cuando el inventario llegue a esa cantidad, el artículo debe reordenarse), inventario, número de cada proveedor y precio al que los surten. Se detectó que se tiene que validar:
•	Clave del insumo, número entre 1 y 100, el usuario podrá capturar cualquier número, es decir, no llevan una secuencia.
•	Descripción, al menos 10 caracteres. Puede contener letras, números y espacios.
•	Punto de reorden, mayor que cero.
•	Inventario, igual o mayor a cero.
•	Número de proveedor, debe existir en el catálogo de proveedores.  A lo más pueden ser 10 (también validarlo).
•	Precio mayor a 0
Crear una estructura para los datos del insumo

# PROVEDOR
Para cada proveedor: número de proveedor, nombre completo, RFC, correo electrónico, descuento, año, mes y día de nacimiento, dirección. Cada proveedor tiene un listado de los artículos que produce, así como su precio de venta. Validar para estos datos lo siguiente:
•	Número de proveedor, número entre 1 y 100.
•	Nombre, al menos tenga 10 caracteres. Puede contener letras y espacios.
•	RFC, validar que sean 13 caracteres y que sigan la estructura de un RFC
•	Correo electrónico, validar que contenga la @ y un punto después de ella entre letras.
•	Descuento, este entre 0 y 1 
•	Año, que se encuentre entre 1950 y 2006 
•	Mes, que se encuentre entre 1 y 12 
•	Día, que corresponda a los días del mes.
•	Dirección, que incluya calle, número, colonia, municipio y Estado. Validar que solo sean letras, espacios y números, en cada dato
Crear una estructura para los datos del proveedor

# MERCADO
Para cada mercado: clave del mercado, nombre completo, RFC, correo electrónico, descuento, año, mes y día de nacimiento, dirección. Validar para estos datos lo siguiente:
•	Clave del mercado, mayor que cero.
•	Nombre, al menos tenga 10 caracteres. Puede contener letras y espacios.
•	RFC, validar que sean 13 caracteres y lo correspondiente.
•	Correo electrónico, validar que contenga la @ y un punto después de ella.
•	Descuento, este entre 0 y 1
•	Año, que se encuentre entre 1950 y 2006 
•	Mes, que se encuentre entre 1 y 12 
•	Día, que corresponda a los días del mes.
•	Dirección, que incluya calle, número, colonia, municipio y Estado. Validar que solo sean letras, espacios y números, en cada dato
Crear una estructura para los datos del mercado
 
# EMPLEADO
Para cada empleado: número de empleado, nombre completo, RFC, correo electrónico, porcentaje de comisión recibida, año, mes y día de contratación, dirección. Validar para estos datos lo siguiente:
•	Número de empleado, valor entre 1 y 1,000.
•	Nombre completo, al menos tenga 20 caracteres. Puede contener letras y espacios.
•	RFC, validar que sean 13 caracteres.
•	Correo electrónico, validar que contenga la @ y un punto con letras antes y después de él.
•	Comisión. 
•	Año, que se encuentre entre 1990 y año actual
•	Mes, que se encuentre entre 1 y 12
•	Día, que corresponda a los días del mes.
•	Dirección, que incluya calle, número, colonia, municipio y Estado. Validar que solo sean letras, espacios y números, en cada dato
Crear una estructura para los datos del empleado



Utiliza estructuras anidadas en donde se requiere.
 

# VENTA
Para cada venta que se realice a los mercados, se tendrá lo siguiente: Número de mercado (cliente), número de artículo, cantidad, precio y factura. Validar para estos datos lo siguiente:
•	Número de mercado, validar que existe en el catálogo de mercados. (utilizar una función que regrese V o F, utilizando datos booleanos)
•	Número de artículo, validar que existe en el catálogo de artículos. (utilizar una función que regrese V o F, utilizando datos booleanos).
•	Cantidad, validar que sea mayor a cero y que tenga el inventario suficiente para la venta. (utilizar una función que regrese V o F, utilizando datos booleanos).
•	Precio, traerlo del catálogo de artículos para el cálculo de lo que pagará el cliente.
•	Número de empleado. (Validar que exista en el catálogo de empleados).
•	Factura. Se le preguntará al usuario si desea factura, y en caso afirmativo, se mandará a pantalla.

# COMPRA
Para cada compra que se realice a los proveedores, se tendrá lo siguiente: Número de proveedor, número de insumo, cantidad y precio. Validar para estos datos lo siguiente:
•	Número de proveedor, validar que existe en el catálogo de proveedores. (utilizar una función que regrese V o F, utilizando datos booleanos)
•	Número de insumo, validar que existe en el catálogo de insumos y que el proveedor corresponda al indicado previamente. (utilizar una función que regrese V o F, utilizando datos booleanos).
•	Cantidad, validar que sea mayor a cero
•	Precio, traerlo del catálogo de insumos de tal forma que corresponda con el artículo indicado.

# CONTROL DE INVETARIO
Para el control de inventarios, se utiliza para llevar un registro de las compras de insumos que se hicieron y que ya las recibimos en nuestra granja.
•	Número de proveedor, validar que exista en el catálogo
