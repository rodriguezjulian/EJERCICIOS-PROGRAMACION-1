/*
 * compras.h
 *
 *  Created on: 16 nov. 2022
 *      Author: Julian Rodriguez
 */

#ifndef COMPRAS_H_
#define COMPRAS_H_
typedef struct
{
	int codigoCompra;
	char descripcionCompra[100];
	int origenCompra;
	float precioUnitarioCompra;
	int cantidadCompra;
	float totalCompra;

}eCompras;

eCompras* compras_new();
void compra_Delete(eCompras* this);
eCompras* compras_newParametros(char* codigoCompra,char* descripcionCompra,char* origenCompra, char* precioUnitarioCompra,char*cantidadCompra,char* totalCompra);
int compras_getTotal(eCompras* this, float* totalCompra);
int compras_getCantidad(eCompras* this, int* cantidadCompra);
int compras_getPrecioUnitario(eCompras* this, float* precioUnitarioCompra);
int compras_getOrigen(eCompras* this, int* origenCompra);
int compras_getDescripcion(eCompras* this, char* descripcionCompra);
int compras_getCodigo(eCompras* this,int* codigoCompra);
int compras_setCodigo(eCompras* this,int codigoCompra);
int compras_setDescripcion(eCompras* this,char* descripcion);
int compras_setOrigen(eCompras* this,int origen);
int compras_setPrecioUnitario(eCompras* this,float PrecioUnitario);
int compras_setCantidad(eCompras* this,int cantidad);
int compras_setTotal(eCompras* this,float total);
#endif /* COMPRAS_H_ */
//data.csv
