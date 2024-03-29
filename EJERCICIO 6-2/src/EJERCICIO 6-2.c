/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 6-2
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "ingresos.h"
#define TAM 10

int main(void) {
	setbuf(stdout,NULL);

	int numerosIngresados[TAM];
	int numerosNegativos[TAM];
	int numerosPositvos[TAM];

	inicializarArray(numerosNegativos,TAM);
	inicializarArray(numerosPositvos,TAM);

	for(int i=0;i<TAM;i++)
	{
		ingresarInt2(&numerosIngresados[i]);

		if(numerosIngresados[i]<0)
		{
			numerosNegativos[i]=numerosIngresados[i];
		}
		else
		{
			numerosPositvos[i]=numerosIngresados[i];
		}

	}

	imprimirArrayInt(numerosIngresados,TAM, "Numeros ingresados \n");

	//ORDENOS LOS ARRAY NEGATIVO Y POSITIVO
	ordenarArrayDescendente(numerosNegativos,TAM);
	ordenarArrayAscendente(numerosPositvos,TAM);

	/*TENGO QUE IMPRIMIR SIN CERO PORQUE SINO LAS POSICIONES QUE QUEDARON VACIAS
	LAS IMPRIMO COMO 0 (PORQUE HABIA INICIALIZADO A LOS ARRAY)*/

	imprimirArrayIntSinCero(numerosNegativos,TAM, "ORDENADOS NEGATIVOS \n");
	imprimirArrayIntSinCero(numerosPositvos,TAM, "ORDENADOS POSITIVOS \n");

	return EXIT_SUCCESS;
}

