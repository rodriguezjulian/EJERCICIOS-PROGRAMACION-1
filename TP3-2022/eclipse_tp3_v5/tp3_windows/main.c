#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "ingresos.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaConfederaciones=ll_newLinkedList();

	//ingresarIntConRango(&option, "INGRESE SEGUN QUIERA OPERAR", "ERROR, Ingrese opcion valida", 1, 2);
    do{

    	printf("+==================================================+\n|%*s|\n%s",
    			-50,"                MENU PRINCIPAL","+==================================================+\n");

    	printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n%s\n",-50,"1.CARGA DE ARCHIVOS",
    			-50,"2.ALTA DE JUGADOR",-51,"3.MODIFICACIÓN DE JUGADOR",-50,"4.BAJA DE JUGADOR",-50,"5.LISTADOS",
    			-50,"6.CONVOCAR JUGADORES",-50,"7.ORDENAR Y LISTAR",-50,"8.GENERAR ARCHIVO BINARIO",-50,"9.CARGAR ARCHIVO BINARIO",
    			-50,"10.GUARDAR ARCHIVOS .CSV",-50,"11.SALIR","+==================================================+\n");


    	ingresarIntConRango(&option, "INGRESE SEGUN QUIERA OPERAR", "ERROR, Ingrese opcion valida", 1, 5);
        switch(option)
        {
            case 1:

            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaConfederaciones);
            break;
            case 2:
            	controller_agregarJugador(listaJugadores);

            break;
            case 3:
            	controller_editarJugador(listaJugadores);
            break;
            case 4:

            break;
            case 5:
            	controller_listarJugadores(listaJugadores);
            	controller_listarSelecciones(listaConfederaciones);
            break;
        }
    }while(option != 10);

    return 0;
}

