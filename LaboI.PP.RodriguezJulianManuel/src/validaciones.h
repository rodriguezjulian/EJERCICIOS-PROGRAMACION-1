/*
 * validaciones.h
 *
 *  Created on: 20 oct. 2022
 *      Author: Julian Rodriguez
 */
#include "transporte.h"
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// \fn int verificarCaracterSN(char)
/// \brief Verifica si se ingreso una letra mayuscula S || N, sirve utilizar el retorno de esta funcion para iteraciones.
///
/// \param letra , letra recibida a evaluar.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int verificarCaracterSN(char letra);

/// \fn int verificarExistenciaDeTipoDeTransporte(eTransporte*, int, int)
/// \brief Se recibe como parametro el tipo a verificar y se empieza a comparar con el campo tipo de la estructura de tipo eTransporte.
///
/// \param transporte , estructura a recorrer (campo del tipo unicamente).
/// \param tipoBuscado ,tipo a verificar.
/// \param tam ,utilizado para establecer las iteraciones.
/// \return return=0 SI HAY COINCIDENCIA || return=-1 si NO hay coincidencia (es decir se verifica que no existe un transporte de ese tipo).
int verificarExistenciaDeTipoDeTransporte(eTransporte* transporte, int tipoBuscado, int tam);

#endif /* VALIDACIONES_H_ */
