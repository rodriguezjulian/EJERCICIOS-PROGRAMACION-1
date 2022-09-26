/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN DIV J EJERCICIO 6-3
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "ingresos.h"
#define TAM 3

int main(void) {
	setbuf(stdout,NULL);

	//LEGAJO=POSICION;
	int edad[15];
	float salario[15];
	int sexo[15];
	float promedioSalario;


	for(int i=0;i<TAM;i++)
	{
		ingresarNumerosConRangoV1(&edad[i], "Ingrese edad del empleado\n", "ERROR, Ingrese edad valida\n",18,75);

		ingresarFloatConMinimo(&salario[i], "Ingrese salario del empleado","ERROR, ingrese salario valido\n",0);


		ingresarNumerosConRangoV1(&sexo[i], "Ingrese sexo:\n 1.Masculino | 2.Femenino | 3.No binario \n", "ERROR, Ingrese sexo valido\n",1,3);
	}

	for(int i=0;i<TAM;i++)
	{
		if(sexo[i]==3)
		{
			printf("El empleado con legajo %d es no binario\n",i);
		}
	}

	calcularPromedioArrayFlotante(TAM,salario,&promedioSalario);
	printf("promedio salario= %.2f\n",promedioSalario);






	return EXIT_SUCCESS;
}

//int getString(char* resultado, char* mensaje, char* mensajeError, int max, int mina)



