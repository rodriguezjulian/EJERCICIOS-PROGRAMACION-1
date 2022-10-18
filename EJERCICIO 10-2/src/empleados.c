/*
 * empleados.c
 *
 *  Created on: 2 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include<string.h>
#include <ctype.h>
#include "empleados.h"
#define TAM 300
#define VACIO 1
#define OCUPADO 0

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
int validarSector(int idSector,eSector* sectores, int tam)
{
	int retorno=-1;

	for(int i=0;i<tam;i++)
	{
		if(idSector==sectores[i].idSector)
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}

int loguearEmpleado(eEmpleado* empleadoAuxliar,int estado, int* id, eSector* sectores, int tamSectores)
{
	int retorno=-1;
	int flagMensajeError=0;
	if(empleadoAuxliar!=NULL && id!=NULL)
	{
			(*empleadoAuxliar).id=*id;
			*id=*id+1;
			ingresarArrayCaracteres((*empleadoAuxliar).name,"Ingrese nombre de empleado","Error, ingrese nombre valido",51);
			ingresarArrayCaracteres((*empleadoAuxliar).lastName,"Ingrese apellido de empleado","Error, ingrese apellido valido",51);
			ingresarFloatConMinimo(&(*empleadoAuxliar).salary, "Ingrese sueldo","Ingrese sueldo valido",0);
			printf("+--------SECTORES--------+\n");
			for(int i=0;i<tamSectores;i++)
			{
				printf("|%*d|%*s|\n",-3,sectores[i].idSector,-20,sectores[i].descripcionSector);
			}
			printf("+------------------------+\n");
			do
			{
				if(flagMensajeError==1)
				{
					printf("ERROR, Ingrese sector valido\n");
				}
				ingresarIntConMinimo(&(*empleadoAuxliar).sector, "Ingrese sector del empleado\n","Ingrese sector valido\n",0);
				flagMensajeError=1;
			}while(validarSector((*empleadoAuxliar).sector,sectores,tamSectores)==-1);

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

int mostrarEmpleados(eEmpleado* empleados, int tam, float resultadoAcumulado, float promedioDeSueldos, int empleadosArribaMedia, eSector* sector, int tamSector)
{
	int retorno=-1;
	//eEmpleado auxiliar;
	char reAxuliar[tam][102];
	if(empleados!=NULL && tam>0 && sector!=NULL && tamSector>0)
	{	printf("+--------------------+--------------------+--------------------+\n");
		printf("|%*s|%*s|%*s|\n",-20,"Empleado",-20,"Salario",-20,"Sector");//
		for(int posicion=0;posicion<tam;posicion++)
		{
			for(int j=0;j<tamSector;j++)
			{
				//MANDAR NUMERO ENTERO
					if(empleados[posicion].isEmpety==OCUPADO && empleados[posicion].sector==sector[j].idSector)
					{
						//PARA MOSTRAR TODO MEJOR PUEDO CONCATENAR NOMBRE Y APELLIDO;
						strcpy(reAxuliar[posicion],empleados[posicion].name);
						strcat(reAxuliar[posicion]," ");
						strcat(reAxuliar[posicion],empleados[posicion].lastName);

						printf("|%*s|%*.2f|%*s|\n",-20,reAxuliar[posicion],-20,empleados[posicion].salary,-20,sector[j].descripcionSector);
					}
			}
		}
		printf("+--------------------+--------------------+--------------------+\n\n");
		printf("+------------------------------+------------------------------+------------------------------+\n");
		printf("|%*s|%*s|%*s|\n",-30,"Suma total de sueldos",-30,"Promedio de salarios",-30, "Por encima del promedio");
		printf("|%*.2f|%*.2f|%*d|\n",-30,resultadoAcumulado,-30,promedioDeSueldos,-30, empleadosArribaMedia);
		printf("+------------------------------+------------------------------+------------------------------+\n");

		retorno=0;
	}
	return retorno;
}
int calcularSectorConMasEmpleados(eEmpleado* empleados, int tamEmpleados, int* mayor)
{
	int retorno=-1;
	int contador100=0;
	int contador200=0;
	int contador300=0;
	int contador400=0;

	if(empleados!=NULL)
	{
		for(int i=0;i<tamEmpleados;i++)
		{
			if(empleados[i].isEmpety==OCUPADO)
			{
				switch(empleados[i].sector)
				{
				case 100:
					contador100=contador100+1;
				break;
				case 200:
					contador200=contador200+1;
				break;
				case 300:
					contador300=contador300+1;
				break;
				case 400:
					contador400=contador400+1;
				break;

				}
			}
		}
		if(contador100>contador200 && contador100>contador300 && contador100>contador400)
		{
			*mayor=contador100;
		}
		else
		{
			if(contador200>contador300 && contador200>contador400 && contador200>contador100)
			{
				*mayor=contador200;
			}
			else
			{
				if(contador300>contador400)
				{
					*mayor=contador300;
				}
				else
				{
					*mayor=contador400;
				}
			}

		}



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
