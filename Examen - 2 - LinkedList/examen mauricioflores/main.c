#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Inputs.h"
#include "Piloto.h"

int main()
{
    LinkedList* pArrayListLlamadas = ll_newLinkedList();
    int opcion;
    do{
        while(getInt(&opcion,"1. Cargar Arhivo\n2. Impriimir Vuleos\n3.Generar Archivos de Llamada\n4.Listar vuelos a Portugal\n5Salir\nElija una opcion: ","Solo puede ingresar numeros del[1] al [4]",1,6)!=0);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("Vuelos.csv",pArrayListLlamadas);
            break;
        case 2:
            mostrarTodosLosPilotos(pArrayListLlamadas);
            break;
        case 3:
            //FiltrarLlamada(pArrayListLlamadas);
            break;
        case 4:
            filtrarVuelosPortugal(pArrayListLlamadas);

            break;
        case 5:
            filtrarPiloto(pArrayListLlamadas);
            break;
        default:
            printf("\nSALIR\n");
            break;
        }
    }while(opcion!=6);
    return 0;
}
