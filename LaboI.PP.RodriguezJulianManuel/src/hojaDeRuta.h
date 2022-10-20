/*
 * hojaDeRuta.j.h
 *
 *  Created on: 13 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef HOJADERUTA_H_
#define HOJADERUTA_H_
#include "ingresos.h"




typedef struct
{
	int idHoja;//comienza en 20.000
	int transporteId;//validar existencia
	float precioViaje;
	float kmTotales;
	eFecha fecha;
	int isEmpty;

}eHojaDeRuta;

/// \fn int inicializarIsEmptyHojaDeRuta(eHojaDeRuta*, int, int)
/// \brief Dara valor al campo IsEmpty de una estrucutura de tipo eHojaDeRuta. El mismo se interpretara como VACIO 1 - OCUPADO 0
///
/// \param hojaDeRuta ,estructura sobre la que se operara
/// \param tam ,tamanio del array de estructura.
/// \param estado , estado que el usuario desea darle al campo isEmpty.
/// \return
int inicializarIsEmptyHojaDeRuta(eHojaDeRuta* hojaDeRuta, int tam, int estado);

/// \fn int loguearHojaDeRuta(eTransporte*, eHojaDeRuta*, int*, int, int*)
/// \brief Ingresar hoja de ruta, es decir, ingresar transporte a cargo, precio del viaje, kilometros totales,
/// fecha, el ID sera autoincremental a partir de 20.000.
///
/// \param transporte , utilizado para listar transportes y que usuario pueda elegir viendo los que existen y
/// utilizado para corrobar si el usuario cargo un ID valido.
/// \param hojaAuxiliar ,se guardaran los datos en esta estructura auxiliar para luego en el main pasar los valores al array de hojas de ruta.
/// \param idHoja ,al ser el id autoincremental, ya se recibe con un valor de 19.999 para que el primero sea 20.000.
/// \param contador ,utilizado para listar transportes.
/// \param contadorDeHojas ,contador que servira como validacion en otras funciones.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int loguearHojaDeRuta(eTransporte* transporte,eHojaDeRuta* hojaAuxiliar, int* idHoja, int contador, int* contadorDeHojas);

/// \fn int asignarDescripcionTransporteConId(eTransporte*, int, int, char*)
/// \brief Recibo un ID como referencia, con el voy a la direccion de memoria donde esta la descripcion y la copio a una variable
/// que luego sera mostrada en otras funciones.
/// Con esta funcion me facilite las relaciones entre estructuras.
///
/// \param transporte ,de donde sacare la descripcion
/// \param transporteId ,el id que recibo el cual me serviria como referencia para buscar la descripcion.
/// \param descripcion , devolvere por referencia la descripcion que luego sera mostrada.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int asignarDescripcionTransporteConId(eTransporte* transporte,int transporteId, int tam, char* descripcion);

/// \fn int listarHojasDeRuta(eHojaDeRuta*, int, eTransporte*, int)
/// \brief  Se listaran hojas de ruta existentes, mostrando toda aquella informacion relevante contenida en la estructura.
///
/// \param hojaDeRuta ,array de estructuras a recorrer.
/// \param tam ,referencia para la cantidad de iteraciones.
/// \param transporte ,array de estructuras utilizado para mostrar descripcion (funcion asignarDescripcionTransporteConId).
/// \param contador ,variable de control ,debe ser mayor a 0 para confirmar la existencia de hojas de ruta.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int listarHojasDeRuta(eHojaDeRuta* hojaDeRuta, int tam,eTransporte* transporte ,int contador);

/// \fn int listarHojasDeRutaPorFecha(eHojaDeRuta*, eTransporte*, int, int)
/// \brief El usuario ingresara una fecha, en caso de existir hojas de ruta para su seleccion, se listaran.
///
/// \param hojaDeRuta ,estructura a recorrer.
/// \param transporte ,array de estructuras utilizado para mostrar descripcion (funcion asignarDescripcionTransporteConId).
/// \param tam ,referencia para la cantidad de iteraciones.
/// \param contadorDeHojas ,variable de control ,debe ser mayor a 0 para confirmar la existencia de hojas de ruta.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int listarHojasDeRutaPorFecha(eHojaDeRuta* hojaDeRuta, eTransporte* transporte,int tam, int contadorDeHojas);

/// \fn int informarImporteDeHojasPorId(eTransporte*, int, eHojaDeRuta*, int, int)
/// \brief El usuario ingresara un tipo de transporte y en caso de existir hojas de ruta para su seleccion, se listaran.
///
/// \param transporte ,utilizado para listar transportes.
/// \param contador , utilizado para listar transportes.
/// \param hojaDeRuta ,estructura a recorrer.
/// \param contadorDeHojas ,contadorDeHojas ,variable de control ,debe ser mayor a 0 para confirmar la existencia de hojas de ruta.
/// \param tam ,referencia para la cantidad de iteraciones.
/// \return
int informarImporteDeHojasPorId(eTransporte* transporte,int contador, eHojaDeRuta* hojaDeRuta, int contadorDeHojas ,int tam);




#endif /* HOJADERUTA_H_ */
