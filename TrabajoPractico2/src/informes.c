/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Julian Rodriguez
 */

#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "nexo.h"

#define VACIO 1
#define OCUPADO 0
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
			ordenarJugadoresAlfabeticamente(jugadores,confederaciones,tam);
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
				printf("| %*d|%*s|%*s|     %*d|%*.2f|%*s|         %*d|\n",-3,(*(jugadores+i)).id,-50,(*(jugadores+i)).nombre,-50,(*(jugadores+i)).posicion,-7,(*(jugadores+i)).numeroCamiseta,-16,(*(jugadores+i)).salario,-15,descripcion,-11,(*(jugadores+i)).aniosContrato);
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
int listarJugadoresXConfederaciones(eJugador* jugadores,eConfederacion* confederaciones,int tam, int tamConfederaciones)
{
	int retorno=-1;
	int idConf=100;

	if(jugadores!=NULL && confederaciones!=NULL)
	{
		retorno=0;
		for(int i=0;i<tamConfederaciones;i++)
		{
			listarJugadoresXUnaConf(jugadores,confederaciones,tam,idConf,tamConfederaciones);

			idConf=idConf+1;
		}
	}

	return retorno;
}
void informarTotalyMediaDeSalarios(eJugador* jugadores, int tam, int contadorJugadores)
{
	int jugPorArribaDeLaMedia;
	float totalSalarios;
	float promedioSalarios;

	acumularTotalSalarios(jugadores,tam, &totalSalarios);
	promedioSalarios=calcularPromedio(totalSalarios, contadorJugadores);
	jugPorArribaDeLaMedia=calcularJugPorArribaDeLaMedia( jugadores,  promedioSalarios);

	printf("%s\n|            %*s|      %*s|\n%s\n","+========================================================+",
			-23,"DESCRIPCION",-14,"RESULTADO","+========================================================+");


	printf("|%*s|   %*.2f|\n|%*s|   %*.2f|\n|%*s|         %*d|\n%s\n",-35,"TOTAL DE SALARIOS",-17,totalSalarios,-35,
			"PROMEDIO DE SALARIOS",-17,promedioSalarios,-35,"JUGADORES POR ARRIBA DEL PROMEDIO",-11,jugPorArribaDeLaMedia,
			"+========================================================+");
}
void mostrarConfConMasAniosContrato(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones)
{

	int maxAniosContrato;
	int arrayAniosAcumulados[tamConfederaciones];
	calcConfConMasAniosDeContrato(jugadores, tamConfederaciones,  tam, &maxAniosContrato);
	contarAniosDeContratoPorConf(jugadores,  tam,  tamConfederaciones,arrayAniosAcumulados);

	printf("+============================================================+\n"
				"|%*s|\n%s",-60,"CONFEDERACION CON MAYOR CANTIDAD DE AÑOS DE CONTRATOS TOTAL:",
				"+============================================================+\n");
	for(int i=0;i<tamConfederaciones;i++)
	{
		if((*(arrayAniosAcumulados+i))==maxAniosContrato)
		{
			printf("|%*s|\n",-60,(*(confederaciones+i)).nombre);
		}
	}
	printf("+============================================================+\n");
}
void informarPorcPorConf(eJugador* jugadores, int tam, int contJugadores, eConfederacion* confederaciones, int tamConfederaciones)
{
	float arrayPorcentajes[tamConfederaciones];
	//CALCULO PORCENTAJES
	calcPorcentajePorConf(jugadores, contJugadores,  tam, arrayPorcentajes,  tamConfederaciones);

	printf("%s|%*s|%*s|\n%s\n","+====================================+\n",-25,"         NOMBRE",-10,"PORCENTAJE",
			"+====================================+");

	for(int i=0;i<tamConfederaciones;i++)
	{
		printf("|%*s|   %*.2f|\n",-24,(*(confederaciones+i)).nombre,-8,(*(arrayPorcentajes+i)));
	}
}
int informarRegionMasAsistida(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones)
{
	int retorno=-1;
	int maximoContador;
	int flag=0;
	int idConfeAux=100;//INICIALIZADO EN 100 TENIENDO EN CUENTA QUE LOS ID DE CONFEDERACION ARRANCAN EN ESE NUMERO

	int arrayCantidadAcumulados[tamConfederaciones];
	buscarMayorNumJugPorRegion(jugadores,  tam,  tamConfederaciones,arrayCantidadAcumulados);

	for(int i=0;i<tamConfederaciones;i++)
	{
		if(flag==0)
		{
			flag=1;
			maximoContador=(*(arrayCantidadAcumulados+i));
		}
		else
		{
			if(maximoContador<(*(arrayCantidadAcumulados+i)))
			{
				maximoContador=(*(arrayCantidadAcumulados+i));
			}
		}

		idConfeAux=idConfeAux+1;
	}

	for(int i=0;i<tamConfederaciones;i++)
	{
		flag=0;
		if((*(arrayCantidadAcumulados+i))==maximoContador)
		{
			for(int j=0;j<tam;j++)
			{
				if(flag==0 && (*(jugadores+j)).isEmpty==OCUPADO  && (*(jugadores+j)).idConfederacion==(*(confederaciones+i)).id)
				{
					retorno=0;
					flag=1;
					printf("+==================================================+\n|REGION %*s|"
							"\n+==================================================+\n",-43,(*(confederaciones+i)).region);
				}
				if((*(jugadores+j)).isEmpty==OCUPADO  && (*(jugadores+j)).idConfederacion==(*(confederaciones+i)).id)
				{
					printf("|%*s|\n",-50,(*(jugadores+j)).nombre);
				}
			}
		}
	}
	printf("+==================================================+\n");

	return retorno;
}

