#include "Piloto.h"
#include <string.h>

int get_IdVuelo(ePilotos* this,int* idVuelo)
{
    int retorno = -1;
    if(this!=NULL&&idVuelo!=NULL)
    {
        *idVuelo = this->idVuelo;
        retorno = 0;
    }
    return retorno;
}

int set_IdVuelo(ePilotos* this,int idVuelo)
{
    int retorno = -1;
    if(this!=NULL&&idVuelo>0)
    {
        this->idVuelo = idVuelo;
        retorno = 0;
    }
    return retorno;
}

int get_IdAvion(ePilotos* this,int* idAvion)
{
    int retorno = -1;
    if(this!=NULL&&idAvion!=NULL)
    {
        *idAvion = this->idAvion;
        retorno = 0;
    }
    return retorno;
}

int set_IdAvion(ePilotos* this,int idAvion)
{
    int retorno = -1;
    if(this!=NULL&&idAvion>0)
    {
        this->idAvion = idAvion;
        retorno = 0;
    }
    return retorno;
}

int get_IdPiloto(ePilotos* this,int* idPiloto)
{
    int retorno = -1;
    if(this!=NULL&&idPiloto!=NULL)
    {
        *idPiloto = this->idPiloto;
        retorno = 0;
    }
    return retorno;
}

int set_IdPiloto(ePilotos* this,int idPiloto)
{
    int retorno = -1;
    if(this!=NULL&&idPiloto>0)
    {
        this->idPiloto = idPiloto;
        retorno = 0;
    }
    return retorno;
}

int get_fecha(ePilotos* this,char* fecha)
{
    int retorno = -1;
    if(this!=NULL&&fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno = 0;
    }
    return retorno;
}

int set_fecha(ePilotos* this,char* fecha)
{
    int retorno = -1;
    if(this!=NULL&&fecha)
    {
        strcpy(this->fecha,fecha);
        retorno = 0;
    }
    return retorno;
}
int get_destino(ePilotos* this,char* destino)
{
    int retorno = -1;
    if(this!=NULL&&destino!=NULL)
    {
        strcpy(destino,this->destino);
        retorno = 0;
    }
    return retorno;
}

int set_destino(ePilotos* this,char* destino)
{
    int retorno = -1;
    if(this!=NULL&&destino>0)
    {
        strcpy(this->destino,destino);
        retorno = 0;
    }
    return retorno;
}

int get_cantPasajeros(ePilotos* this,int* cantPasajeros)
{
    int retorno = -1;
    if(this!=NULL&&cantPasajeros!=NULL)
    {
        *cantPasajeros = this->cantPasajeros;
        retorno = 0;
    }
    return retorno;
}

int set_cantPasajeros(ePilotos* this,int cantPasajeros)
{
    int retorno = -1;
    if(this!=NULL&&cantPasajeros>0)
    {
        this->cantPasajeros = cantPasajeros;
        retorno = 0;
    }
    return retorno;
}

int get_horaDespegue(ePilotos* this,int* horaDespegue)
{
    int retorno = -1;
    if(this!=NULL&&horaDespegue!=NULL)
    {
        *horaDespegue = this->horaDespegue;
        retorno = 0;
    }
    return retorno;
}


int set_horaDespegue(ePilotos* this,int horaDespegue)
{
    int retorno = -1;
    if(this!=NULL&&horaDespegue>0)
    {
        this->horaDespegue = horaDespegue;
        retorno = 0;
    }
    return retorno;
}

int get_horaLlegada(ePilotos* this,int* horaLlegada)
{
    int retorno = -1;
    if(this!=NULL&&horaLlegada!=NULL)
    {
        *horaLlegada = this->horaLlegada;
        retorno = 0;
    }
    return retorno;
}


int set_horaLlegada(ePilotos* this,int horaLlegada)
{
    int retorno = -1;
    if(this!=NULL&&horaLlegada>0)
    {
        this->horaLlegada = horaLlegada;
        retorno = 0;
    }
    return retorno;
}

//----------------------------------------------------------------------------------------------

ePilotos* pilotos_new(void)
{
    ePilotos* this = (ePilotos*)malloc(sizeof(ePilotos));
    if(this!=NULL)
    {
        this->idVuelo = 0;
        this->idAvion = 0;
        this->idPiloto = 0;
        strcpy(this->fecha,"");
        strcpy(this->destino,"");
        this->cantPasajeros = 0;
        this->horaDespegue = 0;
        this->horaLlegada = 0;
    }

    return this;
}

ePilotos* pilotos_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr)
{
    ePilotos* this = pilotos_new();

    if(idVueloStr!=NULL&&idAvionStr!=NULL&&idPilotoStr!=NULL&&fechaStr!=NULL&&destinoStr!=NULL&&cantPasajerosStr!=NULL&&horaDespegueStr!=NULL&&horaLlegadaStr!=NULL)
    {
        if(this!=NULL)
        {
            set_IdVuelo(this,atoi(idVueloStr));
            set_IdAvion(this,atoi(idAvionStr));
            set_IdPiloto(this,atoi(idPilotoStr));
            set_fecha(this,fechaStr);
            set_destino(this,destinoStr);
            set_cantPasajeros(this,atoi(cantPasajerosStr));
            set_horaDespegue(this,atoi(horaDespegueStr));
            set_horaLlegada(this,atoi(horaLlegadaStr));
        }
    }
    return this;
}

