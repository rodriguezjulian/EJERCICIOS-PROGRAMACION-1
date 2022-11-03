/*
 * nexo.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"
#include "confederaciones.h"

void inicializarArray(int* array,int tam)
{
	if(array!=NULL)
	{
		for (int i = 0; i < tam; ++ i)
		{
			(*(array+i))=0;
		}
	}
}
void inicializarArrayFloat(float* array,int tam)
{
	if(array!=NULL)
	{
		for (int i = 0; i < tam; ++ i)
		{
			(*(array+i))=0;
		}
	}
}
float calcPorcentaje(int total, int parcial)
{
	float resultado;

	resultado=(float)parcial*100/total;


	return resultado;
}

float calcularPromedio(float numeroA, int numeroB)
{
	float resultado;

	resultado=numeroA/numeroB;

	return resultado;
}
int verificarCaracterSN(char letra)
{
	int retorno=-1;

	if(letra=='S' || letra=='N')
	{
		retorno=0;
	}

	return retorno;
}
