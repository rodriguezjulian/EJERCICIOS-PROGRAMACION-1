#include <stdio.h>
#include <stdlib.h>

struct Empresa
{
    char nombreEmp[20];
};

struct Empresa cargaEmpleadoTec();///CARGA ESTRUCTURA PRINCIPAL
void mostrarEmpresa(struct Empresa p);///MOSTRAR EMPRESA

int main()
{
	setbuf(stdout,NULL);
	struct Empresa empresa1;
	char prueba[]="HOLA";
 	empresa1=cargaEmpleadoTec();

    mostrarEmpresa(empresa1);

    return 0;
}

///IMPLEMENTACION
struct Empresa cargaEmpleadoTec()
{
    struct Empresa p;

    printf("Ingrese el nombre de la empresa\n");
    fflush(stdin);
    gets(p.nombreEmp);

    return p;
 }
void mostrarEmpresa(struct Empresa p)
{
    printf("Nombre de la empresa: %s\n",p.nombreEmp);
}

