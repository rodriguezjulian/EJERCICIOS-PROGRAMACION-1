#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seleccion.h"
#include "ingresos.h"
#include "Jugador.h"
/// \fn void selec_delete(Seleccion*)
/// \brief Libero espacio de memoria de un puntero a estructura Seleccion recibido.
///
/// \param this
void selec_delete(Seleccion* this)
{

	free(this);
}
/// \fn Seleccion selec_new*()
/// \brief Reserva espacio de memoria para una estructura de tipo Seleccion.
///
/// \return retorna puntero a estructura de tipo Seleccion
Seleccion* selec_new()
{
	Seleccion* pSeleccion;
	pSeleccion = (Seleccion*)calloc(1,sizeof(Seleccion)*1);
	return pSeleccion;
}
/// \fn Seleccion selec_newParametros*(char*, char*, char*, char*)
/// \brief Recibe por parametro valores para completar los campos de una estructa de tipo Seleccion, habiendo reservado memoria anteriormente.
///
/// \param idStr
/// \param paisStr
/// \param confederacionStr
/// \param convocadosStr
/// \return retorna puntero a estructura de tipo Seleccion
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* pSeleccion;
	pSeleccion=selec_new();
	if(pSeleccion!=NULL)
	{
		pSeleccion->convocados=atoi(convocadosStr);
		pSeleccion->id=atoi(idStr);
		strcpy(pSeleccion->confederacion,confederacionStr);
		strcpy(pSeleccion->pais,paisStr);
	}
	return pSeleccion;
}
/// \fn int selec_getId(Seleccion*, int*)
/// \brief Asigno valor del campo id de una estructura de tipo Seleccion a una variable.
///
/// \param this
/// \param id variable a la que se le pasara el valor por referencia.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_getId(Seleccion* this,int* id)
{
	int retorno=-1;
	if(this!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}
/// \fn int selec_getPais(Seleccion*, char*)
/// \brief Asigno valor del campo pais de una estructura de tipo Seleccion a una variable.
///
/// \param this
/// \param pais variable a la que se le pasara el valor por referencia.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;
	if(this!=NULL)
	{
		strcpy(pais,this->pais);
		retorno=0;

	}
	return retorno;
}
/// \fn int selec_getConfederacion(Seleccion*, char*)
/// \brief  Asigno valor del campo confederacion de una estructura de tipo Seleccion a una variable.
///
/// \param this
/// \param confederacion variable a la que se le pasara el valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		strcpy(confederacion,this->confederacion);
		retorno=0;
	}
	return retorno;
}
/// \fn int selec_setConvocados(Seleccion*, int)
/// \brief Se le asigna  a this el valor que se reciba por parametro en el campo convocados.
///
/// \param this
/// \param convocados entero que se recibe
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->convocados=convocados;
		retorno=0;
	}
	return retorno;
}
/// \fn int selec_getConvocados(Seleccion*, int*)
/// \brief Asigno valor del campo convocados de una estructura de tipo Seleccion a una variable.
///
/// \param this
/// \param convocados
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;
	if(this!=NULL)
	{
		*convocados=this->convocados;
		retorno=0;
	}
	return retorno;
}
/// \fn int selec_IngresarConfederacion(char*)
/// \brief Solicita ingresar confederacion por teclado mostrando las disponibles para luego validar lo ingresado.
///
/// \param opcion Se pasa por referencia el resultado.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_IngresarConfederacion(char* opcion)
{
	int retorno=-1;
	int flag=0;
	char opcionAux[30];

	do
	{
		ingresarCadenaCaracteres(30, opcionAux, "Ingrese confederacion de la que desea guardar listado de jugadores.\n"
				" AFC - CAF - CONCACAF - CONMEBOL - UEFA \n", "ERROR,Ingrese conferacion valida.\n");

		//if(strcmp(opcionAux,"AFC") && opcionAux!="CAF" && opcionAux!="CONCACAF" && opcionAux!="CONMEBOL" && opcionAux!="UEFA")
		if(strcmp(opcionAux,"AFC")==0 || strcmp(opcionAux,"CAF")==0 || strcmp(opcionAux,"CONCACAF")==0 || strcmp(opcionAux,"CONMEBOL")==0 || strcmp(opcionAux,"UEFA")==0)
		{
			flag=1;
			strcpy(opcion,opcionAux);

			retorno=0;
		}
		else
		{
			printf("ERROR, Ingrese confederacion valida.\n");
		}

	}while(flag==0);

	return retorno;
}
//ME FIJO SI LOS PAISES DE LA CONFEDERACION SELECCIONADA TIENEN JUGADORES CONVOCADOS, EN CASO QUE EL CONTADOR SEA MAYOR A UNO YA SE PUEDE SEGUIR

