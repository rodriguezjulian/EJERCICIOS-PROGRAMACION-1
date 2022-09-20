/*
 * ingresos.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */
#include "ingresos.h"

float ingresarFloat(void)
{
	float numeroIngresado;
	printf("Ingrese numero\n");
	scanf("%f",&numeroIngresado);

	return numeroIngresado;
}
int ingresarInt(void)
{
	int numeroIngresado;
	printf("Ingrese numero\n");
	scanf("%d",&numeroIngresado);

	return numeroIngresado;

}
