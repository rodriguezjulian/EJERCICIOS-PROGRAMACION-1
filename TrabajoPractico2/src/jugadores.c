/*
 * jugadores.c
 *
 *  Created on: 27 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "ingresos.h"
#include<string.h>


#define TAM 8
#define VACIO 1
#define OCUPADO 0

int inicializarIsEmpty(eJugador* jugadores, int tam, int estado)
{
	int retorno=-1;

	if(jugadores!=NULL  && tam>0)
	{

		for(int i=0;i<TAM;i++)
		{
			(*(jugadores+i)).isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}

		retorno=0;
	}
	return retorno;

}
int loguearJugador(eJugador* jugadores,eConfederacion* confederaciones, int* id,int* contadorJugadores,int tamJugadores)
{
	int retorno=-1;
	eJugador jugadorAuxiliar;
	if(jugadores!=NULL && confederaciones!=NULL)
	{
		if(*contadorJugadores<tamJugadores)
		{
			*id=*id+1;//CADA VEZ QUE INGRESE TOMO AL VALOR QUE LLEGA COMO PARAMETRO PARA SUMARLE UNO Y ASI QUEDE AUTOINCREMENTAL
			jugadorAuxiliar.id=*id;

			*contadorJugadores=*contadorJugadores+1;

			 ingresarCadenaCaracteres( 50,jugadorAuxiliar.nombre,"Ingrese nombre del jugador\n","ERROR, Ingrese nombre valido\n");

			 ingresarCadenaCaracteres( 50,jugadorAuxiliar.posicion,"Ingrese posicion del jugador\n","ERROR, Ingrese posicion valida\n");

			 ingresarShortConRango(&jugadorAuxiliar.numeroCamiseta,"Ingrese numero de camiseta entre 1 y 100\n", "Ingrese numero valido\n", 1,  100);

			 //MOSTRAR LISTADO DE CONFEDERACIONES.
			 listarConfederaciones(confederaciones);
			 ingresarIntConRango(&jugadorAuxiliar.idConfederacion, "Ingrese ID de confederacion\n", "ERROR,Ingrese ID valido\n", 100, 105);

			 ingresarFloatConMinimo(&jugadorAuxiliar.salario,"Ingrese salario","ERROR, ingrese salario valido\n",1);

			 ingresarShortConRango(&jugadorAuxiliar.aniosContrato,"Ingrese anios de contrato entre 1 y 10\n", "Ingrese cantidad valida\n", 1, 10);

			 jugadorAuxiliar.isEmpty=OCUPADO;

			for(int i=0;i<tamJugadores;i++)
			 {
				 if((*(jugadores+i)).isEmpty==VACIO)
				 {
					 (*(jugadores+i))=jugadorAuxiliar;
					 break;
				 }
			 }
		}
		else
		{
			printf("ERROR,SIN ESPACIO EN MEMORIA");
		}
	}
	return retorno;
}
int asignarDescripcion(eJugador* jugadores,eConfederacion* confederaciones,int tamConfederaciones, char* descripcion ,int posicion)
{
	int retorno=-1;


		if(jugadores!=NULL && confederaciones!=NULL)
		{
			retorno=0;
			for(int i=0;i<tamConfederaciones;i++)
			{
				if((*(jugadores+posicion)).idConfederacion==(*(confederaciones+i)).id)
				{
					strcpy(descripcion,(*(confederaciones+i)).nombre);
				}
			}
		}
	return retorno;
}
int ordenarJugadoresAlfabeticamente(eJugador* jugadores,eConfederacion* confederaciones,int tam)
{
	int retorno=-1;
	char descripcionUno[50];
	char descripcionDos[50];

	eJugador jugadorAuxiliar; //PARA EL SWAP

	if(jugadores!=NULL && confederaciones!=NULL)
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

						if(strcmp(descripcionUno, descripcionDos)>0)
						{
							jugadorAuxiliar=(*(jugadores+i));
							(*(jugadores+i))=(*(jugadores+j));
							(*(jugadores+j))=jugadorAuxiliar;
						}
						else
						{	if(strcmp(descripcionUno, descripcionDos)==0)
							{
								if(strcmp( (*(jugadores+i)).nombre,(*(jugadores+j)).nombre)>0)
								{
									jugadorAuxiliar=(*(jugadores+i));
									(*(jugadores+i))=(*(jugadores+j));
									(*(jugadores+j))=jugadorAuxiliar;
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
int ordenarJugadoresXId(eJugador* jugadores, int tam)
{
	int retorno=-1;
	eJugador jugadorAuxiliar;

	if(jugadores!=NULL)
	{
		retorno=0;
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{
				for(int j=i+1;j<tam;j++)
				{
					if((*(jugadores+j)).isEmpty==OCUPADO)
					{
						if((*(jugadores+i)).id>(*(jugadores+j)).id)
						{
								jugadorAuxiliar=(*(jugadores+i));
								(*(jugadores+i))=(*(jugadores+j));
								(*(jugadores+j))=jugadorAuxiliar;
						}
					}
				}
			}
		}
	}
	return retorno;
}
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
int contarIteraciones(eJugador* jugadores,int* iteraciones, int tam, int idModificar)
{
	int flag=0;

	int retorno=-1;


	for(int i=0;i<tam;i++)
	{
		if((*(jugadores+i)).id==idModificar && (*(jugadores+i)).isEmpty==OCUPADO)
		{
			flag=1;
			retorno=0;
			*iteraciones=i;
			break;
		}
	}
	if(flag==0)
	{
		printf("ERROR, Ingrese ID valido\n");
	}
	return retorno;
}
int modificarJugador(eJugador* jugadores,eConfederacion* confederaciones, int tam , int contadorJugadores)
{
	int retorno=-1;
	int opcion;
	int idModificar;
	int i;

	//SI EL LISTAR ME RETORNA 0 ES PORQUE HAY JUGADORES CARGADOS YA!
	//EN CASO QUE NO EXISTA JUGADOR CARGADO, DIRECTAMENTE EL AVISO LO IMPRIME LA FUINCION listarJugadores.
	//NO VERIFICO POR NULL PORQUE YA LO HACE listarJugadores
	if(listarJugadores(jugadores,confederaciones,tam, contadorJugadores,2)==0)
	{

		do
		{
			ingresarIntConRango(&idModificar, "Ingrese ID a modificar", "ERROR, Ingrese ID valido\n",1,3000);
			//EN CONTAR ITERACIONES, SI HAY PROBLEMAS CON EL ID, RETORNO -1
		}while(contarIteraciones(jugadores,&i, tam, idModificar)==-1);

		printf("+=========================+\n|%*s|\n+=========================+\n",-25,"SUB MENU - MODIFICACIONES");
		printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",-25,"1.NOMBRE",-25,"2.POSICION",-25,"3.NUMERO DE CAMISETA",-25,"4.CONFEDERACION",-25,"5.SALARIO",-25,"6.ANIOS DE CONTRATO");

		ingresarIntConRango(&opcion, "Ingrese opcion segun desee operar", "ERROR, Ingrese opcion valida\n",1,7);

		switch(opcion)
		{
		case 1:
			ingresarCadenaCaracteres( 50,(*(jugadores+i)).nombre,"Ingrese nuevo nombre del jugador\n","ERROR, Ingrese nombre valido\n");
		break;
		case 2:
			ingresarCadenaCaracteres( 50,(*(jugadores+i)).posicion,"Ingrese nueva posicion del jugador\n","ERROR, Ingrese posicion valida\n");
		break;
		case 3:
			ingresarShortConRango(&(*(jugadores+i)).numeroCamiseta,"Ingrese nuevo numero de camiseta entre 1 y 100\n", "Ingrese numero valido\n", 1,  100);
		break;
		case 4:
			 listarConfederaciones(confederaciones);
			 ingresarIntConRango(&(*(jugadores+i)).idConfederacion, "Ingrese nuevo ID de confederacion\n", "ERROR,Ingrese ID valido\n", 100, 105);
		break;
		case 5:
			ingresarFloatConMinimo(&(*(jugadores+i)).salario,"Ingrese nuevo salario","ERROR, ingrese salario valido\n",1);
		break;
		case 6:
			ingresarShortConRango(&(*(jugadores+i)).aniosContrato,"Ingrese nueva cantidad de anios de contrato entre 1 y 10\n", "Ingrese cantidad valida\n", 1, 10);
		break;

		}
		printf("<<<<<<<<<< ID %d MODIFICADO SATISFACTORIAMENTE >>>>>>>>>>\n",(*(jugadores+i)).id);
	}
	//HACER QUE PUEDA VOLVER AL MENU PRINCIPAL
	return retorno;
}
int darLaBajaJugador(eJugador* jugadores,int tam, int* contadorJugadores, eConfederacion* confederaciones)
{
	int retorno=-1;
	int idDarBaja;
	int i;
	//NO VERIFICO POR NULL PORQUE YA LO HACE listarJugadores
	if(listarJugadores(jugadores,confederaciones,tam, *contadorJugadores,2)==0)
	{

		do
		{
			ingresarIntConRango(&idDarBaja, "Ingrese ID a dar de baja", "ERROR, Ingrese ID valido\n",1,3000);
			//EN CONTAR ITERACIONES, SI HAY PROBLEMAS CON EL ID, RETORNO -1
		}while(contarIteraciones(jugadores,&i, tam, idDarBaja)==-1);

		(*(jugadores+i)).isEmpty=VACIO;
		*contadorJugadores=*contadorJugadores-1;
		printf("<<<<<<<<<< ID %d DADO DE BAJA SATISFACTORIAMENTE>>>>>>>>>>\n ",(*(jugadores+i)).id);
	}
	return retorno;
}

int listarJugadoresXUnaConf(eJugador* jugadores,eConfederacion* confederaciones,int tam, int idConf, int tamConfederaciones)
{
	int retorno=-1;
	int flag=0;
	char descripcionConf[50];
	for(int i=0;i<tam;i++)
	{
		if((*(jugadores+i)).isEmpty==OCUPADO && (*(jugadores+i)).idConfederacion==idConf)
		{
			if(flag==0)
			{
				flag=1;
				printf("+==========================================================================================================================+\n");
				asignarDescripcion(jugadores,confederaciones,6, descripcionConf ,i);
				printf("|                                                     %*s|\n",-69,descripcionConf);
				printf("+--------------------------------------------------------------------------------------------------------------------------+\n");
				//printf("+==========================================================================================================================+\n");
				printf("|%*s|%*s|%*s|\n",-50,"                     NOMBRE",-50,"                     POSICION",-21,"     N° CAMISETA");
				//printf("+==========================================================================================================================+\n");
				printf("+--------------------------------------------------------------------------------------------------------------------------+\n");
			}
			printf("|%*s|%*s|         %*d|\n",-50,(*(jugadores+i)).nombre,-50,(*(jugadores+i)).posicion,-11,(*(jugadores+i)).numeroCamiseta);
		}
	}
	if(flag==0)
	{
		for(int i=0;i<tamConfederaciones;i++)
		{
			if((*(confederaciones+i)).id==idConf)
			{
				printf("+==========================================================================================================================+\n");
				printf("                                   NO EXISTEN JUGADORES EN LA CONDEFERACION:%s                                      \n",(*(confederaciones+i)).nombre);
				printf("+==========================================================================================================================+\n");
			}
		}
	}

	return retorno;
}
int listarJugadoresXConfederaciones(eJugador* jugadores,eConfederacion* confederaciones,int tam, int tamConfederaciones)
{
	int retorno=-1;
	int idConf=100;

	if(jugadores!=NULL && confederaciones!=NULL)
	{
		for(int i=0;i<tamConfederaciones;i++)
		{
			listarJugadoresXUnaConf(jugadores,confederaciones,tam,idConf,tamConfederaciones);
			//listarJugadoresXUnaConf(jugadores,confederaciones,tam,idConf);
			idConf=idConf+1;
		}
	}
	/*else
	{
		printf("ERROR, Para operar esta opcion debe existir al menos 1 jugador cargado\n");
	}*/
	return retorno;
}





