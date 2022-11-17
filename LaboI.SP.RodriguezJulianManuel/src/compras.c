/*
 * compras.c
 *
 *  Created on: 16 nov. 2022
 *      Author: Julian Rodriguez
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "compras.h"
#include <string.h>
/*
int compras_getCodigo(eCompras* this,int* codigoCompra)
{
	int retorno=-1;
	if(this!=NULL)
	{
		*codigoCompra=this->codigoCompra;
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
int compras_getCantidad(eCompras* this, int* cantidadCompra)
{
	int retorno=-1;
	if(this!=NULL && cantidadCompra!=NULL)
	{
		*cantidadCompra=this->cantidadCompra;
		retorno=0;
	}
	return retorno;
}
int compras_getTotal(eCompras* this, float* totalCompra)
{
	int retorno=-1;
	if(this!=NULL && totalCompra!=NULL)
	{
		*totalCompra=this->totalCompra;
		retorno=0;
	}
	return retorno;
}
*/
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
	eCompras* pCompra;
	pCompra=compras_new();
	if(pCompra!=NULL && codigoCompra!=NULL && descripcionCompra!=NULL && origenCompra!=NULL && precioUnitarioCompra!=NULL && cantidadCompra!=NULL && totalCompra!=NULL)
	{
		printf("HOLAAA");
		pCompra->cantidadCompra=atoi(cantidadCompra);
		pCompra->codigoCompra=atoi(codigoCompra);
		strcpy(pCompra->descripcionCompra,descripcionCompra);
		pCompra->origenCompra=atoi(origenCompra);
		pCompra->precioUnitarioCompra=atof(precioUnitarioCompra);
		pCompra->totalCompra=atof(totalCompra);
	}
	return pCompra;
}

