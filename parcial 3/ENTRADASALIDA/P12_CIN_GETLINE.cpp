#include <iostream>

using namespace std;

main()
{
	char buffer1[80], buffer2[80];
	
	cout << "Ingrese la primera oracion: \n";
	cin >> buffer1; 
	cout << "\nLa primera cadena leida con cin es: " << buffer1 << endl;
	
	cin.getline(buffer2, 80);
	cout << "\nLa cadena leida con cin.gentline es: " << buffer2 << endl;
}
