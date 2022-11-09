#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	//int isEmpty;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

void selec_delete();

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);

//int selec_getConfederacion(Seleccion* this,int* confederacion);
int selec_getConfederacion(Seleccion* this,char* confederacion);

//int selec_getIsEmpty(Seleccion* this,int* isEmpty);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

int imprimirSeleccion(LinkedList* pArrayListSeleccion, int index);
int selec_buscar_Pais(LinkedList* listaConfederaciones, int idSeleccion, char* paisEncontrado);

int selec_buscarPorId(LinkedList* pArrayListSeleccion, int idBuscado, int *indice);
int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais);
int selec_Solicitar_Id(LinkedList* pArrayListSeleccion, int* indice);

int selec_OrdenarPorConfederacion(void* unaConderacion, void* otraConfederacion);


int selec_IngresarConfederacion(char* opcion);

#endif // selec_H_INCLUDED