#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "recaudacion.h"
#include "contribuyentes.h"
#include "tipo.h"
#include "menu.h"

int inicializarRecaudaciones(eRecaudacion recaudaciones[], int tam_r)
{
    int error = 1;
    if (recaudaciones!=NULL && tam_r > 0)
    {
        for(int i=0; i<tam_r; i++)
        {
        	recaudaciones[i].isEmpty = 1;
        }
        error = 0;
    }

    return error;
}

int buscarEspacio(eRecaudacion recaudaciones[], int tam_r)
{
    int indice = -1;

    for(int i = 0; i < tam_r; i++)
    {
        if(recaudaciones[i].isEmpty == 1)
        {
            indice = 1;
            break;
        }
    }

    return indice;
}

int lugarLibreRec(eRecaudacion recaudaciones[], int tam_r)
{
	int indice;

	indice = -1;

	for(int i=0; i<tam_r; i++)
	{
		if(recaudaciones[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int agregarRecaudacion(eRecaudacion recaudaciones[], int tam_r, int* idRecaudacion, eContribuyente contribuyentes[], int tam_c, eTipo tipo[], int tam_t)
{
	int error;
	int hayContribuyentes;
	int indiceContribuyente;
	int espacioRecaudaciones;

	error = -1;

	eRecaudacion nuevaRecaudacion; //creo variable de tipo eContribuyente

	if(recaudaciones!=NULL && tam_r>0)
	{

		hayContribuyentes = checkContribuyentes(contribuyentes,tam_c);
		indiceContribuyente = lugarLibreRec(recaudaciones,tam_r);
		espacioRecaudaciones = buscarEspacio(recaudaciones,tam_r);

		if(hayContribuyentes==-1)
		{
            printf("\n\n            EL ALTA NO PUEDE REALIZARSE. NO HAY CONTRIBUYENTES DISPONIBLES\n\n\n");
            system("pause");
		}
		else
		{
			if(espacioRecaudaciones==1)
			{
				mostrarContribuyentes(contribuyentes,tam_c);
				printf("        INGRESE EL ID DEL CONTRIBUYENTE: ");
				scanf("%d", &nuevaRecaudacion.idContribuyente);
				indiceContribuyente = encontrarContribuyente(contribuyentes,tam_c,nuevaRecaudacion.idContribuyente);

				if(indiceContribuyente==-1)
				{
					printf("\n\n             X ERROR X\n");
					printf("   NO EXISTEN CONTRIBUYENTES CON ESE ID\n\n\n\n");
				}else
				{

					*idRecaudacion = *idRecaudacion + 1;
					nuevaRecaudacion.id = *idRecaudacion;
					nuevaRecaudacion.isEmpty = 0;

					do
					{

						printf("INGRESE MES: ");
						scanf("%d", &nuevaRecaudacion.mes);

					}while(nuevaRecaudacion.mes<0 || nuevaRecaudacion.mes>12);

					do
					{
						mostrarTipos(tipo,tam_t);
						printf("INGRESE EL ID DEL TIPO DE LA RECAUDACION: ");
						scanf("%d", &nuevaRecaudacion.tipoRecaudacion);

					}while(nuevaRecaudacion.tipoRecaudacion<1 || nuevaRecaudacion.tipoRecaudacion>3);

					do
					{
						printf("INGRESE EL IMPORTE DE LA RECAUDACION: ");
						scanf("%d", &nuevaRecaudacion.importe);

					}while(nuevaRecaudacion.importe>=0);

					*idRecaudacion = *idRecaudacion + 1;
					nuevaRecaudacion.id = *idRecaudacion;
					nuevaRecaudacion.isEmpty = 0;

				}

				recaudaciones[indiceContribuyente] = nuevaRecaudacion;

				printf("\n\n                    ALTA REALIZADA CON EXITO\n\n\n\n");
				system("pause");

				error = 0;
			}else
			{
				printf("\n\n                NO HAY ESPACIO PARA MAS RECAUDACIONES\n\n\n\n");
				system("pause");
			}
		}


	}

	return error;

}
