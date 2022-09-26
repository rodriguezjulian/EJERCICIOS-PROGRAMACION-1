/*
 * calculos.h
 *
 *  Created on: 14 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
/**
 * \fn int calcularPromedioArray(int, int*, float*)
 * \brief Esta funcion calcula promedio de un array de enteros luego de veficar que el tamaño sea mayor a 0 y
 * que ni el array que se recibe como parametro ni el puntero son NULL
 *
 * \param tam, tamaño del array a recorrer, con el podremos operar un for la cantidad de veces correspondientes para recorrer el array.
 * \param array, es el array que se recibe como parametro, del que se busca obtener el promedio.
 * \param promedio, se guardara el resultado de la operacion a traves de un puntero, pasando el resultado por referencia.
 * \return, todo bien un 0 / todo mal -1.
 */
int calcularPromedioArray(int tam, int* array, float *promedio);
/**
 * \fn void inicializarArray(int[], int)
 * \brief Esta funcion guardara un 0 en cada posicion del array que se recibe como parametro.
 *
 * \param array, recibido como parametro, sus posicion son las que seran inicializadas en 0.
 * \param tam, tamaño del array a recorrer, con el podremos operar un for la cantidad de veces correspondientes para recorrer el array.
 */
void inicializarArray(int array[],int tam);
/**
 * \fn int calcularMaximoArray(int*, int*)
 * \brief Esta funcion calcula el mayor numero ingresado en un array de enteros, dando un valor inicial como mayor y luego comparandolo con los demas.
 *
 * \param array, array a evaluar recibido como parametro.
 * \param valorMaximo, se guardara el resultado de la operacion a traves de un puntero, pasando el resultado por referencia.
 * \return, todo bien un 0 / todo mal -1.
 */
int calcularMaximoArray(int* array, int* valorMaximo);
/**
 * \fn int contarImparesDeArray(int*, int)
 * \brief Esta funcion contara la cantidad de numeros impares contenidos en un array de enteros.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \return Se retornara la cantidad de numeros impares que contenga el array.
 */
int contarImparesDeArray(int* array,int tam);
/**
 * \fn int contarNegativosArray(int*, int)
 * \brief Esta funcion contara la cantidad de numeros negativos contenidos en un array de enteros.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \return, se retornara la cantidad de numeros negativos que contenga el array.
 */
int contarNegativosArray(int* array,int tam);
/**
 * \fn int sumarImparesDeArray(int[], int)
 * \brief Esta funcion sumara enteros impares positivos y negativos contenidos en el array recibido como parametro.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \return, se retornara la suma de enteros impares positivos y negativos.
 */
int sumarImparesDeArray(int array[],int tam);
/**
 * \fn int calcularMaximoArrayPar(int*, int*)
 * \brief Esta funcion calculara el mayor numero par contenido dentro de un array de enteros.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param valorMaximo, se guardara el resultado de la operacion a traves de un puntero, pasando el resultado por referencia.
 * \return, todo bien un 0 / todo mal -1.
 */
int calcularMaximoArrayPar(int* array, int* valorMaximo);
/**
 * \fn int imprimirArrayInt(int*, int, char*)
 * \brief Esta funcion imprimira un array de enteros acompañado por un mensaje que el usuario escribira al momento operar.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \param mensaje, contendra un texto escrito por el usuario al operar la funcion.
 * \return, todo bien un 0 / todo mal -1.
 */
int imprimirArrayInt(int* array,int tam, char* mensaje);
/**
 * \fn int imprimirArrayIntConMinimo(int*, int, char*, int)
 * \brief Esta funcion imprimira los valores contenidos en un array de enteros que sobre pasen un minimo establecido, ademas
 * se mostrara un mensaje.
 *
 * \param array,array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \param mensaje, contendra un texto escrito por el usuario al operar la funcion.
 * \param minimo, dado por el usuario para limitar la impresion.
 * \return, todo bien un 0 / todo mal -1.
 */
