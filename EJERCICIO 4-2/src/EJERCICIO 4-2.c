/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 4-2
#include <stdio.h>
#include <stdlib.h>

int sumarConPuntero(int numeroUno, int numeroDos, int *resultado);

int main(void) {
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	int retorno;
	int resultado;

	numeroUno=10;
	numeroDos=20;

	retorno=sumarConPuntero(numeroUno, numeroDos,&resultado);

	printf("RESULTADO: %d\n",resultado);
	printf("RETORNO 0 SI SALIO TODO BIEN Y -1 SINO: %d\n", retorno);

	return EXIT_SUCCESS;//0 ES FALSO
}
int sumarConPuntero(int numeroUno, int numeroDos, int *resultado)
{
	int retorno=-1;//SALIO TODO MAL
	if(resultado!=NULL)
	{
		*resultado=numeroUno+numeroDos;
		retorno=0;//SALIO TODO BIEN
	}
	return retorno;
}
