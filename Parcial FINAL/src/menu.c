#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"

void menuOptions()
{
    printf("******************************************************\n");
    printf("            MENU RECAUDACION DE IMPUESTOS\n");
    printf("******************************************************\n\n");
    printf("            [1] - ALTA DE CONTRIBUYENTE\n");
    printf("            [2] - MODIFICAR DATOS DE CONTRIBUYENTE\n");
    printf("            [3] - BAJA DEL CONTRIBUYENTE\n");
    printf("            [4] - ALTA DE RECAUDACION\n");
    printf("            [5] - REFINANCIAR RECAUDACION\n");
    printf("            [6] - SALDAR RECAUDACION\n");
    printf("            [7] - IMPRIMIR CONTRIBUYENTES\n");
    printf("            [8] - IMPRIMIR RECAUDACION\n");
    printf("            [9] - CONTRIBUYENTE CON MAS RECAUDACIONES 'REFINANCIADAS'\n");
    printf("            [10] - RECAUDACIONES 'SALDADAS'\n");
    printf("            [11] - CONTRIBUYENTES POR TIPO\n");
    printf("            [12] - RECAUDACIONES EN FEBRERO\n");
    printf("            [13] - SALIR\n\n\n");
}

void exitProgram(int *exit)
{
	int option;

	printf("\n\n                CONFIRMA SALIDA?\n\n");
	printf("                    [1] - SI \n");
	printf("                    [2] - NO \n\n");
	printf("                  RESPUESTA: ");
	scanf("%d", &option);

	if(option==1)
	{
		*exit = 0;
	}

	printf("\n\n          -> [ SALIDA EXITOSA ] <-\n\n");

}
