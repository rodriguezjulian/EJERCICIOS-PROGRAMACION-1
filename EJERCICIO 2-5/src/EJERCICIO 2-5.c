/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : JULIAN MANUEL RODRIGUEZ DIV J EJERCICIO 2-5
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void imprimirMundo();//PROTOTIPO
int pedirNumero();//PROTOTIPO - SOLO PIDE NUMERO
void sumarImpreso(int num1, int num2);//ESTA MAL PORQUE CADA FUNCION TIENE QUE REALIZAR 1 TAREA EN ESPECIFICO Y EN ESTE CASO SUMARIA E IMPRIMIRIA
int sumarConRetorno(int num1, int num2);
int Restar1(int num1, int num2);

int main(void) {
	setbuf(stdout,NULL);
	int numero;
	int numeroDos;
	int resultado;

	imprimirMundo();
	numero= pedirNumero();
	numeroDos=pedirNumero();
	sumarImpreso(numero,numeroDos);
	resultado=sumarConRetorno(numero,numeroDos);
	printf("RESULTADO: %d",resultado);
	//printf("El numero ingresado es %d",numero);
	return EXIT_SUCCESS;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//999 +
void imprimirMundo()//DESARROLLO
{
	printf("Hola mundo \n");
}
int pedirNumero()
{
	int numero;
	printf("Pedir numero \n");
	scanf("%d",&numero);

	return numero;
}
void sumarImpreso(int num1, int num2)
{

	int resultado=num1+num2;
	printf("El resultado es: %d\n",resultado);
}
int sumarConRetorno(int num1, int num2)
{
	int total=num1+num2;
	return total;
}
int Restar1(int num1, int num2)
{
	int resta=num1-num2;
	return resta;
}
