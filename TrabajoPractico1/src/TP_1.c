/*
 ============================================================================
 Name        : TP_1.c
 Author      : RODRIGUEZ JULIAN MANUEL DIV J TP.1
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//RODRIGUEZ JULIAN MANUEL DIV J TP.1
#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca_Tp.1.h"
#include "ingresos.h"
#include "calculos.h"

#define MAX 5 //MENU PRINCIPAL DE OPCIONES
#define MIN 1 //MENU PRINCIPAL DE OPCIONES
#define UEFA 35 //SI LA MAYORIA DE JUGADORES PERTENECE A UEFA SE APLICA UN 35% DE RECARGO AL COSTO DE MANTENIMIENTO.



int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int opcionSubMenu;
	float costoMantenimiento;
	float diferenciaCostoMantenimiento=0;//LO IGUALO A 0 PORQUE EN LA FUNCION INFORMAR RESULTADOS LO UTILIZO COMO FLAG
	float costoMantenimientoAumentado;
	int retornoValidarEntradaParaOpcion3;//CON ESTA MISMA VARIABLE VALIDO LA OPCION 4 EN LA FUNCION INFORMAR RESULTADO
	int porcentajeUefa;//ESTA VARIABLE AYUDA A VERIFICAR SI LA MAYORIA DE JUGADORES PROVIENEN DE LA UEFA
	/////////////////////////
	float hospedaje=0;//AUNQUE LOS PRECIOS SE TERMINEN PISANDO POR EL VALOR CARGADO, LOS PONGO EN 0 PARA LA VISTA DEL MENU
	float comida=0;
	float transporte=0;
	/////////////////////////
	int contadorArqueros=0;
	int contadorDefensores=0;
	int contadorMediocampistas=0;
	int contadorDelanteros=0;
	int contadorJugadores=0; //TAMBIEN LO USO COMO FLAG AL QUERER INGRESAR A LA OPCION 3
	/////////////////////////
	int contadorAfc=0;
	int contadorCaf=0;
	int contadorConcacaf=0;
	int contadorConmebol=0;
	int contadorUefa=0;
	int contadorOfc=0;
	/////////////////////////
	float promedioAfc=0;//IGUALO A 0 POR SI EL USUARIO NO GUARDA NINGUN JUGADOR EN ALGUNA CONFEDERACION, EVITO LA BASURA
	float promedioCaf=0;
	float promedioConcacaf=0;
	float promedioConmebol=0;
	float promedioUefa=0;
	float promedioOfc=0;
	/////////////////////////
	int flagCalculos=0;
	//int flagCostos=0; //A ESTE FLAG LO TERMINO USANDO DE CONTADOR PARA VALIDAR EL INGRESO DE TODOS LOS COSTOS
	int control; // ESTA VARIABLE CONTROLA EL RETORNO DE LA FUNCION limitarContador -1/0

	do
	{
		mostrarMenuPrincipal(hospedaje,comida,transporte,contadorArqueros,contadorDefensores,contadorMediocampistas,contadorDelanteros);

		ingresarNumerosConRangoV1(&opcion,"\nMarque opcion deseada \n","ERROR,Ingrese opcion valida\n",MIN,MAX);

		switch(opcion)
		{
			case 1:
				ingresarNumerosConRangoV1(&opcionSubMenu,"\nMarque opcion deseada\n"
						"1.Costo de hospedaje\n"
						"2.Costo de comida\n"
						"3.Costo de transporte\n","ERROR,Ingrese opcion valida",1,3);
				switch(opcionSubMenu)
				{
				//PIDO QUE EL COSTO INGRESADO SEA MINIMO 1, YA QUE UTILIZARE ESTE DATO EN LA
				//VALIDACION PARA INGRESAR A LA OPCION 3
					case 1:
						ingresarFloatConMinimo(&hospedaje,"Ingrese costo de hospedaje\n","ERROR,Ingrese costo valido\n",1);
					break;
					case 2:
						ingresarFloatConMinimo(&comida,"Ingrese costo de comida\n","ERROR,Ingrese costo valido\n",1);
					break;
					case 3:
						ingresarFloatConMinimo(&transporte,"Ingrese costo de transporte\n","ERROR,Ingrese costo valido\n",1);
					break;
				}
			break;
			case 2:
				ingresarNumerosConRangoV1(&opcionSubMenu,"\nIngrese segun corresponda posicion del jugador a cargar:\n"
						"1.Arqueros\n"
						"2.Defensores\n"
						"3.Mediocampistas\n"
						"4.Delanteros\n","ERROR,Ingrese opcion valida\n",1,4);
				switch(opcionSubMenu)
				{
					case 1:
						control=limitarContador(&contadorArqueros ,2,"ERROR, puede ingresar hasta 2 arqueros\n\n");
						ejecutarSubMenuConfederaciones(control,&contadorAfc,&contadorCaf,&contadorConcacaf,&contadorConmebol,&contadorUefa,
								&contadorOfc,&contadorJugadores);
					break;
					case 2:
						control=limitarContador(&contadorDefensores ,8,"ERROR, puede ingresar hasta 8 defensores\n");
						ejecutarSubMenuConfederaciones(control,&contadorAfc,&contadorCaf,&contadorConcacaf,&contadorConmebol,&contadorUefa,
								&contadorOfc,&contadorJugadores);
					break;
					case 3:
						control=limitarContador(&contadorMediocampistas ,8,"ERROR, puede ingresar hasta 8 mediocampistas\n");
						ejecutarSubMenuConfederaciones(control,&contadorAfc,&contadorCaf,&contadorConcacaf,&contadorConmebol,&contadorUefa,
								&contadorOfc,&contadorJugadores);
					break;
					case 4:
						control=limitarContador(&contadorDelanteros,4,"ERROR, puede ingresar hasta 4 delanteros\n");
						ejecutarSubMenuConfederaciones(control,&contadorAfc,&contadorCaf,&contadorConcacaf,&contadorConmebol,&contadorUefa,
								&contadorOfc,&contadorJugadores);
					break;
				}
			break;
			case 3:
				//SI NO ESTAN LOS 3 COSTOS NO SE PUEDE CALCULAR EL MANTENIMIENTO.
				retornoValidarEntradaParaOpcion3=validarEntradaParaOpcion3(hospedaje,comida,transporte,contadorJugadores);

				if(retornoValidarEntradaParaOpcion3==0)
				{

					flagCalculos=1;
					costoMantenimiento=hospedaje+comida+transporte;
					ejecutarCalculosPromedios(contadorJugadores,contadorAfc,&promedioAfc,contadorCaf,&promedioCaf,
											contadorConcacaf,&promedioConcacaf,contadorConmebol,&promedioConmebol,contadorUefa,&promedioUefa,contadorOfc,&promedioOfc);

					porcentajeUefa=contadorUefa*100/contadorJugadores;

					if(porcentajeUefa>50)
					{
						diferenciaCostoMantenimiento=(UEFA*costoMantenimiento/100);
						costoMantenimientoAumentado=diferenciaCostoMantenimiento+costoMantenimiento;
					}
				}
			break;
			case 4:
					informarResultados( flagCalculos,  promedioAfc, promedioCaf, promedioConcacaf, promedioConmebol, promedioUefa,  promedioOfc,  costoMantenimiento, diferenciaCostoMantenimiento,costoMantenimientoAumentado);
					ingresarIntConMensaje(&opcion,"Si desea salir presione 5, para seguir operando presione cualquier otro numero\n");
					mostrarMensajeSalida(opcion);
			break;
			case 5:
				mostrarMensajeSalida(opcion);
			break;
		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}









