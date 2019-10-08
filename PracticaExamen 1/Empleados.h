#define LIBRE 0
#define OCUPADO 1

typedef struct{

    char nombre[50];
    int nota;
    int legajo;
    int estaVacio;

}eEmpleado;

void inicializarEmpleados(eEmpleado[],int len);
void ingresarDatos(eEmpleado listadoDeEmpleados[],int len);
int indiceLibre(eEmpleado listadoDeEmpleados[],int len);
void MostrarAlumnos(eEmpleado[],int len);
void mostrarUnEmpleado(eEmpleado listadoDeEmpleados[],int len);

int idAuto(eEmpleado listadoDeEmpleados[],int len,int valMenor);
int idMayor(eEmpleado listadoDeEmpleados[],int len,int valMenor);
