#include "persona.h"

ePersona* new_Persona()
{
    ePersona* puntero;

    puntero = (ePersona*)calloc(sizeof(ePersona),1);

    return puntero;
}

ePersona* new_Persona_Parametros(int legajo,char sexo,float altura)
{
    ePersona* p;
    p = new_Persona();

    if(p!=NULL)
    {
        p->legajo = legajo;
        p->sexo = sexo;
        p->altura = altura;
    }

    return p;
}

void setLegajo(ePersona* unaPersona,int legajo)
{
    if(legajo>0)
    {
        unaPersona ->legajo = legajo;
    }
}

int getLegajo(ePersona* unaPersona)
{
    return unaPersona->legajo;
}

void delete_Persona(ePersona* unaPersona)
{
    free(unaPersona);
}

void mostrarPersona(ePersona* unaPersona)
{
    printf("%d--%c--%f",unaPersona->legajo,unaPersona->sexo,unaPersona->altura);
}

