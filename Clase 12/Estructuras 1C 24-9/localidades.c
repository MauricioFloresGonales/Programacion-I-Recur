#include "localidades.h"

void mostrarAlumnoConLocalidad(eAlumno listadoDeAlumnos[],int ta,eLocalidad listaLocalidades[],int tl)
{
    int i;
    int j;

    for(i=0;i<ta;i++)
    {
        if(listadoDeAlumnos[i].estado == OCUPADO)
        {
            printf("%d %s %f ",listadoDeAlumnos[i].legajo,listadoDeAlumnos[i].nombre,listadoDeAlumnos[i].promedio);

            for(j=0;j<tl;j++)
            {
                if(listadoDeAlumnos[i].idLocalidad == listaLocalidades[j].idLocalidad)
                {
                    printf("%s\n",listaLocalidades[j].localidad);
                }
            }
        }
    }
}
