/*
 * ingresos.c
 *S
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "ingresos.h"
int verificarCaracterSN(char letra)
{
	int retorno=-1;

	if(letra=='S' || letra=='N')
	{
		retorno=0;
	}

	return retorno;
}

int confirmarSalida(void)
{
	int retorno=-1;
	char respuesta;
	int reintentos=3;

	do
	{
		printf("\nPara seguir operando presione S|N");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);

		reintentos=reintentos-1;
		if(verificarCaracterSN(respuesta)==-1 )
		{
			printf("ERROR, ingrese opcion valida\nReintentos restantes: %d\n\n",reintentos);
		}
	}while(verificarCaracterSN(respuesta)==-1 && reintentos>0);


	if(respuesta!='S')
	{
		printf("Confirme que desea SALIR presionando X \nPara continuar operando ingrese cualquier otra tecla");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);

		if(respuesta=='X')
		{
			printf("<<<<<<<<<<<<<<<<<<<<SALIR>>>>>>>>>>>>>>>>>>>");
			retorno=0;
		}
	}
	return retorno;
}
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
			printf("%s",mensaje);
			scanf("%d",&numero);
			if(numero>=minimo && numero<maximo && numero!=0)
			{
				*resultado=numero;
				retorno=0;
			}
			else
			{
				printf("%s",mensajeError);
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
int ingresarIntConMinimo(int* resultado, char* mensaje,char*mensajeError,int minimo)
{
	int retorno=-1;
	int numero;
	do
	{
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
		{
			//int ingresarFloat2(float* resultado,char* mensaje)
			ingresarIntConMensaje(&numero,mensaje);
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

int validarAlfanumerico(char* array)
{
	int controlIsDigit=0;
	int controlIsAlpha=0;
	int retorno;
	if(array!=NULL)
	{
		for(int i=0;i<strlen(array);i++)
		{
			if(isdigit(array[i])!=0)
			{
				controlIsDigit=controlIsDigit+1;
			}
			if(isalpha(array[i])!=0)
			{
				controlIsAlpha=controlIsAlpha+1;
			}
		}
		if((controlIsDigit+controlIsAlpha)==strlen(array) && controlIsDigit>0 && controlIsAlpha>0)
		{
			retorno=0;
		}else
		{
			retorno=-1;
		}
	}

	return retorno;
}
int esNumerica(char* cadena)
{
	int retorno=0;
	if(cadena!=NULL)
	{
		for(int i=0;cadena[i]!='\0';i++)
		{
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno=-1;
				break;
			}
		}
	}

	return retorno;
}
int ingresarTelefonoDos(char* resultado)
{
	int retorno=-1;
	char auxiliar[8];
	int longitud;
	int verificacionDeCaracter;

	if(resultado!=NULL)
	{
		while(retorno==-1)
		{
			printf("Ingrese numero telefonico ");
			fflush(stdin);
			scanf("%s",auxiliar);

			longitud=strlen(auxiliar);
			verificacionDeCaracter=esNumerica(auxiliar);

			//printf("ES NUMERICA %d\n",verificacionDeCaracter);
			if(longitud==8 && verificacionDeCaracter==0)
			{
				strcpy(resultado, auxiliar);
				retorno=0;
			}
			else
			{
				printf("ERROR, ingrese 8 numeros\n");
			}
		}
		for(int i=0;i<4;i++)
		{
			printf("%c",resultado[i]);
		}
		printf("-");
		for(int i=4;i<8;i++)
		{

			printf("%c",resultado[i]);
		}

	}
	return retorno;
}

int ingresarArrayCaracteres(char*array,char* mensaje,char* mensajeError,int longitud)
{
	char textoIngresado[longitud];
	int retorno=-1;
	if(array!=NULL && mensaje!=NULL && mensajeError!=NULL && longitud>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",textoIngresado);
		strcpy(array,textoIngresado);
		while(strlen(textoIngresado)>=longitud)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%s",textoIngresado);
			strcpy(array,textoIngresado);
		}
		retorno=0;
	}
	return retorno;
}

