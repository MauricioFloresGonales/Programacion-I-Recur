#include "persona.h"

int main()
{
    ePersona* puntero = new_Persona_Parametros(1000,'M',1.79);
    setLegajo(puntero,1001);
    if(puntero != NULL)
    {
        printf("La persona es: \n");
        if(getLegajo(puntero)>1000);
        mostrarPersona(puntero);             //                         SEGUNDA PARTE
    }

    delete_Persona(puntero);
    return 0;
}

