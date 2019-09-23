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
        printf("5- modificar:\n");
        printf("6- borrar:\n");
        printf("7- salir:\n");

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

                buscarLegajo(listadoDeAlumnos,TAMANIO);

            break;
        case 5:
                modificarAlumno(listadoDeAlumnos,TAMANIO);
            break;
        case 6:
                borrarAlumno(listadoDeAlumnos,TAMANIO);
            break;
        case 7:
            break;
        default:
            printf("SALIR");
        }

    system("pause");
    system("cls");

    }while(opcion != 7);




    return 0;
}
