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
int calcularMaximoArray(int* array, int* valorMaximo);
int contarImparesDeArray(int* array,int tam);
int contarNegativosArray(int* array,int tam);
int sumarImparesDeArray(int array[],int tam);
int calcularMaximoArrayPar(int* array, int* valorMaximo);
int imprimirArrayInt(int* array,int tam, char* mensaje);
int imprimirArrayIntConMinimo(int* array,int tam, char* mensaje, int minimo);
int imprimirIntEnPosicionImpar( int* array, int tam, char* mensaje);
#endif /* CALCULOS_H_ */
