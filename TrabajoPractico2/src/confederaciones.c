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
int listarConfederaciones(eConfederacion* confederaciones,int tamConfederaciones, int contadorConf)
{
	int retorno=-1;

	if(confederaciones!=NULL && contadorConf>0)
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
	else
	{
		printf("ERROR, Debe existir al menos una confederacion cargada.\n");
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
				break;
			}
		}
	}
	return retorno;
}
int contarIteracionesConf(eConfederacion* confederaciones,int* iteraciones, int tamConfederaciones, int idModificar)
{
	int retorno=-1;
	int flag=0;
	for(int i=0;i<tamConfederaciones;i++)
	{
		if((*(confederaciones+i)).id==idModificar && (*(confederaciones+i)).isEmpty==OCUPADO)
		{
			flag=1;
			retorno=0;
			*iteraciones=i;
			break;
		}
	}
	if(flag==0)
	{
		printf("ERROR, Ingrese ID valido\n");
	}
	return retorno;
}
int modificarConfederacion(eConfederacion* confederaciones, int tamConfederaciones , int contadorConf)
{
	int retorno=-1;
	int i;
	int idModificar;
	int opcion;
	if(listarConfederaciones(confederaciones,tamConfederaciones, contadorConf)==0)
	{
		do
		{
			ingresarIntConRango(&idModificar, "Ingrese ID a modificar", "ERROR, Ingrese ID valido\n",1,5000);
			//EN CONTAR ITERACIONES, SI HAY PROBLEMAS CON EL ID, RETORNO -1
		}while(contarIteracionesConf(confederaciones,&i, tamConfederaciones, idModificar)==-1);

		printf("+=========================+\n|%*s|\n+=========================+\n"
				"|%*s|\n|%*s|\n|%*s|\n+=========================+\n",-25,"        MODICAR",-25,"1.NOMBRE",-25,"2.REGION",-25,"3.ANIO DE CREACION");

		ingresarIntConRango(&opcion, "Ingrese opcion segun desee operar", "ERROR, Ingrese opcion valida\n",1,3);
		switch(opcion)
		{
		case 1:
			ingresarCadenaCaracteres(50, (*(confederaciones+i)).nombre, "Ingrese nuevo nombre de la confederacion\n", "ERROR,Ingrese nombre valido\n");
		break;
		case 2:
			ingresarCadenaCaracteres(50, (*(confederaciones+i)).region, "Ingrese nueva region de la confederacion\n", "ERROR,Ingrese region valida\n");
		break;
		case 3:
			ingresarIntConRango(&(*(confederaciones+i)).anioCreacion, "Ingrese nuevo anio de creacion\n", "ERROR, ingrese anio valido\n", 1800, ANIO_ACTUAL);
		break;
		}
	}
	//SI NO HAY CARGAS, EL AVISO LO MUESTRA listarConfederaciones
	return retorno;
}
int darDeBajaConf(eConfederacion* confederaciones, int tamConfederaciones , int* contadorConf)
{
	int retorno=-1;
	int i;
	int idModificar;
	if(listarConfederaciones(confederaciones,tamConfederaciones, *contadorConf)==0)
	{
		retorno=0;
		do
			{
				ingresarIntConRango(&idModificar, "Ingrese ID a dar de baja", "ERROR, Ingrese ID valido\n",1,5000);
				//EN CONTAR ITERACIONES, SI HAY PROBLEMAS CON EL ID, RETORNO -1
			}while(contarIteracionesConf(confederaciones,&i, tamConfederaciones, idModificar)==-1);

		(*(confederaciones+i)).isEmpty=VACIO;
		*contadorConf=*contadorConf-1;
		printf("<<<<<<<<<< ID %d DADO DE BAJA SATISFACTORIAMENTE>>>>>>>>>>\n ",(*(confederaciones+i)).id);

	}
	//SI NO HAY CARGAS, EL AVISO LO MUESTRA listarConfederaciones
	return retorno;
}








