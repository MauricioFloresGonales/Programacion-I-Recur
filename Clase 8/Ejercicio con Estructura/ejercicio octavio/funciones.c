#include <stdio.h>
#include "funciones.h"


void inicializarAlumno(eAlumno listadoDeAlumnos[],int cantidad)
 {
     int i;
     for(i=0;i<cantidad;i++)
     {
         listadoDeAlumnos[i].estaVacio = 0;
     }
 }
void MostrarAlumnos(eAlumno listadoDeAlumnos[],int cantidad)
{
    int flag = 0;
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(listadoDeAlumnos[i].estaVacio == 0)
        {
            flag = 1;
            mostrarUnAlumno(listadoDeAlumnos,i);
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos pramostrar\n");
    }
}

void mostrarUnAlumno(eAlumno unAlumno[],int indice)
{
    printf("%d",unAlumno[indice].nota);
    printf("%d",unAlumno[indice].legajo);
    printf("%s",unAlumno[indice].nombre);
}
