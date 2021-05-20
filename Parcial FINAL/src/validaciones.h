#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/** \brief formatea string, toddo a minuscula y luego primer letra en mayuscula
 *
 * \param string[] char recibe el array a formatear
 * \return void no retorna nada
 *
 */
void formatearString(char string[]);

/** \brief valida que los datos ingresados sean solo letras
 *
 * \param cadena[] char  recibe el array a analizar
 * \return int retorna 1 o 0
 *
 */
int validarCadena(char cadena[]);


#endif /* VALIDACIONES_H_ */
