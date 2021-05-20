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

int main(void){

	setbuf(stdout, NULL);
	//eContribuyente contribuyentes[TAM_C];
	//eRecaudacion recaudaciones[TAM_R];

	eTipo tipos[TAM_Tipos]=
	{
			{1, "ARBA"},
			{2, "IIBB"},
			{3, "GANANCIAS"}
	};
	eEstado estados[TAM_Estados]=
	{
			{1, "PENDIENTE"},
			{2, "SALDADO"},
			{3, "REFINANCIADO"}
	};

	int idContribuyente = 1000;
	int idRecaudacion = 100;
	int exit = 1;
	int option;

	//inicializarContribuyentes(contribuyentes,TAM_C);
	//inicializarRecaudaciones(recaudaciones,TAM_R);

	eContribuyente contribuyentes[TAM_C]={
			{"Darian","Alvarez",1005656112,1000,0},
			{"Lucas","Garcia",1005656112,1001,0},
			{"Esteban","Flores",1005656112,1002,0},
			{"Adrian","Estevez",1005656112,1003,0},
			{"Erik","Gomez",1005656112,1004,0}
	};

	eRecaudacion recaudaciones[TAM_R]={
			{1,2,4000,0,100,1000,3},
			{2,1,3800,0,101,1000,3},
			{2,1,2100,0,102,1000,3},
			{3,2,2200,0,103,1000,3},
			{8,3,1500,0,104,1000,2},
			{2,3,3000,0,105,1001,1},
			{2,2,1500,0,106,1001,1},
			{10,3,3000,0,107,1001,2}
	};


	do{
		menuOptions();
		printf("		DIGITE OPCION: ");
		scanf("%d", &option);

		switch(option)
		{
		case 1:
			agregarContribuyente(contribuyentes,TAM_C,&idContribuyente);
			break;
		case 2:
			validarOpcionDos(contribuyentes,TAM_C);
			break;
		case 3:
			validarOpcionTres(contribuyentes,TAM_C,recaudaciones,TAM_C,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 4:
			validarOpcionCuatro(recaudaciones,TAM_R,&idRecaudacion,contribuyentes,TAM_C,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 5:
			validarOpcionCinco(recaudaciones,TAM_R,contribuyentes,TAM_C,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 6:
			validarOpcionSeis(recaudaciones,TAM_R,contribuyentes,TAM_C,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 7:
			validarOpcionSiete(contribuyentes,TAM_C,recaudaciones,TAM_R,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 8:
			validarOpcionOcho(recaudaciones,TAM_C,contribuyentes,TAM_R,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 9:
			mayorRecaudaciones(recaudaciones,TAM_C,contribuyentes,TAM_R,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 10:
			recaudacionesSuperiores(recaudaciones,TAM_C,contribuyentes,TAM_R,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 11:
			recaudacionesXtipo(recaudaciones,TAM_C,contribuyentes,TAM_R,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 12:
			impuestosPorMes(recaudaciones,TAM_C,contribuyentes,TAM_R,tipos,TAM_Tipos,estados,TAM_Estados);
			break;
		case 13:
			exitProgram(&exit);
			break;
		default:
			printf("\n\n		OPCION ELEGIDA INEXISTENTE. \n		   VUELVA A INTENTARLO. \n\n");
            break;
		}
	}while(exit==1);

	return EXIT_SUCCESS;
}
