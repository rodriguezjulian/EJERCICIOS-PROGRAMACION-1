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
#include <string.h>
#include "confederaciones.h"

#define TAM 8
#define TAM_CONFEDERACIONES 6
#define VACIO 1
#define OCUPADO 0


//int listarJugadoresXUnaConf(eJugador* jugadores,eConfederacion* confederaciones,int tam, int idConf);


int main(void) {

	setbuf(stdout,NULL);

	short opcionMenu;
	int idJugadores=0;//LO INICIALIZO EN 0 YA QUE EL ID SERA AUTOINCREMENTAL
	int contadorJugadores=8;//INICIALIZADO EN 0 YA QUE SE USARA COMO VARIABLE DE CONTROL EN EL MENU
	//eJugador jugadores[TAM];

	eConfederacion confederaciones[6]=
	{
			{100,"CONMEBOL","SUDAMERICA",1916,OCUPADO},
			{101,"UEFA","EUROPA",1954,OCUPADO},
			{102,"AFC","ASIA",1954,OCUPADO},
			{103,"CAF","AFRICA",1957,OCUPADO},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,OCUPADO},
			{105,"OFC","OCEANIA",1966,OCUPADO}

	};

	//inicializarIsEmptyEjugador(jugadores,TAM, VACIO);

	eJugador jugadores [TAM]={
				 {1,"Dario","Delantero",10,100,131,11,OCUPADO},
				 {2,"Nige","Mediocampista",5,100,1,1,OCUPADO},
				 {3,"Messi","Arquero",1,101,155,1,OCUPADO},
				 {4,"Atony","Gil",5,100,145,100,OCUPADO},
				 {5,"El monta carga","Centro",8,101,15,1,OCUPADO},
				 {6,"Tevez","Delantero",9,101,1,20,OCUPADO},
				 {7,"Bufarini","Delantero",10,102,47,121,OCUPADO},
				 {8,"Atos","Centrocampista",5,102,4,2,OCUPADO}
		 };


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
				 loguearJugador(jugadores,confederaciones, &idJugadores,&contadorJugadores, TAM,TAM_CONFEDERACIONES);
			break;
			case 2:
				//BAJA DE JUGADOR
				darLaBajaJugador(jugadores,TAM, &contadorJugadores, confederaciones);
			break;
			case 3:
				modificarJugador(jugadores,confederaciones, TAM , contadorJugadores,TAM_CONFEDERACIONES);
			break;
			case 4:
				menuInformes(jugadores,confederaciones,TAM, contadorJugadores,TAM_CONFEDERACIONES);
			break;
			case 5:
				//LA CONFIRMACION ESTA EN CONDICION DEL while
				printf("¿DESEA SEGUIR EJECUTANDO EL PROGRAMA?");
			break;
		}
		//ESTE IF ESTA PARA ROMPER EL DO WHILE
	}while(confirmarSalida()==-1);

	return EXIT_SUCCESS;
}


