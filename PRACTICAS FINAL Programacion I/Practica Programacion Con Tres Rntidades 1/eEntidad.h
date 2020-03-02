
typedef struct
{
    int id;
    int numerico;
    char AlphaNumerico[51];

}eEntidad;

eEntidad* entidad_new();
eEntidad* entidad_newParametros(int,int,char*);

int set_id(eEntidad*,int);
int get_id(eEntidad*, int*);
int set_numerico(eEntidad*,int);
int get_numerico(eEntidad*,int*);
int set_AlphaNumerico(eEntidad*,char*);
int get_AlphaNumerico(eEntidad*, char*);


//int harcodeo(eEntidad**,int len);
int mostrar(eEntidad*);

int leerEnBinario(char*path);
int guardarEnBinario(char*path,eEntidad*entidad);
/*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinaryAux(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);*/
