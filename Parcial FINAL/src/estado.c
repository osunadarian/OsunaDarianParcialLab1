#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "estado.h"

void mostrarEstado(eEstado estado)
{
    printf("             %d        %s\n", estado.id, estado.descripcion);
}

int mostrarEstados(eEstado estado[], int tam_e)
{
    int error = 1;
    if(estado != NULL && tam_e >0)
    {
        printf("------------------------------------------------\n");
        printf("            *** LISTADO ESTADOS ***            \n");
        printf("------------------------------------------------\n");
        printf("              ID        DESCRIPCION\n\n");
        for(int i=0; i<tam_e; i++)
        {
            mostrarEstado(estado[i]);
        }
        printf("\n\n");
        error = 0;
    }

    return error;
}

int obtenerDescripcionEstado(eEstado estado[], int tam_e, int idEstado, char descEstado[])
{
    int error = 1;
    if(estado != NULL && tam_e > 0 && descEstado != NULL)
    {
        for (int i = 0; i<tam_e ; i++)
        {
            if(estado[i].id == idEstado)
            {
                strcpy(descEstado,estado[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;

}
