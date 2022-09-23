/*
 * tp.1.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef BIBLIOTECA_TP_1_H_
#define BIBLIOTECA_TP_1_H_


int validarEntradaParaOpcion3(float hospedaje,float comida,float transporte,int contadorJugadores);

void informarResultados(int flag, float promedioAfc,float promedioCaf,float promedioConcacaf,float promedioConmebol,
		float promedioUefa, float promedioOfc, float costoMantenimiento,float diferenciaCostoMantenimiento,
		float costoMantenimientoAumentado);


/**
 * \fn void ejecutarCalculoPromedio(int, int, float)
 * \brief
 *
 * \param contadorAfc
 * \param contadorJugadores
 * \param promedioAfc
 */
void ejecutarCalculoPromedio(int contadorAfc,int contadorJugadores,float promedioAfc);


void ejecutarCalculosPromedios(int contadorJugadores,int contadorAfc,float*promedioAfc, int contadorCaf,float* promedioCaf,
		int contadorConcacaf,float*promedioConcacaf,int contadorConmebol,float*promedioConmebol,int contadorUefa,
		float*promedioUefa,int contadorOfc,float*promedioOfc);

void ejecutarSubMenuConfederaciones(int flag,int* contadorAfc,int* contadorCaf,int*contadorConcacaf,
		int* contadorConmebol,int* contadorUefa,int*contadorOfc,int* contadorJugadores);

void mostrarMenuPrincipal(float hospedaje,float comida,float transporte,
		int contadorArqueros,int contadorDefensores,int contadorMediocampistas,int contadorDelanteros);

void mostrarMensajeSalida(int opcion);

#endif /* BIBLIOTECA_TP_1_H_ */
