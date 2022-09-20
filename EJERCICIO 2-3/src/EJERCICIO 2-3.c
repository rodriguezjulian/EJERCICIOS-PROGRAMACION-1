/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : RODRIGUEZ JULIAN MANUEL DIV J 2-3
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 2-3: Usando el concepto de operadores lógicos booleanos en el condicional.
Solicitar un número al usuario e informar si el número es par o impar.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numeroIngresado;

	printf("Ingrese numero \n");
	scanf("%d",&numeroIngresado);

	if(numeroIngresado%2==0)
	{
		printf("El numero %d es PAR", numeroIngresado);
	}
	else
	{
		printf("El numero %d es INPAR", numeroIngresado);
	}

	return EXIT_SUCCESS;
}
