#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "ingresos.h"
/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE *pFile=fopen(path, "r");
	//LLAMO AL PARSER
	//PATH=RUTA
	if(pFile!=NULL)
	{
		//pArrayListJugador=ll_newLinkedList();
		if(parser_JugadorFromText(pFile, pArrayListJugador)==0)
		{
			printf("SE LEYO CORRECTAMENTE EL ARCHIVO \n");
		}
		else
		{
			puts("ERROR AL CARGAR EL ARCHIVO");
		}
	}
	fclose(pFile);
    return 1;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
//ALTA MANUAL
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion=0;
	int retornoFscanf;
	FILE *pArchivoId;

	Jugador* pJugador;
	pJugador=jug_new();

	pArchivoId=fopen("id.txt", "r");
	if(pArrayListJugador!=NULL && pJugador!=NULL && pArchivoId!=NULL)
	{
		while(!feof(pArchivoId))
		{
			retornoFscanf=fscanf(pArchivoId,"%d",&id);
			printf("idAux %d\n",id);
			printf("RETORNO SCANF: %d",retornoFscanf);
			if(retornoFscanf==1)
			{
				id=id+1;
				puts("SE ABRIO OK\n");

			}
			else
			{
				puts("FALLA EL FSCANF\n");
				break;
			}

		}
		fclose(pArchivoId);
		pArchivoId=fopen("id.txt", "w");
		if(pArchivoId!=NULL)
		{
			fprintf(pArchivoId,"%d",id);
		}
		fclose(pArchivoId);
		printf("NUEVO ID %d\n",id);

		if(ingresarCadenaCaracteres(100, nombreCompleto, "Ingrese nombre completo del jugador.\t", "ERROR, Ingrese nombre completo valido\n")==0 &&
				ingresarIntConRango(&edad, "Ingrese edad del jugador.\t", "ERROR, Ingrese edad valida.", 16, 50)==0 &&
				ingresarCadenaCaracteres(30, posicion, "Ingrese posicion del jugador.\nArquero - Defensor - Delantero - Mediocampista\t", "ERROR, Ingrese posicion valida\n")==0 &&
				ingresarCadenaCaracteres(30, nacionalidad, "Ingrese nacionalidad del jugador.\t", "ERROR, Ingrese nacionalidad valida")==0)
		{
			//HACER EL SET DE TOOOODOS LOS DATOS
			if(jug_setId(pJugador, id)==0 &&
				jug_setNombreCompleto(pJugador, nombreCompleto)==0 &&
				jug_setPosicion(pJugador, posicion)==0 &&
				jug_setNacionalidad(pJugador, nacionalidad)==0 &&
				jug_setEdad(pJugador, edad)==0 &&
				jug_setIdSeleccion(pJugador, idSeleccion)==0)
			{
				ll_add(pArrayListJugador, pJugador);
				retorno=0;
				printf("\n<<<<<<<<<<ALTA EXITOSA>>>>>>>>>>\n");
			}
		}
		else
		{
			printf("\n<<<<<<<<<<ERROR AL LOGUEAR NUEVO JUGADOR>>>>>>>>>>\n");
			jug_delete(pJugador);
		}
	}
	else
	{
		printf("\n<<<<<<<<<<ERROR AL LOGUEAR NUEVO JUGADOR>>>>>>>>>>\n");
		jug_delete(pJugador);
	}
    return retorno;

}
/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int cantidad;
	printf("+===========================================================================================================+\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",-6,"  ID",-40,"         NOMBRE COMPLETO",-4,"EDAD",-25,"      POSICION",-18,"    NACIONALIDAD",-8,"ID SELEC.");
	printf("+===========================================================================================================+\n");
	if(pArrayListJugador)
	{
		cantidad=ll_len(pArrayListJugador);
		for(int i=0;i<cantidad;i++)
		{
			imprimirJugador(pArrayListJugador,i);

		}
		printf("+===========================================================================================================+\n");
	}
    return 1;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	//Jugador* pJugador;
	int idBuscado;
	int idMaximo; //PARA DARLE RANGO AL INGRESO DE ID.
	int posicion;
	int opcion;
	FILE* pIdMaximo;
	pIdMaximo=fopen("id.txt", "r");
	if(pIdMaximo!=NULL)
	{
		fscanf(pIdMaximo,"%d",&idMaximo);
	}
	fclose(pIdMaximo);
	//printf("ID MAXIMO HASTA EL MOMENTO %d \n",idMaximo);
	if(pArrayListJugador!=NULL)
	{
		//void ll_remove>Elimina un elemento en LinkedList, en el índice especificado.
		controller_listarJugadores(pArrayListJugador);
		do
		{
			ingresarIntConRango(&idBuscado, "Ingrese ID que desea modificar.\n", "ERROR, Ingrese ID valido\n", 1, idMaximo);
			if(buscarJugPorId(pArrayListJugador, idBuscado, &posicion)==-1)
			{
				printf("ERROR, Ingrese ID existente.\n");
			}
			//printf("POSICION %d\n",posicion);
		}while(buscarJugPorId(pArrayListJugador, idBuscado, &posicion)==-1);


		printf("+===========================================================================================================+\n"
				"|%*s|%*s|%*s|%*s|%*s|%*s|\n%s",-6,"  ID",-40,"         NOMBRE COMPLETO",-4,"EDAD",-25,"      POSICION",-18,"    NACIONALIDAD",-8,"ID SELEC.",
				"+===========================================================================================================+\n");
		imprimirJugador(pArrayListJugador, posicion);
		printf("+===========================================================================================================+\n");


		printf("+==============================+\n|%*s|\n+==============================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n"
				"+==============================+\n",-30,"INGRESE SEGUN DESEE MODIFICAR",-30,"1.NOMBRE.",-30,"2.EDAD.",-30,"3.POSICION.",-30,"4.NACIONALIDAD.");

		ingresarIntConRango(&opcion, "Opcion ingresada:", "ERROR, Ingrese opcion valida", 1, 4);
		switch(opcion)
		{
		case 1:
			jug_Modificar_NombreCompleto(pArrayListJugador, posicion);
		break;
		case 2:
			jug_Modificar_Edad(pArrayListJugador, posicion);
		break;
		case 3:
			jug_Modificar_Posicion(pArrayListJugador, posicion);
		break;
		case 4:
			jug_Modificar_Nacionalidad(pArrayListJugador, posicion);
		break;




		}
	}




    return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
    return 1;
}


/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pFile= fopen(path,"r");
	int retorno=-1;
	if(pFile!=NULL)
	{
		if(parser_SeleccionFromText(pFile, pArrayListSeleccion)==0)
		{
			printf("ARCHIVO DE SELECCIONES LEIDO SATISFACTORIAMENTE\n");
			retorno=0;
		}
		else
		{
			printf("ERROR, Al abrir archivo de selecciones");
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int cantidad;
	int retorno=-1;
	if(pArrayListSeleccion!=NULL)
	{
		//printf("| %*d|%*s|%*s| %*d|\n",-3,id,-25,pais,-10,confederacion,-3,convocados);
		printf("+=========================================================+\n");
		printf("|%*s|%*s|%*s|%*s|\n",-4," ID",-25,"         PAIS",-15," CONFEDERACION",-10,"CONVOCADOS");
		printf("+=========================================================+\n");
		cantidad=ll_len(pArrayListSeleccion);
		for(int i=0;i<cantidad;i++)
		{
			imprimirSeleccion(pArrayListSeleccion, i);
		}
		printf("+=========================================================+\n");
	}

    return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


