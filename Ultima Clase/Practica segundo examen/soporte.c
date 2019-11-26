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

int fnId1(void* pElement)
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

void mostrarEmpleado(eLlamada* this)
{
    if(this!=NULL)
    {
        printf("%5d\t",this->idLlamada);
        printf("%15s\t",this->fecha);
        printf("%10d\t",this->numCliente);
        problemas(this);
        printf("\t%-15s\n",this->solucionado);
    }
}

void problemas(eLlamada* this)
{
    int id;
    if(this!=NULL)
    {
        id=this->idProblema;
        switch(id)
        {
        case 1:
            printf("\tNo enciende PC\t\t");
            break;
        case 2:
            printf("\tNo funciona mouse\t");
            break;
        case 3:
            printf("\tNo funciona teclado\t");
            break;
        case 4:
            printf("\tNo hay internet\t\t");
            break;
        default:
            printf("\tNo funciona teléfono\t");
            break;
        }
    }
}

void mostrarTodosLosLlamados(LinkedList* pArrayListLlamadas)
{
    eLlamada* this;
    int len;
    int i;

    len = ll_len(pArrayListLlamadas);
    printf("Id Llamada   \tfecha\t  Numero de Cliente\t     Problema\t\t    Solucionado\n");
    for(i=0;i<len;i++)
    {
        this =(eLlamada*) ll_get(pArrayListLlamadas,i);
        mostrarEmpleado(this);
    }
}

int FiltrarLlamada(LinkedList* pArrayListLlamadas)
{
    LinkedList* this =NULL;
    int retorno=-1;
    int opcion;
    int len;
    len=ll_len(pArrayListLlamadas);
    if(pArrayListLlamadas!=NULL&&len>0)
    {

        while(getInt(&opcion,"\n1.No enciende PC\n2.No funciona mouse\n3.No funciona teclado\n4.No hay internet\n5.No funciona telefono\n6.Salir\n","Solo puedes ingresar nuemeros entre el [1] y [6]",1,6)!=0);
        switch(opcion)
        {
        case 1:
            this=filter(pArrayListLlamadas,fnId1);
            if(this!=NULL)
            {
            saveAsText("PC.csv",this);
            printf("Archivo: PC.csv\n");
            retorno=1;
            }
            break;
        case 2:
            this=filter(pArrayListLlamadas,fnId2);
            if(this!=NULL)
            {
            saveAsText("MOUSE.csv",this);
            printf("Archivo: MOUSE.csv\n");
            retorno=1;
            }
            break;
        case 3:
            this=filter(pArrayListLlamadas,fnId3);
            if(this!=NULL)
            {
            saveAsText("TECLADO.csv",this);
            printf("Archivo: TECLADO.csv\n");
            retorno=1;
            }
            break;
        case 4:
            this=filter(pArrayListLlamadas,fnId4);
            if(this!=NULL)
            {
            saveAsText("INTERNET.csv",this);
            printf("Archivo: INTERNET.csv\n");
            retorno=1;
            }
            break;
        case 5:
            this=filter(pArrayListLlamadas,fnId5);
            if(this!=NULL)
            {
            saveAsText("TELEFONO.csv",this);
            printf("Archivo es TELEFONO.csv\n");
            retorno=1;
            }
            break;
        case 6:
            printf("Saliendo\n");
            retorno=0;
            break;
        }
    }
    ll_clear(pArrayListLlamadas);
    return retorno;
}


int saveAsText(char* path , LinkedList* pArrayListLlamadas)
{
    FILE* pFile = fopen(path,"w");
    int len;
    int i;
    int retorno = -1;

    if(pFile!=NULL)
    {
        eLlamada* this;

        len = ll_len(pArrayListLlamadas);

        fprintf(pFile,"idLlamada,fecha,numCliente,idProblema,solucionado\n");

        for(i=0;i<len;i++)
        {
            this = ll_get(pArrayListLlamadas,i);
            fprintf(pFile,"%d,%s,%d,%d,%s\n",this->idLlamada,this->fecha,this->numCliente,this->idProblema,this->solucionado);
        }

        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}
