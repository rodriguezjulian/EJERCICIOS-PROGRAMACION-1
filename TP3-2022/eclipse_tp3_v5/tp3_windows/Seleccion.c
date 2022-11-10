#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seleccion.h"
#include "ingresos.h"
#include "Jugador.h"
void selec_delete(Seleccion* this)
{

	free(this);
}

Seleccion* selec_new()
{
	Seleccion* pSeleccion;
	pSeleccion = (Seleccion*)calloc(1,sizeof(Seleccion)*1);
	return pSeleccion;
}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* pSeleccion;
	pSeleccion=selec_new();
	if(pSeleccion!=NULL)
	{
		pSeleccion->convocados=atoi(convocadosStr);
		pSeleccion->id=atoi(idStr);
		strcpy(pSeleccion->confederacion,confederacionStr);
		strcpy(pSeleccion->pais,paisStr);
	}
	return pSeleccion;
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno=-1;
	if(this!=NULL)
	{
		*id=this->id;
		retorno=0;
	}

	return retorno;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;
	if(this!=NULL)
	{
		strcpy(pais,this->pais);
		retorno=0;

	}
	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		strcpy(confederacion,this->confederacion);
		retorno=0;
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->convocados=convocados;
		retorno=0;
	}
	return retorno;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;
	if(this!=NULL)
	{
		*convocados=this->convocados;
		retorno=0;
	}
	return retorno;
}
int imprimirSeleccion(LinkedList* pArrayListSeleccion, int index)
{
	int retorno=-1;
	Seleccion* seleccionAux;
	int id;
	char pais[50];
	char confederacion[50];
	int convocados;
	seleccionAux=ll_get(pArrayListSeleccion, index);

	if(pArrayListSeleccion!=NULL && index>-1)
	{

		if(selec_getId(seleccionAux, &id)==0 &&
		selec_getPais(seleccionAux, pais)==0 &&
		selec_getConfederacion(seleccionAux, confederacion)==0 &&
		selec_getConvocados(seleccionAux, &convocados)==0)
		{
			//printf("IMPRIMIR SELECCION ENTRO");
			printf("| %*d|%*s|%*s| %*d|\n",-3,id,-25,pais,-15,confederacion,-9,convocados);
		}
	}
	return retorno;
}
int selec_IngresarConfederacion(char* opcion)
{
	int retorno=-1;
	int flag=0;
	char opcionAux[30];

	do
	{
		ingresarCadenaCaracteres(30, opcionAux, "Ingrese confederacion de la que desea guardar listado de jugadores.\n"
				" AFC - CAF - CONCACAF - CONMEBOL - UEFA \n", "ERROR,Ingrese conferacion valida.\n");

		//if(strcmp(opcionAux,"AFC") && opcionAux!="CAF" && opcionAux!="CONCACAF" && opcionAux!="CONMEBOL" && opcionAux!="UEFA")
		if(strcmp(opcionAux,"AFC")==0 || strcmp(opcionAux,"CAF")==0 || strcmp(opcionAux,"CONCACAF")==0 || strcmp(opcionAux,"CONMEBOL")==0 || strcmp(opcionAux,"UEFA")==0)
		{
			flag=1;
			strcpy(opcion,opcionAux);

			retorno=0;
		}
		else
		{
			printf("ERROR, Ingrese confederacion valida.\n");
		}

	}while(flag==0);

	return retorno;
}
//ME FIJO SI LOS PAISES DE LA CONFEDERACION SELECCIONADA TIENEN JUGADORES CONVOCADOS, EN CASO QUE EL CONTADOR SEA MAYOR A UNO YA SE PUEDE SEGUIR
//RETORNO =0 ESTA TODO OK, HAY AL MENOS UN JUGADOR CONVOCADO EN LA CONFEDERACION.
int selec_verificarConvocadosPorconfederacion(char* opcion, LinkedList* pArrayListSeleccion, int* convocados )
{
	int retorno=-1;
	Seleccion* pSeleccion;
	int tam;
	int convocadosAux=0;

	tam= ll_len(pArrayListSeleccion);

	if(opcion!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			if(strcmp((*(pSeleccion)).confederacion,opcion)==0)
			{
				convocadosAux=convocadosAux+(*(pSeleccion)).convocados;
			}
		}
	}
	//printf("CONVOCADOS: %d\n",convocados);
	if(convocadosAux>0)
	{
		retorno=0;
		*convocados=convocadosAux;
	}
	else
	{
		printf("ERROR, Los paises que integran a la confederacion %s, NO cuentan con convocados.\n",opcion);
	}
	return retorno;
}
int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais)
{
	int retorno=-1;
	Jugador* pJugador;
	//int idSeleccion;//EL QUE TIENE LA ESTRUCTURA JUGADOR
	int tam;
	Seleccion* pSeleccion;

	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//PUNTERO A LA ESTRUCTURA TENIENDO EL INDICE
		pJugador=ll_get(pArrayListJugador, indice);

		//BUSCO EL TAMANIO DE LA LISTA DE SELECCIONES
		tam=ll_len(pArrayListSeleccion);
		for(int i=0;i<tam;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			if((*(pSeleccion)).id==(*(pJugador)).idSeleccion)
			{
				//PASO EL NOMBRE DEL PAIS
				strcpy(descripcionPais, (*(pSeleccion)).pais);
				break;
			}
		}
	}
	return retorno;
}
int selec_buscarPorId(LinkedList* pArrayListSeleccion, int idBuscado, int *indice)
{
	int retorno=-1;
	int tam;
	Seleccion* pSeleccion;
	tam=ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion!=NULL)
	{

		for(int i=0;i<tam;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			if((*(pSeleccion)).id==idBuscado)
			{
				*indice=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int selec_Solicitar_Id(LinkedList* pArrayListSeleccion, int* indice)
{
	int retorno=-1;
	int idPais;
	Seleccion* pSeleccion;
	if(pArrayListSeleccion!=NULL)
	{
		//SOLICITO ID.
		ingresarIntConRango(&idPais, "Ingrese pais para el que desea convocar jugadores.\n", "ERROR, Ingerse ID valido,\n", 1, 32);
		//CON EL ID, PASO A BUSCAR EL INDICE.
		selec_buscarPorId(pArrayListSeleccion, idPais, &(*(indice)));
		// BUSCO EL PUNTERO AL ELEMENTO TENIENDO EN CUENTA EL INDICE.
		pSeleccion=ll_get(pArrayListSeleccion, *(indice));

		if((*(pSeleccion)).convocados<22)
		{
			retorno=0;
		}
		else
		{
			printf("ERROR, La seleccion llego a su maximo de 22 convocados.\n");
		}
	}
	return retorno;
}
int selec_OrdenarPorConfederacion(void* unaConderacion, void* otraConfederacion)
{
	int retorno=0;//SON IGUALES
	int compara;
	char confederacionUno [30];
	char confederacionDos [30];

	selec_getConfederacion(unaConderacion, confederacionUno);
	selec_getConfederacion(otraConfederacion, confederacionDos);

	compara=strcmp(confederacionUno,confederacionDos);
	if(compara>0)//UNO MAYOR
	{
		retorno=1;
	}
	else
	{
		if(compara<0)//2 MAYOR
		{
			retorno=-1;
		}
	}
	return retorno;
}
/*int selec_buscar_Pais(LinkedList* listaConfederaciones, int id, char* paisEncontrado)
{
	int retorno=-1;
	int cantidad;
	cantidad=ll_len(listaConfederaciones);
	Seleccion* pPaises;

	if(listaConfederaciones!=NULL)
	{
		for(int i=0;i<cantidad;i++)
		{
			pPaises=ll_get(listaConfederaciones, i);
			if(id==(*(pPaises)).id)
			{
				selec_setConvocados(pPaises, convocados)
				paisEncontrado=(*(pPaises+i)).pais;
				printf("PAIS ENCONTRADO: %s",paisEncontrado);
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}*/
