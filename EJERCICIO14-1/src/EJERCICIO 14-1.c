
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 10-2
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

#include "ingresos.h"
#include "empleado.h"
//#include "sector.h"

#define TAM 300
#define VACIO 1
#define OCUPADO 0

int main(void) {
	setbuf(stdout,NULL);

	int id=0;
	int opcion;
	//MEMORIA DINAMICA
	//TENGO QUE REASIGNAR EL TAMANIO SEGUN SE REQUIERA, TENIENDO COMO MINIMO 1 EMPLEADO.
	//TENDRIA QUE UTILIZAR realloc para sumar espacio al loguear y tambien cuando doy de baja???
	eEmpleado* empleados=(eEmpleado*) malloc(sizeof(eEmpleado)*1);

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
	inicializarIsEmpety(empleados,TAM, VACIO);

	do
	{
		ingresarNumerosConRangoV1(&opcion,"MARQUE SEGUN QUIERA OPERAR\n"
				"1.ALTAS\n2.MODIFICAR LEGAJO\n3.BAJAS\n4.INFORMAR\n" ,"Ingrese opcion valida\n",1,4);
		switch(opcion)
		{
		case 1:
			loguearEmpleado(empleados,OCUPADO,&id, &contadorEmpleados, sectores);
		break;
		case 2:
			modificarEmpleado(empleados,TAM, contadorEmpleados, sectores);
		break;
		case 3:
			darDeBajaEmpleado(empleados, TAM, &contadorEmpleados);
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
					calcacularTotalSalarios(empleados,TAM,&resultadoAcumulado);
					promediarSalarios(empleados,TAM,resultadoAcumulado,&promedioDeSueldos);
					contarEmpleadosMayorSueldoMedio(empleados,TAM,promedioDeSueldos,&empleadosArribaMedia);
					mostrarEmpleados(empleados, TAM,resultadoAcumulado,promedioDeSueldos,empleadosArribaMedia,1,sectores);
				break;
				case 2:
					ordenarAlfabeticamente(empleados, TAM);
					mostrarEmpleados(empleados, TAM,resultadoAcumulado,promedioDeSueldos,empleadosArribaMedia,2, sectores);
				break;
				case 3:
					imprimirSectorConMasEmpleados(sectores, empleados, TAM, 4);

				break;
				}
			}
			else
			{
				printf("Para imprimir informes debe existir al menos 1 empleado logueado\n");
			}

		break;
		}
	}while(confirmarSalida()==-1);


	return EXIT_SUCCESS;
}

