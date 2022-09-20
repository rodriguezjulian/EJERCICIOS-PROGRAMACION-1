/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 6-1
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"

int main(void) {
	setbuf(stdout,NULL);

	int numeroA;
	int numeroB;
	int auxiliar;

	numeroA=ingresarInt();
	numeroB=ingresarInt();

	printf("Numero A= %d || Numero B= %d\n",numeroA,numeroB);

	auxiliar=numeroA;
	numeroA=numeroB;
	numeroB=auxiliar;

	printf("INTERCAMBIO EFECTUADO / Numero A= %d || Numero B= %d\n",numeroA,numeroB);

	return EXIT_SUCCESS;
}
