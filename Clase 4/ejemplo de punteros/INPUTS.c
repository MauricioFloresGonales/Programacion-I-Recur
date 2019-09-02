#include <stdio.h>
#include "INPUTS.h"
/*
void funcion(int* x)
{
    printf("ingrese un numero: ");
    scanf("%d",x);
}*/

/*int getInt(char mensaje[],int min, int max )
{
    int numero;

    printf("%s",mensaje);
    scanf("%d",&numero);
    while(numero<min || numero>max)
    {
        printf("error,%s",mensaje);
        scanf("%d",&numero);

    }

    return numero;
}*/
int getInt(int* valor,char mensaje[],int min, int max )
{
    int retorno = 0;

    printf("%s",mensaje);
    scanf("%d",&numero);
    while(numero<min || numero>max)
    {
        printf("error,%s",mensaje);
        scanf("%d",&numero);

    }

    return numero;
}
