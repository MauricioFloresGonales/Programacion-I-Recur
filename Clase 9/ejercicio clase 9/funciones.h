#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct{

    char nombre[50];
    int nota;
    int legajo;
    int estaVacio;

}eAlumno;

void harcodearDatos(eAlumno[],int cantidad);
void inicializarAlumno(eAlumno[],int cantidad);
void ingresarDatos(eAlumno[],int indice);
void MostrarAlumnos(eAlumno[],int cantidad);
void mostrarUnAlumno(eAlumno[],int indice);
int dameIndiceLibre(eAlumno[],int cantidad);//RETORNA un INDICE
void buscarLegajo(eAlumno[],int cantidad);
