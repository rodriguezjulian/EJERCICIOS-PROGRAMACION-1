/*
 ============================================================================
 Name        : EJERCICIO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/* Ejercicio 2-1: Ingresar 7 números negativos distintos de 0 calcular y mostrar el
promedio de los números. Probar la aplicación con distintos valores. Ejemplo
1: (-7)( - 5)( - 12) (- 1)( - 2)*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int contador;
	int numeroIngresado;
	int suma;
	float promedio;

	contador=0;
	suma=0;

	while(contador<7)
	{
		printf("Ingrese un numero entero negativo que no sea 0 \n");
		scanf("%d",&numeroIngresado);

		while(numeroIngresado>-1)
		{
			printf("ERROR, Ingrese un numero entero negativo que no sea 0 \n");
			scanf("%d",&numeroIngresado);
		}
		suma= numeroIngresado+suma;
		contador= contador + 1;
	}
	promedio=(float) suma / 7; //SE CASTEA LA VARIABLE SUMA YA QUE PRECISAMOS QUE TOME EN CUENTA A LOS DECIMALES PARA QUE EL PROMEDIO SE CALCULE CORRECTAMENTE

	printf("El promedio de los numeros ingresados es: %.2f", promedio);

	return EXIT_SUCCESS;
}
