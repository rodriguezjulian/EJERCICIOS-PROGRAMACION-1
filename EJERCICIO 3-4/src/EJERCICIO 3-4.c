/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 3-4
#include <stdio.h>
#include <stdlib.h>
#define MIN 10
#define MAX 100
int validarFloatConRango(float numeroIngresado, int max, int min);

int main(void){
	setbuf(stdout,NULL);

	float numeroIngresado;
	int validacion;

	printf("Ingrese numero \n");
	scanf("%f",&numeroIngresado);
	//SI SALIO TODO BIEN 1 SINO 0
	validacion=validarFloatConRango(numeroIngresado,MIN,MAX);

	printf("El numero ingresado es %.2f, por lo se valida con: %d",numeroIngresado,validacion);

	return EXIT_SUCCESS;
}
int validarFloatConRango(float numeroIngresado, int min, int max)
{
	int retorno;
	//SI SALIO TODO BIEN 1 SINO 0
	if(numeroIngresado>=min && numeroIngresado<=max)
	{
		retorno=1;
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
