#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"seleccion.h"

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
