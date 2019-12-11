#include "entidad.h"

int get_Entero(eEntidad* this,int* entero)
{
    int retorno = -1;
    if(this!=NULL&&entero!=NULL)
    {
        *entero = this->entero;
        retorno = 0;
    }
    return retorno;
}

int set_Entero(eEntidad* this,int entero)
{
    int retorno = -1;
    if(this!=NULL&&entero>0)
    {
        this->entero = entero;
        retorno = 0;
    }
    return retorno;
}

int get_Flotante(eEntidad* this,float* flotante)
{
    int retorno = -1;
    if(this!=NULL&&flotante!=NULL)
    {
        *flotante = this->flotante;
        retorno = 0;
    }
    return retorno;
}

int set_Flotante(eEntidad* this,float flotante)
{
    int retorno = -1;
    if(this!=NULL&&flotante>0)
    {
        this->flotante = flotante;
        retorno = 0;
    }
    return retorno;
}

int get_Palabra(eEntidad* this,char* palabra)
{
    int retorno = -1;
    if(this!=NULL&&palabra!=NULL)
    {
        strcpy(palabra,this->palabra);
        retorno = 0;
    }
    return retorno;
}

int set_Palabra(eEntidad* this,char* palabra)
{
    int retorno = -1;
    if(this!=NULL&&palabra>0)
    {
        strcpy(this->palabra,palabra);
        retorno = 0;
    }
    return retorno;
}

eEntidad* entidad_new(void)
{
    eEntidad* this = (eEntidad*)malloc(sizeof(eEntidad));
    if(this!=NULL)
    {
        set_Entero(this,0);
        set_Flotante(this,0);
        set_Palabra(this,"");
    }

    return this;
}

eEntidad* entidad_newParametros(char* enteroStr,char* flotanteStr,char* palabraStr)
{
    eEntidad* this = entidad_new();

    if(enteroStr!=NULL&&flotanteStr!=NULL&&palabraStr!=NULL)
    {
        if(this!=NULL)
        {
            set_Entero(this,atoi(enteroStr));
            set_Flotante(this,atof(flotanteStr));
            set_Palabra(this,palabraStr);
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
        eEntidad* this = NULL;
        char idVuelo[51];
        char idAvion[51];
        char otro[51];

        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idVuelo, idAvion, otro);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idVuelo, idAvion, otro);
            this = entidad_newParametros(idVuelo, idAvion,otro);
            ll_add(pArrayListLlamadas,this);

        }

        retorno = 0;
    }
    return retorno;
}

void mostrarEntidad(eEntidad* this)
{
    int entero;
    float flotante;
    char palabra[51];

    if(this!=NULL)
    {
        get_Entero(this,&entero);
        get_Flotante(this,&flotante);
        get_Palabra(this,palabra);

        printf("%5d\t",entero);
        printf("%5f\t",flotante);
        printf("%5s\t",palabra);

    }
}

void mostrarTodasLasEntidades(LinkedList* pArrayListLlamadas)
{
    eEntidad* this;
    int len;
    int i;
    if(pArrayListLlamadas!= NULL)
    {
        len = ll_len(pArrayListLlamadas);
        printf("idVuelo\tidAvion\t         Piloto\t\t\t fecha\t      destino\t cant\thoraDesp  horaLlegada\n");

        for(i=0;i<len;i++)
        {
            this =(eEntidad*) ll_get(pArrayListLlamadas,i);
            mostrarEntidad(this);
        }
    }
}

