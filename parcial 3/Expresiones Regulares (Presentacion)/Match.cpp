//Ejemplo 1: Coincidencia exacta con regex y arreglo de caracteres.
//Este ejemplo verifica si un arreglo de caracteres coincide exactamente con un patrón de regex específico.

#include <iostream>
#include <regex>

using namespace std;

main()
{
    char texto[11] = "hola_mund0";

    regex patron("^hola_mundo$");

    if (regex_match(texto, patron))
        cout << "El texto coincide con el patron." << endl;

    else
        cout << "El texto no coincide con el patron." << endl;
}
