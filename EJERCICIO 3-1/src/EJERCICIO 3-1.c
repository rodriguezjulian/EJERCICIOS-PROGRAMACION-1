/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 3-1
#include <stdio.h>
#include <stdlib.h>
void imprimir(int numero);

int main(void) {
	setbuf(stdout,NULL);

	int numero;
	numero=10;

	imprimir(numero);

	return EXIT_SUCCESS;
}

void imprimir(int numero)
{
	printf("%d",numero);
}
