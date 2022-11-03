#include <stdio.h>
#include <stdlib.h>

int borrarOcurrencia(int *arrayInt, int tam, int busco);

int main(void) {
	setbuf(stdout,NULL);

 int*pArrayInt;
 pArrayInt=(int*)malloc(sizeof(int));
 	 if(pArrayInt!=NULL)
 	 {
 		for(int i=0;i<5;i++)
 		{
 			*(pArrayInt+i)=i+1;
 			printf("%d\n",*(pArrayInt+i));
 		}
 	 }
 	borrarOcurrencia(pArrayInt,  5,  3);
 	printf("-------------------------------------\n");
	for(int i=0;i<5;i++)
	{
		*(pArrayInt+i)=i+1;

		printf("%d\n",*(pArrayInt+i));
	}


	return EXIT_SUCCESS;
}
int borrarOcurrencia(int *arrayInt, int tam, int busco)
{
	int retorno=-1;
	int* aux;
	int posicion=0;

	if(arrayInt!=NULL)
	{
		//pido tamanio -1 porque voy a borrar la primer ocurrencia
		aux=(int*)realloc(arrayInt,sizeof(int)*(tam-1));
		//VALIDO EL ESPACIO DE REALLOC
		if(aux!=NULL)
		{
			retorno=0;
			for(int i=0;i<tam;i++)
			{
				printf("ENTRO \n");
				//CADA VEZ QUE EXISTA COINCIDENCIA SE DEBE ENTREAR AL IF
				if((*(arrayInt+i))!=busco)
				{
					printf("ENTRO %d\n",1);
					(*(aux+posicion))=(*(arrayInt+i));
					posicion++;
				}

			}
			arrayInt=aux;
			free(aux);
		}
	}
	return retorno;
}
