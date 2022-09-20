/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN DIV J EJERCICIO 3-2
#include <stdio.h>
#include <stdlib.h>
float ingresarYRetornarFlotante(void);

int main(void) {
	setbuf(stdout,NULL);

	float sueldo;
	sueldo=ingresarYRetornarFlotante();

	printf("El sueldo es %.2f pesos",sueldo);

	return EXIT_SUCCESS;
}
float ingresarYRetornarFlotante(void)
{
	float numeroIngresado;
	printf("Ingrese numero\n");
	scanf("%f",&numeroIngresado);

	return numeroIngresado;
}
