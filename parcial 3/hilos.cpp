#include <iostream>
#include <thread>
#include<chrono>

void areaCirculo(float);

void areaTriangulo(float,float );

void areaRectangulo(float, float);

using namespace std;

int main()
{
	float alturaT, baseT, alturaR, baseR, radio;
	
	cout << "Altura del triangulo\n";
	cin >> alturaT;
	
	cout << "Base del triangulo\n";
	cin >> baseT;

	cout << "Altura del rectangulo \n";
	cin >> alturaR;
	
	cout << "Base del rectangulo\n";
	cin >> baseR;
	
	cout << "Radio del circulo\n";
	cin >> radio;
	
	thread tareaTriangulo(areaTriangulo, alturaT, baseT);
	thread tareaCirculo(areaCirculo, radio);
	thread tareaRectangulo(areaRectangulo,alturaR,baseR);
	
	tareaTriangulo.join();
	tareaCirculo.join();
	tareaRectangulo.join();
}

void areaTriangulo(float falturaT, float fbaseT)
{
	this_thread::sleep_for(chrono::milliseconds(6));
	cout << "El area del triangulo es: " << falturaT * fbaseT / 2 << endl;
}

void areaCirculo(float fradio)
{
	cout << "El area del circulo es: " << 3.1416 * fradio * fradio << endl;
}

void areaRectangulo(float falturaR,float fbaseR)
{
	cout<< "El area del rectangulo es: " << falturaR * fbaseR<<endl;
}
