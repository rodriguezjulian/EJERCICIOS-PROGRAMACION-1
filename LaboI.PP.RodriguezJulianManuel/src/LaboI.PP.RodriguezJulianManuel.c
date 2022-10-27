/*
 ============================================================================
 Name        : RodriguezJulianManuel.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//
//#include "calculos.h"
#include "ingresos.h"
#include "menu.PP.h"
#include "transporte.h"
#include "hojaDeRuta.h"

#define VACIO 1
#define OCUPADO 0
#define TAM 300
#define ANIO 2022
#define TAM_TIPOS 4

int main(void) {
	setbuf(stdout,NULL);

	char opcion;
	int idTransporte=0;
	int idHoja=19999;//EMPIEZO EN 20.000 LOS ID, EN LOGUEAR HOJA DE RUTA VOY AUTOINCREMENTANDO X ESO 19.999
	int i;
	int contador=0;//CONTADOR DE TRANSPORTES
	//int auxPosicion;//cuando encuentro una posicion vacia la guardo aca |||| la dejo de usar por aritmetica
	int contadorDeHojas=0;
	//int controlRetorno;//
	int volverMenuPrincipal;//A ESTA VARIABLE LA UTILIZO COMO UN FLAG AL CUAL CADA VEZ QUE ITERA EL MENU PRINCIPAL PONGO
	           //EN 0 Y SOLO CAMBIO SU VALOR SI EN EL SUBMENU DEL CASE H VOY POR LA OPCION 5.
	int salida=0;

	eTipo tipo[4]={
					{1000,"CAMION RECTO"},
					{1001,"CAMION REMOLQUE"},
					{1002,"CAMION SEMIREMOLQUE"},
					{1003,"CAMION ELEVADOR"}
	};
	//eFecha fecha;
	eTransporte transportes[TAM];
	eTransporte auxiliar;
	eTransporte* pTransportes;

	eHojaDeRuta hojaAuxiliar;
	eHojaDeRuta hojasDeRuta[TAM];
	eHojaDeRuta* pHojasDeRuta;


	inicializarIsEmpty(transportes,TAM, VACIO);
	inicializarIsEmptyHojaDeRuta(hojasDeRuta, TAM, VACIO);

	printf("%d\n",(*(transportes+100)).isEmpty);

	do{
		mostrarOpciones();
		//AL PONER MINIMO Y MAXIMO HAGO LA FUNCION REUTILIZABLE Y GENERICA - ME AYUDO CON LA TABLA ASCII
		ingresarOpcionAlfabeticaMayusc(&opcion,"MARQUE SEGUN QUIERA OPERAR\n","ERROR,Ingrese opcion valida\n",64,74);
		volverMenuPrincipal=0;
		switch(opcion)
		{
		case 'A':
			if(contador<TAM)
			{
				pTransportes=transportes;
				for(i=0;i<TAM;i++)
					{
						if((*pTransportes).isEmpty==VACIO)
						{
							break;
						}
						pTransportes++;
					}

				loguearTransporte(&idTransporte, &auxiliar ,&contador, tipo);
				*pTransportes=auxiliar;
			}
			else
			{
				printf("SIN ESPACIO EN MEMORIA");
			}

		break;
		case'B':
			modificartransporte(transportes,contador);
		break;
		case'C':
			bajaTransporte(transportes,&contador);
		break;
		case 'D':
			//printf("CONTADOR= %d\n",contador);
			ordenarTransportes(transportes, TAM);
			listarTransportes(transportes,TAM,contador);
		break;
		case'E':
			listarTipos(tipo,TAM_TIPOS);
		break;
		case 'F':
			if(contadorDeHojas<TAM)
			{
				if(contador>0)
				{
					pHojasDeRuta=hojasDeRuta;
					for(i=0;i<TAM;i++)
						{
							if((*pHojasDeRuta).isEmpty==VACIO)
							{
								break;
							}
							pHojasDeRuta++;
						}
					loguearHojaDeRuta(transportes,&hojaAuxiliar, &idHoja,contador, &contadorDeHojas);

					*pHojasDeRuta=hojaAuxiliar;
				}
				else
				{
					printf("ERROR,No es posible ingresar a estar opcion, deben existir transportes cargados\n");
				}
			}else
			{
				printf("SIN ESPACIO EN MEMORIA");
			}

		break;
		case 'G':
			listarHojasDeRuta(hojasDeRuta, TAM,transportes,contadorDeHojas);
		break;
		case 'H':
			ejecutarMenuInformes (contador, transportes,hojasDeRuta,tipo,contadorDeHojas,&volverMenuPrincipal,TAM);
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
	}while(volverMenuPrincipal==1 || confirmarSalida()==-1);

	return EXIT_SUCCESS;
}


