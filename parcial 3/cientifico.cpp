
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double x = 0.001234567, y = 1.946e9;

    cout << "Mostrado en formato predeterminado:\n"
         << x << '\t' << y << '\n';

    cout.setf(ios::scientific, ios::floatfield);
    cout << "Mostrado en formato cientifico:\n"
         << x << '\t' << y << '\n';

    cout.unsetf(ios::scientific);
    cout << "Mostrado en formato predeterminado despues de quitar formato cientifico:\n"
         << x << '\t' << y << '\n';

    cout.setf(ios::fixed, ios::floatfield);
    cout << "Mostrado en formato fijo:\n"
         << x << '\t' << y << endl;

    return 0;
}
