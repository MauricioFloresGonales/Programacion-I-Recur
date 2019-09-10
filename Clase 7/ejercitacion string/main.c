#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
    /*
    CHAR NOMBRE[15];
    CHAR APELLIDO[15];
    CHAR APELLIDOnOMBRE[50]; ------------> Apellido,Nombre
       */

    char nombre[15];
    char apellido[15];
    char apellidoNombre[100];

     pedirNombre("ingresar su nombre: ",nombre);
     pedirNombre("ingresar su apellido: ",apellido);
     mostrarNombre(nombre);
     mostrarNombre(apellido);




    return 0;
}
