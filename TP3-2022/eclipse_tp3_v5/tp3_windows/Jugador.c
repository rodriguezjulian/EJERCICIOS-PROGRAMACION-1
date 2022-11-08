#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include <string.h>
 #include <ctype.h>
#include "ingresos.h"

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
int jug_BuscarIdMax(LinkedList* pArrayListJugador, int *idMaximo)
{
	int idMax;
	int retorno=-1;
	FILE* pIdMaximo=fopen("id.txt", "r");
	if(pIdMaximo!=NULL)
	{
		fscanf(pIdMaximo,"%d",&idMax);
		retorno=0;
		*idMaximo=idMax;
	}
	fclose(pIdMaximo);

	return retorno;
}
int jug_Solicitar_Id(LinkedList* pArrayListJugador, int * indice ,char * mensaje)
{
	int retorno=-1;
	int idBuscado;
	int idMaximo;
	//BUSCO EL ULTIMO ID PARA DARLE UN MAXIMO AL INGRESAR EL ID.

	if(pArrayListJugador!=NULL && jug_BuscarIdMax(pArrayListJugador, &idMaximo)==0)
	{
		controller_listarJugadores(pArrayListJugador);
				do
				{
					ingresarIntConRango(&idBuscado, mensaje, "ERROR, Ingrese ID existente\n", 1, idMaximo);
					//ESTE PRINT ES POR SI EL USUARIO CARGA UN ID QUE ESTA POR DEBAJO DEL MAXIMO PERO QUE YA FUE BORRADO.
					if(buscarJugPorId(pArrayListJugador, idBuscado, &(*(indice)))==-1)
					{
						printf("ERROR, Ingrese ID existente.\n");
					}
					//printf("POSICION %d\n",posicion);
				}while(buscarJugPorId(pArrayListJugador, idBuscado, &(*(indice)))==-1);
		retorno=0;
	}

	return retorno;
}
int buscarJugPorId(LinkedList* pArrayListJugador, int idBuscado, int* indice)
{
	int retorno=-1;
	Jugador* AuxJugador;
	if(pArrayListJugador!=NULL)
	{
		int tam= ll_len(pArrayListJugador);
		//printf("tam %d",tam);
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRE AL FOR DE BUSCAR POR ID\n");
			AuxJugador=ll_get(pArrayListJugador, i);
			//NO DEBO HACER (*(AuxJugador+i).id PORQUE YA ll_get me retorna puntero a indice especificado, ademas el tema de trabajar con posiciones consecutivas o no.
			if((*(AuxJugador)).id==idBuscado)
			{
				*indice=i;
				//printf("POSICION %d\n",*posicion);
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int jug_Editar_NombreCompleto(LinkedList* pArrayListJugador , int indice)
{
	int retorno=-1;
	Jugador* pJugador;
	pJugador=ll_get(pArrayListJugador, indice);
	int retornoSrtcmp=0;//LO INICIALIZO POR SI EL USUARIO MODIFICA MAS DE UNA VEZ EL CAMPO.
	char nuevoNombre[100];

	if(pArrayListJugador!=NULL)
	{
		do
		{
			ingresarCadenaCaracteres(100, nuevoNombre, "Ingrese nuevo nombre completo del jugador.\t", "ERROR, Ingrese nombre completo valido\n");
			retornoSrtcmp=strcmp((*(pJugador)).nombreCompleto, nuevoNombre);
			if(retornoSrtcmp==0)
			{
				printf("ERROR, El nombre ingresado es exactamente igual al existente\n");
			}
			else
			{
				jug_setNombreCompleto(pJugador, nuevoNombre);
				printf("\n<<<<<<<<<< MODIFICACION SATISFACTORIA - NUEVO NOMBRE: %s >>>>>>>>>\n\n",nuevoNombre);
				//printf("\n<<<<<<<<<<NUEVO NOMBRE %s>>>>>>>>>>\n", nuevoNombre);
				retorno=0;
			}
		}while(retornoSrtcmp==0);
	}
	if(retorno==-1)
	{
		printf("ERROR AL INTENTAR MODIFICAR");
	}
	return retorno;
}
int jug_Editar_Edad(LinkedList* pArrayListJugador , int indice)
{
	int retorno=-1;
	Jugador* pJugador;
	pJugador=ll_get(pArrayListJugador, indice);
	int nuevaEdad;

	if(pArrayListJugador!=NULL)
	{
		do
		{
			ingresarIntConRango(&nuevaEdad, "Ingrese nueva edad del jugador.(De 16 a 50 anios)\t", "ERROR, Ingrese edad valida.", 16, 50);
			if((*(pJugador)).edad==nuevaEdad)
			{
				printf("ERROR, La edad ingresada debe ser distinta a la existente actualmente.\n");
			}
			else
			{
				jug_setEdad(pJugador, nuevaEdad);
				printf("\n<<<<<<<<<< MODIFICACION SATISFACTORIA - NUEVA EDAD %d>>>>>>>>>>\n",nuevaEdad);
				retorno=0;
			}

		}while(retorno==-1);
	}
	else
	{
		printf("ERROR AL INTENTAR MODIFICAR");
	}
	return retorno;
}
int jug_Editar_Posicion(LinkedList* pArrayListJugador , int indice)
{
	int retorno=-1;
	Jugador* pJugador;
	pJugador=ll_get(pArrayListJugador, indice);
	char nuevaPosicion [30];
	int retornoSrtcmp=0;//LO INICIALIZO POR SI EL USUARIO MODIFICA MAS DE UNA VEZ EL CAMPO.

	if(pArrayListJugador!=NULL)
	{
		do
		{
			ingresarCadenaCaracteres(30, nuevaPosicion, "Ingrese nueva posicion del jugador.\nArquero - Defensor - Delantero - Mediocampista\t", "ERROR, Ingrese posicion valida\n");
			retornoSrtcmp=strcmp((*(pJugador)).posicion, nuevaPosicion);
			if(retornoSrtcmp==0)
			{
				printf("ERROR, La posicion ingresada es exactamente igual a la existente\n");
			}
			else
			{
				jug_setPosicion(pJugador, nuevaPosicion);
				printf("\n<<<<<<<<<< MODIFICACION SATISFACTORIA - NUEVA POSICION %s >>>>>>>>>>\n",nuevaPosicion);
				retorno=0;
			}
		}while(retornoSrtcmp==0);
	}
	else
	{
		printf("ERROR AL INTENTAR MODIFICAR");
	}
	return retorno;
}
int jug_Editar_Nacionalidad(LinkedList* pArrayListJugador , int indice)
{
	int retorno=-1;
	Jugador* pJugador;
	pJugador=ll_get(pArrayListJugador, indice);
	char nuevaNacionalidad[30];
	int retornoSrtcmp=0;//LO INICIALIZO POR SI EL USUARIO MODIFICA MAS DE UNA VEZ EL CAMPO.

	if(pArrayListJugador!=NULL)
	{
		do
		{
			ingresarCadenaCaracteres(30, nuevaNacionalidad, "Ingrese nueva nacionalidad del jugador.\t", "ERROR, Ingrese nacionalidad valida.\n");
			retornoSrtcmp=strcmp((*(pJugador)).nacionalidad, nuevaNacionalidad);
			if(retornoSrtcmp==0)
			{
				printf("ERROR, La nacionalidad ingresada es exactamente igual a la existente\n");
			}
			else
			{
				jug_setNacionalidad(pJugador, nuevaNacionalidad);
				printf("\n<<<<<<<<<< MODIFICACION SATISFACTORIA - NUEVA NACIONALIDAD %s >>>>>>>>>\n",nuevaNacionalidad);
				retorno=0;
			}
		}while(retornoSrtcmp==0);
	}
	else
	{
		printf("ERROR AL INTENTAR MODIFICAR");
	}

	return retorno;
}
int jug_Confirmar_Baja(LinkedList* pArrayListJugador, int indice, char* nombreJugador)
{
	int retorno=-1;
	char confirmacion;
	char auxMayus;
	do
	{
		printf("Para confirmar la baja del jugador %s presione 'S', caso contrario 'N'.\n",nombreJugador);
		fflush(stdin);
		gets(&confirmacion);
		auxMayus=toupper(confirmacion);
		if(auxMayus=='S')
		{
			printf("<<<<<<<<<< BAJA CONFIRMADA >>>>>>>>>\n");
			retorno=0;
			ll_remove(pArrayListJugador, indice);
		}
	}while(verificarCaracterSN(confirmacion)==-1);
	//ARMO UN NUEVO IF PARA ESTE MSJ YA QUE SI LO PONGO COMO ELSE DENTRO DEL do{}while(), CADA VEZ QUE EL USUARIO INGRESE
	//CUALQUIER LETRA, APARECERIA
	if(retorno==-1)
	{
		printf("<<<<<<<<< BAJA CANCELADA >>>>>>>>>>\n");
	}
	return retorno;
}

int jug_convocar(LinkedList* pArrayListJugador, LinkedList* listaConfederaciones)
{
	int retorno=-1;
	int indice;

	//INICIALIZO EL PUNTERO POR BUENAS PRACTICAS
	Jugador* pJugador=NULL;
	char pais[30];
	if(pArrayListJugador!=NULL && listaConfederaciones!=NULL)
	{
		//SOLICITAR ID LLAMA A FUNCION PARA LISTAR JUGADORES.
		jug_Solicitar_Id(pArrayListJugador, &indice, "Ingrese ID del jugador que desea convocar.\n");
		pJugador=ll_get(pArrayListJugador, indice);
		if((*(pJugador)).idSeleccion==0)
		{
			//controller_listarSelecciones(listaConfederaciones);
			//printf("ID SELECCION")
			selec_buscar_Pais(listaConfederaciones, (*(pJugador)).idSeleccion, pais);

			printf("Jugador convocado exitosamente para el pais de %s",pais);

		}
		else
		{
			selec_buscar_Pais(listaConfederaciones, (*(pJugador)).idSeleccion, pais);
			printf("ERROR, El jugador %s ya se encuentra convocado para la seleccion de %s.\n",(*(pJugador)).nombreCompleto,pais);
		}
	}



	return retorno;
}
