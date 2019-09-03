#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define T 5



int main()
{
    int vectorDeNumeros[10];//={7,-5,5,-6,-1,-4,10,5,4,-6};
    int i;
    int contadorDePositivos = 0;
    int sumaDePositivos = 0;
    float promedioPositivos;
    int maximo;
    int minimo;
    int flag;
    int opcion;

    do{
        printf("1 cargar:\n");
        printf(" 2 mostrar todo:\n");
        printf("3 mostrar negativos:\n");
        printf("4 mostrar promedio de positivos:\n");
        printf("5 mostrar maximo:\n");
        printf("6 mostrar minimo:\n");
        printf("7 salir:\n");
        printf("elija una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarVector(vectorDeNumeros,T);

            break;
        case 2:
            printf("\tMUESTRO EL VECTOR\n");
            for(i=0; i<T; i++)
            {
                printf("%d\n", vectorDeNumeros[i]);
            }
            break;
        case 3:
            printf("\n\n\tMUESTRO SOLO LOS NEGATIVOS\n");
            for(i=0; i<T; i++)
            {
                if(vectorDeNumeros[i]<0)
            {
                printf("%d\n", vectorDeNumeros[i]);
            }
        }
            break;
        case 4:
                for(i=0; i<T; i++)
        {
            if(vectorDeNumeros[i]>=0)
            {
                sumaDePositivos += vectorDeNumeros[i];
                contadorDePositivos++;
            }
        }
        promedioPositivos = (float)sumaDePositivos/contadorDePositivos;

        printf("Suma: %d -- Cantidad %d\n\n", sumaDePositivos, contadorDePositivos);

        printf("\n\n\PROMEDIO DE POSITIVOS: %f\n\n", promedioPositivos);
            break;
        case 5:
            mostrarMaximo(vectorDeNumeros,T);


            break;
        case 6:
            flag=0;
            for(i=0; i<T; i++)
            {
                if(flag==0 ||vectorDeNumeros[i]<minimo)
                {
                    minimo=vectorDeNumeros[i];
                }
            flag = 1;

            printf("EL MINIMO: %d",minimo);

            for(i=0; i<T; i++)
            {
                if(vectorDeNumeros[i]==minimo)
                {
                printf(" - %d",i);
                }
            }
        }
            break;
        default:
            printf("SALIR");
        }

    system("pause");
    system("cls");

    }while(opcion != 7);







    return 0;
}
