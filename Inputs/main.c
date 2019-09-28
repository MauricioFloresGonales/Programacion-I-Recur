#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include <ctype.h>

int main()
{
    char nombre[51];
    int r; // Respuesta
    r = getStringWithNums(nombre,"Nombre: ","El largo debe ser entre 2 y 50", 2, 50);
    if(r == 0)
        printf("Nombre: %s\n",nombre);

}
//------------------------------------------------------------------------------------------------------------------------------------------
/*
char* puntero;
   char charAux;

    charAux = 'a';
   *puntero = charAux;

   printf("%c",*puntero);*/

//------------------------------------------------------------------------------------------------------------------------------------------

   /*
   char letra;
    int respuesta;
    printf("ingrese in aletra: ");
    scanf("%c",&letra);
    respuesta = confirmar();
    if(respuesta == 0)
    {
        printf("dijo que si\n");

    }else if(respuesta == 1)
    {
        printf("dijo que no\n");

    }else{
        printf("no puso ninguno de los dos");

    }*/

//------------------------------------------------------------------------------------------------------------------------------------------

    /*int respuesta =1;
    char* input;
    printf("1\n2\n3\n4\n5\n6\n7\n");

    while(respuesta ==1)
    {
        respuesta = getOneChar(&input,"ingrese 'A' o 'B': ","no ingreso ninguna de las dos opciones",'A','B');//---- En este ejemplo me aparece un warnig
            //int getOneChar(char* input,char message[],char eMessage[],char oneLimit, char twoLimit);        //     al querer ver el dato de input en un printf.

    }
    if(respuesta == 0)
        {
            printf("%c",input);
        }*/

//------------------------------------------------------------------------------------------------------------------------------------------
