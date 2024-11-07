#include <iostream>
#include <regex>

using namespace std;

struct estudiante
{
    int matricula;
    char telefono[18],nombre[20],correo[60],fechaNacimiento[30];
};

main()
{
    char opcion;
    bool salir=false;
    struct estudiante datos={0,"","","",""};

    regex pNombre("^[A-Za-z ]+$");
    regex pCorreo("^[A-Za-z]+\\d{2}@[a-z]+\\.(com|mx|edu)$");
    regex pTelefono("^\\(52\\) \\d{2} \\d{4} \\d{4}$");
    regex pFecha("^\\d{2}/(0[1-9]|1[0-2])/\\d{4}$");

    FILE *fPtr;

    cout << "Desea ingresar datos: (s/n)\n";
    fflush(stdin);
    cin >> opcion;
    salir= (opcion=='n');

    while(!salir)
    {
        if((fPtr = fopen("estudiante.dat","a+")) == NULL)
            cout << "No se pudo abrir el archivo" << endl;
        else
        {
            while(!salir)
            {
                do
                {
                    cout << "Ingresa la matricula (100-500)" << endl;
                    cin >> datos.matricula;
                    cin.ignore();

                    if(datos.matricula < 100 || datos.matricula > 500)
                        cout << "La matricula debe estar entre 100 y 500" << endl;
                }
                while(datos.matricula < 100 || datos.matricula > 500);

                cout << "Ingresa el nombre" << endl;
                cin.getline (datos.nombre,20);
                cout << "Ingresa el correo" << endl;
                cin.getline(datos.correo, 60);
                cout << "Ingresa el telefono [(52) 99 9999 9999]" << endl;
                cin.getline(datos.telefono, 18);
                cout << "Ingresa la fecha de nacimiento (DD/MM/AAAA)" << endl;
                cin.getline(datos.fechaNacimiento, 30);

                fseek(fPtr,(datos.matricula-100)*sizeof(struct estudiante),SEEK_SET);
                fwrite(&datos, sizeof(struct estudiante), 1, fPtr);

                cout << "Desea ingresar mas datos: (s/n)\n";
                fflush(stdin);
                cin >> opcion;
                salir= (opcion=='n');
            }

        }
        fclose(fPtr);
    }

    if ((fPtr = fopen("estudiante.dat", "r+")) == NULL)
        cout << "No se pudo abrir el archivo para lectura" << endl;
    else
    {
        cout << "\nVerificando registros en el archivo\n";
        while (fread(&datos, sizeof(struct estudiante), 1, fPtr))
            {
				if (datos.matricula!=0)
				{
					if (!regex_match(datos.nombre, pNombre))
	                cout << "La matricula " << datos.matricula << " contiene caracteres no permitidos en el nombre: " << datos.nombre << endl;
		            if (!regex_match(datos.correo, pCorreo))
		                cout << "La matricula " << datos.matricula << " contiene caracteres no permitidos en el correo: " << datos.correo <<endl;
		            if (!regex_match(datos.telefono, pTelefono))
		                cout << "La matricula " << datos.matricula << " contiene caracteres no permitidos en el telefono: " << datos.telefono <<endl;
		            if (!regex_match(datos.fechaNacimiento, pFecha))
		                cout << "La matricula " << datos.matricula << " contiene caracteres no permitidos en la fecha de nacimiento: " << datos.fechaNacimiento <<endl;
				}
            
            }
        fclose(fPtr);
    }
}
