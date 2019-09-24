#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include <ctype.h>

int main()
{
    char continuar;
    int r; // Respuesta
    r = getChar(&continuar,"Ingrese Opcion [A][B][C]: ","Solo [A][B][C]:",'A','C');
    if(r == 0)
    {
        printf("Continuar: %c",continuar);
    }
/*
    char letra = 'A';
    int ascii;

    ascii = letra;

    printf("la letra %c es en ascii es %d",letra,ascii);*/
}
