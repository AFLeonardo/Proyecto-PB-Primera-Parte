#include <iostream>

using namespace std;

main()
{
	char buffer[80];
	
	cout << "Ingrese la oracion: \n";
	
	cin.read(buffer, 20);
	
	cout << "\nLa cadena ingresada es : \n";
	cout.write(buffer, cin.gcount());
	cout << endl;
}
