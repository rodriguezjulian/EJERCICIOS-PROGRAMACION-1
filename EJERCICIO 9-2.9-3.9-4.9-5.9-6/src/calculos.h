/*
 * calculos.h
 *
 *  Created on: 14 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
int calcularPromedioArray(int tam, int* array, float *promedio);
void inicializarArray(int array[],int tam);
void inicializarArrayChar(char array[],int tam);
int calcularMaximoArray(int* array, int* valorMaximo);
int contarImparesDeArray(int* array,int tam);
int contarNegativosArray(int* array,int tam);
int sumarImparesDeArray(int array[],int tam);
int calcularMaximoArrayPar(int* array, int* valorMaximo);
int imprimirArrayInt(int* array,int tam, char* mensaje);
int imprimirArrayIntConMinimo(int* array,int tam, char* mensaje, int minimo);
int imprimirIntEnPosicionImpar( int* array, int tam, char* mensaje);
int calcularPromedioPositivosArray(int tam, int* array, float* promedio,int contadorPositivos);
int contarPositivosArray(int* array,int tam);
int calcularMinimoArray(int* array, int* valorMinimo, int tam);
int ordenarArrayAscendente(int* array, int tam);
int imprimirArrayIntSinCero(int* array,int tam, char* mensaje);
int ordenarArrayDescendente(int* array, int tam);
int limitarContador(int* contador ,int maxContar,char* mensaje);
float calcularPromedio(int numeroA, int numeroB);

#endif /* CALCULOS_H_ */
