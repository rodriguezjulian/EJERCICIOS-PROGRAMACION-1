/*
 * calculos.c
 *
 *  Created on: 14 sep. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
int calcularPromedioArray(int tam, int* array, float* promedio)
{
	int retorno=-1;
	int acumulador;
	acumulador=0;

	if(tam>0 && array!=NULL && promedio!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			acumulador=acumulador+array[i];
		}
		*promedio=(float)acumulador/tam;
		retorno=0;
	}
	return retorno;
}
void inicializarArray(int array[],int tam)
{
	if(array!=NULL)
	{
		for (int i = 0; i < tam; ++ i)
		{
			array[i]=0;
		}
	}
}

