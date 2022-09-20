/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 3-5
#include <stdio.h>
#include <stdlib.h>
int pedirNumeroEntero();
int restar1(int numeroA, int NumeroB);
int restar2(void);
void restar3(int numeroA,int numeroB);
void restar4(void);

int main(void)
{
	setbuf(stdout,NULL);
	int numeroA;
	int numeroB;
	int restarA;
	int restarB;

	//RESTAR1
	numeroA=pedirNumeroEntero();
	numeroB=pedirNumeroEntero();
	restarA=restar1(numeroA, numeroB);
	printf("Restar 1= %d\n",restarA);


	//RESTAR2
	restarB=restar2();
	printf("Restar 2= %d\n",restarB);

	//RESTAR3
	restar3(numeroA,numeroB);

	//RESTAR4
	restar4();
	return EXIT_SUCCESS;
}
int pedirNumeroEntero()
{
	int numeroIngresado;
	printf("Ingrese numero entero ");
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}
int restar1(int numeroA, int NumeroB)
{
	int resultado;
	resultado=numeroA-NumeroB;
	return resultado;
}
int restar2(void)
{
	int resultado;
	int numeroA;
	int numeroB;
	numeroA=pedirNumeroEntero();
	numeroB	=pedirNumeroEntero();
	resultado=numeroA-numeroB;

	return resultado;
}
void restar3(int numeroA,int numeroB)
{
	int resultado;
	resultado=numeroA-numeroB;
	printf("Restar 3= %d\n",resultado);
}
void restar4(void)
{
	int numeroA;
	int numeroB;
	int resultado;
	numeroA=pedirNumeroEntero();
	numeroB=pedirNumeroEntero();
	resultado=numeroA-numeroB;
	printf("Restar 4= %d",resultado);
}
