/*
 * hojaDeRuta.j.h
 *
 *  Created on: 13 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef HOJADERUTA_H_
#define HOJADERUTA_H_





typedef struct
{
	int idHoja;//comienza en 20.000
	int transporteId;//validar existencia
	float precioViaje;
	float kmTotales;
	eFecha fecha;
	int isEmpty;

}eHojaDeRuta;


int inicializarIsEmptyHojaDeRuta(eHojaDeRuta* hojaDeRuta, int tam, int estado);
int loguearHojaDeRuta(eTransporte* transporte,eHojaDeRuta* hojaAuxiliar, int* idHoja, int contador, int* contadorDeHojas);

int listarHojasDeRuta(eHojaDeRuta* hojaDeRuta, int tam,eTransporte* transporte ,int contador);
int listarHojasDeRutaPorFecha(eHojaDeRuta* hojaDeRuta, eTransporte* transporte,int tam, int contadorDeHojas);




#endif /* HOJADERUTA_H_ */
