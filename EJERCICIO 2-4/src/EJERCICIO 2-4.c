/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : Rodriguez Julian Manuel DIV J 2-4
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 2-4:
Ingresar 8 números enteros, distintos de cero. Mostrar:
a. El menor número ingresado.
b. De los pares el mayor número ingresado.
c. Producto de los negativos.
d. En qué lugar fue ingresado el mayor numero
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int contador;
	int numeroIngresado;
	//int banderaMenorNum;
	int menorNumIngresado;
	int banderaMayorNumPar;
	int mayorNumPar;
	int mayorNum;
	int posicionDeIngresoNumMayor;
	int acumuladorProductoNegativos;


	contador=0;
	//banderaMenorNum=0; NO USAR
	banderaMayorNumPar=0;
	acumuladorProductoNegativos=1;//inicializo en 1 porque sino me queda todo en 0
	while(contador<8)
	{
		contador=contador+1;

		printf("Ingrese numero entero distinto de cero \n");
		scanf("%d",&numeroIngresado);

		while(numeroIngresado==0)
		{
			printf("ERROR,Ingrese numero entero distinto de cero \n");
			scanf("%d",&numeroIngresado);
		}

		if(contador==1)//DIRECTAMENTE USO AL CONTADOR COMO BANDERA
		{
			//banderaMenorNum=1; NO USAR
			menorNumIngresado=numeroIngresado;
		}
		else
		{
			if(numeroIngresado<menorNumIngresado)
			{
				menorNumIngresado=numeroIngresado;
			}
		}
		if(numeroIngresado%2==0 && banderaMayorNumPar==0)
		{
			banderaMayorNumPar=1;
			mayorNumPar=numeroIngresado;
		}
		else
		{
			if(numeroIngresado%2==0 && numeroIngresado>mayorNumPar)
			{
				mayorNumPar=numeroIngresado;
			}
		}
		if(numeroIngresado<0)
		{
			acumuladorProductoNegativos=acumuladorProductoNegativos*numeroIngresado;
		}

		if(contador==1)
		{
			mayorNum=numeroIngresado;
			posicionDeIngresoNumMayor=contador;
		}
		else
		{
			if(numeroIngresado>mayorNum)
			{
				mayorNum=numeroIngresado;
				posicionDeIngresoNumMayor=contador;
			}
		}
	}
	printf("El menor numero ingresado es: %d \n",menorNumIngresado);
	printf("El mayor numero par ingresado es: %d \n",mayorNumPar);
	printf("El producto de los negativos es: %d\n",acumuladorProductoNegativos);
	printf("El mayor numero fue ingresado en %d lugar",posicionDeIngresoNumMayor);

	return EXIT_SUCCESS;
}
