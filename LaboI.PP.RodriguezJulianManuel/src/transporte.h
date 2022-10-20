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


/// \fn void listarTipos(eTipo*, int)
/// \brief Se listaran los tipos de transportes cargados (en este caso hardcodeados).
///
/// \param tipo ,estrucutra de tipo eTipo* usada para imprimir tanto su campo de IDTIPO asi como la descripcion.
/// \param tam , utilizado para iterar cierta cantidad de veces dependiendo el tamanio.
void listarTipos(eTipo* tipo,int tam);

/// \fn int loguearTransporte(int*, eTransporte*, int*, eTipo*)
/// \brief Ingresar un transporte, es decir cargar una descripcion, un peso de carga,
/// una cantidad de bultos, y un tipo. El id se asignara automaticamente siendo el mismo autoincremental.
///
/// \param idTransporte ,Esta variable se pasa como parametro para tomar de referencia a
///  partir de que numero comenzaran a contar los ID.
/// \param auxiliar ,El resultado del ingreso se pasa por referencia a una estructura de tipo eTransporte.
/// \param contador ,Esta variable se incrementara en +1 cada vez que se cargue un transporte.
/// \param tipo ,una variable de tipo eTipo se utilizara para mostrar los tipos a la hora de loguear al transporte y elegir este campo.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int loguearTransporte(int* idTransporte, eTransporte* auxiliar , int* contador, eTipo* tipo);

/// \fn int inicializarIsEmpty(eTransporte*, int, int)
/// \brief Dara valor al campo IsEmpty de una estrucutura de tipo eTransporte. El mismo se interpretara como VACIO 1 - OCUPADO 0
///
/// \param transporte , estructura de tipo eTransporte sobre la que se operara.
/// \param tam ,tamanio del array de estructura.
/// \param estado , estado que el usuario desea darle al campo isEmpty.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int inicializarIsEmpty(eTransporte* transporte, int tam, int estado);

/// \fn int calcularCantidadI(eTransporte*, int)
/// \brief Esta funcion lo que hace es devolverme la cantidad de veces que se itera hasta encontrar una coincidencia de Id teniendo
/// en cuenta al array de estructuras de transportes recibido y al idbuscado.
///
/// \param transporte , array de estructuras a comparar
/// \param iDBuscado ,ID buscado.
/// \return si esta todo bien devuelve cantidad de iteraciones y si esta todo mal devuelve -1
int calcularCantidadI(eTransporte* transporte, int iDBuscado);

/// \fn int modificartransporte(eTransporte*, int)
/// \brief Se solicitara el ID del transporte a modificar.Una vez validada su existencia
/// se consultara si desea modificar peso de carga o cantidad de bultos para luego efectuar el cambio.
///
/// \param transporte ,estructura sobre la que se efectuaran los cambios.
/// \param contador ,variable de control, en caso de NO ser mayor a 0, significaria que no hay transportes logueados por lo que
/// ninguno se podria modificar tampoco.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int modificartransporte(eTransporte* transporte,int contador);


/// \fn int bajaTransporte(eTransporte*, int*)
/// \brief Se solicitara el ID de un transporte.Una vez validada su existencia, se dara valor 1 a su campo isEmpty
///
/// \param transporte ,estructura sobre la que se efectuaran los cambios.
/// \param contador ,variable de control, en caso de NO ser mayor a 0, significaria que no hay transportes logueados por lo que
/// ninguno se podria dar de baja tampoco
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int bajaTransporte(eTransporte* transporte,int *contador);

/// \fn int ordenarTransportes(eTransporte*, int)
/// \brief  Ordenara un array de estrucuras por tipo y por descripcion
///
/// \param transporte , estructura a ordenar.
/// \param tam ,tamanio del array de estructura.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ordenarTransportes(eTransporte* transporte, int tam);

/// \fn int listarTransportes(eTransporte*, int, int)
/// \brief Se listaran los transportes cargados de forma prolija y enmarcada, se logra recorriendo
/// a la variable de tipo eTransporte y comparando su campo isEmpty, se imprira cuando este valga 0.
///
/// \param transporte ,el contenido de esta estrucura sera el impreso.
/// \param tam ,utilizado para iterar cierta cantidad de veces dependiendo el tamanio.
/// \param contador ,variable de control, en caso de NO ser mayor a 0, significaria que no hay transportes logueados por lo que
/// ninguno se podria listar tampoco.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int listarTransportes(eTransporte* transporte, int tam, int contador);

/// \fn int ingresarIdTipo(eTransporte*, eTipo*)
/// \brief Esta funcion sera llamada al loguear un nuevo transporte, la misma mostrara al usuario los tipos de vehiculos, permitiendole
/// elegir uno por ID.
///
/// \param transporte ,se pasara por parametro el resultado.
/// \param tipo ,se utilizara para listar los tipos.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarIdTipo(eTransporte* transporte, eTipo* tipo);

/// \fn int verificarExistenciaDeTipoDeTransporte(eTransporte*, int, int)
/// \brief Se recibe como parametro el tipo a verificar y se empieza a comparar con el campo tipo de la estructura de tipo eTransporte.
///
/// \param transporte , estructura a recorrer (campo del tipo unicamente).
/// \param tipoBuscado ,tipo a verificar.
/// \param tam ,utilizado para establecer las iteraciones.
/// \return return=0 SI HAY COINCIDENCIA || return=-1 si NO hay coincidencia (es decir se verifica que no existe un transporte de ese tipo).
int verificarExistenciaDeTipoDeTransporte(eTransporte* transporte, int tipoBuscado, int tam);


/// \fn int listarTransportesDeUnTipo(eTransporte*, int, int, int)
/// \brief Se listaran los transportes de un tipo seleccionado(viene por parametro). Antes de llamar a esta funcion se debe verificar que
/// exista al menos 1 transporte del tipo seleccionado si no se hace, se imprimira una grilla sin datos.
///
/// \param transporte , array de estructuras que se recorrera buscando aquellas con el tipo seleccionado.
/// \param tam ,utilizado para iterar cierta cantidad de veces dependiendo el tamanio.
/// \param tipo ,utilizado para comparar a la estructura con el tipo recibido por el usuario.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int listarTransportesDeUnTipo(eTransporte* transporte, int tam,int tipo);




#endif /* TRANSPORTE_H_ */
