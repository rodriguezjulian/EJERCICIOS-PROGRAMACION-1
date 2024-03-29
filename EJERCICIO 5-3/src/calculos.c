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
int calcularMaximoArray(int* array, int* valorMaximo)
{
	int retorno=-1;
	if(array!=NULL && valorMaximo!=NULL)
	{
		*valorMaximo=array[0];
		for(int i=0;i<5;i++)
		{
			//ENTRA Y COMPARA EL VALOR MAXIMO QUE DIJIMOS QUE ES EL DE LA POSICION 0 CON CADA UNA DE LAS POSICIONES DEL ARRAY
			if(*valorMaximo<array[i])
			{
					*valorMaximo=array[i];
			}
		}
		retorno=0;
	}

	return retorno;
}
