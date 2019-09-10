#include <stdio.h>
#include <string.h>
#include "funciones.h"

void pedirNombre(char mensaje[],char nombre[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",nombre);
}

void mostrarNombre(char nombre[])
{
    printf("%s\n",nombre);
}

void copiaDeVariable(char nombre[],char aux[])
{
    strcpy(aux,nombre);
    printf("%s\n",aux);
}

void transPrimMayus(char nombre[])
{
    strupr(nombre);
    printf("%s",nombre);
}

void transTodasMin(char nombre[])
{
    strlwr(nombre-nombre[0]);
    printf("%s",nombre);
}

void mostrarNombreCorrecto(char nombre[],char aux[])
{
    copiaDeVariable(aux,nombre);
    transPrimMayus(aux);
    transTodasMin(aux);
    printf("%s",aux);
}


