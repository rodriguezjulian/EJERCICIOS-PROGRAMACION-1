/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 2-6
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int contadorM;
	int i;
	char caracterIngresado;
	contadorM=0;
	for(i=0; i<5; i++)
	{
		printf("Ingrese caracter");
		fflush(stdin);
		scanf("%c",&caracterIngresado);
		if(caracterIngresado=='m')
		{
			contadorM=contadorM+1;
		}
	}
	printf("Se ingresaron %d letras 'm'",contadorM);
	return EXIT_SUCCESS;
}
