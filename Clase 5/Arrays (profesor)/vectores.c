#include <stdio.h>
#include "vectores.h"
// COMPLETAR

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


    void ordenarVector(int vector[],int tam)
    {
        int i;
        int j;
        int aux;

        for(i=0;i<tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(vector[i]>vector[j])
                {
                    aux = vector[i];
                    vector[i] = vector[j];
                    vector[j] = aux;
                }
            }
        }
        for(;;)
        {
            printf("%d"aux);
        }
    }
