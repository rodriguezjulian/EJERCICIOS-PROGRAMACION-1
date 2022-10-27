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
#include "jugadores.h"
#include<string.h>
#include "confederaciones.h"

#define TAM 3000
#define VACIO 1
#define OCUPADO 0

int ordenarJugadores(eJugador* jugadores,eConfederacion* confederaciones,int contadorJugadores,int tam);

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

	 inicializarIsEmpty(jugadores,TAM, VACIO);

	do
	{
		//MOSTRAR OPCIONES
		printf("+=========================+\n|%*s|\n+=========================+\n",-25,"MENU PRINCIPAL");

		printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n+=========================+\n",-25,
				"1.ALTA JUGADOR",-25,
				"2.BAJA JUGADOR",-25,
				"3.MODIFICACION JUGADOR",-25,
				"4.INFORMES",-25,
				"5.SALIR");

		ingresarShortConRango(&opcionMenu, "Ingrese opcion segun desee operar\n", "ERROR, ingrese opcion valida\n",  1,5);

		switch(opcionMenu)
		{
			case 1:
				 loguearJugador(jugadores,confederaciones, &idJugadores,&contadorJugadores, TAM);
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
		//ESTE IF ESTA PARA ROMPER EL DO WHILE
		if(salida==1)
		{
			printf("<<<<<<<<<<<<<<<<<<<<SALIR>>>>>>>>>>>>>>>>>>>");
			break;
		}

	}while(confirmarSalida()==-1);



	return EXIT_SUCCESS;
}
int ordenarJugadores(eJugador* jugadores,eConfederacion* confederaciones,int contadorJugadores,int tam)
{
	int retorno=-1;
	char descripcionUno[50];
	char descripcionDos[50];

	eJugador jugadorAxuliar; //PARA EL SWAP

	if(jugadores!=NULL && confederaciones!=NULL)
	{
		if(contadorJugadores>0)
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

							if(descripcionUno>descripcionDos)
							{
								jugadorAxuliar=(*(jugadores+i));
								(*(jugadores+i))=(*(jugadores+j));
								(*(jugadores+j))=jugadorAxuliar;
							}
						}
					}
				}
			}
		}
		else
		{
			printf("ERROR, Para operar esta opcion debe existir al menos 1 jugador cargado");
		}
	}
	return retorno;
}



