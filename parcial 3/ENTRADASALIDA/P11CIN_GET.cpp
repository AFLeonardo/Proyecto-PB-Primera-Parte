#include <iostream>

using namespace std;

main()
{
	int c;
	
	cout << "Antes de la entrada, cin.eof() es " << cin.eof() << '\n' << "Ingrese una oracion o final del archivo: \n";
	
	while((c = cin.get()) != EOF)
		cout.put(c);
		
	cout << "\nDespues de la entrada, cin.eof() es " << cin.eof() << endl;
}
