/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN DIV J EJERCICIO 7-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void formarApellidoNombre(char* pNombre,char* pApellido,char* pCompleto);

int main(void){
	setbuf(stdout,NULL);

	char nombre[10];
	char apellido[10];
	char nombreCompleto[20];

	printf("Ingresar nombre");
	fflush(stdin);
	gets(nombre);

	printf("Ingresar apellido");
	fflush(stdin);
	gets(apellido);

	formarApellidoNombre(nombre,apellido,nombreCompleto);
	printf("Nombre completo: %s",nombreCompleto);

	return EXIT_SUCCESS;
}

void formarApellidoNombre(char* pNombre,char* pApellido,char* pCompleto)
{
	if(pNombre!=NULL && pApellido!=NULL && pCompleto!=NULL)
	{
		strcpy(pCompleto,pApellido);
		strcat(pCompleto,", ");
		strcat(pCompleto,pNombre);
	}
}

