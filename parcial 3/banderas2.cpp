#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int x = 10000;

    cout << x
         << " impreso como entero con justificacion derecha e izquierda\n"
         << "y como hexadecimal con justificacion interna.\n"
         << "Usando el caracter de relleno predeterminado (espacio):\n";

    cout.setf(ios::showbase);
    cout << setw(10) << x << '\n';

    cout.setf(ios::left, ios::adjustfield);
    cout << setw(10) << x << '\n';

    cout.setf(ios::internal, ios::adjustfield);
    cout << setw(10) << hex << x << "\n\n";

    cout << "Usando varios caracteres de relleno:\n";
    cout.setf(ios::right, ios::adjustfield);
    cout.fill('*');
    cout << setw(10) << dec << x << '\n';

    cout.setf(ios::left, ios::adjustfield);
    cout << setw(10) << setfill('%') << x << '\n';

    cout.setf(ios::internal, ios::adjustfield);
    cout << setw(10) << setfill('^') << hex << x << '\n';

    return 0;
}
