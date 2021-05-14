#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "recaudacion.h"
#include "contribuyentes.h"

#include "tipo.h"
#include "menu.h"


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

	eContribuyente nuevoContribuyente; //creo variable de tipo eContribuyente

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

			*id = *id + 1;
			nuevoContribuyente.idContribuyente = *id;
			nuevoContribuyente.isEmpty = 0;

			do
			{
				printf("\n                    INGRESE NOMBRE: ");
				fflush(stdin);
				gets(nuevoContribuyente.nombre);
				validacionCadena = validarCadena(nuevoContribuyente.nombre);
				fflush(stdin);
				strlwr(nuevoContribuyente.nombre);
				nuevoContribuyente.nombre[0] = toupper(nuevoContribuyente.nombre[0]);

			}while(validacionCadena == 1);

			do
			{
				printf("\n                    INGRESE APELLIDO: ");
				fflush(stdin);
				gets(nuevoContribuyente.apellido);
				validacionCadena = validarCadena(nuevoContribuyente.apellido);
				fflush(stdin);
				strlwr(nuevoContribuyente.apellido);
				nuevoContribuyente.apellido[0] = toupper(nuevoContribuyente.apellido[0]);

			}while(validacionCadena == 1);

			printf("\n                    INGRESE CUIL (SIN GUIONES): ");
			scanf("%d", &nuevoContribuyente.cuil);
			/*
			while(strlen(nuevoContribuyente.cuil)!=11)
			{
				printf("\n     ERROR!      REINGRESE LOS 11 DIGITOS DE SU CUIL: ");
				scanf("%d", &nuevoContribuyente.cuil);
			}
			*/

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
	printf("	 %d         %s	      %s          %d         \n",
			contribuyentes.idContribuyente,
			contribuyentes.nombre,
			contribuyentes.apellido,
			contribuyentes.cuil);

}

int mostrarContribuyentes(eContribuyente contribuyentes[], int tam_c){

    int error = 1;

    if( contribuyentes != NULL && tam_c > 0)
    {
        printf("************************************************************");
        printf("\n       ID        APELLIDO        NOMBRE         CUIL      ");
        printf("\n************************************************************\n\n");

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
	int contador = -1;

	for(int i = 0; i < tam_c; i++)
	    {
	        if(contribuyentes[i].isEmpty == 0)
	        {
	            contador = 1;
	            break;
	        }
	    }

	return contador;
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
        printf("\n\n        POR FAVOR, INGRESE EL ID DEL CONTRIBUYENTE A MODIFICAR: ");
        scanf("%d", &idModificar);

        indice = encontrarContribuyente(contribuyentes,tam_c,idModificar);

        if(indice == -1)
        {
            printf("\n\n            ERROR. ID INGRESADO NO VALIDO.\n\n\n\n");
            system("pause");
        }
        else
        {
            printf("************************************************************");
            printf("\n       ID        APELLIDO        NOMBRE         CUIL      ");
            mostrarUnContribuyente(contribuyentes[indice]);
        	printf("\n\n\n                  QUE AREA DESEA MODIFICAR?  \n\n");
            printf("                        [1]  NOMBRE\n");
        	printf("                        [2]  APELLIDO \n");
        	printf("                        [3]  CUIL\n");
        	printf("\n                       DIGITE OPCION: ");
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
                    printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                    system("pause");

        		}while(validacion==1);
        		break;

        	case 3:
    			printf("\n                    INGRESE CUIL: ");
    			scanf("%d", &contribuyentes[indice].cuil);

                printf("\n\n                     EXITO EN LA MODIFICACION\n\n\n");
                system("pause");
    			break;

			default:
				printf("\n\n\n                            %d NO ES UNA OPCION VALIDA.", opcion);
				break;

        	}
        }
	}

	return error;
}

int bajaContribuyente(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t)
{
	int error = 1;
	int idOut;
	int indice;
	int confirm;

	if(contribuyentes!=NULL && tam_c>0)
	{
		fflush(stdin);
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
        	printf("\n\n              EL SIGUIENTE CONTRIBUYENTE SERA BORRADO DEL SISTEMA\n\n");
            printf("************************************************************");
            printf("\n       ID        APELLIDO        NOMBRE         CUIL      ");
            mostrarUnContribuyente(contribuyentes[indice]);
            printf("************************************************************");
            printf("\n\n                         DESEA CONFIRMAR BAJA?");
            printf("\n\n                         [1] - SI  [2] - NO");
            printf("\n\n                          DIGITE RESPUESTA: ");
            scanf("%d", &confirm);
            if(confirm == 1)
            {
            	contribuyentes[indice].isEmpty = 1;
            	recaudaciones[indice].isEmpty = 1;
                printf("\n\n                   BAJA DEL CONTRIBUYENTE COMPLETA\n\n\n");
                error = 0;
            }
            else
            {
                printf("\n\n          BAJA DEL CONTRIBUYENTE CANCELADA POR EL USUARIO\n\n\n");
                error = 2;
                system("pause");
            }
        }
	}


	return error;

}
