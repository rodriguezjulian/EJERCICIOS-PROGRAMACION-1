/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 4-3
#include <stdio.h>
#include <stdlib.h>
#include "VALIDACIONES.h"
#include "ingresos.h"
#include "conversiones.h"

#define MINIMOCELCIUS 0
#define MINIMOFAHRENHEIT 32
#define MAXCELCIUS 100
#define MAXFAHRENHEIT 212

int main(void) {
	setbuf(stdout,NULL);

	float temperaturaIngresada;
	char unidad;
	char respuesta;
	int retornoRangos;
	int retornoConversiones;
	float resultado;

	do
	{
		do{
		printf("Si desea cargar una temperatura en Celcius pulse 'c', o para Fahrenheit pulse 'f'\n");
		fflush(stdin);
		scanf("%c",&unidad);

		if(unidad!='c' && unidad!='f')
		{
			printf("ERROR, Ingrese un caracter valido\n");
		}

		}while(unidad!='c'&& unidad!='f');

		temperaturaIngresada=ingresarFloat();

		if(unidad=='c')
		{
			retornoRangos=validarFloatConRango(temperaturaIngresada,MINIMOCELCIUS , MAXCELCIUS);
			if(retornoRangos==0)
			{
				//funcion de celcius a farenheit
				retornoConversiones=convertirAFarenheit(temperaturaIngresada, &resultado);
				if(retornoConversiones==0)
				{
					printf("%.2f grados celcius equivalen a %.2f grados farenheit\n",temperaturaIngresada,resultado);
				}
			}
			else
				{
					printf("ERROR,cargue temperatura teniendo en cuenta los rangos minimos y maximos\n");
				}
		}
		else
		{
				retornoRangos=validarFloatConRango(temperaturaIngresada,MINIMOFAHRENHEIT , MAXFAHRENHEIT);
				if(retornoRangos==0)
				{
					retornoConversiones=convertirACelcius(temperaturaIngresada, &resultado);
					if(retornoConversiones==0)
					{
						printf("%.2f grados farenheit equivalen a %.2f grados celcius \n ",temperaturaIngresada,resultado);
					}
				}
				else
				{
					printf("ERROR,cargue temperatura teniendo en cuenta los rangos minimos y maximos\n");
				}
		}

		printf("Si desea cargar otra temperatura presione 's'\n");
		fflush(stdin);
		scanf("%c",&respuesta);


	}while(respuesta=='s');

	return EXIT_SUCCESS;
}
