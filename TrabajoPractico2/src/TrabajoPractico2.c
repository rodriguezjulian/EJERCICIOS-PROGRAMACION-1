/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#define TAM 3000

#define VACIO 1
#define OCUPADO 0

	typedef struct
	{
		int id;
		char nombre[50];
		char region[50];
		int anioCreacion;

	}eConfederacion;
	typedef struct
	{
		int id;
		char nombre[50];
		char posicion[50];
		short numeroCamiseta;
		int idConfederacion;
		float salario;
		short aniosContrato;
		short isEmpty;

	}eJugador;

int loguearJugador(eJugador* jugadores,eConfederacion* confederaciones, int* id,int* contadorJugadores);
int listarConfederaciones(eConfederacion* confederaciones);
int main(void) {

	setbuf(stdout,NULL);
	short opcionMenu;
	short salida=0;//
	int idJugadores=0;//LO INICIALIZO EN 0 YA QUE EL ID SERA AUTOINCREMENTAL
	int contadorJugadores=0;//INICIALIZADO EN 0 YA QUE SE USARA COMO VARIABLE DE CONTROL EN EL MENU
	eJugador jugadores[3000];
	eConfederacion confederaciones[6]=
	{
			{100,"CONMEBOL","SUDAMERICA",1916},
			{101,"UEFA","EUROPA",1954},
			{102,"AFC","ASIA",1954},
			{103,"CAF","AFRICA",1957},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
			{105,"OFC","OCEANIA",1966}

	};
	//MOSTRAR OPCIONES
	printf("+=========================+\n|%*s|\n+=========================+\n",-25,"MENU PRINCIPAL");

	printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n+=========================+\n",-25,
			"1.ALTA JUGADOR",-25,
			"2.BAJA JUGADOR",-25,
			"3.MODIFICACION JUGADOR",-25,
			"4.INFORMES",-25,
			"5.SALIR");

	ingresarShortConRango(&opcionMenu, "Ingrese opcion segun desee operar\n", "ERROR, ingrese opcion valida\n",  1,5);


	do
	{
		switch(opcionMenu)
		{
			case 1:
				 loguearJugador(jugadores,confederaciones, &idJugadores,&contadorJugadores);
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			case 5:
				salida=1;
			break;
		}
		if(salida==1)
		{
			//printf("<<<<<<<<<<<<<<<<<<<<SALIR>>>>>>>>>>>>>>>>>>>");
			break;
		}

	}while(salida==0);



	return EXIT_SUCCESS;
}



int listarConfederaciones(eConfederacion* confederaciones)
{
	int retorno=-1;

	if(confederaciones!=NULL)
	{
		retorno=0;

		 printf("+=========================================================================================================================+\n");
		 printf("|%*s|%*s|%*s|%*s|\n",-3,"ID",-50,"NOMBRE",-50,"REGION",-15,"ANIO CREACION");
		 printf("+=========================================================================================================================+\n");

		 for(int i=0;i<6;i++)
		 {
			 printf("|%*d|%*s|%*s|%*d|\n",-3,(*(confederaciones+i)).id,-50,(*(confederaciones+i)).nombre,-50,(*(confederaciones+i)).region,-15,(*(confederaciones+i)).anioCreacion);
		 }
		 printf("+=========================================================================================================================+\n");
	}

		return retorno;
}

int loguearJugador(eJugador* jugadores,eConfederacion* confederaciones, int* id,int* contadorJugadores)
{
	int retorno=-1;
	eJugador jugadorAuxiliar;
	if(jugadores!=NULL && confederaciones!=NULL)
	{
		*id=*id+1;//CADA VEZ QUE INGRESE TOMO AL VALOR QUE LLEGA COMO PARAMETRO PARA SUMARLE UNO Y ASI QUEDE AUTOINCREMENTAL
		*contadorJugadores=*contadorJugadores+1;

		 ingresarCadenaCaracteres( 50,jugadorAuxiliar.nombre,"Ingrese nombre del jugador\n","ERROR, Ingrese nombre valido\n");

		 ingresarCadenaCaracteres( 50,jugadorAuxiliar.posicion,"Ingrese posicion del jugador\n","ERROR, Ingrese posicion valida\n");

		 ingresarShortConRango(&jugadorAuxiliar.numeroCamiseta,"Ingrese numero de camiseta entre 1 y 100\n", "Ingrese numero valido\n", 1,  100);


		 listarConfederaciones(confederaciones);
		 //MOSTRAR LISTADO DE CONFEDERACIONES.

		 ingresarIntConRango(&jugadorAuxiliar.idConfederacion, "Ingrese ID de confederacion\n", "ERROR,Ingrese ID valido", 100, 105);

		 ingresarFloatConMinimo(&jugadorAuxiliar.salario,"Ingrese salario","ERROR, ingrese salario valido",1);

		 ingresarShortConRango(&jugadorAuxiliar.aniosContrato,"Ingrese anios de contrato entre 1 y 10\n", "Ingrese cantidad valida\n", 1, 10);

		 jugadorAuxiliar.isEmpty=OCUPADO;

	}

	return retorno;
}




