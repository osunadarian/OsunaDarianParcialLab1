#ifndef RECAUDACION_H_
#define RECAUDACION_H_

#define TAM_R 8

typedef struct{

	int mes;
	int tipoRecaudacion;
	int importe;
	int isEmpty;
	int id;
	int idContribuyente;
	int estadoRecaudacion;

}eRecaudacion;

#include "tipo.h"
#include "contribuyentes.h"
#include "estado.h"
#include "validaciones.h"

/** \brief inicializa el campo isEmpty de las recaudaciones
 *
 * \param recaudaciones[] eRecaudacion  recibe variable de tipo estructura
 * \param tam_r int  tamaño de la estructura para recorrer
 * \return int retorna 1 o 0
 *
 */
int inicializarRecaudaciones(eRecaudacion recaudaciones[], int tam_r);

/** \brief busca espacio disponible en las recaudaciones
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \return int  retorna 1 o 0 depende de si encontro o no lugar
 *
 */
int buscarEspacio(eRecaudacion recaudaciones[], int tam_r);

/** \brief busca un lugar libre dentro de las recaudaciones
 *
 * \param recaudaciones[] eRecaudacion
 * \param tam_r int
 * \return int devuelve el indice con lugar disponbile
 *
 */
int lugarLibreRec(eRecaudacion recaudaciones[], int tam_r);

/** \brief agrega una recaudacion
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r inttamaño de la estructura para recorrer
 * \param idRecaudacion int* recibe un puntero para modificar el id
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param tipo[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int
 *
 */
int agregarRecaudacion(eRecaudacion recaudaciones[], int tam_r, int* idRecaudacion, eContribuyente contribuyentes[], int tam_c, eTipo tipo[], int tam_t, eEstado estados[], int tam_e);

/** \brief encuentra una recaudacion
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param idRec int id para encontrar una recaudacion
 * \return int retorna 1 o 0
 *
 */
int encontrarRecaudacion(eRecaudacion recaudaciones[], int tam_r, int idRec);

/** \brief muestra una recaudacion
 *
 * \param recaudaciones eRecaudacion  recibe variable de tipo estructura
 * \param tipos[] eTipo  recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado  recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return void no retorna nada
 *
 */
void mostrarUnaRecaudacion(eRecaudacion recaudaciones, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

/** \brief  muestra todas las recaudaciones
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int retorna 1 o 0
 *
 */
int mostrarRecaudaciones(eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

/** \brief muestra recaudaciones sin financiar
 *
 * \param recaudaciones[] eRecaudacion  recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param tipos[] eTipo  recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado  recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int  retorna 1 o 0
 *
 */
int mostrarRecaudacionesSinFinanciar(eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

/** \brief muestra recaudaciones sin saldar
 *
 * \param recaudaciones[] eRecaudacion  recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param tipos[] eTipo  recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado  recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int  retorna 1 o 0
 *
 */
int mostrarRecaudacionesSinSaldar(eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

/** \brief muestra recaudaciones por id
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param id int recibe id para buscar
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int  retorna 1 o 0
 *
 */
int mostrarRecaudacionesPorId(eRecaudacion recaudaciones[], int tam_r, int id, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);
/** \brief refinancia las recaudaciones
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int retorna 1 o 0
 *
 */
int refinanciarRecaudacion(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

/** \brief funcion que cambia el estado de la recaudacion a saldada
 *
 * \param recaudaciones[] eRecaudacion  recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param contribuyentes[] eContribuyente  recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param tipos[] eTipo  recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado  recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int retorna 1 o 0
 *
 */
int saldarRecaudacion(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);
/** \brief imprime recaudaciones junto a contribuyentes
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int retorna 1 o 0
 *
 */
int imprimirRecaudaciones(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);
/** \brief chequea que existan recaudaciones
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \return int retorna 1 o 0
 *
 */
int checkRecaudaciones(eRecaudacion recaudaciones[], int tam_r);
/** \brief valida ingreso a opcion cinco
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return void retorna 1 o 0
 *
 */
void validarOpcionCinco(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);
/** \brief valida ingreso a opcion seis
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return void retorna 1 o 0
 *
 */
void validarOpcionSeis(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);
/** \brief valida ingreso a opcion ocho
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return void retorna 1 o 0
 *
 */
void validarOpcionOcho(eRecaudacion recaudaciones[], int tam_r, eContribuyente contribuyentes[], int tam_c, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

#endif /* RECAUDACION_H_ */
