
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 14-2
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "empleado.h"
#include "ingresos.h"

//#include "sector.h"

#define TAM 1000
#define VACIO 1
#define OCUPADO 0
//Empleado* crearEmpleado(void);
//eEmpleado* crearEmpleado(void);//Constructor Por defecto
/*int inicializarArrayEmpleados(eEmpleado* arrayPunteros, int limite);
int buscarLibreArray(eEmpleado* arrayPunteros, int limite, int* posicionLibre);*/
//int mostrarEmpleadoNueva(eEmpleado* empleados, int contadorEmpleados, eSector* sectores);
void construirEmpleado(eEmpleado empleadoAux,eEmpleado** empleados, int* contadorEmpleados );
void mostrarEmpleadosnuevo(int contadorEmpleados, eEmpleado* empleados);
int main(void) {
	setbuf(stdout,NULL);

	int id=0;
	int opcion;
	//MEMORIA DINAMICA
	//TENGO QUE REASIGNAR EL TAMANIO SEGUN SE REQUIERA, TENIENDO COMO MINIMO 1 EMPLEADO.
	//TENDRIA QUE UTILIZAR realloc para sumar espacio al loguear y tambien cuando doy de baja???

	float resultadoAcumulado;
	float promedioDeSueldos;
	int empleadosArribaMedia;
	int contadorEmpleados=1;
	eEmpleado* empleados;

	empleados=(eEmpleado*) malloc(sizeof(eEmpleado)*TAM);
	//ARMAR FUNCION TENIENDO EN CUENTA TAMANIO POR #DEFINE
	//(*(empleados+0)).id=0;
	inicializarIsEmpety(empleados, TAM);


	//FSCANF OBTENGO INFORMACION DEPENDIENDO LA ESTRUCTURA
	//FILE * fopen (const char *Path_al_archivo , const char *Modo)

	//PRIMERO QUE NADA LEO AL ARCHIVO


	//CONTAR TODO Y MANTENER EN MEMORIA
	//AL SALIR SIN GUARDAR PEDIR CONFIRMACION (FLAG)
	eEmpleado empleadoAux;

	FILE* pArchivos;
	int cantidad;
	char var[50];
	pArchivos=fopen ("data - data.csv", "r");
	if(pArchivos !=NULL)
	{

		puts("SE ABRIO");
		cantidad=0;
		int r;
		while(!feof(pArchivos))
		{

			if(cantidad==0)
			{
				r=fscanf(pArchivos,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var,var,var,var,var);
				cantidad++;
			}
			//FREAD MAS PARA BINARIOS  -  FSCANF MAS PARA TEXTO
			if(cantidad==1)
			{
				//printf("<<<<<<<<<<LEER>>>>>>>>>>\n");
				//ESCANEO ENTERO, ESCANEO LA , SOLO PARA MOVER EL PUNTERO A
				//LA CADENA DE CARACTERES.
				r=fscanf(pArchivos,"%d,%[^,],%[^,],%f,%d\n",&(empleadoAux.id),empleadoAux.name,empleadoAux.lastName,&(empleadoAux.salary),&(empleadoAux.sector));
				printf("%d\n",r);
				//%[^,] EXPRESION REGULAR PARA ESCANEAR DATOS SIN COMA, INCLUYENDO
				//LOS ESPACIOS. EL %s ME CORTA EN LOS ESPACIOS.
				//fscanf(pArchivos,"%[^,],",&empleadoAux.name);
				/*fscanf(pArchivos,"%[^,],",&empleadoAux.lastName);
				fscanf(pArchivos,"%.2f,",&empleadoAux.salary);
				//MUEVO EL PUNTERO A LA SIGUIENTE FILA, SALTEANDO AL \n
				fscanf(pArchivos,"%d\n",&empleadoAux.sector);*/
				construirEmpleado(empleadoAux,&empleados,&contadorEmpleados);
			}
		}
	}
	else
	{
		printf("ERROR AL ABRIR EL ARCHIVO");
	}
	fclose(pArchivos);

	//printf("CONTADOR EMPLEADOS %d" ,contadorEmpleados);
	//AHORA VOY A ESCRIBIR ESTO EN EL ARCHIVO
	/*cantidad=fwrite(&empleados,sizeof(empleados),1,pArchivos);
    if (cantidad < 1){
        printf("\n error al escribir");}
    else
    {
    	printf("\n escritura normal");
    }*/


	eSector sectores[4]=
	{
			{100,"Sistemas"},
			{200,"RecursosHumanos"},
			{300,"Administracion"},
			{400,"Gerencia"}
	};


	do
	{
		ingresarNumerosConRangoV1(&opcion,"MARQUE SEGUN QUIERA OPERAR\n"
				"1.ALTAS\n2.MODIFICAR LEGAJO\n3.BAJAS\n4.INFORMAR\n" ,"Ingrese opcion valida\n",1,5);
		switch(opcion)
		{
		case 1:
			loguearEmpleado(&empleados,OCUPADO,&id, &contadorEmpleados, sectores);
		break;
		case 2:
			modificarEmpleado(empleados,contadorEmpleados, sectores);
		break;
		case 3:
			darDeBajaEmpleado(empleados, &contadorEmpleados);
		break;
		case 4:
			if(contadorEmpleados>0)
			{
				ingresarNumerosConRangoV1(&opcion, "MARQUE SEGUN QUIERA OPERAR\n"
						"1.Empleados ordenados por nombre y sector.\n"
						"2.Total y promedio de los salarios / cuantos superan el promedio.\n"
						"3.Sector con más empleados y listado de ellos mismos", "ERROR, Ingrese opcion valida\n", 1, 3);
				switch(opcion)
				{
				case 1:
					calcacularTotalSalarios(empleados,contadorEmpleados,&resultadoAcumulado);
					promediarSalarios(empleados,contadorEmpleados,resultadoAcumulado,&promedioDeSueldos);
					contarEmpleadosMayorSueldoMedio(empleados,contadorEmpleados,promedioDeSueldos,&empleadosArribaMedia);
					mostrarEmpleados(empleados, contadorEmpleados,resultadoAcumulado,promedioDeSueldos,empleadosArribaMedia,1,sectores);
				break;
				case 2:
					ordenarAlfabeticamente(empleados, contadorEmpleados);
					mostrarEmpleados(empleados, contadorEmpleados,resultadoAcumulado,promedioDeSueldos,empleadosArribaMedia,2, sectores);
				break;
				case 3:
					imprimirSectorConMasEmpleados(sectores, empleados, contadorEmpleados, 4);

				break;
				}
			}
			else
			{
				printf("Para imprimir informes debe existir al menos 1 empleado logueado\n");
			}

		break;
		case 5:
			 mostrarEmpleadosnuevo( contadorEmpleados, empleados);
		break;
		}//
	}while(confirmarSalida()==-1);
	return EXIT_SUCCESS;
}
void construirEmpleado(eEmpleado empleadoAux,eEmpleado** empleados, int* contadorEmpleados )
{
	eEmpleado* pAux;
	if(contadorEmpleados==0)
	{
		//CON EL PRIMER * ACCEDO AL PUNTERO A LA DIRECCION ORIGINAL Y CON EL SEGUNDO * A LA POSICION ESPECIFICA EN ESTE CASO 0
		**empleados=empleadoAux;
		*contadorEmpleados=*contadorEmpleados+1;
	}
	else
	{
		pAux=(eEmpleado*) realloc (*empleados, sizeof(eEmpleado)*((*contadorEmpleados)+1));
		if(pAux!=NULL)
		{
			*empleados=pAux;
			(*(*empleados+*contadorEmpleados))=empleadoAux;
			*contadorEmpleados=*contadorEmpleados+1;
		}
	}
}
void mostrarEmpleadosnuevo(int contadorEmpleados, eEmpleado* empleados)
{

	if(empleados!=NULL)
	{

		for(int i=0;i<contadorEmpleados;i++)
		{
			printf("ID %d \n",(*(empleados+i)).id);
		}

	}
}
/*int mostrarEmpleadoNueva(eEmpleado* empleados, int contadorEmpleados, eSector* sectores)
{
	int retorno=-1;
	//char descripcionSector[50];
	for(int i=0;i<contadorEmpleados;i++)
	{
		retorno=0;
		printf("%s", (*(empleados+i)).name);
	}
	return retorno;
}*/



