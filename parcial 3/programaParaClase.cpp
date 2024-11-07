#include<iostream>
#include<regex>

using namespace std;

int main()
{
    FILE* archivo;
    regex correoPatron ("[A-Z][a-zA-Z]{3}\\d{2}@[a-z]+\\.(com|edu|mx)");
    char correo[50], agregar;
    int opcion, correosValidos, correosTotales;
    bool continuar = true;

    while(continuar)
    {
        cout << "MENU:" << endl;
        cout << "1) Lectura de datos" << endl;
        cout << "2) Contabilizacion" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingrese una opcion:" << endl;
        do
        {
            cin >> opcion;
            if(opcion < 1 || opcion > 3)
                cout << "La opcion debe estar entre 1 y 3." << endl;
        } while (opcion < 1 || opcion > 3);
        
        switch(opcion)
        {
            case 1:
                try
                {
                    archivo = fopen("correos.txt", "a");

                    if(archivo == NULL)
                        throw "Error: No se pudo abrir el archivo.";
                    else
                    {
                        do
                        {
                            cout << "Ingrese el correo:" << endl;
                            cin >> correo;
                            fprintf(archivo, "%s\n", correo);
                            cout << "Desea ingresar mas (s/n):" << endl;
                            cin >> agregar;
                        } while (agregar == 's');
                        fclose(archivo);
                    }
                }
                catch(const char* mensaje)
                {
                    cout << mensaje << endl;
                }
                break;
            case 2:
                try
                {
                    archivo = fopen("correos.txt", "r");

                    if(archivo == NULL)
                        throw "Error: No se pudo abrir el archivo.";
                    else
                    {
                        correosTotales = 0, correosValidos = 0;
                        fscanf(archivo, "%s", correo);
                        while(!feof(archivo))
                        {
                            correosTotales++;
                            if(regex_match(correo, correoPatron))
                                correosValidos++;
                            fscanf(archivo, "%s", correo);
                        }
                        cout << "Hubo " << correosValidos << " correos validos de " << correosTotales << " correos totales." << endl;
                        fclose(archivo);
                    }
                }
                catch(const char* mensaje)
                {
                    cout << mensaje << endl;
                }
                break;
            case 3:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
                
        }
    }
    
}
