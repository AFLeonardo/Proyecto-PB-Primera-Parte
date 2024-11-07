#include <optional>
#include <iostream>

using namespace std;

optional<int> division(int a, int b)
{
    if (b == 0)
        return nullopt;
    return a / b;
}

main()
{
    int a = 10, b = 0;

    auto resultado = division(a, b);

    if (resultado)
        cout << "Resultado: " << *resultado << endl;
    else
        cout << "Division por cero" << endl;
}
