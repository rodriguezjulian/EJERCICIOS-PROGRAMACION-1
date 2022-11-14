#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "ingresos.h"
#include<string.h>

#include "salidas.h"

#include "Seleccion.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaJugadoresOriginal = ll_newLinkedList();//USADA PARA COMPARARLA CON LA POTENCIALMENTE MODIFICABLE

    LinkedList* listaSelecciones=ll_newLinkedList();

    LinkedList* listaJugadoresBinario=ll_newLinkedList();
    int idMax;
    char path[30];
    strcpy(path,"ARCHIVO_BINARIO.bin");
    int flagSalida=0;

    do{
    	mostrarMenuPrincipal();
    	ingresarIntConRango(&option, "INGRESE SEGUN QUIERA OPERAR", "ERROR, Ingrese opcion valida.\n", 1, 11);
        switch(option)
        {
            case 1:
            	if(ll_isEmpty(listaJugadores)==1 && ll_isEmpty(listaSelecciones)==1)
            	{
            		if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)==0 &&
            				controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadoresOriginal)==0)
            		{
            			printf("\n<<<<<<<<<< ARCHIVO DE JUGADORES CARGADO EXITOSAMENTE >>>>>>>>>>\n");
            			if(controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones)!=0)
            			{
            				printf("ERROR al cargar el archivo: selecciones.csv\n");
            			}
            		}
            		else
            		{
            			printf("ERROR al cargar el archivo: jugadores.csv\n");
            		}
            	}
            	else
            	{
            		printf("Los archivos ya han sido cargados.\n ");
            	}
            break;
            case 2:
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
            	{
            		if(controller_agregarJugador(listaJugadores, &idMax)!=0)
            		{
            			printf("\n<<<<<<<<<< ERROR AL LOGUEAR NUEVO JUGADOR>>>>>>>>>>\n");
            		}
            	}
            	else
            	{
            		printf("Debe operar la opcion 1 antes de poder dar de alta a nuevos jugadores.\n");
            	}
            break;
            case 3:
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
            	{
            		if(controller_editarJugador(listaJugadores,listaSelecciones)!=0)
            		{
            			printf("\n<<<<<<<<<< ERROR, AL EDITAR JUGADOR>>>>>>>>>>\n");
            		}
            	}
            	else
            	{
            		printf("Debe operar la opcion 1 antes de modificar el legajo de jugadores.\n ");
            	}
            break;
            case 4:
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
            	{
            		if(controller_removerJugador(listaJugadores,listaSelecciones)!=0)
            		{
            			printf("\n<<<<<<<<<< ERROR AL REMOVER JUGADOR >>>>>>>>>>\n");
            		}
            	}
            	else
            	{
            		printf("Debe operar la opcion 1 antes de dar de baja a jugadores.\n");
            	}
            break;
            case 5:
            	if(controller_listar(listaJugadores, listaSelecciones)!=0)
            	{
            		printf("<<<<<<<<<< ERROR, al listar.>>>>>>>>>\n");
            	}
            break;
            case 6:
            	if(controller_editarSeleccion(listaJugadores, listaSelecciones)!=0)
            	{
            		printf("<<<<<<<<<< ERROR al editar seleccion.>>>>>>>>>\n");
            	}
            break;
            case 7:
            	if(controller_ordenarJugadores(listaJugadores, listaSelecciones)!=0)
            	{
            		printf("<<<<<<<<<< ERROR al ordenar jugadores / listarlos. >>>>>>>>>\n");
            	}
            break;
            case 8:
            	if(controller_guardarJugadoresModoBinario(path, listaJugadores,listaSelecciones)!=0)
            	{
            		printf("<<<<<<<<<< ERROR AL INTENTAR CREAR ARCHIVO BINARIO >>>>>>>>>\n");
            	}
            break;
            case 9:
            	if(controller_cargarJugadoresDesdeBinario(path, listaJugadoresBinario,listaSelecciones)!=0)
            	{
            		printf("ERROR, al cargar archivo binario.\n");
            	}
            break;
            case 10:
            	if(controller_guardarJugadoresModoTexto("probando guardar jugadores.txt", listaJugadores)!=0 &&
            	controller_guardarSeleccionesModoTexto("prueba listas.txt", listaSelecciones)!=0 &&
            	controller_guardarMaxId("id.txt", idMax)!=0)
            	{
            		printf("\n<<<<<<<<<< ERROR AL GUARDAR ARCHIVOS >>>>>>>>>>\n");
            	}
            break;
            case 11:
            	if(controller_Salir(listaSelecciones, listaJugadores, listaJugadoresOriginal, idMax)==0)
				{
            		flagSalida=1;
				}
            break;
        }
    }while(flagSalida==0);

    return 0;
}

