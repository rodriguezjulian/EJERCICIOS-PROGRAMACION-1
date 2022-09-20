/*
 * conversiones.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */

#include "conversiones.h"

int convertirAFarenheit(float temperaturaIngresada, float* resultado)
{
	int retorno;
	retorno=-1;
	if(resultado!=NULL)
	{
		*resultado=(temperaturaIngresada*9/5)+32;
		retorno=0;
	}
	//(100 °C × 9/5) + 32 = 212 °F
	return retorno;
}
int convertirACelcius(float temperaturaIngresada, float* resultado)
{
	int retorno;
	retorno=-1;
	if(resultado!=NULL)
	{
		*resultado=(temperaturaIngresada-32)*5/9;
		//[°C] = (100°F − 32) × 5 ⁄ 9.
		retorno=0;
	}

	return retorno;
}
