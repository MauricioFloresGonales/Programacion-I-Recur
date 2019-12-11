#include "carrera.h"

int get_Id(eCarrera* this,int* id)
{
    int retorno = -1;
    if(this!=NULL&&id!=NULL)
    {
        *id = this->ID_BIKE;
        retorno = 0;
    }
    return retorno;
}

int set_Id(eCarrera* this,int id)
{
    int retorno = -1;
    if(this!=NULL&&id>0)
    {
        this->ID_BIKE = id;
        retorno = 0;
    }
    return retorno;
}
//------------------------------------------------------------

int get_Nombre(eCarrera* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,this->NOMBRE);
        retorno = 0;
    }
    return retorno;
}

int set_Nombre(eCarrera* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL&&nombre>0)
    {
        strcpy(this->NOMBRE,nombre);
        retorno = 0;
    }
    return retorno;
}

//------------------------------------------------------------

int get_Tipo(eCarrera* this,char* tipo)
{
    int retorno = -1;
    if(this!=NULL&&tipo!=NULL)
    {
        strcpy(tipo,this->TIPO);
        retorno = 0;
    }
    return retorno;
}

int set_Tipo(eCarrera* this,char* tipo)
{
    int retorno = -1;
    if(this!=NULL&&tipo>0)
    {
        strcpy(this->TIPO,tipo);
        retorno = 0;
    }
    return retorno;
}
//------------------------------------------------------------
int get_tiempo(eCarrera* this,int* tiempo)
{
    int retorno = -1;
    if(this!=NULL&&tiempo!=NULL)
    {
        *tiempo = this->TIEMPO;
        retorno = 0;
    }
    return retorno;
}

int set_tiempo(eCarrera* this,int tiempo)
{
    int retorno = -1;
    if(this!=NULL&&tiempo>=0)
    {
        this->TIEMPO = tiempo;
        retorno = 0;
    }
    return retorno;
}

eCarrera* entidad_new(void)
{
    eCarrera* this = (eCarrera*)malloc(sizeof(eCarrera));
    if(this!=NULL)
    {
        set_Id(this,0);
        set_Nombre(this,"");
        set_Tipo(this,"");
        set_tiempo(this,0);
    }

    return this;
}

eCarrera* entidad_newParametros(char* idStr,char*nombreStr,char* tipoStr,char* tiempoStr)
{
    eCarrera* this = entidad_new();

    if(idStr!=NULL&&tipoStr!=NULL&&tiempoStr!=NULL)
    {
        if(this!=NULL)
        {
            set_Id(this,atoi(idStr));
            set_Nombre(this,nombreStr);
            set_Tipo(this,tipoStr);
            set_tiempo(this,atoi(tiempoStr));
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
        eCarrera* this = NULL;
        char idCarrera[51];
        char nombre[51];
        char idTipo[51];
        char tiempo[51];

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idCarrera,nombre,idTipo, tiempo);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idCarrera,nombre,idTipo, tiempo);
            this = entidad_newParametros(idCarrera,nombre,idTipo,tiempo);
            ll_add(pArrayListLlamadas,this);

        }

        retorno = 0;
    }
    return retorno;
}

void mostrarEntidad(eCarrera* this)
{
    int idCarrera;
    char nombre[51];
    char tipo[51];
    int tiempo;

    if(this!=NULL)
    {
        get_Id(this,&idCarrera);
        get_Nombre(this,nombre);
        get_Tipo(this,tipo);
        get_tiempo(this,&tiempo);


        printf("%5d\t",idCarrera);
        printf("%-5s\t",nombre);
        printf("%-5s\t",tipo);
        printf("%6d\n",tiempo);

    }
}

void mostrarTodasLasEntidades(LinkedList* pArrayListLlamadas)
{
    eCarrera* this;
    int len;
    int i;
    if(pArrayListLlamadas!= NULL)
    {
        len = ll_len(pArrayListLlamadas);
        //printf("Id Bike\tNombre\tTipo\t Tiempo\t\n");

        for(i=0;i<len;i++)
        {
            this =(eCarrera*) ll_get(pArrayListLlamadas,i);
            mostrarEntidad(this);
        }
    }
}

void* aleatorio(void* pElement)
{
    int aleatorio;
    if(pElement!=NULL)
    {
        aleatorio = rand()%(71)+50;
        set_tiempo(pElement,aleatorio);
    }
    return pElement;
}

