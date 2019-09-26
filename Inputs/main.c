#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
}

/*
char* puntero;
   char charAux;

    charAux = 'a';
   *puntero = charAux;

   printf("%c",*puntero);*/
