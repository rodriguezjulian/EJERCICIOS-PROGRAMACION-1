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


//int informarImporteDeHojasPorId(eTransporte* transporte,int contador, eHojaDeRuta* hojaDeRuta, int contadorDeHojas);
int informarImporteDeHojasPorId(eTransporte* transporte,int contador, eHojaDeRuta* hojaDeRuta, int contadorDeHojas ,int tam);
int main(void) {
	setbuf(stdout,NULL);

	char opcion;
	int idTransporte=0;
	int idHoja=19999;//EMPIEZO EN 20.000 LOS ID, EN LOGUEAR HOJA DE RUTA VOY AUTOINCREMENTANDO X ESO 19.999
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

			//controlRetorno=ingresarNumerosConRango(&opcionDeInformes, ,, 1, 5,3);
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
				informarImporteDeHojasPorId(transporte,contador, hojaDeRuta, contadorDeHojas,TAM);
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
int informarImporteDeHojasPorId(eTransporte* transporte,int contador, eHojaDeRuta* hojaDeRuta, int contadorDeHojas ,int tam)
{
	//DEBO USAR EL CONTADOR PARA LLAMAR A LA FUNCION listarTransportes(transporte, TAM,  contador);
	//MAS ALLA QUE YA SEPA QUE HAY TRANSPORTES PORQUE SE PERMITIO EL ACCESO AL CASE
	int retorno=-1;
	eTransporte auxiliar;
	eTransporte* pTransporte;
	eHojaDeRuta* pHojaDeRutaAuxiliar;

	pTransporte=transporte;
	pHojaDeRutaAuxiliar=hojaDeRuta;
	int posicion;
	int flag=0; //PARA MOSTRAR EL MENU SOLA UNA VEZ
	int importeTotal=0; //este importe corresponde al total de las hojas de ruta que pertenecen al ID elegido por el usuario.

	if(transporte!=NULL && hojaDeRuta!=NULL && contadorDeHojas>0)
	{
		//LISTO LOS TRANSPORTES EXISTENTES PARA QUE LE SEA MAS FACIL AL USUARIO ELEGIR.
		listarTransportes(transporte, tam, contador);

		ingresarIntConMensajeMin(&auxiliar.idTransporte,"Ingrese id del transporte del que desea informar el importe total de las hojas de ruta realizadas \n", "Error, ingrese id valido\n", 0);

		posicion=auxiliar.idTransporte-1;

		if((*(pTransporte+posicion)).isEmpty==OCUPADO)
		{
			for(int i=0;i<tam;i++)
			{
				//if((*(pHojaDeRutaAuxiliar+i)).transporteId==(*(pTransporte+posicion)).idTransporte && flag==0)
				if((*(pHojaDeRutaAuxiliar+i)).transporteId==(*(pTransporte+posicion)).idTransporte && flag== 0)
				{
					printf("+--------------------+------------------------------+--------------------+----------+--------+\n");
					printf("|%*s|%*s|%*s|%*s|%*s|\n",-20,"ID HOJA DE RUTA",-30,"TRANSPORTE",-20,"PRECIO DEL VIAJE",-10,"KM TOTALES",-8,"FECHA");
					printf("+--------------------+------------------------------+--------------------+----------+--------+\n");
					printf("|%*d|%*s|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRutaAuxiliar+i)).idHoja,-30,(*(pTransporte+i)).descripcion,-19,(*(pHojaDeRutaAuxiliar+i)).precioViaje,-6,(*(pHojaDeRutaAuxiliar+i)).kmTotales,(*(pHojaDeRutaAuxiliar+i)).fecha.dia,(*(pHojaDeRutaAuxiliar+i)).fecha.mes,(*(pHojaDeRutaAuxiliar+i)).fecha.anio);
					importeTotal=importeTotal+hojaDeRuta[i].precioViaje;
					flag=1;
				}
				else
				{
					if((*(pHojaDeRutaAuxiliar+i)).transporteId==(*(pTransporte+posicion)).idTransporte)
					{
						importeTotal=importeTotal+hojaDeRuta[i].precioViaje;
						printf("|%*d|%*s|$%*.2f|%*.2f Km |%d/%d/%d|\n",-20,(*(pHojaDeRutaAuxiliar+i)).idHoja,-30,(*(pTransporte+i)).descripcion,-19,(*(pHojaDeRutaAuxiliar+i)).precioViaje,-6,(*(pHojaDeRutaAuxiliar+i)).kmTotales,(*(pHojaDeRutaAuxiliar+i)).fecha.dia,(*(pHojaDeRutaAuxiliar+i)).fecha.mes,(*(pHojaDeRutaAuxiliar+i)).fecha.anio);
						//printf("|%*d|%*s|$%*.2f|%*.2f Km |\n",-20,hojaDeRuta[i].idHoja,-30,transporte[i].descripcion,-19,hojaDeRuta[i].precioViaje,-6,hojaDeRuta[i].kmTotales);
					}

				}
			}
		}
		else
		{
			printf("El ID ingresado no corresponde a un transporte existente.\n");
		}
	}
	else
	{	//se valida en el ingreso a case H la existencia de un transporte
		printf("\nERROR, Para operar esta opcion primero debe crear al menos 1 hoja de ruta\n");
	}

	if(flag==1)
	{
		retorno=0;
		printf("+--------------------+------------------------------+--------------------+----------+--------+\n");

		printf("==============================================================================\n");
		printf("+|%*s%*d||+\n",-37,"IMPORTE TOTAL ACUMULADO",-38,importeTotal);
		printf("==============================================================================\n");
	}/*else
	{
		printf("El transporte aun no tiene hojas de ruta para mostrar\n");
	}*/

	return retorno;
}

