#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int x = 12345;

   cout << "Por defecto (justificado a la derecha):\n";
   cout << setw(10) << x << "\n\n";

    cout << "Usando setf para justificar a la izquierda:\n";
    cout.setf(ios::left, ios::adjustfield);
    cout <<setw(10) << x << "\n";
    cout.unsetf(ios::left);
    cout << "Restaurado al defecto (justificado a la derecha):\n";
    cout << setw(10) << x << "\n\n";
    cout << "Usando setiosflags para justificar a la izquierda:\n";
    cout << setw(10) << setiosflags(ios::left) << x << "\n";
    cout << resetiosflags(ios::left);
    cout << "Restaurado al defecto (justificado a la derecha):\n";
    cout <<setw(10) << x << "\n";

    return 0;
}
