/*
 * nexo.h
 *
 *  Created on: 29 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef NEXO_H_
#define NEXO_H_

/// \fn void inicializarArrayFloat(float*, int)
/// \brief Asignar valor 0 por referencia a todas las posiciones de un array tipo float.
///
/// \param array , array a inicializar.
/// \param tam , tamanio del array.
void inicializarArrayFloat(float* array,int tam);

/// \fn void inicializarArray(int*, int)
/// \brief Asignar valor 0 por referencia a todas las posiciones de un array tipo int,
///
/// \param array , array a inicializar.
/// \param tam , tamanio del array.
void inicializarArray(int* array,int tam);

/// \fn float calcPorcentaje(int, int)
/// \brief Se recibe como parametro un total que representa el 100% y el parcial.
/// Se retornara el porcentaje que representa el valor parcial respecto al total.
///
/// \param total
/// \param parcial
/// \return resultado
float calcPorcentaje(int total, int parcial);

/// \fn float calcularPromedio(float, int)
/// \brief Recibe por parametro 2 numeros, el numero A sera dividido por el numero B (cantidad de casos).
///
/// \param numeroA , numero que sera divido (total)
/// \param numeroB cantidad de casos
/// \return resultado
float calcularPromedio(float numeroA, int numeroB);

/// \fn int verificarCaracterSN(char)
/// \brief Verifica si se ingreso una letra mayuscula S || N, sirve utilizar el retorno de esta funcion para iteraciones.
///
/// \param letra , letra recibida a evaluar.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int verificarCaracterSN(char letra);
#endif /* NEXO_H_ */
