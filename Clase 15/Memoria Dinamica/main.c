#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char sexo;
    float altura;

}ePersona;

ePersona* new_Persona();

int main()
{
    ePersona* puntero = new_Persona();

    if(puntero != NULL)
    {
        printf("La persona es: \n");//      ESTA ES LAFORMA SEGURA DE HACERLO
        printf("%d--%c--%f",puntero->legajo,puntero->sexo,puntero->altura);
    }
/*
    printf("La persona es: \n");//Este printf hace que el dato de la funcion new_Persona ya que los datos de la funcion fue pisado

    printf("%d--%c--%f",puntero->legajo,puntero->sexo,puntero->altura);
*/


    return 0;
}

/*
ePersona* new_Persona()
{
    ePersona unaPersona = {1000,'M',1.78};
    ePersona* puntero;
                                            //con esta funcion se produce el error
    puntero = &unaPersona;

    return puntero;
}*/



ePersona* new_Persona()
{
    ePersona* puntero;

    puntero = (ePersona*)malloc(sizeof(ePersona));
                                                //con este ya no se produce el error
    if(puntero != NULL)
    {
        puntero->legajo = 1000;
        puntero->sexo = 'M';
        puntero->altura = 1.79;
    }




    return puntero;
}
