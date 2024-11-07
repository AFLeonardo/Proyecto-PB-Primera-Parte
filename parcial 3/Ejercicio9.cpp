#include <iostream>
#include <regex>
#include <stdexcept> 

using namespace std;


void guardarCorreo();
bool validarCorreo(char *);
void verificarCorreos(); 



int main() 
{
    int opcion;

    do
    {
        cout << "\nMenu:\n";
        cout << "1) Lectura de datos: Guardar correo en archivo\n";
        cout << "2) Realizar contabilizacion: Contar correos validos\n";
        cout << "3) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    }while(opcion < 1 || opcion > 3);


    while(opcion != 3) 
    {
        switch (opcion) 
        {
            case 1:
                guardarCorreo();
                break;
            case 2:
                verificarCorreos();
                break;
        }

        do
        {
            cout << "\nMenu:\n";
            cout << "1) Lectura de datos: Guardar correo en archivo\n";
            cout << "2) Realizar contabilizacion: Contar correos válidos\n";
            cout << "3) Salir\n";
            cout << "Seleccione una opción: ";
            cin >> opcion;
        }while(opcion < 1 || opcion > 3);
    }

    cout << "Saliendo del programa... ";
    return 0;
}



void guardarCorreo() 
{
    char correo[50];
    FILE *archivo; 


    try 
    {
        archivo = fopen("correos.dat", "a");
        if (archivo == NULL) 
            throw runtime_error("Error al abrir el archivo.");

        cout << "Ingrese correo electronico: ";
        fflush(stdin);
        cin >> correo;
        fprintf(archivo, "%s\n", correo);
        fclose(archivo);
        cout << "Correo guardado correctamente." << endl;
    }
    catch (const runtime_error& e)
    { 
        cout << e.what() << endl;
    }
}



bool validarCorreo(char *correo) 
{
    regex patron("^[A-Z][a-zA-Z]{3}[0-9]{2}@[a-zA-Z]{6}\\.(com|mx|edu)$");
    return regex_match(correo, patron);
}


void verificarCorreos() 
{
    char correo[50];
    int indice = 1;
    bool hayErrores = false;
    FILE *archivo;


    try 
    {
        archivo = fopen("correos.dat", "r");
        if (archivo == NULL) 
            throw runtime_error("Error al abrir el archivo.");
    
        while(fscanf(archivo, "%[^\n]%*c", correo) == 1)
        {
            cout << "Correo " << indice << ":\n";
            
            if (!validarCorreo(correo)) 
            {
                cout << "  Correo electronico invalido\n";
                hayErrores = true;
            } 
            else 
                cout << "  Correo valido\n";
            indice++;
        }
    
        fclose(archivo);

        if (!hayErrores)
            cout << "Todos los correos son validos." << endl;
    } 
    catch (const runtime_error& e) 
    {
        cout << e.what() << endl;
    }
}
