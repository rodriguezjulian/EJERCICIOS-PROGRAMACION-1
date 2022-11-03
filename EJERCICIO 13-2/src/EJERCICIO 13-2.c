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

int insertarNumero(int* arrayInt,int tam, int posicion, int intinsertar);

int main(void) {
	setbuf(stdout,NULL);

	int* arrayInt;
	arrayInt = (int*)malloc(sizeof(int)*5);
	if(arrayInt!=NULL)
	{
		for(int i=0;i<5;i++)
		{
			(*(arrayInt+i))=i;
			printf("%d |",(*(arrayInt+i)));
		}
		printf("\n");
		if(insertarNumero (arrayInt, 5,  3, 9)==0)
		{
			for(int i=0;i<6;i++)
			{
				printf("%d |",(*(arrayInt+i)));
			}

		}else
		{
			printf("ALGO SALIO MAL");
		}

	}
	return EXIT_SUCCESS;
}
int insertarNumero (int* arrayInt,int tam, int posicion, int intinsertar)
{
	int*aux;
	int retorno=-1;
	if(arrayInt!=NULL)
	{
		//vaux = (int*)realloc(vec,sizeof(int)*10); //AGRANDAR SU TAMAÑO DINAMICAMENTE
		aux=(int*)realloc(arrayInt,sizeof(int)*(tam+1));
		if(aux!=NULL)
		{
			for(int i=0;i<tam+1;i++)
			{
				if(i==posicion)
				{
					(*(aux+i+1))=(*(arrayInt+i));
					(*(aux+i))=intinsertar;
				}
				else
				{

					(*(aux+i))=(*(arrayInt+i));
				}
				retorno=0;
			}
		}
		arrayInt=aux;
	}
	//free(aux);
	return retorno;
}

