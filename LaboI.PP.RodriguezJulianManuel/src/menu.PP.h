/*
 * menu.PP.h
 *
 *  Created on: 13 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef MENU_PP_H_
#define MENU_PP_H_
#include "transporte.h"
#include "hojaDeRuta.h"


/// \fn void mostrarOpciones(void)
/// \brief MOSTRAR OPCIONES DEL MENU PRINCIPAL
///
void mostrarOpciones(void);

/// \fn int ejecutarMenuInformes(int, eTransporte*, eHojaDeRuta*, eTipo*, int, int*, int)
/// \brief Se listara la lista de opciones para el submenu, se podra elegir y operar la opcion que
/// el usuario desee.
///
/// \param contador ,utilizado para validar la entrada al sub menu (debe existir al menos 1 transporte).
/// \param transporte ,array de estructura utilizado en el desarrollo de las opciones.
/// \param hojaDeRuta ,array de estructura utilizado en el desarrollo de las opciones.
/// \param tipo ,array de estructura utilizado en el desarrollo de las opciones.
/// \param contadorDeHojas ,utilizado para validar el ingreso a las opciones 2,3,4.
/// \param volverMenuPrincipal ,si el usuario desea puede salir del sub menu e ir al principal
/// \param tam ,utilizado para iteraciones.
/// \return
int ejecutarMenuInformes (int contador, eTransporte* transporte,eHojaDeRuta* hojaDeRuta, eTipo* tipo, int contadorDeHojas,int* volverMenuPrincipal, int tam);

#endif /* MENU_PP_H_ */
