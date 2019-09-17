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
        listaDeAlumnos[i].estaVacio = OCUPADO;
    }
}

//----------------------------------------------------------------------------------------------------------------
void ingresarDatos(eAlumno listaDeAlumnos[],int indice)
{
    indice = dameIndiceLibre(listaDeAlumnos,indice);

    if(indice != -1)
    {
        printf("ingrese el Legajo: ");
        scanf("%d",&listaDeAlumnos[indice].legajo);
        printf("ingrese el Nombre: ");
        fflush(stdin);
        scanf("%[^\n]",listaDeAlumnos[indice].nombre);
        printf("ingresar la Nota: ");
        scanf("%d",&listaDeAlumnos[indice].nota);
        listaDeAlumnos[indice].estaVacio = OCUPADO;
    }else{
        printf("Ya no se pueden ungresar mas alumnos\n");
    }
}

//----------------------------------------------------------------------------------------------------------------

void inicializarAlumno(eAlumno listadoDeAlumnos[],int cantidad)
 {
     int i;
     for(i=0;i<cantidad;i++)
     {
         listadoDeAlumnos[i].estaVacio = LIBRE;
     }
 }
 //----------------------------------------------------------------------------------------------------------------

void MostrarAlumnos(eAlumno listadoDeAlumnos[],int cantidad)
{
    int flag = 0;
    int i;
    printf("\nLegajo\t\tnombre\t\t\tNotas\n");
    for(i=0;i<cantidad;i++)
    {
        if(listadoDeAlumnos[i].estaVacio == OCUPADO)
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
    if(unAlumno[indice].estaVacio == OCUPADO)
    {
        printf("\n%d",unAlumno[indice].legajo);
        printf("\t\t%-10s",unAlumno[indice].nombre);
        printf("\t\t%5d\n",unAlumno[indice].nota);
    }

}

//----------------------------------------------------------------------------------------------------------------

int dameIndiceLibre(eAlumno alumno[],int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(alumno[i].estaVacio == LIBRE)
        {
            return i;
        }
    }
    return -1;
}

//----------------------------------------------------------------------------------------------------------------

void buscarLegajo(eAlumno[],int cantidad);
