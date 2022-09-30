/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J EJERCICIO 10-1
#include <stdio.h>
#include <stdlib.h>

	typedef struct
	{
		char calle[10];
		int numero;
		char localidad[20];
		char provincia[20];
	}eDireccion;


	typedef struct
	{
		int idProveedor;
		char razonSocial[20];
		eDireccion direccion ;
	}eProveedor;
	//La relacion seria meter el id del proveedor en la estructura de producto
	//un proveedor por producto, pero un proveedor puede vender varios productos (1,1--------1,n)
	typedef struct
	{
		int idProducto;
		char descripcion[20];
		float precio;
		int idProveedor;

	}eProducto;
//<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>
 typedef struct
 {
	 int idDuenio;
	 char nombre[51];
	 int edad;
	 char sexo[10];

 }eDuenio;

 typedef struct
 {
	 char origen[10];
	 char raza[10];
 }eRaza;
 // un dueño puede tener muchas mascotas, pero la mascota solo un dueño (1,n ------1,1)
 typedef struct
 {
	 int idMascota;
	 char nombre[51];
	 eRaza raza;
	 char sexo[10];
	 int idDuenio;
 }eMascota;
 //<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>

 typedef struct
 {
	 int idLocalidad;
	 char descripcion[20];
	 int codigoPostal;
 }eLocalidad;
typedef struct
{
	int idAlumno;
	char nombre[51];
	char idLocalidad;
}eAlumno;

int main(void) {


	return EXIT_SUCCESS;
}
