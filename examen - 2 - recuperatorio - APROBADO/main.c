#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Inputs.h"
#include "carrera.h"
#include "time.h"

int main()
{
    srand (time(NULL));
    LinkedList* pArrayListBicicletas = ll_newLinkedList();
    int opcion;
    do{
        while(getInt(&opcion,"1.Cargar Archivo\n2.Imprimir Lista\n3.Asignar Tiempo\n4.Filtrar Tipo\n5.MostrarPosiciones\n6.Salir\nElija una opcion: ","Solo puede ingresar numeros del[1] al [6]",1,6)!=0);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("bicicletas.csv",pArrayListBicicletas);
            break;
        case 2:
            mostrarTodasLasEntidades(pArrayListBicicletas);
            break;
        case 3:
            ll_map(pArrayListBicicletas,aleatorio);
            break;
        case 4:
            filtroPorTipo(pArrayListBicicletas);
            break;
        case 5:
            posciones(pArrayListBicicletas);
            break;
        default:
            printf("\nSALIR\n");
            break;
        }
    }while(opcion!=6);
    return 0;
}
