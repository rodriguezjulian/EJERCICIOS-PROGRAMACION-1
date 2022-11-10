#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "ingresos.h"
#include<string.h>

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
	//PASAR A FUNCION.
	pArchivoId=fopen("id.txt", "r");
	if(pArrayListJugador!=NULL && pJugador!=NULL && pArchivoId!=NULL)
	{
		while(!feof(pArchivoId))
		{
			retornoFscanf=fscanf(pArchivoId,"%d",&id);
			//printf("idAux %d\n",id);
			//printf("RETORNO SCANF: %d",retornoFscanf);
			if(retornoFscanf==1)
			{
				id=id+1;
				//puts("SE ABRIO OK\n");

			}
			else
			{
				//puts("FALLA EL FSCANF\n");
				break;
			}

		}
		fclose(pArchivoId);
		//VER SI LA SOBRE ESCRITURA LA PONGO EN OTRA OPCION
		pArchivoId=fopen("id.txt", "w");
		if(pArchivoId!=NULL)
		{
			fprintf(pArchivoId,"%d",id);
		}
		fclose(pArchivoId);
		//printf("NUEVO ID %d\n",id);

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
	int retorno=-1;
	//int idBuscado;
	//int idMaximo; //PARA DARLE RANGO AL INGRESO DE ID.
	int indice;
	int opcion;
	//FILE* pIdMaximo;



	/*pIdMaximo=fopen("id.txt", "r");
	if(pIdMaximo!=NULL)
	{
		fscanf(pIdMaximo,"%d",&idMaximo);
	}
	fclose(pIdMaximo);*/
	//printf("ID MAXIMO HASTA EL MOMENTO %d \n",idMaximo);
	if(pArrayListJugador!=NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		//SOLICITO ID (AL HACERLO TOMO COMO PARAMETRO EL MAXIMO ID)
		jug_Solicitar_Id(pArrayListJugador, &indice, "Ingrese ID que desea modificar.\n");

		printf("+===========================================================================================================+\n"
				"|%*s|%*s|%*s|%*s|%*s|%*s|\n%s",-6,"  ID",-40,"         NOMBRE COMPLETO",-4,"EDAD",-25,"      POSICION",-18,"    NACIONALIDAD",-8,"ID SELEC.",
				"+===========================================================================================================+\n");
		imprimirJugador(pArrayListJugador, indice);
		printf("+===========================================================================================================+\n");

		printf("+==============================+\n|%*s|\n+==============================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n"
				"+==============================+\n",-30,"INGRESE SEGUN DESEE MODIFICAR",-30,"1.NOMBRE.",-30,"2.EDAD.",-30,"3.POSICION.",-30,"4.NACIONALIDAD.");

		ingresarIntConRango(&opcion, "Opcion ingresada:", "ERROR, Ingrese opcion valida", 1, 4);
		switch(opcion)
		{
		case 1:
			jug_Editar_NombreCompleto(pArrayListJugador, indice);
		break;
		case 2:
			jug_Editar_Edad(pArrayListJugador, indice);
		break;
		case 3:
			jug_Editar_Posicion(pArrayListJugador, indice);
		break;
		case 4:
			jug_Editar_Nacionalidad(pArrayListJugador, indice);
		break;
		}
		retorno=0;
	}
    return retorno;
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
	int retorno=-1;

	int indice;

	Jugador* pJugador;
	//SOLICITO ID (AL HACERLO TOMO COMO PARAMETRO EL MAXIMO ID)
	jug_Solicitar_Id(pArrayListJugador, &indice, " Ingrese ID que desea dar de baja.\n");
	pJugador=ll_get(pArrayListJugador, indice);

	//SE ENCARGA DE CONFIRMAR LA BAJA.(ll_remove)
	jug_Confirmar_Baja( pArrayListJugador,  indice, (*(pJugador)).nombreCompleto);


	//FALTA HACER LO DE LOS CONVOCADOS.

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
	int orden;
	if(pArrayListSeleccion!=NULL)
	{
		ingresarIntConRango(&orden, "Ingrese 1 para ordenar de forma ascedente o 0 para ordenar de manera descendente.\n", "ERROR, Ingrese numero valido.\n", 0, 1);
		printf("<<<<<<<<<< Este proceso puede tardar unos segundos. >>>>>>>>>>\n");

		ll_sort(pArrayListSeleccion, selec_OrdenarPorConfederacion, 0);
		controller_listarSelecciones(pArrayListSeleccion);

		//selec_OrdenarPorConfederacion(unaConderacion, otraConfederacion)
	}
	return 1;
}
/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=0;
		int orden;
		int opcion;
		if(pArrayListJugador!=NULL)
		{
			printf("+========================================+\n");
			printf("|%*s|\n+========================================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n+========================================+\n",
					-40,"              LISTAR",-40,"1.POR NACIONALIDAD.",-41,"2.POR SELECCIONES POR CONFEDERACIÓN.",
					-40,"3.JUGADORES POR EDAD.",-40,"4.JUGADORES POR NOMBRE.");

			ingresarIntConRango(&opcion, "Ingrese opcion segun desee listar.\n", "ERROR, Ingrese opcion valida.\n", 1, 4);
			//SI LA OPCION ES ==2 DENTRO DE CONTROLLER CONSULTO ACERCA DEL ORDEN
			if(opcion==1 || opcion==3 || opcion==4)
			{
				ingresarIntConRango(&orden, "Ingrese 1 para ordenar de forma ascedente o 0 para ordenar de manera descendente.\n", "ERROR, Ingrese numero valido.\n", 0, 1);
				printf("<<<<<<<<<< Este proceso puede tardar unos segundos. >>>>>>>>>>\n");
			}
			switch(opcion)
			{
			case 1:
				//jug_OrdenarPorNacionalidad
				ll_sort(pArrayListJugador, jug_OrdenarPorNacionalidad, orden);
				controller_listarJugadores(pArrayListJugador);
			break;
			case 2:
				controller_ordenarSelecciones(pArrayListSeleccion);
			break;
			case 3:
				//jug_OrdenarPorEdad
				ll_sort(pArrayListJugador, jug_OrdenarPorEdad, orden);
				controller_listarJugadores(pArrayListJugador);
			break;
			case 4:
				//jug_OrdenarPorNombre
				ll_sort(pArrayListJugador, jug_OrdenarPorNombre, orden);
				controller_listarJugadores(pArrayListJugador);
			break;
			}
		}

		return retorno;
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


