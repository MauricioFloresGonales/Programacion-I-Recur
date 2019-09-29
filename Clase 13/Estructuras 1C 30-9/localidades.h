#include "Alumno.h"

typedef struct
{
    int idLocalidad;
    int contadores;

}eEstructAux;


typedef struct
{
    int idLocalidad;
    char localidad[30];
    int codigoPostal;

} eLocalidad;

void mostrarAlumnoConLocalidad(eAlumno[],int,eLocalidad[],int);
