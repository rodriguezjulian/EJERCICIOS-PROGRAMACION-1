/*
 * transporte.h
 *
 *  Created on: 13 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

typedef struct
{
	int idTransporte;
	char descripcion[30];
	float pesoCarga;
	int cantidadBultos;
	int tipoId;
	int isEmpty;
}eTransporte;

typedef struct
{
	int idTipo;//comienza en 1000
	char descripcion[31];
}eTipo;
//

//int loguearTransporte(int* idTransporte, eTransporte* auxiliar , int* contador);
int loguearTransporte(int* idTransporte, eTransporte* auxiliar , int* contador, eTipo* tipo);
int inicializarIsEmpty(eTransporte* transporte, int tam, int estado);
int bajaTransporte(eTransporte* transporte,int *contador);
int modificartransporte(eTransporte* transporte,int contador);
int listarTransportes(eTransporte* transporte, int tam, int contador);
int ordenarTransportes(eTransporte* transporte, int tam);

void listarTipos(eTipo* tipo,int tam);
int ingresarIdTipo(eTransporte* transporte, eTipo* tipo);

#endif /* TRANSPORTE_H_ */
