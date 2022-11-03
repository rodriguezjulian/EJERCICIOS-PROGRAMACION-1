//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 11-2
#include <stdio.h>
#include <stdlib.h>
int contiene(int* vectorUno, int* vectorDos, int tamVectorUno, int tamVectorDos);

int main(void) {
	setbuf(stdout,NULL);

	int vectorUno[3]={3,0,1};
	int vectorDos[3]={1,3,0};

	if(contiene(vectorUno,vectorDos, 5, 3)==0)
	{
		printf("El vector 2 esta incluido en el vector 1\n");
	}
	else
	{
		printf("El vector 2 NO esta incluido en el vector 1\n");
	}

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
				if((*(vectorUno+i))==(*(vectorDos+j)))
				{
					contador=contador+1;
					break;
				}
			}
		}
	}
	if(contador==tamVectorDos)
	{
		retorno=0;
	}
	return retorno;
}
