#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include <ctype.h>

int main()
{
    int resultado;
    char* letra;

    resultado = getOneChar(&letra,"ingrese S o N: ","solo puede ingresar 'S' o 'N'\n",'s','n');

    if(resultado == 0)
    {
        printf("la letra es %c",letra);
    }



/*
    char continuar;
    int r; // Respuesta
    r = getChar(&continuar,"Ingrese Opcion [A][B][C]: ","Solo [A][B][C]:",'A','C');
    if(r == 0)
    {
        printf("Continuar: %c",continuar);
    }*/
}
