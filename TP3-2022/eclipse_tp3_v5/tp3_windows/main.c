#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "ingresos.h"
 #include<string.h>

#include "seleccion.h"
int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones=ll_newLinkedList();

    char path[30];

	//ingresarIntConRango(&option, "INGRESE SEGUN QUIERA OPERAR", "ERROR, Ingrese opcion valida", 1, 2);
    do{

    	printf("+==================================================+\n|%*s|\n%s",
    			-50,"                MENU PRINCIPAL","+==================================================+\n");

    	printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n%s\n",-50,"1.CARGA DE ARCHIVOS",
    			-50,"2.ALTA DE JUGADOR",-51,"3.MODIFICACIÓN DE JUGADOR",-50,"4.BAJA DE JUGADOR",-50,"5.LISTADOS",
    			-50,"6.CONVOCAR JUGADORES",-50,"7.ORDENAR Y LISTAR",-50,"8.GENERAR ARCHIVO BINARIO",-50,"9.CARGAR ARCHIVO BINARIO",
    			-50,"10.GUARDAR ARCHIVOS .CSV",-50,"11.SALIR","+==================================================+\n");


    	ingresarIntConRango(&option, "INGRESE SEGUN QUIERA OPERAR", "ERROR, Ingrese opcion valida", 1, 10);
        switch(option)
        {
            case 1:

            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);
            break;
            case 2:
            	controller_agregarJugador(listaJugadores);

            break;
            case 3:
            	controller_editarJugador(listaJugadores);
            break;
            case 4:
            	controller_removerJugador(listaJugadores);
            break;
            case 5:
            	operara_Menu_Opcion5(listaJugadores, listaSelecciones);
            	//PONER EN MENU LOS LISTADOS

            break;
            case 6:
            	operara_Menu_Opcion6(listaJugadores, listaSelecciones);

            break;
            case 7:
            	controller_ordenarJugadores(listaJugadores, listaSelecciones);

            break;
            case 8:

            	controller_guardarJugadoresModoBinario(path, listaJugadores);
            	//printf("CONFEDERACION %s",path);
            break;
        }
    }while(option != 10);

    return 0;
}

