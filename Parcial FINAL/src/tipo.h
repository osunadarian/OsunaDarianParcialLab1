#ifndef TIPO_H_
#define TIPO_H_

#define TAM_Tipos 3

typedef struct{

	int id;
	char descripcion[20];

}eTipo;

/** \brief muestra un tipo
 *
 * \param tipo eTipo recibe dato de tipo estructura
 * \return void no retorna nada
 *
 */
void mostrarTipo(eTipo tipo);

/** \brief muestra todos los tipos
 *
 * \param tipo[] eTipo recibe dato de tipo estructura
 * \param tam_t int recibe tamanio del array
 * \return int retorna 1 o 0
 *
 */
int mostrarTipos(eTipo tipo[], int tam_t);

/** \brief obtiene descripcion del tipo
 *
 * \param tipo[] eTipo recibe dato de tipo estructura
 * \param tam_t int recibe tamanio del array
 * \param idTipo int almacena dato entero para comparar
 * \param descTipo[] char a este dato se le asigna la descripcion
 * \return int
 *
 */
int obtenerDescripcionTipo(eTipo tipo[], int tam_t, int idTipo, char descTipo[]);

#endif /* TIPO_H_ */
