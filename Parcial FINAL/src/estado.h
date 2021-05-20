#ifndef ESTADO_H_
#define ESTADO_H_

#define TAM_Estados 3

typedef struct{

	int id;
	char descripcion[20];

}eEstado;

/** \brief muestra un estado
 *
 * \param estado eEstado recibe dato de tipo estructura
 * \return void no retorna nada
 *
 */
void mostrarEstado(eEstado estado);

/** \brief muestra todos los estados
 *
 * \param estado[] eEstado recibe dato de tipo estructura
 * \param tam_e int tamanio para recorrer
 * \return int retorna 1 o 0
 *
 */
int mostrarEstados(eEstado estado[], int tam_e);
/** \brief obtiene descripcion mediante dato
 *
 * \param estado[] eEstado recibe dato de tipo estructura
 * \param tam_e int tamanio para recorrer
 * \param idEstado int almacena dato entero para comparar
 * \param descEstado[] char  a este dato se le asigna la descripcion
 * \return int
 *
 */
int obtenerDescripcionEstado(eEstado estado[], int tam_e, int idEstado, char descEstado[]);

#endif /* ESTADO_H_ */
