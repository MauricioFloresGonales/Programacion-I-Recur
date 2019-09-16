#include <stdio.h>
#include <string.h>
#include "funciones.h"

//----------------------------------------------------------------------------------------------------------------
void harcodearDatos(eAlumno listaDeAlumnos[],int cantidad)
{
    int legajos[]={111,222,333,444,555};
    int notas[]={1,2,3,4,5};
    char nombres[][50]={"ana","juan","pepe","laura","mauricio"};
    int i;

    for(i=0;i<cantidad;i++)
    {
        listaDeAlumnos[i].legajo = legajos[i];
        listaDeAlumnos[i].nota = notas[i];
        strcpy(listaDeAlumnos[i].nombre,nombres[i]);
        listaDeAlumnos[i].estaVacio = 0 ;
    }
}

//----------------------------------------------------------------------------------------------------------------

void inicializarAlumno(eAlumno listadoDeAlumnos[],int cantidad)
 {
     int i;
     for(i=0;i<cantidad;i++)
     {
         listadoDeAlumnos[i].estaVacio = 0;
     }
 }
 //----------------------------------------------------------------------------------------------------------------

void MostrarAlumnos(eAlumno listadoDeAlumnos[],int cantidad)
{
    int flag = 0;
    int i;
    printf("\nLegajo\t\tNotas\t\tnombre\n");
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
        printf("No hay alumnos para mostrar\n");
    }
}

//----------------------------------------------------------------------------------------------------------------

void mostrarUnAlumno(eAlumno unAlumno[],int indice)
{
    printf("\n%d",unAlumno[indice].legajo);
    printf("\t\t%d",unAlumno[indice].nota);
    printf("\t\t%s\n",unAlumno[indice].nombre);
}

//----------------------------------------------------------------------------------------------------------------

int dameIndiceLibre(eAlumno alumno[],int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(alumno[i].estaVacio == 0)
        {
            return i;
        }
    }
    return -1;
}

//----------------------------------------------------------------------------------------------------------------


