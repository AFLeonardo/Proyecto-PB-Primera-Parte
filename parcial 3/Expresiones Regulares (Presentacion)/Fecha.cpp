//Ejemplo 4: Formato AAAA-MM-DD
//En este ejemplo. Se muestran las diferentes maneras en las que se puede especificar un patron AAAA-MM-DD utilizando regex.

#include <iostream>
#include <regex>

using namespace std;

main()
{
    string texto = "La fecha es 2024-10-28";

    //regex patron("\\d{4}-\\d{2}-\\d{2}");

    //regex patron(R"(\d{4}-\d{2}-\d{2})"); // Utiliza R"(...)" para evitar el doble backslash (Cadena sin procesar)

    regex patron("[0-9]{4}-[0-9]{2}-[0-9]{2}");

    if (regex_search(texto, patron))
        cout << "Se encontro una fecha en el texto." << endl;

    else
        cout << "No se encontro una fecha en el texto." << endl;
}
