#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
CHAR NOMBRE[15];
CHAR APELLIDO[15];
CHAR APELLIDOnOMBRE[50]; ------------> Apellido,Nombre
                                       Scarafilo,German
*/

int main()
{

   char palabra[10];
   char otraPalabra[10]= "CHAU";
   int largo;
   int comp1;
   int comp2;

   printf("ingrese una palabra: ");
   fflush(stdin);
   //scanf("%s",palabra);//NO PUEDE GUARDAR ESPACIOS
   //gets(palabra);//SI PUEDE GUARDAR ESPACIOS
   scanf("%[^\n]",palabra);//LEE LOS ESPACIOS --- (^) = SIGNIFICA HASTA
   printf("%s\n",palabra);
//---------------------------------------------------------------------------------
   largo = strlen(palabra);
   printf("el largo es : %d\n",largo);
//---------------------------------------------------------------------------------
    //strcpy(palabra,otraPalabra);
    //printf("%s\n",palabra);
//---------------------------------------------------------------------------------
    comp1 = strcmp(palabra,otraPalabra);//S T R C M P
    printf("la comparacion da: %d\n",comp1);//S T R I C M P

    comp2 = stricmp(palabra,otraPalabra);
    printf("la comparacion da: %d\n",comp2);
//---------------------------------------------------------------------------------
    strupr(palabra);
    printf("%s\n",palabra);

    strlwr(palabra);
    printf("%s\n",palabra);
//---------------------------------------------------------------------------------
    strcat(palabra,otraPalabra);
    printf("la concatenacion es: %s",palabra);




    return 0;
}
