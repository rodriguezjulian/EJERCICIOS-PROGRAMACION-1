/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 5-3
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "calculos.h"
#define TAM 5

int main(void) {
	setbuf(stdout,NULL);

	int numerosIngresados[TAM];
	int valorMaximo;
	int retorno;

	for(int i=0;i<TAM;i++)
	{
		numerosIngresados[i]= ingresarInt();
	}

	retorno=calcularMaximoArray(numerosIngresados, &valorMaximo);
	if(retorno==0)
	{
		printf("El valor maximo cargado es %d", valorMaximo);
	}
	else
	{
		printf("No se pudo calcular el valor maximo");
	}

	return EXIT_SUCCESS;
}

