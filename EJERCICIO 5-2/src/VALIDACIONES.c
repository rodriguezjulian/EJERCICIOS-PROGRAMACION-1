/*
 * VALIDACIONES.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */
#include "VALIDACIONES.h"

int validarFloatConRango(float numeroIngresado, int min, int max)
{
	int retorno;
	//0 SALIO BIEN - -1 SALIO MAL
	if(numeroIngresado>=min && numeroIngresado<=max)
	{
		retorno=0;
	}
	else
	{
		retorno=-1;
	}
	return retorno;
}
