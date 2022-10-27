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
#include "validaciones.h"


#define ANIO 2022 //PARA FUNCION DE FECHA

int ingresarOpcionAlfabeticaMayusc(char* resultado,char* mensaje,char* mensajeError, int minimo ,int maximo )
{
	int retorno=-1;
	char auxiliar;
	if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&auxiliar);
			auxiliar=toupper(auxiliar);

			if(auxiliar>minimo  &&  auxiliar<maximo)
			{
				*resultado=auxiliar;
				retorno=0;
			}else
			{
				printf("%s",mensajeError);
			}
		}while(retorno==-1);
	}
	return retorno;
}
int ingresarIntConMensajeMin(int* resultado,char* mensaje, char* mensajeError, int minimo)
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

				if(verificacionScanf==1 && numeroIngresado>= minimo)
				{
					*resultado=numeroIngresado;
					retorno=0;
				}
				else
				{
					printf("%s",mensajeError);
				}
			}
		}
		return retorno;

}

int ingresarNumConRangoYReintentos(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int numero;
	int retornoScanf=0;
	while(retorno==-1 && reintentos>0)
	{
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf("%s",mensaje);
			retornoScanf=scanf("%d",&numero);
			if(retornoScanf==1)
			{
				if(numero>=minimo && numero<=maximo)
				{
					*resultado=numero;
					retorno=0;
				}
				else
				{
					if(reintentos-1==0)
					{
						printf("<<<<<<<<<<SIN REINTENTOS>>>>>>>>>>\n");
					}
					else
					{
						printf("%s",mensajeError);
						printf("Le quedan %d intentos ",reintentos-1);
					}

				}
			}
			else
			{
				printf("ERROR, Ingrese un numero\n");
			}

		}
		reintentos= reintentos -1;
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
int ingresarNumIntConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo)
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
int ingresarFecha(eFecha* resultado)
{

	eFecha fecha;
	int retorno=-1;
	ingresarIntConMensajeMin(&fecha.anio,"Ingrese anio", "ERROR, ingrese anio valido\n", ANIO);
	ingresarNumIntConRango(&fecha.mes,"Ingrese mes en numero", "ERROR, ingrese mes valido\n",1, 12);
	if(fecha.mes==1 || fecha.mes==3 || fecha.mes==5 || fecha.mes==7 || fecha.mes==8 || fecha.mes==10 || fecha.mes==12)
	{
		ingresarNumIntConRango(&fecha.dia,"Ingrese dia", "ERROR, ingrese dia valido\n",1, 31);
	}
	else
	{
		if(fecha.mes==4 || fecha.mes==6 || fecha.mes==9 || fecha.mes==11)
		{
			ingresarNumIntConRango(&fecha.dia,"Ingrese dia", "ERROR, ingrese dia valido\n",1, 30);
		}
		else
		{
			ingresarNumIntConRango(&fecha.dia,"Ingrese dia", "ERROR, ingrese dia valido\n",1, 28);
		}
		retorno=0;
		*resultado=fecha;
	}
	return retorno;
}
int ingresarCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    if(textoIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0)
    {
    	while(retorno==-1)
    	{
            printf("%s",mensaje);
            fflush(stdin);
            gets(textoIngresado);//GETS SE AGARRA EL BUFFER DEL TECLADO, CORTA EL REGISTRO CON EL ENTER

            if(strlen(textoIngresado)<=tam)
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



