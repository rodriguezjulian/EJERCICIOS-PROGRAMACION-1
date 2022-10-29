/*
 * ingresos.h
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef INGRESOS_H_
#define INGRESOS_H_
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

/// \fn int ingresarOpcionAlfabeticaMayusc(char*, char*, char*, int, int)
/// \brief Pido ingresar un caracter, el cual sera validado por el rango que le de con ayuda del codigo ASCII
///
/// \param resultado ,se pasara por referencia el caracter ingresado una vez validado.
/// \param mensaje ,mensaje utilizado para solicitar el caracter.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un caracter fuera de rango.
/// \param minimo ,limite inferior del rango.
/// \param maximo ,limite superior del rango.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarOpcionAlfabeticaMayusc(char* resultado,char* mensaje,char* mensajeError, int minimo ,int maximo );

/// \fn int ingresarNumerosConRango(int*, char*, char*, int, int, int)
/// \brief Ingresar un numero entero comprendido dentro de un
/// rango especificado al momento de llamar a la funcion, teniendo en cuenta un determinado numero de reintentos.
/// \param resultado ,se pasara por referencia el numero ingresado una vez validado.
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero fuera de rango.
/// \param minimo ,limite inferior del rango.
/// \param maximo ,limite superior del rango.
/// \param reintentos ,cantidad de reintentos que tendra el usuario al estar operando.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarNumConRangoYReintentos(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// \fn int ingresarFloat2(float*, char*)
/// \brief Ingresar un numero flotante.
///
/// \param resultado ,se pasara por referencia el numero ingresado una vez validado a esta variable.
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarFloat2(float* resultado,char* mensaje);

/// \fn int ingresarFloatConMinimo(float*, char*, char*, int)
/// \brief Ingresar un numero flotante teniendo en cuenta un minimo (rango inferior)
///
/// \param resultado ,se pasara por referencia el numero ingresado una vez validado a esta variable.
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero por debajo del minimo.
/// \param minimo ,usado como referencia, su valor se utilizara como rango inferior.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarFloatConMinimo(float* resultado, char* mensaje,char*mensajeError,int minimo);

/// \fn int ingresarIntConMensajeMin(int*, char*, char*, int)
/// \brief Ingresar un numero entero teniendo en cuenta un minimo (rango inferior)
///
/// \param resultado ,se pasara por referencia el numero ingresado una vez validado a esta variable.
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero por debajo del minimo.
/// \param minimo ,usado como referencia, su valor se utilizara como rango inferior.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarIntConMensajeMin(int* resultado,char* mensaje, char* mensajeError, int minimo);

/// \fn int ingresarNumIntConRango(int*, char*, char*, int, int)
/// \brief Ingresar un numero entero comprendido dentro de un
/// rango especificado al momento de llamar a la funcion.
///
/// \param resultado ,se pasara por referencia el numero ingresado una vez validado a esta variable.
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero por debajo del minimo.
/// \param minimo ,limite inferior del rango.
/// \param maximo ,limite superior del rango.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarIntConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo);



/// \fn int confirmarSalida(void)
/// \brief Cuando el usuario ingresa una opcion para dejar de operar un programa,
/// esta funcion verifica que es lo que realmente quiere y no que se equivoco.
/// \return return en 0 cuando se confirma la salida del usuario.
int confirmarSalida(void);

/// \fn int ingresarFecha(eFecha*)
/// \brief Ingresar una fecha, la misma se guardara dentro de una estructura de tipo eFecha
///
/// \param resultado , el resultado se pasara por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarFecha(eFecha* resultado);

/// \fn int ingresarCadenaCaracteres(int, char*, char*, char*)
/// \brief Ingresar una cadena de caracteres.
///
/// \param tam ,tamaño de la cadena
/// \param textoIngresado ,el resultado se pasara por referencia.
/// \param mensaje ,mensaje utilizado para solicitar la cadena.
/// \param mensajeError ,mensaje de error por si el usuario excede la cantidad de caracteres.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError);


int ingresarShortConRango(short* resultado, char* mensaje, char* mensajeError, short minimo, short maximo);
int verificarCaracterSN(char letra);

#endif /* INGRESOS_H_ */
