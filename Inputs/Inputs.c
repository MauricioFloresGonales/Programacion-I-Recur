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


    while(validador == -1)
    {
        scanf("%d", valor);

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


    while(validador == -1)
    {
        scanf("%f", valor);

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

 int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
 {
     char charAux[5];
     char lowLimitAux[5] = lowLimit;
     char hiLimitAux[5] = hiLimit;
     int letraAux;
     int lowAux;
     int hiAux;
     int retorno = -1;

    printf("%s",message);

    while(retorno != 0)
    {
        fflush(stdin);
        scanf("%s",charAux);

        letraAux = validarUnaLetra(charAux);
        lowAux = validarUnaLetra(lowLimitAux);
        hiAux = validarUnaLetra(hiLimitAux);

        if(letraAux == 0 && lowAux == 0 && hiAux == 0)
        {
            printf("entro al primer if\n");
            if(charAux[0] < lowLimit  || charAux[0] > hiLimit)/**Algo Anda Mal **/
            {
                printf("entro al segundo if\n");
                printf("%s",eMessage);
            }else{
                *input = charAux[0];
                retorno = 0;
            }//if
        }else{
            printf("%s",eMessage);
        }
    }//while

    return retorno;
 }
//------------------------------------------------------------------------------------------------------------------------------------------

int getOneChar(char* input,char message[],char eMessage[],char oneLimit, char twoLimit)
{
    int validador;
    int retorno = -1;
    char charAux[10];

    printf("%s",message);

    while(retorno == -1)
    {

        fflush(stdin);
        scanf("%s",charAux);

        validador = validarUnaLetra(charAux);

        if(validador == 0)
        {
            if(charAux[0] == oneLimit || charAux[0] == twoLimit)
            {
                retorno = 0;

            }else{
                    printf("%s",eMessage);
                 }
        }else{

            printf("%s",eMessage);
            fflush(stdin);

        }//if
    }//while

    *input = charAux[0];

    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int validarUnaLetra(char* input)
{
    char letraAux;
    int lenAux;
    int alphaAux;
    int retorno;

    letraAux = *input;

    lenAux = strlen(input);
    alphaAux = isalpha(letraAux);

    if(lenAux == 1 && alphaAux != 0)
    {
        retorno = 0;
    }else{
        retorno = -1;

    }

    return retorno;

}

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

        if((validarLetrasEnString(arrAux,hiLimit+1)) == -1)
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

int validarLetrasEnString(char palabra[],int tam)
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

//------------------------------------------------------------------------------------------------------------------------------------------









