#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "soporte.h"
#include "Inputs.h"

int main()
{
    LinkedList* pArrayListLlamadas;
    int opcion;
    do{
        while(getInt(&opcion,"1. Cargar Arhivo\n2. Impriimir Llamadas\n3.Generar Archivos de Llamada\n4. Salir\nElija una opcion: ","Solo puede ingresar numeros del[1] al [4]",1,4)!=0);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("DATOS.csv",pArrayListLlamadas);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
    }while(opcion!=4);



    return 0;
}
