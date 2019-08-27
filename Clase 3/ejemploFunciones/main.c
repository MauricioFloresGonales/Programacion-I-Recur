#include <stdio.h>
#include <stdlib.h>

//PROTOTIPO

int sumarNuemeros(int,int);

int main()
{
    //LLAMADA

    int numeroUno = 8;
    int numeroDos = 9;
    int total;

    total = sumarNuemeros(numeroUno,numeroDos);
    printf("la suma es %d", total);

    return 0;
}

//DESARROLLO

  int sumarNuemeros(int a, int b)
  {
      int resultado;

      resultado = a + b ;

      return resultado;
  }