/*eEmpleado* crearEmpleado(void)//Constructor Por defecto
{
	eEmpleado* puntero;
	puntero=(eEmpleado*) malloc(sizeof(eEmpleado)*1);
	if(puntero!=NULL)
	{
		return puntero;
	}
	return puntero;
*/
/*eEmpleado* crearEmpleadoConParametro(int id,char name[51], char lastName[51], float salary, int sector, int isEmpty)
{
	eEmpleado* puntero;
	puntero=crearEmpleado();
	if(puntero!=NULL)
	return puntero;
}*/
/*int inicializarArrayEmpleados(eEmpleado* apunteros[], int limite)
{
	int retorno=-1;
	int i;
	if(apunteros!=NULL && limite>0)
	{
		retorno=0;
		//VOY A HACER QUE EL ARRAY VACIO APUNTE  A NULL.
		for(i=0;i<limite;i++)
		{
			(*(apunteros+i))=NULL;
		}
	}

	return retorno;
}
int buscarLibreArray(eEmpleado* arrayPunteros, int limite, int* posicionLibre)
{
	int retorno=-1;
	int i;
	if(arrayPunteros!=NULL && limite>0)
	{
		retorno=0;
		//VOY A HACER QUE EL ARRAY VACIO APUNTE  A NULL.
		for(i=0;i<limite;i++)
		{
			if((arrayPunteros+i)==NULL)
			{
				retorno=0;
				//INDICE DEL ELEMENTO LIBRE
				*posicionLibre=i;
				break;
			}
		}
	}
	return retorno;
}
*/
