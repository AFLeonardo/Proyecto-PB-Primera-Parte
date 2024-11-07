#include <iostream>

using namespace std;

main()
{
	int x, y;
	
	cout << "Ingrese los dos numeros: ";
	cin >> x >> y;
	cout << x << (x == y ? " es " : " no es ") << " es igual " << y << endl;
}
