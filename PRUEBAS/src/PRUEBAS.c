/*
 ============================================================================
 Name        : PRUEBAS.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J - EJERCICIO ARRAYS EN CLASE
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#define TAM 2

void mostrarNombre(char arrayNombre[][20],int tam);

int main(void) {

	setbuf(stdout,NULL);

	char nombre[2][20];
	//[filas][columnas] las columnas serian el largo

	for(int i=0;i<TAM;i++)
	{
		printf("Ingrese nombre");
		fflush(stdin);
		scanf("%s", nombre[i]);
	}
	mostrarNombre(nombre,TAM);

	return EXIT_SUCCESS;
}

void mostrarNombre(char arrayNombre[][20],int tam)
{
	int i;
	for(i=0;i<TAM;i++)
	{
		printf("\nSu nombre es:%s",arrayNombre[i]);
	}
}








