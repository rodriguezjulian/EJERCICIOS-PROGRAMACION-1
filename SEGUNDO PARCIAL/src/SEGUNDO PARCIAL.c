/*
 ============================================================================
 Name        : SEGUNDO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "controller.h"
#include "ingresos.h"

int main(void) {
	setbuf(stdout,NULL);
	//int opcion;
	//int flag=0;
	LinkedList* listaDeCompras = ll_newLinkedList();

	controllerCargarArchivoDesdeTexto(listaDeCompras);
	jug_imprimirJugadores( listaDeCompras);

	/*do
	{
		printf("+====================+\n|%*s|\n+====================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n+====================+\n"
				,-20,"   MENU PRINCIPAL",-20,"1.CARGAR ARCHIVO",-20,"2.IMPRIMIR LISTA",-20,"3.ASIGNAR TOTALES",-20,"4.FILTRAR POR TIPO",-20,
				"5.MOSTRAR COMPRAS",-20,"6.GUARDAR COMPRAS",-20,"7.SALIR");

		ingresarIntConRango(&opcion, "Ingrese opcion segun desee operar.\n", "ERROR,Ingrese opcion valida.\n", 1, 7);

		switch(opcion)
		{
			case 1:
				controllerCargarArchivoDesdeTexto(listaDeCompras);

			break;
			case 2:
			//	controllerImprimirLista(listaDeCompras);
				controller_listarCompras(listaDeCompras);
			break;
			case 3:
			break;
			case 4:
			break;
			case 5:
			break;
			case 6:
			break;
			case 7:
			break;
			}
	}while(flag==0);*/

	return EXIT_SUCCESS;
}
