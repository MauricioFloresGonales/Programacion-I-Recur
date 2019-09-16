#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nombre[50];
    int nota;
    int legajo;
    int estaVacio;//1 PARA NO - 0 SI ESTA VACIO ---- ESTO FUE AGREFADO APARTIR DEL TERCER EJEMPLO


}eAlumno;

void inicializarAlumno(eAlumno[],int cantidad);
void MostrarAlumnos(eAlumno[],int cantidad);
void mostrarUnAlumno(eAlumno[],int indice);
int dameIndiceLibre(eAlumno[],int cantidad);

int main()
{
    /*
    int numero;
    eAlumno unAlumno;


    scanf("%d",&numero);
    printf("el numero es: %d\n",numero);

    scanf("%s",unAlumno.nombre);
    printf("el nombre es: %s\n",unAlumno.nombre);

    scanf("%d",&unAlumno.nota);
    printf("la nota es: %d\n",unAlumno.nota);

    scanf("%d",&unAlumno.legajo);
    printf("el legajo es: %d\n",unAlumno.legajo);

    */

//-------------------------------------------------------------------------------------------------------------

    //testeo de copia entre dos esstructuras.
    /*
    eAlumno unAlumno;
    eAlumno otroAlumno;

    printf("ingrese nombre: \n");
    scanf("%s",unAlumno.nombre);
    printf("ingrese nota: \n");
    scanf("%d",&unAlumno.nota);
    printf("ingrese legajo: \n");
    scanf("%d",&unAlumno.legajo);

    otroAlumno = unAlumno;

    printf("el nombre es: %s\n",otroAlumno.nombre);
    printf("la nota es: %d\n",otroAlumno.nota);
    printf("el legajo es: %d\n",otroAlumno.legajo);

    */
//-------------------------------------------------------------------------------------------------------------

    eAlumno listadoDeAlumnos[5];

    inicializarAlumno(listadoDeAlumnos,5);
    MostrarAlumnos(listadoDeAlumnos,5);






    return 0;
}

 void inicializarAlumno(eAlumno listadoDeAlumnos[],int cantidad)
 {
     int i;
     for(i=0;i<cantidad;i++)
     {
         listadoDeAlumnos[i].estaVacio = 0;
     }
 }
void MostrarAlumnos(eAlumno listadoDeAlumnos[],int cantidad)
{
    int flag = 0;
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(listadoDeAlumnos[i].estaVacio == 0)
        {
            flag = 1;
            mostrarUnAlumno(listadoDeAlumnos,i);
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos pramostrar\n");
    }
}

void mostrarUnAlumno(eAlumno unAlumno[],int indice)
{
    printf("%d",unAlumno[indice].nota);
    printf("%d",unAlumno[indice].legajo);
    printf("%s",unAlumno[indice].nombre);
}




