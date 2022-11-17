/*
 * controller.c
 *
 *  Created on: 16 nov. 2022
 *      Author: Julian Rodriguez
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "compras.h"
#include "ingresos.h"
#include "parser.h"
//
int controller_cargarComprasDesdeTexto(char* path , LinkedList* pArrayListaCompra)
{
	int retorno = -1;
	FILE *pArchivo= fopen(path,"r");
	if(pArchivo != NULL)
	{
		parser_compraFromText(pArchivo,pArrayListaCompra);
		retorno = 0;
	}
	else
	{
		retorno = -1;
		//printf("error\n");
	}
	fclose(pArchivo);
	return retorno;
}



/*int controllerCargarArchivoDesdeTexto(LinkedList* listaDeCompras)
{
	int retorno=-1;
	//char nombreArchivo[200];
	FILE* pFile=NULL;

	//do
	//{
		//ingreseNombreArchivo("Ingrese nombre del archivo que desea cargar.\n", nombreArchivo);
		pFile=fopen("data.csv", "r");
		if(pFile!=NULL)
		{
			parserCompraDesdeTexto(pFile, listaDeCompras);
			if(parserCompraDesdeTexto(pFile, listaDeCompras)!=0)
			{

				printf("ERROR AL CARGAR EL ARCHIVO");
			}}
		}
		else
		{
				printf("<<<<<<<<< ARCHIVO CARGADO SATISFACTORIAMENTE >>>>>>>>>>\n");
				retorno=0;
		}


		if(retorno!=0)
		{
			printf("ERROR,Ingrese nombre de archivo valido.\n");
		}
		fclose(pFile);
	}while(retorno!=0);
	return retorno;
}
*/
/*int controllerImprimirLista(LinkedList* listaDeCompras)
{
	int retorno=-1;
	eCompras* pCompra;
	int codigoCompraAux;
	char descripcionCompraAux[100];
	int origenCompraAux;
	float precioUnitarioCompraAux;
	int  cantidadCompraAux;
	float totalCompraAux;

	if(listaDeCompras!=NULL)
	{
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",-17,"CODIGO DE COMPRA",-50,"                 DESCRIPCION",-6,"ORIGEN",-15,"PRECIO UNITARIO",-8,"CANTIDAD",-14,"TOTAL COMPRA");
		for(int i=0;i<ll_len(listaDeCompras);i++)
		{
			pCompra=ll_get(listaDeCompras, i);
			//printf("%d\n",(*(pCompra+i)).origenCompra);
			if(compras_getCodigo(pCompra, &codigoCompraAux)==0 &&
					compras_getDescripcion(pCompra, descripcionCompraAux)==0 &&
					compras_getOrigen(pCompra, &origenCompraAux)==0 &&
					compras_getPrecioUnitario(pCompra, &precioUnitarioCompraAux)==0 &&
					compras_getCantidad(pCompra, &cantidadCompraAux)==0 &&
					compras_getTotal(pCompra, &totalCompraAux)==0)
			{
				//printf("|%*d|%*s|%*d|%*.2f|%*d|%*.2f|\n",-17,codigoCompraAux,-50,descripcionCompraAux,-6,origenCompraAux,-15,precioUnitarioCompraAux,-8,cantidadCompraAux,-14,totalCompraAux);
			}
		}
	}
	return retorno;
}*/



















