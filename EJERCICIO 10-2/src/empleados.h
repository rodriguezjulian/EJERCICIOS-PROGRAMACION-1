/*
 * empleados.h
 *
 *  Created on: 2 oct. 2022
 *      Author: Julian Rodriguez
 */

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
#define EMPLEADOS_H_
#ifndef EMPLEADOS_H_

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

#endif /* EMPLEADOS_H_ */