int jug_guardarJugadores(LinkedList* pArrayListSeleccion, char* nombreConfederacion, LinkedList* pArrayListJugador, int cantidadConvocados, char* path)
{
	int retorno=-1;
	Jugador* pJugador;
	int tamJugadores;
	//char nombresJugadoresAux[100];
	tamJugadores=ll_len(pArrayListJugador);
	//int arrayIdsAux[cantidadConvocados];
	//int j=0;

	FILE* pArchivo;
	pArchivo=fopen(path,"wb");

	if(pArrayListSeleccion!=NULL)
	{

			for(int i=0;i<tamJugadores;i++)
			{
				if(strcmp(nombreConfederacion,"CONMEBOL"))
				{
					pJugador=ll_get(pArrayListJugador, i);
					if((*(pJugador)).id==3 || (*(pJugador)).id==6 || (*(pJugador)).id==13 || (*(pJugador)).id==32)
					{
						//fwrite(pJugador,sizeof(Jugador),cantidadConvocados,pArchivo);
						fwrite(pJugador,sizeof(Jugador),cantidadConvocados,pArchivo);
						//fprintf();
					}
				}
			}
		fclose(pArchivo);
	}

	return retorno;
}



/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	/*char confederacion [30];

	FILE* pArchivo;
	int cantidadConvocados;
	//char nombresJugadoresAux[100];
	int cantidadLeida;

	Jugador pJugador;
	//int tam;
	//tam=ll_len(pArrayListJugador);

	selec_IngresarConfederacion(confederacion);

	selec_verificarConvocadosPorconfederacion(confederacion, pArrayListSeleccion,&cantidadConvocados);
	//printf("CONVOCADOS %d",cantidadConvocados);
	strcat(confederacion,".bin");
	strcpy(path,confederacion);

	jug_guardarJugadores(pArrayListSeleccion, confederacion, pArrayListJugador, cantidadConvocados, path);

*/
	/*while(!feof(pArchivo))
	{

		cantidadLeida=fread(pJugador,sizeof(Jugador),cantidadConvocados,pArchivo);
		if(cantidadLeida==1)
		{
			printf("Nombre: %s",pJugador.nombreCompleto);
		}


	}*/


	return retorno;
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


