/*
 * ingresos.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "ingresos.h"


int ingresarFloat(float* resultado,char* mensaje)
{
	int retorno=-1;
	int flag;
	char	numero[999999];
	int tamIngreso;
	do
	{
		flag=0;
		if(resultado!=NULL && mensaje!=NULL)
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(numero);
			tamIngreso=strlen(numero);
            for(int i=0;i<tamIngreso;i++)
            {
            	if(isdigit((*(numero+i)))==0)
            	{
            		flag=1;
            		printf("ERROR, Ingrese un numero\n");
            		break;
            	}
            }
            if(flag==0)
            {
            	retorno=0;
            	*resultado=atoi(numero);
            }
		}

	}while(retorno!=0);
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
			ingresarFloat(&numero,mensaje);
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
int ingresarIntConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno=-1;
	int flag;
	int tamIngreso;
	char numero[999999];

	do
	{
		flag=0;
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(numero);

            tamIngreso=strlen(numero);

            for(int i=0;i<tamIngreso;i++)
            {
            	if(isdigit((*(numero+i)))==0)
            	{
            		flag=1;
            		printf("ERROR, Ingrese un numero\n");
            		break;
            	}
            }
            if(flag==0)
            {
            	*resultado=atoi(numero);
                if(*resultado>=minimo && *resultado<= maximo)
                {
                	retorno=0;
                }
                else
                {
                	printf("%s",mensajeError);
                }
            }
		}

	}while(retorno!=0);

	return retorno;
}

/*int confirmarSalida(void)
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
}*/

int ingresarCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    int tamIngreso;
    int flag;
    if(textoIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0)
    {
    	while(retorno==-1)
    	{
    		flag=0;
            printf("%s",mensaje);
            fflush(stdin);
            gets(textoIngresado);//GETS SE AGARRA EL BUFFER DEL TECLADO, CORTA EL REGISTRO CON EL ENTER

            tamIngreso=strlen(textoIngresado);

            for(int i=0;i<tamIngreso;i++)
            {
            	if(isdigit((*(textoIngresado+i)))!=0)
            	{
            		flag=1;
            		break;
            	}
            }
            if(strlen(textoIngresado)<=tam && flag==0)
            {
            	retorno=0;
            }else
            {
            	printf("%s",mensajeError);
            }
    	}

    }
    return retorno;
}
int ingresarShortConRango(short* resultado, char* mensaje, char* mensajeError, short minimo, short maximo)
{
	short retorno=-1;
	int flag;
	int tamIngreso;
	char numero[999999];
	do
		{
			flag=0;
			if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
			{
				printf("%s",mensaje);
				fflush(stdin);
				gets(numero);

	            tamIngreso=strlen(numero);

	            for(int i=0;i<tamIngreso;i++)
	            {
	            	if(isdigit((*(numero+i)))==0)
	            	{
	            		flag=1;
	            		printf("ERROR, Ingrese un numero\n");
	            		break;
	            	}
	            }
	            if(flag==0)
	            {
	            	*resultado=atoi(numero);
	                if(*resultado>=minimo && *resultado<= maximo)
	                {
	                	retorno=0;
	                }
	                else
	                {
	                	printf("%s",mensajeError);
	                }
	            }
			}

		}while(retorno!=0);
	return retorno;
}

