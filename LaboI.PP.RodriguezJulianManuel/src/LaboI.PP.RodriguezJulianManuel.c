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

int verificarSN(char letra);
int confirmarSalida(void);


int main(void) {
	setbuf(stdout,NULL);
//	char respuesta;
	char opcion;
	int idTransporte=0;
	int idHoja=20000;
	int i;
	int contador=0;
	//int auxPosicion;//cuando encuentro una posicion vacia la guardo aca |||| la dejo de usar por ari
	int contadorDeHojas=0;

	eTipo tipo[4]={
					{1000,"CAMION RECTO"},
					{1001,"CAMION REMOLQUE"},
					{1002,"CAMION SEMIREMOLQUE"},
					{1003,"CAMION ELEVADOR"}
	};

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
		mostrarOpciones();
		ingresarOpcionAlfabetica(&opcion,"MARQUE SEGUN QUIERA OPERAR\n","ERROR,Ingrese opcion valida\n");

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

			/*for(i=0;i<TAM;i++)
			{
				if(transporte[i].isEmpty==VACIO)
				{
					auxPosicion=i;
					break;
				}
			}*/
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

			/*
			for(i=0;i<TAM;i++)
			{
				if(hojaDeRuta[i].isEmpty==VACIO)
				{
					auxPosicion=i;
					break;
				}
			}*/
			loguearHojaDeRuta(transporte,&hojaAuxiliar, &idHoja,contador, &contadorDeHojas);
			//hojaDeRuta[auxPosicion]=hojaAuxiliar;
			*pHojaDeRuta=hojaAuxiliar;
		break;
		case 'G':
			listarHojasDeRuta(hojaDeRuta, TAM,transporte,contadorDeHojas);
		break;
		case 'H':

		break;
		}

		/*printf("Desea seguir operando? S/N ");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);*/

	}while(confirmarSalida()==-1);

	return EXIT_SUCCESS;
}
int verificarSN(char letra)
{
	int retorno=-1;

	if(letra=='S' || letra=='N')
	{
		retorno=0;
	}

	return retorno;
}
int confirmarSalida(void)
{
	int retorno=-1;
	char respuesta;
	int reintentos=3;

	do
	{
		printf("Para seguir operando presione S|N");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);

		reintentos=reintentos-1;
		if(verificarSN(respuesta)==-1 )
		{
			printf("ERROR, ingrese opcion valida\nReintentos restantes: %d\n\n",reintentos);
		}
	}while(verificarSN(respuesta)==-1 && reintentos>0);


	if(respuesta!='S')
	{
		printf("Confirme que desea SALIR presionando X \nPara continuar operando ingrese cualquier otra tecla");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);

		if(respuesta=='X')
		{
			printf("<<<<<<<<<<<<<<<<<<<<SALIR>>>>>>>>>>>>>>>>>>>");
			retorno=0;
		}
	}
	return retorno;
}






