#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_

#define TAM_C 5

typedef struct{

	char nombre[20];
	char apellido[20];
	long long int cuil;
	int idContribuyente;
	int isEmpty;

}eContribuyente;

#include "recaudacion.h"
#include "tipo.h"
#include "estado.h"
#include "validaciones.h"

/** \brief inicializa el campo isEmpty de los contribuyentes
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura
 * \return int retorna 1 o 0
 *
 */
int inicializarContribuyentes(eContribuyente contribuyentes[], int tam_c);

/** \brief busca un lugar libre para agregar un contribuyente
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura
 * \return int retorna 1 si encontro lugar y -1 si no lo hizo
 *
 */
int lugarLibre(eContribuyente contribuyentes[], int tam_c);

/** \brief añade un contribuyente al array de estructuras
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param id int* recibe un id en forma de puntero para dar un valor ya pre-asignado
 * \return int
 *
 */
int agregarContribuyente(eContribuyente contribuyentes[], int tam_c, int* id);

/** \brief muestra un solo contribuyente
 *
 * \param contribuyentes eContribuyente recibe variable de tipo estructura
 * \return void no retorna nada
 *
 */
void mostrarUnContribuyente(eContribuyente contribuyentes);

/** \brief muestra todos los contribuyentes
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \return int retorna 1 o 0
 *
 */
int mostrarContribuyentes(eContribuyente contribuyentes[], int tam_c);

/** \brief encuentra un contribuyente por un id
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param id int id que recibe para encontrarlo en la lista
 * \return int retorna 1 o -1 depende de si lo encontro o no
 *
 */
int encontrarContribuyente(eContribuyente contribuyentes[], int tam_c, int id);

/** \brief chequea que haya contribuyentes en la lista
 *
 * \param contribuyentes[] eContribuyente  recibe variable de tipo estructura
 * \param tam_c int  tamaño de la estructura para recorrer
 * \return int retorna -1 si no encontro contribuyentes
 *
 */
int checkContribuyentes(eContribuyente contribuyentes[], int tam_c);

/** \brief modifica un campo de un contribuyente previamente seleccionado por el usuario
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \return int retorna -1 si no encontro a nadie
 *
 */
int modificarContribuyente(eContribuyente contribuyentes[], int tam_c);

/** \brief realiza la baja logica de un contribuyente
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int retorna 0 si logro hacer su funcion
 *
 */
int bajaContribuyente(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

/** \brief muestra un contribuyente por id
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int  tamaño de la estructura para recorrer
 * \param idBuscado int id que va a buscar
 * \return int
 *
 */
int mostrarContribuyentePorId(eContribuyente contribuyentes[], int tam_c, int idBuscado);

/** \brief imprime a los contribuyentes con estado "saldadas"
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return int
 *
 */
int imprimirContribuyentes(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

/** \brief valida ingreso a la opcion dos
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \return void no retorna nada
 *
 */
void validarOpcionDos(eContribuyente contribuyentes[], int tam_c);

/** \brief valida ingreso a la opcion tres
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return void no retorna nada
 *
 */
void validarOpcionTres(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);

/** \brief valida ingreso a la opcion cuatro
 *
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param idRecaudacion int* id
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param tipo[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return void no retorna nada
 *
 */
void validarOpcionCuatro(eRecaudacion recaudaciones[], int tam_r, int* idRecaudacion, eContribuyente contribuyentes[], int tam_c, eTipo tipo[], int tam_t, eEstado estados[], int tam_e);

/** \brief  valida ingreso a la opcion siete
 *
 * \param contribuyentes[] eContribuyente recibe variable de tipo estructura
 * \param tam_c int tamaño de la estructura para recorrer
 * \param recaudaciones[] eRecaudacion recibe variable de tipo estructura
 * \param tam_r int tamaño de la estructura para recorrer
 * \param tipos[] eTipo recibe variable de tipo estructura
 * \param tam_t int tamaño de la estructura para recorrer
 * \param estados[] eEstado recibe variable de tipo estructura
 * \param tam_e int tamaño de la estructura para recorrer
 * \return void  no retorna nada
 *
 */
void validarOpcionSiete(eContribuyente contribuyentes[], int tam_c, eRecaudacion recaudaciones[], int tam_r, eTipo tipos[], int tam_t, eEstado estados[], int tam_e);


#endif /* CONTRIBUYENTES_H_ */