float calcularPromedio(float numeroA, int numeroB)
{
	float resultado;

	resultado=numeroA/numeroB;

	return resultado;
}
int acumularTotalSalarios(eJugador* jugadores,int tam, float* totalSalarios)
{
	//NO VALIDO POR NULL PORQUE YA SE HIZO AL INGRESAR AL INFORME
	int retorno=-1;
	float totalAux=0;
	for(int i=0;i<tam;i++)
	{
		if((*(jugadores+i)).isEmpty==OCUPADO)
		{
			retorno=0;
			totalAux=totalAux+(*(jugadores+i)).salario;
		}
	}
	*totalSalarios=totalAux;
	return retorno;
}
int calcularJugPorArribaDeLaMedia(eJugador* jugadores, float promedioSalarios)
{
	int total=0;

	//NO VALIDO POR NULL PORQUE YA SE HIZO AL INGRESAR AL INFORME
	for(int i=0;i<TAM;i++)
	{
		if((*(jugadores+i)).isEmpty==OCUPADO && (*(jugadores+i)).salario> promedioSalarios)
		{
			total=total+1;
		}
	}
	return total;
}

int informarTotalyMediaDeSalarios(eJugador* jugadores, int tam, int contadorJugadores)
{
	int retorno=-1;
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
	return retorno;
}

