//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 11-3
#include <stdio.h>
#include <stdlib.h>

int buscarMax(int* arrayInt, int* numeroMaximo, int tam);

int main(void) {
	setbuf(stdout,NULL);
	int numeroMaximo;
	int arrayInt[10]={5,99,1,0,45,4,7,4,4,58};

	buscarMax(arrayInt, &numeroMaximo, 10);
	printf("El numero mayor es: %d",numeroMaximo);

	return EXIT_SUCCESS;
}
int buscarMax(int* arrayInt, int* numeroMaximo, int tam)
{
	int retorno=-1;
	int maxAuxiliar;
	int flag=0;

	if(arrayInt!=NULL)
	{
		retorno=0;
		for(int i=0;i<tam;i++)
		{
			if(flag==0)
			{
				flag=1;
				maxAuxiliar=(*(arrayInt+i));
			}
			else
			{
				if(maxAuxiliar<(*(arrayInt+i)))
				{
					maxAuxiliar=(*(arrayInt+i));
				}
			}
		}
	}

	*numeroMaximo=maxAuxiliar;

	return retorno;
}
