/*
 ============================================================================
 Name        : dsada.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
int main(void) {
	setbuf(stdout,NULL);

	ePersonaEstr p1=cargarPersona(23,"mengano");
    mostrarPersona(p1);
    return 0;


	return EXIT_SUCCESS;
}
