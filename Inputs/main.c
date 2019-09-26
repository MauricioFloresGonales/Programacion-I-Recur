#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include <ctype.h>

int main()
{
    int resultado;
    char* letra;

    resultado = getOneChar(&letra,"ingrese S o N: ","solo puede ingresar 'S' o 'N':",'s','n');

    if(resultado == 0)
    {
        printf("la letra es %c",letra);
    }


/*
    int resultado;
    int alphaAux;
    //int len;
    //char letras[]= {"a"};
   char letra = 'a';

    resultado = validarUnaLetra(letra);
    //len = strlen(letra);
    alphaAux = isalpha(letra);

     //printf("el len es: %d\n",len);
     printf("el alphaAux es: %d\n",alphaAux);

    printf("el valor de la letra es: %d\n",resultado);

*/







/*

    char continuar;
    int r; // Respuesta
    r = getChar(&continuar,"Ingrese Opcion [A][B][C]: ","Solo [A][B][C]:",'A','C');
    if(r == 0)
    {
        printf("Continuar: %c",continuar);
    }*/
}
