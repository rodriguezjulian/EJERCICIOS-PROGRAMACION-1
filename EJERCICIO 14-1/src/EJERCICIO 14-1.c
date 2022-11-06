
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 14-1
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "empleado.h"
#include "ingresos.h"

//#include "sector.h"

#define TAM 1
#define VACIO 1
#define OCUPADO 0
//Empleado* crearEmpleado(void);
//eEmpleado* crearEmpleado(void);//Constructor Por defecto
/*int inicializarArrayEmpleados(eEmpleado* arrayPunteros, int limite);
int buscarLibreArray(eEmpleado* arrayPunteros, int limite, int* posicionLibre);*/
//int mostrarEmpleadoNueva(eEmpleado* empleados, int contadorEmpleados, eSector* sectores);
int main(void) {
	setbuf(stdout,NULL);

	int id=0;
	int opcion;
	//MEMORIA DINAMICA
	//TENGO QUE REASIGNAR EL TAMANIO SEGUN SE REQUIERA, TENIENDO COMO MINIMO 1 EMPLEADO.
	//TENDRIA QUE UTILIZAR realloc para sumar espacio al loguear y tambien cuando doy de baja???

	float resultadoAcumulado;
	float promedioDeSueldos;
	int empleadosArribaMedia;
	int contadorEmpleados=0;
	eSector sectores[4]=
	{
			{100,"Sistemas"},
			{200,"RecursosHumanos"},
			{300,"Administracion"},
			{400,"Gerencia"}
	};
	eEmpleado* empleados;
	empleados=(eEmpleado*) malloc(sizeof(eEmpleado)*1);
	//ARMAR FUNCION TENIENDO EN CUENTA TAMANIO POR #DEFINE
	//(*(empleados+0)).id=0;
	inicializarIsEmpety(empleados, TAM);

	do
	{
		ingresarNumerosConRangoV1(&opcion,"MARQUE SEGUN QUIERA OPERAR\n"
				"1.ALTAS\n2.MODIFICAR LEGAJO\n3.BAJAS\n4.INFORMAR\n" ,"Ingrese opcion valida\n",1,4);
		switch(opcion)
		{
		case 1:
			loguearEmpleado(&empleados,OCUPADO,&id, &contadorEmpleados, sectores);
		break;
		case 2:
			modificarEmpleado(empleados,contadorEmpleados, sectores);
		break;
		case 3:
			darDeBajaEmpleado(empleados, &contadorEmpleados);
		break;
		case 4:
			if(contadorEmpleados>0)
			{
				ingresarNumerosConRangoV1(&opcion, "MARQUE SEGUN QUIERA OPERAR\n"
						"1.Empleados ordenados por nombre y sector.\n"
						"2.Total y promedio de los salarios / cuantos superan el promedio.\n"
						"3.Sector con más empleados y listado de ellos mismos", "ERROR, Ingrese opcion valida\n", 1, 3);
				switch(opcion)
				{
				case 1:
					calcacularTotalSalarios(empleados,contadorEmpleados,&resultadoAcumulado);
					promediarSalarios(empleados,contadorEmpleados,resultadoAcumulado,&promedioDeSueldos);
					contarEmpleadosMayorSueldoMedio(empleados,contadorEmpleados,promedioDeSueldos,&empleadosArribaMedia);
					mostrarEmpleados(empleados, contadorEmpleados,resultadoAcumulado,promedioDeSueldos,empleadosArribaMedia,1,sectores);
				break;
				case 2:
					ordenarAlfabeticamente(empleados, contadorEmpleados);
					mostrarEmpleados(empleados, contadorEmpleados,resultadoAcumulado,promedioDeSueldos,empleadosArribaMedia,2, sectores);
				break;
				case 3:
					imprimirSectorConMasEmpleados(sectores, empleados, contadorEmpleados, 4);

				break;
				}
			}
			else
			{
				printf("Para imprimir informes debe existir al menos 1 empleado logueado\n");
			}

		break;
		}//
	}while(confirmarSalida()==-1);
	return EXIT_SUCCESS;
}
/*int mostrarEmpleadoNueva(eEmpleado* empleados, int contadorEmpleados, eSector* sectores)
{
	int retorno=-1;
	//char descripcionSector[50];
	for(int i=0;i<contadorEmpleados;i++)
	{
		retorno=0;
		printf("%s", (*(empleados+i)).name);
	}
	return retorno;
}*/



/*eEmpleado* crearEmpleado(void)//Constructor Por defecto
{
	eEmpleado* puntero;
	puntero=(eEmpleado*) malloc(sizeof(eEmpleado)*1);
	if(puntero!=NULL)
	{
		return puntero;
	}
	return puntero;
*/
/*eEmpleado* crearEmpleadoConParametro(int id,char name[51], char lastName[51], float salary, int sector, int isEmpty)
{
	eEmpleado* puntero;
	puntero=crearEmpleado();
	if(puntero!=NULL)
	return puntero;
}*/
/*int inicializarArrayEmpleados(eEmpleado* apunteros[], int limite)
{
	int retorno=-1;
	int i;
	if(apunteros!=NULL && limite>0)
	{
		retorno=0;
		//VOY A HACER QUE EL ARRAY VACIO APUNTE  A NULL.
		for(i=0;i<limite;i++)
		{
			(*(apunteros+i))=NULL;
		}
	}

	return retorno;
}
int buscarLibreArray(eEmpleado* arrayPunteros, int limite, int* posicionLibre)
{
	int retorno=-1;
	int i;
	if(arrayPunteros!=NULL && limite>0)
	{
		retorno=0;
		//VOY A HACER QUE EL ARRAY VACIO APUNTE  A NULL.
		for(i=0;i<limite;i++)
		{
			if((arrayPunteros+i)==NULL)
			{
				retorno=0;
				//INDICE DEL ELEMENTO LIBRE
				*posicionLibre=i;
				break;
			}
		}
	}
	return retorno;
}
*/
