#include "Inputs.h"
#include "LinkedList.h"
#include <string.h>
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[51];
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}ePilotos;

int get_IdVuelo(ePilotos* this,int* idVuelo);
int set_IdVuelo(ePilotos* this,int idVuelo);

int get_IdAvion(ePilotos* this,int* idAvion);
int set_IdAvion(ePilotos* this,int idAvion);

int get_IdPiloto(ePilotos* this,int* idPiloto);
int set_IdPiloto(ePilotos* this,int idPiloto);

int get_fecha(ePilotos* this,char* fecha);
int set_fecha(ePilotos* this,char* fecha);

int get_destino(ePilotos* this,char* destino);
int set_destino(ePilotos* this,char* destino);

int get_cantPasajeros(ePilotos* this,int* cantPasajeros);
int set_cantPasajeros(ePilotos* this,int cantPasajeros);

int get_horaDespegue(ePilotos* this,int* horaDespegue);
int set_horaDespegue(ePilotos* this,int horaDespegue);

int get_horaLlegada(ePilotos* this,int* horaLlegada);
int set_horaLlegada(ePilotos* this,int horaLlegada);

ePilotos* pilotos_new(void);

ePilotos* pilotos_newParametros(char* ,char* ,char* ,char* ,char*,char*,char*,char* );

int controller_loadFromText(char* path , LinkedList* pArrayListLlamadas);
int parser_LLamadasFromText(FILE* pFile , LinkedList* pArrayListLlamadas);

void mostrarPiloto(ePilotos* this);
void nombres(ePilotos* this);
void mostrarTodosLosPilotos(LinkedList* pArrayListLlamadas);

int filtrarVuelosPortugal(LinkedList* pArrayListVuelos);
int fnPortugal(void* pElement);
int fnAlex(void* pElement);
int filtrarPiloto(LinkedList* pArrayListVuelos);
