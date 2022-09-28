/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 9-2:Una empresa requiere un sistema para administrar su nómina de
empleados. Se sabe que dicha nómina bajo ninguna circunstancia superara los 300
empleados.
El sistema deberá tener el siguiente menú de
opciones:

 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 9-3
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "ingresos.h"

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

int main(void) {
	setbuf(stdout,NULL);

	int respuesta;
	int id=100;
	int auxPosicion;//cuando encuentro una posicion vacia la guardo aca
	eEmpleado empleados[TAM];
	eEmpleado empleadoAuxiliar;
	inicializarIsEmpety(empleados,TAM, VACIO);

	do
	{
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

		ingresarIntConMensaje(&respuesta,"Para seguir ingresando trabajadores presione  1");

	}while(respuesta==1);



	//printf("Nombre ingresado %s\n",empleados[0].name);
	//printf("Apellido ingresado %s\n",empleados[0].lastName);


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
