#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pVec;
    int* auxVec;

    int i;

    pVec = (int*)malloc(sizeof(int)*5);

    for(i=0; i<5; i++)
    {
        *(pVec+i) = i+1;
    }

    for(i=0; i<5; i++)
    {
        printf("%d\n",*(pVec+i));
    }

//------------------------------------------------------------------------------------------------------------------------------------------

    //para agrandar elvector

    auxVec = (int*)realloc(pVec,sizeof(int)*10);

    if(auxVec != NULL)
    {
        pVec = auxVec;
        for(i=5; i<10; i++)
        {
            printf("Ingrese otros numeros: ");
            scanf("%d",pVec+i);
        }

        for(i=0; i<10; i++)
        {
            printf("%d\n",*(pVec+i));
        }

    }

//------------------------------------------------------------------------------------------------------------------------------------------

    //PARA BORRAR ESPACIOS

    printf("Lo achico\n");

    pVec = (int*)realloc(pVec,sizeof(int)*4);

    if(pVec != NULL)
    {

        for(i=0; i<10; i++)
        {
            printf("%d\n",*(pVec+i));
        }

    }




    return 0;
}
