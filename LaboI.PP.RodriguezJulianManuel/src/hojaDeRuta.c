/*
 * hojaDeRuta.j.s
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
			hojaDeRuta[i].isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}
		retorno=0;
	}


	return retorno;
}

int loguearHojaDeRuta(eTransporte* transporte,eHojaDeRuta* hojaAuxiliar, int* idHoja, int contador, int* contadorDeHojas)
{
	int retorno=-1;
	eTransporte transporteAuxiliar;
	int posicion;
	if(transporte!=NULL && hojaAuxiliar!=NULL && contador>0)
	{

		*contadorDeHojas=*contadorDeHojas+1;
		ingresarIntConMensajeMin(&transporteAuxiliar.idTransporte,"Ingrese ID de transporte a utilizar\n", "Error, ingrese id valido\n", 0);
		posicion=transporteAuxiliar.idTransporte-1;

		if(transporte[posicion].isEmpty==OCUPADO)
		{
			//PRECIO DE VIAJE MINIMO $1
			ingresarFloatConMinimo(&hojaAuxiliar->precioViaje, "Ingrese precio del viaje","ERROR, ingrese precio valido\n",1);
			//MINIMO 1KM DE RECORRIDO
			ingresarFloatConMinimo(&hojaAuxiliar->kmTotales, "Ingrese kilometros totales del viaje","ERROR, ingrese kilometraje valido\n",1);
			ingresarFecha(&hojaAuxiliar->fecha);
			*idHoja=*idHoja+1;
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
int listarHojasDeRuta(eHojaDeRuta* hojaDeRuta, int tam,eTransporte* transporte ,int contadorDeHojas)
{
	int retorno=-1;
	if(hojaDeRuta!=NULL && tam>0 && contadorDeHojas>0)
	{
		printf("+--------------------+------------------------------+--------------------+----------+\n");
		printf("|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30,"TRANSPORTE",-20,"PRECIO DEL VIAJE",-10,"KM TOTALES");
		printf("+--------------------+------------------------------+--------------------+----------+\n");
		for(int i=0;i<tam;i++)
		{
			if(hojaDeRuta[i].isEmpty==OCUPADO)
			{
				//NOSE COMO IMPRIMIR LA FECHA -CREO QUE %d/%d/%d DIA-MES-ANIO
				printf("|%*d|%*s|$%*.2f|%*.2f Km |\n",-20,hojaDeRuta[i].idHoja,-30,transporte[i].descripcion,-19,hojaDeRuta[i].precioViaje,-6,hojaDeRuta[i].kmTotales);
			}
		}
		printf("+--------------------+------------------------------+--------------------+----------+\n");
	}
	else
	{
		printf("No hay hojas de ruta para mostrar\n");
	}


	return retorno;
}
int listarHojasDeRutaPorFecha(eHojaDeRuta* hojaDeRuta, eTransporte* transporte,int tam, int contadorDeHojas)
{
	int retorno=-1;
	eFecha fechaAuxiliar; // EN ESTA VARIABLE GUARDO LA FECHA QUE INGRESARA EL USUARIO, LA CUAL USARE PARA COMPARAR CON LAS EXISTENTES.
	if(hojaDeRuta!=NULL && transporte!=NULL && tam>0 && contadorDeHojas>0)
	{
		//printf("ENTRO");
		ingresarFecha(&fechaAuxiliar);
		int aviso=0; //ESTA VARIABLE ES CLAVE PARA IMPRIMIR EL CUADRO DE INFORMES, SI EXISTEN INFORMACION PARA MOSTRAR LOS ENCABEZADOS
					//SE IMPRIMEN UNA SOLA VEZ Y SI NO LA HAY DIRECTAMENTE NUNCA SE IMPRIMEN.

		for(int i=0;i<tam;i++)
		{
			if(fechaAuxiliar.anio==hojaDeRuta[i].fecha.anio && fechaAuxiliar.mes==hojaDeRuta[i].fecha.mes && fechaAuxiliar.dia==hojaDeRuta[i].fecha.dia && aviso==0)
			{
				printf("+--------------------+------------------------------+--------------------+----------+\n");
				printf("|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30,"TRANSPORTE",-20,"PRECIO DEL VIAJE",-10,"KM TOTALES");
				printf("+--------------------+------------------------------+--------------------+----------+\n");
				printf("|%*d|%*s|$%*.2f|%*.2f Km |\n",-20,hojaDeRuta[i].idHoja,-30,transporte[i].descripcion,-19,hojaDeRuta[i].precioViaje,-6,hojaDeRuta[i].kmTotales);

				aviso=1;
			}
			else
			{
				if(fechaAuxiliar.anio==hojaDeRuta[i].fecha.anio && fechaAuxiliar.mes==hojaDeRuta[i].fecha.mes && fechaAuxiliar.dia==hojaDeRuta[i].fecha.dia)
				{
					printf("|%*d|%*s|$%*.2f|%*.2f Km |\n",-20,hojaDeRuta[i].idHoja,-30,transporte[i].descripcion,-19,hojaDeRuta[i].precioViaje,-6,hojaDeRuta[i].kmTotales);
				}
			}
		}

		if(aviso==0)
		{
			printf("No hay hojas de rutas asignadas para la fecha %d/%d/%d",fechaAuxiliar.dia,fechaAuxiliar.mes,fechaAuxiliar.anio);
		}
		else
		{
			//ESTO LO AGREGO POR UN TEMA VISUAL NOMAS, COMO PARA CERRAR EL CUADRITO Y QUE QUEDE PROLIJO
			printf("+--------------------+------------------------------+--------------------+----------+\n");
		}
	}
	else
	{
		printf("No hay hojas de ruta para mostrar\n");
	}

	return retorno;
}

