//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 8-1 | 8-2 | 8-3 | 8-4 | 8-5 | 8-6
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include<string.h>
#include <ctype.h>
#include "calculos.h"
#define TAM 4

void ejecutarMenuprincipal(char respuesta, char* opcion);
//int ingresarArrayCodigo(char array[][4],char* mensaje,char* mensajeError,int longitud);
//int ordenarCodigoAscendente(char array[][5], int tam);
int main(void) {
	setbuf(stdout,NULL);

	char codigo[TAM][5];
	char auxiliar[TAM][5];
	char modelo[TAM][11];
	int cantidad[TAM];
	float precio[TAM];
	char opcion;
	int i=0;
	int posicion;
	int auxCantidad;

	char respuesta='S';
	do
	{
		ejecutarMenuprincipal(respuesta, &opcion);
		switch(opcion)
		{
			case'A':
				printf("Carga de productos\n");
				for(i=0;i<TAM;i++)
				{
					do
					{
						ingresarArrayCaracteres(codigo[i],"Ingrese codigo alfanumerico de 4 caracteres","ERROR,cargue codigo valido\n",5);
						if(validarAlfanumerico(codigo[i])==-1 || strlen(codigo[i])!=4)
							{
								printf("ERROR,cargue codigo valido\n");
							}
					}while(validarAlfanumerico(codigo[i])==-1 || strlen(codigo[i])!=4);//

					ingresarArrayCaracteres(modelo[i],"Ingrese modelo","ERROR,cargue modelo valido\n",11);
					ingresarIntConMinimo(&cantidad[i], "Ingrese cantidad","ERROR, ingrese cantidad valida",1);
					ingresarFloatConMinimo(&precio[i], "Ingrese precio","ERROR, ingrese precio valido",0);
				}

			break;
			case 'B':
				if(i>0)
				{
					printf("Venta de productos\n");
						printf(" Listado | Codigo |        Modelo       | Cantidad | precio \n");
					for(int j=0;j<TAM;j++)
					{
						printf("   %d   |    %s   |%s                   |    %d    | %.2f\n",i,codigo[j],modelo[j],cantidad[j],precio[j]);
					}
				}
				else
				{
					printf("Para poder vender primero hay que cargar productos\n");
				}

				printf("Ingrese pocision de producto a  vender");
				scanf("%d",&posicion);
				printf("Ingrese cantidad de producto a  vender");
				scanf("%d",&auxCantidad);

				cantidad[posicion]=cantidad[posicion]-auxCantidad;
				printf("NUEVA CANTIDAD= %d",cantidad[posicion]);
			break;
			case 'C':
				printf("Modificación del precio\n");
				if(i>0)
				{
					printf(" Listado | Codigo |        Modelo       | Cantidad | precio \n");
					for(int j=0;j<TAM;j++)
					{
						printf("   %d   |    %s   |%s                   |    %d    | %.2f\n",j,codigo[j],modelo[j],cantidad[j],precio[j]);
					}
					ingresarNumerosConRangoV1(&posicion, "Ingrese posicion de precio a modificar\n", "ERROR, ingrese posicion valida\n", 0, 19);
					ingresarFloatConMinimo(&precio[posicion], "Ingrese nuevo precio","ERROR, ingrese precio valido",0);//
				}
				else
				{
					printf("Para poder modificar precios primero hay que cargar productos\n");
				}


			break;
			case'D':
				printf("Modificar el modelo\n");
				if(i>0)
				{
					printf(" Listado | Codigo |        Modelo       | Cantidad | precio \n");
					for(int j=0;j<TAM;j++)
					{
						printf("   %d   |    %s   |%s                   |    %d    | %.2f\n",j,codigo[j],modelo[j],cantidad[j],precio[j]);
					}

					ingresarNumerosConRangoV1(&posicion, "Ingrese posicion de modelo a modificar\n", "ERROR, ingrese posicion valida\n", 0, 19);
					ingresarArrayCaracteres(modelo[posicion],"Ingrese nuvea denemonicacion para modelo","ERROR,cargue modelo valido\n",11);
				}
				else
				{
					printf("Para poder modificar modelos primero hay que cargar productos\n");
				}

			break;
			case 'E':

				if(i>0)
				{
					printf("Listar ordenado por código\n");
					for(i=0;i<TAM-1;i++)
							{
								for(int j=i+1;j<TAM;j++)
								{
									//strcmp(cadena1,cadena2)
									if(strcmp(codigo[i],codigo[j])>0)
									{
										//COMO SON CADENAS TENGO QUE USAR
										//strcpy(destino, origen)
										strcpy(auxiliar[i],codigo[i]);
										strcpy(codigo[i],codigo[j]);
										strcpy(codigo[j],auxiliar[i]);
									}
								}
							}
					printf(" Listado | Codigo |        Modelo       | Cantidad | precio \n");
					for(int j=0;j<TAM;j++)
					{
						printf("   %d   |    %s   |%s                   |    %d    | %.2f\n",j,codigo[j],modelo[j],cantidad[j],precio[j]);
					}

				}
				else
				{
					printf("Para poder lisar ordenado por codigo, primero hay que cargar los productos\n");
				}

			break;
			case 'F':
				if(i>0)
				{
					printf("Listar datos de los productos con menos de 3 unidades\n");//
					printf(" Listado | Codigo |        Modelo       | Cantidad | precio \n");
					for(int j=0;j<TAM;j++)
					{
						if(cantidad[j]<3)
						{
							printf("   %d   |    %s   |%s                   |    %d    | %.2f\n",j,codigo[j],modelo[j],cantidad[j],precio[j]);
						}
					}
				}
				else
				{
					printf("Para poder listar datos de los productos con menos de 3 unidades,\n primero debe cargarlos\n/");
				}

			break;
		}

		printf("Pulse 'S' para continuar operando");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);


	}while(respuesta=='S');

	return EXIT_SUCCESS;
}

void ejecutarMenuprincipal(char respuesta, char* opcion)
{
	char axuliar;
	if(respuesta=='S')
	{
		printf("Ingrese opcion que desea operar\n"
				"'A'Carga de productos\n"
				"'B' Venta de productos\n"
				"'C'Modificación del precio\n"
				"'D'Modificar el modelo\n"
				"'E'Listar ordenado por código\n"
				"'F'Listar datos de los productos con menos de 3 unidades\n");
		fflush(stdin);
		scanf("%c",&axuliar);
		axuliar=toupper(axuliar);
		*opcion=axuliar;
	}
}

/*
int ordenarCodigoAscendente(char array[][5], int tam)
{
	int retorno=-1;
	char auxiliar[tam][4];

	if(array!=NULL && tam>0)
	{
		retorno=0;
		for(int i=0;i<tam-1;i++)
		{
			for(int j=i+1;j<tam;j++)
			{
				//strcmp(cadena1,cadena2)
				if(strcmp(auxiliar[i],auxiliar[j])>0)
				{
					//COMO SON CADENAS TENGO QUE USAR
					//strcpy(destino, origen)
					strcpy(auxiliar[i],array[i]);
					strcpy(auxiliar[i],array[j]);
					strcpy(array[j],auxiliar[i]);
				}
				if(array[i]>array[j])
				{
					auxiliar=array[i];
					array[i]=array[j];
					array[j]=auxiliar;
				}
			}
		}
	}
	return retorno;
}

*/




