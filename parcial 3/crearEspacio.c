#include <stdio.h>

struct estudiante
{
    int matricula;
    char telefono[18],nombre[20],correo[60],fechaNacimiento[30];
};

main ()
{
    int i;
    struct estudiante datos={0,"","","",""};

    FILE *f;

    if((f=fopen("estudiante.dat","w"))==NULL)
        printf("No se pudo abrir el archivo\n");
    else
    {
        for(i=1; i<=100; i++)
            fwrite(&datos,sizeof(struct estudiante),1,f);
    }
}
