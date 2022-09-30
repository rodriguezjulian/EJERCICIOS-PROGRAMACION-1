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

#define TAM 300
#define VACIO 1
#define OCUPADO 0

typedef struct
{
	int idSector;
	char descripcionSector[20];

}eSector;
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int idSector;
	int isEmpety;
}eEmpleado;
//VALIDAR QUE EL SECTOR EXISTA - UNA FUNCION QUE MUESTRE LOS SECTORES - UNA FUNCION QUE LE TIRE EL NUMERO DE SECTOR Y ME DEVUELVA LA CADENA DE CARACTERES
int inicializarIsEmpety(eEmpleado* empleados, int tam, int estado);
int loguearEmpleado(eEmpleado* empleadoAuxliar,int estado, int* id);
int modificarEmpleado(eEmpleado* empleados);
int darDeBajaEmpleado(eEmpleado* empleados);
int ordenarAlfabeticamente(eEmpleado* empleados, int tam);
//int mostrarEmpleados(eEmpleado* empleados, int tam);
int mostrarEmpleados(eEmpleado* empleados, int tam, float resultadoAcumulado, float promedioDeSueldos, int empleadosArribaMedia);
int calcacularTotalSalarios(eEmpleado* empleados, int tam, float* resultadoAcumulado);
int promediarSalarios(eEmpleado* empleados, int tam, float totalEnSueldos,float* promedio);
int contarEmpleadosMayorSueldoMedio(eEmpleado* empleados,int tam,float promedio, int* resultado);

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
			printf("%*s",-40,"Menu principal");

			ingresarNumerosConRangoV1(&opcion,"MARQUE SEGUN QUIERA OPERAR\n"
					"1.ALTAS\n2.MODIFICAR LEGAJO\n3.BAJAS\n4.INFORMAR\n" ,"Ingrese opcion valida",1,4);
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
int ordenarAlfabeticamente(eEmpleado* empleados, int tam)
{
	int retorno=-1;
	eEmpleado auxiliar[tam];

	if(empleados!= NULL)
	{
		for(int i=0;i<tam-1;i++)
		{
			if(empleados[i].isEmpety==OCUPADO)
			{
				for(int j=i+1;j<tam;j++)
				{
					//strcmp(cadena1,cadena2)  para comparar las cadenas
					if(strcmp(empleados[i].name,empleados[j].name)>0)
					{
						//COMO SON CADENAS TENGO QUE USAR
						//strcpy(destino, origen)
						/*strcpy(auxiliar[i].name,empleados[i].name);
						strcpy(empleados[i].name,empleados[j].name);
						strcpy(empleados[j].name,auxiliar[i].name);*/
						//COMO VOY A MOVER DIRECTAMENTE TODA LA ESTRUCTURA USO EL =
						auxiliar[i]=empleados[i];
						empleados[i]=empleados[j];
						empleados[j]=auxiliar[i];

					}
				}
			}
		}
		retorno=0;
	}
	return retorno;
}

int mostrarEmpleados(eEmpleado* empleados, int tam, float resultadoAcumulado, float promedioDeSueldos, int empleadosArribaMedia )
{
	int retorno=-1;
	//eEmpleado auxiliar;
	char reAxuliar[tam][102];
	if(empleados!=NULL && tam>0)
	{
		printf("+--------------------+--------------------+-------+\n");
		printf("|%*s|%*s|%*s|\n",-20,"Empleado",-20,"Salario",-7, "Sector");//
		for(int posicion=0;posicion<tam;posicion++)
		{
			if(empleados[posicion].isEmpety==OCUPADO)
			{
				//PARA MOSTRAR TODO MEJOR PUEDO CONCATENAR NOMBRE Y APELLIDO;
				//strcat(destino, origen)
				//strcpy(destino, origen)
				strcpy(reAxuliar[posicion],empleados[posicion].name);
				strcat(reAxuliar[posicion]," ");
				strcat(reAxuliar[posicion],empleados[posicion].lastName);

				printf("|%*s|%*.2f|%*d|\n",-20,reAxuliar[posicion],-20,empleados[posicion].salary,-7,empleados[posicion].sector);
			}
		}
		printf("+--------------------+--------------------+-------+\n\n");
		printf("+------------------------------+------------------------------+------------------------------+\n");
		printf("|%*s|%*s|%*s|\n",-30,"Suma total de sueldos",-30,"Promedio de salarios",-30, "Por encima del promedio");
		printf("|%*.2f|%*.2f|%*d|\n",-30,resultadoAcumulado,-30,promedioDeSueldos,-30, empleadosArribaMedia);
		printf("+------------------------------+------------------------------+------------------------------+\n");
		retorno=0;
	}
	return retorno;
}
int calcacularTotalSalarios(eEmpleado* empleados, int tam, float* resultadoAcumulado)
{
	int retorno=-1;
	//eEmpleado auxiliar;
	float acumulador=0;
	if(empleados!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpety==OCUPADO)
			{
				acumulador=acumulador+empleados[i].salary;
			}
		}
		*resultadoAcumulado=acumulador;
		retorno=0;
	}

	return retorno;
}
int promediarSalarios(eEmpleado* empleados, int tam, float totalEnSueldos,float* promedio)
{
	int retorno=-1;
	int contadorEmpleados=0;
	if(empleados!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpety==OCUPADO)
			{
				contadorEmpleados=contadorEmpleados+1;
			}
		}
		*promedio=totalEnSueldos/contadorEmpleados;
		retorno=0;
	}
	return retorno;
}
int contarEmpleadosMayorSueldoMedio(eEmpleado* empleados,int tam,float promedio, int* resultado)
{
	int retorno=-1;
	int contadorEmpleadosMayorIngresos=0;
	if(empleados!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpety==OCUPADO && empleados[i].salary>promedio)
			{
				contadorEmpleadosMayorIngresos=contadorEmpleadosMayorIngresos+1;
			}
		}
		*resultado=contadorEmpleadosMayorIngresos;

		retorno=0;
	}


	return retorno;
}
