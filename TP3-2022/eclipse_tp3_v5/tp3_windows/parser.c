#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	//id,nombreCompleto,edad,posicion,nacionalidad,idSelecion
	char texto[6][150];
	int cantidad;
	//POR BUENA PRACTICA LO INICIALIZO
	Jugador* jugadorAux=NULL;
	int retorno;
	//LECTURA FANTASMA
	if(pFile!=NULL && pArrayListJugador!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",(*(texto+0)),(*(texto+1)),(*(texto+2)),(*(texto+3)),(*(texto+4)),(*(texto+5)));
		if(pFile!=NULL)
		{
			while(!feof(pFile))
			{
				//fscanf(pFile,"%[^,],",(*(texto+0)));
				//USO AL RETORNO DE SCANF PARA VERIFICAR QUE ESTA TODO BIEN
				cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",(*(texto+0)),(*(texto+1)),(*(texto+2)),(*(texto+3)),(*(texto+4)),(*(texto+5)));
				//printf("%s---%s---%s---%s---%s---%s\n",(*(texto+0)),(*(texto+1)),(*(texto+2)),(*(texto+3)),(*(texto+4)),(*(texto+5)));
				if(cantidad>6)
				{
					jug_delete(jugadorAux);
					jugadorAux=NULL;
					retorno=-1;
					break;
				}
				else
				{
					jugadorAux=jug_newParametros((*(texto+0)), (*(texto+1)),(*(texto+2)),(*(texto+3)),(*(texto+4)),(*(texto+5)));
					if(jugadorAux!=NULL)
					{
						printf("%d---%s---%d---%s---%s---%d\n",jugadorAux->id,jugadorAux->nombreCompleto,jugadorAux->edad,jugadorAux->posicion,jugadorAux->nacionalidad,jugadorAux->idSeleccion);
						ll_add(pArrayListJugador,(Jugador*) jugadorAux);
						retorno=0;
					}

				}
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
    return 1;
}

