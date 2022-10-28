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
int contarIteraciones(eJugador* jugadores,int* iteraciones, int tam, int idModificar)
{
	int flag=0;

	int retorno=-1;


	for(int i=0;i<tam;i++)
	{
		if((*(jugadores+i)).id==idModificar && (*(jugadores+i)).isEmpty==OCUPADO)
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
int modificarJugador(eJugador* jugadores,eConfederacion* confederaciones, int tam , int contadorJugadores)
{
	int retorno=-1;
	int opcion;
	int idModificar;
	int i;

	//SI EL LISTAR ME RETORNA 0 ES PORQUE HAY JUGADORES CARGADOS YA!
	//EN CASO QUE NO EXISTA JUGADOR CARGADO, DIRECTAMENTE EL AVISO LO IMPRIME LA FUINCION listarJugadores.
	if(listarJugadores(jugadores,confederaciones,tam, contadorJugadores,2)==0)
	{

		do
		{
			ingresarIntConRango(&idModificar, "Ingrese ID a modificar", "ERROR, Ingrese ID valido\n",1,3000);
			//EN CONTAR ITERACIONES, SI HAY PROBLEMAS CON EL ID, RETORNO -1
		}while(contarIteraciones(jugadores,&i, tam, idModificar)==-1);



		printf("+=========================+\n|%*s|\n+=========================+\n",-25,"SUB MENU - MODIFICACIONES");
		printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",-25,"1.NOMBRE",-25,"2.POSICION",-25,"3.NUMERO DE CAMISETA",-25,"4.CONFEDERACION",-25,"5.SALARIO",-25,"6.ANIOS DE CONTRATO");

		ingresarIntConRango(&opcion, "Ingrese opcion segun desee operar", "ERROR, Ingrese opcion valida\n",1,7);

		switch(opcion)
		{
		case 1:
			ingresarCadenaCaracteres( 50,(*(jugadores+i)).nombre,"Ingrese nuevo nombre del jugador\n","ERROR, Ingrese nombre valido\n");
		break;
		case 2:
			ingresarCadenaCaracteres( 50,(*(jugadores+i)).posicion,"Ingrese nueva posicion del jugador\n","ERROR, Ingrese posicion valida\n");
		break;
		case 3:
			ingresarShortConRango(&(*(jugadores+i)).numeroCamiseta,"Ingrese nuevo numero de camiseta entre 1 y 100\n", "Ingrese numero valido\n", 1,  100);
		break;
		case 4:
			 listarConfederaciones(confederaciones);
			 ingresarIntConRango(&(*(jugadores+i)).idConfederacion, "Ingrese nuevo ID de confederacion\n", "ERROR,Ingrese ID valido\n", 100, 105);
		break;
		case 5:
			ingresarFloatConMinimo(&(*(jugadores+i)).salario,"Ingrese nuevo salario","ERROR, ingrese salario valido\n",1);
		break;
		case 6:
			ingresarShortConRango(&(*(jugadores+i)).aniosContrato,"Ingrese nueva cantidad de anios de contrato entre 1 y 10\n", "Ingrese cantidad valida\n", 1, 10);
		break;

		}
		printf("<<<<<<<<<< ID %d MODIFICADO SATISFACTORIAMENTE >>>>>>>>>>\n",(*(jugadores+i)).id);
	}
	//HACER QUE PUEDA VOLVER AL MENU PRINCIPAL
	return retorno;
}
int darLaBajaJugador(eJugador* jugadores,int tam, int* contadorJugadores, eConfederacion* confederaciones)
{
	int retorno=-1;
	int idDarBaja;
	int i;
	if(listarJugadores(jugadores,confederaciones,tam, *contadorJugadores,2)==0)
	{

		do
		{
			ingresarIntConRango(&idDarBaja, "Ingrese ID a dar de baja", "ERROR, Ingrese ID valido\n",1,3000);
			//EN CONTAR ITERACIONES, SI HAY PROBLEMAS CON EL ID, RETORNO -1
		}while(contarIteraciones(jugadores,&i, tam, idDarBaja)==-1);

		(*(jugadores+i)).isEmpty=VACIO;
		*contadorJugadores=*contadorJugadores-1;
		printf("<<<<<<<<<< ID %d DADO DE BAJA SATISFACTORIAMENTE>>>>>>>>>>\n ",(*(jugadores+i)).id);
	}
	return retorno;
}

int listarJugadoresXUnaConf(eJugador* jugadores,eConfederacion* confederaciones,int tam, int idConf, int tamConfederaciones)
{
	int retorno=-1;
	int flag=0;
	char descripcionConf[50];
	for(int i=0;i<tam;i++)
	{
		if((*(jugadores+i)).isEmpty==OCUPADO && (*(jugadores+i)).idConfederacion==idConf)
		{
			if(flag==0)
			{
				flag=1;
				printf("+==========================================================================================================================+\n");
				asignarDescripcion(jugadores,confederaciones,6, descripcionConf ,i);
				printf("|                                                     %*s|\n",-69,descripcionConf);
				printf("+--------------------------------------------------------------------------------------------------------------------------+\n");
				//printf("+==========================================================================================================================+\n");
				printf("|%*s|%*s|%*s|\n",-50,"                     NOMBRE",-50,"                     POSICION",-21,"     N° CAMISETA");
				//printf("+==========================================================================================================================+\n");
				printf("+--------------------------------------------------------------------------------------------------------------------------+\n");
			}
			printf("|%*s|%*s|%*d|\n",-50,(*(jugadores+i)).nombre,-50,(*(jugadores+i)).posicion,-20,(*(jugadores+i)).numeroCamiseta);
		}
	}
	if(flag==0)
	{
		for(int i=0;i<tamConfederaciones;i++)
		{
			if((*(confederaciones+i)).id==idConf)
			{
				printf("+==========================================================================================================================+\n");
				printf("                                   NO EXISTEN JUGADORES EN LA CONDEFERACION:%s                                      \n",(*(confederaciones+i)).nombre);
				printf("+==========================================================================================================================+\n");
			}
		}
	}

	return retorno;
}
int listarJugadoresXConfederaciones(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores, int tamConfederaciones)
{
	int retorno=-1;
	int idConf=100;

	if(jugadores!=NULL && confederaciones!=NULL && contadorJugadores>0)
	{
		for(int i=0;i<tamConfederaciones;i++)
		{
			listarJugadoresXUnaConf(jugadores,confederaciones,tam,idConf,tamConfederaciones);
			//listarJugadoresXUnaConf(jugadores,confederaciones,tam,idConf);
			idConf=idConf+1;
		}
	}
	else
	{
		printf("ERROR, Para operar esta opcion debe existir al menos 1 jugador cargado\n");
	}
	return retorno;
}




















