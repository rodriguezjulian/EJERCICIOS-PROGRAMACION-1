/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J 5-2
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "calculos.h"
#define TAM 5


int main(void) {

	setbuf(stdout,NULL);

	int numerosIngresados[TAM];
	int i;
	float promedio;
	int retornoPromedio;


	for(i=0;i<TAM;i++)
	{
		numerosIngresados[i]= ingresarInt();
	}

	retornoPromedio=calcularPromedioArray(TAM, numerosIngresados, &promedio);
	if(retornoPromedio==0)
	{
		printf("El promedio es: %.2f", promedio);
	}
	else
	{
		printf("No se pudo calcular el promedio del array");
	}


	return EXIT_SUCCESS;
}
