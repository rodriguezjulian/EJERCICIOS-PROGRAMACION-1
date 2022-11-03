#include <stdio.h>
#include <stdlib.h>
//EN EL HEAP SE GUARDAN LAS VARIABLES DINAMICAS
//void* malloc(unsigned int numBytes);
//el *void es un tipo de dato comodin, es un NO TIPO DE DATO, que mas adelante castearemos
 //MALLOC VERIFICA QUE PUEDO RESERVAR ESPACIO EN MEMORIA DE UN TAMANIO DETERMINADO
 //antes de la palabra malloc realizo el casteo
 //inmediatamente despues de utilizar malloc hay que comprobar que sea distinto de NULL


//REALLOC NOS PERMITE REDIMENSIONAR UN ARRAY / LA CANTIDAD DE MEMORIA RESERVADA
//void* realloc(void* ptr, unsigned int numBytes);
//SIEMPRE QUE TRABAJEMOS CON REALLOC UTILIZAMOS VARIABLES AUXILIARES

//void free(void* ptr);
//libera el espacio reservado.

//#define TAM 5
int borrarOcurrencia(int *arrayInt, int tam, int busco);

int main(void) {
	setbuf(stdout,NULL);

	int tam=5;
	int array[5];
	int *pArrayInt=&array[5];
	pArrayInt=(int*)malloc(sizeof(int)*tam);
 	if(pArrayInt!=NULL)
 	{
 		for(int i=0;i<5;i++)
 		{
 			*(pArrayInt+i)=i+1;
 			printf("%d\n",*(pArrayInt+i));
 		}
 	 }
 	if(borrarOcurrencia(pArrayInt, tam ,3)==0)
 	{
		printf("-------------------------------------\n");
		for(int i=0;i<tam-1;i++)
		{
			printf("%d\n",*(pArrayInt+i));
		}
	}
	return EXIT_SUCCESS;
}
int borrarOcurrencia(int *arrayInt, int tam, int busco)
{
	int retorno=-1;
	int* pAux;

	int posicion=-1;

	if(arrayInt!=NULL)
	{
		if(arrayInt!=NULL)
		{
			for(int i=0;i<(tam);i++)
			{
				if(*(arrayInt+i)==busco)
				{
					posicion=i;
					//printf("POSICION: %d",posicion);
					break;
				}
			}
			if(posicion!=-1)
			{
				for(int j=posicion;j<(tam-1);j++)
				{
					*(arrayInt+j)=*(arrayInt+(j+1));
					retorno=0;
				}

				pAux = (int *) realloc (arrayInt , sizeof(int) * tam-1);
				if(pAux!=NULL)
				{
					arrayInt=pAux;
					retorno=0;
				}
			}
			else
			{
				printf("No se encontro la ocurrencia\n");
			}
		}
	}
	return retorno;
}
