#include <stdio.h>
#include <stdlib.h>
#include "string.h"
/**Realizar un programa que permita manejar una entidad definida por id,
 con por lo menos 2 campos (uno numérico y otro alfanumérico).
Dicho programa deberá trabajar la entidad de manera dinámica,
de acuerdo a las reglas establecidas en la cátedra, permitiendo guardar
en un archivo binario por lo menos dos datos de la entidad en cuestión. Por ultimo leer
del archivo dichos datos y mostrarlos.*/

typedef struct
{
    int id;
    int numero;
    char letra[51];

}eEntidad;

int getId(eEntidad*,int id);
int setId(eEntidad*,int* id);
int getNumero(eEntidad*,int numero);
int setNumero(eEntidad*,int* numero);
int getLetra(eEntidad*,char* letra);
int getLetra(eEntidad*,char* letra);
int constructor(eEntidad*,int*,int*,char*);
int guardarEnArchivo(eEntidad*,int len,char* archivo);
int cargarElArchivo(eEntidad*,char* archivo);
void harcodeo(eEntidad*,int len);
void mostrar(eEntidad*);

int main()
{
    eEntidad entidad[5];
    int opcion;

    harcodeo(entidad,5);

    do{
        printf("1.cargar El Archivo\n");
        printf("2.guardar En Archivo\n") ;
        printf("3.Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarElArchivo(entidad,"archivo.bin");
            break;
        case 2:
            guardarEnArchivo(entidad,5,"archivo.bin");
            break;
        case 3:
            printf("Salir\n");
            break;
        default:
            printf("no ingreso ninguna opcion\n");
            break;
        }
    }while(opcion!=3);


    return 0;
}

int getId(eEntidad* entidad,int id)
{
    int retorno = -1;
    if(entidad!=NULL)
    {
        id = entidad->id;
        retorno = 0;
    }
    return retorno;

}
int setId(eEntidad*entidad,int* id)
{
    int retorno = -1;
    if(entidad!=NULL)
    {
        entidad->id = id;
        retorno = 0;
    }
    return retorno;

}

int getNumero(eEntidad*entidad,int numero)
{
    int retorno = -1;
    if(entidad!=NULL)
    {
        numero = entidad->numero;
        retorno = 0;
    }
    return retorno;
}
int setNumero(eEntidad*entidad,int* numero)
{
    int retorno = -1;
    if(entidad!=NULL)
    {
        entidad->numero = numero;
        retorno = 0;
    }
    return retorno;
}
int getLetra(eEntidad*entidad,char* letra)
{
    int retorno = -1;
    if(entidad!=NULL)
    {
        strcpy(letra,entidad->letra);
        retorno = 0;
    }
    return retorno;
}
int setLetra(eEntidad*entidad,char* letra)
{
    int retorno = -1;
    if(entidad!=NULL)
    {
        strcpy(entidad->letra,letra);
        retorno = 0;
    }
    return retorno;
}

int constructor(eEntidad*entidad,int*id,int*numero,char*palabra)
{
    int retorno = -1;
    if(entidad!=NULL)
    {
        setId(entidad,id);
        setNumero(entidad,numero);
        setLetra(entidad,palabra);
        retorno = 0;
    }
    return retorno;
}

int guardarEnArchivo(eEntidad* entidad,int len,char* archivo)
{
    FILE* pfile = (FILE*)malloc(sizeof(FILE));
    eEntidad* aux = NULL;
    int retorno;
    int i;

    if(pfile != NULL && entidad!=NULL)
    {
        pfile = fopen(archivo,"wb");
        for(i=0;i<len;i++)
        {
            aux = entidad[i];
            mostrar(aux);
            retorno = fwrite(aux,sizeof(eEntidad),1,pfile);
        }
        fclose(pfile);
    }
    return retorno;
}

int cargarElArchivo(eEntidad* entidad,char* archivo)
{
    FILE* pfile = (FILE*)malloc(sizeof(FILE));
    eEntidad* aux;
    int retorno;
    int idAux;
    int numeroAux;
    char palabraAux[51];

    if(pfile != NULL)
    {
        pfile = fopen(archivo,"rb");
        while(!feof(pfile))
        {
            aux = (eEntidad*)malloc(sizeof(eEntidad));
            if(aux!=NULL)
            {
                retorno = fread(aux,sizeof(eEntidad),1,pfile);
                getId(aux,idAux);
                getNumero(aux,numeroAux);
                getLetra(aux,palabraAux);
                constructor(entidad,idAux,numeroAux,palabraAux);
            }
        }
        fclose(pfile);
    }
    return retorno;
}

void harcodeo(eEntidad* entidad,int len)
{
    int idAux[] = {1,2,3,4,5};
    int numeroAux[]={12,13,14,15,16};
    char palabraAux[][51] = {"hola","chau","ooo","mmm","qqqq"};
    int i;

    if(entidad!=NULL)
    {
        for(i=0;i<len;i++)
        {
            entidad = (eEntidad*)malloc(sizeof(eEntidad));
            constructor(entidad,idAux[i],numeroAux[i],palabraAux[i]);
        }
    }
}

void mostrar(eEntidad*entidad)
{
    int id;
    int numero;
    char palabra[51];
    if(entidad!=NULL)
    {
        getId(entidad,id);
        getNumero(entidad,numero);
        getLetra(entidad,palabra);
        printf("%d - %d - %s\n",id,numero,palabra);
    }
}
