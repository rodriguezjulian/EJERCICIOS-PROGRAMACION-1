/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : Julian Manuel Rodriguez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	float numeroA;
	float numeroB;
	float numeroC;

	printf("Ingrese un numero\n");
	scanf("%f",&numeroA);
	printf("Ingrese un numero\n");
	scanf("%f",&numeroB);
	printf("Ingrese un numero\n");
	scanf("%f",&numeroC);

	if(numeroA!=numeroB && numeroA!=numeroC && numeroB!=numeroC)
	{
		if((numeroA>numeroB && numeroA<numeroC)|| (numeroA<numeroB && numeroA>numeroC))
		{
			printf("De los 3 numeros ingresados, el del medio es %.2f",numeroA);
		}
		else
		{
			if((numeroB>numeroA && numeroB<numeroC) || (numeroB<numeroA && numeroB>numeroC))
			{
				printf("De los 3 numeros ingresados, el del medio es %.2f",numeroB);
			}
			else
			{
				printf("De los 3 numeros ingresados, el del medio es %.2f",numeroC);
			}
		}
	}
	else
	{
		printf("No existe numero del medio");
	}

	return EXIT_SUCCESS;
}
