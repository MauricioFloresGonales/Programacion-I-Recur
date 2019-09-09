#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD 5
int main()
{
    //int sillas[5]={55,11,22,33,44};

    int sillas[CANTIDAD];
    int maximo;
    int minimo;
    int ocupadas;
    int edades[CANTIDAD];


    harcodearLegajo(sillas,CANTIDAD);
    harcodearEdades(edades,CANTIDAD);

    maximo = calcularMaximo(sillas,CANTIDAD);
    printf("maximo = %d\n",maximo);

    minimo = calcularMinimo(sillas,CANTIDAD);
    printf("minimo = %d\n",minimo);

    inicializarArray(sillas,CANTIDAD,int valorDeInicio);

    ocupadas= cantidadOcupadas(sillas,CANTIDAD,int valorInicial);
    printf("la cantidad de ocuapadas son: %d\n",ocupadas);


    return 0;
}
