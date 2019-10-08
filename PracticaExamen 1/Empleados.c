#include <stdio.h>
#include "Empleados.h"
#include "Inputs.h"


void inicializarEmpleados(eEmpleado listadoDeEmpleados[],int len)
 {
     int i;
     for(i=0;i<len;i++)
     {
         listadoDeEmpleados[i].legajo = 0;
         listadoDeEmpleados[i].estaVacio = LIBRE;
     }
 }

 //-----------------------------------------------------------------------------------------------------------------------

 void ingresarDatos(eEmpleado listadoDeEmpleados[],int len)
{
    int indice;

    indice = indiceLibre(listadoDeEmpleados,len);

    if(indice != -1)
    {
        listadoDeEmpleados[indice].legajo = idAuto(listadoDeEmpleados,len,100);
        while(getString(listadoDeEmpleados[indice].nombre,"Ingrese el Nombre: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
        while(getInt(&listadoDeEmpleados[indice].nota,"Ingrese la Nota: ","L a nota solo puede ser 1-10",1,10)!= 0);
        listadoDeEmpleados[indice].estaVacio = OCUPADO;
    }else{
        printf("Ya no se pueden ungresar mas alumnos\n");
    }
}

//-------------------------------------------------------------------------------------------------------------------------

int indiceLibre(eEmpleado listadoDeEmpleados[],int len)
{
    int i;
    int index = -1;

    for(i=0;i<len;i++)
    {
        if(listadoDeEmpleados[i].estaVacio == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

//-------------------------------------------------------------------------------------------------------------------------

void MostrarAlumnos(eEmpleado listadoDeEmpleados[],int len)
{
    int flag = 0;
    int i;
    printf("\nLegajo\t\tnombre\t\t\tNotas\n");
    for(i=0;i<len;i++)
    {
        if(listadoDeEmpleados[i].estaVacio == OCUPADO)
        {
            flag = 1;
            mostrarUnEmpleado(listadoDeEmpleados,i);
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos para mostrar\n");
    }
}

//-------------------------------------------------------------------------------------------------------------------------

void mostrarUnEmpleado(eEmpleado unEmpleados[],int index)
{
    if(unEmpleados[index].estaVacio == OCUPADO)
    {
        printf("\n%d",unEmpleados[index].legajo);
        printf("\t\t%-10s",unEmpleados[index].nombre);
        printf("\t\t%5d\n",unEmpleados[index].nota);
    }

}

//-------------------------------------------------------------------------------------------------------------------------

int idAuto(eEmpleado listadoDeEmpleados[],int len,int valMenor)
{
    int indexAnterior;
    int idFinal;

    indexAnterior = idMayor(listadoDeEmpleados,len,valMenor);

    idFinal = indexAnterior +1;

    return idFinal;

}

int idMayor(eEmpleado listadoDeEmpleados[],int len,int valMenor)
{
    int i;
    int mayor = valMenor-1;

    for(i=0;i<len;i++)
    {
        if(mayor<listadoDeEmpleados[i].legajo)
        {
            mayor = listadoDeEmpleados[i].legajo;
        }
    }
    return mayor;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------





