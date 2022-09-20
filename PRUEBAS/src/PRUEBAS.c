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
#define TAM 5

int calcularPromedioArray(int tam, int* array, float *promedio);

int main(void) {

	setbuf(stdout,NULL);

	int numerosIngresados[TAM];
	int i;
	float promedio;
	int retorno;


	for(i=0;i<TAM;i++)
	{
		numerosIngresados[i]= ingresarInt();
	}

	retorno=calcularPromedioArray(TAM, numerosIngresados, &promedio);
	if(retorno==0)
	{
		printf("El promedio es: %.2f", promedio);
	}
	else
	{
		printf("No se pudo calcular el promedio del array");
	}


	return EXIT_SUCCESS;
}
int calcularPromedioArray(int tam, int* array, float* promedio)
{
	int retorno=-1;
	int acumulador;
	acumulador=0;

	if(tam>0 && array!=NULL && promedio!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			acumulador=acumulador+array[i];
		}
		*promedio=(float)acumulador/tam;
		retorno=0;
	}
	return retorno;//
}









