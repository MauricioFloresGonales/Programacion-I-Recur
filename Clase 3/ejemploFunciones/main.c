#include <stdio.h>
#include <stdlib.h>

//PROTOTIPO

int pedirNumero(int);
int sumarNuemeros(int,int);
int restarNumeros(int,int);

int main()
{
    //LLAMADA

    int numeroUno /*= 8*/;
    int numeroDos /*= 9*/;
    int totalSuma;
    int totalResta;

    numeroUno = pedirNumero(numeroUno);
    numeroDos = pedirNumero(numeroDos);
    totalSuma = sumarNuemeros(numeroUno,numeroDos);
    totalResta = restarNumeros(numeroUno,numeroDos);
    printf("la suma es %d\n", totalSuma);
    printf("la resta es %d\n", totalResta);

    return 0;
}

//DESARROLLO

int pedirNumero(int numeroIngresado)
{
    int numero;
    printf("ingrese un numero: ");
    scanf("%d",&numero);
    return numero;
}

  int sumarNuemeros(int a, int b)
  {
      int resultado;

      resultado = a + b ;

      return resultado;
  }

  int restarNumeros(int a,int b)
  {
      int resultado;

        resultado = a - b ;

      return resultado;
  }
