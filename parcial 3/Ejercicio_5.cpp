#include<iostream>
#include<regex>

using namespace std;

main()
{
	string cadena;
	
	cout << "Ingrese una cadena: ";
	cin >> cadena;
	
	regex arroba(R"(\d{4}[a-zA-Z]{4}@[a-zA-Z]+.(com|mx))");
	
	if (regex_match(cadena, arroba))
		cout << "El correo es valido";
	else
		cout << "El correo es invalido";
}
