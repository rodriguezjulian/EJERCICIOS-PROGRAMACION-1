/*
 ============================================================================
 Name        : EJECICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 7-2
int ingresarTelefonoDos(char* resultado);
int esNumerica(char* cadena);
int validarAlfanumerico(char* array);
int ingresarArrayCaracteres(char*array,char* mensaje,char* mensajeError,int longitud);

int main(void) {
	setbuf(stdout,NULL);

   char numeroTelefonico[10];
   char alfaNumerico[5];
   ingresarArrayCaracteres(alfaNumerico,"Ingrese 4 caracteres alfanumericos","Error, escribiste de mas",5);
   if(validarAlfanumerico(alfaNumerico)==-1)
   {
	   printf("NO es alfanumerico\n");
   }
   else
   {
	   printf("Es alfanumerico\n");
   }
   //ingresarTelefonoDos(numeroTelefonico);

	return EXIT_SUCCESS;
}
int validarAlfanumerico(char* array)
{
	int controlIsDigit=0;
	int controlIsAlpha=0;
	int retorno=-1;
	if(array!=NULL)
	{
		for(int i=0;i<strlen(array);i++)
		{
			if(isdigit(array[i])!=0)
			{
				controlIsDigit=controlIsDigit+1;
			}
			if(isalpha(array[i])!=0)
			{
				controlIsAlpha=controlIsAlpha+1;
			}
			if((controlIsDigit+controlIsAlpha)==strlen(array) && controlIsDigit>0 && controlIsAlpha>0)
			{
				retorno=0;
			}
		}
	}

	return retorno;
}
int ingresarTelefonoDos(char* resultado)
{
	int retorno=-1;
	char auxiliar[8];
	int longitud;
	int verificacionDeCaracter;

	if(resultado!=NULL)
	{
		while(retorno==-1)
		{
			printf("Ingrese numero telefonico ");
			fflush(stdin);
			scanf("%s",auxiliar);

			longitud=strlen(auxiliar);
			verificacionDeCaracter=esNumerica(auxiliar);

			//printf("ES NUMERICA %d\n",verificacionDeCaracter);
			if(longitud==8 && verificacionDeCaracter==0)
			{
				strcpy(resultado, auxiliar);
				retorno=0;
			}
			else
			{
				printf("ERROR, ingrese 8 numeros\n");
			}
		}
		for(int i=0;i<4;i++)
		{
			printf("%c",resultado[i]);
		}
		printf("-");
		for(int i=4;i<8;i++)
		{

			printf("%c",resultado[i]);
		}

	}
	return retorno;
}
int esNumerica(char* cadena)
{
	int retorno=0;
	if(cadena!=NULL)
	{
		for(int i=0;cadena[i]!='\0';i++)
		{
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno=-1;
				break;
			}
		}
	}

	return retorno;
}
int ingresarArrayCaracteres(char*array,char* mensaje,char* mensajeError,int longitud)
{
	char textoIngresado[longitud];
	int retorno=-1;
	if(array!=NULL && mensaje!=NULL && mensajeError!=NULL && longitud>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",textoIngresado);
		strcpy(array,textoIngresado);
		while(strlen(textoIngresado)>=longitud)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%s",textoIngresado);
			strcpy(array,textoIngresado);
		}
		retorno=0;
	}
	return retorno;
}


/*int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	//scanf("%s",buffer);
	//fgets(stdin,longitud,cadena);

	return 0;
}*/
/*
   int imprimirArrayInt(int* array,int tam, char* mensaje)
{
	int retorno=-1;
	if(array!=NULL && tam>0)
	{
		printf("%s",mensaje);
		for(int i=0;i<tam;i++)
		{
			printf("%d | ",array[i]);
			retorno=0;
		}
		printf("\n");
	}
	return retorno;
}
 */


void IngresarTelefono(int* resultado )
{
	int auxiliar[8];
	int retornoScanf;
	if(resultado!=NULL)
	{
		printf("Ingrese numero telefonico, numero por numero");

		for(int i=0;i<8;i++)
		{
			retornoScanf=scanf("%d",&auxiliar[i]);
			if(retornoScanf==1)
			{
				resultado[i]=auxiliar[i];
			}
			else
			{
				printf("ERROR, Digite un numero");
			}
		}
		printf("El numero de telefono ingresado es:");
		for(int i=0;i<8;i++)
		{
			printf("%d",resultado[i]);

		}
	}

}


