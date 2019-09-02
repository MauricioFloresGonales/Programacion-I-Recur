#include <stdio.h>
#include <stdlib.h>
#include "INPUTS.h"



int main()
{
    /*int numero;
    int edad;
    legajo
    nombre

    nota
    peso


    edad = getInt("ingrese su esdad: ",10,50);
    printf("Ud ingreso: %d anos",edad);
    numero = getInt("ingrese un numero: ",1,10);
    printf("Ud ingreso el numero: %d ",numero);*/

    /*int numero = 7;
    int edad;

    printf("%d\n",edad);
    funcion(&edad);
    printf("%d\n",edad);*/

    getInt(&edad,"ingrese su esdad: ",10,50);
    printf("Ud ingreso: %d anos",edad);
    getInt("ingrese un numero: ",1,10);
    printf("Ud ingreso el numero: %d ",numero);

    return 0;
}



