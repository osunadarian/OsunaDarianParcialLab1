#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"

void mostrarTipo(eTipo tipo)
{
    printf("             %d        %s\n", tipo.id, tipo.descripcion);
}

int mostrarTipos(eTipo tipo[], int tam_t)
{
    int error = 1;
    if(tipo != NULL && tam_t >0)
    {
        printf("------------------------------------------------\n");
        printf("            *** LISTADO TIPOS ***            \n");
        printf("------------------------------------------------\n");
        printf("              ID        DESCRIPCION\n\n");
        for(int i=0; i<tam_t; i++)
        {
            mostrarTipo(tipo[i]);
        }
        printf("\n\n");
        error = 0;
    }

    return error;
}

int obtenerDescripcionTipo(eTipo tipo[], int tam_t, int idTipo, char descTipo[])
{
    int error = 1;
    if(tipo != NULL && tam_t > 0 && descTipo != NULL)
    {
        for (int i = 0; i<tam_t ; i++)
        {
            if(tipo[i].id == idTipo)
            {
                strcpy(descTipo,tipo[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;

}
