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

#define TAM 8
#define TAM_CONFEDERACIONES 6
#define VACIO 1
#define OCUPADO 0


//int listarJugadoresXUnaConf(eJugador* jugadores,eConfederacion* confederaciones,int tam, int idConf);


int main(void) {

	setbuf(stdout,NULL);

	short opcionMenu;
	short salida=0;
	int idJugadores=0;//LO INICIALIZO EN 0 YA QUE EL ID SERA AUTOINCREMENTAL
	int contadorJugadores=8;//INICIALIZADO EN 0 YA QUE SE USARA COMO VARIABLE DE CONTROL EN EL MENU
	//eJugador jugadores[TAM];

	eConfederacion confederaciones[6]=
	{
			{100,"CONMEBOL","SUDAMERICA",1916},
			{101,"UEFA","EUROPA",1954},
			{102,"AFC","ASIA",1954},
			{103,"CAF","AFRICA",1957},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},
			{105,"OFC","OCEANIA",1966}

	};

	//inicializarIsEmpty(jugadores,TAM, VACIO);

	eJugador jugadores [TAM]={
				 {1,"Dario","Delantero",10,100,105,1,OCUPADO},
				 {2,"Nige","Mediocampista",5,102,1,1,OCUPADO},
				 {3,"Messi","Arquero",1,100,155,1,OCUPADO},
				 {4,"Atony","Gil",5,100,145,1,OCUPADO},
				 {5,"El monta carga","Centro",8,104,15,11,OCUPADO},
				 {6,"Tevez","Delantero",9,102,1,1,OCUPADO},
				 {7,"Bufarini","Delantero",10,105,47,1,OCUPADO},
				 {8,"Atos","Centrocampista",5,100,4,2,OCUPADO}
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
				 loguearJugador(jugadores,confederaciones, &idJugadores,&contadorJugadores, TAM);
			break;
			case 2:
				//BAJA DE JUGADOR
				darLaBajaJugador(jugadores,TAM, &contadorJugadores, confederaciones);
			break;
			case 3:
				modificarJugador(jugadores,confederaciones, TAM , contadorJugadores);
			break;
			case 4:
				menuInformes(jugadores,confederaciones,TAM, contadorJugadores,TAM_CONFEDERACIONES);
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









/*int altaForzada(eJugador* jugadores, int tamJugadores,int id,char* nombre, char* posicion, short numeroCamiseta, int idConf,float salario,short AniosCont)
{
	int retorno=-1;
	eJugador jugadorAuxiliar;
	if(jugadores!=NULL)
	jugadorAuxiliar.id=id;
	strcpy(jugadorAuxiliar.nombre, nombre);
	strcpy(jugadorAuxiliar.posicion, posicion);
	jugadorAuxiliar.numeroCamiseta =numeroCamiseta;
	jugadorAuxiliar.idConfederacion=idConf;
	jugadorAuxiliar.salario=salario;
	jugadorAuxiliar.aniosContrato=AniosCont;
	jugadorAuxiliar.isEmpty=OCUPADO;
	retorno=0;
	for(int i=0;i<tamJugadores;i++)
	 {
		 if((*(jugadores+i)).isEmpty==VACIO)
		 {
			 (*(jugadores+i))=jugadorAuxiliar;
			 break;
		 }
	 }

	return retorno;
}*/
/*int seleccionarPosicion(eJugador* jugadores, int tam)
{
	int retorno=-1;



	return retorno;
}*/




