#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "recaudacion.h"
#include "contribuyentes.h"
#include "tipo.h"
#include "menu.h"
#include "estado.h"

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

int checkRecaudaciones(eRecaudacion recaudaciones[], int tam_r)
{
	int error = -1;

	for(int i = 0; i < tam_r; i++)
	    {
	        if(recaudaciones[i].isEmpty == 0)
	        {
	            error = 1;
	            break;
	        }
	    }

	return error;

}

int agregarRecaudacion(eRecaudacion recaudaciones[], int tam_r, int* idRecaudacion, eContribuyente contribuyentes[], int tam_c, eTipo tipo[], int tam_t, eEstado estados[], int tam_e)
{
	int error;
	int indiceContribuyente;
	int espacioRecaudaciones;
	int contribuyente;

	error = -1;

	eRecaudacion nuevaRecaudacion; //creo variable de tipo eContribuyente

	if(recaudaciones!=NULL && tam_r>0)
	{
		indiceContribuyente = lugarLibreRec(recaudaciones,tam_r);
		espacioRecaudaciones = buscarEspacio(recaudaciones,tam_r);

		if(espacioRecaudaciones==1)
		{
			mostrarContribuyentes(contribuyentes,tam_c);
			printf("        INGRESE EL ID DEL CONTRIBUYENTE: ");
			scanf("%d", &nuevaRecaudacion.idContribuyente);

			contribuyente = encontrarContribuyente(contribuyentes,tam_c,nuevaRecaudacion.idContribuyente);

			if(contribuyente==-1)
			{
				printf("\n\n             X ERROR X\n");
				printf("   NO EXISTEN CONTRIBUYENTES CON ESE ID\n\n\n\n");
			}else
			{
				nuevaRecaudacion.id = *idRecaudacion;
				*idRecaudacion = *idRecaudacion + 1; //aumentamos en 1 el id

				nuevaRecaudacion.isEmpty = 0; //campo con datos
				nuevaRecaudacion.estadoRecaudacion = 1;

				do
				{
					printf("------------------------------\n");
					printf("		INGRESE MES: \n\n");
					printf("		Enero      -> 1\n");
					printf("		Febrero    -> 2\n");
					printf("		Marzo      -> 3\n");
					printf("		Abril      -> 4\n");
					printf("		Mayo       -> 5\n");
					printf("		Junio      -> 6\n");
					printf("		Julio      -> 7\n");
					printf("		Agosto     -> 8\n");
					printf("		Septiembre -> 9\n");
					printf("		Octubre    -> 10\n");
					printf("		Noviembre  -> 11\n");
					printf("		Diciembre  -> 12\n");
					printf("\n\n\n		MES SELECCIONADO: ");
					scanf("%d", &nuevaRecaudacion.mes);

					if(nuevaRecaudacion.mes<0 || nuevaRecaudacion.mes>12)
					{
						printf("\nERROR! EL NUMERO INGRESADO NO CORRESPONDE CON NINGUN MES.\n");
					}

				}while(nuevaRecaudacion.mes<0 || nuevaRecaudacion.mes>12);

				do
				{
					printf("\n\n\n");
					mostrarTipos(tipo,tam_t);
					printf("INGRESE EL ID DEL TIPO DE LA RECAUDACION: ");
					scanf("%d", &nuevaRecaudacion.tipoRecaudacion);

				}while(nuevaRecaudacion.tipoRecaudacion<1 || nuevaRecaudacion.tipoRecaudacion>3);

				do
				{
					printf("INGRESE EL IMPORTE DE LA RECAUDACION: $");
					scanf("%d", &nuevaRecaudacion.importe);

					if(nuevaRecaudacion.importe<0)
					{
						printf("\nERROR! EL IMPORTE NO PUEDE SER NEGATIVO.\n");
					}

				}while(nuevaRecaudacion.importe<0);

				recaudaciones[indiceContribuyente] = nuevaRecaudacion;

				printf("\n\n                    ALTA REALIZADA CON EXITO\n\n\n\n");
				system("pause");

				error = 0;
			}
		}else
		{
			printf("\n\n\n      ERROR. NO HAY MAS ESPACIO PARA NUEVAS CONTRIBUCIONES\n\n\n\n");
		}

	}

	return error;

}

