//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 11-5
typedef struct
{
	int legajo;
	char nombre[20];
	int edad;
}eEstudiante;

#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#define TAM 3
int cargarEstudiante(eEstudiante* estudiantes, int tam, int *id);
int main(void) {
	setbuf(stdout,NULL);
	int id=0;
	eEstudiante estudiantes[TAM];

	if(cargarEstudiante(estudiantes,3, &id)==0)
	{
		for(int i=0;i<TAM;i++)
		{
			printf("Legajo %*d |Nombre: %*s |Edad %*d |\n",-4,(*(estudiantes+i)).legajo,-20,(*(estudiantes+i)).nombre,-20,(*(estudiantes+i)).edad);
		}
	}
	else
	{
		printf("No se pudieron cargar los %d estudiantes",TAM);
	}
	return EXIT_SUCCESS;
}
int cargarEstudiante(eEstudiante* estudiantes, int tam, int *id)
{
	int retorno=-1;
	if(estudiantes!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			retorno=0;
			*id=*id+1;
			(*(estudiantes+i)).legajo=*id;
			ingresarCadenaCaracteres(20,(*(estudiantes+i)).nombre,"Ingrese nombre\n","ERROR,Ingrese nombre valido");
			ingresarIntConRango(&(*(estudiantes+i)).edad, "Ingrese edad\n", "ERROR,ingrese edad valida.\n", 17, 80);
		}
	}
	return retorno;
}
