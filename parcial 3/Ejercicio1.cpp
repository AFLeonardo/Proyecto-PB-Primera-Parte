#include<iostream>
using std:: cout;
using std:: cin;
using std:: endl;

main()
{
	float numero1, numero2,resultado;
	int opcion;
	bool valido;
	do
	{
		cout<<"---------------------- \n";
		cout<<"1. Sumar \n";
		cout<<"2. Restar \n";
		cout<<"3. Multiplicar \n";
		cout<<"4. Division \n";
		cout<<"5. Salir \n";
		cout<<"---------------------- \n";
		cin>> opcion;
	}
	while(opcion < 1 || opcion > 5);
	while(opcion !=5)
	{
		valido=true
		cout<<"Introduzca el 1er numero: \n";
		cin>> numero1;
		cout<<"Introduzca el 2do numero: \n";
		cin>> numero2;
		switch(opcion)
		{
			case 1:
				resultado = numero1 + numero2;
				break;
				
			case 2:
				resultado = numero1 - numero2;
				break;
				
			case 3:
			     resultado = numero1 * numero2;
				 break;
			
			case 4:
				if(numero2==0)
				{
					cout<<"No se puede dividir entre 0"<<"\n";
					valido=false;
				}else
					resultado = numero1 / numero2;
			
				break;
			}
		if(valido)
		{
			cout<<"La operacion de "<<numero1<<"y "<<numero2<<" es: "<<resultado<<"\n";	
		}
		
			
		do
		{
			cout<<"---------------------- \n";
			cout<<"1. Sumar \n";
			cout<<"2. Restar \n";
			cout<<"3. Multiplicar \n";
			cout<<"4. Division \n";
			cout<<"5. Salir \n";
			cout<<"---------------------- \n";
			cin>> opcion;
		}
		while(opcion < 1 || opcion > 5);
	}
}
