//Ejemplo 2: B�squeda dentro de un arreglo de caracteres.
//En este segundo ejemplo, se busca un patr�n dentro de un texto m�s largo utilizando regex_search.

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
        cout << "No se encontro ningun n�mero en el texto." << endl;
}
