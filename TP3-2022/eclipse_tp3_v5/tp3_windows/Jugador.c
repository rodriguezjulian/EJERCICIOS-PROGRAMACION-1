#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include<string.h>

Jugador* jug_new()
{
	Jugador* pJugador;
	//RESERVO ESPACIO DE MEMORIA E INICIALIZO LOS CAMPOS
	//EL 1 EN CALLOC ES EL NUMERO DE ELEMENTOS
	pJugador=(Jugador*)calloc(1,sizeof(Jugador)*1);
	return pJugador;
}

void jug_delete(Jugador* this)
{
	free(this);

}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* pJugador;
	//RESERVO EL ESPACIO DE MEMORIA
	pJugador=jug_new();
	if(pJugador!=NULL)
	{
		//CASTEO A INT LO QUE HACE FALTA
		if(jug_setId(pJugador,atoi(idStr))!=0 ||
		jug_setNombreCompleto(pJugador, nombreCompletoStr)!=0 ||
		jug_setPosicion(pJugador, posicionStr)!=0 ||
		jug_setNacionalidad(pJugador, nacionalidadStr)!=0 ||
		jug_setEdad(pJugador, atoi(edadStr))!=0 ||
		jug_setIdSeleccion(pJugador, atoi(idSelccionStr)!=0))
		{
			jug_delete(pJugador);
			pJugador=NULL;
		}
	}
	return pJugador;
}
int jug_setId(Jugador* this,int id)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->id=id;
		retorno=0;
	}

	return retorno;
}
int jug_getId(Jugador* this,int* id)
{
	int retorno=-1;
	if(this!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		strcpy(this->nombreCompleto,nombreCompleto);
	}

	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		strcpy(nombreCompleto,this->nombreCompleto);
	}
	return retorno;
}
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		strcpy(this->posicion,posicion);
	}
	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		strcpy(posicion,this->posicion);
	}
	return retorno;
}
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL)
	{

		strcpy(this->nacionalidad,nacionalidad);
		retorno=0;
	}
	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL)
	{

		strcpy(nacionalidad,this->nacionalidad);
		retorno=0;
	}
	return retorno;
}
int jug_setEdad(Jugador* this,int edad)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		this->edad=edad;
	}
	return retorno;

}
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		*edad=this->edad;
	}
	return retorno;
}
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		this->idSeleccion=idSeleccion;
	}
	return retorno;

}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		*idSeleccion=this->idSeleccion;
	}
	return retorno;
}
int imprimirJugador(LinkedList* pArrayListJugador, int index)
{
	int retorno=-1;
	int id;
	char nombreCompleto[200];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;
	Jugador* pJugAux;
	pJugAux=ll_get(pArrayListJugador, index);

	//index>-1 para mostrar el indice 0
	if(pArrayListJugador!=NULL && index>-1)
	{
		//DEBERIA VALIDAD A pJugAux!=NULL?
		if(jug_getId(pJugAux, &id)==0 &&
				jug_getNombreCompleto(pJugAux, nombreCompleto)==0 &&
				jug_getPosicion(pJugAux, posicion) == 0 &&
				jug_getNacionalidad(pJugAux, nacionalidad)== 0 &&
				jug_getEdad(pJugAux,&edad)== 0 &&
				jug_getSIdSeleccion(pJugAux, &idSeleccion)==0)
		{
			printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|\n",-4,id,-40,nombreCompleto,-3,edad,-25,posicion,-18,nacionalidad,-5,idSeleccion);
		}

	}
	return retorno;
}
//REVISAR
int jug_OrdenarPorNacionalidad(void* unJugador, void* otroJugador)
{
	int compara;
	Jugador* jugadorUno;
	Jugador* jugadorDos;
	jugadorUno=(Jugador*)unJugador;
	jugadorDos=(Jugador*)otroJugador;
	compara=strcmp(jugadorUno->nacionalidad,jugadorDos->nacionalidad);
	//ll_sort(listaJugadores, jug_OrdenarPorNacionalidad, 1);
	return compara;
}


