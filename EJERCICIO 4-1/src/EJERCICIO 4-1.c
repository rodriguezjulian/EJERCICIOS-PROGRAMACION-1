/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J  EJERCICIO 4-1
#include <stdio.h>
#include <stdlib.h>
int pedirNumeroEntero();

int main(void) {
	setbuf(stdout,NULL);
	int acumulador;
	int numeroIngresado;
	char respuesta;

	acumulador=1;
	do
	{
		numeroIngresado=pedirNumeroEntero();
		acumulador=acumulador*numeroIngresado;

		printf("Si desea ingresar otro numero presione 's'");
		fflush(stdin);
		scanf("%c",&respuesta);

	}while(respuesta=='s');

	printf("Factorial de numeros ingresados: %d",acumulador);

	return EXIT_SUCCESS;
}
int pedirNumeroEntero()
{
	int numeroIngresado;
	printf("Ingrese numero entero ");
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}
