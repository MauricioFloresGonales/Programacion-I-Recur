#include <stdio.h>
#include <stdlib.h>
//Mostrar el mayor valor en dolares

int main()
{
    int dinero;
    char tipo;
    int cont = 0;
    int mayorValorDolar;
    int primerDolar = 0;
    int cantPesos = 0;
    int totalPesos = 0;
    float promedioPesos = 0;

    while(cont < 5){

        printf("Ingrese el tipo :");
        fflush(stdin);
        scanf("%c", &tipo);

        printf("Ingrese la cantidad :");
        scanf("%d", &dinero);

        if(tipo == 'd' && primerDolar == 0)
        {
            mayorValorDolar = dinero;
            primerDolar = 1;
        }
        else if(tipo == 'd' && dinero > mayorValorDolar)
        {
            mayorValorDolar = dinero;
        }

        if(tipo == 'p')
        {
            totalPesos += dinero;
            cantPesos++;
        }

        cont++;
    }

    promedioPesos = totalPesos / cantPesos;

    if(primerDolar == 0)
    {
        printf("No se ingresaron dolares");
    }
    else
    {
        printf("El importe maximo en dolares es : %d \n", mayorValorDolar);
    }

    printf("El promedio en pesos es : %f \n", promedioPesos);

    return 0;
}
