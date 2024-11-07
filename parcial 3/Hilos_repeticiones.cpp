#include <iostream>
#include <thread>
#include <chrono>

void infocadena(char*, int, int);

using namespace std;

int main()
{
	char cadena[3][50];
	int repeticiones[3], tiempo[3], i;
	
	for(i=0; i<3; i++)
	{
		cout<<"\nIngresa la cadena: ";
		fflush(stdin);
		gets(cadena[i]);
		
		cout<<"Ingresa el numero de repeticiones: ";
		cin>>repeticiones[i];
		
		cout<<"Ingresa el tiempo a esperar para la cadena: ";
		cin>>tiempo[i];
	}
	
	thread cadena1(infocadena, cadena[0], repeticiones[0], tiempo[0]);
	thread cadena2(infocadena, cadena[1], repeticiones[1], tiempo[1]);
	thread cadena3(infocadena, cadena[2], repeticiones[2], tiempo[2]);
	
	cadena1.join();
	cadena2.join();
	cadena3.join();
}

void infocadena(char* fcadena, int frepeticiones, int ftiempo)
{
	int i;
	
	for(i=0; i<frepeticiones; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(ftiempo));
		cout<<fcadena<<endl;
	}
}
