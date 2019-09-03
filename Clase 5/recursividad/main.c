#include <stdio.h>
#include <stdlib.h>

/*
int main()
{
    int numero=5;
    int resultado=1;
    int i;

    for(i=numero;i>=1;i--)
    {
        resultado = resultado * i;
    }
    printf("%d",resultado);

    return 0;
}
*/

/** \brief calcula el factorial de un numero
 *
 * \param int el numero sobre el que se calcula
 * \return int en factorial
 *
 */
int factorial(int);
int main()
{
   int numero= 5;

    numero = factorial(numero);
    printf("%d",numero);

}

int factorial(int numero)
{
    unsigned int resultado;

    if(numero== 0)
    {
        resultado = 1;
    }else{
        resultado=numero*factorial(numero-1);
    }
    return resultado;
}
