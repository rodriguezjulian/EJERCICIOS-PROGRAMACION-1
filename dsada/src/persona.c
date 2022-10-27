/*
 * persona.c
 *
 *  Created on: 22 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include <string.h>
///IMPLEMENTACION

ePersonaEstr cargarPersona(int e, char n[20]){
     ePersonaEstr p;
    p.edad=e;
    strcpy(p.nombre,n);
    return p;
    }

void mostrarPersona(ePersonaEstr p){
    printf("Nombre: %s\n",p.nombre);
    printf("Edad: %d",p.edad);
    }
