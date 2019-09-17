#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define TAMANIO 6

int main()
{
    eAlumno listadoDeAlumnos[TAMANIO];

    inicializarAlumno(listadoDeAlumnos,TAMANIO);

    int opcion;
    do{
        printf("1- Cargar datos hardcodeados\n");
        printf("2- mostrar:\n");
        printf("3- cargar:\n");
        printf("4- buscar:\n");
        printf("5- borrar:\n");
        printf("6- salir:\n");

        printf("elija una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            harcodearDatos(listadoDeAlumnos,5);

            break;
        case 2:

            MostrarAlumnos(listadoDeAlumnos,TAMANIO);

            break;
        case 3:

            ingresarDatos(listadoDeAlumnos,TAMANIO);

            break;
        case 4:



            break;
        case 5:
                borrarAlumno(listadoDeAlumnos,TAMANIO);
            break;
        case 6:
            break;
        default:
            printf("SALIR");
        }

    system("pause");
    system("cls");

    }while(opcion != 6);




    return 0;
}
