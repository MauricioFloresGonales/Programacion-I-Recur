#include <stdio.h>
#include <string.h>

void pedirNombre(char mensaje[],char nombre[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",nombre);
}

void mostrarNombre(char nombre[])
{
    printf("%s\n",nombre);
}
