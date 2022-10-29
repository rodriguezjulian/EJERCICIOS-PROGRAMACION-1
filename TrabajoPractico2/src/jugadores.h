/*
 * jugadores.h
 *
 *  Created on: 27 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_
#include "confederaciones.h"

	typedef struct
	{
		int id;
		char nombre[50];
		char posicion[50];
		short numeroCamiseta;
		int idConfederacion;
		float salario;
		short aniosContrato;
		short isEmpty;

	}eJugador;

/// \fn int inicializarIsEmpty(eJugador*, int, int)
/// \brief Dara valor al campo IsEmpty de una estrucutura de tipo eJugador. El mismo se interpretara como VACIO 1 - OCUPADO 0
///
/// \param jugadores , estructura de tipo eJugador sobre la que se operara.
/// \param tam , tamanio del array de estructura.
/// \param estado , estado que el usuario desea darle al campo isEmpty.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int inicializarIsEmptyEjugador(eJugador* jugadores, int tam, int estado);

/// \fn int loguearJugador(eJugador*, eConfederacion*, int*, int*, int)
/// \brief Esta funcion se encarga de completar todos los campos de la estructura eJugador, dependiendo cual sera
/// cargado por el usuario (funciones con sus validaciones correspondientes) o bien se ocuparan automaticamente (campo isEmpty y id autoincremental).
///
/// \param jugadores , estructura de tipo eJugador sobre la que se operara.
/// \param confederaciones , estructura de tipo eConfederacion, llamada en varias funciones que intervienen en el logueo.
/// \param id ,el id se recibe como parametro en 0 (inicializado en 0 por consigna)y se modifica su valor automaticamente .
/// \param contadorJugadores , serviria para posteriormente utilizar esta variable como control de acceso a otras opciones (autoincremental).
/// \param tamJugadores
/// \return
int loguearJugador(eJugador* jugadores,eConfederacion* confederaciones, int* id,int* contadorJugadores,int tamJugadores,int tamConfederaciones);


/// \fn int asignarDescripcion(eJugador*, eConfederacion*, int, char*, int)
/// \brief Esta funcion retorna por referencia una cadena de caracteres que posteriormente sera compara con otra en la funcion ordenarJugadoresAlfabeticamente.
///
///
/// \param jugadores , estructura de tipo eJugador usada como parametro para utilizar los valores contenidos en sus campos.
/// \param confederaciones , obtendremos la descripcion de un array de tipo eConfederacion.
/// \param tamConfederaciones , tamanio del array de confederaciones, utilizado como referencia en un bucle for
/// \param descripcion , a esta variable se le asignara el valor de la cadena de caracteres.
/// \param posicion , la posicion sera dada por el numero de iteracion que lleve una funcion for(){} comunmente utilizadas letra i o j
/// \return
int asignarDescripcion(eJugador* jugadores,eConfederacion* confederaciones,int tamConfederaciones, char* descripcion ,int posicion);

/// \fn int ordenarJugadoresAlfabeticamente(eJugador*, eConfederacion*, int, int)
/// \brief Se obtendran las descripciones teniendo en cuenta los campos idConfederacion de un array de estructuras de tipo eJugador y el
/// campo nombre de la estructura eConfederacion (mediante funcion asignarDescripcion).
/// Se compararan de a dos descripciones (nombres de estructura) y en caso de coincidencia se tendra en cuenta el campo nombre de la estrucutra  eJugador, se
/// busca ordenar alfabeticamente en ambos casos.
/// \param jugadores , estructura de tipo eJugador que sera ordenada.
/// \param confederaciones , variable utilizada para llamar a la funcion asignarDescripcion.
/// \param tam , tamanio del array de estructuras de tipo eJugador
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ordenarJugadoresAlfabeticamente(eJugador* jugadores,eConfederacion* confederaciones,int tam);

/// \fn int ordenarJugadoresXId(eJugador*, int)
/// \brief Teniendo en cuenta el campo id de un array de estruturas de tipo eJugador, se ordernaran las posiciones segun id.
/// Se comparara y en caso de ser necesario se hara un "swap"
///
/// \param jugadores , array de estructuras a ordenar.
/// \param tam , tamanio del array de tipo eJugador que se ordenara.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ordenarJugadoresXId(eJugador* jugadores, int tam);

/// \fn int contarIteraciones(eJugador*, int*, int, int)
/// \brief Esta funcion recibe un valor asignado al campo id de un array de estructuras, en caso de validar que existe, devuelve por
/// parametro cuantas iteraciones debio realizar hasta llegar a la coincidencia, de esta manera se podra trabajar especificamente sobre esa
/// direccion de memoria.En caso que NO se valide como existente el id recibido se retornara -1.
///
/// \param jugadores , array de estructuras que sera recorrido buscando la coincidencia entre el id buscado y los existentes.
/// \param iteraciones , se pasa por refencia este valor una vez que se halle la coincidencia (en caso de hallarse).
/// \param tam , tamanio del array de estructuras de tipo eJugador.
/// \param idModificar , id buscado (ingresado por el usuario en otra funcion, aca llega como parametro).
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int contarIteraciones(eJugador* jugadores,int* iteraciones, int tam, int idModificar);

/// \fn int modificarJugador(eJugador*, eConfederacion*, int, int)
/// \brief Esta funcion llamara a  "listarJugadores" para mostrar aquellos existentes, mostrar opciones para
/// que el usuario pueda elegir que modificar , pedir el ingreso de una de estas opciones (por funcion ingresarIntConRango) y segun
/// se elija llamar a otra funcion para que concrete la modificacion.
///Se llamara a "contarIteraciones" para modificar en exactamente la direccion de memoria correspondiente.
/// \param jugadores , array de estructuras de tipo eJugador al que se le modificara un campo.
/// \param confederaciones , array de tipo eConfederacion utilizado para llamar a la funcion "listarJugadores" y "listarConfederaciones".
/// \param tam ,  tamanio del array de estructuras de tipo eJugador.
/// \param contadorJugadores , utilizado para llamar a la funcion "listarJugadores".
/// \return
int modificarJugador(eJugador* jugadores, eConfederacion* confederaciones, int tam ,int contadorJugadores,int tamConfederaciones);

/// \fn int darLaBajaJugador(eJugador*, int, int*, eConfederacion*)
/// \brief Esta funcion llamara a  "listarJugadores" para mostrar aquellos existentes, pedira un id (por medio de la funcion "ingresarIntConRango") y
/// en caso de existir se modificara el campo isEmpty (DE OCUPADO A VACIO) de la estrucutra de tipo eJugador correspondiente.
///Se llamara a "contarIteraciones" para dar la baja en exactamente la direccion de memoria correspondiente.
/// \param jugadores , estructura de tipo eJugador sobre la que se operara.
/// \param tam , tamanio del array de estructuras de tipo eJugador.
/// \param contadorJugadores , se restara 1 a la cantidad total de jugadores (variable de control).
/// \param confederaciones  , array de tipo eConfederacion utilizado para llamar a la funcion "listarJugadores" .
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int darLaBajaJugador(eJugador* jugadores,int tam, int* contadorJugadores, eConfederacion* confederaciones);

/// \fn int listarJugadoresXUnaConf(eJugador*, eConfederacion*, int, int, int)
/// \brief Lista jugadores de una confederacion especifica, la misma se recibe por ID, aunque se muestran descripciones y no numeros.
///
/// \param jugadores , array de estructuras de tipo eJugador que se recorrera.
/// \param confederaciones , array de estructuras de tipo eConfederacion que se recorrera.
/// \param tam , tamanio del array de estructuras de tipo eJugador.
/// \param idConf , id de estructura buscado.
/// \param tamConfederaciones , tamanio de array de confederaciones.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int listarJugadoresXUnaConf(eJugador* jugadores,eConfederacion* confederaciones,int tam, int idConf, int tamConfederaciones);


/// \fn int listarJugadoresXConfederaciones(eJugador*, eConfederacion*, int, int)
/// \brief Esta funcion llama dentro de un bucle for a la funcion "listarJugadoresXUnaConf", teniendo en cuenta el tamanio de las confederaciones.
/// De esta manera se listaran los jugadores de la confederacion correspondiente o bien en caso de NO haber jugadores cargados en esa conferencia
/// se hara un print aclarando la NO existencia de jugadores.
///
/// \param jugadores , array de estructuras utilizado en el llamado a la funcion "listarJugadoresXUnaConf".
/// \param confederaciones , array de estructuras de tipo eConfederacion utilizado para llamar a la funcion "listarJugadoresXUnaConf".
/// \param tam , tamanio del array de estructuras de tipo eJugador.
/// \param tamConfederaciones , tamanio de array de confederaciones.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int listarJugadoresXConfederaciones(eJugador* jugadores,eConfederacion* confederaciones,int tam, int tamConfederaciones);

/// \fn float calcularPromedio(float, int)
/// \brief Recibe por parametro 2 numeros, el numero A sera dividido por el numero B (cantidad de casos).
///
/// \param numeroA , numero que sera divido (total)
/// \param numeroB cantidad de casos
/// \return resultado
float calcularPromedio(float numeroA, int numeroB);

/// \fn int acumularTotalSalarios(eJugador*, int, float*)
/// \brief Se acumularan los salarios de TODOS los jugadores cargados, se utiliza un bucle for para recorrer el array de estructuras e ir acumulando los
/// valores del campo "salario".
///
/// \param jugadores ,array de estructuras de tipo eJugador que se recorrera.
/// \param tam , tamanio del array de estructuras de tipo eJugador.
/// \param totalSalarios ,una vez se concluye con el acumulamiento, se asigna este valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int acumularTotalSalarios(eJugador* jugadores,int tam, float* totalSalarios);

/// \fn int calcularJugPorArribaDeLaMedia(eJugador*, float)
/// \brief Teniendo en cuenta el promedio de los salarios calculado anteriormente con la funcion "calcularPromedio", se recorrera el array
/// de estructuras de tipo eJugador, contando +1 cada vez que un jugador supere ese promedio (salario promedio).
///
/// \param jugadores ,array de estructuras de tipo eJugador que se recorrera.
/// \param promedioSalarios , promedio de salarios recibido.
/// \return resultado
int calcularJugPorArribaDeLaMedia(eJugador* jugadores, float promedioSalarios);

/// \fn int informarTotalyMediaDeSalarios(eJugador*, int, int)
/// \brief En esta funcion se llamara a "acumularTotalSalarios","calcularPromedio"y "calcularJugPorArribaDeLaMedia""
/// Una vez obtenidos estos datos se mostraran ordenadamente.
///
/// \param jugadores , array de estructuras de tipo eJugador.
/// \param tam ,  tamanio del array de estructuras de tipo eJugador.
/// \param contadorJugadores , cantidad total de jugadores logueados.
void informarTotalyMediaDeSalarios(eJugador* jugadores, int tam, int contadorJugadores);

/// \fn int calcConfConMasAniosDeContrato(eJugador*, int, int, int*)
/// \brief Se calculara la mayor cantidad de años total acumulada en una confederacion (puede haber 2 o mas confederaciones con
/// la misma cantidad).
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param tamConfederaciones , tamanio de array de estructura de tipo eConfederacion.
/// \param tamJugadores ,  tamanio del array de estructuras de tipo eJugador
/// \param resultadoAnios , total acumulado mayor.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int calcConfConMasAniosDeContrato(eJugador* jugadores,int tamConfederaciones, int tamJugadores, int* resultadoAnios);

/// \fn int contarAniosDeContratoPorConf(eJugador*, int, int, eConfederacion*, int*)
/// \brief Se inicializara en 0 un array de enteros (funcion inicializarArray),y se acumularan anios de contrato de una confederacion para
/// luego asignarle ese valor a la posicion del array que corresponda, asi consecutivamente hasta que se rompa el bucle que toma como referencia el
/// tamanio de las confederaciones.
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param tam ,  tamanio del array de estructuras de tipo eJugador.
/// \param tamConfederaciones , tamConfederaciones , tamanio de array de confederaciones.
/// \param arrayAniosAcumulados , array al que se le asignara los valores mencionados anteriormente.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int contarAniosDeContratoPorConf(eJugador* jugadores, int tam, int tamConfederaciones,int* arrayAniosAcumulados );


/// \fn void mostrarConfConMasAniosContrato(eJugador*, int, int, eConfederacion*)
/// \brief Se llamara a las funciones "calcConfConMasAniosDeContrato" y "contarAniosDeContratoPorConf", para luego recorrer e
/// imprimir a travez de un bucle for y printear, teniendo en cuenta que posiciones del array cargado en  contarAniosDeContratoPorConf,
/// son iguales al maximo encontrado(recordar que surge de acumular los anios de contrato).
///
/// \param jugadores , array de estructuras de tipo eJugador, utilizado en las funciones llamadas.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param tamConfederaciones , tamConfederaciones , tamanio de array de confederaciones.
/// \param confederaciones , array de estrucuturas de tipo eConfederacion.
void mostrarConfConMasAniosContrato(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones);



/// \fn float calcPorcentaje(int, int)
/// \brief Se recibe como parametro un total que representa el 100% y el parcial.
/// Se retornara el porcentaje que representa el valor parcial respecto al total.
///
/// \param total
/// \param parcial
/// \return resultado
float calcPorcentaje(int total, int parcial);

/// \fn int calcPorcentajePorConf(eJugador*, int, int, float*, int)
/// \brief Se llama a inicializarArrayFloat para inicializar en 0 al array en donde luego se guardaran valores por referencia segun corresponda en cada posicion.
/// Con el uso de contadores y la funcion "calcPorcentaje", se calculara el porcentaje que representa cada confederacion respecto a la cantidad de jugadores que tiene.
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param contJugadores , valor utilizado para calcular porcentajes.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param arrayPorcentajes , array al que se le asignaran valores de porcentaje segun corresponda.
/// \param tamConfederaciones , tamanio de array de estructura de tipo eConfederacion.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int calcPorcentajePorConf(eJugador* jugadores,int contJugadores, int tam, float* arrayPorcentajes, int tamConfederaciones);


/// \fn int informarPorcPorConf(eJugador*, int, int, eConfederacion*, int)
/// \brief Se llama a la funcion "calcPorcentajePorConf" y se recorre con un bucle for al array de estructuras de tipo eJugador utilizando como condicion
/// al campo isEmpty y al valor del campo id del arrays de estructuras de tipo eConfederacion (se tiene en cuenta que los id de las confederaciones comienzan
/// en 100).
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param contJugadores , utilizado para llamar a la funcion "calcPorcentajePorConf".
/// \param confederaciones , array de estructuras de tipo eConfederacion.
/// \param tamConfederaciones , tamanio de array de estructura de tipo eConfederacion.
void informarPorcPorConf(eJugador* jugadores, int tam, int contJugadores, eConfederacion* confederaciones, int tamConfederaciones);

/// \fn int buscarMayorNumJugPorRegion(eJugador*, int, int, int*)
/// \brief En esta funcion se le dara valor a cada posicion de un array (inicializado en 0 con funcion "inicializarArray") de
/// enteros, a cada una corresponde la acumulacion de cantidad de jugadores.Se declara un array para evitar declarar 1 contador por
/// cada confederacion.
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param tamConfederaciones , tamanio del array de tipo eEstrucutra utilizado en un bucle for.Al array en si no es necesario utilizarlo en esta funcion, ya que
/// tenemos la referencia de que los id de las confederaciones comienzan en 100, sumado a tener el dato del tamanio.
/// \param arrayCantidadAcumulados , array al que se le asignaran valores.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int buscarMayorNumJugPorRegion(eJugador* jugadores, int tam, int tamConfederaciones,int* arrayCantidadAcumulados);



/// \fn int informarRegionMasAsistida(eJugador*, int, int, eConfederacion*)
/// \brief Se llama a la funcion "buscarMayorNumJugPorRegion", mediante un bucle for se determina la mayor cantidad acumulada de jugadores en alguna de las
/// confederaciones y se toma como referencia para hacer print teniendo en cuenta cuales posiciones del array al cual se le asignaron valores en la funcion
/// "buscarMayorNumJugPorRegion", coinciden con este numero maximo.
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param tamConfederaciones ,utilizado en los bucles for.
/// \param confederaciones , array de estructuras de tipo eConfederacion a recorrer.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int informarRegionMasAsistida(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones);

/// \fn int listarJugadores(eJugador*, eConfederacion*, int, int, int)
/// \brief Listara jugadores mostrando NOMBRE, POSICION, NUMERO DE CAMISETA, SUELDO, CONFEDERACION, ANIOS DE CONTRATO.
/// El orden que esta informacion se lista dependera de la variable "referenciaOrdenamiento".
///
/// \param jugadores , array de estructuras de tipo eJugador a recorrer.
/// \param confederaciones ,array de estructuras de tipo eConfederacion a recorrer.
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param contadorJugadores , utilizado como variable de control.
/// \param referenciaOrdenamiento	referenciaOrdenamiento -> 1. ordeno por orden alfabetico | referenciaOrdenamiento -> 2.ordeno por id
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int listarJugadores(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int referenciaOrdenamiento);

/// \fn int menuInformes(eJugador*, eConfederacion*, int, int, int)
/// \brief Se mostraran opciones, el usuario ingresara una (funcion ingresarShortConRango), lo cual derivara a la llamada de multiples funciones
/// segun corresponda.
/// \param jugadores array, de estructuras de tipo eJugador.
/// \param confederaciones ,array de estructuras de tipo eConfederacion
/// \param tam ,tamanio del array de estructuras de tipo eJugador.
/// \param contadorJugadores , variable de control.
/// \param tamConfederaciones , tamanio del array de estructuras de tipo eConfederacion.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL.
int menuInformes(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int tamConfederaciones);

/// \fn void inicializarArrayFloat(float*, int)
/// \brief Asignar valor 0 por referencia a todas las posiciones de un array tipo float.
///
/// \param array , array a inicializar.
/// \param tam , tamanio del array.
void inicializarArrayFloat(float* array,int tam);

/// \fn void inicializarArray(int*, int)
/// \brief Asignar valor 0 por referencia a todas las posiciones de un array tipo int,
///
/// \param array , array a inicializar.
/// \param tam , tamanio del array.
void inicializarArray(int* array,int tam);

#endif /* JUGADORES_H_ */
