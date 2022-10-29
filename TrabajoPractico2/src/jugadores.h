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
int listarJugadoresXUnaConf(eJugador* jugadores,eConfederacion* confederaciones,int tam, int idConf, int tamConfederaciones);
int listarJugadoresXConfederaciones(eJugador* jugadores,eConfederacion* confederaciones,int tam, int tamConfederaciones);


int menuInformes(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int tamConfederaciones);



int acumularTotalSalarios(eJugador* jugadores,int tam, float* totalSalarios);
int calcularJugPorArribaDeLaMedia(eJugador* jugadores, float promedioSalarios);
float calcularPromedio(float numeroA, int numeroB);


int acumularAnios(eJugador* jugadores, int tam, int* aniosAcumulados);
int calcConfConMasAniosDeContrato(eJugador* jugadores,int tamConfederaciones, int tamJugadores, char* confederacionConMasAniosDeContrato,eConfederacion* confederaciones);


int informarTotalyMediaDeSalarios(eJugador* jugadores, int tam, int contadorJugadores);


float calcPorcentaje(int contJugadores, int conf);
int calcPorcentajePorConf(eJugador* jugadores,int contJugadores, int tam, float* porcentajeConmebol, float* porcentajeUefa,float* porcentajeAfc, float* porcentajeCaf,float* porcentajeConcacaf,float* porcentajeOfc);
//int informarPorcPorConf(eJugador* jugadores, int tam, int contJugadores);
int informarPorcPorConf(eJugador* jugadores, int tam, int contJugadores, eConfederacion* confederaciones);

#endif /* JUGADORES_H_ */
