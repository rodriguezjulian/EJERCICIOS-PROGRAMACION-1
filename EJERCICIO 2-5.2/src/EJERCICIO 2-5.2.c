/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 *///
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 2-5
#include <stdio.h>
#include <stdlib.h>
#define PRECIO 450
#define DESCUENTOA -5
#define DESCUENTOB -10
#define DESCUENTO60 -25

int main(void) {
	setbuf(stdout,NULL);
	int numeroLegajo;
	int edad;
	char estadoCivil;
	int ingreso;
	char genero;
	char respuesta;
	int contadorMayores60;
	int legajoMujerIngresoAntes;
	int edadMujerIngresoAntes;
	int ingresoMujerMasAntiguo;
	int banderaMujerIngresoAntes;
	int importeSinDescuento;
	int contadorAlumnos;
	float importeConDescuentos;
	int descuentoMayores;

	contadorMayores60=0;
	banderaMujerIngresoAntes=0;
	contadorAlumnos=0;


	do{
		printf("Ingrese numero de legajo,4 cifras sin 0 a la derecha \n");
		scanf("%d",&numeroLegajo);
		while(numeroLegajo<999)
		{
			printf("ERROR,Ingrese numero de legajo VALIDO\n");
			scanf("%d",&numeroLegajo);
		}
		printf("Ingrese estado civil, 's' para soltero, 'c' para casado, 'v' para viudo \n");
		fflush(stdin);
		scanf("%c",&estadoCivil);
		while(estadoCivil!='s' && estadoCivil!='c' && estadoCivil!='v')
		{
			printf("ERROR, Ingrese estado civil, 's' para soltero, 'c' para casado, 'v' para viudo \n");
			fflush(stdin);
			scanf("%c",&estadoCivil);
		}
		printf("Ingrese edad \n");
		scanf("%d",&edad);
		while(edad<17 || edad>100)
		{
			printf("ERROR,Ingrese edad mayor a 17\n");
			scanf("%d",&edad);
		}
		printf("Cargue año de ingreso\n");
		scanf("%d", &ingreso);
		while(ingreso<2000 || ingreso>2022)
		{
			printf("ERROR,Cargue año de ingreso VALIDO\n");
			scanf("%d", &ingreso);
		}
		printf("Ingrese genero, 'f' para femenino, 'm'para masculino, 'o' para no binario\n");
		fflush(stdin);
		scanf("%c",&genero);
		while(genero!='f' && genero!='m' && genero!='o')
		{
			printf("ERROR,Ingrese genero, 'f' para femenino, 'm'para masculino, 'o' para no binario\n");
			fflush(stdin);
			scanf("%c",&genero);
		}

		printf("Desea ingresar los datos de otro alumno?\n");
		fflush(stdin);
		scanf("%c",&respuesta);

		if(edad>60)
		{
			contadorMayores60=contadorMayores60+1;
		}
		if(banderaMujerIngresoAntes==0 && genero=='f' )
		{
			legajoMujerIngresoAntes=numeroLegajo;
			edadMujerIngresoAntes=edad;
			ingresoMujerMasAntiguo=ingreso;
			banderaMujerIngresoAntes=1;
		}
		else
		{
			if(genero=='f' && ingresoMujerMasAntiguo>ingreso )
			{
				legajoMujerIngresoAntes=numeroLegajo;
				edadMujerIngresoAntes=edad;
				ingresoMujerMasAntiguo=ingreso;
			}
		}
		contadorAlumnos=contadorAlumnos+1;
	}while(respuesta=='s');

	importeSinDescuento=contadorAlumnos*PRECIO;

	if(contadorAlumnos<5)
	{
		importeConDescuentos=contadorAlumnos*PRECIO;
	}
	else
	{
		if(contadorAlumnos<11)
		{
			//importeConDescuentos=(contadorAlumnos*PRECIO)*0.95;
			importeConDescuentos=(DESCUENTOA*importeSinDescuento/100)+importeSinDescuento;
		}
		else
		{
			if(contadorAlumnos>10)
			{
				importeConDescuentos=(DESCUENTOB*importeSinDescuento/100)+importeSinDescuento;
			}
		}
	}
	if(contadorMayores60>0)
	{
		descuentoMayores=(DESCUENTO60*PRECIO/100)*contadorMayores60;
		importeConDescuentos=importeConDescuentos-descuentoMayores;
	}

	printf("La cantidad de personas mayores de 60 años es %d \n",contadorMayores60);
	printf(" El legajo de la mujer que ingreso hace más tiempo es %d y su edad es %d\n",legajoMujerIngresoAntes,edadMujerIngresoAntes);
	printf("La facultad debe pagar sin tener en cuenta los descuentos %d pesos\n",importeSinDescuento );
	printf("El importe con descuentos es: %.2f",importeConDescuentos );
	return EXIT_SUCCESS;
}
