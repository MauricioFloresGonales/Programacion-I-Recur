#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char sexo;
    float altura;

}ePersona;

ePersona* new_Persona(); // CONSTRUCTOR POR DEFECTO
ePersona* new_Persona_Parametros(int,char,float);//CONSTRUCTOR PARAMETRISADO

void setLegajo(ePersona*,int);
int getLegajo(ePersona*);

void delete_Persona(ePersona*);
void mostrarPersona(ePersona*);
