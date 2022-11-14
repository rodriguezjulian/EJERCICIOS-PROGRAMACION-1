#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	//int isEmpty;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

//void jug_delete();
void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

//HACER QUE TODAS LAS FUNCIONES ARRANQUEN CON jug
//int jug_imprimirJugador(LinkedList* pArrayListJugador, int index,LinkedList* pArrayListSeleccion);
int jug_imprimirJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int referenciaDeUso);


int jug_OrdenarPorNacionalidad(void* unJugador, void* otroJugador);
int buscarJugPorId(LinkedList* pArrayListJugador, int idBuscado, int* indice);


int jug_Editar_NombreCompleto(LinkedList* pArrayListJugador , int indice);
int jug_Editar_Edad(LinkedList* pArrayListJugador , int indice);
int jug_Editar_Posicion(LinkedList* pArrayListJugador , int indice);
int jug_Editar_Nacionalidad(LinkedList* pArrayListJugador , int indice);





int jug_Confirmar_Baja(LinkedList* pArrayListJugador, int indice, char* nombreJugador);
int jug_BuscarIdMax(LinkedList* pArrayListJugador, int *idMaximo);
int jug_Solicitar_Id(LinkedList* pArrayListJugador, int * indice ,char * mensaje);
int jug_convocar(LinkedList* pArrayListJugador, LinkedList* listaConfederaciones);


int operara_Menu_Opcion5(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int jug_OrdenarPorNombre(void* unJugador, void* otroJugador);
int jug_OrdenarPorEdad(void* unJugador, void* otroJugador);
int jug_OrdenarPorNacionalidad(void* unJugador, void* otroJugador);




int jug_IngresarPosicion(char* posicion);
void jug_MostrarNacionalidades(void);
int jug_IngresarNacionalidad(char* nacionalidad);


int jug_OrdenarPorPosicion(void* unJugador, void* otroJugador);
int jug_Quitar_Convocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);


#endif // jug_H_INCLUDED
