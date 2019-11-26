#include "Inputs.h"
#include "LinkedList.h"
#include "soporte.h"
#include <string.h>

int get_IdLlamada(eLlamada* this,int* id)
{
    int retorno = -1;
    if(this!=NULL&&id!=NULL)
    {
        *id = this->idLlamada;
        retorno = 0;
    }
    return retorno;
}

int set_IdLlamada(eLlamada* this,int id)
{
    int retorno = -1;
    if(this!=NULL&&id>0)
    {
        this->idLlamada = id;
        retorno = 0;
    }
    return retorno;
}

int get_Fecha(eLlamada* this,char* fecha)
{
    int retorno = -1;
    if(this!=NULL&&fecha!=NULL)
    {
        fecha = this->fecha;
        retorno = 0;
    }
    return retorno;
}

int set_Fecha(eLlamada* this,char* fecha)
{
    int retorno = -1;
    if(this!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno = 0;
    }
    return retorno;
}

int get_NumCliente(eLlamada* this,int* numCliente)
{
    int retorno = -1;
    if(this!=NULL&&numCliente!=NULL)
    {
        *numCliente = this->numCliente;
        retorno = 0;
    }
    return retorno;
}

int set_NumCliente(eLlamada* this,int numCliente)
{
    int retorno = -1;
    if(this!=NULL&&numCliente>0)
    {
        this->numCliente = numCliente;
        retorno = 0;
    }
    return retorno;
}

int get_IdProblema(eLlamada* this,int* idProblema)
{
    int retorno = -1;
    if(this!=NULL&&idProblema!=NULL)
    {
        *idProblema = this->idProblema;
        retorno = 0;
    }
    return retorno;
}

int set_IdProblema(eLlamada* this,int idProblema)
{
    int retorno = -1;
    if(this!=NULL&&idProblema>0)
    {
        this->idProblema = idProblema;
        retorno = 0;
    }
    return retorno;
}
int get_Solucionado(eLlamada* this,char* solucionado)
{
    int retorno = -1;
    if(this!=NULL&&solucionado!=NULL)
    {
        solucionado = this->solucionado;
        retorno = 0;
    }
    return retorno;
}

int set_Solucionado(eLlamada* this,char* solucionado)
{
    int retorno = -1;
    if(this!=NULL&&solucionado>0)
    {
        strcpy(this->solucionado,solucionado);
        retorno = 0;
    }
    return retorno;
}
//--------------------------------------------------------------------------------------------------------------------------

int fnid1(void* pElement)
{
    int compara = 0;
    eLlamada* this=(eLlamada*)pElement;
    int id;
    get_IdLlamada(this,&id);
    if(id==1)
    {
        compara=1;
    }
    return compara;
}

int fnId2(void* pElement)
{
    int compara = 0;
    eLlamada* this=(eLlamada*)pElement;
    int id;
    get_IdLlamada(this,&id);
    if(id==2)
    {
        compara=1;
    }
    return compara;

}
int fnId3(void* pElement)
{
    int compara = 0;
    eLlamada* this=(eLlamada*)pElement;
    int id;
    get_IdLlamada(this,&id);
    if(id==3)
    {
        compara=1;
    }
    return compara;

}
int fnId4(void* pElement)
{
    int compara = 0;
    eLlamada* this=(eLlamada*)pElement;
    int id;
    get_IdLlamada(this,&id);
    if(id==4)
    {
        compara=1;
    }
    return compara;

}
int fnId5(void* pElement)
{
    int compara = 0;
    eLlamada* this=(eLlamada*)pElement;
    int id;
    get_IdLlamada(this,&id);
    if(id==5)
    {
        compara=1;
    }
    return compara;
}

eLlamada* llamada_new()
{
    eLlamada* this =(eLlamada*)malloc(sizeof(eLlamada));
    if(this!=NULL)
    {
        this->idLlamada = 0;
        strcpy(this->fecha,"");
        this->numCliente = 0;
        this->idProblema = 0;
        strcpy(this->solucionado,"");
    }
    return this;
}

eLlamada* Llamada_newParametros(char* idLlamadaStr,char* fechaStr,char* numClienteStr,char* idProblemaStr,char* solucionadoStr)
{
    eLlamada* this = llamada_new();

    if(idLlamadaStr!=NULL&&fechaStr!=NULL&&numClienteStr!=NULL&&idProblemaStr!=NULL&&solucionadoStr!=NULL)
    {
        if(this!=NULL)
        {
            set_IdLlamada(this,atoi(idLlamadaStr));
            set_Fecha(this,fechaStr);
            set_NumCliente(this,atoi(numClienteStr));
            set_IdProblema(this, atoi(idProblemaStr));
            set_Solucionado(this,solucionadoStr);
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
        eLlamada* this = NULL;
        char idLlamada[51];
        char fecha[51];
        char numCliente[51];
        char idProblema[51];
        char solucionado[3];

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idLlamada,fecha,numCliente,idProblema,solucionado);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idLlamada,fecha,numCliente,idProblema,solucionado);
            this = Llamada_newParametros(idLlamada,fecha,numCliente,idProblema,solucionado);
            ll_add(pArrayListLlamadas,this);

        }

        retorno = 0;
    }
    return retorno;
}

