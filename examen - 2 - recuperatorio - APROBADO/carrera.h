#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Inputs.h"
#include "time.h"

typedef struct
{
    int ID_BIKE;
    char NOMBRE[51];
    char TIPO[51];
    int TIEMPO;

}eCarrera;

int get_Id(eCarrera*,int*);
int set_Id(eCarrera*,int );
int get_Nombre(eCarrera* this,char* tipo);
int set_Nombre(eCarrera* this,char* tipo);
int get_Tipo(eCarrera*,char*);
int set_Tipo(eCarrera*,char*);
int get_tiempo(eCarrera*,int*);
int set_tiempo(eCarrera*,int );


eCarrera* entidad_new(void);
eCarrera* entidad_newParametros(char*,char*,char*,char*);
int controller_loadFromText(char* path , LinkedList* pArrayListLlamadas);
int parser_LLamadasFromText(FILE*,LinkedList* pArrayListLlamadas);
void mostrarEntidad(eCarrera*);
void tiposDeBicis(eCarrera*,int id);
void mostrarTodasLasEntidades(LinkedList* pArrayListLlamadas);
void* aleatorio(void* pElement);
int soloBmx(void* pElement);
int soloPlayera(void* pElement);
int soloMtb(void* pElement);
int soloPaseo(void* pElement);
void filtroPorTipo(LinkedList* pArrayListBicicletas);
int ordenarPos(void* unaBici,void* otraBici);
void posciones(LinkedList* pArrayListBicicletas);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
