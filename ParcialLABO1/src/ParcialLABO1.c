#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "contribuyentes.h"
#include "recaudacion.h"
#include "tipo.h"
#include "menu.h"


int main(void){

	setbuf(stdout, NULL);

	eContribuyente contribuyentes[TAM_C];
	eRecaudacion recaudaciones[TAM_R];

	eTipo tipos[TAM_Tipos]=
	{
			{1, "ARBA"},
			{2, "IIBB"},
			{3, "GANANCIAS"}
	};

	int idContribuyente = 1000;
	int idRecaudacacion = 100;
	int exit = 1;
	int option;

	inicializarContribuyentes(contribuyentes,TAM_C);
	inicializarRecaudaciones(recaudaciones,TAM_R);

	//eContribuyente contribuyentes[TAM_C]={{"DARIAN","Alvarez",10056561,100,0}};

	do{
		menuOptions();
		printf("DIGITE OPCION: ");
		scanf("%d", &option);

		switch(option)
		{
		case 1:
			agregarContribuyente(contribuyentes,TAM_C,&idContribuyente);
			break;
		case 2:
			modificarContribuyente(contribuyentes,TAM_C);
			break;
		case 3:
			break;
		case 4:
			agregarRecaudacion(recaudaciones,TAM_R,&idRecaudacacion,contribuyentes,TAM_C,tipos,TAM_Tipos);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
            break;
		}

	}while(exit==1);







	return EXIT_SUCCESS;
}
