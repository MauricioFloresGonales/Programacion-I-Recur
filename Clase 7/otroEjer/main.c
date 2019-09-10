#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3
#define LEN 20

/*AGREGAR EL NOMBRE DE CADA ALUMNO
MOSTRAR NOMBRE DEL MAXIMO ALUMNO
CREAR FUNCION QUE ORDENE TODOS LOS ALUMNOS QUE ESTEN SENTADOS POR NOMBRE
*/
int main()
{
    int legajo[T];
    char nombre[T][LEN];
    int i;
    int j;
    int auxInt;
    char auxString[LEN];

    for(i=0;i<T;i++)
    {
        printf("ingrese legajo: ");
        scanf("%d", &legajo[i]);

        printf("ingrese nombre: ");
        fflush(stdin);
        gets(nombre[i]);
    }

    for(i=0;i<T;i++)
    {
        printf("%d\t%s\n",legajo[i],nombre[i]);
    }


    for(i=0;i<T-1;i++)
    {
        for(j=i+1;j<T;j++)
        {
            if(legajo[i]>legajo[j])
            {
                auxInt = legajo[i];
                legajo[i]= legajo[j];
                legajo[j]=auxInt;

                strcpy(auxString,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxString);
            }
        }



    }
    return 0;
}