int encontrarRecaudacion(eRecaudacion recaudaciones[], int tam_r, int idRec)
{
	int indice = -1;

	for(int i=0; i<tam_r; i++)
	{
		if(recaudaciones[i].id == idRec && recaudaciones[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

void mostrarUnaRecaudacion(eRecaudacion recaudaciones, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{

	char descripcionTipo[20];
	char descripcionEstado[20];

	if(obtenerDescripcionTipo(tipos,tam_t,recaudaciones.tipoRecaudacion,descripcionTipo)==0 &&
			obtenerDescripcionEstado(estados,tam_e,recaudaciones.estadoRecaudacion,descripcionEstado)==0)
	{
		printf("	 %d              %d                 $%-4d	        %-2d          %-8s        %-10s\n",
				recaudaciones.id,
				recaudaciones.idContribuyente,
				recaudaciones.importe,
				recaudaciones.mes,
				descripcionTipo,
				descripcionEstado);
	}

}

int mostrarRecaudaciones(eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e){

    int error = 1;

    if( recaudaciones != NULL && tam_r > 0)
    {
        printf("--------------------------------------------------------------------------------------------------------");
        printf("\n       ID REC        ID CONTRIBUYENTE        IMPORTE           MES            TIPO            ESTADO ");
        printf("\n--------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam_r; i++)
        {
            if(recaudaciones[i].isEmpty == 0)
            {
            	mostrarUnaRecaudacion(recaudaciones[i], tipos, tam_t, estados, tam_e);
            }
        }

        printf("\n\n");

        error = 0;
    }

    return error;

}

int mostrarRecaudacionesSinFinanciar(eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e){

    int error = 1;

    if( recaudaciones != NULL && tam_r > 0)
    {
        printf("--------------------------------------------------------------------------------------------------------");
        printf("\n       ID REC        ID CONTRIBUYENTE        IMPORTE           MES            TIPO            ESTADO ");
        printf("\n--------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam_r; i++)
        {
            if(recaudaciones[i].isEmpty == 0 && recaudaciones[i].estadoRecaudacion != 3)
            {
            	mostrarUnaRecaudacion(recaudaciones[i], tipos, tam_t, estados, tam_e);
            }
        }

        printf("\n\n");

        error = 0;
    }

    return error;

}

int mostrarRecaudacionesSinSaldar(eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e){

    int error = 1;

    if( recaudaciones != NULL && tam_r > 0)
    {
        printf("--------------------------------------------------------------------------------------------------------");
        printf("\n       ID REC        ID CONTRIBUYENTE        IMPORTE           MES            TIPO            ESTADO ");
        printf("\n--------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam_r; i++)
        {
            if(recaudaciones[i].isEmpty == 0 && recaudaciones[i].estadoRecaudacion != 2)
            {
            	mostrarUnaRecaudacion(recaudaciones[i], tipos, tam_t, estados, tam_e);
            }
        }

        printf("\n\n");

        error = 0;
    }

    return error;

}

int mostrarRecaudacionesPorId(eRecaudacion recaudaciones[], int tam_r, int id, eTipo tipos[], int tam_t, eEstado estados[], int tam_e){

    int error = 1;

    if( recaudaciones != NULL && tam_r > 0)
    {
        printf("--------------------------------------------------------------------------------------------------------");
        printf("\n       ID REC        ID CONTRIBUYENTE        IMPORTE           MES            TIPO            ESTADO ");
        printf("\n--------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam_r; i++)
        {
            if(recaudaciones[i].idContribuyente == id && recaudaciones[i].isEmpty == 0)
            {
            	mostrarUnaRecaudacion(recaudaciones[i],tipos,tam_t,estados,tam_e);
            }
        }

        printf("\n\n");

        error = 0;
    }

    return error;

}

int refinanciarRecaudacion(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{

	int error = 1;
	int indice;
	int id;
	int opcion;

	if(recaudaciones!=NULL && tam_r > 0 && tipos!=NULL && tam_t > 0 && estados!=NULL && tam_e>0 && contribuyentes!=NULL && tam_c > 0)
	{

		mostrarRecaudacionesSinFinanciar(recaudaciones,tam_r,tipos,tam_t,estados,tam_e);
		printf("\n\n\nPOR FAVOR, DIGITE EL ID DE LA RECAUDACION A REFINANCIAR: ");
		scanf("%d", &id);
		indice = encontrarRecaudacion(recaudaciones,tam_r,id);

		if(indice==-1)
		{
            printf("\n\n                     X ERROR X\n");
            printf("            NO EXISTE UNA RECAUDACION CON ESE ID\n\n\n\n");
		}else
		{
			printf("\n\n\n");
			mostrarContribuyentePorId(contribuyentes,tam_c,id);
			printf("\n\n");
			printf("CONFIRMA LA REFINANCIACION DE LA RECAUDACION?\n\n");
			printf("[1] - SI\n");
			printf("[2] - NO\n\n");
			printf("OPCION ELEGIDA: ");
			scanf("%d", &opcion);

			if(opcion==1)
			{
				recaudaciones[indice].estadoRecaudacion = 3;
				error = 0;
			}else if(opcion==2)
			{
				printf("\n\nREFINANCIACION CANCELADA POR EL USUARIO");
			}else
			{
				printf("\n\nOPCION INCORRECTA. VUELVA A INTENTARLO");
			}
		}
	}

	return error;

}

int saldarRecaudacion(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{

	int error = 1;
	int indice;
	int id;
	int opcion;

	if(recaudaciones!=NULL && tam_r > 0 && tipos!=NULL && tam_t > 0 && estados!=NULL && tam_e>0 && contribuyentes!=NULL && tam_c > 0)
	{

		mostrarRecaudacionesSinSaldar(recaudaciones,tam_r,tipos,tam_t,estados,tam_e);
		printf("\n\n\nPOR FAVOR, DIGITE EL ID DE LA RECAUDACION A SALDAR: ");
		scanf("%d", &id);
		indice = encontrarRecaudacion(recaudaciones,tam_r,id);

		if(indice==-1)
		{
            printf("\n\n                     X ERROR X\n");
            printf("            NO EXISTE UNA RECAUDACION CON ESE ID\n\n\n\n");
		}else
		{
			printf("\n\n\n");
			mostrarContribuyentePorId(contribuyentes,tam_c,id);
			printf("\n\n");
			printf("CONFIRMA SALDAR LA RECAUDACION?\n\n");
			printf("[1] - SI\n");
			printf("[2] - NO\n\n");
			printf("OPCION ELEGIDA: ");
			scanf("%d", &opcion);

			if(opcion==1)
			{
				recaudaciones[indice].estadoRecaudacion = 2;
				error = 0;

			}else if(opcion==2)
			{
				printf("\n\nACCION CANCELADA POR EL USUARIO");
			}else
			{
				printf("\n\nOPCION INCORRECTA. VUELVA A INTENTARLO");
			}
		}

	}

	return error;

}

int imprimirRecaudaciones(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	int error = -1;
	int idCont;
	int flag = 0;
	int encabezados;

	if(recaudaciones!=NULL && tam_r > 0 && tipos!=NULL && tam_t > 0 && estados!=NULL && tam_e>0 && contribuyentes!=NULL && tam_c > 0)
	{
		for(int i=0; i<tam_c; i++)
		{
			encabezados = 0;
			flag = 0;
			idCont = contribuyentes[i].idContribuyente; //aca valdria 1000

			for(int j=0;j<tam_r;j++) //recorre recaudaciones
			{
				if(recaudaciones[j].isEmpty == 0 && recaudaciones[j].estadoRecaudacion == 2 && idCont == recaudaciones[j].idContribuyente)
				{
					if(encabezados==0)
					{
						printf("\n\n********************************************************************************************************************\n");
						printf("\n       ID REC        ID CONTRIBUYENTE        IMPORTE           MES            TIPO            ESTADO ");
						printf("\n--------------------------------------------------------------------------------------------------------\n");
					}
					mostrarUnaRecaudacion(recaudaciones[j], tipos, tam_t, estados, tam_e);
					flag = recaudaciones[j].idContribuyente;
					encabezados=1;
				}
			}
			if(flag!=0)
			{
				printf("\n                 ID                 NOMBRE                   APELLIDO                   CUIL");
				printf("\n--------------------------------------------------------------------------------------------------------\n");
				mostrarUnContribuyente(contribuyentes[i]);
				printf("\n********************************************************************************************************************\n");
			}

			printf("\n");
		}
	}

	return error;

}

int recaudacionesSinFinanciar(eRecaudacion recaudaciones[], int tam_r)
{
	int error = -1;

	for(int i = 0; i < tam_r; i++)
	    {
	        if(recaudaciones[i].isEmpty == 0 && recaudaciones[i].estadoRecaudacion != 3)
	        {
	            error = 1;
	            break;
	        }
	    }

	return error;
}

int recaudacionesSinSaldar(eRecaudacion recaudaciones[], int tam_r)
{
	int error = -1;

	for(int i = 0; i < tam_r; i++)
	    {
	        if(recaudaciones[i].isEmpty == 0 && recaudaciones[i].estadoRecaudacion != 2)
	        {
	            error = 1;
	            break;
	        }
	    }

	return error;
}

void validarOpcionCinco(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	if(checkContribuyentes(contribuyentes,tam_c)==1)
	{
		if(recaudacionesSinFinanciar(recaudaciones,tam_r)==1)
		{
			refinanciarRecaudacion(recaudaciones,tam_r,contribuyentes,tam_c,tipos,tam_t,estados,tam_e);

		}else
		{
			printf("\n\n\n      TODAS LAS CONTRIBUCIONES EXISTENTES YA ESTAN FINANCIADAS\n\n\n\n");
		}

	}else
	{
		printf("\n\n\n      ERROR. NO HAY RECAUDACIONES CARGADAS EN EL SISTEMA\n\n\n\n");
	}

}

void validarOpcionSeis(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	if(checkContribuyentes(contribuyentes,tam_c)==1)
	{
		if(recaudacionesSinSaldar(recaudaciones,tam_r)==1)
		{
			saldarRecaudacion(recaudaciones,tam_r,contribuyentes,tam_c,tipos,tam_t,estados,tam_e);

		}else
		{
			printf("\n\n\n      TODAS LAS CONTRIBUCIONES EXISTENTES YA ESTAN FINANCIADAS\n\n\n\n");
		}

	}else
	{
		printf("\n\n\n      ERROR. NO HAY RECAUDACIONES CARGADAS EN EL SISTEMA\n\n\n\n");
	}

}

void validarOpcionOcho(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	if(checkRecaudaciones(recaudaciones,tam_r)==1)
	{
		imprimirRecaudaciones(recaudaciones,tam_r,contribuyentes,tam_c,tipos,tam_t,estados,tam_t);
	}else
	{
		printf("\n\n\n      ERROR. NO HAY RECAUDACIONES CARGADAS EN EL SISTEMA\n\n\n\n");
	}

}


