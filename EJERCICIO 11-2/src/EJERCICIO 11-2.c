/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int contiene(int* vectorUno, int* vectorDos, int tamVectorUno, int tamVectorDos);


int main(void) {
	setbuf(stdout,NULL);

	int vectorUno[5]={3,0,1,0,2};
	int vectorDos[3]={1,0,2};


	printf("%d",contiene(vectorUno,vectorDos, 5, 3));

	return EXIT_SUCCESS;
}
int contiene(int* vectorUno, int* vectorDos, int tamVectorUno, int tamVectorDos)
{
	int retorno=-1;
	int contador=0;
	if(vectorUno!=NULL && vectorDos!=NULL && tamVectorUno>0 && tamVectorDos>0 && tamVectorUno>tamVectorDos)
	{
		for(int i=0;i<tamVectorUno;i++)
		{

			for(int j=0;j<tamVectorDos;j++)
			{
				if(*(vectorUno+i)==*(vectorDos+j))
				{
					contador=contador+1;
					retorno=contador;
				}
			}
		}
	}

	return retorno;
}
