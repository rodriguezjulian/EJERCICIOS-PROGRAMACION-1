/*
 * empleado.c
 *
 *  Created on: 2 nov. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

#include "ingresos.h"
#include "empleado.h"

#define TAM 300
#define VACIO 1
#define OCUPADO 0
void mostrarSectores(eSector* sectores, int tam)
{
	if(sectores!=NULL && tam>0)
	{
		printf("+========================================================+\n");
		printf("%*s|%*s|\n",-6,"  ID  ",-50,"                   SECTORES");
		printf("+========================================================+\n");
		for(int i=0;i<tam;i++)
		{
			printf("  %*d|%*s|\n",-4,(*(sectores+i)).idSector,-50,(*(sectores+i)).descripcionSector);
		}

		printf("+========================================================+\n");
	}
	else
	{
		printf("ERROR, para listar sectores debe al menos existir 1 logueado");
	}
}
int verificarSectorIngresado(eSector* sectores, int idBuscado, int tamSectores)
{
	int retorno=-1;
	if(sectores!=NULL)
	{
		for(int i=0;i<tamSectores;i++)
		{
			if((*(sectores+i)).idSector==idBuscado)
			{
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}
int asignarDescripcion(eEmpleado* empleados,eSector* sectores,int tamSectores, char* descripcion ,int posicion)
{
	int retorno=-1;


		if(empleados!=NULL && sectores!=NULL)
		{
			retorno=0;
			for(int i=0;i<tamSectores;i++)
			{
				if((*(empleados+posicion)).sector==(*(sectores+i)).idSector)
				{
					strcpy(descripcion,(*(sectores+i)).descripcionSector);
				}
			}
		}
	return retorno;
}
int inicializarIsEmpety(eEmpleado* empleados, int tam, int estado)
{
	int retorno=OCUPADO;
	if(empleados!=NULL  && tam>0)
	{
		for(int i=0;i<TAM;i++)//HABRIA QUE PASARLO A UNA FUNCION.
		{
			(*(empleados+i)).isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}
		retorno=0;
	}
	return retorno;
}
int loguearEmpleado(eEmpleado* empleados,int estado, int* id , int* contadorEmpleados,eSector* sectores)
{
	int retorno=-1;
	eEmpleado empleadoAuxliar;
	int flagSectores=0;
	if(empleados!=NULL && id!=NULL)
	{

			*id=*id+1;
			*contadorEmpleados=*contadorEmpleados+1;
			(empleadoAuxliar).id=*id;
			ingresarArrayCaracteres(empleadoAuxliar.name,"Ingrese nombre de empleado","Error, ingrese nombre valido",51);
			ingresarArrayCaracteres(empleadoAuxliar.lastName,"Ingrese apellido de empleado","Error, ingrese apellido valido",51);
			ingresarFloatConMinimo(&empleadoAuxliar.salary, "Ingrese sueldo","Ingrese sueldo valido",0);
			mostrarSectores(sectores, 4);
			do{
				ingresarIntConMinimo(&empleadoAuxliar.sector, "Ingrese sector del empleado","Ingrese sector valido",0);
				if(verificarSectorIngresado(sectores, empleadoAuxliar.sector, 4)==-1)
				{
					printf("ERROR, ingrese sector valido\n");
				}
				else
				{
					flagSectores=1;
				}
			}while(flagSectores==0);

			empleadoAuxliar.isEmpty=estado;

			for(int i=0;i<TAM;i++)
			{
				if((*(empleados+i)).isEmpty==VACIO)
				{
					(*(empleados+i))=empleadoAuxliar;
					break;
				}
			}
			retorno=0;
	}

	return retorno;
}

int contarIteraciones(eEmpleado* empleados,int* iteraciones, int tam, int idModificar)
{
	int flag=0;

	int retorno=-1;
	if(empleados!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if((*(empleados+i)).id==idModificar && (*(empleados+i)).isEmpty==OCUPADO)
			{
				flag=1;
				retorno=0;
				*iteraciones=i;
				break;
			}
		}
		if(flag==0)
		{
			printf("ERROR, Ingrese ID valido\n");
		}
	}

	return retorno;
}
int modificarEmpleado(eEmpleado* empleados, int tam, int contadorEmpleados, eSector* sectores)
{
	int retorno=-1;
	int posicion;
	int opcion;
	int idModificar;
	int flagSectores=0;
	if(empleados!=NULL &&  contadorEmpleados>0)
	{
		do{
			ingresarIntConMensaje(&idModificar,"Ingresar numero identificacion ID de empleado a modificar");
		}while(contarIteraciones(empleados,&posicion,tam,idModificar)==-1);

		if(empleados[posicion].isEmpty==OCUPADO)
		{
			ingresarNumerosConRangoV1(&opcion,"MARQUE SEGUN QUIERA MODIFICAR\n"
					"1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n" ,"Ingrese opcion valida",1,4);
			switch(opcion)
			{
				case 1:
					ingresarArrayCaracteres((*(empleados+posicion)).name,"Ingrese nombre de empleado","Error, ingrese nombre valido",51);
				break;
				case 2:
					ingresarArrayCaracteres((*(empleados+posicion)).lastName,"Ingrese apellido de empleado","Error, ingrese apellido valido",51);
				break;
				case 3:
					ingresarFloatConMinimo(&(*(empleados+posicion)).salary, "Ingrese sueldo","Ingrese sueldo valido",0);
				break;
				case 4:
					do{
						ingresarIntConMinimo(&(*(empleados+posicion)).sector, "Ingrese nuevo sector del empleado","Ingrese sector valido",0);
						if(verificarSectorIngresado(sectores, empleados[posicion].sector, 4)==-1)
						{
							printf("ERROR, ingrese sector valido\n");
						}
						else
						{
							flagSectores=1;
						}
					}while(flagSectores==0);

				break;
			}
			retorno=0;
		}
	}
	else
	{
		printf("Para modificar a un empleado debe existir como minimo 1 logueado\n");
	}
	return retorno;
}
int darDeBajaEmpleado(eEmpleado* empleados, int tam,int *contadorEmpleados)
{
	int retorno=-1;
	int posicion;
	int idModificar;

	if(empleados!=NULL && *contadorEmpleados>0)
	{
		do{
			ingresarIntConMensaje(&idModificar,"Ingresar numero identificacion ID de empleado a dar de baja\n");
		}while(contarIteraciones(empleados,&posicion,tam,idModificar)==-1);

		if(empleados[posicion].isEmpty==OCUPADO)
		{
			*contadorEmpleados=*contadorEmpleados-1;
			(*(empleados+posicion)).isEmpty=VACIO;
			retorno=0;
			printf("<<<<<<<<<<EMPLEADO DADO DE BAJA>>>>>>>>>>\n");
		}
	}
	else
	{
		printf("Para dar de baja a un empleado debe existir como minimo 1 logueado\n");
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
			if((*(empleados+i)).isEmpty==OCUPADO)
			{
				for(int j=i+1;j<tam;j++)
				{
					//strcmp(cadena1,cadena2)  para comparar las cadenas
					if(strcmp(empleados[i].name,empleados[j].name)>0)
					{
						//COMO VOY A MOVER DIRECTAMENTE TODA LA ESTRUCTURA USO EL =
						(*(auxiliar+i))=(*(empleados+i));
						(*(empleados+i))=(*(empleados+j));
						(*(empleados+j))=(*(auxiliar+i));

					}
				}
			}
		}
		retorno=0;
	}
	return retorno;
}

int mostrarEmpleados(eEmpleado* empleados, int tam, float resultadoAcumulado, float promedioDeSueldos, int empleadosArribaMedia , int referencia,eSector* sectores)
{
	int retorno=-1;
	char reAxuliar[tam][102];
	char descripcionSector[50];
	if(empleados!=NULL && tam>0)
	{
		//REFERENCIA=1 INFORME 1 | ORDENANDO POR NOMBRE Y SECTOR
		//REFERENCIA=1 INFORME 1 | Total y promedio de los salarios / cuantos superan el promedio.
		if(referencia==1)
		{
			printf("+--------------------+--------------------+----------+-------------------------+\n");
			printf("|%*s|%*s|%*s|%*s|\n",-20,"Empleado",-20,"Salario",-10, "ID SECTOR",-25,"         SECTOR");
			printf("+--------------------+--------------------+----------+-------------------------+\n");
			for(int posicion=0;posicion<tam;posicion++)
			{
				if((*(empleados+posicion)).isEmpty==OCUPADO)
				{
					//PARA MOSTRAR TODO MEJOR PUEDO CONCATENAR NOMBRE Y APELLIDO;
					//strcat(destino, origen)
					//strcpy(destino, origen)
					strcpy((*(reAxuliar+posicion)),(*(empleados+posicion)).name);
					strcat((*(reAxuliar+posicion))," ");
					strcat((*(reAxuliar+posicion)),(*(empleados+posicion)).lastName);

					asignarDescripcion(empleados,sectores,4, descripcionSector , posicion);

					printf("|%*s|%*.2f|   %*d|%*s|\n",-20,(*(reAxuliar+posicion)),-20,(*(empleados+posicion)).salary,-7,(*(empleados+posicion)).sector,-25,descripcionSector);
				}
			}
			printf("+--------------------+--------------------+----------+-------------------------+\n");
			retorno=0;
		}
		else
		{
			if(referencia==2)
			{
				printf("+------------------------------+------------------------------+------------------------------+\n");
				printf("|%*s|%*s|%*s|\n",-30,"Suma total de sueldos",-30,"Promedio de salarios",-30, "Por encima del promedio");
				printf("|%*.2f|%*.2f|%*d|\n",-30,resultadoAcumulado,-30,promedioDeSueldos,-30, empleadosArribaMedia);
				printf("+------------------------------+------------------------------+------------------------------+\n");
				retorno=0;
			}
			else
			{
				printf("ERROR al cargar referencia de informe\n");
			}
		}
		retorno=0;
	}
	return retorno;
}

int calcacularTotalSalarios(eEmpleado* empleados, int tam, float* resultadoAcumulado)
{
	int retorno=-1;
	float acumulador=0;
	if(empleados!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if((*(empleados+i)).isEmpty==OCUPADO)
			{
				acumulador=acumulador+(*(empleados+i)).salary;
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
			if((*(empleados+i)).isEmpty==OCUPADO)
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
			if((*(empleados+i)).isEmpty==OCUPADO && (*(empleados+i)).salary>promedio)
			{
				contadorEmpleadosMayorIngresos=contadorEmpleadosMayorIngresos+1;
			}
		}
		*resultado=contadorEmpleadosMayorIngresos;

		retorno=0;
	}
	return retorno;
}
int buscarSectoresMasEmp(eSector* sectores, eEmpleado* empleados, int tamEmpleados, int tamSectores, int* sectorMasPopular)
{
	int retorno=-1;
	int acumuladorSectores[tamSectores];//INICIALIZO EN 0 POR SER UN CONTADOR
	for(int i=0;i<tamSectores;i++)
	{
		(*(acumuladorSectores+i))=0;
	}
	int resultadoAux;
	int flag=0;

	if(sectores!=NULL && empleados!=NULL)
	{
		retorno=0;
		for(int i=0;i<tamSectores;i++)
		{
			for(int j=0;j<tamEmpleados;j++)
			{
				if((*(empleados+j)).isEmpty==OCUPADO && (*(sectores+i)).idSector==(*(empleados+j)).sector)
				{
					(*(acumuladorSectores+i))=(*(acumuladorSectores+i))+1;
				}
			}
			if(flag==0)
			{
				flag=1;
				resultadoAux=(*(sectores+i)).idSector;
			}
			else
			{
				if(resultadoAux<(*(acumuladorSectores+i)))
				{
					resultadoAux=(*(sectores+i)).idSector;
				}
			}
		}

		*sectorMasPopular=resultadoAux;
	}
	return retorno;
}


void imprimirSectorConMasEmpleados(eSector* sectores, eEmpleado* empleados, int tamEmpleados, int tamSectores)
{

	int sectorMasPopular;
	char nombreApellido[100];
	buscarSectoresMasEmp(sectores, empleados, tamEmpleados, tamSectores, &sectorMasPopular);
	printf("+=================================================================================+\n");
	printf("|%*s|%*s|\n",-10,"ID SECTOR",-70,"EMPLEADO");
	printf("+=================================================================================+\n");
	for(int i=0;i<tamEmpleados;i++)
	{
		strcpy(nombreApellido,(*(empleados+i)).name);
		strcat(nombreApellido," ");
		strcat(nombreApellido, (*(empleados+i)).lastName);

		if((*(empleados+i)).isEmpty==OCUPADO && (*(empleados+i)).sector==sectorMasPopular)
		{
			printf("|%*d|%*s|\n",-10,(*(empleados+i)).sector,-70,nombreApellido);
		}
	}
	printf("+=================================================================================+\n");


}

