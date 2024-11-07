#include <iostream>

using namespace std;

int main() {
    int x;

    cout << "Antes de hacer una operacion invalida:\n"
         << "cin.rdstate(): " << cin.rdstate()
         << "\n cin.eof(): " << cin.eof()
         << "\n cin.fail(): " << cin.fail()
         << "\n cin.bad(): " << cin.bad()
         << "\n cin.good(): " << cin.good() << "\n\n";

    cout << "Espera un entero, pero se le da un caracter: ";
    cin >> x;

    cout << "\nDespues de una operacion invalida:\n"
         << "cin.rdstate(): " << cin.rdstate()
         << "\n cin.eof(): " << cin.eof()
         << "\n cin.fail(): " << cin.fail()
         << "\n cin.bad(): " << cin.bad()
         << "\n cin.good(): " << cin.good() << "\n\n";

    cin.clear();

    cout << "Despues de cin.clear()\n"
         << "cin.fail(): " << cin.fail() << endl;

    return 0;
}
