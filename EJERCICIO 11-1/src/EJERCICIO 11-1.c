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

	printf("ANTES DE EJECUTAR LA FUNCION %s\n",cadena);
	printf("Cantidad de reemplazos: %d\n",reemplazarChar(cadena,'a','o'));

	printf("Asi quedo la palabra:%s\n",cadena);

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

			if((*(string+i))==busqueda)
			{
				(*(string+i))=reemplazo;
				contador=contador+1;
				retorno=contador;
			}
		}
	}
	return retorno;
}
