/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 3-6
#include <stdio.h>
#include <stdlib.h>

#define MIN 10
#define MAX 100
#define PORCENTAJE -5

int pedirNumeroEntero();
int validarFloatConRango(float numeroIngresado, int min, int max);
float aplicarPorcentaje(float valor, int porcentaje);

int main(void) {
	setbuf(stdout,NULL);

	float numeroIngresado;
	int retornoRango;
	float resultadoConDescuento;

	do{
			numeroIngresado=pedirNumeroEntero();

			retornoRango=validarFloatConRango(numeroIngresado,MIN,MAX);
			if(retornoRango==1)
			{
				resultadoConDescuento=aplicarPorcentaje( numeroIngresado, PORCENTAJE);
				printf("Resultado con descuento: %.2f",resultadoConDescuento);
			}
			else
			{
				printf("ERROR, Ingrese un numero del rango solicitado\n");
				retornoRango=0;
			}
		}while(retornoRango==0);

	return EXIT_SUCCESS;
}
int pedirNumeroEntero()
{
	int numeroIngresado;
	printf("Ingrese numero entero ");
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}
int validarFloatConRango(float numeroIngresado, int min, int max)
{
	int retorno;
	//SI SALIO TODO BIEN 1 SINO 0/
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
float aplicarPorcentaje(float valor, int porcentaje)
{
	float resultado;
	resultado=(porcentaje*valor/100)+valor;
	return resultado;
}



/*
 void aplicarPorcentaje(float valor, int porcentaje, float *resultado)
{
	*resultado=(porcentaje*valor/100)+valor;
}
 */
