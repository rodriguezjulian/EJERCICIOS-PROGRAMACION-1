/*
 * InformesPP.c
 *
 *  Created on: 20 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>

#include "ingresos.h"
#include <ctype.h>
#include "transporte.h"
#include "hojaDeRuta.h"
#include "validaciones.h"
#define VACIO 1
#define OCUPADO 0
#define TAM 300
#define ANIO 2022
#define TAM_TIPOS 4

int listarTransportesDeUnTipo(eTransporte* transporte, int tam,int tipo)
{

	int retorno=-1;
	eTransporte* pTransporte;
	pTransporte=transporte;

	if(transporte!=NULL && tam>0)
	{
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|\n",-15,"ID TRANSPORTE",-20,"ID TIPO VEHICULO",-30,"Descripcion",-30,"Peso de carga",-30,"Cantidad de bultos");
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");

		for(int i=0;i<tam;i++)
		{
			//if(transporte[i].isEmpty==OCUPADO)
			if((*(pTransporte+i)).isEmpty==OCUPADO && (*(pTransporte+i)).tipoId==tipo)
			{
				retorno=0;
				//printf("|%*d|%*d|%*s|%*.2f|%*d|\n",-15,transporte[i].idTransporte,-20,transporte[i].tipoId,-30,transporte[i].descripcion,-30,transporte[i].pesoCarga,-30,transporte[i].cantidadBultos);
				printf("|%*d|%*d|%*s|%*.2f|%*d|\n",-15,(*(pTransporte+i)).idTransporte,-20,(*(pTransporte+i)).tipoId,-30,(*(pTransporte+i)).descripcion,-30,(*(pTransporte+i)).pesoCarga,-30,(*(pTransporte+i)).cantidadBultos);
			}
		}
		printf("+---------------+--------------------+------------------------------+------------------------------+------------------------------+\n");

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
				printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
				printf("|%*s|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30,"TRANSPORTE",-20,"PRECIO DEL VIAJE",-14,"KM TOTALES",-8,"FECHA");
				printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
				//ESTE ANDABA MOSTRANDO 1 VEZ DESCRIPCION
				asignarDescripcionTransporteConId(transporte,(*(pHojaDeRuta+i)).transporteId, TAM, descripcion);
				printf("|%*d|%*s|$%*.2f|%*.2f|%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,descripcion,-19,(*(pHojaDeRuta+i)).precioViaje,-14,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);

				//printf("|%*d|%*d|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,(*(pHojaDeRuta+i)).transporteId,-19,(*(pHojaDeRuta+i)).precioViaje,-6,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);
				flag=1;
				retorno=0;
			}
			else
			{
				//if(fechaAuxiliar.anio==hojaDeRuta[i].fecha.anio && fechaAuxiliar.mes==hojaDeRuta[i].fecha.mes && fechaAuxiliar.dia==hojaDeRuta[i].fecha.dia)
				if(fechaAuxiliar.anio==(*(pHojaDeRuta+i)).fecha.anio && fechaAuxiliar.mes==(*(pHojaDeRuta+i)).fecha.mes && fechaAuxiliar.dia==(*(pHojaDeRuta+i)).fecha.dia)
				{
					//ESTE ANDABA MOSTRANDO ID %D
					//printf("|%*d|%*d|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,(*(pHojaDeRuta+i)).transporteId,-19,(*(pHojaDeRuta+i)).precioViaje,-6,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);

					asignarDescripcionTransporteConId(transporte,(*(pHojaDeRuta+i)).transporteId, TAM, descripcion);
					printf("|%*d|%*s|$%*.2f|%*.2f|%d/%d/%d|\n",-20,(*(pHojaDeRuta+i)).idHoja,-30,descripcion,-19,(*(pHojaDeRuta+i)).precioViaje,-14,(*(pHojaDeRuta+i)).kmTotales,(*(pHojaDeRuta+i)).fecha.dia,(*(pHojaDeRuta+i)).fecha.mes,(*(pHojaDeRuta+i)).fecha.anio);



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
			printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
		}
	}
	else
	{
		printf("ERROR, Para operar esta opcion primero debe crear al menos 1 hoja de ruta\n");
	}

	return retorno;
}
int informarImporteDeHojasPorId(eTransporte* transporte,int contador, eHojaDeRuta* hojaDeRuta, int contadorDeHojas ,int tam)
{
	//DEBO USAR EL CONTADOR PARA LLAMAR A LA FUNCION listarTransportes(transporte, TAM,  contador);
	//MAS ALLA QUE YA SEPA QUE HAY TRANSPORTES PORQUE SE PERMITIO EL ACCESO AL CASE
	int retorno=-1;
	eTransporte auxiliar;
	eTransporte* pTransporte;
	eHojaDeRuta* pHojaDeRutaAuxiliar;

	pTransporte=transporte;
	pHojaDeRutaAuxiliar=hojaDeRuta;
	int posicion;
	int flag=0; //PARA MOSTRAR EL MENU SOLA UNA VEZ
	int importeTotal=0; //este importe corresponde al total de las hojas de ruta que pertenecen al ID elegido por el usuario.

	if(transporte!=NULL && hojaDeRuta!=NULL && contadorDeHojas>0)
	{
		//LISTO LOS TRANSPORTES EXISTENTES PARA QUE LE SEA MAS FACIL AL USUARIO ELEGIR.
		listarTransportes(transporte, tam, contador);

		ingresarIntConMensajeMin(&auxiliar.idTransporte,"Ingrese id del transporte del que desea informar el importe total de las hojas de ruta realizadas \n", "Error, ingrese id valido\n", 0);

		posicion=auxiliar.idTransporte-1;

		if((*(pTransporte+posicion)).isEmpty==OCUPADO)
		{
			for(int i=0;i<tam;i++)
			{
				//if((*(pHojaDeRutaAuxiliar+i)).transporteId==(*(pTransporte+posicion)).idTransporte && flag==0)
				if((*(pHojaDeRutaAuxiliar+i)).transporteId==(*(pTransporte+posicion)).idTransporte && flag== 0)
				{
					printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
					printf("|%*s|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30,"TRANSPORTE SELECCIONADO",-20,"PRECIO DEL VIAJE",-14,"KM TOTALES",-8,"FECHA");
					printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
					printf("|%*d|%*s|$%*.2f|%*.2f|%d/%d/%d|\n",-20,(*(pHojaDeRutaAuxiliar+i)).idHoja,-30,(*(pTransporte+posicion)).descripcion,-19,(*(pHojaDeRutaAuxiliar+i)).precioViaje,-14,(*(pHojaDeRutaAuxiliar+i)).kmTotales,(*(pHojaDeRutaAuxiliar+i)).fecha.dia,(*(pHojaDeRutaAuxiliar+i)).fecha.mes,(*(pHojaDeRutaAuxiliar+i)).fecha.anio);
					//(*(pTransporte+i))
					importeTotal=importeTotal+(*(hojaDeRuta+i)).precioViaje;
					//importeTotal=importeTotal+hojaDeRuta[i].precioViaje;
					flag=1;
				}
				else
				{
					if((*(pHojaDeRutaAuxiliar+i)).transporteId==(*(pTransporte+posicion)).idTransporte)
					{
						//importeTotal=importeTotal+hojaDeRuta[i].precioViaje;
						importeTotal=importeTotal+(*(hojaDeRuta+i)).precioViaje;
						printf("|%*d|%*s|$%*.2f|%*.2f|%d/%d/%d|\n",-20,(*(pHojaDeRutaAuxiliar+i)).idHoja,-30,(*(pTransporte+posicion)).descripcion,-19,(*(pHojaDeRutaAuxiliar+i)).precioViaje,-14,(*(pHojaDeRutaAuxiliar+i)).kmTotales,(*(pHojaDeRutaAuxiliar+i)).fecha.dia,(*(pHojaDeRutaAuxiliar+i)).fecha.mes,(*(pHojaDeRutaAuxiliar+i)).fecha.anio);
					}
				}
			}
		}
		else
		{
			printf("El ID ingresado no corresponde a un transporte existente.\n");
		}
	}
	else
	{	//se valida en el ingreso a case H la existencia de un transporte
		printf("\nERROR, Para operar esta opcion primero debe crear al menos 1 hoja de ruta\n");
	}

	if(flag==1)
	{
		retorno=0;
		printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");

		printf("==============================================================================\n");
		printf("+|%*s%*d||+\n",-37,"IMPORTE TOTAL ACUMULADO",-38,importeTotal);
		printf("==============================================================================\n");
	}/*else
	{
		printf("El transporte aun no tiene hojas de ruta para mostrar\n");
	}*/

	return retorno;
}
int informarImpTotalDeHojasPorTipoyFecha(int tam, int tamTipos,eTipo* tipos,int opcionDeInformes , eTransporte* transportes,eHojaDeRuta*  hojaDeRuta,int* volverMenu ,int contadorDeHojas)
{
	int retorno=-1;
	int controlRetorno;
	eFecha fechaAuxiliar;
	int flag=0;
	int importeTotal=0;
	char descripcion[31];
	if(tipos!=NULL && transportes!=NULL && contadorDeHojas>0)
	{
		listarTipos(tipos,tamTipos);
		controlRetorno=ingresarNumConRangoYReintentos(&opcionDeInformes, "Ingrese tipo por ID\n","ERROR,Ingrese ID valido\n", 1000, 1003,3);

		if(controlRetorno!=-1 && verificarExistenciaDeTipoDeTransporte(transportes, opcionDeInformes, tam)==0)
		{
			ingresarFecha(&fechaAuxiliar);

			for(int i=0;i<tam;i++)
			{
				if(fechaAuxiliar.anio==(*(hojaDeRuta+i)).fecha.anio && fechaAuxiliar.mes==(*(hojaDeRuta+i)).fecha.mes && fechaAuxiliar.dia==(*(hojaDeRuta+i)).fecha.dia && flag==0)
				{

					flag=1;
					retorno=0;
					importeTotal=importeTotal+(*(hojaDeRuta+i)).precioViaje;

					printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
					printf("|%*s|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30,"TRANSPORTE",-20,"PRECIO DEL VIAJE",-14,"KM TOTALES",-8,"FECHA");
					printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");
					asignarDescripcionTransporteConId(transportes,(*(hojaDeRuta+i)).transporteId, TAM, descripcion);
					printf("|%*d|%*s|$%*.2f|%*.2f|%d/%d/%d|\n",-20,(*(hojaDeRuta+i)).idHoja,-30,descripcion,-19,(*(hojaDeRuta+i)).precioViaje,-14,(*(hojaDeRuta+i)).kmTotales,(*(hojaDeRuta+i)).fecha.dia,(*(hojaDeRuta+i)).fecha.mes,(*(hojaDeRuta+i)).fecha.anio);
				}
				else
				{

					if(fechaAuxiliar.anio==(*(hojaDeRuta+i)).fecha.anio && fechaAuxiliar.mes==(*(hojaDeRuta+i)).fecha.mes && fechaAuxiliar.dia==(*(hojaDeRuta+i)).fecha.dia)
					{
						importeTotal=importeTotal+(*(hojaDeRuta+i)).precioViaje;
						asignarDescripcionTransporteConId(transportes,(*(hojaDeRuta+i)).transporteId, TAM, descripcion);
						printf("|%*d|%*s|$%*.2f|%*.2f|%d/%d/%d|\n",-20,(*(hojaDeRuta+i)).idHoja,-30,descripcion,-19,(*(hojaDeRuta+i)).precioViaje,-14,(*(hojaDeRuta+i)).kmTotales,(*(hojaDeRuta+i)).fecha.dia,(*(hojaDeRuta+i)).fecha.mes,(*(hojaDeRuta+i)).fecha.anio);
					}
				}
			}
			if(flag==0)
			{
				printf("No hay hojas de rutas asignadas para la fecha %d/%d/%d",fechaAuxiliar.dia,fechaAuxiliar.mes,fechaAuxiliar.anio);
			}
			else
			{
				printf("+--------------------+------------------------------+--------------------+--------------+--------+\n");

				printf("==============================================================================\n");
				printf("+|%*s%*d||+\n",-37,"IMPORTE TOTAL ACUMULADO",-38,importeTotal);
				printf("==============================================================================\n");
			}

		}
		else
		{
			//SI SE QUEDA SIN REITENTOS VA AL MENU PRINCIPAL OTRA VEZ
			*volverMenu=1;
		}
	}
	else
	{
		printf("\nERROR, Para operar esta opcion primero debe crear al menos 1 hoja de ruta\n");
	}
	return retorno;
}


