#include<iostream>
#include<thread>
#include<chrono>

float areaCirculo(float&);
float areaTriangulo(float&, float&);
float areaRectangulo(float&, float&);

using namespace std;

main()
{
    float alturaT, baseT, baseR, alturaR, radio;
    float areaT, areaR, areaC;  
    
    cout << "Altura del triangulo: ";
    cin >> alturaT;
    
    cout << "Base del triangulo: ";
    cin >> baseT;
    
    cout << "Altura del rectangulo: ";
    cin >> alturaR;
    
    cout << "Base del rectangulo: ";
    cin >> baseR;
    
    cout << "Radio del circulo: ";
    cin >> radio;
    

    thread tareaTriangulo([&] { areaT = areaTriangulo(alturaT, baseT); });
    thread tareaCirculo([&] { areaC = areaCirculo(radio); });
    thread tareaRectangulo([&] { areaR = areaRectangulo(alturaR, baseR); });
    
  
    tareaTriangulo.join();
    tareaCirculo.join();
    tareaRectangulo.join();
    
    cout << "\nEl area del triangulo es: " << areaT << endl;
    cout << "\nEl area del circulo es: " << areaC << endl;
    cout << "\nEl area del rectangulo es: " << areaR << endl;
}

float areaTriangulo(float &alturaT, float &baseT)
{
    return alturaT * baseT / 2;
}

float areaCirculo(float &radio)
{
    return 3.1416 * radio * radio;
}

float areaRectangulo(float &alturaR, float &baseR)
{
    return alturaR * baseR;
}
