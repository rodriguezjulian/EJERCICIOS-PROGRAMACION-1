/*
 * confederaciones.h
 *
 *  Created on: 27 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_
#include "jugadores.h"

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;

}eConfederacion;
/// \fn int listarConfederaciones(eConfederacion*, int, int)
/// \brief Se listan las confederaciones existentes (se verifica),mostrando nombre, region y anio de creacion.
///
/// \param confederaciones , array de estructuras de tipo eConfederacion a recorrer.
/// \param tamConfederaciones , tamanio de array de tipo eConfederacion.
/// \param contadorConf , contador de confederaciones, variable de control
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int listarConfederaciones(eConfederacion* confederaciones,int tamConfederaciones, int contadorConf);

/// \fn int loguearConfederacion(int*, eConfederacion*, int, int*)
/// \brief Se ingresara nombre, region, y anio de creacion, el id sera autoincremental a partir de 100 (para ello debemos declararlo
/// en el main con este valor de inicio), por ultimo el espacio isEmpty tendra referencia de OCUPADO.
/// Todo lo que el usuario cargue estara pedido y validado con funciones
///
/// \param id , autoincremental
/// \param confederaciones , , array de estructuras de tipo eConfederacion a las que se les asignaran valores.
/// \param tamConfederaciones , tamanio de array de tipo eConfederacion.
/// \param contadorConf ,contador de confederaciones, variable de control (autoincremtal desde 0).
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int loguearConfederacion(int *id,eConfederacion* confederaciones, int tamConfederaciones, int* contadorConf);

/// \fn int contarIteracionesConf(eConfederacion*, int*, int, int)
/// \brief Esta funcion sera de vital importancia a la hora de modificar o dar de baja una confederacion, validando que el
/// id que ingreso el usuario sea valido, y devolviendo por referencia cuantas veces itero un bucle for para encontrar la posicion
/// en el array de estructuras de tipo eConfederacion.
///
/// \param confederaciones , array de estructuras de tipo eConfederacion a recorrer.
/// \param iteraciones , valor que representa cuantas veces itero un bucle for para encontrar la posicion.
/// \param tamConfederaciones , tamanio de array de tipo eConfederacion.
/// \param idModificar , ingresado por el usuario (ingresarIntConRango)
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int contarIteracionesConf(eConfederacion* confederaciones,int* iteraciones, int tamConfederaciones, int idModificar);

/// \fn int darDeBajaConf(eConfederacion*, int, int*)
/// \brief El usuario ingresara id (ingresarIntConRango), una vez validada su existencia, se realizara una baja logica teniendo
/// en cuenta la posicion del array de estrucutras de tipo eConfederacion donde se encuentra.
///
/// \param confederaciones , array de estructuras de tipo eConfederacion a operar.
/// \param tamConfederaciones , tamConfederaciones , tamanio de array de tipo eConfederacion.
/// \param contadorConf , se restara -1 del contador de confederaciones al efectuarse la baja.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int darDeBajaConf(eConfederacion* confederaciones, int tamConfederaciones , int* contadorConf);

#endif /* CONFEDERACIONES_H_ */
