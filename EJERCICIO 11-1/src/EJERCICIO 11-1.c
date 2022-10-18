/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 11-1
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int reemplazarChar(char* string,char busqueda,char reemplazo);

int main(void) {
	setbuf(stdout,NULL);

	char cadena[7]={'j','u','l','i','a','n'};

	printf("Cantidad de reemplazos: %d",reemplazarChar(cadena,'a','o'));

	return EXIT_SUCCESS;
}
int reemplazarChar(char* string,char busqueda,char reemplazo)
{
	int retorno=-1;
	int contador=0;
	if(string!=NULL && strlen(string)>0)
	{

		for(int i=0;i<strlen(string);i++)
		{

			if(*string==busqueda)
			{
				printf("BUENASS");
				*string=reemplazo;
				contador=contador+1;
				retorno=contador;
			}
		}
	}
	return retorno;
}
