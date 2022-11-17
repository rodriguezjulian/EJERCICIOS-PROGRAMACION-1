/*
 * compras.c
 *
 *  Created on: 16 nov. 2022
 *      Author: Julian Rodriguez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "compras.h"

int compras_setCodigo(eCompras* this,int codigoCompra)
{

	int retorno=-1;
	if(this!=NULL && codigoCompra>0)
	{
		this->codigoCompra=codigoCompra;
		retorno=0;
	}
	return retorno;
}
int compras_getCodigo(eCompras* this,int* codigoCompra)
{
	int retorno=-1;
	if(this!=NULL && codigoCompra!=NULL)
	{
		*codigoCompra=this->codigoCompra;
		retorno=0;
	}
	return retorno;
}
int compras_setDescripcion(eCompras* this,char* descripcion)
{

	int retorno=-1;
	if(this!=NULL && descripcion!=NULL && strlen(descripcion)>1 && strlen(descripcion)<100)
	{
		strcpy(this->descripcionCompra,descripcion);
		retorno=0;
	}
	return retorno;
}

int compras_getDescripcion(eCompras* this, char* descripcionCompra)
{
	int retorno=-1;
	if(this!=NULL && descripcionCompra!=NULL)
	{
		strcpy(descripcionCompra,this->descripcionCompra);
		retorno=0;
	}
	return retorno;
}
int compras_setOrigen(eCompras* this,int origen)
{

	int retorno=-1;
	if(this!=NULL)
	{
		this->origenCompra=origen;
		retorno=0;
	}
	return retorno;
}
int compras_getOrigen(eCompras* this, int* origenCompra)
{
	int retorno=-1;
	if(this!=NULL && origenCompra!=NULL)
	{
		*origenCompra=this->origenCompra;
		retorno=0;
	}
	return retorno;
}
int compras_setPrecioUnitario(eCompras* this,float PrecioUnitario)
{

	int retorno=-1;
	if(this!=NULL)
	{
		this->precioUnitarioCompra=PrecioUnitario;
		retorno=0;
	}
	return retorno;
}
int compras_getPrecioUnitario(eCompras* this, float* precioUnitarioCompra)
{
	int retorno=-1;
	if(this!=NULL && precioUnitarioCompra!=NULL)
	{
		*precioUnitarioCompra=this->precioUnitarioCompra;
		retorno=0;
	}
	return retorno;
}
int compras_setCantidad(eCompras* this,int cantidad)
{

	int retorno=-1;
	if(this!=NULL && cantidad>0)
	{
		this->cantidadCompra=cantidad;
		retorno=0;
	}
	return retorno;
}
int compras_getCantidad(eCompras* this, int* cantidadCompra)
{
	int retorno=-1;
	if(this!=NULL )
	{
		*cantidadCompra=this->cantidadCompra;
		retorno=0;
	}
	return retorno;
}
int compras_setTotal(eCompras* this,float total)
{

	int retorno=-1;
	if(this!=NULL && total>0)
	{
		this->totalCompra=total;
		retorno=0;
	}
	return retorno;
}
int compras_getTotal(eCompras* this, float* totalCompra)
{
	int retorno=-1;
	if(this!=NULL )
	{
		*totalCompra=this->totalCompra;
		retorno=0;
	}
	return retorno;
}
void compra_Delete(eCompras* this)
{
	free(this);
}
eCompras* compras_new()
{
	eCompras* pCompras;
	pCompras = (eCompras*)calloc(1,sizeof(pCompras)*1);
	return pCompras;
}
eCompras* compras_newParametros(char* codigoCompra ,char* descripcionCompra,char* origenCompra, char* precioUnitarioCompra,char* cantidadCompra,char* totalCompra)
{
	eCompras* pCompra=NULL;
	pCompra=compras_new();
	if(pCompra!=NULL && codigoCompra!=NULL && descripcionCompra!=NULL && origenCompra!=NULL && precioUnitarioCompra!=NULL && cantidadCompra!=NULL && totalCompra!=NULL)
	{

		if(compras_setCantidad(pCompra,atoi(cantidadCompra))!=0 ||
				compras_setCodigo(pCompra, atoi(codigoCompra))!=0 ||
				compras_setDescripcion(pCompra, descripcionCompra)!=0 ||
				compras_setOrigen(pCompra, atoi(origenCompra))!=0 ||
				compras_setPrecioUnitario(pCompra, atof(precioUnitarioCompra))!=0 ||
				compras_setTotal(pCompra, atof(totalCompra))!=0)
		{
			compra_Delete(pCompra);
		}
		//printf("|%*d|%*s|%*d|%*.2f|%*d|%*.2f|\n",-17,atoi(codigoCompra),-50,descripcionCompra,-6,atoi(origenCompra),-15,atof(precioUnitarioCompra),-8,atoi(cantidadCompra),-14,atof(totalCompra));
	}
	return pCompra;
}
