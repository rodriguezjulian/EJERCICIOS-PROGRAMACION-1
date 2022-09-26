/*
 * ingresos.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>

int ingresarNumerosConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int numero;

	while(retorno==-1 && reintentos>1)
	{
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf("%s",mensaje);
			scanf("%d",&numero);
			if(numero>=minimo && numero<=maximo)
			{
				*resultado=numero;
				retorno=0;
			}
			else
			{
				printf("%s",mensajeError);
				printf("Le quedan %d intentos ",reintentos);
			}
		}
		reintentos= reintentos -1;
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
int ingresarFloat2(float* resultado,char* mensaje)
{
	int retorno=-1;
	float numeroIngresado;
	int verificacionScanf;
	if(resultado!=NULL)
	{
		while(retorno==-1)
		{
			if(mensaje!=NULL)
			{
				printf("%s \n", mensaje);
				fflush(stdin);
				verificacionScanf=scanf("%f",&numeroIngresado);

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
	}
	return retorno;
}
int ingresarFloatConMinimo(float* resultado, char* mensaje,char*mensajeError,int minimo)
{
	int retorno=-1;
	float numero;
	do
	{
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
		{
			//int ingresarFloat2(float* resultado,char* mensaje)
			ingresarFloat2(&numero,mensaje);
			if(numero>=minimo)
			{
				*resultado=numero;
				retorno=0;
			}
			else
			{
				printf("%s",mensajeError);
			}
		}
	}while(retorno!=0);

	return retorno;
}

int ingresarNumerosConRangoV1(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno=-1;
	int numero;
	int verificacionScanf=0;
	do
	{
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf("%s",mensaje);
			fflush(stdin);
			verificacionScanf=scanf("%d",&numero);
			if(verificacionScanf==1)
			{
				if(numero>=minimo && numero<=maximo)
				{
					*resultado=numero;
					retorno=0;
				}
				else
				{
					printf("%s",mensajeError);
				}
			}
			else
			{
				printf("ERROR, Ingrese un numero\n");
			}
		}
	}while(retorno!=0);

	return retorno;
}
int ingresarIntConMensaje(int* resultado,char* mensaje)
{
	int retorno=-1;
	int numeroIngresado;
	int verificacionScanf;
	if(resultado!=NULL && mensaje!=NULL)
	{
		while(retorno==-1)
		{
			printf("%s",mensaje);
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


