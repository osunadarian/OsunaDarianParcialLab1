#ifndef INFORMES_H_
#define INFORMES_H_

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

int mayorRecaudaciones(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);
int recaudacionesSuperiores(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);
int recaudacionesXtipo(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);
int impuestosPorMes(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

#endif /* INFORMES_H_ */
