/*
 * ingresos.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>

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
int ingresarNumeroDistintoCero(int* array,int reintentos,int *resultado)
{
	//DEBERIA FIJARME QUE HACER CUANDO SE TERMINAN LOS REINTENTOS
	int retorno=-1;
	int numero;
	if(array!=NULL && resultado!=NULL && reintentos>0)
	{
		while(reintentos>1)
		{
			printf("Ingrese un numero entero distinto de cero");
			scanf("%d",&numero);
			if(numero==0)
			{
				printf("ERROR, Recuerde que el numero debe ser distinto a cero\n");
				reintentos=reintentos-1;
				printf("Le quedan %d reintentos \n",reintentos);

			}
			else
			{
				*resultado=numero;
				retorno=0;
			}

		}

	}
	return retorno;
}
int ingresarNumerosConRangoMenosCero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int numero;

	while(retorno==-1 && reintentos>1)
	{
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf(mensaje);
			scanf("%d",&numero);
			if(numero>minimo && numero<maximo && numero!=0)
			{
				*resultado=numero;
				retorno=0;
			}
			else
			{
				printf(mensajeError);
				reintentos= reintentos -1;
				printf("Le quedan %d intentos \n",reintentos);

			}
		}

	}
	return retorno;
}
int ingresarInt2(int* resultado)
{
	int retorno=-1;
	int numeroIngresado;
	int verificacionScanf;
	if(resultado!=NULL)
	{
		while(retorno==-1)
		{
			printf("Ingrese numero entero\n");
			fflush(stdin);
			verificacionScanf=scanf("%d",&numeroIngresado);

			if(verificacionScanf==1)
			{
				*resultado=numeroIngresado;
				retorno=0;
			}
			else
			{
				printf("ERROR, Ingrese un numero\n");
			}
		}
	}
	return retorno;
}
