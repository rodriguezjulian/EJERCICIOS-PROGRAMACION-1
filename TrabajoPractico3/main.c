#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();

    puts("funciona ok");

    do{
        switch(option)
        {
            case 1:
            	//controller_cargarJugadoresDesdeTexto("C:\\Users\\Julian Rodriguez\\Desktop\\PROGRAMACION 1\\EJERCICIO 14-2.csv",listaJugadores);

                break;
        }
    }while(option != 10);

    return 0;
}

