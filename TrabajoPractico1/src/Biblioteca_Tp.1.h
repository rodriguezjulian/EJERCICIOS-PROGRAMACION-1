/*
 * Biblioteca_Tp.1.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef BIBLIOTECA_TP_1_H_
#define BIBLIOTECA_TP_1_H_

/**
 * \fn int validarEntradaParaOpcion3(float, float, float, int)
 * \brief Esta funcion toma como parametros el valor que contienen las variables hospedaje,
 * comida y transporte, y contador total de jugadores, de esta manera sabe que el usuario opero estas opciones por
 * lo que se pueden realizar calculos.
 *
 * \param hospedaje, en esta variable se contiene el costo cargado por el usuario.
 * \param comida en, esta variable se contiene el costo cargado por el usuario.
 * \param transporte, en esta variable se contiene el costo cargado por el usuario.
 * \param contadorJugadores, apenas el usuario cargue al primer jugador, el contador comenzara a acumular ingresos.
 * \return,todo bien un 0 / todo mal -1.
 */
int validarEntradaParaOpcion3(float hospedaje,float comida,float transporte,int contadorJugadores);

/**
 * \fn void informarResultados(int, float, float, float, float, float, float, float, float, float)
 * \brief Esta funcion primero verifica que este accionada la bandera de la opcion 3 para ejecutarse, de lo contrario,
 * mostrara un mensaje de error. Una vez realizada la verificacion pasa a mostrar los resultados, en el caso del costo de
 * mantenimiento, una vez verificado el promedio se toma en cuenta el valor de la variable diferenciaCostoMantenimiento
 * para mostrarlo de forma adecuada segun corresponda.
 *
 * \param flag, una vez que la opcion 3 logra realizar los calculos este flag cambia de valor para asi dar lugar a imprimir todos los calculos.
 * \param promedioAfc, esta variable contiene un valor calculado en la opcion numero 3 desde la funcion ejecutarCalculosPromedios.
 * \param promedioCaf, esta variable contiene un valor calculado en la opcion numero 3 desde la funcion ejecutarCalculosPromedios.
 * \param promedioConcacaf, esta variable contiene un valor calculado en la opcion numero 3 desde la funcion ejecutarCalculosPromedios.
 * \param promedioConmebol, esta variable contiene un valor calculado en la opcion numero 3 desde la funcion ejecutarCalculosPromedios.
 * \param promedioUefa, esta variable contiene un valor calculado en la opcion numero 3 desde la funcion ejecutarCalculosPromedios.
 * \param promedioOfc, esta variable contiene un valor calculado en la opcion numero 3 desde la funcion ejecutarCalculosPromedios.
 * \param costoMantenimiento, contiene un valor calculado en la opcion 3 resultante de la suma de todos los costos ingresados.
 * \param diferenciaCostoMantenimiento, en caso de ser la mayoria de jugadores provenientes de UEFA, se mostrara esta variable, caso contrario NO.
 * \param costoMantenimientoAumentado, en caso de ser la mayoria de jugadores provenientes de UEFA, se mostrara esta variable, caso contrario NO.
 */
void informarResultados(int flag, float promedioAfc,float promedioCaf,float promedioConcacaf,float promedioConmebol,
		float promedioUefa, float promedioOfc, float costoMantenimiento,float diferenciaCostoMantenimiento,
		float costoMantenimientoAumentado);
/**
 * \fn void ejecutarCalculosPromedios(int, int, float*, int, float*, int, float*, int, float*, int, float*, int, float*)
 * \brief En esta funcion se calculan los promedios de jugadores provenientes de cada confederacion, se utiliza la funcion
 * calcularPromedio de la biblioteca calculos.c
 * Basicamente el calculo ejecutado es el siguiente: contadorDeConfederacion/contadoresDeJugadores
 *
 * \param contadorJugadores, surge de acumular cada ingreso de jugador, independientemente de su confederacion.
 * \param contadorAfc, sumatoria de jugadores para una confederacion especifica.
 * \param promedioAfc, en esta variable se guardara el valor resultante de contadorDeConfederacion/contadoresDeJugadores.
 * \param contadorCaf, sumatoria de jugadores para una confederacion especifica.
 * \param promedioCaf,en esta variable se guardara el valor resultante de contadorDeConfederacion/contadoresDeJugadores.
 * \param contadorConcacaf, sumatoria de jugadores para una confederacion especifica.
 * \param promedioConcacaf, en esta variable se guardara el valor resultante de contadorDeConfederacion/contadoresDeJugadores.
 * \param contadorConmebol, sumatoria de jugadores para una confederacion especifica.
 * \param promedioConmebol, en esta variable se guardara el valor resultante de contadorDeConfederacion/contadoresDeJugadores.
 * \param contadorUefa, sumatoria de jugadores para una confederacion especifica.
 * \param promedioUefa, en esta variable se guardara el valor resultante de contadorDeConfederacion/contadoresDeJugadores.
 * \param contadorOfc, sumatoria de jugadores para una confederacion especifica.
 * \param promedioOfc, en esta variable se guardara el valor resultante de contadorDeConfederacion/contadoresDeJugadores.
 */
