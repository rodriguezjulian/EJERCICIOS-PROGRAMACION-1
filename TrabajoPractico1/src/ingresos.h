/*
 * ingresos.h
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef INGRESOS_H_
#define INGRESOS_H_


float ingresarFloat(void);
int ingresarInt(void);
int ingresarNumerosConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int ingresarNumeroDistintoCero(int* array,int reintentos,int *resultado);
int ingresarNumerosConRangoMenosCero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int ingresarInt2(int* resultado);
int ingresarFloat2(float* resultado,char* mensaje);
int ingresarFloatConMinimo(float* resultado, char* mensaje,char*mensajeError,int minimo);
int ingresarNumerosConRangoV1(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo);
int ingresarIntConMensaje(int* resultado,char* mensaje);
#endif /* INGRESOS_H_ */
