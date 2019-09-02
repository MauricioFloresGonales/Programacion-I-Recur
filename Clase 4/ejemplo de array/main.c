#include <stdio.h>
#include <stdlib.h>

int main()
{
/*  1- ingresar numeros
    2- mostrar numeros enteros y positivos
    3- contador de positivos
    4- encontrar maximo y minimo  */
    //jemplo de arrray

    int numero;
    int vectorDeNumeros[10]={-1,2,-3,-4,-5,6,-7,-8,-9,-10};
    int i;
    int contadorDePositivos = 0;
    int sumaDePositivos;
    float promedioDePositivos;
    int flag = 0;
    int maximo;
    int minimo;

    /*for(i=0;i<10;i++)
    {
        printf("ingrese un numero: ");
        scanf("%d",&vectorDeNumeros[i]);
    }*/

    for(i=0;i<10;i++)
    {
       //printf("vectorDeNumeros[i] = %d ;\n",vectorDeNumeros[i]);

        if(vectorDeNumeros[i]< 0)
        {
            printf("Negativo = %d\n\n",vectorDeNumeros[i]);
        }else{
            printf("Positivo = %d\n\n",vectorDeNumeros[i]);
        }
    }

    for(i=0;i<10;i++)
    {
        if(vectorDeNumeros[i]>= 0)
        {
            sumaDePositivos += vectorDeNumeros[i];
            contadorDePositivos++;
        }
    }

    for(i=0;i<10;i++)
    {
        if(flag == 1)
        {
            if(vectorDeNumeros[i]> maximo)
            {
                maximo= vectorDeNumeros[i];
            }else if(vectorDeNumeros<minimo)
            {
                minimo=vectorDeNumeros[i];
            }

        }else{

            minimo = vectorDeNumeros[i];
            maximo = vectorDeNumeros[i];
            flag = 1;

        }
    }


    promedioDePositivos = (float)sumaDePositivos/contadorDePositivos;
    printf("el promedio de positivos es: %f\n",promedioDePositivos);


    printf("EL MAXIMO ES: %d\n",maximo);
    printf("EL MINIMO ES: %d\n",minimo);



    return 0;
}
