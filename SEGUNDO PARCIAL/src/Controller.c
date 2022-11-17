/*
 * Controller.c
 *
 *  Created on: 17 nov. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "parser.h"
#include "compras.h"
#include "Controller.h"
int controllerCargarArchivoDesdeTexto(LinkedList* listaDeCompras)
{
	int retorno=-1;

	FILE *pFile=fopen("data.csv", "r");
	if(pFile!=NULL)
	{
		if(parserCompraDesdeTexto(pFile, listaDeCompras)==0)
		{
			printf("SE ABRIO EL ARCHIVO");
		}
		else
		{
			printf("sadsadsa");
		}
	}
	return retorno;

}
int jug_imprimirJugadores(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int codigoCompraAux;
	char descripcionCompraAux[100];
	int origenCompraAux=0;
	float precioUnitarioCompraAux=0;
	int  cantidadCompraAux=0;
	float totalCompraAux=0;;
	int tam;

	eCompras* pCompra;

	//index>-1 para mostrar el indice 0
	if(pArrayListJugador!=NULL)
	{
		tam=ll_len(pArrayListJugador);

		for(int i=0;i<tam;i++)
		{
			pCompra=ll_get(pArrayListJugador, i);
			if(compras_getCodigo(pCompra, &codigoCompraAux)==0 &&
					compras_getDescripcion(pCompra, descripcionCompraAux)==0 &&
					compras_getOrigen(pCompra, &origenCompraAux)==0 &&
					compras_getPrecioUnitario(pCompra, &precioUnitarioCompraAux)==0 &&
					compras_getCantidad(pCompra, &cantidadCompraAux)==0 &&
					compras_getTotal(pCompra, &totalCompraAux)==0)
			{

					retorno=0;
					//printf("ENTRE AL IF isSeleccion>0\n");
					printf("|%*d|%*s|%*d|%*.2f|%*d|%*.2f|\n",-17,codigoCompraAux,-50,descripcionCompraAux,-6,origenCompraAux,-15,precioUnitarioCompraAux,-8,cantidadCompraAux,-14,totalCompraAux);
			}
		}
	}
	return retorno;
}
/*int imprimirUnaCompra(eCompras* pCompra )
{
	int retorno=-1;
	int codigoCompraAux;
	char descripcionCompraAux[100];
	int origenCompraAux=0;
	float precioUnitarioCompraAux=0;
	int  cantidadCompraAux=0;
	float totalCompraAux=0;
	if(pCompra!=NULL)
	{
		if(compras_getCodigo(pCompra, &codigoCompraAux)==0 &&
				compras_getDescripcion(pCompra, descripcionCompraAux)==0 &&
				compras_getOrigen(pCompra, &origenCompraAux)==0 &&
				compras_getPrecioUnitario(pCompra, &precioUnitarioCompraAux)==0 &&
				compras_getCantidad(pCompra, &cantidadCompraAux)==0 &&
				compras_getTotal(pCompra, &totalCompraAux)==0)
		{
			printf("|%*d|%*s|%*d|%*.2f|%*d|%*.2f|\n",-17,codigoCompraAux,-50,descripcionCompraAux,-6,origenCompraAux,-15,precioUnitarioCompraAux,-8,cantidadCompraAux,-14,totalCompraAux);
			retorno=0;
		}
	}
	return retorno;
}
int controllerImprimirLista(LinkedList* listaDeCompras)
{
	int retorno=-1;
	eCompras* pCompra;
	int tam=ll_len(listaDeCompras);
	if(listaDeCompras!=NULL)
	{
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",-17,"CODIGO DE COMPRA",-50,"                 DESCRIPCION",-6,"ORIGEN",-15,"PRECIO UNITARIO",-8,"CANTIDAD",-14,"TOTAL COMPRA");
		for(int i=0;i<tam;i++)
		{
			pCompra=(eCompras*)ll_get(listaDeCompras, i);
			imprimirUnaCompra(pCompra);
		}
	}
	return retorno;
}*/
