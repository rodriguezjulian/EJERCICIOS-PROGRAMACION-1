/*
 * ingresos.h
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef INGRESOS_H_
#define INGRESOS_H_
/**
 * \fn int ingresarNumerosConRango(int*, char*, char*, int, int, int)
 * \brief Esta funcion permitira el ingreso de un numero entero, teniendo en cuenta un rango y cantidad de reintentos determinados.
 *
 * \param resultado, Una vez verificado el numero ingresado, se dara valor a la variable mediante un puntero (pasaje por referencia).
 * \param mensaje ,redaccion del usuario que opere la funcion.
 * \param mensajeError ,redaccion del usuario para cuando se de un ERROR en el ingreso del entero.
 * \param minimo , minimo numero a cargar.
 * \param maximo, maximo numero a cargar.
 * \param reintentos, cantidad de reintentos.
 * \return , todo bien=0 , todo mal=-1.
 */
int ingresarNumerosConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/**
 * \fn int ingresarInt2(int*)
 * \brief	Esta funcion nos permite ingresar un numero entero.
 *
 * \param resultado, el numero cargado por el usuario se guardara en esta variable (pasaje por referencia)
 * \return ,todo bien=0 , todo mal=-1.
 */
int ingresarInt2(int* resultado);
/**
 * \fn int ingresarFloat2(float*, char*)
 * \brief Esta funcion nos permite ingresar un numero flotante.
 *
 * \param resultado, el numero cargado por el usuario se guardara en esta variable (pasaje por referencia)
 * \param mensaje , redaccion del usuario que opere la funcion.
 * \return , todo bien=0 , todo mal=-1.
 */
int ingresarFloat2(float* resultado,char* mensaje);
/**
 * \fn int ingresarFloatConMinimo(float*, char*, char*, int)
 * \brief Esta funcion permite el ingreso del flotante agregando que habra un minimo, por ejemplo el ingreso de
 * un flotante mayor o igual a 10.5.
 *
 * \param resultado, el numero cargado por el usuario se guardara en esta variable (pasaje por referencia).
 * \param mensaje , redaccion del usuario que opere la variable.
 * \param mensajeError ,redaccion del usuario para cuando se de un ERROR en el ingreso del flotante.
 * \param minimo, numero minimo a cargar
 * \return , todo bien=0 , todo mal=-1.
 */
int ingresarFloatConMinimo(float* resultado, char* mensaje,char*mensajeError,int minimo);
/**
 * \fn int ingresarNumerosConRangoV1(int*, char*, char*, int, int)
 * \brief Esta funcion permitira el ingreso de un numero entero, teniendo en cuenta un rango.
 *
 * \param resultado , el numero cargado por el usuario se guardara en esta variable (pasaje por referencia).
 * \param mensaje , redaccion del usuario que opere la funcion.
 * \param mensajeError ,redaccion del usuario para cuando se de un ERROR en el ingreso del entero.
 * \param minimo , minimo numero a cargar.
 * \param maximo , maximo numero a cargar.
 * \return , todo bien=0 , todo mal=-1.
 */
int ingresarNumerosConRangoV1(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo);
/**
 * \fn int ingresarIntConMensaje(int*, char*)
 * \brief Esta funcion permite el ingreso de un numero entero, al hacerlo se imprimira un mensaje redactado por el usuario
 * y pasado como parametro.
 *
 * \param resultado , el numero cargado por el usuario se guardara en esta variable (pasaje por referencia).
 * \param mensaje  , redaccion del usuario que opere la funcion.
 * \return , todo bien=0 , todo mal=-1.
 */
int ingresarIntConMensaje(int* resultado,char* mensaje);
#endif /* INGRESOS_H_ */
