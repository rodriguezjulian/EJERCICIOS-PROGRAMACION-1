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
int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais)
{
	int retorno=-1;
	Jugador* pJugador;
	//int idSeleccion;//EL QUE TIENE LA ESTRUCTURA JUGADOR
	int tam;
	Seleccion* pSeleccion;

	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//PUNTERO A LA ESTRUCTURA TENIENDO EL INDICE
		pJugador=ll_get(pArrayListJugador, indice);

		//BUSCO EL TAMANIO DE LA LISTA DE SELECCIONES
		tam=ll_len(pArrayListSeleccion);
		for(int i=0;i<tam;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			if((*(pSeleccion)).id==(*(pJugador)).idSeleccion)
			{
				//PASO EL NOMBRE DEL PAIS
				strcpy(descripcionPais, (*(pSeleccion)).pais);
				break;
			}
		}
	}
	return retorno;
}
int jug_Listar_NoConvocados(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	Jugador* pJugador;
	int tam;
	tam=ll_len(pArrayListJugador);
	//referencia: SI LLEGA 1 SE MUESTRAN LOS JUGADORES CONVOCADOS, SI LLEGA 2 SE MUESTRAN LOS JUGADORES NO CONVOCADOS
	if(pArrayListJugador!=NULL)
	{


		printf("+===========================================================================================================+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",-6,"  ID",-40,"         NOMBRE COMPLETO",-4,"EDAD",-25,"      POSICION",-18,"    NACIONALIDAD",-8,"ID SELEC.");
		printf("+===========================================================================================================+\n");
		printf("|%*s|\n",-107,"                                           JUGADORES NO CONVOCADOS");
		printf("+===========================================================================================================+\n");
		for(int i=0;i<tam;i++)
		{
			pJugador=ll_get(pArrayListJugador, i);
			if((*(pJugador)).idSeleccion==0)
			{
				imprimirJugador(pArrayListJugador, i);
			}
		}
		printf("+===========================================================================================================+\n");
	}
	return retorno;
}

