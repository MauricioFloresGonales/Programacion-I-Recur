#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float salario;

}eEmpleado;

eEmpleado* new_Empleado();

int main()
{
    eEmpleado* lista[50];
    eEmpleado* unEmpleado;// = new_Empleado();  Con esto aca nos los datos se nos pisan al nsolo crear un puntero

    FILE* pArchivo;
    char legajo[20];
    char nombre [10];
    char apellido[10];
    char sueldo[20];
    int i;

    pArchivo = fopen("datos.csv","r");

    fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);

    while(!feof(pArchivo))
    {
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);

        unEmpleado= new_Empleado();

        unEmpleado->id = atoi(legajo);
        strcpy(unEmpleado->nombre,nombre);
        strcpy(unEmpleado->apellido,apellido);
        unEmpleado->salario = atof(sueldo);

        lista[i] = unEmpleado;
        i++;
    }

    fclose(pArchivo);

    for(i=0;i<50;i++)
    {
        printf("%d-%s-%s-%f\n",lista[i]->id,lista[i]->nombre,lista[i]->apellido,lista[i]->salario);
    }


    return 0;
}


eEmpleado* new_Empleado()
{
    eEmpleado* p;

    p = (void*)malloc(sizeof(eEmpleado));

    return p;
}


/*
int main()
{
    eEmpleado* lista[50];

    FILE* pArchivo;
    char legajo[20];
    char nombre [10];
    char apellido[10];
    char sueldo[20];

    pArchivo = fopen("datos.csv","r");

    while(!feof(pArchivo))
    {
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);

        printf("%s-%s-%s-%s",legajo,nombre,apellido,sueldo);
    }

    fclose(pArchivo);

    return 0;
}*/
