
typedef struct
{
    int idLlamada;
    char fecha[51];
    int numCliente;
    int idProblema;
    char solucionado[3];

}eLlamada;

int get_IdLlamada(eLlamada* llamada,int* id);
int set_IdLlamada(eLlamada* llamada,int id);

int get_Fecha(eLlamada* llamada,char* fecha);
int set_Fecha(eLlamada* llamada,char* fecha);

int get_NumCliente(eLlamada* llamada,int* numCliente);
int set_NumCliente(eLlamada* llamada,int numCliente);

int get_IdProblema(eLlamada* llamada,int* idProblema);
int set_IdProblema(eLlamada* llamada,int idProblema);

int get_Solucionado(eLlamada* llamada,char* solucionado);
int set_Solucionado(eLlamada* llamada,char* solucionado);

eLlamada* llamada_new(void);

int fnId1(void* pElement);
int fnId2(void* pElement);
int fnId3(void* pElement);
int fnId4(void* pElement);
int fnId5(void* pElement);

eLlamada* Llamada_newParametros(char* idLlamadaStr,char* fechaStr,char* numClienteStr,char* idProblemaStr,char* solucionadoStr);

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int parser_LLamadasFromText(FILE* pFile , LinkedList* pArrayListEmployee);

void mostrarEmpleado(eLlamada* this);
void problemas(eLlamada* this);
void mostrarTodosLosLlamados(LinkedList* pArrayListEmployee);

int FiltrarLlamada(LinkedList* pArrayListLlamadas);

int saveAsText(char* path , LinkedList* pArrayListLlamadas);

