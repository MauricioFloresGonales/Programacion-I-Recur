#include <stdio.h>
#include <stdlib.h>
#include "eEntidad.h"
#include "string.h"

eEntidad* entidad_new()
{
    eEntidad* retorno = (eEntidad*)calloc(sizeof(eEntidad),1);

    return retorno;
}

eEntidad* entidad_newParametros(int id, int numero, char* palabra)
{
    eEntidad* retorno = entidad_new();

    if(retorno!=NULL)
    {
        set_id(retorno,id);
        set_numerico(retorno,numero);
        set_AlphaNumerico(retorno,palabra);
    }

    return retorno;
}

int set_id(eEntidad* entidad, int id)
{
    int retorno = -1;
    if(entidad != NULL)
    {
        entidad->id = id;
        retorno = 0;
    }

    return retorno;
}

int get_id(eEntidad*entidad, int* id)
{
    int retorno=-1;
    if(entidad!=NULL && id != NULL)
    {
        *id = entidad->id;
        retorno = 0;
    }
    return retorno;
}

int set_numerico(eEntidad*entidad,int numerico)
{
    int retorno=-1;
    if(entidad!=NULL)
    {
        entidad->numerico = numerico;
        retorno=0;
    }
    return retorno;
}

int get_numerico(eEntidad*entidad, int* numerico)
{
    int retorno=-1;
    if(entidad!=NULL && numerico != NULL)
    {
        *numerico = entidad->numerico;
        retorno = 0;
    }
    return retorno;
}

int set_AlphaNumerico(eEntidad*entidad, char* alphaNumerico)
{
    int retorno=-1;
    if(entidad!=NULL)
    {
        strcpy(entidad->AlphaNumerico, alphaNumerico);
        retorno=0;
    }
    return retorno;
}

int get_AlphaNumerico(eEntidad*entidad, char* alphaNumerico)
{
    int retorno=-1;
    if(entidad!=NULL && alphaNumerico != NULL)
    {
        strcpy(alphaNumerico, entidad->AlphaNumerico);
        retorno = 0;
    }
    return retorno;
}

int mostrar(eEntidad* entidad)
{
    int retorno=-1;
    int idAux;
    int numericoAux;
    char alphaNumericoAux[21];

    if(entidad!=NULL)
    {
        get_id(entidad,&idAux);
        get_numerico(entidad, &numericoAux);
        get_AlphaNumerico(entidad, alphaNumericoAux);
        printf("%d - %d - %s\n", idAux, numericoAux, alphaNumericoAux);
        retorno=0;
    }
    return retorno;
}

int guardarEnBinario(char*path,eEntidad*entidad)
{
    FILE*pfile=fopen(path,"ab");
    int retorno=-1;
    int i;

    if(pfile!=NULL && entidad != NULL)
    {
        fseek(pfile, 0L, SEEK_END);
        fwrite(entidad,sizeof(eEntidad),1,pfile);
        retorno=0;
    }

    fclose(pfile);

    return retorno;
}


int leerEnBinario(char*path)
{
    FILE*pfile = fopen(path,"rb");
    int retorno=-1;

    eEntidad* aux;

    int pudoLeerUno = 0;

    if(pfile!=NULL)
    {
        while(!feof(pfile))
        {
            aux = entidad_new();

            //Valido si es distinto de nulo, porque el constructor por defecto puede retornar un nulo
            if(aux != NULL)
            {

                //Verifico si pudo leer una Entidad (El fread retorna 1 si pudo leer y 0 en caso contrario)
                pudoLeerUno = fread(aux,sizeof(eEntidad),1,pfile);

                printf("pudoLeerUno %d\n", pudoLeerUno);

                //Si la pudo leer la muestro
                if(pudoLeerUno)
                {
                    mostrar(aux);
                }

            }
        }
        retorno=0;
    }

    fclose(pfile);

    return retorno;
}


/*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"rb");
    int retorno = -1;
    Employee* empleado;
    int aux;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            empleado = employee_new();
            aux = fread(empleado,sizeof(Employee),1,pFile);
            if(aux == 1)
            {
                ll_add(pArrayListEmployee,empleado);
            }
        }
        fclose(pFile);
    }else{
        printf("NO Existe\n");
    }
    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"wb");
    int len;
    int i;
    int retorno = -1;

    if(pFile!=NULL)
    {
        Employee* empleado;

        len = ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            fwrite(empleado,sizeof(Employee),1,pFile);
        }

        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}/*

*/
