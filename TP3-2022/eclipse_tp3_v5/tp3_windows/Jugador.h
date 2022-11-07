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


int imprimirJugador(LinkedList* pArrayListJugador, int index);
int jug_OrdenarPorNacionalidad(void* unJugador, void* otroJugador);
int buscarJugPorId(LinkedList* pArrayListJugador, int idBuscado, int* posicion);


int jug_Modificar_NombreCompleto(LinkedList* pArrayListJugador , int posicion);
int jug_Modificar_Edad(LinkedList* pArrayListJugador , int posicion);
int jug_Modificar_Posicion(LinkedList* pArrayListJugador , int posicion);
int jug_Modificar_Nacionalidad(LinkedList* pArrayListJugador , int posicion);
#endif // jug_H_INCLUDED