int calcConfConMasAniosDeContrato(eJugador* jugadores,int tamConfederaciones, int tamJugadores, int* resultadoAnios,eConfederacion* confederaciones)
{
	int retorno=-1;
	int resultadoAux=0;
	int idConfeAux=100;
	int acumulador=0;
	//retorno la cantidad maxima de contratos encontrados
	for(int i=0;i<tamConfederaciones;i++)
	{
		acumulador=0;
		for(int j=0;j<tamJugadores;j++)
		{

			if((*(jugadores+j)).isEmpty==OCUPADO && (*(jugadores+j)).idConfederacion==idConfeAux)
			{
				acumulador=acumulador+(*(jugadores+j)).aniosContrato;
				retorno=0;
			}
		}

		if(resultadoAux<acumulador)
		{
			resultadoAux=acumulador;

		}
		idConfeAux=idConfeAux+1;
	}
	*resultadoAnios=resultadoAux;
	return retorno;
}
void inicializarArray(int* array,int tam)
{
	if(array!=NULL)
	{
		for (int i = 0; i < tam; ++ i)
		{
			(*(array+i))=0;
		}
	}
}
void inicializarArrayFloat(float* array,int tam)
{
	if(array!=NULL)
	{
		for (int i = 0; i < tam; ++ i)
		{
			(*(array+i))=0;
		}
	}
}

