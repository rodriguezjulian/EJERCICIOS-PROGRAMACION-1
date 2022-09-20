/*
 * ingresos.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */
#include "ingresos.h"

float ingresarFloat(void)
{
	float numeroIngresado;
	printf("Ingrese numero\n");
	scanf("%f",&numeroIngresado);

	return numeroIngresado;
}
int ingresarInt(void)
{
	int numeroIngresado;
	printf("Ingrese numero\n");
	scanf("%d",&numeroIngresado);

	return numeroIngresado;

}
int ingresarNumerosConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int numero;

	while(retorno==-1 && reintentos>1)
	{
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf(mensaje);
			scanf("%d",&numero);
			if(numero>minimo && numero<maximo)
			{
				*resultado=numero;
				retorno=0;
			}
			else
			{
				printf(mensajeError);
				printf("Le quedan %d intentos ",reintentos);
			}
		}
		reintentos= reintentos -1;
	}
	return retorno;
}
