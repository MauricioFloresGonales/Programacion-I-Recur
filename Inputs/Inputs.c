#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include <ctype.h>


int getInt(int* valor, char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno = -1;
    int validador = -1;

    printf("%s", message);
    scanf("%d", valor);

    while(validador == -1)
    {
        if(*valor<lowLimit || *valor>hiLimit)
        {
            printf("Error, %s", eMessage);

        }else{
            validador = 0;
            retorno = 0;
        }
    }

    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int getFloat(float* valor,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int retorno = -1;
    int validador = -1;

    printf("%s", message);
    scanf("%f", valor);

    while(validador == -1)
    {
        if(*valor<lowLimit || *valor>hiLimit)
        {
            printf("Error, %s ", eMessage);

        }else{
            validador = 0;
            retorno = 0;
        }
    }
    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------
/*
 int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
 {
     int retorno = -1;

     printf("%s".message);
     fflush(stdin);
     scanf("%c",input);


    return 0
 }*/

//------------------------------------------------------------------------------------------------------------------------------------------

int getString(char* input,char message[],char eMessage[],char eNumMessage[], int lowLimit, int hiLimit)
{
    int retorno = 0;
    int validar = 1;
    char arrAux[hiLimit+1];
    int largo;

    while(validar == 1)
    {
        printf("%s",message);
        fflush(stdin);
        scanf("%s",arrAux);
        largo = strlen(arrAux);

        if((validarLetras(arrAux,hiLimit+1)) == -1)
        {
            printf("%s",eNumMessage);

        }else if(largo < lowLimit || largo > hiLimit)
            {
                printf("%s",eMessage);

            }else{
                strcpy(input,arrAux);
                validar = 0;
                retorno = 0;
            }
    }

    return retorno;
}

int validarLetras(char palabra[],int tam)
{
    int i;
    int validador;
    int retorno = 0;

    for(i=0;i<tam;i++)
    {
        validador = isdigit(palabra[i]);

        if(validador == 1)
        {
            retorno = -1;
        }
    }
    return retorno;
}









