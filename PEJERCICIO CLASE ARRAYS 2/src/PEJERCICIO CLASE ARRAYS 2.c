/*
 ============================================================================
 Name        : PEJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int main(void) {
	setbuf(stdout,NULL);

	int notas[TAM];
	int i;
	int legajo;

	for(i=0;i<5;i++)
	{
		notas[i]=0;
	}
	printf("Ingrese legajo a completar");
	scanf("%d",&legajo);


	return EXIT_SUCCESS;
}
