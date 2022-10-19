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
#include <ctype.h>
#include <string.h>
#define TAM 30
int utn_getCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError);
int buscarNegativoMayor(int* array, int tam, int* resultado);

int main(void) {
	setbuf(stdout,NULL);
	int resultado;
	char textoIngresado[TAM];
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
	utn_getCadenaCaracteres(TAM,textoIngresado,"Ingrese nombre","ERROR, Ingrese nombre valido");
	printf("%s",textoIngresado);

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
int utn_getCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    if(textoIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0)
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(textoIngresado);//GETS SE AGARRA EL BUFFER DEL TECLADO, CORTA EL REGISTRO CON EL ENTER

        if(strlen(textoIngresado)<=tam)
        {
        	retorno=0;
        }else
        {
        	printf("%s",mensajeError);
        }
    }
    return retorno;
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
