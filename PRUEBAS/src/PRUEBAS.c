/*
 ============================================================================
 Name        : PRUEBAS.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J - EJERCICIO ARRAYS EN CLASE
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include<string.h>

#define TAM 2

	//UNA FORMA DE HACERLO
	/*struct ePersona
	{
		char nombre[20];//ESTO ES UN CAMPO
		char apellido[20];
		int edad;
		char estadoCivil;
		float altura;
	};
	*/
	//OTRA FORMA DE HACERLO
	typedef struct
	{
		char nombre[20];//ESTO ES UN CAMPO
		char apellido[20];
		int edad;
		char estadoCivil;
		float altura;
	}ePersona;//ePersona seria el tipo de la estructura, es un tipo especifico que creamos nosotros
//%[^ para el scanf hasta \0 || \n


	/////////	ESTRUCTURA ANIDADA
	typedef struct
	{
		int dia;
		int mes;
		int anio;
	}eFecha;
	typedef struct
	{
		char nombre[20];//ESTO ES UN CAMPO
		char apellido[20];
		int edad;
		char estadoCivil;
		float altura;
		eFecha fechaNacimiento;
	}ePersonitaa;

int main(void){

	/******************************************************************************

	Welcome to GDB Online.
	GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
	C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
	Code, Compile, Run and Debug online from anywhere in world.

	*******************************************************************************/
	#include <stdio.h>

	int main()
	{
	    int numeroIngresado;
	    int retornoScanf;
	    int retorno=-1;

	    do{
	        printf("Ingrese un numero");
	       retornoScanf=scanf("%d",&numeroIngresado);
	        if(retornoScanf==1)
	        {
	            printf("SALIO TODO BIEN ASIQUE CAMBIO EL RETORNO\n");
	            retorno=0;
	        }
	        else
	        {
	            printf("SALIO MAL ASIQUE DEJO EL RETORNO Y SIGUE ITERANDO\n");
	        }

	    }while(retorno==-1);


	    return 0;
	}








/*
	setbuf(stdout,NULL);
	ePersona personita;
	personita.edad=23;
	strcpy(personita.nombre,"julian");

	printf("EDAD %d | nombre %s",personita.edad,personita.nombre);

*/
	return EXIT_SUCCESS;
}








