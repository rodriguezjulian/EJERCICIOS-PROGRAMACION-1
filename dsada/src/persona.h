/*
 * persona.h
 *
 *  Created on: 22 oct. 2022
 *      Author: Julian Rodriguez
 */

#ifndef PERSONA_H_
#define PERSONA_H_


typedef struct{
    int edad;
    char nombre[20];
    }ePersonaEstr;

ePersonaEstr cargarPersona(int e, char n[20]);

void mostrarPersona(ePersonaEstr p);

#endif /* PERSONA_H_ */
