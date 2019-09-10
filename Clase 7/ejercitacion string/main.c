#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"




int main()
{
    char auxString[1000];
    char nombre[15];


    printf("ingrese nombre:");
    fflush(stdin);
    gets(auxString);
    while(strlen(auxString)>14)
    {
        printf("reingrese su nombre: ");
        fflush(stdin);
        gets(auxString);
    }
    strcpy(nombre,auxString);



    /*
    CHAR NOMBRE[15];
    CHAR APELLIDO[15];
    CHAR APELLIDOnOMBRE[50]; ------------> Apellido,Nombre
       */

    char nombre[15];
    char apellido[15];
    char apellidoNombre[100];
    char nombreAux[50];
    char apellidoAux[50];

     pedirNombre("ingresar su nombre: ",nombre);
     pedirNombre("ingresar su apellido: ",apellido);
     //mostrarNombre(nombre);
     //mostrarNombre(apellido);

    //mostrarNombreCorrecto(nombre,nombreAux);
    copiaDeVariable(nombre,nombreAux);
    transPrimMayus(nombreAux);


    return 0;
}
