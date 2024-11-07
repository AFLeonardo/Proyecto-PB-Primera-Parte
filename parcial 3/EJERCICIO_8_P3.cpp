#include <iostream>
#include <stdexcept> 

float divisionerror(float , float);

using namespace std;

main() 
{
    float numero_1, numero_2,resultado;

    cout << "Indique el numero 1: ";
    cin >> numero_1;
    cout << "Indique el numero 2: ";
    cin >> numero_2;

    try 
	{
        resultado = divisionerror(numero_1, numero_2);
        cout << "Resultado: " << resultado << endl;
    }
    catch (const runtime_error &error) 
	{
        cout << error.what() << endl;
    }
}

float divisionerror(float fnumero_1 , float fnumero_2)
{
    if (fnumero_2 == 0) 
	{
        throw runtime_error("No se puede dividir entre cero \n");
    }
    return fnumero_1 / fnumero_2;
}

