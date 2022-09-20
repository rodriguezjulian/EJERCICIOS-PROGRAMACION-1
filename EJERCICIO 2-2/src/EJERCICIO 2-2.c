/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : RODRIGUEZ JULIAN MANUEL DIV J 2-2
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Ejercicio 2-2: Ingresar números enteros, hasta que el usuario pida. Mostrar:
a) El promedio de los positivos y su mínimo.
b) El promedio de los negativos y su máximo
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	char respuesta;
	int numeroIngresado;
	int acumuladorDePositivos;
	int acumuladorDeNegativos;
	int contadorNegativos;
	int contadorPositivos;
	int banderaNumMaximoNegativos;
	int banderaNumMinimoPositivos;
	int numMinimoPositivos;
	int numMaximoNegativos;
	float promedioPositivos;
	float promedioNegativos;

	acumuladorDePositivos=0;
	acumuladorDeNegativos=0;
	contadorNegativos=0;
	contadorPositivos=0;
	respuesta='s';
	banderaNumMaximoNegativos=0;
	banderaNumMinimoPositivos=0;

	while(respuesta=='s')
	{
		printf("Ingrese un numero entero \n");
		scanf("%d",&numeroIngresado);


		if(numeroIngresado>0)
		{
			contadorPositivos=contadorPositivos+1;
			acumuladorDePositivos=acumuladorDePositivos+numeroIngresado;

			if(banderaNumMinimoPositivos==0)
			{
				banderaNumMinimoPositivos=1;//podria haber ahorrado las variables de banderas utilizando contadores
				numMinimoPositivos=numeroIngresado;
			}
			else
			{
				if(numeroIngresado<numMinimoPositivos)
				{
					numMinimoPositivos=numeroIngresado;
				}
			}

		}
		else
		{
			contadorNegativos=contadorNegativos+1;
			acumuladorDeNegativos=acumuladorDeNegativos+numeroIngresado;

			if(banderaNumMaximoNegativos==0)
			{
				banderaNumMaximoNegativos=1;
				numMaximoNegativos=numeroIngresado;
			}
			else
			{
				if(numeroIngresado>numMaximoNegativos)
				{
					numMaximoNegativos=numeroIngresado;
				}
			}
		}

		printf("Desea ingresar mas numeros?S/N \n");
		fflush(stdin);
		scanf("%c",&respuesta);

	}

	promedioPositivos= (float)acumuladorDePositivos/contadorPositivos;
	promedioNegativos=(float)acumuladorDeNegativos/contadorNegativos;

	printf("El promedio de los positivos es: %.2f \n",promedioPositivos);
	printf("El minimo de los positivos es: %d \n",numMinimoPositivos);
	printf("El promedio de los negativos es: %.2f \n",promedioNegativos );
	printf("El maximo de los negativos es: %d \n",numMaximoNegativos);

	return EXIT_SUCCESS;
}
