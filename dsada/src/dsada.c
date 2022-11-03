#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int arrayRemove(int array[], int *tam, int valueRemove);
void arrayPrint(int array[], int tam);

int main(void) {
	setbuf(stdout, NULL);

	int sizeArray = 5;
	int *array = (int*) malloc(sizeof(int) * sizeArray);

	for (int i = 0; i < sizeArray; i++) {
		*(array + i) = i + 1;
	}

	*(array + 3) = 2;
	arrayPrint(array, sizeArray);
	arrayRemove(array, &sizeArray, 2);
	arrayPrint(array, sizeArray);

	return 0;
}

int arrayRemove(int array[], int *tam, int valueRemove) {
	/*
	 * La función se encargará de buscar el valor
	 * entero y borrará la primera ocurrencia del mismo.
	 * El array deberá reestructurarse dinámicamente.
	 */
	int rtn = 0;

	//BUSQUEDA
	int index = -1;
	for (int i = 0; i < (*tam); i++) {
		if (*(array + i) == valueRemove) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		for (int i = index; i < (*tam) - 1; i++) {
			*(array + i) = *(array + (i + 1));
		}
	}

	//REDIMENSIONAR
	int *pAux = (int*) realloc(array, sizeof(int) * ((*tam) - 1));

	if (pAux != NULL) {
		array = pAux;
		(*tam)--;
	}

	return rtn;
}

void arrayPrint(int array[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
}


