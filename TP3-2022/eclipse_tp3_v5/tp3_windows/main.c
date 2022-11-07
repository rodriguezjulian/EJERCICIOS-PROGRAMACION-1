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
	printf("+==================================================+\n|%*s|\n%s",
			-50,"                MENU PRINCIPAL","+==================================================+\n");

	printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n%s\n",-50,"1.CARGA DE ARCHIVOS",
			-50,"2.ALTA DE JUGADOR",-51,"3.MODIFICACIÓN DE JUGADOR",-50,"4.BAJA DE JUGADOR",-50,"5.LISTADOS",
			-50,"6.CONVOCAR JUGADORES",-50,"7.ORDENAR Y LISTAR",-50,"8.GENERAR ARCHIVO BINARIO",-50,"9.CARGAR ARCHIVO BINARIO",
			-50,"10.GUARDAR ARCHIVOS .CSV",-50,"11.SALIR","+==================================================+\n");
	//ingresarIntConRango(&option, "INGRESE SEGUN QUIERA OPERAR", "ERROR, Ingrese opcion valida", 1, 2);
    do{
    	ingresarIntConRango(&option, "INGRESE SEGUN QUIERA OPERAR", "ERROR, Ingrese opcion valida", 1, 5);
        switch(option)
        {
            case 1:

            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaConfederaciones);
            	//controller_listarSelecciones(listaJugadores);

            	/*ll_sort(listaJugadores, jug_OrdenarPorNacionalidad, 1);
            	for(int i=0;i<370;i++)
            	{
            		auxiliar=ll_get(listaJugadores, i);

            		printf("%s\n",(*(auxiliar+i)).nombreCompleto);

            	}
			controller_listarSelecciones

            	ll_sort(listaJugadores, jug_OrdenarPorNacionalidad, 1);*/

            break;
            case 2:

            	controller_listarSelecciones(listaConfederaciones);
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            	controller_listarSelecciones(listaConfederaciones);
            break;
        }
    }while(option != 10);

    return 0;
}

