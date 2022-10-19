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
 #include<string.h>

#include "transporte.h"
#include "hojaDeRuta.h"
#define VACIO 1
#define OCUPADO 0
#define TAM 300


int inicializarIsEmptyHojaDeRuta(eHojaDeRuta* hojaDeRuta, int tam, int estado)
{
	int retorno=-1;
	eHojaDeRuta* pHojaDeRuta;
	pHojaDeRuta=hojaDeRuta;

	if(hojaDeRuta!=NULL  && tam>0 )
	{
		for(int i=0;i<TAM;i++)//HABRIA QUE PASARLO A UNA FUNCION.
		{
			(*(pHojaDeRuta+i)).isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}
		retorno=0;
	}
	return retorno;
}

int loguearHojaDeRuta(eTransporte* transporte,eHojaDeRuta* hojaAuxiliar, int* idHoja, int contador, int* contadorDeHojas)
{
	int retorno=-1;
	eTransporte transporteAuxiliar;

	//TENGO QUE IGUALAR EL PUNTERO DE HOJA DE RUTA A LA HOJA AUXILIAR, BASICAMENTE PARA EVITAR LA ->
	eHojaDeRuta* pHojaDeRuta;
	pHojaDeRuta=hojaAuxiliar;

	eTransporte* pTransporte;
	pTransporte=transporte;

	int posicion;
	if(transporte!=NULL && hojaAuxiliar!=NULL && contador>0)
	{
		*contadorDeHojas=*contadorDeHojas+1;
		ingresarIntConMensajeMin(&transporteAuxiliar.idTransporte,"Ingrese ID de transporte a utilizar\n", "Error, ingrese id valido\n", 0);
		posicion=transporteAuxiliar.idTransporte-1; //ESTE -1 ES PORQUE EL INDICE ES -1 QUE EL ID AL COMENZAR EN 0.

		if((*(pTransporte+posicion)).isEmpty==OCUPADO)
		{
			//PRECIO DE VIAJE MINIMO $1
			//ingresarFloatConMinimo(&hojaAuxiliar->precioViaje, "Ingrese precio del viaje","ERROR, ingrese precio valido\n",1);
			ingresarFloatConMinimo(&(*pHojaDeRuta).precioViaje, "Ingrese precio del viaje","ERROR, ingrese precio valido\n",1);

			//MINIMO 1KM DE RECORRIDO
			ingresarFloatConMinimo(&(*pHojaDeRuta).kmTotales, "Ingrese kilometros totales del viaje","ERROR, ingrese kilometraje valido\n",1);

			ingresarFecha(&(*pHojaDeRuta).fecha);
			//ID AUTOINCREMENTAL
			*idHoja=*idHoja+1;

			//SI NO HAGO ESTO NUNCA TERMINO DE RELACIONAR LAS ESTRUCTURAS
			(*(pHojaDeRuta)).transporteId=transporteAuxiliar.idTransporte;

			(*(pHojaDeRuta)).idHoja=*idHoja;
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
	eHojaDeRuta* pHojaDeRuta;
	pHojaDeRuta=hojaDeRuta;
	eTransporte* pTransporte;
	pTransporte=transporte;
	if(hojaDeRuta!=NULL && tam>0 && contadorDeHojas>0)
	{
		printf("+--------------------+------------------------------+--------------------+--------------+\n");
		printf("|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30,"TRANSPORTE",-20,"PRECIO DEL VIAJE",-10,"KM TOTALES");
		printf("+--------------------+------------------------------+--------------------+--------------+\n");
		for(int i=0;i<tam;i++)
		{
			//if(hojaDeRuta[i].isEmpty==OCUPADO)
			if((*(pHojaDeRuta+i)).isEmpty==OCUPADO)
			{
				//NOSE COMO IMPRIMIR LA FECHA -CREO QUE %d/%d/%d DIA-MES-ANIO
				//printf("|%*d|%*s|$%*.2f|%*.2f Km |\n",-20,hojaDeRuta[i].idHoja,-30,transporte[i].descripcion,-19,hojaDeRuta[i].precioViaje,-6,hojaDeRuta[i].kmTotales);
				printf("|%*d|%*s|$%*.2f|%*.2f Km |\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,(*(pTransporte+i)).descripcion,-19,(*(pHojaDeRuta+i)).precioViaje,-10,(*(pHojaDeRuta+i)).kmTotales);

			}
		}
		printf("+--------------------+------------------------------+--------------------+--------------+\n");
	}
	else
	{
		printf("No hay hojas de ruta para mostrar\n");
	}


	return retorno;
}
int imprimirTransporteConId(eTransporte* transporte,int transporteId, int tam, char* descripcion)
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

int listarHojasDeRutaPorFecha(eHojaDeRuta* hojaDeRuta, eTransporte* transporte,int tam, int contadorDeHojas)
{
	int retorno=-1;

	int flag=0; //ESTA VARIABLE ES CLAVE PARA IMPRIMIR EL CUADRO DE INFORMES, SI EXISTEN INFORMACION PARA MOSTRAR LOS ENCABEZADOS
						//SE IMPRIMEN UNA SOLA VEZ Y SI NO LA HAY DIRECTAMENTE NUNCA SE IMPRIMEN.

	eFecha fechaAuxiliar; // EN ESTA VARIABLE GUARDO LA FECHA QUE INGRESARA EL USUARIO, LA CUAL USARE PARA COMPARAR CON LAS EXISTENTES.
	eHojaDeRuta* pHojaDeRuta;
	pHojaDeRuta=hojaDeRuta;
	//eTransporte* pTransporte;
	//pTransporte=transporte;

	char descripcion[30];

	if(hojaDeRuta!=NULL && transporte!=NULL && tam>0 && contadorDeHojas>0)
	{
		//printf("ENTRO");
		ingresarFecha(&fechaAuxiliar);
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRO  DOS");
			//if(fechaAuxiliar.anio==hojaDeRuta[i].fecha.anio && fechaAuxiliar.mes==hojaDeRuta[i].fecha.mes && fechaAuxiliar.dia==hojaDeRuta[i].fecha.dia && flag==0)
			if(fechaAuxiliar.anio==(*(pHojaDeRuta+i)).fecha.anio && fechaAuxiliar.mes==(*(pHojaDeRuta+i)).fecha.mes && fechaAuxiliar.dia==(*(pHojaDeRuta+i)).fecha.dia && flag==0)
			{
				//printf("ENTRO  TRES");
				printf("+--------------------+------------------------------+--------------------+----------+--------+\n");
				printf("|%*s|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30," ID TRANSPORTE",-20,"PRECIO DEL VIAJE",-10,"KM TOTALES",-8,"FECHA");
				printf("+--------------------+------------------------------+--------------------+----------+--------+\n");
				//ESTE ANDABA MOSTRANDO 1 VEZ DESCRIPCION
				imprimirTransporteConId(transporte,(*(pHojaDeRuta+i)).transporteId, TAM, descripcion);
				printf("|%*d|%*s|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,descripcion,-19,(*(pHojaDeRuta+i)).precioViaje,-6,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);

				//printf("|%*d|%*d|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,(*(pHojaDeRuta+i)).transporteId,-19,(*(pHojaDeRuta+i)).precioViaje,-6,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);
				flag=1;
			}
			else
			{
				//if(fechaAuxiliar.anio==hojaDeRuta[i].fecha.anio && fechaAuxiliar.mes==hojaDeRuta[i].fecha.mes && fechaAuxiliar.dia==hojaDeRuta[i].fecha.dia)
				if(fechaAuxiliar.anio==(*(pHojaDeRuta+i)).fecha.anio && fechaAuxiliar.mes==(*(pHojaDeRuta+i)).fecha.mes && fechaAuxiliar.dia==(*(pHojaDeRuta+i)).fecha.dia)
				{
					//ESTE ANDABA MOSTRANDO ID %D
					//printf("|%*d|%*d|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,(*(pHojaDeRuta+i)).transporteId,-19,(*(pHojaDeRuta+i)).precioViaje,-6,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);

					imprimirTransporteConId(transporte,(*(pHojaDeRuta+i)).transporteId, TAM, descripcion);
					printf("|%*d|%*s|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,descripcion,-19,(*(pHojaDeRuta+i)).precioViaje,-6,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);



					//MOSTRANDO DESCRIPCION
					//printf("|%*d|%*s|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,(*(pTransporte+i)).descripcion,-19,(*(pHojaDeRuta+i)).precioViaje,-6,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);

				}
			}
		}

		if(flag==0)
		{
			printf("No hay hojas de rutas asignadas para la fecha %d/%d/%d",fechaAuxiliar.dia,fechaAuxiliar.mes,fechaAuxiliar.anio);
		}
		else
		{
			//ESTO LO AGREGO POR UN TEMA VISUAL NOMAS, COMO PARA CERRAR EL CUADRITO Y QUE QUEDE PROLIJO
			printf("+--------------------+------------------------------+--------------------+----------+--------+\n");
		}
	}
	else
	{
		printf("No hay hojas de ruta para mostrar\n");
	}

	return retorno;
}

































