/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 20

int main(void) {
	setbuf(stdout,NULL);

	char codigo[TAM][4];
	char modelo[TAM][10];
	int cantidad[TAM];
	float precio[TAM];

	return EXIT_SUCCESS;
}
void menu(void)
{
	char respuesta;
	char opcion;
	int banderaCargaProductos=0;
	int banderaVenta=0;
	int banderaModificacion=0;
	int banderaListarOrdenado=0;
	int banderaListarProductos3=0;
	do
	{
		//METER AL PRINTF EN UNA FUNCION
		printf("Ingrese opcion que desea operar\n"
				"'A'Carga de productos\n"
				"'B' Venta de productos\n"
				"'C'Modificación del precio\n"
				"'D'Modificar el modelo\n"
				"'E'Listar ordenado por código\n"
				"'F'Listar datos de los productos con menos de 3 unidades\n");
		fflush(stdin);
		scanf("%c",&opcion);

		switch(opcion)
		{
			case'A':
				printf("Carga de productos\n");
			break;
			case 'B':
				printf("Venta de productos\n");
			break;
			case 'C':
				printf("Modificación del precio\n");
			break;
			case'D':
				printf("Modificar el modelo\n");
			break;
			case 'E':
				printf("Listar ordenado por código\n");
			break;
			case 'F':
				printf("Listar datos de los productos con menos de 3 unidades\n");
			break;
		}

		printf("Pulse 'S' para continuar operando");
		fflush(stdin);
		scanf("%c",&respuesta);

	}while(respuesta=='S');
}