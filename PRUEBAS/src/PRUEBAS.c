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
#include<string.h>

void borrarNum(int *numeros, int tam, int numBorrar);

int main(void) {
	setbuf(stdout, NULL);
	int *numeros;
	numeros = (int*)malloc(sizeof(int)*5);
	if (numeros != NULL) {
		for(int i = 0; i < 5; i++){
			*(numeros + i) = i;
		}
		for(int i = 0; i < 5; i++){
			printf("%d\n", *(numeros + i));
		}
	}
	borrarNum(numeros, 5, 2);
	printf("Borramos el numero 2\n");
	for(int i = 0; i < 4; i++){
		printf("%d\n", *(numeros + i));
	}
	free(numeros);
	return EXIT_SUCCESS;
}

void borrarNum(int *numeros, int tam, int numBorrar)
{
	if (numeros != NULL)
	{
		int *aux;
		int j = 0;

		aux = (int*)realloc(numeros,sizeof(int)*(tam-1));
		if (aux != NULL)
		{
			for(int i = 0; i < tam; i++)
			{
				if (*(numeros + i) != numBorrar)
				{
					*(aux + j) = *(numeros + i);
					j++;
				}
			}
			numeros = aux;
			free(aux);
		}
	}else
	{
		printf("ocurrio un error");
	}
}






