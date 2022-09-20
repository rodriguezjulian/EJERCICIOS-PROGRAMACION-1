/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN DIV J EJERCICIO 3-3
#include <stdio.h>
#include <stdlib.h>
int determinarPar(int numero);

int main(void) {
	setbuf(stdout,NULL);

	int numeroIngresado;
	int retorno;

	printf("Ingrese numero entero\n");
	scanf("%d", &numeroIngresado);

	retorno=determinarPar(numeroIngresado);
	//0 = PAR 1=INPAR
	printf("El numero ingresado es %d, por lo que le corresponde un %d \n",numeroIngresado,retorno);

	return EXIT_SUCCESS;
}
int determinarPar(int numero)
{
	//0 = PAR 1=INPAR
	int retorno;
 	if(numero%2==0)
	{
		retorno=1;
	}
	else
	{
		retorno=0;
	}
	return retorno;
}



/*
 	if(numeroIngresado%2==0)
	{
		printf("El numero %d es PAR", numeroIngresado);
	}
	else
	{
		printf("El numero %d es INPAR", numeroIngresado);
	}
 */