int contarAniosDeContratoPorConf(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones,int* arrayAniosAcumulados )
{
	int retorno=-1;

	//CADA POSICION DEL ARRAY RESPETA EL ORDEN DE LAS CONFEDERACIONES
	int idConfeAux=100;
	int acumulador;

	//INICIALIZO EN 0 AL ARRAY
	inicializarArray(arrayAniosAcumulados, tam);

	for(int i=0;i<tamConfederaciones;i++)
	{
		acumulador=0;
		for(int j=0;j<tam;j++)
		{
			if((*(jugadores)).isEmpty==OCUPADO && (*(jugadores+j)).idConfederacion==idConfeAux)
			{
				acumulador=acumulador+(*(jugadores+j)).aniosContrato;
			}
		}
		(*(arrayAniosAcumulados+i))=acumulador;
		idConfeAux=idConfeAux+1;
	}
	return retorno;
}
void mostrarConfConMasAniosContrato(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones)
{

	int maxAniosContrato;
	int arrayAniosAcumulados[tamConfederaciones];
	calcConfConMasAniosDeContrato(jugadores, tamConfederaciones,  tam, &maxAniosContrato,confederaciones);
	contarAniosDeContratoPorConf(jugadores,  tam,  tamConfederaciones,  confederaciones,arrayAniosAcumulados);

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

float calcPorcentaje(int total, int parcial)
{
	float resultado;

	resultado=(float)parcial*100/total;


	return resultado;
}
//informar porcentaje de jugadores por cada confederación.
/*int calcPorcentajePorConf(eJugador* jugadores,int contJugadores, int tam, float* porcentajeConmebol, float* porcentajeUefa,float* porcentajeAfc, float* porcentajeCaf,float* porcentajeConcacaf,float* porcentajeOfc)
{
	int retorno=-1;
	//LOS INICIALIZO PORQUE SON CONTADORES
	int contConmebol=0;
	int contUefa=0;
	int contAfc=0;
	int contCaf=0;
	int contConcacaf=0;
	int contOfc=0;
	//NO VALIDO POR NULL PORQUE SE HIZO EN LA FUNCION DE menuInformes
	for(int i=0;i<tam;i++)
	{
		if((*(jugadores+i)).isEmpty==OCUPADO)
		{
			switch((*(jugadores+i)).idConfederacion)
			{
				case 100:
					contConmebol=contConmebol+1;
					*porcentajeConmebol=calcPorcentaje(contJugadores, contConmebol);
				break;
				case 101:
					contUefa=contUefa+1;
					*porcentajeUefa=calcPorcentaje(contJugadores, contUefa);
				break;
				case 102:
					contAfc=contAfc+1;
					*porcentajeAfc=calcPorcentaje(contJugadores, contAfc);
				break;
				case 103:
					contCaf=contCaf+1;
					*porcentajeCaf=calcPorcentaje(contJugadores, contCaf);
				break;
				case 104:
					contConcacaf=contConcacaf+1;
					*porcentajeConcacaf=calcPorcentaje(contJugadores, contConcacaf);
				break;
				case 105:
					contOfc=contOfc+1;
					*porcentajeOfc=calcPorcentaje(contJugadores, contOfc);
				break;
			}
		}
	}
	return retorno;
}*/

int calcPorcentajePorConf(eJugador* jugadores,int contJugadores, int tam, float* arrayPorcentajes, int tamConfederaciones)
{
	int retorno=-1;
	//LOS INICIALIZO PORQUE SON CONTADORES
	int contConmebol=0;
	int contUefa=0;
	int contAfc=0;
	int contCaf=0;
	int contConcacaf=0;
	int contOfc=0;
	inicializarArrayFloat(arrayPorcentajes,tamConfederaciones);
	//NO VALIDO POR NULL PORQUE SE HIZO EN LA FUNCION DE menuInformes
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{
				switch((*(jugadores+i)).idConfederacion)
				{
					case 100:
						contConmebol=contConmebol+1;
						//*porcentajeConmebol=calcPorcentaje(contJugadores, contConmebol);
						(*(arrayPorcentajes+0))=calcPorcentaje(contJugadores, contConmebol);
					break;
					case 101:
						contUefa=contUefa+1;
						(*(arrayPorcentajes+1))=calcPorcentaje(contJugadores, contUefa);
					break;
					case 102:
						contAfc=contAfc+1;
						(*(arrayPorcentajes+2))=calcPorcentaje(contJugadores, contAfc);
					break;
					case 103:
						contCaf=contCaf+1;
						(*(arrayPorcentajes+3))=calcPorcentaje(contJugadores, contCaf);
					break;
					case 104:
						contConcacaf=contConcacaf+1;
						(*(arrayPorcentajes+4))=calcPorcentaje(contJugadores, contConcacaf);
					break;
					case 105:
						contOfc=contOfc+1;
						(*(arrayPorcentajes+5))=calcPorcentaje(contJugadores, contOfc);
					break;
					}
				}
			}
	return retorno;
}
int informarPorcPorConf(eJugador* jugadores, int tam, int contJugadores, eConfederacion* confederaciones, int tamConfederaciones)
{
	int retorno=-1;
	float arrayPorcentajes[tamConfederaciones];
	//CALCULO PORCENTAJES
	calcPorcentajePorConf(jugadores, contJugadores,  tam, arrayPorcentajes,  tamConfederaciones);

	printf("%s|%*s|%*s|\n%s\n","+====================================+\n",-25,"         NOMBRE",-10,"PORCENTAJE",
			"+====================================+");

	for(int i=0;i<tamConfederaciones;i++)
	{
		printf("|%*s|   %*.2f|\n",-24,(*(confederaciones+i)).nombre,-8,(*(arrayPorcentajes+i)));
	}
	return retorno;
}
int buscarMayorNumJugPorRegion(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones,int* arrayCantidadAcumulados)
{
	int retorno=-1;

	//CADA POSICION DEL ARRAY RESPETA EL ORDEN DE LAS CONFEDERACIONES
	int idConfeAux=100;//INICIALIZADO EN 100 TENIENDO EN CUENTA QUE LOS ID DE CONFEDERACION ARRANCAN EN ESE NUMERO
	int acumulador;

	//INICIALIZO EN 0 AL ARRAY
	inicializarArray(arrayCantidadAcumulados, tam);

	for(int i=0;i<tamConfederaciones;i++)
	{
		acumulador=0;
		for(int j=0;j<tam;j++)
		{
			if((*(jugadores)).isEmpty==OCUPADO && (*(jugadores+j)).idConfederacion==idConfeAux)
			{
				acumulador=acumulador+1;
			}
		}
		(*(arrayCantidadAcumulados+i))=acumulador;
		idConfeAux=idConfeAux+1;
	}
	//printf("A VER QUE SE GUARDO X POSICION: %d %d %d %d %d %d",arrayCantidadAcumulados[0],arrayCantidadAcumulados[1],arrayCantidadAcumulados[2],arrayCantidadAcumulados[3],arrayCantidadAcumulados[4],arrayCantidadAcumulados[5]);
	return retorno;
}

