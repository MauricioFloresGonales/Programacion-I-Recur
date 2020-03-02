#include <stdio.h>
#include <stdlib.h>
#include "eEntidad.h"

/**Realizar un programa que permita manejar una entidad definida por id,
con por lo menos 2 campos (uno numérico y otro alfanumérico).

Dicho programa deberá trabajar la entidad de manera dinámica,
de acuerdo a las reglas establecidas en la cátedra, permitiendo guardar
en un archivo binario por lo menos dos datos de la entidad en cuestión. Por ultimo leer
del archivo dichos datos y mostrarlos.*/

/*como lo tengo que hacer?
tengo que usar un vector?seguiria usandolo con memoria dinamica?
*/


int main()
{
    eEntidad* entidadUno = entidad_newParametros(10, 5, "entidadUno");


    //mostrar(entidad);

    guardarEnBinario("entidades.txt", entidadUno);
    leerEnBinario("entidades.txt");


    return 0;
}





