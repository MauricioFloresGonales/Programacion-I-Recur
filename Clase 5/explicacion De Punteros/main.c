#include <stdio.h>
#include <stdlib.h>
/*
int funcion();

int main()
{
    int numero=4;
    printf("El numero antes de modificar es: %d\n",numero);
    numero = funcion();
    printf("El numero despues de modificar es: %d\n",numero);
    return 0;
}

int funcion()
{
        int numero;
        numero 100;
        return numero;
}*/



/*
void funcion(int*);

int main()
{
    int numero=4;
    printf("El numero antes de modificar es: %d\n",numero);
    funcion(&numero);
    printf("El numero despues de modificar es: %d\n",numero);
    return 0;
}

void funcion(int* numero)
{
    numero= 100;
}*/




/*

void funcion(int*);

int main()
{
    int numero=4;
    printf("El numero antes de modificar es: %d\n",numero);
    funcion(&numero);
    printf("El numero despues de modificar es: %d\n",numero);
    return 0;
}

void funcion(int* numero)
{
    *numero= 100;
}*/






void funcion(int*);

int main()
{
    int numero=4;
    printf("El numero antes de modificar es: %d\n",numero);
    funcion(&numero);
    printf("El numero despues de modificar es: %d\n",numero);
    return 0;
}

void funcion(int* numero)
{
    printf("ingreseun numero: ");
    scanf("%d", numero);
}



