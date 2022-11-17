/*
 * ingresos.h
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef INGRESOS_H_
#define INGRESOS_H_
int ingresarIntConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo);
int ingresarCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError);
int verificarCaracterSN(char letra);
int ingresarIntConMinimo(int* resultado, char* mensaje, char* mensajeError, int minimo);
int ingreseNombreArchivo(char* mensaje, char* nombreIngresado);
#endif /* INGRESOS_H_ */
