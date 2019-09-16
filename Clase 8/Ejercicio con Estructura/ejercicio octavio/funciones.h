
typedef struct{

    char nombre[50];
    int nota;
    int legajo;
    int estaVacio;


}eAlumno;

void inicializarAlumno(eAlumno[],int cantidad);
void MostrarAlumnos(eAlumno[],int cantidad);
void mostrarUnAlumno(eAlumno[],int indice);
int dameIndiceLibre(eAlumno[],int cantidad);
