/*
 * Controller.h
 *
 *  Created on: 17 nov. 2022
 *      Author: Julian Rodriguez
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controllerCargarArchivoDesdeTexto(LinkedList* listaDeCompras);
//int controller_cargarComprasDesdeTexto(char* path , LinkedList* pArrayListaCompra);
//int controllerImprimirLista(LinkedList* listaDeCompras);
int controller_listarCompras(LinkedList* pArrayListaCompra);
int jug_imprimirJugadores(LinkedList* pArrayListJugador);

#endif /* CONTROLLER_H_ */
