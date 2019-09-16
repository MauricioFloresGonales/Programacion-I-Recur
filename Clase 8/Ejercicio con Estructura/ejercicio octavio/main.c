#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    eAlumno listadoDeAlumnos[5];

    inicializarAlumno(listadoDeAlumnos,5);
    MostrarAlumnos(listadoDeAlumnos,5);

    return 0;
}
