/*
 * transporte.c
 *
 *  Created on: 13 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "ingresos.h"
#include <ctype.h>
#include<string.h>

#include "transporte.h"

#define VACIO 1
#define OCUPADO 0
#define TAM 300
#define ANIO 2022
#define TAM_TIPOS 4

void listarTipos(eTipo* tipo,int tam)
{
	eTipo* pTipo;
	pTipo=tipo;

	if(tipo!=NULL && tam>0)
	{
		printf("+------------TIPOS DE VEHICULOS-----------+\n");

		for(int i=0;i<tam;i++)
		{
			printf("|%*d|%*s|\n",-10,(*(pTipo+i)).idTipo,-30,(*(pTipo+i)).descripcion);
		}
		printf("+-----------------------------------------+\n");
	}
}
int ingresarIdTipo(eTransporte* transporte, eTipo* tipo)
{
	eTransporte* pTransporte;
	pTransporte=transporte;
	int retorno=-1;
	if(transporte!=NULL)
	{
		listarTipos(tipo,TAM_TIPOS);
		ingresarNumerosConRangoV1(&(*(pTransporte)).tipoId, "Ingrese ID segun tipo\n", "ERROR, Ingrese ID valido\n", 1000, 1003);
		retorno=0;
	}
	return retorno;
}


int inicializarIsEmpty(eTransporte* transporte, int tam, int estado)
{
	int retorno=-1;
	eTransporte* pInt;//el puntero a una variable debe tener el MISMO TIPO

	pInt=transporte;//LO IGUAL A LA PRIMER POSICION DE LA ESTRUCTURA

	if(transporte!=NULL  && tam>0)
	{

		for(int i=0;i<TAM;i++)
		{
			//transporte[i].isEmpty=VACIO;
			(*(pInt+i)).isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}

		/*for(int i=0;i<TAM;i++)//HABRIA QUE PASARLO A UNA FUNCION.
		{
			transporte[i].isEmpty=VACIO;//
		}*/
		retorno=0;
	}
	return retorno;
}

