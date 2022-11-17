#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "ingresos.h"
#include <string.h>
#include "salidas.h"

/// \fn int controller_cargarIdMaximo(LinkedList*, int*)
/// \brief Abre un archivo que contiene el maximo id y lo pasa por referencia.
///
/// \param pArrayListJugador
/// \param idMaximo
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int controller_cargarIdMaximo( int *idMaximo)
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
/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *Dentro de la funcion se llama a parser_JugadorFromText para poder cargar los datos de manera ordenada y
 *satisfactoria.
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int return=0 SALIO BIEN / return=-1 SALIO MAL
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	FILE *pFile=fopen(path, "r");
	//LLAMO AL PARSER
	//PATH=RUTA
	if(pFile!=NULL)
	{
		//pArrayListJugador=ll_newLinkedList();
		if(parser_JugadorFromText(pFile, pArrayListJugador)!=0)
		{
			puts("ERROR AL CARGAR EL ARCHIVO");
		}
		else
		{
			retorno=0;
		}
	}
	fclose(pFile);
    return retorno;
}
/// \fn int controller_listarSelecciones(LinkedList*)
/// \brief Se listan selecciones,dentro se llama a imprimir seleccion.
///
/// \param pArrayListSeleccion
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
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
			if(selec_imprimirSeleccion(pArrayListSeleccion, i)==0)
			{
				retorno=0;
			}
		}
		printf("+=========================================================+\n");
	}
    return retorno;
}

/// \fn int controller_listarJugadores(LinkedList*, LinkedList*)
/// \brief  *Se listan jugadores, se llama a jug_imprimirJugadores pasando como parametro un 1 para mostrar
/// tanto a jugadores convocados como no convocados.
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	//UTILIZO LA FUNCION jug_imprimirJugadores EN VARIAS OCASIONES YA QUE RECIBE UNA REFERENCIA DE QUE
	//MOSTRAR, EN ESTE CASO LA REFERENCIA SERA DE 1 PARA ASI MOSTRAR JUGADORES CONVOCADOS Y NO.
	if(jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 1)==0)
	{
		retorno=0;
	}

    return retorno;
}
/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return  return=0 SALIO BIEN / return=-1 SALIO MAL
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* listaJugadoresBinario,LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	FILE *pArchivo;
	Jugador* jugadorAux;
	int cantidad;


	if(listaJugadoresBinario!=NULL && ll_clear(listaJugadoresBinario)==0)
	{
		pArchivo=fopen(path,"rb");
		if(pArchivo!=NULL)
		{
			while(!feof(pArchivo))
				{
					jugadorAux=jug_new();
					//VERIFICAR ARCHIVO DISTINTO DE NULL
					cantidad=fread(jugadorAux,sizeof(Jugador),1,pArchivo);
					if(cantidad==1)
					{
						ll_add(listaJugadoresBinario, jugadorAux);
						retorno=0;
					}
				}
				fclose(pArchivo);
				controller_listarJugadores(listaJugadoresBinario,pArrayListSeleccion);
		}
	}
    return retorno;
}

