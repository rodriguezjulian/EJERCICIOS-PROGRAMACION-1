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

/// \fn int inicializarIsEmpty(eJugador*, int, int)
/// \brief Dara valor al campo IsEmpty de una estrucutura de tipo eJugador. El mismo se interpretara como VACIO 1 - OCUPADO 0
///
/// \param jugadores , estructura de tipo eJugador sobre la que se operara.
/// \param tam , tamanio del array de estructura.
/// \param estado , estado que el usuario desea darle al campo isEmpty.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int inicializarIsEmpty(eJugador* jugadores, int tam, int estado);

/// \fn int loguearJugador(eJugador*, eConfederacion*, int*, int*, int)
/// \brief Esta funcion se encarga de completar todos los campos de la estructura eJugador, dependiendo cual sera
/// cargado por el usuario (funciones con sus validaciones correspondientes) o bien se ocuparan automaticamente (campo isEmpty y id autoincremental).
///
/// \param jugadores , estructura de tipo eJugador sobre la que se operara.
/// \param confederaciones , estructura de tipo eConfederacion, llamada en varias funciones que intervienen en el logueo.
/// \param id ,el id se recibe como parametro en 0 (inicializado en 0 por consigna)y se modifica su valor automaticamente .
/// \param contadorJugadores , serviria para posteriormente utilizar esta variable como control de acceso a otras opciones.
/// \param tamJugadores
/// \return
int loguearJugador(eJugador* jugadores,eConfederacion* confederaciones, int* id,int* contadorJugadores,int tamJugadores);


/// \fn int asignarDescripcion(eJugador*, eConfederacion*, int, char*, int)
/// \brief Esta funcion retorna por referencia una cadena de caracteres que posteriormente sera compara con otra en la funcion ordenarJugadoresAlfabeticamente.
///
///
/// \param jugadores , estructura de tipo eJugador usada como parametro para utilizar los valores contenidos en sus campos.
/// \param confederaciones , obtendremos la descripcion de un array de tipo eConfederacion.
/// \param tamConfederaciones , tamanio del array de confederaciones, utilizado como referencia en un bucle for
/// \param descripcion , a esta variable se le asignara el valor de la cadena de caracteres.
/// \param posicion , la posicion sera dada por el numero de iteracion que lleve una funcion for(){} comunmente utilizadas letra i o j
/// \return
int asignarDescripcion(eJugador* jugadores,eConfederacion* confederaciones,int tamConfederaciones, char* descripcion ,int posicion);

/// \fn int ordenarJugadoresAlfabeticamente(eJugador*, eConfederacion*, int, int)
/// \brief Se obtendran las descripciones teniendo en cuenta los campos idConfederacion de un array de estructuras de tipo eJugador y el
/// campo nombre de la estructura eConfederacion (mediante funcion asignarDescripcion).
/// Se compararan de a dos descripciones (nombres de estructura) y en caso de coincidencia se tendra en cuenta el campo nombre de la estrucutra  eJugador, se
/// busca ordenar alfabeticamente en ambos casos.
/// \param jugadores , estructura de tipo eJugador que sera ordenada.
/// \param confederaciones , variable utilizada para llamar a la funcion asignarDescripcion.
/// \param tam , tamanio del array de estructuras de tipo eJugador
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ordenarJugadoresAlfabeticamente(eJugador* jugadores,eConfederacion* confederaciones,int tam);

/// \fn int ordenarJugadoresXId(eJugador*, int)
/// \brief Teniendo en cuenta el campo id de un array de estruturas de tipo eJugador, se ordernaran las posiciones segun id.
/// Se comparara y en caso de ser necesario se hara un "swap"
///
/// \param jugadores , array de estructuras a ordenar.
/// \param tam , tamanio del array de tipo eJugador que se ordenara.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ordenarJugadoresXId(eJugador* jugadores, int tam);

/// \fn int contarIteraciones(eJugador*, int*, int, int)
/// \brief
///
/// \param jugadores
/// \param iteraciones
/// \param tam
/// \param idModificar
/// \return
int contarIteraciones(eJugador* jugadores,int* iteraciones, int tam, int idModificar);


int modificarJugador(eJugador* jugadores, eConfederacion* confederaciones, int tam ,int contadorJugadores);
int darLaBajaJugador(eJugador* jugadores,int tam, int* contadorJugadores, eConfederacion* confederaciones);
int acumularTotalSalarios(eJugador* jugadores,int tam, float* totalSalarios);
int calcularJugPorArribaDeLaMedia(eJugador* jugadores, float promedioSalarios);
int calcConfConMasAniosDeContrato(eJugador* jugadores,int tamConfederaciones, int tamJugadores, int* resultadoAnios,eConfederacion* confederaciones);
float calcPorcentaje(int contJugadores, int conf);
int calcPorcentajePorConf(eJugador* jugadores,int contJugadores, int tam, float* arrayPorcentajes, int tamConfederaciones);
int calcularRegionMasJug(eJugador* jugadores,int tamConfederaciones, int tamJugadores, char* confederacionConMasJug,eConfederacion* confederaciones);
int calcConfConMasAniosDeContrato(eJugador* jugadores,int tamConfederaciones, int tamJugadores, int* resultadoAnios,eConfederacion* confederaciones);
int contarAniosDeContratoPorConf(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones,int* arrayAniosAcumulados );

int informarPorcPorConf(eJugador* jugadores, int tam, int contJugadores, eConfederacion* confederaciones, int tamConfederaciones);
int informarTotalyMediaDeSalarios(eJugador* jugadores, int tam, int contadorJugadores);
void mostrarConfConMasAniosContrato(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones);

int listarJugadores(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int referenciaOrdenamiento);
int listarJugadoresXUnaConf(eJugador* jugadores,eConfederacion* confederaciones,int tam, int idConf, int tamConfederaciones);
int listarJugadoresXConfederaciones(eJugador* jugadores,eConfederacion* confederaciones,int tam, int tamConfederaciones);
int menuInformes(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int tamConfederaciones);
void inicializarArrayFloat(float* array,int tam);
void inicializarArray(int* array,int tam);
float calcularPromedio(float numeroA, int numeroB);
#endif /* JUGADORES_H_ */
