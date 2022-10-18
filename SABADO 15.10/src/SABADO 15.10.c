/*
 ============================================================================
 Name        : PRUEBA2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Funcion que busque el numero negativo mas grande de un array, y lo retorne, ademas que indique si lo pudo hallar o no.
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "ingresos.h"

int buscarNegativoMayor(int* array, int tam, int* resultado);

int main(void) {
	setbuf(stdout,NULL);
	int resultado;

	int array[10]={10,30,45,-10,-20,30,2,5,4000,20};

	//buscarNegativoMayor(array, 10, &resultado);
	if(buscarNegativoMayor(array, 10, &resultado)==0)
	{
		printf("El numero negativo mayor es %d ",resultado);
	}
	else
	{
		printf("No hay numeros negativos");
	}


	char hola=66;//ACA ESTOY HACIENDO REFERENCIA A LA 'B' de la tabla

	if(hola>64 && hola<90)
	{
		printf("entro");

	}
	else
	{
		printf("NOOOO ENTRO");
	}





	return EXIT_SUCCESS;
}






int buscarNegativoMayor(int* array, int tam, int* resultado)
{
	int retorno=-1;
	int numeroNegativoMayor;
	int flag=0;
	//numeroNegativoMayor=array[0];
	if(array!=NULL && tam>0 && resultado!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(array[i]<0 && flag==0)
			{
				flag=1;
				numeroNegativoMayor=array[i];
			}
			else
			{
				if(numeroNegativoMayor<array[i] && array[i]<0)
				{
					numeroNegativoMayor=array[i];

				}
			}

		}
		if(flag==1)
		{
			*resultado=numeroNegativoMayor;
			retorno=0;
		}
	}

	return retorno;
}
