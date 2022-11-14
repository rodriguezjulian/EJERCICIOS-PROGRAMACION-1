/*
 * salidas.c
 *
 *  Created on: 14 nov. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "Seleccion.h"
#include "Jugador.h"

void mostrarMenuPrincipal()
{
	printf("+==================================================+\n|%*s|\n%s",
			-50,"                MENU PRINCIPAL","+==================================================+\n");

	printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n%s\n",-50,"1.CARGA DE ARCHIVOS",
			-50,"2.ALTA DE JUGADOR",-51,"3.MODIFICACIÓN DE JUGADOR",-50,"4.BAJA DE JUGADOR",-50,"5.LISTADOS",
			-50,"6.CONVOCAR JUGADORES",-50,"7.ORDENAR Y LISTAR",-50,"8.GENERAR ARCHIVO BINARIO",-50,"9.CARGAR ARCHIVO BINARIO",
			-50,"10.GUARDAR ARCHIVOS .CSV",-50,"11.SALIR","+==================================================+\n");
}

int selec_imprimirSeleccion(LinkedList* pArrayListSeleccion, int index)
{
	int retorno=-1;
	int id;
	char pais[50];
	char confederacion[50];
	int convocados;
	Seleccion* seleccionAux;
	seleccionAux=ll_get(pArrayListSeleccion, index);

	if(pArrayListSeleccion!=NULL && index>-1)
	{

		if(selec_getId(seleccionAux, &id)==0 &&
		selec_getPais(seleccionAux, pais)==0 &&
		selec_getConfederacion(seleccionAux, confederacion)==0 &&
		selec_getConvocados(seleccionAux, &convocados)==0)
		{
			//printf("IMPRIMIR SELECCION ENTRO");
			printf("| %*d|%*s|%*s| %*d|\n",-3,id,-25,pais,-15,confederacion,-9,convocados);
		}
	}
	return retorno;
}
int jug_imprimirJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int referenciaDeUso)
{
	int retorno=-1;
	int id;
	char nombreCompleto[200];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;
	char descripcionSeleccion[30];
	int tam;
	//*referenciaDeUso=flagRefUno;
	/*
	 * referenciaDeUso==1 / SE MUESTRAN TODOS LOS JUGADORES.
	 * referenciaDeUso==2 / SE MUESTRAN LOS JUGADORES CONVODADOS.
	 * referenciaDeUso==3 / SE MUESTRAN LOS JUGADORES NO CONVOCADOS.
	 */
	Jugador* pJugAux;

	//index>-1 para mostrar el indice 0
	if(pArrayListJugador!=NULL)
	{
		tam=ll_len(pArrayListJugador);

		printf("+================================================================================================================================+\n");
				printf("|%*s|\n",-128,"                                                    JUGADORES ");
				printf("+================================================================================================================================+\n");
				printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n%s\n",-6,"  ID",-40,"         NOMBRE COMPLETO",-4,"EDAD",-25,"      POSICION",
						-18,"    NACIONALIDAD",-8,"ID SELEC.",-20,"PAIS QUE CONVOCA",
						"+================================================================================================================================+");

		for(int i=0;i<tam;i++)
		{
			pJugAux=ll_get(pArrayListJugador, i);
			if(jug_getId(pJugAux, &id)==0 &&
					jug_getNombreCompleto(pJugAux, nombreCompleto)==0 &&
					jug_getPosicion(pJugAux, posicion) == 0 &&
					jug_getNacionalidad(pJugAux, nacionalidad)== 0 &&
					jug_getEdad(pJugAux,&edad)== 0 &&
					jug_getSIdSeleccion(pJugAux, &idSeleccion)==0)
			{
				if(idSeleccion>0 && (referenciaDeUso==2 || referenciaDeUso==1))
				{
					retorno=0;
					//printf("ENTRE AL IF isSeleccion>0\n");
					selec_AsignarDescripcionPais(pArrayListSeleccion, pArrayListJugador, i, descripcionSeleccion);
					//printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|\n",-4,id,-40,nombreCompleto,-3,edad,-25,posicion,-18,nacionalidad,-5,idSeleccion,-20,descripcionSeleccion);
					printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n",
							-4,id,-40,nombreCompleto,-3,edad,-25,posicion,-18,nacionalidad,-5,idSeleccion,-20,descripcionSeleccion);
				}
				else
				{
					if(referenciaDeUso==3 || referenciaDeUso==1)
					{
						retorno=0;
						//printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|\n",-4,id,-40,nombreCompleto,-3,edad,-25,posicion,-18,nacionalidad,-5,idSeleccion);
						printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n",
									-4,id,-40,nombreCompleto,-3,edad,-25,posicion,-18,nacionalidad,-5,idSeleccion,-20,"NO CONVOCADO");
					}
				}
			}
		}
		printf("+================================================================================================================================+\n");
	}
	return retorno;
}
void jug_MostrarNacionalidades(void)
{

	printf("+====================+\n");
	printf("|%*s|\n+====================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n"
			"|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",-20,"   NACIONALIDADES"
			,-20,"1.Arabe.",-20,"2.Australiano.",-20,"3.Coreano.",-20,"4.Iranie.",-20,"5.Japones.",-20,"6.Qatari.",-20,"7.Camerunes.",-20,"8.Ghanes.",-20,"9.Marroqui.",-20,"10.Senagales"
			,-20,"11.Tunez",-20,"12.Canadiense.",-20,"13.Costarriquense.",-20,"14.Estadounidense.",-20,"15.Mexicano",-20,"16.Argentino.",-20,"17.Brasilero.",-20,"18.Ecuatoriano."
			,-20,"19.Uruguayo.",-20,"20.Aleman.",-20,"21.Belga.",-20,"22.Croata",-20,"23.Dinamarques.",-20,"24.Espaniol.",-20,"25.Frances.",-20,"26.Gales",-
			20,"27.Holandes.",-20,"28.Ingles.",-20,"29.Polaco."
			,-20,"30.Portugues.",-20,"31.Serbio.",-20,"32.Suizo.");
	printf("+====================+\n");
}
