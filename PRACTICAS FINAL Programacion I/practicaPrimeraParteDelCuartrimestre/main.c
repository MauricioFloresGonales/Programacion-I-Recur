#include <stdio.h>
#include <stdlib.h>
#include "string.h"

float sacarPorsentaje(int numero,int porcentaje);
void vocalRepetida(char palabra[]);

int main()
{
    float resultado;
    int numero=200;
    int porcentaje=55;

    char palabra[21]="mimamamemimamucho";

    resultado=sacarPorsentaje(numero,porcentaje);

    printf("el resultado es %f \n\n",resultado);

    vocalRepetida(palabra);
    return 0;
}


float sacarPorsentaje(int numero,int porcentaje)
{
    float resultado;
    int multiplicacion;

    multiplicacion = numero*porcentaje;
    resultado= (float)multiplicacion/100;
    return resultado;
}

void vocalRepetida(char palabra[])
{
    int i;
    int j;
    int len=strlen(palabra);
    char vocales[]={'a','e','i','o','u'};
    int numeroVocales[5]={0,0,0,0,0};
    palabra=strlwr(palabra);

    for(i=0;i<len;i++)
    {
        for(j=0;j<5;j++)
        {
            if(palabra[i]==vocales[j])
            {
                numeroVocales[j]=numeroVocales[j]+1;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%c-%d\n",vocales[i],numeroVocales[i]);
    }

}

