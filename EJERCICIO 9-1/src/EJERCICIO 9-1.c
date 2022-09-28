/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 9-1
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "ingresos.h"
#include<string.h>

#define TAM 10
#define VACIO 1
#define OCUPADO 0

typedef struct
{
	char name[51];
	int materiasAprobadas;
	int sumaDeNotas;
	float promedio;
	int isEmpety;
}eAlumno;

int inicializarIsEmpety(eAlumno* alumno, int tam, int estado);
int cargarEstudiante(eAlumno* estudiante, int posicion);
int mostrarAlumnos(eAlumno* estudiante, int tam);
int promediarNotas(eAlumno* estudiante, int tam, float* promedioDeNotas);

int main(void) {
	setbuf(stdout,NULL);

	eAlumno estudiante[TAM];
	int posicion;
	int respuesta;
	float promedioDeNotas;
	inicializarIsEmpety(estudiante,TAM, VACIO);

	do
	{
		for(int i=0;i<TAM;i++)
		{
			if(estudiante[i].isEmpety==VACIO)
			{
				posicion=i;
				break;
			}
		}

		cargarEstudiante(estudiante,posicion);

		ingresarIntConMensaje(&respuesta,"Para cargar los datos de otro estudiante presione 1.");

	}while(respuesta==1);

	mostrarAlumnos(estudiante,TAM);
	promediarNotas(estudiante,TAM,&promedioDeNotas);

	printf("El promedio de notas es %.2f",promedioDeNotas);

	return EXIT_SUCCESS;
}
int cargarEstudiante(eAlumno* estudiante, int posicion)
{
	int retorno=-1;

	eAlumno auxiliar;

	if(estudiante!=NULL)
	{
		estudiante[posicion].sumaDeNotas=0;//LO PONGO EN 0 PORQUE LO VOY A USAR COMO ACUMULADOR

		ingresarArrayCaracteres((auxiliar).name,"Ingrese nombre del estudiante","Ingres nombre valido",51);
		ingresarIntConMensaje(&(auxiliar).materiasAprobadas,"Ingrese cantidad de materias aprobadas");
		//SEGUN LA CANTIDAD DE MATERIAS APROBADAS, SE INGRESARAN LAS NOTAS (MISMA CANTIDAD)
		for(int i=0;i<auxiliar.materiasAprobadas;i++)
		{
			ingresarIntConMensaje(&auxiliar.sumaDeNotas,"Ingrese nota");
			estudiante[posicion].sumaDeNotas=estudiante[posicion].sumaDeNotas+auxiliar.sumaDeNotas;
		}

		auxiliar.isEmpety=OCUPADO;
		//PASO LO DEL AUXILIAR AL ARRAY de eAlumno.

		strcpy(estudiante[posicion].name, auxiliar.name);
		estudiante[posicion].materiasAprobadas=auxiliar.materiasAprobadas;
		estudiante[posicion].promedio=(float)estudiante[posicion].sumaDeNotas/estudiante[posicion].materiasAprobadas;
		estudiante[posicion].isEmpety=auxiliar.isEmpety;
		retorno=0;
	}
	return retorno;
}
int inicializarIsEmpety(eAlumno* alumno, int tam, int estado)
{
	int retorno=OCUPADO;
	if(alumno!=NULL  && tam>0)
	{
		for(int i=0;i<TAM;i++)//HABRIA QUE PASARLO A UNA FUNCION.
		{
			alumno[i].isEmpety=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}
		retorno=0;
	}
	return retorno;
}
int mostrarAlumnos(eAlumno* estudiante, int tam)
{
	int retorno=-1;
	if(estudiante!=NULL && tam>0)
	{
		for(int posicion=0;posicion<tam;posicion++)
		{
			if(estudiante[posicion].isEmpety==OCUPADO)
			{
				printf("nombre: %s | Materias aprobadas: %d | Suma de notas: %d | Promedio: %.2f\n",estudiante[posicion].name,estudiante[posicion].materiasAprobadas,estudiante[posicion].sumaDeNotas,estudiante[posicion].promedio);
			}
		}
		retorno=0;
	}
	return retorno;
}
int promediarNotas(eAlumno* estudiante, int tam, float* promedioDeNotas)
{
	int retorno=-1;
	eAlumno auxiliar;

	auxiliar.sumaDeNotas=0;//LOS USO PARA ACUMULAR
	auxiliar.materiasAprobadas=0;

	if(estudiante!=NULL && tam>0)
	{
		for(int posicion=0;posicion<tam;posicion++)
		{
			if(estudiante[posicion].isEmpety==OCUPADO)
			{
				auxiliar.sumaDeNotas=auxiliar.sumaDeNotas+estudiante[posicion].sumaDeNotas;
				auxiliar.materiasAprobadas=auxiliar.materiasAprobadas+estudiante[posicion].materiasAprobadas;
			}
		}
		*promedioDeNotas=(float)auxiliar.sumaDeNotas/auxiliar.materiasAprobadas;
		retorno=0;
	}
	return retorno;
}
