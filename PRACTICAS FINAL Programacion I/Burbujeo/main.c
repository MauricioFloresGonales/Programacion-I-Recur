#include <stdio.h>
#include <stdlib.h>

#define LEN 4

void burbujeo(int numerosUno[],int tam);

int main()
{
    int numeros[6]={1,2,3,4,5,6};
    int i;
    burbujeo(numeros,6);
    for(i=0;i<6;i++)
    {
        printf("%d\n",numeros[i]);
    }
    return 0;
}

void burbujeo(int numerosUno[],int tam)
{
    int i;
    int j;
    int aux;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++);
        {
            if(numerosUno[i]<numerosUno[j])
            {
                aux = numerosUno[i];
                numerosUno[i] = numerosUno[j];
                numerosUno[j] = aux;
            }
        }
    }
}
