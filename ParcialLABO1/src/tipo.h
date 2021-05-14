#ifndef TIPO_H_
#define TIPO_H_

#define TAM_Tipos 3

typedef struct{

	int id;
	char descripcion[20];

}eTipo;

void mostrarTipo(eTipo tipo);
int mostrarTipos(eTipo tipo[], int tam_t);
int obtenerDescripcionTipo(eTipo tipo[], int tam_t, int idTipo, char descTipo[]);

#endif /* TIPO_H_ */
