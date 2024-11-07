#include <iostream>

using namespace std;

main()
{
	char buffer[80];
	
	cout << "Ingrese la oracion: \n";
	
	cin.getline(buffer, 80);
	
	cout << "\nLa cadena leida con cin.gentline es: " << buffer << endl;
}
