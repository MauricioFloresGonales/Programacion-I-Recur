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
     char charAux;
     int letraAux;
     int lowAux;
     int hiAux;
     int retorno = -1;

    printf("%s",message);

    while(retorno != 0)
    {
        fflush(stdin);
        scanf("%c",&charAux);

        letraAux = isalpha(charAux);
        lowAux = isalpha(lowLimit);
        hiAux = isalpha(hiLimit);

        if(letraAux != 0 && lowAux != 0 && hiAux != 0)
        {
            if(charAux < lowLimit  || charAux > hiLimit)/**Algo Anda Mal **/
            {
                printf("%s",eMessage);
            }else{
                *input = charAux;
                retorno = 0;
            }//if
        }
    }//while

    return retorno;
 }
//------------------------------------------------------------------------------------------------------------------------------------------

int getOneChar(char* input,char message[],char eMessage[],char oneLimit, char twoLimit)
{
    int validador;
    char charAux;
    int retorno = -1;

    printf("%s",message);

    while(retorno == -1)
    {

        fflush(stdin);
        scanf("%c",&charAux);

        validador = validarUnaLetra(charAux);

        printf("el validador esta en: %d\n",validador);

        if(validador == 0)
        {
            if(charAux == oneLimit || charAux == twoLimit)
            {
                *input = charAux;
                retorno = 0;
            }else{ printf("el if te dio mal\n");}
        }else{

            printf("%s",eMessage);
            fflush(stdin);
        }//if
    }//while

    return retorno;
}
//------------------------------------------------------------------------------------------------------------------------------------------

int validarUnaLetra(char input)
{
    char letraAux[10];
    int lenAux;
    int alphaAux;
    int retorno = -1;

    letraAux[0] = input;

    lenAux = strlen(letraAux);
    alphaAux = isalpha(input);

    if(lenAux == 1 && alphaAux != 0)
    {
        retorno = 0;
    }else{ printf("algo esta mal\n");}

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









