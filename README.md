<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PIA de Edna Alch</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 20px;
            background-color: #f4f4f4;
            color: #333;
        }
        h1 {
            color: #2c3e50;
        }
        h2 {
            color: #2980b9;
        }
        h3 {
            color: #27ae60;
        }
        ul {
            margin: 10px 0;
        }
        li {
            margin-bottom: 5px;
        }
        .section {
            background: #fff;
            padding: 15px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            margin-bottom: 20px;
        }
    </style>
</head>
<body>
    <h1>PIA de Edna Alch</h1>
    <div class="section">
        <h2>Descripción General</h2>
        <p>En una granja de la localidad, se dedican a cultivar una gran variedad de frutas y verduras, las cuales, en su tiempo, son vendidas en los mercados locales. Últimamente han aumentado sus ventas, por lo que requieren un sistema automático que los ayude a: llevar el control de sus ventas, empleados, artículos, clientes, proveedores e inventario tanto del producto terminado, así como los insumos para producirlos (semillas, fertilizante, etc.), para lo cual, se ha iniciado un análisis de los datos para poder automatizar dicha información.</p>
    </div>

    <div class="section">
        <h2>Artículo</h2>
        <p>Para cada artículo se cuenta con la siguiente información:</p>
        <ul>
            <li>Clave del artículo</li>
            <li>Descripción</li>
            <li>Temporada de siembra</li>
            <li>Temporada de cosecha</li>
            <li>Claves de los mercados al que los surten</li>
            <li>Insumos (Material Prima) requeridos</li>
            <li>Costo de producción</li>
            <li>Inventario</li>
            <li>Precio de venta</li>
        </ul>
        <h3>Validaciones:</h3>
        <ul>
            <li>Clave de artículo, número entre 1 y 1,000, el usuario podrá capturar cualquier número.</li>
            <li>Descripción, al menos 10 caracteres.</li>
            <li>Clave de mercados, a lo más son 10 y debe existir en el catálogo de mercados.</li>
            <li>Insumos requeridos, debe incluir la clave de los insumos.</li>
            <li>Costo y precio, mayor que cero.</li>
            <li>Inventario, igual o mayor a cero.</li>
        </ul>
    </div>

    <div class="section">
        <h2>Insumo</h2>
        <p>Para cada insumo se cuenta con la siguiente información:</p>
        <ul>
            <li>Clave del insumo</li>
            <li>Descripción</li>
            <li>Punto de reorden</li>
            <li>Inventario</li>
            <li>Número de cada proveedor</li>
            <li>Precio al que los surten</li>
        </ul>
        <h3>Validaciones:</h3>
        <ul>
            <li>Clave del insumo, número entre 1 y 100.</li>
            <li>Descripción, al menos 10 caracteres.</li>
            <li>Punto de reorden, mayor que cero.</li>
            <li>Inventario, igual o mayor a cero.</li>
            <li>Número de proveedor, debe existir en el catálogo de proveedores.</li>
            <li>Precio mayor a 0.</li>
        </ul>
    </div>

    <div class="section">
        <h2>Proveedor</h2>
        <p>Para cada proveedor:</p>
        <ul>
            <li>Número de proveedor</li>
            <li>Nombre completo</li>
            <li>RFC</li>
            <li>Correo electrónico</li>
            <li>Descuento</li>
            <li>Año, mes y día de nacimiento</li>
            <li>Dirección</li>
        </ul>
        <h3>Validaciones:</h3>
        <ul>
            <li>Número de proveedor, número entre 1 y 100.</li>
            <li>Nombre, al menos tenga 10 caracteres.</li>
            <li>RFC, validar que sean 13 caracteres.</li>
            <li>Correo electrónico, validar que contenga la @ y un punto después de ella.</li>
            <li>Descuento, este entre 0 y 1.</li>
            <li>Año, que se encuentre entre 1950 y 2006.</li>
            <li>Mes, que se encuentre entre 1 y 12.</li>
            <li>Día, que corresponda a los días del mes.</li>
            <li>Dirección, que incluya calle, número, colonia, municipio y Estado.</li>
        </ul>
    </div>

    <div class="section">
        <h2>Mercado</h2>
        <p>Para cada mercado:</p>
        <ul>
            <li>Clave del mercado</li>
            <li>Nombre completo</li>
            <li>RFC</li>
            <li>Correo electrónico</li>
            <li>Descuento</li>
            <li>Año, mes y día de nacimiento</li>
            <li>Dirección</li>
        </ul>
        <h3>Validaciones:</h3>
        <ul>
            <li>Clave del mercado, mayor que cero.</li>
            <li>Nombre, al menos tenga 10 caracteres.</li>
            <li>RFC, validar que sean 13 caracteres.</li>
            <li>Correo electrónico, validar que contenga la @ y un punto después de ella.</li>
            <li>Descuento, este entre 0 y 1.</li>
            <li>Año, que se encuentre entre 1950 y 2006.</li>
            <li>Mes, que se encuentre entre 1 y 12.</li>
            <li>Día, que corresponda a los días del mes.</li>
            <li>Dirección, que incluya calle, número, colonia, municipio y Estado.</li>
        </ul>
    </div>

    <div class="section">
        <h2>Empleado</h2>
        <p>Para cada empleado:</p>
        <ul>
            <li>Número de empleado</li>
            <li>Nombre completo</li>
            <li>RFC</li>
            <li>Correo electrónico</li>
            <li>Porcentaje de comisión recibida</li>
            <li>Año, mes y día de contratación</li>
            <li>Dirección</li>
        </ul>
        <h3>Validaciones:</h3>
        <ul>
            <li>Número de empleado, valor entre 1 y 1,000.</li>
            <li>Nombre completo, al menos tenga 20 caracteres.</li>
            <li>RFC, validar que sean 13 caracteres.</li>
            <li>Correo electrónico, validar que contenga la @ y un punto con letras antes y después de él.</li>
            <li>Año, que se encuentre entre 1990 y año actual.</li>
            <li>Mes, que se encuentre entre 1 y 12.</li>
            <li>Día, que corresponda a los días del mes.</li>
            <li>Dirección, que incluya calle, número, colonia, municipio y Estado.</li>
        </ul>
    </div>

    <div class="section">
        <h2>Venta</h2>
        <p>Para cada venta que se realice a los mercados, se tendrá lo siguiente:</p>
        <ul>
            <li>Número de mercado (cliente)</li>
            <li>Número de artículo</li>
            <li>Cantidad</li>
            <li>Precio</li>
            <li>Factura</li>
        </ul>
        <h3>Validaciones:</h3>
        <ul>
            <li>Número de mercado, validar que existe en el catálogo de mercados.</li>
            <li>Número de artículo, validar que existe en el catálogo de artículos.</li>
            <li>Cantidad, validar que sea mayor a cero y que tenga el inventario suficiente para la venta.</li>
            <li>Precio, traerlo del catálogo de artículos.</li>
            <li>Número de empleado, validar que exista en el catálogo de empleados.</li>
            <li>Factura, se le preguntará al usuario si desea factura.</li>
        </ul>
    </div>

    <div class="section">
        <h2>Compra</h2>
        <p>Para cada compra que se realice a los proveedores, se tendrá lo siguiente:</p>
        <ul>
            <li>Número de proveedor</li>
            <li>Número de insumo</li>
            <li>Cantidad</li>
            <li>Precio</li>
        </ul>
        <h3>Validaciones:</h3>
        <ul>
            <li>Número de proveedor, validar que existe en el catálogo de proveedores.</li>
            <li>Número de insumo, validar que existe en el catálogo de insumos.</li>
            <li>Cantidad, validar que sea mayor a cero.</li>
            <li>Precio, traerlo del catálogo de insumos.</li>
        </ul>
    </div>

    <div class="section">
        <h2>Control de Inventario</h2>
        <p>Para el control de inventarios, se utiliza para llevar un registro de las compras de insumos que se hicieron y que ya se recibieron en nuestra granja.</p>
        <ul>
            <li>Número de proveedor, validar que exista en el catálogo.</li>
        </ul>
    </div>
</body>
</html>
