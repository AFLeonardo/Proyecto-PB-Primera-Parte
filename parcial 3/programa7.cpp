#include <iostream>

void division(float, float);

using namespace std;

main()
{
    float num1, num2;

    cout << "Ingrese el numero 1: " << endl;
    cin >> num1;

    cout << "Ingrese el numero 2: " << endl;
    cin >> num2;

    try
    {
        division(num1, num2);

    }
    catch(const char * mensaje)
    {
        cout << mensaje << endl;
    }


}

void division(float fnum1, float fnum2)
{
    float total;

    if(fnum2 == 0)
        throw "Error al dividir entre 0";

    total = fnum1 / fnum2;

    cout << "El resultado es: " << total << endl;
}

