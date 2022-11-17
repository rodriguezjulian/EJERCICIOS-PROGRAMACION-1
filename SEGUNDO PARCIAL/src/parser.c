/*
 * parser.c
 *
 *  Created on: 17 nov. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "compras.h"
#include "controller.h"
#include "ingresos.h"

int parserCompraDesdeTexto(FILE* pFile , LinkedList* listaDeCompras)
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
					//printf("\nACAAAA\n");//SE MUESTRA
					ll_add(listaDeCompras,(eCompras*) compraAux);
					//printf("|%*d|%*s|%*d|%*.2f|%*d|%*.2f|\n",-17,codigoCompra,-50,descripcion,-6,origen,-15,precioUnitario,-8,cantidad,-14,totalCompra);
					retorno=0;
				}
			}
		}
	}
	return retorno;
}
