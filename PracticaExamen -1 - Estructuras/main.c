#include <stdio.h>
#include <stdlib.h>
#include "Empleados.h"

#define LEN 4
int main()
{
    eEmpleado empleado[LEN];
    int i;


    inicializarEmpleados(empleado,LEN);

    for(i=0;i<LEN;i++)
    {
        ingresarDatos(empleado,LEN);
    }


    MostrarAlumnos(empleado,LEN);

    return 0;
}
