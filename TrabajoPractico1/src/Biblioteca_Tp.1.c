/*
 * Biblioteca_Tp.1.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "calculos.h"

int validarEntradaParaOpcion3(float hospedaje,float comida,float transporte,int contadorJugadores)
{
	int retorno=-1;
	if(hospedaje>0 && comida>0 && transporte>0 && contadorJugadores>0)
	{
		printf("\n<<<<<<<<<<Calculos realizados correctamente>>>>>>>>>>\n\n");
		retorno=0;
	}else
	{
		printf("\nERROR, Primero debe cargar TODOS los costos e ingresar jugadores\n\n");
	}
	return retorno;
}
void informarResultados(int flag, float promedioAfc,float promedioCaf,float promedioConcacaf,float promedioConmebol,
		float promedioUefa, float promedioOfc, float costoMantenimiento,float diferenciaCostoMantenimiento,
		float costoMantenimientoAumentado)
{
	if(flag==1)
	{
		printf("El promedio de AFC es %.2f \n",promedioAfc);
		printf("El promedio de CAF es %.2f \n",promedioCaf);
		printf("El promedio de CONCACAF es %.2f \n",promedioConcacaf);
		printf("El promedio de CONMEBOL es %.2f \n",promedioConmebol);
		printf("El promedio de UEFA es %.2f \n",promedioUefa);
		printf("El promedio de OFC es %.2f \n\n",promedioOfc);

		if(diferenciaCostoMantenimiento>0)
		{
			printf("El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f\n\n",costoMantenimiento,diferenciaCostoMantenimiento,costoMantenimientoAumentado);
		}
		else
		{
			printf("El costo de manteniento es %.2f \n\n",costoMantenimiento);
		}
	}
	else
	{
		printf("Debe operar las opciones 1,2 y 3 antes de informar resultados\n\n");
	}

}


void ejecutarCalculosPromedios(int contadorJugadores,int contadorAfc,float*promedioAfc, int contadorCaf,float* promedioCaf,
		int contadorConcacaf,float*promedioConcacaf,int contadorConmebol,float*promedioConmebol,int contadorUefa,
		float*promedioUefa,int contadorOfc,float*promedioOfc)
{
	if(promedioAfc!=NULL && promedioCaf!=NULL && promedioConcacaf!=NULL && promedioConmebol!=NULL && promedioUefa!=NULL && promedioOfc!=NULL)
	{
		*promedioAfc=calcularPromedio(contadorJugadores, contadorAfc);
		*promedioCaf=calcularPromedio(contadorJugadores, contadorCaf);
		*promedioConcacaf=calcularPromedio(contadorJugadores, contadorConcacaf);
		*promedioConmebol=calcularPromedio(contadorJugadores, contadorConmebol);
		*promedioUefa=calcularPromedio(contadorJugadores, contadorUefa);
		*promedioOfc=calcularPromedio(contadorJugadores, contadorOfc);
	}

}
void ejecutarSubMenuConfederaciones(int flag,int* contadorAfc,int* contadorCaf,int*contadorConcacaf, int* contadorConmebol,int* contadorUefa,
		int*contadorOfc,int* contadorJugadores)
{
	int opcionSubMenu;
	int numeroCamiseta;
	if(flag==0 && contadorAfc!=NULL && contadorCaf!=NULL && contadorConcacaf!=NULL && contadorConmebol!=NULL && contadorUefa!=NULL)
	{
		//CAMISETA SE PUEDE REPETIR PORQUE ES EL NUMERO DEL JUGADOR EN SU CLUB ESPECIFICO - VALIDAR 1/99
		ingresarNumerosConRangoV1(&numeroCamiseta, "Ingresar numero de camiseta (1/99)\n", "ERROR, Ingresar dato valido\n", 1, 99);

		ingresarNumerosConRangoV1(&opcionSubMenu,"Ingrese segun corresponda la conferedacion a la que pertenece el jugador\n"
						"1.AFC\n"
						"2.CAF\n"
						"3.CONCACAF\n"
						"4.CONMEBOL\n"
						"5.UEFA\n"
						"6.OFC\n","ERROR,Ingrese opcion valida\n",1,6);

		*contadorJugadores=*contadorJugadores+1;

		switch(opcionSubMenu)
		{
			case 1:
				*contadorAfc=*contadorAfc+1;
			break;
			case 2:
					*contadorCaf=*contadorCaf+1;
			break;
			case 3:
					*contadorConcacaf=*contadorConcacaf+1;

			break;
			case 4:
					*contadorConmebol=*contadorConmebol+1;
			break;
			case 5:
					*contadorUefa=*contadorUefa+1;
			break;
			case 6:
					*contadorOfc=*contadorOfc+1;
			break;
		}
	}
}
void mostrarMenuPrincipal(float hospedaje,float comida,float transporte,
		int contadorArqueros,int contadorDefensores,int contadorMediocampistas,int contadorDelanteros)
{
	printf(	"1. Ingreso de los costos de mantenimiento\n"
					"	Costo de hospedaje ->$%.2f\n"
					"	Costo de comida ->$%.2f\n "
					"	Costo de transporte ->$%.2f\n"
					"2.Carga de jugadores\n"
					"	Arqueros ->%d\n"
					"	Defensores ->%d\n"
					"	Mediocampistas ->%d \n"
					"	Delanteros ->%d\n"
					"3.Realizar todos los calculos\n"
					"4.Informar todos los resultados\n"
					"5.Salir\n",hospedaje,comida,transporte,contadorArqueros,contadorDefensores,contadorMediocampistas,contadorDelanteros);
}
void mostrarMensajeSalida(int opcion)
{
	if(opcion==5)
	{
		printf("\n<<<<<<<<<<SALIR>>>>>>>>>>\n");
	}
}

