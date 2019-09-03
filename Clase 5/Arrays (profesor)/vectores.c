#include <stdio.h>
#include "vectores.h"


void cargarVector(int vector[],int tam)
    {
        int i;
        printf("\tCARGA DE DATOS\n");
        for(i=0; i<tam; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", &vector[i]);
        }
    }

    void mostrarMaximo(int vector[],int tam)
    {
        int maximo;
        int i;
        maximo=calcularMaximo(vector,tam);

        printf("EL MAXIMO: %d\n", maximo);

            for(i=0; i<tam; i++)
            {
                if(vector[i]==maximo)
                {
                printf(" - %d\n",i);
                }
            }
    }

    int calcularMaximo(int vector[],int tam)
    {
        int flag=0;
        int i;
        int maximo;
        for(i=0; i<tam; i++)
            {
                if(flag==0 ||vector[i]>maximo)
                {
                    maximo=vector[i];
                }
                flag = 1;
            }
        return maximo;
    }
