/*
 * informes.h
 *
 *  Created on: 29 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/// \fn int listarJugadores(eJugador*, eConfederacion*, int, int, int)
/// \brief Listara jugadores mostrando NOMBRE, POSICION, NUMERO DE CAMISETA, SUELDO, CONFEDERACION, ANIOS DE CONTRATO.
/// El orden que esta informacion se lista dependera de la variable "referenciaOrdenamiento".
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param confederaciones ,array de estructuras de tipo eConfederacion a recorrer.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param contadorJugadores , utilizado como variable de control.
/// \param referenciaOrdenamiento	referenciaOrdenamiento -> 1. ordeno por orden alfabetico | referenciaOrdenamiento -> 2.ordeno por id
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int listarJugadores(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int referenciaOrdenamiento);


/// \fn int listarJugadoresXConfederaciones(eJugador*, eConfederacion*, int, int)
/// \brief Esta funcion llama dentro de un bucle for a la funcion "listarJugadoresXUnaConf", teniendo en cuenta el tamanio de las confederaciones.
/// De esta manera se listaran los jugadores de la confederacion correspondiente o bien en caso de NO haber jugadores cargados en esa conferencia
/// se hara un print aclarando la NO existencia de jugadores.
///
/// \param jugadores , array de estructuras utilizado en el llamado a la funcion "listarJugadoresXUnaConf".
/// \param confederaciones , array de estructuras de tipo eConfederacion utilizado para llamar a la funcion "listarJugadoresXUnaConf".
/// \param tam , tamanio del array de estructuras de tipo eJugador.
/// \param tamConfederaciones , tamanio de array de confederaciones.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int listarJugadoresXConfederaciones(eJugador* jugadores,eConfederacion* confederaciones,int tam, int tamConfederaciones);

/// \fn int informarTotalyMediaDeSalarios(eJugador*, int, int)
/// \brief En esta funcion se llamara a "acumularTotalSalarios","calcularPromedio"y "calcularJugPorArribaDeLaMedia""
/// Una vez obtenidos estos datos se mostraran ordenadamente.
///
/// \param jugadores , array de estructuras de tipo eJugador.
/// \param tam ,  tamanio del array de estructuras de tipo eJugador.
/// \param contadorJugadores , cantidad total de jugadores logueados.
void informarTotalyMediaDeSalarios(eJugador* jugadores, int tam, int contadorJugadores);

/// \fn int informarPorcPorConf(eJugador*, int, int, eConfederacion*, int)
/// \brief Se llama a la funcion "calcPorcentajePorConf" y se recorre con un bucle for al array de estructuras de tipo eJugador utilizando como condicion
/// al campo isEmpty y al valor del campo id del arrays de estructuras de tipo eConfederacion (se tiene en cuenta que los id de las confederaciones comienzan
/// en 100).
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param contJugadores , utilizado para llamar a la funcion "calcPorcentajePorConf".
/// \param confederaciones , array de estructuras de tipo eConfederacion.
/// \param tamConfederaciones , tamanio de array de estructura de tipo eConfederacion.
void informarPorcPorConf(eJugador* jugadores, int tam, int contJugadores, eConfederacion* confederaciones, int tamConfederaciones);

/// \fn int informarRegionMasAsistida(eJugador*, int, int, eConfederacion*)
/// \brief Se llama a la funcion "buscarMayorNumJugPorRegion", mediante un bucle for se determina la mayor cantidad acumulada de jugadores en alguna de las
/// confederaciones y se toma como referencia para hacer print teniendo en cuenta cuales posiciones del array al cual se le asignaron valores en la funcion
/// "buscarMayorNumJugPorRegion", coinciden con este numero maximo.
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param tamConfederaciones ,utilizado en los bucles for.
/// \param confederaciones , array de estructuras de tipo eConfederacion a recorrer.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int informarRegionMasAsistida(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones);
#endif /* INFORMES_H_ */