void ejecutarCalculosPromedios(int contadorJugadores,int contadorAfc,float*promedioAfc, int contadorCaf,float* promedioCaf,
		int contadorConcacaf,float*promedioConcacaf,int contadorConmebol,float*promedioConmebol,int contadorUefa,
		float*promedioUefa,int contadorOfc,float*promedioOfc);
/**
 * \fn void ejecutarSubMenuConfederaciones(int, int*, int*, int*, int*, int*, int*, int*)
 * \brief Esta funcion se encargara de mostrar un menu de opciones para luego tambien operar contadores segun opcion elegida.
 * Esta funcion se ejecutara o no dependiendo del retorno de la funcion limitarContador previamente operada.
 * \param flag, variable de control, se debe limitar el ingreso de jugadores a una cantidad determinada segun posicion.
 * \param contadorAfc,sumatoria de jugadores para una confederacion especifica.
 * \param contadorCaf,sumatoria de jugadores para una confederacion especifica.
 * \param contadorConcacaf,sumatoria de jugadores para una confederacion especifica.
 * \param contadorConmebol,sumatoria de jugadores para una confederacion especifica.
 * \param contadorUefa,sumatoria de jugadores para una confederacion especifica.
 * \param contadorOfc,sumatoria de jugadores para una confederacion especifica.
 * \param contadorJugadores,surge de acumular cada ingreso de jugador, independientemente de su confederacion.
 */
void ejecutarSubMenuConfederaciones(int flag,int* contadorAfc,int* contadorCaf,int*contadorConcacaf,
		int* contadorConmebol,int* contadorUefa,int*contadorOfc,int* contadorJugadores);
/**
 * \fn void mostrarMenuPrincipal(float, float, float, int, int, int, int)
 * \brief Accionara la impresion de los costos y posiciones cargadas hasta el momento.
 *
 * \param hospedaje, en esta variable se contiene el costo cargado por el usuario, sino tambien se la podra encontrar inicializada en 0.
 * \param comida, en esta variable se contiene el costo cargado por el usuario, sino tambien se la podra encontrar inicializada en 0.
 * \param transporte, en esta variable se contiene el costo cargado por el usuario, sino tambien se la podra encontrar inicializada en 0.
 * \param contadorArqueros,sumatoria de jugadores para una confederacion especifica,sino tambien se la podra encontrar inicializada en 0.
 * \param contadorDefensores,sumatoria de jugadores para una confederacion especifica,sino tambien se la podra encontrar inicializada en 0.
 * \param contadorMediocampistas,sumatoria de jugadores para una confederacion especifica,sino tambien se la podra encontrar inicializada en 0.
 * \param contadorDelanteros,sumatoria de jugadores para una confederacion especifica,sino tambien se la podra encontrar inicializada en 0.
 */
void mostrarMenuPrincipal(float hospedaje,float comida,float transporte,
		int contadorArqueros,int contadorDefensores,int contadorMediocampistas,int contadorDelanteros);
/**
 * \fn void mostrarMensajeSalida(int)
 * \brief Esta funcion recibe un entero que representa la opcion cargada por el usuario para luego mostrar un mensaje de salida.
 *
 * \param opcion, esta variable se comparara con la opcion 5, en caso de ser verdadero se mostrara el mensaje, algo muy util al operar la
 * opcion 4 y preguntarle al usuario si decide continuar operando o simplemente salir del programa
 */
void mostrarMensajeSalida(int opcion);

#endif /* BIBLIOTECA_TP_1_H_ */
