/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 5-5
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "calculos.h"
#define TAM 10
#define REINTENTOS 3
#define MAX 75
#define MIN -50



int main(void) {
	setbuf(stdout,NULL);

	int numerosIngresados[TAM];
	int posicion;
	float promedio;
	int validacion;
	int contadorPositivos;
	int valorMinimo;
	inicializarArray(numerosIngresados,TAM);
	for(int i=0;i<TAM;i++)
	{
		do
		{
			printf("Ingrese indice posicion en donde cargara al numero");
			scanf("%d",&posicion);

			if(posicion>-1 && posicion<TAM)
			{
				validacion=0;
				ingresarNumerosConRangoMenosCero(&numerosIngresados[posicion],"INGRESE NUMERO ENTERO ENTRE -50 Y 75, A EXEPCION DEL 0\n","ERROR, RESPETE EL RANGO Y CONDICION\n", MIN,MAX, REINTENTOS);
			}
			else
			{
				printf("ERROR, cargue una posicion valida\n");
				validacion=-1;
			}
		}while(validacion==-1);
	}
	//MUESTRO NUMERO INGRESADOS
	imprimirArrayInt(numerosIngresados,TAM,"Numero ingresados:");
	//CUENTOS LOS POSITIVOS PARA AYUDARME A SACAR EL PROMEDIO DE LOS MISMOS
	contadorPositivos=contarPositivosArray(numerosIngresados,TAM);
	calcularPromedioPositivosArray(TAM, numerosIngresados, &promedio,contadorPositivos);
	//SACAR EL MAXIMO NEGATIVO
	calcularMinimoArray(numerosIngresados, &valorMinimo,TAM);
	printf("El maximo negativo es: %d\n",valorMinimo);

	printf("El promedio de los numeros positivos ingresados es: %.2f\n", promedio);
	return EXIT_SUCCESS;
}
