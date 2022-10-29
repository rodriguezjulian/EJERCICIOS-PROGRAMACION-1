/*
 * confederaciones.c
 *
 *  Created on: 27 oct. 2022
 *      Author: Julian Rodriguez
 */


#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "jugadores.h"

#include "confederaciones.h"
#define ANIO_ACTUAL 2022
#define VACIO 1
#define OCUPADO 0

int inicializarIsEmptyEConfederacion(eConfederacion* confederaciones, int tamConfederaciones, int estado)
{
	int retorno=-1;

	if(confederaciones!=NULL  && tamConfederaciones>0)
	{

		for(int i=0;i<tamConfederaciones;i++)
		{
			(*(confederaciones+i)).isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}

		retorno=0;
	}
	return retorno;

}
int listarConfederaciones(eConfederacion* confederaciones,int tamConfederaciones)
{
	int retorno=-1;

	if(confederaciones!=NULL)
	{
		retorno=0;

		 printf("+============================================================================================================================+\n");
		 printf("| %*s|%*s|%*s|%*s|\n",-4,"ID",-50,"                     NOMBRE",-50,"                     REGION",-16," ANIO CREACION");
		 printf("+============================================================================================================================+\n");

		 for(int i=0;i<tamConfederaciones;i++)
		 {
			 if((*(confederaciones+i)).isEmpty==OCUPADO)
			 {
				 printf("| %*d|%*s|%*s|%*d|\n",-4,(*(confederaciones+i)).id,-50,(*(confederaciones+i)).nombre,-50,(*(confederaciones+i)).region,-16,(*(confederaciones+i)).anioCreacion);
			 }
		 }
		 printf("+============================================================================================================================+\n");
	}

		return retorno;
}
int loguearConfederacion(int *id,eConfederacion* confederaciones, int tamConfederaciones, int* contadorConf)
{
	int retorno=-1;
	eConfederacion confederacionAux;

	if(confederaciones!=NULL)
	{
		//EL ID VIENE COMO PARAMETRO CON UN VALOR DE 100 Y SE VUELVE AUTOINCREMENTAL
		*id=*id+1;
		//VIENE COMO PARAMETRO CON UN VALOR DE 0, LUEGO SERVIRIA COMO VARIABLE DE CONTROL
		*contadorConf=*contadorConf+1;

		confederacionAux.id=*id;
		ingresarCadenaCaracteres(50, confederacionAux.nombre, "Ingrese nombre de la confederacion\n", "ERROR,Ingrese nombre valido\n");
		ingresarCadenaCaracteres(50, confederacionAux.region, "Ingrese region de la confederacion\n", "ERROR,Ingrese region valida\n");
		ingresarIntConRango(&confederacionAux.anioCreacion, "Ingrese anio de creacion\n", "ERROR, ingrese anio valido\n", 1800, ANIO_ACTUAL);
		confederacionAux.isEmpty=OCUPADO;

		for(int i=0;i<tamConfederaciones;i++)
		{
			if((*(confederaciones+i)).isEmpty==VACIO)
			{
				(*(confederaciones+i))=confederacionAux;
			}
		}
	}
	return retorno;
}

int modificarConfederacion(int *id,eConfederacion* confederaciones, int tamConfederaciones)
{
	int retorno=-1;


	return retorno;
}





