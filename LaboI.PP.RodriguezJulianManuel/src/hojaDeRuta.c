/*
 * hojaDeRuta.c
 *
 *  Created on: 13 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>

#include "ingresos.h"
#include <ctype.h>
#include<string.h>
 #include<string.h>

#include "transporte.h"
#include "hojaDeRuta.h"
#define VACIO 1
#define OCUPADO 0
#define TAM 300


int inicializarIsEmptyHojaDeRuta(eHojaDeRuta* hojaDeRuta, int tam, int estado)
{
	int retorno=-1;
	if(hojaDeRuta!=NULL  && tam>0 )
	{
		for(int i=0;i<TAM;i++)//HABRIA QUE PASARLO A UNA FUNCION.
		{
			(*(hojaDeRuta+i)).isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}
		retorno=0;
	}
	return retorno;
}

int loguearHojaDeRuta(eTransporte* transporte,eHojaDeRuta* hojaAuxiliar, int* idHoja, int contador, int* contadorDeHojas)
{
	int retorno=-1;
	eTransporte transporteAuxiliar;
	eFecha fechaAuxiliar;
	int posicion;
	if(transporte!=NULL && hojaAuxiliar!=NULL && contador>0)
	{
		do
		{
			listarTransportes(transporte,TAM,contador);
			ingresarIntConMensajeMin(&transporteAuxiliar.idTransporte,"Ingrese ID de transporte a utilizar\n", "Error, ingrese id valido\n", 0);

			posicion=transporteAuxiliar.idTransporte-1; //ESTE -1 ES PORQUE EL INDICE ES -1 QUE EL ID AL COMENZAR EN 0.

			if((*(transporte+posicion)).isEmpty==OCUPADO)
			{
				*contadorDeHojas=*contadorDeHojas+1;
				//PRECIO DE VIAJE MINIMO $1
				//ingresarFloatConMinimo(&hojaAuxiliar->precioViaje, "Ingrese precio del viaje","ERROR, ingrese precio valido\n",1);
				ingresarFloatConMinimo(&(*hojaAuxiliar).precioViaje, "Ingrese precio del viaje","ERROR, ingrese precio valido\n",1);

				//MINIMO 1KM DE RECORRIDO
				ingresarFloatConMinimo(&(*hojaAuxiliar).kmTotales, "Ingrese kilometros totales del viaje","ERROR, ingrese kilometraje valido\n",1);

				ingresarFecha(&fechaAuxiliar);
				(*(hojaAuxiliar)).fecha=fechaAuxiliar;
				//ID AUTOINCREMENTAL
				*idHoja=*idHoja+1;

				//SI NO HAGO ESTO NUNCA TERMINO DE RELACIONAR LAS ESTRUCTURAS
				(*(hojaAuxiliar)).transporteId=transporteAuxiliar.idTransporte;

				(*(hojaAuxiliar)).idHoja=*idHoja;

				(*(hojaAuxiliar)).isEmpty=OCUPADO;

				retorno=0;
			}
			else
			{
				printf("El ID ingresado no corresponde a un transporte\n\n\n");
			}

		}while(retorno==-1);
	}

	return retorno;
}
int asignarDescripcionTransporteConId(eTransporte* transporte,int transporteId, int tam, char* descripcion)
{
	//TOMANDO EL ID DESDE LA ESTRUCTURA DE HOJA DE RUTA, BUSCO LA DESCRIPCION DENTRO DE TRANSPORTE
	int retorno=-1;
	int posicion;
	/*eTransporte* pTransporte;
	pTransporte=transporte;*/

	posicion=transporteId-1;//MENOS -1 PORQUE ESTOY BUSCANDO TRABAJAR CON LA POSICION
	if(transporte!=NULL && tam>0)
	{
		//strcpy(destino, origen)
		strcpy(descripcion, (*(transporte+posicion)).descripcion);
		retorno=0;
	}
	return retorno;
}

int listarHojasDeRuta(eHojaDeRuta* hojaDeRuta, int tam,eTransporte* transporte ,int contadorDeHojas)
{
	int retorno=-1;

	char descripcion[30];
	if(hojaDeRuta!=NULL && tam>0 && contadorDeHojas>0)
	{
		printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30,"TRANSPORTE",-20,"PRECIO DEL VIAJE",-14,"KM TOTALES",-8,"FECHA");
		printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
		for(int i=0;i<tam;i++)
		{
			//if(hojaDeRuta[i].isEmpty==OCUPADO)
			if((*(hojaDeRuta+i)).isEmpty==OCUPADO)
			{
				asignarDescripcionTransporteConId(transporte,(*(hojaDeRuta+i)).transporteId, TAM, descripcion);
				//printf("|%*d|%*s|$%*.2f|%*.2f Km |\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,(*(pTransporte+i)).descripcion,-19,(*(pHojaDeRuta+i)).precioViaje,-10,(*(pHojaDeRuta+i)).kmTotales);
				printf("|%*d|%*s|$%*.2f|%*.2f|%d/%d/%d|\n",-20,(*(hojaDeRuta+i)).idHoja,-30,descripcion,-19,(*(hojaDeRuta+i)).precioViaje,-14,(*(hojaDeRuta+i)).kmTotales,(*(hojaDeRuta+i)).fecha.dia,(*(hojaDeRuta+i)).fecha.mes,(*(hojaDeRuta+i)).fecha.anio);
				retorno=0;
			}
		}
		printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
	}
	else
	{
		printf("No hay hojas de ruta para mostrar\n");
	}


	return retorno;
}


