/// \fn int selec_verificarConvocadosPorconfederacion(char*, LinkedList*)
/// \brief  Se verifica que los paises de la seleccion recibida por parametro tiene convocados
///
/// \param opcion
/// \param pArrayListSeleccion
/// \return return=0 ESTA TODO OK, HAY AL MENOS UN JUGADOR CONVOCADO EN LA CONFEDERACION.
int selec_verificarConvocadosPorconfederacion(char* opcion, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	Seleccion* pSeleccion;
	int tam;
	char selecConfederacion[30];
	int selecConvocados;
	tam= ll_len(pArrayListSeleccion);

	if(opcion!=NULL)
	{


		for(int i=0;i<tam;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			//RECIBI POR PARAMETRO A LA CONFEDERACION ELEGIDA, AHORA ME FIJO SI LAS SELECCIONES CON ESA CONFEDERACION, TIENEN CONVOCADOS
			if(selec_getConfederacion(pSeleccion, selecConfederacion)==0 && selec_getConvocados(pSeleccion, &selecConvocados)==0)
			{
				//if(strcmp((*(pSeleccion)).confederacion,opcion)==0 && (*(pSeleccion)).convocados>0)
				if(strcmp(selecConfederacion,opcion)==0 && selecConvocados>0)
				{
					retorno=0;
					break;
				}
			}
			else
			{
				printf("ERROR al intentar acceder a la confederacion / cantidad de convocados.\n");
			}

		}
	}

	return retorno;
}
/// \fn int selec_AsignarDescripcionPais(LinkedList*, LinkedList*, int, char*)
/// \brief Al recibir el indice de un jugador, teniendo en cuenta el campo idSeleccion, busco pasar por referencia
/// el nombre de la seleccion a la que esta convocado.
///
/// \param pArrayListSeleccion
/// \param pArrayListJugador
/// \param indice
/// \param descripcionPais paso por referencia la descripcion del pais.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais)
{
	int retorno=-1;
	Jugador* pJugador;
	int tam;
	Seleccion* pSeleccion;
	int selecId;
	char selecPais[30];
	int jugIdSeleccion;


	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//printf("ENTRE AL IF en selec_AsignarDescripcionPais >0\n");
		//PUNTERO A LA ESTRUCTURA TENIENDO EL INDICE
		pJugador=ll_get(pArrayListJugador, indice);
		//BUSCO EL TAMANIO DE LA LISTA DE SELECCIONES
		tam=ll_len(pArrayListSeleccion);
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRE AL FOR en selec_AsignarDescripcionPais >0\n");
			pSeleccion=ll_get(pArrayListSeleccion, i);
		//	printf("PASE EL ll_get\n");
			if(selec_getId(pSeleccion, &selecId)==0 && jug_getSIdSeleccion(pJugador, &jugIdSeleccion)==0)
			{
				//printf("OBTUVE LOS GETTERS\n");
				if(selecId==jugIdSeleccion)
				{
				//	printf("COINCIDENCIA ENTRE EL ID DE SELECCION DEL JUG Y EL DE LA SELEC \n");
					if(selec_getPais(pSeleccion, selecPais)==0)
					{
						retorno=0;
						//PASO EL NOMBRE DEL PAIS
						//printf("HAGO STRCPY selec_AsignarDescripcionPais >0\n");
						strcpy(descripcionPais, selecPais);
						break;
					}
				}
			}
		}
	}
	return retorno;
}
/// \fn int selec_Solicitar_Id(LinkedList*, int*)
/// \brief Ya listadas las selecciones, en esta funcion paso a solicitar el id de la seleccion (valido), verifico que aun
/// se mantenga por debajo de los 22 convocados y retorno segun ello.
///
/// \param pArrayListSeleccion
/// \param indice
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_Solicitar_Id(LinkedList* pArrayListSeleccion, int* indice)
{
	int retorno=-1;
	int idPais;
	Seleccion* pSeleccion;
	int selecConvocados;
	if(pArrayListSeleccion!=NULL)
	{
		//SOLICITO ID.
		ingresarIntConRango(&idPais, "Ingrese pais para el que desea convocar jugadores.\n", "ERROR, Ingerse ID valido,\n", 1, 32);
		//CON EL ID, PASO A BUSCAR EL INDICE.
		if(selec_buscarPorId(pArrayListSeleccion, idPais, &(*(indice)))==0)
		{
			// BUSCO EL PUNTERO AL ELEMENTO TENIENDO EN CUENTA EL INDICE.
			pSeleccion=ll_get(pArrayListSeleccion, *(indice));
			if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
			{
				//if((*(pSeleccion)).convocados<22)
				if(selecConvocados<22)
				{
					retorno=0;
				}
				else
				{
					printf("ERROR, La seleccion llego a su maximo de 22 convocados.\n");
				}
			}

		}

	}
	return retorno;
}
/// \fn int selec_OrdenarPorConfederacion(void*, void*)
/// \brief Obtengo dos valores para el campo confederacion de una estructura de tipo Seleccion, los comparo y retorno
/// segun corresponda.
///
/// \param unaConderacion
/// \param otraConfederacion
/// \return return=0 si son iguales / return=1 si el primero es mayor / return=-1 si el segundo es mayor
int selec_OrdenarPorConfederacion(void* unaConderacion, void* otraConfederacion)
{
	int retorno=0;//SON IGUALES
	int compara;
	char confederacionUno [30];
	char confederacionDos [30];

	selec_getConfederacion(unaConderacion, confederacionUno);
	selec_getConfederacion(otraConfederacion, confederacionDos);

	compara=strcmp(confederacionUno,confederacionDos);
	if(compara>0)//UNO MAYOR
	{
		retorno=1;
	}
	else
	{
		if(compara<0)//2 MAYOR
		{
			retorno=-1;
		}
	}
	return retorno;
}
/// \fn int selec_buscarPorId(LinkedList*, int, int*)
/// \brief Recibe un id de seleccion y pasa por referencia el indice en el que se encuentra el mismo.
///
/// \param pArrayListSeleccion
/// \param idBuscado
/// \param indice
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_buscarPorId(LinkedList* pArrayListSeleccion, int idBuscado, int *indice)
{
	int retorno=-1;
	int tam;
	Seleccion* pSeleccion=NULL;
	int selecId;
	tam=ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion!=NULL)
	{
		//printf("ENTRO 0\n");
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRO 1\n");
			pSeleccion=ll_get(pArrayListSeleccion, i);
			//printf("ENTRO 2\n");
			if(selec_getId(pSeleccion, &selecId)==0)
			{
				//printf("ENTRO 3\n");
				//if((*(pSeleccion)).id==idBuscado)
				if(selecId==idBuscado)
				{
					//printf("ENTRO 4\n");
					*indice=i;
					retorno=0;
					break;
				}
			}
			else
			{
				printf("ERROR al obtener el id de la seleccion.\n");
			}
		}
	}
	return retorno;
}
/// \fn int selec_restarConvocado(LinkedList*, int)
/// \brief Recibiendo por parametro el id de la seleccion a operar, obtengo el indice (selec_buscarPorId)en donde se ubica y le resto -1 a su
/// campo de convocodos, luego hago el set del nuevo valor.
///
/// \param pArrayListSeleccion
/// \param idSeleccion
/// \return
int selec_restarConvocado(LinkedList* pArrayListSeleccion, int idSeleccion)
{
	int retorno=-1;
	int selecIndice;
	Seleccion* pSeleccion;
	int selecConvocados;
	//printf("ENTRO 0\n");
	if(pArrayListSeleccion!=NULL)
	{
	//	printf("ID SELECCION %d \n",idSeleccion);
		if(selec_buscarPorId(pArrayListSeleccion, idSeleccion, &selecIndice)==0)
		{
		//	printf("INDICE DEL PAIS %d",selecIndice);
			pSeleccion=ll_get(pArrayListSeleccion, selecIndice);
			//printf("ENTRO 1\n");
			//EN CASO DE HACERLO DEBO RESTAR 1 AL CONTADOR DE CONVOCADOS DE ESA SELECCION
			if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
			{
				//printf("CONVOCADOS ANTES %d",selecConvocados);
				selecConvocados=selecConvocados-1;
				//printf("CONVOCADOS DESPUES %d",selecConvocados);
				if(selec_setConvocados(pSeleccion, selecConvocados)==0)
				{
					retorno=0;
					printf("<<<<<<<<<< JUGADOR DESCONTADO DE SU SELECCION  >>>>>>>>>\n");
				}
			}
		}
	}
	return retorno;
}

