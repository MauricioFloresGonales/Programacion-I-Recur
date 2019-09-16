#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAMANIO 5
int main()
{
    eAlumno listadoDeAlumnos[TAMANIO];
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
            harcodearDatos(listadoDeAlumnos,TAMANIO);
            MostrarAlumnos(listadoDeAlumnos,TAMANIO);

            break;
        case 2:

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
