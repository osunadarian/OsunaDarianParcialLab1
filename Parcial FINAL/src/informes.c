#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "contribuyentes.h"
#include "recaudacion.h"
#include "tipo.h"
#include "menu.h"
#include "estado.h"
#include "validaciones.h"
#include "informes.h"

int mayorRecaudaciones(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	int error = -1;
	int id;
	int flag=0;
	int contador = 0;
	int contribuyenteConMayorRec;

	if(contribuyentes!=NULL && tam_c>0)
	{
		for(int i=0;i<tam_c;i++)
		{
			if(contribuyentes[i].isEmpty==0)
			{
				id = contribuyentes[i].idContribuyente;

				for(int j=0;j<tam_r;j++)
				{
					if(recaudaciones[j].isEmpty==0 && recaudaciones[j].estadoRecaudacion==3 && recaudaciones[j].idContribuyente == id)
					{
						contador++;
					}
				}

				if(contador>flag)
				{
					contribuyenteConMayorRec = id;
				}
			}
		}

		printf("El contribuyente con mayor recaudaciones financiadas es el numero %d\n", contribuyenteConMayorRec);

	}

	return error;
}

int recaudacionesSuperiores(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	int error = -1;

	if(recaudaciones!=NULL && tam_r>0)
	{
		for(int i=0;i<tam_r;i++)
		{
			if(recaudaciones[i].importe>=1000)
			{
				printf("\n       ID REC        ID CONTRIBUYENTE        IMPORTE           MES            TIPO            ESTADO ");
				printf("\n--------------------------------------------------------------------------------------------------------\n");

				if(recaudaciones[i].estadoRecaudacion==2)
				{
			        mostrarUnaRecaudacion(recaudaciones[i], tipos, tam_t, estados, tam_e);
				}
			}
		}
	}

	return error;

}

int recaudacionesXtipo(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{

	int error = -1;
	int option;
	int flag=1;

	if(recaudaciones!=NULL && tam_r>0)
	{
		printf("POR FAVOR, INGRESE UN TIPO DE DATO\n");
		printf("1- ARBA\n");
		printf("2- IIBB\n");
		printf("3- GANANCIAS\n");
		printf("TIPO DE RECAUDACION: ");
		scanf("%d", &option);


		for(int i=0;i<tam_r;i++)
		{
			if(recaudaciones[i].isEmpty == 0 && option == recaudaciones[i].tipoRecaudacion)
			{
		        printf("\n       ID REC        ID CONTRIBUYENTE        IMPORTE           MES            TIPO            ESTADO ");
		        printf("\n--------------------------------------------------------------------------------------------------------\n");
				mostrarUnaRecaudacion(recaudaciones[i], tipos, tam_t, estados, tam_e);
				flag=0;
			}
		}

		if(flag==1)
		{
			printf("	  NO SE ENCONTRARON RECAUDACIONES DE ESE TIPO\n");
		}

	}

	return error;
}

int impuestosPorMes(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	int error = -1;
	int id;

	if(recaudaciones!=NULL && tam_r>0)
	{

		for(int i=0;i<tam_r;i++)
		{
			if(recaudaciones[i].mes == 2 && recaudaciones[i].isEmpty==0)
			{
				id = recaudaciones[i].idContribuyente;
				mostrarContribuyentePorId(contribuyentes,tam_c,id);
			}
		}
	}

	return error;
}
