/*
 ============================================================================
 Name        : PARCIALITO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J PARCIALITO 3
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"

int calcularMayoryMenor(int numeroA, int numeroB, int* mayor);

int main(void) {
	setbuf(stdout,NULL);
////
	int numeroA;
	int numeroB;
	int mayor;
	int menor;

	ingresarInt2(&numeroA);
	ingresarInt2(&numeroB);

	menor=calcularMayoryMenor(numeroA, numeroB, &mayor);

	printf("Numeros ingresados %d | %d \n Numero mayor= %d \n Numero menor= %d\n",numeroA,numeroB,mayor,menor);

	return EXIT_SUCCESS;
}
int calcularMayoryMenor(int numeroA, int numeroB, int* mayor)
{
	//ME FALTO VALIDAR EL PUNTERO
	int menor;
	if(numeroA>numeroB)
	{
		*mayor=numeroA;
		menor=numeroB;
	}
	else
	{
		*mayor=numeroB;
		menor=numeroA;
	}

	return menor;
}
