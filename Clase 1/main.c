#include <stdio.h>
#include <stdlib.h>

int main()//mostrat(entry point de C)
{
/*
    //comomostrar una variable ya ingresada:

    int unNumero = 10 ;
    printf("el numero es: %d",unNumero);

*/

/*
    //como mostraruna ya ingresada y ahiracon un flotante:

    int unNumero = 10 ;
    float otroNumero = 3.21;
    printf("los numerosson: %d y %f",unNumero,otroNumero);

*/

/*
    //ocomo perçdir datos y mostrarlos:

    int unNumero;
    float otroNumero;
    printf("ingreseun numero entero: ");
    scanf("%d",&unNumero);
    printf("ingreseun numero flotante: ");
    scanf("%f",&otroNumero);
    printf("los numerosson: %d y %.2f",unNumero,otroNumero);

*/

/*
    //sumar:

    int unNumero;
    float otroNumero;
    float suma;
    printf("ingreseun numero entero: ");
    scanf("%d",&unNumero);
    printf("ingreseun numero flotante: ");
    scanf("%f",&otroNumero);
    printf("los numeros son: %d y %.2f\n",unNumero,otroNumero);
    suma= unNumero + otroNumero;
    printf("la suma es: %f", suma);
*/
    //ejemplo de como pedir UN char:

    char letra;
    printf("ingrese una letra: ");
    scanf("%c",&letra);
    printf("la letra es: %c",letra);



    return 0;

}

/*
- Codigo fuente es por ejemploel main.c (donde seescribe el codigo/codigo que nosotros escribimos)
- Codigo ojeto es elpor jemplo el main.o( es donde se escribe automaticamente el compilador/es la traduccion a lnguaj de maquina)
- Programa ejecutable (lo que se entrega al cliente)

 CODEBLOCKS:"codeblocks-17.12mingw-setup.exe"

 char: si solo es un solo caracter se usa ej: `2`
       si sonmas de una se usa ej: "22"


  &: direccion dememoria

  5.2f: esto quiere decir cuantos decimales despues dela coma quiero que aparezcan (redondea el numero)
*/
