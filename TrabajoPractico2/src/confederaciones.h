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

int listarConfederaciones(eConfederacion* confederaciones, int tamConfederaciones);

#endif /* CONFEDERACIONES_H_ */
