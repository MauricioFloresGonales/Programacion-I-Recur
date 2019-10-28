#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* pArchivo;
    /*char miNombre[]="German";

    pArchivo = fopen("miArchivo.txt","w");

    if(pArchivo!=NULL)
    {
        fprintf(pArchivo,"mi nombre es: %s\nEl dia esta nublado\n",miNombre);
        fclose(pArchivo);

    }*/

    //COMO LEO:
    //MODO TEXTO:
    /*pArchivo = fopen("miArchivo.txt","r");
    char miNombre[50];

    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            fgets(miNombre,49,pArchivo);
            printf("%s",miNombre);
        }

        fclose(pArchivo);
    }*/

    //BINARIO:

    /*char miNombre[]="German";

    pArchivo = fopen("miArchivo.bin","wb");

    if(pArchivo!=NULL)
    {
        fwrite(miNombre,sizeof(char),strlen(miNombre),pArchivo);
        fclose(pArchivo);

    }

    //LEER BINARIO:

    pArchivo = fopen("miArchivo.bin","rb");

    if(pArchivo!=NULL)
    {
        fread(miNombre,sizeof(char),strlen(miNombre),pArchivo);
        printf("%s",miNombre);

        fclose(pArchivo);
    }*/

//----------------------------------------------------------------------

/*
    pArchivo = fopen("miArchivo.bin","wb");

    int vector[5]={1,2,3,4,5};
    int i;
    if(pArchivo!=NULL)
    {
        fwrite(vector,sizeof(int),5,pArchivo);
        fclose(pArchivo);

    }

    //LEER BINARIO:

    pArchivo = fopen("miArchivo.bin","rb");

    if(pArchivo!=NULL)
    {
        fread(vector,sizeof(int),5,pArchivo);
        for(i=0;i<5;i++)
        {
            printf("%d",vector[i]);
        }


        fclose(pArchivo);
    }*/

//----------------------------------------------------------------------


    return 0;
}
