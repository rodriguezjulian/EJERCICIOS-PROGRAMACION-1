#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "ingresos.h"
#include<string.h>

#include "Seleccion.h"
void mostrarMenuPrincipal();
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

    do{

    	mostrarMenuPrincipal();
    	ingresarIntConRango(&option, "INGRESE SEGUN QUIERA OPERAR", "ERROR, Ingrese opcion valida.\n", 1, 11);
        switch(option)
        {
            case 1:
            	if(ll_isEmpty(listaJugadores)==1 && ll_isEmpty(listaSelecciones)==1)
            	{
            		if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)!=0 &&
            				controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadoresOriginal)!=0)
            		{
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
            	controller_cargarJugadoresDesdeBinario(path, listaJugadoresBinario,listaSelecciones);
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
            	controller_Salir(listaSelecciones, listaJugadores, listaJugadoresOriginal, idMax);
            break;
        }
    }while(option != 10);

    return 0;
}
void mostrarMenuPrincipal()
{
	printf("+==================================================+\n|%*s|\n%s",
			-50,"                MENU PRINCIPAL","+==================================================+\n");

	printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n%s\n",-50,"1.CARGA DE ARCHIVOS",
			-50,"2.ALTA DE JUGADOR",-51,"3.MODIFICACIÓN DE JUGADOR",-50,"4.BAJA DE JUGADOR",-50,"5.LISTADOS",
			-50,"6.CONVOCAR JUGADORES",-50,"7.ORDENAR Y LISTAR",-50,"8.GENERAR ARCHIVO BINARIO",-50,"9.CARGAR ARCHIVO BINARIO",
			-50,"10.GUARDAR ARCHIVOS .CSV",-50,"11.SALIR","+==================================================+\n");
}
