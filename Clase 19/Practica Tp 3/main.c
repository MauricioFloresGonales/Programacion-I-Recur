#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
/*
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    Employee* empleadoUno = employee_newParametros("5","maria","10","5000");
    Employee* empleadoDos = employee_newParametros("2","carlos","15","6500");
    Employee* empleadoTres = employee_newParametros("6","jose","12","6000");
    Employee* empleadoCuatro = employee_newParametros("9","juan","8","100");

    Employee* aux;

    int x;
    int len;

    ll_add(listaEmpleados,empleadoUno);
    ll_add(listaEmpleados,empleadoDos);
    ll_add(listaEmpleados,empleadoTres);
    //ll_set(listaEmpleados,2,empleadoCuatro);
    ll_push(listaEmpleados,1,empleadoCuatro);///dif entre set y push

    len = ll_len(listaEmpleados);

    for(x=0;x<len;x++)
    {
        aux = (Employee*) ll_get(listaEmpleados,x);
        mostrarEmpleado(aux);
    }

    //ll_remove(listaEmpleados,1);
    aux = ll_pop(listaEmpleados,1);

    printf("\n");
    printf("eliminaste a: \n");
    mostrarEmpleado(aux);

    printf("\n");

    for(x=0;x<len;x++)
    {
        aux = (Employee*) ll_get(listaEmpleados,x);
        mostrarEmpleado(aux);
    }
//---------------------------------------------------------------------------------------------

    ll_clear(listaEmpleados);

    len = ll_isEmpty(listaEmpleados);
    printf("%d",len);

//---------------------------------------------------------------------------------------------
    LinkedList* lsitaAux = ll_subList(listaEmpleados,0,2);
    printf("\n");
    for(x=0;x<len;x++)
    {
        aux = (Employee*) ll_get(lsitaAux,x);
        mostrarEmpleado(aux);
    }

*/

//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------

    LinkedList* listaEmpleados = ll_newLinkedList();

    Employee* empleadoUno = employee_newParametros("5","A maria","10","5000");
    Employee* empleadoDos = employee_newParametros("2","B carlos","15","6000");
    Employee* empleadoTres = employee_newParametros("6","C jose","12","6000.5");
    Employee* empleadoCuatro = employee_newParametros("9","D juan","8","100");

    Employee* aux;

    int x;
    int len;

    ll_add(listaEmpleados,empleadoUno);
    ll_add(listaEmpleados,empleadoDos);
    ll_add(listaEmpleados,empleadoTres);
    //ll_set(listaEmpleados,2,empleadoCuatro);
    ll_push(listaEmpleados,1,empleadoCuatro);///dif entre set y push

    //ll_sort(listaEmpleados,compararPorLegajo,1);
    ll_sort(listaEmpleados,compararPorSueldo,0);
    //ll_sort(listaEmpleados,compararPorNombre,1);
    len = ll_len(listaEmpleados);

    for(x=0;x<len;x++)
    {
        aux = (Employee*) ll_get(listaEmpleados,x);
        mostrarEmpleado(aux);
    }


    return 0;
}
