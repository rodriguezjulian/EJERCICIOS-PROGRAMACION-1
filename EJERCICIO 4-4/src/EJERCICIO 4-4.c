/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 4-4
#include <stdio.h>
#include <stdlib.h>
int verificarMenu(int aVerificar,char mensaje[] ,char mensajeError[],int* resultado);
int main(void) {
	setbuf(stdout,NULL);

	char respuesta;
	int opcion;
	int vericacionDeLogueo;
	int verificacionDeCompra;
	int opcionVender;
	int aver;
	vericacionDeLogueo=0;
	verificacionDeCompra=0;

	do{
		do{
		printf("INGRESE OPCION\n"
				"1. Loguearse\n"
				"2. Comprar\n"
				"3. Ver mis compras\n"
				"4.Vender\n"
				"5.Salir\n");
		scanf("%d",&opcion);
		if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5)
		{
			printf("\nERROR, INGRESE OPCION VALIDA\n");
		}
		}while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5);


		switch(opcion)
		{
			case 1:
				vericacionDeLogueo=1;
			break;

			case 2:
				//int verificarMenu(int aVerificar,char mensaje[] ,char mensajeError[],int* resultado)
				 aver=verificarMenu(vericacionDeLogueo,"Compra validada \n","ERROR ANTES DE COMPRAR DEBE LOGUEARSE\n",&verificacionDeCompra);
				 printf("%d\n",aver);

				/*
				if(vericacionDeLogueo!=1)
				{
					printf("ERROR ANTES DE COMPRAR DEBE LOGUEARSE\n");

				}
				else
				{
					verificacionDeCompra=verificacionDeCompra+1;
				}*/
			break;

			case 3:
				if(vericacionDeLogueo!=1)
				{
					printf("ERROR ANTES DE VER MIS COMPRAS DEBE LOGUEARSE\n");
				}
				else
				{
					if(verificacionDeCompra!=1)
					{
						printf("ERROR ANTES DE VER MIS COMPRAS DEBE COMPRAR\n");
					}

				}
			break;

			case 4:
				if(vericacionDeLogueo!=1)
				{
					printf("ERROR ANTES DE VENDER DEBE LOGUEARSE\n");
				}
				do
				{
					printf("INGRESE OPCION\n"
							"1.Vender \n"
							"2.Hacer factura\n"
							"3.Volver atrás\n");
					scanf("%d",&opcionVender);
				}while(opcionVender!=1 && opcionVender!=2 && opcionVender!=3);

				switch(opcionVender)
				{
					case 1:
						if(verificacionDeCompra<1)
						{
							printf("ERROR ANTES DE VENDER DEBE COMPRAR\n");
						}
						else
						{
							//POR CADA COMPRA PUEDO VENDER UNA VEZ
							printf("Venta ingresada\n");
							verificacionDeCompra=verificacionDeCompra-1;
						}
					break;
					case 2:
					break;
					case 3:
					break;
				}

			break;

			case 5:
				if(vericacionDeLogueo!=1)
				{
					printf("ERROR ANTES DE SALIR DEBE LOGUEARSE\n");
				}
			break;

		}

		printf("Si desea seguir operando presione 's'\n");
		fflush(stdin);
		scanf("%c",&respuesta);

	}while(respuesta=='s');

	return EXIT_SUCCESS;
}

int verificarMenu(int aVerificar,char mensaje[] ,char mensajeError[],int* resultado)
{
	int retorno=-1;
	resultado=0;
	if(resultado!=NULL && aVerificar>0 && mensajeError!=NULL && mensaje!=NULL)
	{
		*resultado=*resultado+1;
		retorno=0;
		printf("\n %s ",mensaje);
	}
	else
	{
		printf("\n %s ",mensajeError);
	}
	return retorno;
}





