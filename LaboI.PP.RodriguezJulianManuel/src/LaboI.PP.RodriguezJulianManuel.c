/*
 ============================================================================
 Name        : RodriguezJulianManuel.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "calculos.h"
#include "ingresos.h"
#include "menu.PP.h"
#include "transporte.h"
#include "hojaDeRuta.h"

#define VACIO 1
#define OCUPADO 0
#define TAM 300
#define ANIO 2022
#define TAM_TIPOS 4

//int listarHojasDeRutaPorFecha(eHojaDeRuta* hojaDeRuta, eTransporte* transporte,int tam);
int listarHojasDeRutaPorFecha(eHojaDeRuta* hojaDeRuta, eTransporte* transporte,int tam, int contadorDeHojas);
int main(void) {
	setbuf(stdout,NULL);

	char opcion;
	int idTransporte=0;
	int idHoja=20000;
	int i;
	int contador=0;
	int opcionDeInformes;//la opcion del submenu del case H, debe ser numerica.
	//int auxPosicion;//cuando encuentro una posicion vacia la guardo aca |||| la dejo de usar por aritmetica
	int contadorDeHojas=0;
	int controlRetorno;//USADO PARA CONTROLAR LOS REINTENTOS AL INGRESAR LA OPCION DEL SUB MENU EN EL CASE H
	int volver;//A ESTA VARIABLE LA UTILIZO COMO UN FLAG AL CUAL CADA VEZ QUE ITERA EL MENU PRINCIPAL PONGO
	           //EN 0 Y SOLO CAMBIO SU VALOR SI EN EL SUBMENU DEL CASE H VOY POR LA OPCION 5.
	int salida=0;

	eTipo tipo[4]={
					{1000,"CAMION RECTO"},
					{1001,"CAMION REMOLQUE"},
					{1002,"CAMION SEMIREMOLQUE"},
					{1003,"CAMION ELEVADOR"}
	};
	//eFecha fecha;
	eTransporte transporte[TAM];
	eTransporte auxiliar;
	eTransporte* pTransporte;
	eHojaDeRuta hojaAuxiliar;
	eHojaDeRuta hojaDeRuta[TAM];
	eHojaDeRuta* pHojaDeRuta;

	inicializarIsEmpty(transporte,TAM, VACIO);
	inicializarIsEmptyHojaDeRuta(hojaDeRuta, TAM, VACIO);

	printf("%d\n",(*(transporte+100)).isEmpty);

	do{
		volver=0;
		mostrarOpciones();
		//AL PONER MINIMO Y MAXIMO HAGO LA FUNCION REUTILIZABLE Y GENERICA - ME AYUDO CON LA TABLA ASCII
		ingresarOpcionAlfabeticaMayusc(&opcion,"MARQUE SEGUN QUIERA OPERAR\n","ERROR,Ingrese opcion valida\n",64,74);

		switch(opcion)
		{
		case 'A':
			pTransporte=transporte;

			for(i=0;i<TAM;i++)
				{
					if((*pTransporte).isEmpty==VACIO)
					{
						break;
					}
					pTransporte++;
				}

			loguearTransporte(&idTransporte, &auxiliar ,&contador, tipo);
			*pTransporte=auxiliar;
		break;
		case'B':
			modificartransporte(transporte,contador);
		break;
		case'C':
			bajaTransporte(transporte,&contador);
		break;
		case 'D':
			ordenarTransportes(transporte, TAM);
			listarTransportes(transporte,TAM,contador);
		break;
		case'E':
			listarTipos(tipo,TAM_TIPOS);
		break;
		case 'F':
			pHojaDeRuta=hojaDeRuta;
			for(i=0;i<TAM;i++)
				{
					if((*pHojaDeRuta).isEmpty==VACIO)
					{
						break;
					}
					pHojaDeRuta++;
				}
			loguearHojaDeRuta(transporte,&hojaAuxiliar, &idHoja,contador, &contadorDeHojas);
			//hojaDeRuta[auxPosicion]=hojaAuxiliar;
			*pHojaDeRuta=hojaAuxiliar;
		break;
		case 'G':
			listarHojasDeRuta(hojaDeRuta, TAM,transporte,contadorDeHojas);
		break;
		case 'H':
			printf("\n+=================================================================================+\n");
			printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",-81,"1.Transportes de un tipo a seleccionar.",-81,
					"2.Hojas de ruta efectuadas en una fecha a seleccionar.",-81,
					"3.Importe total de las hojas de ruta realizadas en un transporte a seleccionar.",-81,
					"4.Importe total de todas las hojas de ruta de un tipo en una fecha a seleccionar.",-81,
					"5.Volver al menu principal.");
			printf("+=================================================================================+\n\n");

			controlRetorno=ingresarNumerosConRango(&opcionDeInformes, "\nIngrese opcion segun desee informar\n","Ingrese opcion valida,", 1, 5,3);

			if(controlRetorno==-1)
			{
				//SI SE QUEDA SIN REINTENTOS LO MANDO AL MENU PRINCIPAL OTRA VEZ
				volver=1;
			}

			switch(opcionDeInformes)
			{
			case 1:
				listarTipos(tipo,TAM_TIPOS);
				controlRetorno=ingresarNumerosConRango(&opcionDeInformes, "Ingrese tipo por ID\n","ERROR,Ingrese ID valido\n", 1000, 1003,3);
				if(controlRetorno!=-1)
				{
					listarTransportesDeUnTipo(transporte, TAM,contador,opcionDeInformes);
				}
				else
				{
					//SI SE QUEDA SIN REINTENTOS LO MANDO AL MENU PRINCIPAL OTRA VEZ
					volver=1;
				}

			break;
			case 2:
				//listarHojasDeRutaPorFecha(hojaDeRuta,transporte, TAM);
				 listarHojasDeRutaPorFecha( hojaDeRuta,  transporte,TAM, contadorDeHojas);
			break;
			case 3:
			break;
			case 4:
			break;
			case 5:
				volver=1;
			break;

			}
		break;
		case 'I':
			salida=1;
		break;
		}
		//ESTE IF LO ARMO PARA ROMPER AL WHILE
		if(salida==1)
		{
			printf("<<<<<<<<<<<<<<<<<<<<SALIR>>>>>>>>>>>>>>>>>>>");
			break;
		}
	}while(volver==1 || confirmarSalida()==-1);

	return EXIT_SUCCESS;
}




