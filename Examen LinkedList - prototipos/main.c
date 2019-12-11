#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Inputs.h"


int main()
{
    LinkedList* pArrayListLlamadas = ll_newLinkedList();
    int opcion;
    do{
        while(getInt(&opcion,"1.\n2.\n3.\n4.\n5\nElija una opcion: ","Solo puede ingresar numeros del[1] al [6]",1,6)!=0);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("Entidad.csv",pArrayListLlamadas);
            break;
        case 2:
            mostrarTodasLasEntidades(pArrayListLlamadas);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("\nSALIR\n");
            break;
        }
    }while(opcion!=6);
    return 0;
}
