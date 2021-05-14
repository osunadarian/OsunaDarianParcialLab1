#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_

#define TAM_C 50

typedef struct{

	char nombre[20];
	char apellido[20];
	int cuil;
	int idContribuyente;
	int isEmpty;

}eContribuyente;

int validarCadena(char cadena[]);
int inicializarContribuyentes(eContribuyente contribuyentes[], int tam_c);
int lugarLibre(eContribuyente contribuyentes[], int tam_c);
int agregarContribuyente(eContribuyente contribuyentes[], int tam_c, int* id);
void mostrarUnContribuyente(eContribuyente contribuyentes);
int mostrarContribuyentes(eContribuyente contribuyentes[], int tam_c);
int encontrarContribuyente(eContribuyente contribuyentes[], int tam_c, int id);
int checkContribuyentes(eContribuyente contribuyentes[], int tam_c);
int modificarContribuyente(eContribuyente contribuyentes[], int tam_c);

#endif /* CONTRIBUYENTES_H_ */