int soloBmx(void* pElement)
{
    int compara = 0;
    eCarrera* this=(eCarrera*)pElement;
    char bicicleta[51];
    get_Tipo(this,bicicleta);

    if(stricmp(bicicleta,"BMX")==0)
    {
        compara=1;
    }
    return compara;
}

int soloPlayera(void* pElement)
{
    int compara = 0;
    eCarrera* this=(eCarrera*)pElement;
    char bicicleta[51];
    get_Tipo(this,bicicleta);

    if(stricmp(bicicleta,"PLAYERA")==0)
    {
        compara=1;
    }
    return compara;
}
int soloMtb(void* pElement)
{
    int compara = 0;
    eCarrera* this=(eCarrera*)pElement;
    char bicicleta[51];
    get_Tipo(this,bicicleta);

    if(stricmp(bicicleta,"MTB")==0)
    {
        compara=1;
    }
    return compara;
}
int soloPaseo(void* pElement)
{
    int compara = 0;
    eCarrera* this=(eCarrera*)pElement;
    char bicicleta[51];
    get_Tipo(this,bicicleta);

    if(stricmp(bicicleta,"PASEO")==0)
    {
        compara=1;
    }
    return compara;
}

void filtroPorTipo(LinkedList* pArrayListBicicletas)
{
    LinkedList* aux = NULL;
    int opcion;
    aux = ll_clone(pArrayListBicicletas);
    while(getInt(&opcion,"1.Solo BMX\n2.Solo PLAYERA\n3.Solo MTB\n4.Solo PASEO\nElija una opcion: ","Solo puede ingresar numeros del[1] al [4]",1,4)!=0);

    switch(opcion)
        {
    case 1:
           aux= filter(pArrayListBicicletas,soloBmx);
        controller_saveAsText("BMX.csv" , aux);
            break;
        case 2:
             aux=filter(pArrayListBicicletas,soloPlayera);
            controller_saveAsText("PLAYERA.csv", aux);
            break;
        case 3:
            aux= filter(pArrayListBicicletas,soloMtb);
            controller_saveAsText("MTB.csv" ,aux);
            break;
        default:
            aux= filter(pArrayListBicicletas,soloPaseo);
            controller_saveAsText("PASEO.csv",aux);
            break;
    }
    mostrarTodasLasEntidades(aux);
}

int ordenarPos(void* unaBici,void* otraBici)
{
    int compara;
    eCarrera* biciUno =(eCarrera*)unaBici;
    eCarrera* biciDos = (eCarrera*)otraBici;

    int tiempoUno;
    int tiempoDos;

    get_tiempo(biciUno,&tiempoUno);
    get_tiempo(biciDos,&tiempoDos);

    if(tiempoUno > tiempoDos)
    {
        compara = 1;
    }else{
        if(tiempoUno==tiempoDos)
        {
            compara = 0;
        }
    }
    return compara;
}

void posciones(LinkedList* pArrayListBicicletas)
{
    LinkedList* aux1 = NULL;
    LinkedList* aux2 = NULL;
    LinkedList* aux3 = NULL;
    LinkedList* aux4 = NULL;


    aux1= filter(pArrayListBicicletas,soloBmx);
    aux2=filter(pArrayListBicicletas,soloPlayera);
    aux3= filter(pArrayListBicicletas,soloMtb);
    aux4= filter(pArrayListBicicletas,soloPaseo);
    ll_sort(aux1,ordenarPos,1);
    ll_sort(aux2,ordenarPos,1);
    ll_sort(aux3,ordenarPos,1);
    ll_sort(aux4,ordenarPos,1);
    mostrarTodasLasEntidades(aux1);
    mostrarTodasLasEntidades(aux2);
    mostrarTodasLasEntidades(aux3);
    mostrarTodasLasEntidades(aux4);
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"w+");
    int len;
    int i;
    int retorno = -1;

    if(pFile!=NULL)
    {
        eCarrera* carrera;

        len = ll_len(pArrayListEmployee);

        fprintf(pFile,"id_bike,nombre,tipo,tiempo\n");

        for(i=0;i<len;i++)
        {
            carrera = ll_get(pArrayListEmployee,i);
            fprintf(pFile,"%d,%s,%s,%d\n",carrera->ID_BIKE,carrera->NOMBRE,carrera->TIPO,carrera->TIEMPO);
        }

        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}
