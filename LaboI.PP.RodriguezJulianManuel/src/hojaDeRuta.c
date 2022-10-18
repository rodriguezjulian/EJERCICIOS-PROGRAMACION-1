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
#define ANIO 2022

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
int ingresarFecha(eFecha* resultado)
{

	eFecha fecha;
	int retorno=-1;
	ingresarIntConMensajeMin(&fecha.anio,"Ingrese año", "ERROR, ingrese año valido", ANIO);
	ingresarNumerosConRangoV1(&fecha.mes,"Ingrese mes en numero", "ERROR, ingrese mes valido",1, 12);
	if(fecha.mes==1 || fecha.mes==3 || fecha.mes==5 || fecha.mes==7 || fecha.mes==8 || fecha.mes==10 || fecha.mes==12)
	{
		ingresarNumerosConRangoV1(&fecha.dia,"Ingrese dia", "ERROR, ingrese dia valido",1, 31);
	}
	else
	{
		if(fecha.mes==4 || fecha.mes==6 || fecha.mes==9 || fecha.mes==11)
		{
			ingresarNumerosConRangoV1(&fecha.dia,"Ingrese dia", "ERROR, ingrese dia valido",1, 30);
		}
		else
		{
			ingresarNumerosConRangoV1(&fecha.dia,"Ingrese dia", "ERROR, ingrese dia valido",1, 28);
		}
		*resultado=fecha;
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
				//NOSE COMO IMPRIMIR LA FECHA
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

