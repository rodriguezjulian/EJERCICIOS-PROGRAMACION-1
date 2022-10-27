/*
 * jugadores.c
 *
 *  Created on: 27 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "ingresos.h"
#include<string.h>


#define TAM 3000
#define VACIO 1
#define OCUPADO 0

int inicializarIsEmpty(eJugador* jugadores, int tam, int estado)
{
	int retorno=-1;

	if(jugadores!=NULL  && tam>0)
	{

		for(int i=0;i<TAM;i++)
		{
			(*(jugadores+i)).isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}

		retorno=0;
	}
	return retorno;

}
int loguearJugador(eJugador* jugadores,eConfederacion* confederaciones, int* id,int* contadorJugadores,int tamJugadores)
{
	int retorno=-1;
	eJugador jugadorAuxiliar;
	if(jugadores!=NULL && confederaciones!=NULL)
	{
		if(*contadorJugadores<tamJugadores)
		{
			*id=*id+1;//CADA VEZ QUE INGRESE TOMO AL VALOR QUE LLEGA COMO PARAMETRO PARA SUMARLE UNO Y ASI QUEDE AUTOINCREMENTAL
			jugadorAuxiliar.id=*id;

			*contadorJugadores=*contadorJugadores+1;

			 ingresarCadenaCaracteres( 50,jugadorAuxiliar.nombre,"Ingrese nombre del jugador\n","ERROR, Ingrese nombre valido\n");

			 ingresarCadenaCaracteres( 50,jugadorAuxiliar.posicion,"Ingrese posicion del jugador\n","ERROR, Ingrese posicion valida\n");

			 ingresarShortConRango(&jugadorAuxiliar.numeroCamiseta,"Ingrese numero de camiseta entre 1 y 100\n", "Ingrese numero valido\n", 1,  100);

			 //MOSTRAR LISTADO DE CONFEDERACIONES.
			 listarConfederaciones(confederaciones);
			 ingresarIntConRango(&jugadorAuxiliar.idConfederacion, "Ingrese ID de confederacion\n", "ERROR,Ingrese ID valido\n", 100, 105);

			 ingresarFloatConMinimo(&jugadorAuxiliar.salario,"Ingrese salario","ERROR, ingrese salario valido\n",1);

			 ingresarShortConRango(&jugadorAuxiliar.aniosContrato,"Ingrese anios de contrato entre 1 y 10\n", "Ingrese cantidad valida\n", 1, 10);

			 jugadorAuxiliar.isEmpty=OCUPADO;

			for(int i=0;i<tamJugadores;i++)
			 {
				 if((*(jugadores+i)).isEmpty==VACIO)
				 {
					 (*(jugadores+i))=jugadorAuxiliar;
					 break;
				 }
			 }
		}
		else
		{
			printf("ERROR,SIN ESPACIO EN MEMORIA");
		}
	}
	return retorno;
}
int asignarDescripcion(eJugador* jugadores,eConfederacion* confederaciones,int tamConfederaciones, char* descripcion ,int posicion)
{
	int retorno=-1;


		if(jugadores!=NULL && confederaciones!=NULL)
		{
			retorno=0;
			for(int i=0;i<tamConfederaciones;i++)
			{
				if((*(jugadores+posicion)).idConfederacion==(*(confederaciones+i)).id)
				{
					strcpy(descripcion,(*(confederaciones+i)).nombre);
				}
			}
		}



	return retorno;
}
int ordenarJugadoresAlfabeticamente(eJugador* jugadores,eConfederacion* confederaciones,int contadorJugadores,int tam)
{
	int retorno=-1;
	char descripcionUno[50];
	char descripcionDos[50];

	eJugador jugadorAuxiliar; //PARA EL SWAP

	if(jugadores!=NULL && confederaciones!=NULL && contadorJugadores>0)
	{
		for(int i=0;i<tam-1;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{
				retorno=0;
				for(int j=i+1;j<tam;j++)
				{
					if((*(jugadores+j)).isEmpty==OCUPADO)
					{
						asignarDescripcion(jugadores,confederaciones,6, descripcionUno ,i);
						asignarDescripcion(jugadores,confederaciones,6, descripcionDos ,j);

						printf("DESCRIPCION 1: %s\n",descripcionUno);
						printf("DESCRIPCION 2: %s\n",descripcionDos);

						if(strcmp(descripcionUno, descripcionDos)>0)
						{
							jugadorAuxiliar=(*(jugadores+i));
							(*(jugadores+i))=(*(jugadores+j));
							(*(jugadores+j))=jugadorAuxiliar;
						}
						else
						{	if(strcmp(descripcionUno, descripcionDos)==0)
							{
								//if( (*(jugadores+i)).nombre>(*(jugadores+j)).nombre)
								if(strcmp( (*(jugadores+i)).nombre,(*(jugadores+j)).nombre)>0)
								{
									jugadorAuxiliar=(*(jugadores+i));
									(*(jugadores+i))=(*(jugadores+j));
									(*(jugadores+j))=jugadorAuxiliar;
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
int ordenarJugadoresXId(eJugador* jugadores, int tam)
{
	int retorno=-1;
	eJugador jugadorAuxiliar;

	if(jugadores!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{
				for(int j=i+1;j<tam;j++)
				{
					if((*(jugadores+j)).isEmpty==OCUPADO)
					{
						if((*(jugadores+i)).id>(*(jugadores+j)).id)
						{
								jugadorAuxiliar=(*(jugadores+i));
								(*(jugadores+i))=(*(jugadores+j));
								(*(jugadores+j))=jugadorAuxiliar;
						}
					}
				}
			}
		}
	}
	return retorno;
}
int listarJugadores(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int referenciaOrdenamiento)
{
	//referenciaOrdenamiento -> 1. ordeno por orden alfabetico
	//referenciaOrdenamiento -> 2.ordeno por id
	int retorno=-1;
	char descripcion[50];
	if(jugadores!=NULL && confederaciones!=NULL && contadorJugadores>0)
	{
		retorno=0;
		if(referenciaOrdenamiento==1)
		{
			ordenarJugadoresAlfabeticamente(jugadores,confederaciones,contadorJugadores,tam);
		}
		else
		{
			ordenarJugadoresXId(jugadores, tam);
		}

		printf("+=============================================================================================================================================================================+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",-4," ID",-50,"                     NOMBRE",-50,"                     POSICION",
					-13," N°CAMISETA",-16,"     SUELDO",-15," CONFEDERACION",-20,"  ANIOS DE CONTRATO");
		printf("+=============================================================================================================================================================================+\n");
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{

				//entre=entre+1;
				//printf("ENTRE %d\n",entre);
				asignarDescripcion(jugadores,confederaciones,6, descripcion ,i);
				printf("|%*d|%*s|%*s|%*d|%*.2f|%*s|%*d|\n",-4,(*(jugadores+i)).id,-50,(*(jugadores+i)).nombre,-50,(*(jugadores+i)).posicion,-12,(*(jugadores+i)).numeroCamiseta,-16,(*(jugadores+i)).salario,-15,descripcion,-20,(*(jugadores+i)).aniosContrato);
			}
		}
		printf("+=============================================================================================================================================================================+\n");

	}
	else
	{
		printf("ERROR, Para operar esta opcion debe existir al menos 1 jugador cargado\n");
	}
	return retorno;
}

