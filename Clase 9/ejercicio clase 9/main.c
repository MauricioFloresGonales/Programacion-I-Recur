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
        printf("1- mostrar:\n");
        printf("2- cargar:\n");
        printf("3- buscar:\n");
        printf("4- borrar:\n");
        printf("5- salir:\n");
        printf("elija una opcion:\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            harcodearDatos(listadoDeAlumnos,5);
            MostrarAlumnos(listadoDeAlumnos,TAMANIO);

            break;
        case 2:
                ingresarDatos(listadoDeAlumnos,TAMANIO);


            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        default:
            printf("SALIR");
        }

    system("pause");
    system("cls");

    }while(opcion != 5);




    return 0;
}