//ARME UNA NUEVA FUNCION PARA MOSTRAR A LOS JUGADORES CONVOCADOS Y AL NOMBRE DEL PAIS QUE LOS CONVOCO.
int jug_Listar_Convocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	Jugador* pJugador;
	int tam;
	tam=ll_len(pArrayListJugador);
	char descripcionPais[30];

	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		printf("+================================================================================================================================+\n");
		printf("|%*s|\n",-128,"                                                    JUGADORES CONVOCADOS");
		printf("+================================================================================================================================+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n%s\n",-6,"  ID",-40,"         NOMBRE COMPLETO",-4,"EDAD",-25,"      POSICION",
				-18,"    NACIONALIDAD",-8,"ID SELEC.",-20,"PAIS QUE CONVOCA","+================================================================================================================================+");

		for(int i=0;i<tam;i++)
		{
			pJugador=ll_get(pArrayListJugador, i);
			if((*(pJugador)).idSeleccion>0)
			{
				selec_AsignarDescripcionPais(pArrayListSeleccion, pArrayListJugador, i, descripcionPais);
				printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n",
						-4,(*(pJugador)).id,-40,(*(pJugador)).nombreCompleto,-3,(*(pJugador)).edad,-25,(*(pJugador)).posicion,
						-18,(*(pJugador)).nacionalidad,-5,(*(pJugador)).idSeleccion,-15,descripcionPais);
				retorno=0;
			}
		}
		printf("+================================================================================================================================+\n");
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
int selec_buscarPorId(LinkedList* pArrayListSeleccion, int idBuscado, int *indice)
{
	int retorno=-1;
	int tam;
	Seleccion* pSeleccion;
	tam=ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion!=NULL)
	{

		for(int i=0;i<tam;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			if((*(pSeleccion)).id==idBuscado)
			{
				*indice=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int selec_Solicitar_Id(LinkedList* pArrayListSeleccion, int* indice)
{
	int retorno=-1;
	int idPais;
	Seleccion* pSeleccion;
	if(pArrayListSeleccion!=NULL)
	{
		//SOLICITO ID.
		ingresarIntConRango(&idPais, "Ingrese pais para el que desea convocar jugadores.\n", "ERROR, Ingerse ID valido,\n", 1, 32);
		//CON EL ID, PASO A BUSCAR EL INDICE.
		selec_buscarPorId(pArrayListSeleccion, idPais, &(*(indice)));
		// BUSCO EL PUNTERO AL ELEMENTO TENIENDO EN CUENTA EL INDICE.
		pSeleccion=ll_get(pArrayListSeleccion, *(indice));

		if((*(pSeleccion)).convocados<22)
		{
			retorno=0;
		}
		else
		{
			printf("ERROR, La seleccion llego a su maximo de 22 convocados.\n");
		}
	}

	return retorno;
}
int jug_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int indiceSeleccion;
	int indiceJugador;
	int convocados;//SI SE CONFIRMA LA CONVOCACION DEBO SUMAR 1 A LA CANTIDAD DE CONVOCADOS EXISTENTES
	Seleccion* pSeleccion;
	Jugador* pJugador;
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//LISTO A LAS SELECCIONES
		controller_listarSelecciones(pArrayListSeleccion);
		//SOLICITO ID VALIDANDO DESDE ESTA MISMA FUNCION A TRAVEZ DE LLAMAR A selec_buscarPorId QUE EL PAIS NO HAYA LLEGADO A 22 CONVOCADOS.
		if(selec_Solicitar_Id(pArrayListSeleccion, &indiceSeleccion)==0)
		{
			jug_Listar_NoConvocados( pArrayListJugador);

			jug_Solicitar_Id(pArrayListJugador, &indiceJugador, "Ingrese ID de jugador que desea convocar\t");
			//PIEDO EL PUNTERO AL JUGADOR TENIENDO EN CUENTA EL INDICE.
			pJugador=ll_get(pArrayListJugador, indiceJugador);
			if((*(pJugador)).idSeleccion==0)
			{
				//APUNTO A LA ESTRUCUTRA DE SELECCION.
				pSeleccion=ll_get(pArrayListSeleccion, indiceSeleccion);
				//SUMO 1 A LOS CONVOCADOS YA EXISTENTES.
				convocados=(*(pSeleccion)).convocados+1;
				//LO SETEO.
				selec_setConvocados(pSeleccion, convocados);
				//ASIGNO LA SELECCION AL JUGADOR
				(*(pJugador)).idSeleccion=(*(pSeleccion)).id;
				printf("<<<<<<<<<< %s fue CONVOCADO exitosamente por %s >>>>>>>>>>\n\n",(*(pJugador)).nombreCompleto,(*(pSeleccion)).pais);
				retorno=0;
			}
			else
			{
				printf("ERROR, el jugador ya se encuentra convocado.\n");
			}

		}





	}

	return retorno;
}
/*int jug_convocar(LinkedList* pArrayListJugador, LinkedList* listaConfederaciones)
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
			//selec_buscar_Pais(listaConfederaciones, (*(pJugador)).idSeleccion, pais);

			printf("Jugador convocado exitosamente para el pais de %s",pais);
		}
		else
		{
		//	selec_buscar_Pais(listaConfederaciones, (*(pJugador)).idSeleccion, pais);
			printf("ERROR, El jugador %s ya se encuentra convocado para la seleccion de %s.\n",(*(pJugador)).nombreCompleto,pais);
		}
	}
	return retorno;
}*/
int operara_Menu_Opcion5(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int opcion;
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		printf("+==============================+\n|%*s|\n+==============================+\n",-30,"          LISTADOS");
		printf("|%*s|\n|%*s|\n|%*s|\n+==============================+\n",-30,"1.TODOS LOS JUGADORES ",-30,"2.TODAS LAS SELECCIONES",-30,"3.JUGADORES CONVOCADOS");
		ingresarIntConRango(&opcion, "INGRESE OPCION SEGUN DESEE LISTAR.\t", "ERROR, Ingrese opcion valida.\n", 1, 3);

    	switch(opcion)
    	{
    	case 1:
    		controller_listarJugadores(pArrayListJugador);
    	break;
    	case 2:
    		controller_listarSelecciones(pArrayListSeleccion);
    	break;
    	case 3:

    		jug_Listar_Convocados(pArrayListJugador, pArrayListSeleccion);
    	break;

    	}



	}

	return retorno;
}
