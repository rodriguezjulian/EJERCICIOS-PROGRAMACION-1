/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J 5-1
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#define TAM 5

int main(void) {
	setbuf(stdout,NULL);
	int numerosIngresados [TAM];
	int acumulador;
	acumulador=0;
	for(int i=0;i<5;i++)
	{
		numerosIngresados[i]=ingresarInt();
		acumulador=acumulador+numerosIngresados[i];
		if(numerosIngresados[i]%2!=0)
		{
			printf("El numero %d es impar\n",numerosIngresados[i]);
		}
	}//numeroIngresado%2==0
	printf("La sumatoria de los numeros ingresados es: %d",acumulador);
	return EXIT_SUCCESS;
}

