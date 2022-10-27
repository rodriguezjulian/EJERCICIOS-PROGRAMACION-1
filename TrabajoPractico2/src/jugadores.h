/*
 * jugadores.h
 *
 *  Created on: 27 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_
#include "confederaciones.h"

	typedef struct
	{
		int id;
		char nombre[50];
		char posicion[50];
		short numeroCamiseta;
		int idConfederacion;
		float salario;
		short aniosContrato;
		short isEmpty;

	}eJugador;


int inicializarIsEmpty(eJugador* jugadores, int tam, int estado);
int loguearJugador(eJugador* jugadores,eConfederacion* confederaciones, int* id,int* contadorJugadores,int tamJugadores);
int asignarDescripcion(eJugador* jugadores,eConfederacion* confederaciones,int tamConfederaciones, char* descripcion ,int posicion);
int ordenarJugadoresAlfabeticamente(eJugador* jugadores,eConfederacion* confederaciones,int contadorJugadores,int tam);
int ordenarJugadoresXId(eJugador* jugadores, int tam);


//int listarJugadoresOrdenAfalbetico(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores);
int listarJugadores(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int referenciaOrdenamiento);
int contarIteraciones(eJugador* jugadores,int* iteraciones, int tam, int idModificar);
int modificarJugador(eJugador* jugadores, eConfederacion* confederaciones, int tam ,int contadorJugadores);
int darLaBajaJugador(eJugador* jugadores,int tam, int* contadorJugadores, eConfederacion* confederaciones);




#endif /* JUGADORES_H_ */
