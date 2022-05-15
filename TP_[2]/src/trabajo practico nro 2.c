/*
 ============================================================================
 Name        : trabajo.c
 Author      : rodrigo ibarra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ArrayPassenger.h"
#include "funciones.h"
#define T 51
#define tam 2000


int main(void) {
	system("cls");
	setbuf(stdin,NULL);
	int exit=0;

	Passenger Pasajero[tam];

	initPassengers(Pasajero,tam);


	do
	{
		switch(menuPrincipal())
		{

			case 1:
					Altas(Pasajero,tam);
				break;
			case 2:
					Modificar(Pasajero,tam);
				break;
			case 3:
					Baja(Pasajero,tam);
				break;
			case 4:
					Listar(Pasajero,tam);
				break;
			case 5:
					altaForzada(Pasajero,tam);

					break;
			case 6:
				exit=1;
				break;

		}
	}while(exit!=1);
	system("pause");

	return EXIT_SUCCESS;
}
