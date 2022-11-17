/*
 ============================================================================
 Name        : Pruebitas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int vec[4]= {0,5,10,15};
	int* pvec=vec;
	pvec++;
	printf("%d",*pvec+3);
	return EXIT_SUCCESS;
}
