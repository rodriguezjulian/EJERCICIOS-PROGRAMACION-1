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
	int id;
	char pais[50];
	char confederacion[50];
	int convocados;
	Seleccion* seleccionAux;
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
int selec_verificarConvocadosPorconfederacion(char* opcion, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	Seleccion* pSeleccion;
	int tam;
	char selecConfederacion[30];
	int selecConvocados;
	tam= ll_len(pArrayListSeleccion);

	if(opcion!=NULL)
	{


		for(int i=0;i<tam;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			//RECIBI POR PARAMETRO A LA CONFEDERACION ELEGIDA, AHORA ME FIJO SI LAS SELECCIONES CON ESA CONFEDERACION, TIENEN CONVOCADOS
			if(selec_getConfederacion(pSeleccion, selecConfederacion)==0 && selec_getConvocados(pSeleccion, &selecConvocados)==0)
			{
				//if(strcmp((*(pSeleccion)).confederacion,opcion)==0 && (*(pSeleccion)).convocados>0)
				if(strcmp(selecConfederacion,opcion)==0 && selecConvocados>0)
				{
					retorno=0;
					break;
				}
			}
			else
			{
				printf("ERROR al intentar acceder a la confederacion / cantidad de convocados.\n");
			}

		}
	}

	return retorno;
}
int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais)
{
	int retorno=-1;
	Jugador* pJugador;
	int tam;
	Seleccion* pSeleccion;
	int selecId;
	char selecPais[30];
	int jugIdSeleccion;


	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//printf("ENTRE AL IF en selec_AsignarDescripcionPais >0\n");
		//PUNTERO A LA ESTRUCTURA TENIENDO EL INDICE
		pJugador=ll_get(pArrayListJugador, indice);
		//BUSCO EL TAMANIO DE LA LISTA DE SELECCIONES
		tam=ll_len(pArrayListSeleccion);
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRE AL FOR en selec_AsignarDescripcionPais >0\n");
			pSeleccion=ll_get(pArrayListSeleccion, i);
		//	printf("PASE EL ll_get\n");
			if(selec_getId(pSeleccion, &selecId)==0 && jug_getSIdSeleccion(pJugador, &jugIdSeleccion)==0)
			{
				//printf("OBTUVE LOS GETTERS\n");
				if(selecId==jugIdSeleccion)
				{
				//	printf("COINCIDENCIA ENTRE EL ID DE SELECCION DEL JUG Y EL DE LA SELEC \n");
					if(selec_getPais(pSeleccion, selecPais)==0)
					{
						retorno=0;
						//PASO EL NOMBRE DEL PAIS
						//printf("HAGO STRCPY selec_AsignarDescripcionPais >0\n");
						strcpy(descripcionPais, selecPais);
						break;
					}
				}
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
	int selecConvocados;
	if(pArrayListSeleccion!=NULL)
	{
		//SOLICITO ID.
		ingresarIntConRango(&idPais, "Ingrese pais para el que desea convocar jugadores.\n", "ERROR, Ingerse ID valido,\n", 1, 32);
		//CON EL ID, PASO A BUSCAR EL INDICE.
		if(selec_buscarPorId(pArrayListSeleccion, idPais, &(*(indice)))==0)
		{
			// BUSCO EL PUNTERO AL ELEMENTO TENIENDO EN CUENTA EL INDICE.
			pSeleccion=ll_get(pArrayListSeleccion, *(indice));
			if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
			{
				//if((*(pSeleccion)).convocados<22)
				if(selecConvocados<22)
				{
					retorno=0;
				}
				else
				{
					printf("ERROR, La seleccion llego a su maximo de 22 convocados.\n");
				}
			}

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
int selec_buscarPorId(LinkedList* pArrayListSeleccion, int idBuscado, int *indice)
{
	int retorno=-1;
	int tam;
	Seleccion* pSeleccion=NULL;
	int selecId;
	tam=ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion!=NULL)
	{
		//printf("ENTRO 0\n");
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRO 1\n");
			pSeleccion=ll_get(pArrayListSeleccion, i);
			//printf("ENTRO 2\n");
			if(selec_getId(pSeleccion, &selecId)==0)
			{
				//printf("ENTRO 3\n");
				//if((*(pSeleccion)).id==idBuscado)
				if(selecId==idBuscado)
				{
					//printf("ENTRO 4\n");
					*indice=i;
					retorno=0;
					break;
				}
			}
			else
			{
				printf("ERROR al obtener el id de la seleccion.\n");
			}
		}
	}
	return retorno;
}
int selec_restarConvocado(LinkedList* pArrayListSeleccion, int idSeleccion)
{
	int retorno=-1;
	int selecIndice;
	Seleccion* pSeleccion;
	int selecConvocados;
	//printf("ENTRO 0\n");
	if(pArrayListSeleccion!=NULL)
	{
	//	printf("ID SELECCION %d \n",idSeleccion);
		if(selec_buscarPorId(pArrayListSeleccion, idSeleccion, &selecIndice)==0)
		{
		//	printf("INDICE DEL PAIS %d",selecIndice);
			pSeleccion=ll_get(pArrayListSeleccion, selecIndice);
			//printf("ENTRO 1\n");
			//EN CASO DE HACERLO DEBO RESTAR 1 AL CONTADOR DE CONVOCADOS DE ESA SELECCION
			if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
			{
				//printf("CONVOCADOS ANTES %d",selecConvocados);
				selecConvocados=selecConvocados-1;
				//printf("CONVOCADOS DESPUES %d",selecConvocados);
				if(selec_setConvocados(pSeleccion, selecConvocados)==0)
				{
					retorno=0;
					printf("<<<<<<<<<< JUGADOR DESCONTADO DE SU SELECCION  >>>>>>>>>\n");
				}
			}
		}
	}
	return retorno;
}

