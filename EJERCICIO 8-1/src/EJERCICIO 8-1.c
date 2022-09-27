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
#include "ingresos.h"
#include<string.h>
#include <ctype.h>
#include "calculos.h"
#define TAM 2

void ejecutarMenuprincipal(char respuesta, char* opcion);
int cargarProductos(char codigo[][5],char modelo[][11] ,int* cantidad, float* precio,int longitud);

int main(void) {
	setbuf(stdout,NULL);

	char codigo[TAM][5];
	char modelo[TAM][11];
	int cantidad[TAM];
	float precio[TAM];
	char opcion;

	//int banderaCargaProductos=0;
	//int banderaVenta=0;
	//int banderaModificacion=0;
	//int banderaListarOrdenado=0;
	//int banderaListarProductos3=0;

	char respuesta='S';
	do
	{
		ejecutarMenuprincipal(respuesta, &opcion);
		switch(opcion)
		{
			case'A'://
				printf("Carga de productos\n");
				cargarProductos(codigo,modelo,cantidad,precio,TAM);
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

	return EXIT_SUCCESS;
}

void ejecutarMenuprincipal(char respuesta, char* opcion)
{
	char axuliar;
	if(respuesta=='S')
	{
		printf("Ingrese opcion que desea operar\n"
				"'A'Carga de productos\n"
				"'B' Venta de productos\n"
				"'C'Modificación del precio\n"
				"'D'Modificar el modelo\n"
				"'E'Listar ordenado por código\n"
				"'F'Listar datos de los productos con menos de 3 unidades\n");
		fflush(stdin);
		scanf("%c",&axuliar);
		*opcion=axuliar;
	}
}
int cargarProductos(char codigo[][5],char modelo[][11] ,int* cantidad, float* precio,int longitud)
{
	int retorno=-1;
	int i=0;
	char axuliarCodigo [longitud][5];
	char auxiliarModelo [longitud][11];
	int auxiliarCantidad [longitud];
	float auxiliarPrecio[longitud];

	do
	{
		if(axuliarCodigo!=NULL && modelo!=NULL && longitud>0)
		{

				do
				{
					ingresarArrayCaracteres(axuliarCodigo[i],"Ingrese codigo alfanumerico de 4 caracteres","ERROR,cargue codigo valido\n",5);
					if(validarAlfanumerico(axuliarCodigo[i])==-1)
					{
						printf("ERROR,cargue codigo valido\n");
					}

				}while((validarAlfanumerico(axuliarCodigo[i])==-1));
				strcpy(*codigo,axuliarCodigo[i]);

				ingresarArrayCaracteres(auxiliarModelo[i],"Ingrese modelo","ERROR,cargue modelo valido\n",5);
				strcpy(*modelo,auxiliarModelo[i]);

				if(ingresarNumerosConRangoV1(&auxiliarCantidad[i], "Ingrese cantidad", "ERROR, ingrese cantidad valida", 1, 10000)==0 && ingresarFloatConMinimo(&auxiliarPrecio[i], "Ingrese precio","ERROR, ingrese precio valido",0)==0)
				{
					*cantidad=auxiliarCantidad[i];
					*precio=auxiliarPrecio[i];
					retorno=0;
					i=i+1;
				}

			}
		}while(i>longitud);




	return retorno;
}

