#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Inputs.h"

typedef struct
{
    int entero;
    float flotante;
    char palabra[51];

}eEntidad;
int get_Entero(eEntidad*,int*);
int set_Entero(eEntidad*,int );
int get_Flotante(eEntidad*,float*);
int set_Flotante(eEntidad*,float);
int get_Palabra(eEntidad*,char*);
int set_Palabra(eEntidad* ,char*);
eEntidad* entidad_new(void);
eEntidad* entidad_newParametros(char*,char*,char*);
int controller_loadFromText(char* path , LinkedList* pArrayListLlamadas);
int parser_LLamadasFromText(FILE*,LinkedList* pArrayListLlamadas);
void mostrarEntidad(eEntidad*);
void mostrarTodasLasEntidades(LinkedList* pArrayListLlamadas);
