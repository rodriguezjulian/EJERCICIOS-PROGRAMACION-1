#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"seleccion.h"

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
		pSeleccion->convocados=*convocadosStr;
		pSeleccion->id=*idStr;
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
	}

	return retorno;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;
	if(this!=NULL)
	{
		strcpy(pais,this->pais);

	}
	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		strcpy(confederacion,this->confederacion);
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->convocados=convocados;
	}
	return retorno;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;
	if(this!=NULL)
	{
		*convocados=this->convocados;
	}
	return retorno;
}
