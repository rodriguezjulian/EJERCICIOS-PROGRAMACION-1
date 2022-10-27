/*
 * InformesPP.h
 *
 *  Created on: 20 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef INFORMESPP_H_
#define INFORMESPP_H_


/// \fn int listarTransportesDeUnTipo(eTransporte*, int, int, int)
/// \brief Se listaran los transportes de un tipo seleccionado(viene por parametro). Antes de llamar a esta funcion se debe verificar que
/// exista al menos 1 transporte del tipo seleccionado si no se hace, se imprimira una grilla sin datos.
///
/// \param transporte , array de estructuras que se recorrera buscando aquellas con el tipo seleccionado.
/// \param tam ,utilizado para iterar cierta cantidad de veces dependiendo el tamanio.
/// \param tipo ,utilizado para comparar a la estructura con el tipo recibido por el usuario.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int listarTransportesDeUnTipo(eTransporte* transporte, int tam,int tipo);


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

/// \fn int informarImpTotalDeHojasPorTipoyFecha(int, int, eTipo*, int, eTransporte*, eHojaDeRuta*, int*)
/// \brief El usuario ingresara un tipo de transporte, en caso de existir hojas de ruta para su seleccion se le pedira una fecha
/// y en caso existir hojas de ruta asignadas para esa fecha, las mismas se listaran para luego mostrarse el importe que acumularon entre todas.
///
/// \param tam ,Tamanio para establecer cantidad de iteraciones.
/// \param tamTipos ,Tamanio del array de estructura de tipo eTipo, para ejecutar una funcion que muestra los distintos tipos.
/// \param tipos ,estructura de tipos a mostrar.
/// \param opcionDeInformes ,en esta variable se guardara el id que el usuario ingrese por teclado.
/// \param transportes ,array de estructuras a recorrer y utilizado para mostrar descripcion (funcion asignarDescripcionTransporteConId).
/// \param hojaDeRuta ,estructura a recorrer y utilizado para listar hojas de ruta.
/// \param volverMenuPrincipal ,Si el usuario se queda sin reintentos para colocar un ID correcto, esta variable sera la referencia para mandarlo al menu principal.
/// \return
int informarImpTotalDeHojasPorTipoyFecha(int tam, int tamTipos,eTipo* tipos,int opcionDeInformes , eTransporte* transportes,eHojaDeRuta*  hojaDeRuta,int* volverMenu, int contadorDeHojas);
#endif /* INFORMESPP_H_ */

