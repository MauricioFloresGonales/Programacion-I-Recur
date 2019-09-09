#include <stdio.h>
#include "funciones.h"


void harcodearLegajo(int numeros[],int tam)
{
    int arrayAux[]={55,11,22,33,44};
    int i;
    for(i=0;i<tam;i++)
    {
        numeros[i] = arrayAux[i];
    }
}

void harcodearEdades(int edad[],int tam)
{
    int arrayAux[]={18,19,81,91,98};
    int i;
    for(i=0;i<tam;i++)
    {
        edad[i] = arrayAux[i];
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

 int calcularMinimo(int vector[],int tam)
    {
        int flag=0;
        int i;
        int minimo;
        for(i=0; i<tam; i++)
            {
                if(flag==0 ||vector[i]<minimo)
                {
                    minimo=vector[i];
                }
                flag = 1;
            }
        return minimo;
    }

void inicializarArray(int arrayDeSillas[],int tam,int valorDeInicio)//inicializa el array en un numero
{
    int i;

    for(i=0;i<tam;i++)
    {
        arrayDeSillas[i]= valorDeInicio;
    }
}

int estaLibre(int arrayDeSillas[],int tam,int laSilla,int valorInicial)
{
    int i;
    int retorno=0;
    for(i=0;i<tam;i++)
    {
        if(arrayDeSillas[laSilla]==valorInicial)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int ocuparSilla(int arrayDeSillas[],int arrayDeEdad[],int tam,int laSilla,int legajo,int edad)
{
    int estaLibreLaSilla;

    int retorno= 1;

    if(laSilla==tam)
    {
        estaLibreLaSilla= estaLibre(arrayDeSillas,tam,laSilla,-1);

        if(estaLibreLaSilla == 1)
        {
            arrayDeSillas[laSilla]=legajo;
            arrayDeEdad[laSilla]=edad;

            retorno= 1;
        }
    }
    return retorno;
}

int cantidadOcupadas(int arrayDeSillas[],int tam,int valorInicial)
{
    int ocupadas=0;
    int i;

    for(i=0;i<tam;i++)
    {
        if(estaLibre(arrayDeSillas,tam,i,valorInicial) == 1)
        {
            ocupadas++;
        }
    }
    return ocupadas;
}


int cantidadLibres(int arrayDeSillas[],int tam,int valorInicial)
{
    int libres = 0;

    if(cantidadOcupadas(arrayDeSillas,tam,valorInicial) != 1)
    {
        libres++;
    }
    return libres;
}

int indicePrimerLibre(int arrayDeSillas[],int tam,int valorInicial)
{
    int indice;
    int i;
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if(estaLibre(arrayDeSillas,tam,i,valorInicial)== 1 && flag == 0)
        {
            indice = i;
            flag = 1;
        }
    }

    return indice;
}

int ordenarSillas(int arrayDeSillas[],int tam)
{
    int i;
    int j;
    int aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(arrayDeSillas[i]>arrayDeSillas[j])
            {
                aux = arrayDeSillas[i];
                arrayDeSillas[i] = arrayDeSillas[j];
                arrayDeSillas[j] = aux;
            }
        }
    }
}

void mostrarTodosLosDatos(int arrayDeSillas[],int arrayDeEdades[],tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\t%d\t%d\n",i+1,arrayDeSillas[i],arrayDeEdades[i]);
    }
}

void mostarMasViejo(int arrayDeSillas[],int arrayDeEdades[],tam)
{
    int viejo;
    viejo = calcularMaximo(arrayDeEdades,tam)

    printf("%d\t%d\t%d\n",i+1,arrayDeSillas[i],arrayDeEdades[i]);

}
