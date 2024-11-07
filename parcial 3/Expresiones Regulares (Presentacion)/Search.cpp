//Ejemplo 2: Búsqueda dentro de un arreglo de caracteres.
//En este segundo ejemplo, se busca un patrón dentro de un texto más largo utilizando regex_search.

#include <iostream>
#include <regex>

using namespace std;

main()
{
    char texto[28] = "Texto con un numero: aaaaa.";

    regex patron("\\d+");

    if (regex_search(texto, patron))
        cout << "Se encontro un numero en el texto." << endl;
    else
        cout << "No se encontro ningun número en el texto." << endl;
}
