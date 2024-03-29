/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 5-4
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "calculos.h"

#define TAM 10
#define MIN -100
#define MAX 100
#define REINTENTOS 3


int main(void) {
	setbuf(stdout,NULL);

	int numerosIngresados[TAM];
	int contadorNegativos;
	int sumatoriaDeImpares;
	int mayorPar;
	int retornoMayorPar;


	//INICIALIZO POR SI EL USUARIO SE QUEDA SIN REINTENTOS, EN ESTE CASO LA POSICION QUEDARIA EN 0
	inicializarArray(numerosIngresados,TAM);
	//CARGA DE DATOS
	for(int i=0;i<TAM;i++)
	{
		ingresarNumerosConRango(&numerosIngresados[i],"Ingrese un numero comprendido en el rango ", "Error, debe respetar el rango\n", MIN, MAX, REINTENTOS);
	}

	for(int i=0;i<TAM;i++)
	{
		//PUNTO A
		contadorNegativos=contarNegativosArray(numerosIngresados,TAM);
		//PUNTO B
		sumatoriaDeImpares=sumarImparesDeArray(numerosIngresados,TAM);
		//PUNTO C
		retornoMayorPar=calcularMaximoArrayPar(numerosIngresados,&mayorPar);

	}
	printf("\nSE INGRESARON %d NUMEROS NEGATIVOS\n",contadorNegativos );
	printf("LA SUMA DE LOS NUMEROS IMPARES INGRESADOS ES %d \n",sumatoriaDeImpares);
	if(retornoMayorPar==0)
	{
		printf("EL MAYOR DE LOS PARES ES %d \n",mayorPar);
	}
	else
	{
		printf("NO SE PUDO CALCULAR EL MAYOR DE LOS PARES \n");
	}

	imprimirArrayInt(numerosIngresados, TAM, "Los numeros ingresados son \n");
	imprimirArrayIntConMinimo(numerosIngresados,TAM,"Listado de numeros mayores a 15:\n", 15);
	imprimirIntEnPosicionImpar( numerosIngresados, TAM, "Listado de numeros en posiciones impares: ");

	return EXIT_SUCCESS;
}


