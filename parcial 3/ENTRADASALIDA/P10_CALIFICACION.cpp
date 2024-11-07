#include <iostream>

using namespace std;

main()
{
	int calificacion, calificacion_alta = -1;
	
	cout << "Ingrese la calificacion (ingrese fin del archivo para terminar: ";
	while(cin >> calificacion)
	{
		if(calificacion > calificacion_alta)
			calificacion_alta = calificacion;
		cout << "Ingrese la calificacion (ingrese fin del archivo para terminar: ";	
	}
	if(calificacion_alta != -1)
		cout << "\nLa calificacion mas alta es: " << calificacion_alta << endl;
	else
		cout << "\nNo ingreso ninguna calificacion";
}
