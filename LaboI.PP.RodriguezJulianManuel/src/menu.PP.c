/*
 * menu.PP.c
 *
 *  Created on: 13 oct. 2022
 *      Author: Julian Rodriguez
 */
//#include "menu.PP.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrarOpciones(void)
{
	printf("+------------------------+\n");//
	printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",-24,"A.ALTA TRASPORTE",-24,"B.MODIFICAR TRANSPORTE",-24,
			"C.BAJA TRANSPORTE",-24,"D.LISTAR TRANSPORTES",-24,"E.LISTAR TIPOS",-24,"F.ALTA HOJA DE RUTA",-24,
			"G.LISTAR HOJAS DE RUTA",-24,"H.INFORMES",-24,"I.SALIR");
	printf("+------------------------+\n");

}
int ingresarOpcionAlfabeticaMayusc(char* resultado,char* mensaje,char* mensajeError, int minimo ,int maximo )
{
	int retorno=-1;
	char auxiliar;
	if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&auxiliar);
			auxiliar=toupper(auxiliar);

			if(auxiliar>minimo  &&  auxiliar<maximo)
			{
				*resultado=auxiliar;
				retorno=0;
			}else
			{
				printf(mensajeError);
			}
		}while(retorno==-1);
	}
	return retorno;
}



