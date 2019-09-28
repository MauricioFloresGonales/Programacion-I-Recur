#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include <ctype.h>


int getInt(int* valor, char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int opcion;
    int retorno;
    char numeroAux[hiLimit+1];
    int validador;

    do{
        printf("%s", message);
        fflush(stdin);
        scanf("%s", numeroAux);
        opcion = confirmar();

    }while(opcion != 0);

    validador = validarNumero(numeroAux);

    *valor=atoi(numeroAux);

    if(validador==0)
    {
        if(*valor<lowLimit || *valor>hiLimit)
        {
            printf("%s", eMessage);
            retorno = -1;

        }else{
              retorno = 0;
        }
    }else{
        printf("%s", eMessage);
        retorno = -1;
    }



    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int getFloat(float* valor,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int opcion;
    int retorno;
    char numeroAux[(int)hiLimit+1];
    int validador;

    do{
        printf("%s", message);
        fflush(stdin);
        scanf("%s", numeroAux);
        opcion = confirmar();

    }while(opcion != 0);

    validador = validarNumero(numeroAux);

    *valor=atof(numeroAux);

    if(validador==0)
    {
        if(*valor<lowLimit || *valor>hiLimit)
        {
            printf("%s", eMessage);
            retorno = -1;

        }else{
              retorno = 0;
        }
    }else{
        printf("%s", eMessage);
        retorno = -1;
    }
    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int validarNumero(char* numeroChar)
{
    int digitoAux;
    int retorno;

    digitoAux = isdigit(*numeroChar);

    if(digitoAux == 1)
    {
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;

}

//------------------------------------------------------------------------------------------------------------------------------------------

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
 {
    int retorno;
    int opcion;
    char charAux;

    do{
        printf("%s",message);
        fflush(stdin);
        scanf("%c",&charAux);
        opcion = confirmar();
    }while(opcion !=0);

    charAux = tolower(charAux);
    lowLimit = tolower(lowLimit);
    hiLimit = tolower(hiLimit);

    if(charAux < lowLimit  || charAux> hiLimit)
    {
        printf("%s",eMessage);
        retorno = -1;
    }else{
        *input = charAux;
        retorno = 0;
    }//if

    return retorno;
 }

//------------------------------------------------------------------------------------------------------------------------------------------

int getOneChar(char* input,char message[],char eMessage[],char oneLimit, char twoLimit)
{
    int opcion;
    int retorno = -1;

    do{
        printf("%s",message);
        fflush(stdin);
        scanf("%s",input);
        opcion = confirmar();

    }while(opcion != 0);

    if(*input == oneLimit || *input == twoLimit)
    {
        retorno = 0;

    }else{
        printf("%s",eMessage);
        retorno= -1;
    }//if

    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int confirmar()
{
    int retorno;
    char letra;

    do{
        printf("Continuar: 'S' -- Cancelar: 'N'\n\n");
        fflush(stdin);
        //scanf("%c",&letra);
        letra = getch();
        //letra = getch();//------ En windows la funcion se escribe: int getch(void);
        //letra = getchar();//------ En Linux int getchar(void);
        letra = tolower(letra);


        if(letra == 's')
        {
            retorno = 0;
        }else if(letra == 'n')
            {
                retorno = 1;

            }else{

                retorno = -1;

                }
    }while(retorno == -1);

    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int getString(char* input,char message[],char eMessage[],char eNumMessage[], int lowLimit, int hiLimit)
{
    int retorno = 0;
    int opcion;
    char arrAux[hiLimit+1];
    int largo;

    do{
        printf("%s",message);
        fflush(stdin);
        scanf("%s",arrAux);
        opcion = confirmar();

    }while(opcion != 0);

    largo = strlen(arrAux);

    if((validarLetrasEnString(arrAux,hiLimit+1)) == -1)
    {
        printf("%s",eNumMessage);
        retorno = -1;

    }else if(largo < lowLimit || largo > hiLimit)
        {
            printf("%s",eMessage);
            retorno = -1;

        }else{
            strcpy(input,arrAux);
            retorno = 0;
        }


    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

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

int getStringWithNums(char* input,char message[],char eMessage[],int lowLimit, int hiLimit)
{
    int retorno = 0;
    int opcion;
    char arrAux[hiLimit+1];
    int largo;

    do{
        printf("%s",message);
        fflush(stdin);
        scanf("%s",arrAux);
        opcion = confirmar();

    }while(opcion != 0);

    largo = strlen(arrAux);

    if(largo < lowLimit || largo > hiLimit)
    {
        printf("%s",eMessage);
        retorno = -1;

    }else{
        strcpy(input,arrAux);
        retorno = 0;
    }


    return retorno;
}






