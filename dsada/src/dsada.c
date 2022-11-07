#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char lastName[51];
	float salary;
	int sector;
}ePractica;

int ingresarChar(char* mensaje,char* mensajeError, char minimo, char maximo, char* resultado);
int main(void) {
	setbuf(stdout, NULL);
	char letraIngresada;
	ingresarChar("INGRESAR S", "NOOO",'s', 't', &letraIngresada);
	//

	return 0;
}


int ingresarChar(char* mensaje,char* mensajeError, char minimo, char maximo, char* resultado)
{
	int retorno=-1;
	char letraIngresada;
	if(mensaje!=NULL && mensajeError!=NULL && resultado!=NULL && minimo<maximo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(&letraIngresada);
			if(letraIngresada<minimo || letraIngresada>maximo)
			{
				printf("%s", mensajeError);
			}
			else
			{
				*resultado=letraIngresada;
				retorno=0;
			}
		}while(retorno==-1);
	}
	return retorno;
}