/// \fn int controller_agregarJugador(LinkedList*, int*)
/// \brief Solicita validando continuamente los datos necesarios para completar cada campo de la estructura de un jugador,
/// los mismo se setean y agregan a la likedlist. Se pasa por referencia el valor de idMax, que es el ID maximo hasta el momento,
/// este dato sera de vital importancia a la hora de guardar o no los datos que se modificaron en el archivo.
///
/// \param pArrayListJugador
/// \param idMax
/// \return  return=0 SALIO BIEN / return=-1 SALIO MAL
//ALTA MANUAL
int controller_agregarJugador(LinkedList* pArrayListJugador , int* idMax)
{
	int retorno=-1;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion=0;

	//FILE *pArchivoId;

	Jugador* pJugador;
	pJugador=jug_new();
	//PASAR A FUNCION.
	//pArchivoId=fopen("id.txt", "r");
	if(pArrayListJugador!=NULL && pJugador!=NULL)
	{
		//jug_BuscarIdMax(pArrayListJugador, &id);
		*idMax=*idMax+1;

		if(ingresarCadenaCaracteres(100, nombreCompleto, "Ingrese nombre completo del jugador.\t", "ERROR, Ingrese nombre completo valido\n")==0 &&
				ingresarIntConRango(&edad, "Ingrese edad del jugador (16/50).\t", "ERROR, Ingrese edad valida.", 16, 50)==0 &&
				jug_IngresarPosicion(posicion)==0 &&
				jug_IngresarNacionalidad(nacionalidad)==0)
		{
			//HACER EL SET DE TODOS LOS DATOS
			if(jug_setId(pJugador, *idMax)==0 &&
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

/// \fn int controller_listar(LinkedList*, LinkedList*)
/// \brief Muestra menu para que el usuario ingrese opcion segun lo que se desee listar y llama a la funcion que corresponda,
///  se valida el retorno de la funcion llamada.
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_listar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
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
    		if(controller_listarJugadores(pArrayListJugador,pArrayListSeleccion)==0)
    		{
    			retorno=0;
    		}
    	break;
    	case 2:
    		if(controller_listarSelecciones(pArrayListSeleccion)==0)
    		{
    			retorno=0;
    		}
    	break;
    	case 3:
    		if(jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 2)==0)
    		{
    			retorno=0;
    		}
    	break;
    	}
	}
	return retorno;
}
/** \brief Modificar datos del jugador
 *Muestra lista de jugadores llamando a jug_imprimirJugadores, pide id de jugador a modificar (se valida),muestra menu
 *para que el usuario ingrese opcion segun desee operar, se llaman funciones segun corresponda y se validan sus
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return return=0 SALIO BIEN / return=-1 SALIO MAL
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{

	int retorno=-1;
	int indice;
	int opcion;

	if(pArrayListJugador!=NULL)
	{
		controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);
		//SOLICITO ID (AL HACERLO TOMO COMO PARAMETRO EL MAXIMO ID)
		jug_Solicitar_Id(pArrayListJugador, &indice, "Ingrese ID que desea modificar.\n");


		jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 1);


		printf("+==============================+\n|%*s|\n+==============================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n"
				"+==============================+\n",-30,"INGRESE SEGUN DESEE MODIFICAR",-30,"1.NOMBRE.",-30,"2.EDAD.",-30,"3.POSICION.",-30,"4.NACIONALIDAD.");

		ingresarIntConRango(&opcion, "Opcion ingresada:", "ERROR, Ingrese opcion valida", 1, 4);
		switch(opcion)
		{
		case 1:
			if(jug_Editar_NombreCompleto(pArrayListJugador, indice)==0)
			{
				retorno=0;
			}
		break;
		case 2:
			if(jug_Editar_Edad(pArrayListJugador, indice)==0)
			{
				retorno=0;
			}
		break;
		case 3:
			if(jug_Editar_Posicion(pArrayListJugador, indice)==0)
			{
				retorno=0;
			}
		break;
		case 4:
			if(jug_Editar_Nacionalidad(pArrayListJugador, indice)==0)
			{
				retorno=0;
			}
		break;
		}

	}
    return retorno;
}



/// \fn int controller_removerJugador(LinkedList*, LinkedList*)
/// \brief Se listad jugadores, se solita id (se valida), se elimina jugador de la lista y en caso que este convocado por alguna
/// seleccion, se descuenta 1 (funcion selec_restarConvocado).
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	Jugador* pJugador;
	int jugIdSelec;
	char jugNombreCompleto[100];
	int indice;

	if(pArrayListJugador!=NULL)
	{
		controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);
		//SOLICITO ID (AL HACERLO TOMO COMO PARAMETRO EL MAXIMO ID)
		jug_Solicitar_Id(pArrayListJugador, &indice, " Ingrese ID que desea dar de baja.\n");
		pJugador=ll_get(pArrayListJugador, indice);
		if(jug_getNombreCompleto(pJugador, jugNombreCompleto)==0)
		{
			//SE ENCARGA DE CONFIRMAR LA BAJA. DENTRO SE LLAMA A (ll_remove).
			if(jug_Confirmar_Baja( pArrayListJugador,  indice, jugNombreCompleto)==0)
			{
				//VERIFICO QUE SI EL JUGADOR PERTENECE A UN EQUIPO.
				if(jug_getSIdSeleccion(pJugador, &jugIdSelec)==0)
				{
					//DEBERIA MOVER ESTE CODIGO A UNA FUNCION Y LLAMARLA DESDE CONFIRMAR BAJA
					if(jugIdSelec>0)
					{
						//printf("ENTRO 2\n");
						//SI EL JUGADOR ESTABA CONVOCADO, ANTES DE REMOVERLO, LE RESTO 1 AL CONTADOR DE CONVOCADOS DE SU SELECCION.
						if(selec_restarConvocado(pArrayListSeleccion, jugIdSelec)==0)
						{
							//UNA VEZ QUE RESTE, REMUEVO AL JUGADOR FINALMENTE.
							ll_remove(pArrayListJugador, indice);
							retorno=0;
						}
					}
					else
					{
						//SI EL JUGADOR NO ESTABA CONVOCADO POR NINGUNA SELECCION ll_remove
						ll_remove(pArrayListJugador, indice);
						retorno=0;
					}
				}
			}
		}
	}
    return retorno;
}


/// \fn int controller_ordenarSelecciones(LinkedList*)
/// \brief Se pide un orden para ordenar, ascendente o descente (se valida), se llama a ll_sort utilizando puntero
/// a funcion con selec_OrdenarPorConfederacion
///
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int orden;
	int retorno=-1;
	if(pArrayListSeleccion!=NULL)
	{
		ingresarIntConRango(&orden, "Ingrese 1 para ordenar de forma ascedente o 0 para ordenar de manera descendente.\n", "ERROR, Ingrese numero valido.\n", 0, 1);
		printf("<<<<<<<<<< Este proceso puede tardar unos segundos. >>>>>>>>>>\n");

		if(ll_sort(pArrayListSeleccion, selec_OrdenarPorConfederacion, orden)==0 &&
		controller_listarSelecciones(pArrayListSeleccion)==0)
		{
			retorno=0;
		}
	}
	return retorno;
}
/// \fn int controller_ordenarJugadores(LinkedList*, LinkedList*)
/// \brief Se muestra un menu de opciones, el usuario ingresa segun desee operar (validacion),se llama a
/// la funcion correspondiente validando su retorno.
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
		int orden;
		int opcion;

		if(pArrayListJugador!=NULL)
		{
			printf("+========================================+\n");
			printf("|%*s|\n+========================================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n+========================================+\n",
					-40,"              LISTAR",-40,"1.POR NACIONALIDAD.",-41,"2.POR CONFEDERACIÓN.",
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
				if(ll_sort(pArrayListJugador, jug_OrdenarPorNacionalidad, orden)==0 &&
				controller_listarJugadores(pArrayListJugador,pArrayListSeleccion)==0)
				{
					retorno=0;
				}
			break;
			case 2:
				if(controller_ordenarSelecciones(pArrayListSeleccion)==0)
				{
					retorno=0;
				}
			break;
			case 3:
			if(	ll_sort(pArrayListJugador, jug_OrdenarPorEdad, orden)==0 &&
				controller_listarJugadores(pArrayListJugador,pArrayListSeleccion))
			{
				retorno=0;
			}
			break;
			case 4:

				if(ll_sort(pArrayListJugador, jug_OrdenarPorNombre, orden)==0 &&
				controller_listarJugadores(pArrayListJugador,pArrayListSeleccion))
				{
					retorno=0;
				}
			break;
			}
		}
		return retorno;
}
/// \fn int controller_editarSeleccion(LinkedList*, LinkedList*)
/// \brief Se muestra menu, el usuario elige segun desee operar (validacion), se llama a jug_convocar o a jug_Quitar_Convocado segun corresponda.
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_editarSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int opcion;
	Seleccion* pSeleccion;
	int tamSeleccion;
	int selecConvocados;
	int flag=0;//SI AL RECORRER LA LINKEDLIST NO SE ENCUENTRA NINGUNA SELECCION CON CONVOCADOS, EL FLAG QUEDARA EN 0, NO SE PODRA ACCEDER
	//A LA OPCION DE QUITAR CONVOCADOS Y SE MOSTRARA UN MENSAJE.
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		printf("+=========================================+\n");
		printf("|%*s|\n|%*s|\n",-41,"         1.CONVOCAR JUGADOR",-41,"         2.QUITAR DE SELECCION");
		printf("+=========================================+\n");
		ingresarIntConRango(&opcion, "Ingrese opcion segun desee operar.\n", "ERROR, Elija opcion valida.\n", 1, 2);
		switch(opcion)
		{
		case 1:
			if(jug_convocar(pArrayListJugador, pArrayListSeleccion)==0)
			{
				retorno=0;
			}
		break;
		case 2:
			//TENGO QUE HACER ESTO PORQUE SI EL USUARIO CONVOCO Y SALIO GUARDANDO, Y LUEGO QUISO OPERAR ESTA OPCION, SI USO UN FLAG
			//ESTARIA SETEADO NUEVAMENTE  A 0
			tamSeleccion=ll_len(pArrayListSeleccion);
			for(int i=0;i<tamSeleccion;i++)
			{
				pSeleccion=ll_get(pArrayListSeleccion, i);

				if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
				{
					if(selecConvocados!=0)
					{
						if(jug_Quitar_Convocado(pArrayListJugador, pArrayListSeleccion)==0)
						{
							retorno=0;
							flag=1;
							break;
						}
					}
				}
			}
			if(flag==0)
			{
				printf("ERROR, No se pueden quitar convocados si aun no hay ninguno.\n");
			}
		break;
		}
	}
	return retorno;
}


/// \fn int controller_guardarJugadoresModoTexto(char*, LinkedList*)
/// \brief Se abre un archivo para sobrescribirlo con lo cargado en la lista recibida por parametro, se
/// obtienen valores mediante getters validando, y por ultimo se cierra el archivo.
///
/// \param path
/// \param pArrayListJugador
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	FILE* pFile= fopen(path,"w");
	int tam= ll_len(pArrayListJugador);
	Jugador* pJugador;
	int edad;
	int id;
	char nacionalidad[30];
	char nombreCompleto[100];
	char posicion[30];
	int idSeleccion;
	if(pArrayListJugador!=NULL && pFile!=NULL )
	{
		fprintf(pFile,"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");
		for(int i=0;i<tam;i++)
		{
			pJugador=ll_get(pArrayListJugador, i);

			if(jug_getEdad(pJugador, &edad)==0 &&
				jug_getId(pJugador, &id)==0	&&
				jug_getNacionalidad(pJugador, nacionalidad)==0 &&
				jug_getNombreCompleto(pJugador, nombreCompleto)==0 &&
				jug_getPosicion(pJugador, posicion)==0 &&
				jug_getSIdSeleccion(pJugador, &idSeleccion)==0)
				{
					fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
					retorno=0;
				}
		}
		fclose(pFile);
	}
	if(retorno==0)
	{
		printf("\n<<<<<<<<<< JUGADORES GUARDADOS CORRECTAMENTE >>>>>>>>>>\n");
	}
    return retorno;
}


/// \fn int controller_guardarMaxId(char*, int)
/// \brief Abre un archivo y obtiene el unico dato que contiene, el mismo corresponde al id maximo operado hasta el momento.
///
/// \param path
/// \param maxId
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_guardarMaxId(char* path, int maxId)
{
	int retorno=-1;
	FILE* pArchivo= fopen("id.txt", "w");
	if(path!=NULL)
	{
		fprintf(pArchivo,"%d",maxId);
		retorno=0;

		printf("\n<<<<<<<<<< MAXIMO ID GUARDADO CORRECTAMENTE >>>>>>>>>>\n");
	}
	fclose(pArchivo);
	return retorno;
}
/** \brief Guarda los datos de los jugadores convocados en un archivo binario de una confederacion especifica validando que la
 * misma tenga convocados.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return return=0 SALIO BIEN / return=-1 SALIO MAL
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	char confederacion [30];

	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		selec_IngresarConfederacion(confederacion);

		if(selec_verificarConvocadosPorconfederacion(confederacion, pArrayListSeleccion)==0)
		{
			//ANALIZAR SI DEBO SOBREESCRIBIR O GENERAR NUEVOS ARCHIVOS.
			if(jug_guardarJugadores(pArrayListSeleccion, confederacion, pArrayListJugador, path)==0)
			{
				printf("<<<<<<<<<< ARCHIVO BINARIO CREADO SATISFACTORIAMENTE >>>>>>>>>\n");
				retorno=0;
			}
		}
		else
		{
			printf("ERROR, Los paises que integran a la confederacion %s, NO cuentan con convocados.\n",confederacion);
		}
	}
	return retorno;
}




/** \brief Carga los datos de las selecciones desde el archivo selecciones.csv (modo texto).
 *Dentro de la funcion se llama a parser_SeleccionFromText para poder cargar los datos de manera ordenada y
 *satisfactoria.
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return return=0 SALIO BIEN / return=-1 SALIO MAL
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
			printf("\n<<<<<<<<<< ARCHIVO DE SELECCIONES CARGADO EXITOSAMENTE >>>>>>>>> \n");
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


/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return return=0 SALIO BIEN / return=-1 SALIO MAL
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	FILE* pFile=fopen(path,"w");
	Seleccion* pSeleccion;
	char confederacion[30];
	int convocados;
	int id;
	int tam;
	char pais[30];
	tam=ll_len(pArrayListSeleccion);
	if(pArrayListSeleccion!=NULL && pFile!=NULL)
	{
		fprintf(pFile,"id,pais,confederacion,convocados\n");
		for(int i=0;i<tam;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			if(selec_getConfederacion(pSeleccion, confederacion)==0 &&
					selec_getConvocados(pSeleccion, &convocados)==0 &&
					selec_getId(pSeleccion, &id)==0 &&
					selec_getPais(pSeleccion, pais)==0)
			{
				fprintf(pFile,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
				retorno=0;
			}
		}
		fclose(pFile);
	}
	if(retorno==0)
	{
		printf("\n<<<<<<<<<< SELECCIONES GUARDADAS CORRECTAMENTE >>>>>>>>>>\n");
	}
    return retorno;
}
/// \fn int controller_Salir(LinkedList*, LinkedList*, LinkedList*, int)
/// \brief Verifica que se hayan realizado cambios y en tal caso ofrece guardarlos.Repregunta si esta seguro el usuario de que desea salir.
///
/// \param pArrayListSeleccion lista de selecciones.
/// \param pArrayListJugador lista de jugadores.
/// \param pArrayListJugadorOriginal lista de jugadores sin modificar.
/// \param idMax id maximo obtenido hasta el momento.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_Salir(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador ,LinkedList* pArrayListJugadorOriginal, int idMax)
{
	int retorno=-1;
	int jug_Flag=0;
	int opcion;
	if(pArrayListSeleccion!=NULL && pArrayListJugador!=NULL)
	{
		if(jug_verificarCambios(pArrayListJugador, pArrayListJugadorOriginal, &jug_Flag)==0)
		{
			if(jug_Flag==1)
			{
				ingresarIntConRango(&opcion, "\n<<<<<<<<<< SE DETECTARON CAMBIOS, PARA GUARDAR PRESIONE: 1, "
						"PARA SALIR SIN GUARDAR: 2 >>>>>>>>>>\n", "ERROR, Ingrese opcion valida.\n", 1, 2);
				if(opcion==1)
				{
					if(controller_guardarJugadoresModoTexto("jugadores.csv", pArrayListJugador)!=0 ||
					controller_guardarSeleccionesModoTexto("selecciones.csv", pArrayListSeleccion)!=0 ||
					controller_guardarMaxId("id.txt", idMax)!=0)
					{
						printf("\n<<<<<<<<<< ERROR AL GUARDAR ARCHIVOS >>>>>>>>>>\n");
					}
					else
					{
						printf("\n<<<<<<<<<< ARCHIVOS GUARDADOS EXITOSAMENTE >>>>>>>>>>\n");
					}
				}
			}
		}
		if(retorno==-1)
		{
			ingresarIntConRango(&opcion, "Para confirmar salida presione 2, para continuar operando presione 1.\n", "ERROR,Ingrese opcion valida", 1, 2);
			if(opcion==2)
			{
				retorno=0;
				ll_deleteLinkedList(pArrayListJugadorOriginal);
				ll_deleteLinkedList(pArrayListJugador);
				ll_deleteLinkedList(pArrayListSeleccion);
				printf("\n<<<<<<<<<< SALIDA EXITOSA >>>>>>>>>>\n");
			}
		}
	}
	return retorno;
}

