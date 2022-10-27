/*
 * menu.PP.c
 *
 *  Created on: 13 oct. 2022
 *      Author: Julian Rodriguez
 */
//#include "menu.PP.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//#include "calculos.h"
//#include "ingresos.h"
//#include "menu.PP.h"
#include "transporte.h"
#include "hojaDeRuta.h"
#include "InformesPP.h"
#include "validaciones.h"

#define VACIO 1
#define OCUPADO 0
#define TAM 300
#define ANIO 2022
#define TAM_TIPOS 4

void mostrarOpciones(void)
{
	printf("+------------------------+\n");//
	printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",-24,"A.ALTA TRASPORTE",-24,"B.MODIFICAR TRANSPORTE",-24,
			"C.BAJA TRANSPORTE",-24,"D.LISTAR TRANSPORTES",-24,"E.LISTAR TIPOS",-24,"F.ALTA HOJA DE RUTA",-24,
			"G.LISTAR HOJAS DE RUTA",-24,"H.INFORMES",-24,"I.SALIR");
	printf("+------------------------+\n");

}
int ejecutarMenuInformes (int contador, eTransporte* transporte,eHojaDeRuta* hojaDeRuta, eTipo* tipo, int contadorDeHojas,int* volverMenuPrincipal, int tam)
{
	int retorno=-1;
	int controlRetorno;//USADO PARA CONTROLAR LOS REINTENTOS AL INGRESAR LA OPCION DEL SUB MENU EN EL CASE H
	int opcionDeInformes;


	if(contador>0)
	{
		retorno=0;
		printf("\n+=================================================================================+\n");
		printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",-81,"1.Transportes de un tipo a seleccionar.",-81,
							"2.Hojas de ruta efectuadas en una fecha a seleccionar.",-81,
							"3.Importe total de las hojas de ruta realizadas en un transporte a seleccionar.",-81,
							"4.Importe total de todas las hojas de ruta de un tipo en una fecha a seleccionar.",-81,
							"5.Volver al menu principal.");
		printf("+=================================================================================+\n\n");

					//controlRetorno=ingresarNumerosConRango(&opcionDeInformes, ,, 1, 5,3);
					controlRetorno=ingresarNumConRangoYReintentos(&opcionDeInformes, "\nIngrese opcion segun desee informar\n","Ingrese opcion valida,", 1, 5,3);
					if(controlRetorno==-1)
					{
						//SI SE QUEDA SIN REINTENTOS LO MANDO AL MENU PRINCIPAL OTRA  VEZ
						*volverMenuPrincipal=1;
					}

					switch(opcionDeInformes)
					{
					case 1:
						listarTipos(tipo,TAM_TIPOS);
						controlRetorno=ingresarNumConRangoYReintentos(&opcionDeInformes, "Ingrese tipo por ID\n","ERROR,Ingrese ID valido\n", 1000, 1003,3);
						if(controlRetorno!=-1 && verificarExistenciaDeTipoDeTransporte(transporte, opcionDeInformes, tam)==0)
						{
							//TENGO QUE CONTROLAR QUE EL TIPO ELEGIDO TENGA AL MENOS 1 TRANSPORTE CARGADO.
							listarTransportesDeUnTipo(transporte, TAM,opcionDeInformes);
						}
						else
						{
							//SI SE QUEDA SIN REINTENTOS LO MANDO AL MENU PRINCIPAL OTRA VEZ
							*volverMenuPrincipal=1;
						}

					break;
					case 2:
						 listarHojasDeRutaPorFecha( hojaDeRuta,  transporte,TAM, contadorDeHojas);
					break;
					case 3:
						informarImporteDeHojasPorId(transporte,contador, hojaDeRuta, contadorDeHojas,TAM);
					break;
					case 4:
						informarImpTotalDeHojasPorTipoyFecha(TAM, TAM_TIPOS,tipo, opcionDeInformes,transporte, hojaDeRuta,volverMenuPrincipal,contadorDeHojas);
					break;
					case 5:
						*volverMenuPrincipal=1;
						if(*volverMenuPrincipal==1)
						{
							printf("<<<<<<<<<<VOLVER AL MENU PRINCIPAL>>>>>>>>>>\n");
						}
					break;

					}
	}
	else
	{
		printf("Para operar esta opcion debe al menos existir un transporte logueado\n");
	}

	return retorno;

}


