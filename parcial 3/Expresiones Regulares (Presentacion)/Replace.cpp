//Ejemplo 3: Reemplazo de una subcadena en un arreglo de caracteres.
//En este ejemplo, reemplazamos una secuencia de caracteres que coincide con un patrón utilizando regex_replace.


#include <iostream>
#include <regex>

using namespace std;

main()
{
    string texto = "El color es azul.", resultado;

    regex patron("azul");

    resultado = regex_replace(texto, patron, "rojo");

    cout << "Texto despues del reemplazo: " << resultado << endl;
}
