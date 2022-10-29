/*
 * confederaciones.c
 *
 *  Created on: 27 oct. 2022
 *      Author: Julian Rodriguez
 */


#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "jugadores.h"

#include "confederaciones.h"


int listarConfederaciones(eConfederacion* confederaciones)
{
	int retorno=-1;

	if(confederaciones!=NULL)
	{
		retorno=0;

		 printf("+============================================================================================================================+\n");
		 printf("| %*s|%*s|%*s|%*s|\n",-4,"ID",-50,"                     NOMBRE",-50,"                     REGION",-16," ANIO CREACION");
		 printf("+============================================================================================================================+\n");

		 for(int i=0;i<6;i++)
		 {
			 printf("| %*d|%*s|%*s|%*d|\n",-4,(*(confederaciones+i)).id,-50,(*(confederaciones+i)).nombre,-50,(*(confederaciones+i)).region,-16,(*(confederaciones+i)).anioCreacion);
		 }
		 printf("+============================================================================================================================+\n");
	}

		return retorno;
}