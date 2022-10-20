/*
 * validaciones.c
 *
 *  Created on: 20 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "transporte.h"

int verificarCaracterSN(char letra)
{
	int retorno=-1;

	if(letra=='S' || letra=='N')
	{
		retorno=0;
	}

	return retorno;
}

//CON ESTA FUNCION BUSCA EVITAR MOSTRAR UN MENU VACIO EN CASO DE QUE EL USUARIO LISTE UN TIPO DE TRANSPORTE QUE AUN NO HAYA SIDO INGRESADO
int verificarExistenciaDeTipoDeTransporte(eTransporte* transporte, int tipoBuscado, int tam)
{
	int retorno=-1;

	for(int i=0;i<tam;i++)
	{
		if((*(transporte+i)).tipoId==tipoBuscado)
		{
			retorno=0;
		}
	}
	if(retorno==-1)
	{
		printf("NO EXISTEN TRANSPORTES DE ESE TIPO CARGADOS AUN\n");
	}
	return retorno;
}

