/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 9-5
#include <stdio.h>
#include <stdlib.h>
//#include "calculos.h"
#include "ingresos.h"
#include<string.h>
#include <ctype.h>

#define TAM 300
#define VACIO 1
#define OCUPADO 0

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpety;
}eEmpleado;

int inicializarIsEmpety(eEmpleado* empleados, int tam, int estado);
int loguearEmpleado(eEmpleado* empleadoAuxliar,int estado, int* id);
int modificarEmpleado(eEmpleado* empleados);
int darDeBajaEmpleado(eEmpleado* empleados);

int main(void) {
	setbuf(stdout,NULL);

	char respuesta;
	int id=0;
	int auxPosicion;//cuando encuentro una posicion vacia la guardo aca
	eEmpleado empleados[TAM];
	eEmpleado empleadoAuxiliar;
	int opcion;

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
		break;
		}

		printf("Pulse 'S' para continuar operando");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=toupper(respuesta);

	}while(respuesta=='S');

	return EXIT_SUCCESS;
}
int inicializarIsEmpety(eEmpleado* empleados, int tam, int estado)
{
	int retorno=OCUPADO;
	if(empleados!=NULL  && tam>0)
	{
		for(int i=0;i<TAM;i++)//HABRIA QUE PASARLO A UNA FUNCION.
		{
			empleados[i].isEmpety=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}
		retorno=0;
	}
	return retorno;
}
int loguearEmpleado(eEmpleado* empleadoAuxliar,int estado, int* id )
{
	int retorno=-1;

	if(empleadoAuxliar!=NULL && id!=NULL)
	{
			(*empleadoAuxliar).id=*id;
			*id=*id+1;
			ingresarArrayCaracteres((*empleadoAuxliar).name,"Ingrese nombre de empleado","Error, ingrese nombre valido",51);
			ingresarArrayCaracteres((*empleadoAuxliar).lastName,"Ingrese apellido de empleado","Error, ingrese apellido valido",51);
			ingresarFloatConMinimo(&(*empleadoAuxliar).salary, "Ingrese sueldo","Ingrese sueldo valido",0);
			ingresarIntConMinimo(&(*empleadoAuxliar).sector, "Ingrese sector del empleado","Ingrese sector valido",0);
			(*empleadoAuxliar).isEmpety=estado;

			retorno=0;
	}
	return retorno;
}
int modificarEmpleado(eEmpleado* empleados)
{
	int retorno=-1;
	eEmpleado auxiliar;
	int posicion;
	int opcion;

	if(empleados!=NULL)
	{
		ingresarIntConMensaje(&auxiliar.id,"Ingresar numero identificacion ID de empleado a modificar");
		posicion=auxiliar.id-1;

		if(empleados[posicion].isEmpety==OCUPADO)
		{
			ingresarNumerosConRangoV1(&opcion,"MARQUE SEGUN QUIERA MODIFICAR\n"
					"1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n" ,"Ingrese opcion valida",1,4);
			switch(opcion)
			{
				case 1:
					ingresarArrayCaracteres(auxiliar.name,"Ingrese nombre de empleado","Error, ingrese nombre valido",51);
					strcpy(empleados[posicion].name, auxiliar.name);
				break;
				case 2:
					ingresarArrayCaracteres(auxiliar.lastName,"Ingrese apellido de empleado","Error, ingrese apellido valido",51);
					strcpy(empleados[posicion].lastName, auxiliar.lastName);
				break;
				case 3:
					ingresarFloatConMinimo(&auxiliar.salary, "Ingrese sueldo","Ingrese sueldo valido",0);
					empleados[posicion].salary=auxiliar.salary;
				break;
				case 4:
					ingresarIntConMinimo(&auxiliar.sector, "Ingrese sector del empleado","Ingrese sector valido",0);
					empleados[posicion].sector=auxiliar.sector;
				break;
			}
			retorno=0;
		}
		else
		{
			printf("El ID ingresado no corresponde a un empleado\n");
		}
	}
	return retorno;
}
int darDeBajaEmpleado(eEmpleado* empleados)
{
	int retorno=-1;
	int posicion;
	eEmpleado auxiliar;
	if(empleados!=NULL)
	{
		ingresarIntConMensaje(&auxiliar.id,"Ingresar numero identificacion ID de empleado a dar de baja\n");
		posicion=auxiliar.id-1;
		if(empleados[posicion].isEmpety==OCUPADO)
		{
			empleados[posicion].isEmpety=VACIO;
			retorno=0;
			printf("<<<<<<<<<<EMPLEADO DADO DE BAJA>>>>>>>>>>\n");
		}
		else
		{
			printf("El ID ingresado no corresponde a un empleado\n");
		}
	}
	return retorno;
}
