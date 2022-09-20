/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J DESAFIO
#include <stdio.h>
#include <stdlib.h>
int Menu (void);

int main(void) {
	setbuf(stdout,NULL);
	//int opcion;
	int banderaOpcion1;
	int banderaOpcion2;
	char respuesta;


	banderaOpcion1=0;
	banderaOpcion2=0;



	do{
			switch(Menu())
			{
			case 1:
				printf("USTED A INICIADO CORRECTAMENTE\n");
				banderaOpcion1=1;
			break;
			case 2:
				if(banderaOpcion1==0)
				{
					printf("Debe Iniciar antes de Procesar\n");
				}
			else
				{
					banderaOpcion2=1;
					printf("SE PROCESO CORRECTAMENTE\n");
				}
				break;
				case 3:
					if( banderaOpcion1==0)
					{
						printf("Debe Iniciar antes de Finalizar\n");
					}
					else
					{
						if(banderaOpcion2==0)
						{
							printf("Debe Procesar antes de Finalizar\n");
						}
						else
						{
							printf("SE FINALIZO CORRECTAMENTE\n");
							banderaOpcion1=0;
							banderaOpcion2=0;
						}
					}
				break;
				case 4:
						printf("esta seguro que desea salir?s\n");
						fflush(stdin);
						scanf("%c",&respuesta);
				break;
			}

	 	 }while(respuesta!='s');

	return EXIT_SUCCESS;
}
int Menu (void)
{
	int opcion;
	printf("Marque opcion \n"
			"1 INICIAR \n"
			"2 PROCESAR \n"
			"3 FINALIZAR \n"
			"4 SALIR\n");
	scanf("%d",&opcion);
	return opcion;
}
