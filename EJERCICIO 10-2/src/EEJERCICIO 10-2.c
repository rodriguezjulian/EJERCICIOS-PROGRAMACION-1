/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 9-6
#include <stdio.h>
#include <stdlib.h>
//#include "calculos.h"
#include "ingresos.h"
#include<string.h>
#include <ctype.h>
#include "empleados.h"

#define TAM 300
#define VACIO 1
#define OCUPADO 0

int main(void) {
	setbuf(stdout,NULL);


	char respuesta;
	int id=0;
	int auxPosicion;//cuando encuentro una posicion vacia la guardo aca
	eEmpleado empleados[TAM];
	eEmpleado empleadoAuxiliar;
	int opcion;
	float resultadoAcumulado;
	float promedioDeSueldos;
	int empleadosArribaMedia;

	eSector sectores[4]={
							{100,"Sistemas"},
							{200,"RecursosHumanos"},
							{300,"Administracino"},
							{400,"Gerencia"}
						};

	inicializarIsEmpety(empleados,TAM, VACIO);

	do
	{
		ingresarNumerosConRangoV1(&opcion,"MARQUE SEGUN QUIERA OPERAR\n"
				"1.ALTAS\n2.MODIFICAR LEGAJO\n3.BAJAS\n4.INFORMAR\n" ,"Ingrese opcion valida",1,4);
		switch(opcion)
		{
		case 1:
			for(int i=0;i<TAM;i++)
			{
				if(empleados[i].isEmpety==VACIO)
				{
					auxPosicion=i;
					break;
				}
			}
			loguearEmpleado(&empleadoAuxiliar,OCUPADO,&id);

			empleados[auxPosicion]=empleadoAuxiliar;
		break;
		case 2:
			modificarEmpleado(empleados);
		break;
		case 3:
			darDeBajaEmpleado(empleados);
		break;
		case 4:

			calcacularTotalSalarios(empleados,TAM,&resultadoAcumulado);
			promediarSalarios(empleados,TAM,resultadoAcumulado,&promedioDeSueldos);
			contarEmpleadosMayorSueldoMedio(empleados,TAM,promedioDeSueldos,&empleadosArribaMedia);

			ordenarAlfabeticamente(empleados, TAM);
			mostrarEmpleados(empleados, TAM,resultadoAcumulado,promedioDeSueldos,empleadosArribaMedia);
		break;
		}

		printf("Desea seguir operando? S/N ");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);

	}while(respuesta=='S');


	return EXIT_SUCCESS;
}
