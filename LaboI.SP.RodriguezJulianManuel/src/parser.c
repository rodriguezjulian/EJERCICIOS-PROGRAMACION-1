/*
 * parser.c
 *
 *  Created on: 16 nov. 2022
 *      Author: Julian Rodriguez
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "compras.h"
#include <string.h>
#include "controller.h"
#include "ingresos.h"

int parser_compraFromText(FILE* pFile , LinkedList* pArrayListaCompra)
{
	int retorno = -1;
	eCompras* unaCompra;
	char bufferCompra[6][200];
	int cantidad;

	if(pFile != NULL && pArrayListaCompra != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				bufferCompra[0],bufferCompra[1],bufferCompra[2],
				bufferCompra[3],bufferCompra[4],bufferCompra[5]);
		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					bufferCompra[0],bufferCompra[1],
					bufferCompra[2],bufferCompra[3],
					bufferCompra[4],bufferCompra[5]);
			if(cantidad < 6)
			{
				//com_delete(unaCompra);
				unaCompra = NULL;
				retorno=-1;
				break;
			}else
			{
				unaCompra = compras_newParametros(
						bufferCompra[0],
						bufferCompra[1],
						bufferCompra[2],
						bufferCompra[3],
						bufferCompra[4],
						bufferCompra[5]);
				if(unaCompra != NULL)
				{
					//ll_add(pArrayListaCompra,unaCompra);
					ll_add(pArrayListaCompra,(eCompras*)unaCompra);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
/*int parserCompraDesdeTexto(FILE* pFile , LinkedList* listaDeCompras)
{

	int retornoCantidad;
	char codigoCompra [20];
	char descripcion [100];
	char origen[20];
	char precioUnitario[20];
	char cantidad[20];
	char totalCompra[20];
	//POR BUENA PRACTICA LO INICIALIZO
	eCompras* compraAux=NULL;
	int retorno;

	if(pFile!=NULL && listaDeCompras!=NULL)
	{
		//LECTURA FANTASMA
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);
		while(!feof(pFile))
		{
			//USO AL RETORNO DE SCANF PARA VERIFICAR QUE ESTA TODO BIEN
			retornoCantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);
			if(retornoCantidad<6)
			{
				compra_Delete(compraAux);
				compraAux=NULL;
				retorno=-1;
				break;
			}
			else
			{
				compraAux=compras_newParametros(codigoCompra, descripcion, origen, precioUnitario, cantidad, totalCompra);
				if(compraAux!=NULL)
				{
					printf("\nACAAAA\n");//SE MUESTRA
					if(ll_add(listaDeCompras,(eCompras*) compraAux)==0)
					{
						printf("\nLL_ADD SALIO BIEN\n");
					}
					else
					{
						printf("LL_ADD  salio MAL\n");
					}
					retorno=0;
				}
			}
		}
	}
	return retorno;
}*/
