/*
 * empleado.h
 *
 *  Created on: 2 nov. 2022
 *      Author: Julian Rodriguez
 */

#ifndef EMPLEADO_C_
#define EMPLEADO_C_
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmpleado;
typedef struct
{
	int idSector;
	char descripcionSector[50];
}eSector;

void inicializarIsEmpety(eEmpleado* empleados, int tam);
int loguearEmpleado(eEmpleado** empleados,int estado, int* id , int* contadorEmpleados, eSector* sectores);
int modificarEmpleado(eEmpleado* empleados,int contadorEmpleados, eSector* sectores);
int darDeBajaEmpleado(eEmpleado* empleados,int *contadorEmpleados);
int ordenarAlfabeticamente(eEmpleado* empleados, int tam);
int mostrarEmpleados(eEmpleado* empleados, int tam, float resultadoAcumulado, float promedioDeSueldos, int empleadosArribaMedia, int referencia,eSector* sectores);
int calcacularTotalSalarios(eEmpleado* empleados, int tam, float* resultadoAcumulado);
int promediarSalarios(eEmpleado* empleados, int tam, float totalEnSueldos,float* promedio);
int contarEmpleadosMayorSueldoMedio(eEmpleado* empleados,int tam,float promedio, int* resultado);
int contarIteraciones(eEmpleado* empleados,int* iteraciones, int tam, int idModificar);
void mostrarSectores(eSector* sectores, int tam);
int verificarSectorIngresado(eSector* sectores, int idBuscado, int tamSectores);
int asignarDescripcion(eEmpleado* empleados,eSector* sectores,int tamSectores, char* descripcion ,int posicion);
int buscarSectoresMasEmp(eSector* sectores, eEmpleado* empleados, int tamEmpleados, int tamSectores, int* sectorMasPopular);
void imprimirSectorConMasEmpleados(eSector* sectores, eEmpleado* empleados, int tamEmpleados, int tamSectores);
#endif /* EMPLEADO_C_ */
