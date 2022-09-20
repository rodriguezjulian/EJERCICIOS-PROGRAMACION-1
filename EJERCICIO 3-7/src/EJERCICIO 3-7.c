/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 3-7
#include <stdio.h>
#include <stdlib.h>
#define MIN 10
#define MAX 100

int pedirNumeroEntero();
//int validarEnteroConRangoPuntero(int numeroIngresado, int min, int max,*resultado);
int restar1(int numeroA, int NumeroB);
int sumar(int numeroA, int NumeroB);
int validarIntConRango(int numeroIngresado, int min, int max);

int main(void) {
	setbuf(stdout,NULL);

	int numero1;
	int numero2;
	char operacion;
	int validacion1;
	int validacion2;
	int resultado;

	do{
	//PIDO DATOS
	numero1=pedirNumeroEntero();
	numero2=pedirNumeroEntero();
	//VALIDO

	validacion1=validarIntConRango(numero1,MIN , MAX);
	validacion2=validarIntConRango(numero2,MIN , MAX);

	if(validacion1==0 || validacion2==0)
	{
		printf("ERROR, INGRESE NUMEROS RESPETANDO RANGOS ASIGNADOS\n");
	}
	}while(validacion1==0|| validacion2==0);

	do{
		printf("Si desea sumar ingrese 's', si desea restar ingrese 'r'\n");
		fflush(stdin);
		scanf("%c", &operacion);

	}while(operacion!='s' && operacion!='r');

	if(operacion=='s')
	{
		resultado=sumar(numero1,numero2);
		printf("El resultado es: %d", resultado);
	}
	else
	{
		resultado=restar1(numero1,numero2);
		printf("El resultado es: %d", resultado);
	}

	return EXIT_SUCCESS;
}
int pedirNumeroEntero()
{
	int numeroIngresado;
	printf("Ingrese numero entero ");
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}
int validarIntConRango(int numeroIngresado, int min, int max)
{
	int retorno;
	//SI SALIO TODO BIEN 1 SINO 0/
	if(numeroIngresado>=min && numeroIngresado<=max)
	{
		retorno=1;
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
int restar1(int numeroA, int NumeroB)
{
	int resultado;
	resultado=numeroA-NumeroB;
	return resultado;
}
int sumar(int numeroA, int NumeroB)
{
	int resultado;
	resultado=numeroA+NumeroB;
	return resultado;
}