int informarRegionMasAsistida(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones)
{
	int retorno=-1;
	int maximoContador;
	int flag=0;
	int idConfeAux=100;//INICIALIZADO EN 100 TENIENDO EN CUENTA QUE LOS ID DE CONFEDERACION ARRANCAN EN ESE NUMERO

	int arrayCantidadAcumulados[tamConfederaciones];
	buscarMayorNumJugPorRegion(jugadores,  tam,  tamConfederaciones,  confederaciones,arrayCantidadAcumulados);

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
				if(flag==0)
				{
					flag=1;
					printf("+==================================================+\n|REGION %*s|"
							"\n+==================================================+\n",-43,(*(confederaciones+i)).region);
				}
				if((*(jugadores)).isEmpty==OCUPADO  && (*(jugadores+j)).idConfederacion==(*(confederaciones+i)).id)
				{
					printf("|%*s|\n",-50,(*(jugadores+j)).nombre);
				}
			}
		}
	}
	printf("+==================================================+\n");

	return retorno;
}
int menuInformes(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores, int tamConfederaciones)
{
	int retorno=-1;
	short opcionSubMenu;
	if(jugadores!=NULL && confederaciones!=NULL && contadorJugadores>0 )
	{
		printf("%s\n|%*s|\n%s\n","+====================================================================================================+"
				,-100,"                                       MENU DE INFORMES","+====================================================================================================+");

		printf("|%*s  |\n|%*s|\n|%*s  |\n|%*s  |\n|%*s |\n|%*s  |\n%s\n",-100,"1.Imprimir jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.",
				-100,"2.Listado de confederaciones con sus jugadores.",-100,"3.Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.",
				-100,"4.Informar la confederación con mayor cantidad de años de contratos total.",-100,"5.Informar porcentaje de jugadores por cada confederación."
				,-100,"6.Informar cual es la región con más jugadores y el listado de los mismos.",
				"+====================================================================================================+\n");
		ingresarShortConRango(&opcionSubMenu,"Ingrese segun desee informar", "ERROR, Ingrese opcion valida\n", 1, 6);

		switch(opcionSubMenu)
		{
		case 1:
			listarJugadores(jugadores,confederaciones,TAM, contadorJugadores,1);
		break;
		case 2:
			listarJugadoresXConfederaciones( jugadores, confederaciones, TAM, tamConfederaciones);
		break;
		case 3:
			informarTotalyMediaDeSalarios(jugadores, tam, contadorJugadores);
		break;
		case 4:
			mostrarConfConMasAniosContrato(jugadores, tam, tamConfederaciones, confederaciones);
		break;
		case 5:
			//informarPorcPorConf(jugadores, TAM,  contadorJugadores,confederaciones);
		 informarPorcPorConf( jugadores,  tam,  contadorJugadores,  confederaciones,  tamConfederaciones);
		break;
		case 6:
			informarRegionMasAsistida(jugadores,  tam,  tamConfederaciones,  confederaciones);
		break;
		}
	}
	else
	{
		printf("ERROR, Para operar esta opcion debe existir al menos 1 jugador cargado\n");
	}
	return retorno;
}