int imprimirArrayIntConMinimo(int* array,int tam, char* mensaje, int minimo);
/**
 * \fn int imprimirIntEnPosicionImpar(int*, int, char*)
 * \brief Esta funcion esta encargada de imprimir los valores cargados en posiciones impares de un array de enteros.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \param mensaje, contendra un texto escrito por el usuario al operar la funcion.
 * \return, todo bien un 0 / todo mal -1.
 */
int imprimirIntEnPosicionImpar( int* array, int tam, char* mensaje);
/**
 * \fn int calcularPromedioPositivosArray(int, int*, float*, int)
 * \brief Esta funcion se encargada de calcular el promedio de numeros positivos contenidos en un array de enteros.
 *
 * \param tam, tamaño del array.
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param promedio, se guardara el resultado de la operacion a traves de un puntero, pasando el resultado por referencia.
 * \param contadorPositivos, contara la cantidad de positivos registrados para asi poder calcular el promedio.
 * \return
 */
int calcularPromedioPositivosArray(int tam, int* array, float* promedio,int contadorPositivos);
/**
 * \fn int contarPositivosArray(int*, int)
 * \brief Esta funcion contara los numeros positivos contenidos dentro de un array de enteros.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \return, se retornara la cantidad de numeros positivos encontrados.
 */
int contarPositivosArray(int* array,int tam);
/**
 * \fn int calcularMinimoArray(int*, int*, int)
 * \brief Funcion encargada de buscar el valor menor contenido dentro de un array de enteros.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param valorMinimo, se guardara el resultado de la operacion a traves de un puntero, pasando el resultado por referencia.
 * \param tam, tamaño del array.
 * \return, todo bien un 0 / todo mal -1.
 */
int calcularMinimoArray(int* array, int* valorMinimo, int tam);
/**
 * \fn int ordenarArrayAscendente(int*, int)
 * \brief Esta funcion ordernara los numeros contenidos en un array de enteros de forma ascendente.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \return ,todo bien un 0 / todo mal -1.
 */
int ordenarArrayAscendente(int* array, int tam);
/**
 * \fn int imprimirArrayIntSinCero(int*, int, char*)
 * \brief Esta funcion imprimira un array de enteros, obviando los numeros 0.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \param mensaje, contendra un texto escrito por el usuario al operar la funcion.
 * \return ,todo bien un 0 / todo mal -1.
 */
int imprimirArrayIntSinCero(int* array,int tam, char* mensaje);
/**
 * \fn int ordenarArrayDescendente(int*, int)
 * \brief Esta funcion ordernara los numeros contenidos en un array de enteros de forma descendente.
 *
 * \param array, array recibido como parametro sobre el que se trabajara.
 * \param tam, tamaño del array.
 * \return
 */
int ordenarArrayDescendente(int* array, int tam);
/**
 * \fn int limitarContador(int*, int, char*)
 * \brief Esta funcion acumulara de a 1 en un contador teniendo en cuenta que este mismo solo puede accionarse
 * determinada cantidad de veces, una vez llegado el limite solo se imprimira un mensaje de error y el retorno quedara en -1(todo mal)
 *
 * \param contador, variable en la que se acumulara.
 * \param maxContar , indicara hasta cuanto puede llegar el contador.
 * \param mensaje , mensaje de error escrito por el usuario cuando se quiera contar excediendo el limite.
 * \return ,todo bien un 0 / todo mal -1.
 */
int limitarContador(int* contador ,int maxContar,char* mensaje);
/**
 * \fn float calcularPromedio(int, int)
 * \brief Esta funcion calculara el promedio de dos numeros enteros recibidos por parametro.
 *
 * \param numeroA
 * \param numeroB
 * \return , Se retornara el resultado.
 */
float calcularPromedio(int numeroA, int numeroB);

#endif /* CALCULOS_H_ */
