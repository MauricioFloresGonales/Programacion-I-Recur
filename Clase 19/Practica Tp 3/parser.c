#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pFile!=NULL)
    {
        Employee* empleado;
        char id[51];
        char nombre[51];
        char horasTrabajadas[51];
        char sueldo[51];

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        empleado.id = atoi(id);
        strcpy(empleado.nombre,nombre);
        empleado.horasTrabajadas = atoi(horasTrabajadas);
        empleado.sueldo = atof(sueldo);

        retorno = 0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pFile!=NULL)
    {
        Employee* empleado;
        char id[51];
        char nombre[51];
        char horasTrabajadas[51];
        char sueldo[51];

        fwrite(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        empleado.id = atoi(id);
        strcpy(empleado.nombre,nombre);
        empleado.horasTrabajadas = atoi(horasTrabajadas);
        empleado.sueldo = atof(sueldo);

        retorno = 0;
    }
    return retorno;

    return 1;
}
