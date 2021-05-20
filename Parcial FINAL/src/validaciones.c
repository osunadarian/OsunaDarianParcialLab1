#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"

void formatearString(char string[])
{
    int i = 0;
    while (string[i])
    {
    	string[i] = tolower(string[i]);
        i++;
    }
    string[0] = toupper(string[0]);
}

int validarCadena(char cadena[])
{
    int error = 0;

    for(int i=0; i<strlen(cadena); i++)
    {
        if(!((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]>=97 && cadena[i]<=122)))
        {
            error = 1;
        }
    }
    if(error)
    {
        printf("\n                 ERROR! INGRESE SOLO LETRAS.\n");
    }

    return error;
}
