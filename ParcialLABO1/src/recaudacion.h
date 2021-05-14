#ifndef RECAUDACION_H_
#define RECAUDACION_H_

#define TAM_R 50

#include "tipo.h"
#include "contribuyentes.h"

typedef struct{

	int mes;
	int tipoRecaudacion;
	int importe;
	int isEmpty;
	int id;
	int idContribuyente;

}eRecaudacion;

int inicializarRecaudaciones(eRecaudacion recaudaciones[], int tam_r);
int lugarLibreRec(eRecaudacion recaudaciones[], int tam_r);
int agregarRecaudacion(eRecaudacion recaudaciones[], int tam_r, int* idRecaudacion, eContribuyente contribuyentes[], int tam_c, eTipo tipo[], int tam_t);
#endif /* RECAUDACION_H_ */
