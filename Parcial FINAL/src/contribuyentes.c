#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "contribuyentes.h"
#include "recaudacion.h"
#include "tipo.h"
#include "menu.h"
#include "validaciones.h"

int inicializarContribuyentes(eContribuyente contribuyentes[], int tam_c)//LISTO
{
    int error = 1;
    if (contribuyentes!=NULL && tam_c > 0)
    {
        for(int i=0; i<tam_c; i++)
        {
        	contribuyentes[i].isEmpty = 1;
        }
        error = 0;
    }

    return error;
}

int lugarLibre(eContribuyente contribuyentes[], int tam_c)//LISTO
{
	int indice;

	indice = -1;

	for(int i=0; i<tam_c; i++)
	{
		if(contribuyentes[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int agregarContribuyente(eContribuyente contribuyentes[], int tam_c, int* id)
{
	int error;
	int indice;
	int validacionCadena;

	validacionCadena = 1;
	error = -1;

	eContribuyente nuevoContribuyente;

	if(contribuyentes!=NULL && tam_c>0)
	{

		indice = lugarLibre(contribuyentes,tam_c);

		if(indice==-1)
		{
            printf("\n\n            EL ALTA NO PUEDE REALIZARSE. EL SISTEMA ESTA COMPLETO.\n\n\n");
            system("pause");
		}
		else
		{

			nuevoContribuyente.idContribuyente = *id;
			*id = *id + 1;
			nuevoContribuyente.isEmpty = 0;


			printf("\n                    INGRESE NOMBRE: ");
			fflush(stdin);
			gets(nuevoContribuyente.nombre);
			validacionCadena = validarCadena(nuevoContribuyente.nombre);
			fflush(stdin);
			formatearString(nuevoContribuyente.nombre);

			while(validacionCadena == 1)//valido cadena de caracteres
			{
				printf("\n           ERROR EN LA LECTURA. REINGRESE NOMBRE: ");
				fflush(stdin);
				gets(nuevoContribuyente.nombre);
				validacionCadena = validarCadena(nuevoContribuyente.nombre);
				fflush(stdin);
				formatearString(nuevoContribuyente.nombre);
			}

			printf("\n                    INGRESE APELLIDO: ");
			fflush(stdin);
			gets(nuevoContribuyente.apellido);
			validacionCadena = validarCadena(nuevoContribuyente.apellido);
			fflush(stdin);
			formatearString(nuevoContribuyente.apellido);

			while(validacionCadena == 1)
			{
				printf("\n           ERROR EN LA LECTURA. REINGRESE APELLIDO: ");
				fflush(stdin);
				gets(nuevoContribuyente.apellido);
				validacionCadena = validarCadena(nuevoContribuyente.apellido);
				fflush(stdin);
				formatearString(nuevoContribuyente.apellido);
			}

			printf("\n     INGRESE CUIL DEL CONTRIBUYENTE (SIN GUIONES) : ");
			scanf("%I64d", &nuevoContribuyente.cuil);
			while(nuevoContribuyente.cuil<20000000000 || nuevoContribuyente.cuil>40000000000)
			{
				printf("\n     ERROR! REINGRESE CUIL (SIN GUIONES): ");
				scanf("%I64d", &nuevoContribuyente.cuil);
			}

			contribuyentes[indice] = nuevoContribuyente;

			printf("\n\n                    ALTA REALIZADA CON EXITO\n\n\n\n");
			system("pause");

			error = 0;
		}

	}

	return error;

}

void mostrarUnContribuyente(eContribuyente contribuyentes)
{

	printf("                %-4d                %-10s                %-10s             %-14I64d\n",
			contribuyentes.idContribuyente,
			contribuyentes.nombre,
			contribuyentes.apellido,
			contribuyentes.cuil);

}

int mostrarContribuyentes(eContribuyente contribuyentes[], int tam_c){

    int error = 1;

    if( contribuyentes != NULL && tam_c > 0)
    {
        printf("\n                 ID                 NOMBRE                   APELLIDO                   CUIL");
        printf("\n--------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam_c; i++)
        {
            if(contribuyentes[i].isEmpty == 0)
            {
            	mostrarUnContribuyente(contribuyentes[i]);
            }
        }

        printf("\n\n");

        error = 0;
    }

    return error;

}

int encontrarContribuyente(eContribuyente contribuyentes[], int tam_c, int id)
{
	int indice = -1;

	for(int i=0; i<tam_c; i++)
	{
		if(contribuyentes[i].idContribuyente == id && contribuyentes[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int checkContribuyentes(eContribuyente contribuyentes[], int tam_c)
{
	int error = -1;

	for(int i = 0; i < tam_c; i++)
	    {
	        if(contribuyentes[i].isEmpty == 0)
	        {
	            error = 1;
	            break;
	        }
	    }

	return error;
}

int modificarContribuyente(eContribuyente contribuyentes[], int tam_c)
{
	int error = 1;
	int idModificar;
	int indice;
	int opcion;
	int validacion;

	if(contribuyentes!=NULL && tam_c>0)
	{
		mostrarContribuyentes(contribuyentes,tam_c);
        printf("\n\n                POR FAVOR, INGRESE EL ID DEL CONTRIBUYENTE A MODIFICAR: ");
        scanf("%d", &idModificar);

        indice = encontrarContribuyente(contribuyentes,tam_c,idModificar);

        if(indice == -1)
        {
            printf("\n\n                ERROR. ID INGRESADO NO VALIDO.\n\n\n\n");
            system("pause");
        }
        else
        {
            printf("\n                 ID                 NOMBRE                   APELLIDO                   CUIL");
            printf("\n--------------------------------------------------------------------------------------------------------\n");
            mostrarUnContribuyente(contribuyentes[indice]);
        	printf("\n\n\n                                    QUE AREA DESEA MODIFICAR?  \n\n");
            printf("                                           [1]  NOMBRE\n");
        	printf("                                           [2]  APELLIDO \n");
        	printf("                                           [3]  CUIL\n");
        	printf("\n                                         DIGITE OPCION: ");
        	scanf("%d", &opcion);

        	switch(opcion)
        	{
        	case 1:
        		do
        		{

    				printf("\n                    INGRESE NOMBRE: ");
    				fflush(stdin);
    				gets(contribuyentes[indice].nombre);
    				fflush(stdin);
    				validacion = validarCadena(contribuyentes[indice].nombre);
    				formatearString(contribuyentes[indice].nombre);
                    printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                    system("pause");

        		}while(validacion==1);
        		break;

        	case 2:
        		do
        		{
    				printf("\n                    INGRESE APELLIDO: ");
    				fflush(stdin);
    				gets(contribuyentes[indice].apellido);
    				fflush(stdin);
    				validacion = validarCadena(contribuyentes[indice].apellido);
    				formatearString(contribuyentes[indice].apellido);
                    printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                    system("pause");

        		}while(validacion==1);
        		break;

        	case 3:
    			printf("\n     INGRESE CUIL DEL CONTRIBUYENTE (SIN GUIONES) : ");
    			scanf("%I64d", &contribuyentes[indice].cuil);
    			while(contribuyentes[indice].cuil<20000000000 || contribuyentes[indice].cuil>40000000000)
    			{
    				printf("\n     ERROR! REINGRESE CUIL (SIN GUIONES): ");
    				scanf("%I64d", &contribuyentes[indice].cuil);
    			}
                printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                system("pause");
                break;

			default:
				printf("\n\n\n                            %d NO ES UNA OPCION VALIDA.\n\n\n", opcion);
				break;

        	}
        }
	}

	return error;
}

int bajaContribuyente(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	int error = 1;
	int idOut;
	int indice;
	int opcion;

	if(contribuyentes!=NULL && tam_c>0 && recaudaciones!=NULL && tam_r>0 && tipos!=NULL && tam_t>0)
	{

		mostrarContribuyentes(contribuyentes,tam_c);
		printf("\n\n        POR FAVOR, INGRESE EL ID DEL CONTRIBUYENTE A REMOVER DEL SISTEMA: ");
		fflush(stdin);
		scanf("%d", &idOut);

		indice = encontrarContribuyente(contribuyentes,tam_c,idOut);

		if(indice==-1)
		{
			printf("\n\n               ----> EL ID INGRESADO ES INVALIDO <----\n\n\n\n");
			system("pause");
		}
		else
		{
			mostrarRecaudacionesPorId(recaudaciones, tam_r, idOut, tipos, tam_t,estados,tam_e);

			printf("DESEA DAR LA BAJA DEFINITIVA DEL CONTRIBUYENTE?\n\n");
			printf("SI -> 1\n");
			printf("NO -> 2\n\n");
			printf("OPCION ELEGIDA: ");
			scanf("%d", &opcion);

			if(opcion==1)
			{
				contribuyentes[indice].isEmpty = 1;
				recaudaciones[indice].isEmpty = 1;
				error = 0;
			}else
			{
				error = 2;
			}

		}

	}

	return error;

}

int mostrarContribuyentePorId(eContribuyente contribuyentes[], int tam_c, int idBuscado)
{
	 int error = 1;

	if( contribuyentes != NULL && tam_c > 0)
	{
        printf("\n                 ID                 NOMBRE                   APELLIDO                   CUIL");
        printf("\n--------------------------------------------------------------------------------------------------------\n");

		for(int i=0; i<tam_c; i++)
		{
			if(contribuyentes[i].idContribuyente == idBuscado && contribuyentes[i].isEmpty == 0)
			{
				mostrarUnContribuyente(contribuyentes[i]);
			}
		}

		printf("\n\n");

		error = 0;
	}

	return error;

}

int imprimirContribuyentes(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	int error = -1;
	int indice;

	if(contribuyentes!=NULL && tam_c>0 && recaudaciones!=NULL && tam_r>0 && tipos!=NULL && tam_t>0 && estados!=NULL && tam_e>0)
	{
			for(int i=0;i<tam_c;i++)
			{
				if(contribuyentes[i].isEmpty == 0)
				{
			        printf("\n                 ID                 NOMBRE                   APELLIDO                   CUIL");
			        printf("\n--------------------------------------------------------------------------------------------------------\n");
					mostrarUnContribuyente(contribuyentes[i]);
					indice = contribuyentes[i].idContribuyente;
					mostrarRecaudacionesPorId(recaudaciones,tam_r,indice,tipos,tam_t,estados,tam_e);
				}
			}

        error = 0;
		}

	return error;
}

void validarOpcionDos(eContribuyente contribuyentes[], int tam_c)
{
	if(checkContribuyentes(contribuyentes,tam_c)==1)
	{
		modificarContribuyente(contribuyentes,tam_c);
	}else
	{
        printf("\n\n\n      ERROR. NO HAY CONTRIBUYENTES CARGADOS EN EL SISTEMA\n\n\n\n");
	}
}

void validarOpcionTres(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	if(checkContribuyentes(contribuyentes,tam_c)==1)
	{
		bajaContribuyente(contribuyentes,TAM_C,recaudaciones,tam_r,tipos,tam_t,estados,tam_e);
	}else
	{
		printf("\n\n\n      ERROR. NO HAY CONTRIBUYENTES CARGADOS EN EL SISTEMA\n\n\n\n");
	}
}

void validarOpcionCuatro(eRecaudacion recaudaciones[], int tam_r, int* idRecaudacion, eContribuyente contribuyentes[], int tam_c, eTipo tipo[], int tam_t, eEstado estados[], int tam_e)
{
	if(checkContribuyentes(contribuyentes,tam_c)==1)
	{
		agregarRecaudacion(recaudaciones, tam_r, idRecaudacion, contribuyentes, tam_c, tipo,tam_t, estados,tam_e);
	}else
	{
		printf("\n\n\n      ERROR. NO HAY CONTRIBUYENTES CARGADOS EN EL SISTEMA\n\n\n\n");
	}
}

void validarOpcionSiete(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e)
{
	if(checkContribuyentes(contribuyentes,tam_c)==1)
	{
		imprimirContribuyentes(contribuyentes,tam_c,recaudaciones,tam_r,tipos,tam_t,estados,tam_e);
	}else
	{
        printf("\n\n\n      ERROR. NO HAY CONTRIBUYENTES CARGADOS EN EL SISTEMA\n\n\n\n");
	}

}