int controller_loadFromText(char* path , LinkedList* pArrayListLlamadas)
{
    FILE* pFile = fopen(path,"r");
    int retorno = -1;

    if(pFile!=NULL)
    {

        retorno = parser_LLamadasFromText(pFile,pArrayListLlamadas);

        fclose(pFile);
    }

    return retorno;
}

int parser_LLamadasFromText(FILE* pFile , LinkedList* pArrayListLlamadas)
{
    int retorno = -1;
    if(pFile!=NULL)
    {
        ePilotos* this = NULL;
        char idVuelo[51];
        char idAvion[51];
        char idPiloto[51];
        char fecha[51];
        char destino[51];
        char cantPasajeros[51];
        char horaDespegue[51];
        char horaLlegada[51];

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            this = pilotos_newParametros(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            ll_add(pArrayListLlamadas,this);

        }

        retorno = 0;
    }
    return retorno;
}

void mostrarPiloto(ePilotos* this)
{
    int idvueloAux;
    int idAvionAux;
    char fechaAux[51];
    char destinoAux[51];
    int cantPasAux;
    int horaDespegueAux;
    int horaLlegadaAux;
    if(this!=NULL)
    {
        get_IdVuelo(this,&idvueloAux);
        get_IdAvion(this,&idAvionAux);
        get_fecha(this,fechaAux);
        get_destino(this,destinoAux);
        get_cantPasajeros(this,&cantPasAux);
        get_horaDespegue(this,&horaDespegueAux);
        get_horaLlegada(this,&horaLlegadaAux);

        printf("%5d\t",idvueloAux);
        printf("%5d\t",idAvionAux);
        nombres(this);
        printf("%15s\t",fechaAux);
        printf("%15s\t",destinoAux);

        printf("%5d\t",cantPasAux);
        printf("%5d\t",horaDespegueAux);
        printf("%5d\n",horaLlegadaAux);
    }
}

void nombres(ePilotos* this)
{
    int id;
    if(this!=NULL)
    {
        id= this->idPiloto;
        //get_IdPiloto(this,id);
        switch(id)
        {
        case 1:
            printf("\tAlex Lifeson\t");
            break;
        case 2:
            printf("\tRichard Bach\t");
            break;
        case 3:
            printf("\tJohn Kerry\t");
            break;
        case 4:
            printf("\tErwin Rommel\t");
            break;
        default:
            printf("\tStephen Coonts\t");
            break;
        }
    }
}

void mostrarTodosLosPilotos(LinkedList* pArrayListLlamadas)
{
    ePilotos* this;
    int len;
    int i;
    if(pArrayListLlamadas!= NULL)
    {
        len = ll_len(pArrayListLlamadas);
        printf("idVuelo\tidAvion\t         Piloto\t\t\t fecha\t      destino\t cant\thoraDesp  horaLlegada\n");

        for(i=0;i<len;i++)
        {
            this =(ePilotos*) ll_get(pArrayListLlamadas,i);
            mostrarPiloto(this);
        }
    }
}

int filtrarVuelosPortugal(LinkedList* pArrayListVuelos)
{
    LinkedList* arrayAux = NULL;
    ePilotos* PilotoAux = NULL;
    int len;
    int i;
    int retorno = -1;
    if(pArrayListVuelos!=NULL)
    {
        len = ll_len(pArrayListVuelos);
        if(len>0)
        {

            arrayAux  = filter(pArrayListVuelos,fnPortugal);

            for(i=0;i<len;i++)
            {
             //   PilotoAux=ll_get(arrayAux,i);
                //mostrarPiloto(PilotoAux);
                retorno = 0;
            }
            mostrarTodosLosPilotos(arrayAux);

        }
    }
    return retorno;
}

int fnPortugal(void* pElement)
{
    int compara = 0;
    ePilotos* this=(ePilotos*)pElement;
    char destino[51];
    get_destino(this,destino);

    if(strcmp(destino,"Portugal")== 0)
    {
        compara=1;
    }
    return compara;
}

int fnAlex(void* pElement)
{
    int compara = 0;
    ePilotos* this=(ePilotos*)pElement;
    int piloto;
    get_IdPiloto(this,&piloto);

    if(piloto!= 1)
    {
        compara=1;
    }
    return compara;
}


int filtrarPiloto(LinkedList* pArrayListVuelos)
{
    LinkedList* arrayAux = NULL;
    ePilotos* PilotoAux = NULL;
    int len;
    int i;
    int retorno = -1;
    if(pArrayListVuelos!=NULL)
    {
        len = ll_len(pArrayListVuelos);
        if(len>0)
        {
            arrayAux = filter(pArrayListVuelos,fnAlex);
            mostrarTodosLosPilotos(arrayAux);
        }
    }
    return retorno;
}