int loguearTransporte(int* idTransporte, eTransporte* auxiliar , int* contador, eTipo* tipo)
{
	int retorno=-1;
	eTransporte* pAuxiliar;
	pAuxiliar=auxiliar;

	if(auxiliar!= NULL && idTransporte!=NULL)
	{
		*contador=*contador+1;
		*idTransporte=*idTransporte+1;
		auxiliar->idTransporte=*idTransporte;
		//ENTIENDO QUE LA DESCRIPCION ESTA RELACIONADA CON LA ESTRUCUTRA eTipo
		//ingresarArrayCaracteres((*(pAuxiliar)).descripcion,"Ingrese descripcion del transporte\n","ERROR, Ingrese descripcion valida\n",31);
		ingresarCadenaCaracteres(31,(*(pAuxiliar)).descripcion,"Ingrese descripcion del transporte\n","ERROR, Ingrese descripcion valida\n");
		ingresarFloatConMinimo(&(*(pAuxiliar)).pesoCarga, "Ingrese peso de carga\n","ERROR, Ingrese peso valido\n",0);

		ingresarIntConMensajeMin(&(*(pAuxiliar)).cantidadBultos,"Ingrese cantidad de bultos\n","ERROR, Ingrese cantidad valida\n",0);

		ingresarIdTipo(auxiliar,tipo);


		auxiliar->isEmpty=OCUPADO;

	}
	return retorno;
}
int modificartransporte(eTransporte* transporte,int contador)
{
	int retorno=-1;
	eTransporte auxiliar;
	int posicion;
	int opcion;
	eTransporte* pTransporte;
	pTransporte=transporte;

	if(transporte!=NULL && contador>0)
	{
		ingresarIntConMensajeMin(&auxiliar.idTransporte,"Ingrese id del transporte a modificar\n", "Error, ingrese id valido\n", 0);
		//ingresarIntConMensaje(&auxiliar.idTransporte,"Ingrese id", "Error, ingrese un numero");
		posicion=auxiliar.idTransporte-1;

		if((*(pTransporte)).isEmpty==OCUPADO)
		{
			printf("+----------------------------------------+\n");
			printf("|%*s|\n|%*s|\n|%*s|\n",-40,"          MODIFICAR TRANSPORTE",-40,"1-PESO DE CARGA",-40,"2-CANTIDAD DE BULTOS");
			printf("+----------------------------------------+\n");
			ingresarNumerosConRangoV1(&opcion, "MARQUE SEGUN DESEE OPERAR\n","ERROR, Ingrese opcion valida\n" ,1, 2);

			switch(opcion)
			{
				case 1:
					ingresarFloatConMinimo(&auxiliar.pesoCarga, "Ingrese peso de carga nuevo\n","ERROR, Ingrese peso valido\n",0);
					//transporte[posicion].pesoCarga=auxiliar.pesoCarga;
					(*(pTransporte+posicion)).pesoCarga=auxiliar.pesoCarga;
				break;
				case 2:
					ingresarIntConMensajeMin(&auxiliar.cantidadBultos,"Ingrese nueva cantidad de bultos\n","ERROR, Ingrese cantidad valida\n",0);
					//transporte[posicion].cantidadBultos=auxiliar.cantidadBultos;
					(*(pTransporte+posicion)).cantidadBultos=auxiliar.cantidadBultos;
					break;
			}
		}
		else
		{
			printf("El ID ingresado no corresponde a un transporte\n");
		}
		retorno=0;
	}
	else
	{
		printf("ERROR,No es posible ingresar a estar opcion, deben existir transportes cargados\n");
	}
	return retorno;
}
int bajaTransporte(eTransporte* transporte,int *contador)
{
	int retorno=-1;
	eTransporte auxiliar;
	eTransporte* pTransporte;
	pTransporte=transporte;

	int posicion;
	if(transporte!=NULL && *contador>0)
	{
		ingresarIntConMensajeMin(&auxiliar.idTransporte,"Ingrese id del transporte que desea dar de baja\n", "Error, ingrese id valido\n", 0);
		posicion=auxiliar.idTransporte-1;
		if((*(pTransporte+posicion)).isEmpty==OCUPADO)
		{
			printf("Transporte con ID %d dado de baja satisfactoriamente \n",transporte[posicion].idTransporte);
			//transporte[posicion].isEmpty=VACIO;
			(*(pTransporte+posicion)).isEmpty=VACIO;
			*contador=*contador-1;
		}
		else
		{
			printf("El ID ingresado no corresponde a un transporte\n");
		}
	}
	else
	{
		printf("ERROR,No es posible ingresar a estar opcion, deben existir transportes cargados\n");
	}


	return retorno;
}
int ordenarTransportes(eTransporte* transporte, int tam)
{
	int retorno=-1;
	eTransporte auxiliar;//lo uso solo para el swap

	eTransporte* pTransporte;
	pTransporte=transporte;

	if(transporte!=NULL && tam>0)
	{
		for(int i=0;i<tam-1;i++)
		{
			if((*(pTransporte+i)).isEmpty==OCUPADO)
			{
				for(int j=i+1;j<tam;j++)
				{
					if((*(pTransporte+j)).isEmpty==OCUPADO)
					{
						if((*(pTransporte+i)).tipoId>(*(pTransporte+j)).tipoId)
						{
							auxiliar=*(pTransporte+i);
							*(pTransporte+i)=*(pTransporte+j);
							*(pTransporte+j)=auxiliar;
						}
						else
						{
							if((*(pTransporte+i)).tipoId==(*(pTransporte+j)).tipoId)
							{
								if(strcmp((*(pTransporte+i)).descripcion,(*(pTransporte+j)).descripcion)>0)
								{
									auxiliar=*(pTransporte+i);
									*(pTransporte+i)=*(pTransporte+j);
									*(pTransporte+j)=auxiliar;
								}
							}
						}
					}

				}
			}
		}
	}
	return retorno;
}
int listarTransportes(eTransporte* transporte, int tam, int contador)
{

	int retorno=-1;
	eTransporte* pTransporte;
	pTransporte=transporte;

	if(transporte!=NULL && tam>0 && contador>0)
	{
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|\n",-15,"ID TRANSPORTE",-20,"ID TIPO VEHICULO",-30,"Descripcion",-30,"Peso de carga",-30,"Cantidad de bultos");
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");

		for(int i=0;i<tam;i++)
		{
			if((*(pTransporte+i)).isEmpty==OCUPADO)
			{
				printf("|%*d|%*d|%*s|%*.2f|%*d|\n",-15,(*(pTransporte+i)).idTransporte,-20,(*(pTransporte+i)).tipoId,-30,(*(pTransporte+i)).descripcion,-30,(*(pTransporte+i)).pesoCarga,-30,(*(pTransporte+i)).cantidadBultos);
			}
		}
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");
	}
	else
	{
		printf("ERROR, no se puede operar esta opcion si no hay transportes dados de alta\n");
	}


	return retorno;
}

int listarTransportesDeUnTipo(eTransporte* transporte, int tam, int contador,int tipo)
{

	int retorno=-1;
	eTransporte* pTransporte;
	pTransporte=transporte;

	if(transporte!=NULL && tam>0 && contador>0)
	{
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|\n",-15,"ID TRANSPORTE",-20,"ID TIPO VEHICULO",-30,"Descripcion",-30,"Peso de carga",-30,"Cantidad de bultos");
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");

		for(int i=0;i<tam;i++)
		{
			//if(transporte[i].isEmpty==OCUPADO)
			if((*(pTransporte+i)).isEmpty==OCUPADO && (*(pTransporte+i)).tipoId==tipo)
			{
				//printf("|%*d|%*d|%*s|%*.2f|%*d|\n",-15,transporte[i].idTransporte,-20,transporte[i].tipoId,-30,transporte[i].descripcion,-30,transporte[i].pesoCarga,-30,transporte[i].cantidadBultos);
				printf("|%*d|%*d|%*s|%*.2f|%*d|\n",-15,(*(pTransporte+i)).idTransporte,-20,(*(pTransporte+i)).tipoId,-30,(*(pTransporte+i)).descripcion,-30,(*(pTransporte+i)).pesoCarga,-30,(*(pTransporte+i)).cantidadBultos);
			}
		}
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");

	}
	else
	{
		printf("ERROR, no se puede operar esta opcion si no hay transportes del tipo seleccionado dados de alta\n");
	}


	return retorno;
}

























