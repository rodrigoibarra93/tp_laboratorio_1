/*
 * funciones.c
 *
 *  Created on: 12 may. 2022
 *      Author: ibarr
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "funciones.h"
#include "ArrayPassenger.h"


int banderaAlta=1;

/**
 * \fn void Altas(Passenger[], int)
 * \brief	funcion para carga UN solo pasajero
 * \param list
 * \param tam
 */
void Altas(Passenger list[], int tam)
{
	Passenger aux;
	pedirPasajero(&aux);

	addPassenger(list,tam,aux.id,aux.name,aux.lastName,aux.price,aux.typePassenger,aux.flycode,aux.statusFlight);
	banderaAlta=0;
	system("pause");
}

/**
 * \fn void Modificar(Passenger[], int)
 * \brief modifica un dato del tipo de dato pasajero de un array de pasajeros
 * \param list
 * \param tam
 */
void Modificar(Passenger list[], int tam)
{

	if(banderaAlta==0)
	{
		imprimirPasajeros(list,tam);
		modificarPasajero(list,tam);
	}
	else
	{
		printf("Todavia no se cargo ningun pasajero\n");
		system("pause");
	}

}

/**
 * \fn void Baja(Passenger[], int)
 * \brief hace un eliminacion logica cambiar isEmpty camambiando el estado a libre
 * \param list
 * \param tam
 */
void Baja(Passenger list[], int tam)
{
	int id;
	int r;

	if(banderaAlta==0)
	{

		imprimirPasajeros(list,tam);
		id=pedirEnteroPositivoVALIDO("ingrese numero de id del PASAJERO a dar de BAJA\n","ERROR\n",0);
		r=removePassenger(list,tam,id);
		if(r==0)
		{
			printf("Baja Exitosa\n");
			system("pause");
		}
		else if(r==-1)
		{
			printf("No se encontro el Pasajero\n");
			system("pause");
		}

	}
	else
	{
		printf("Todavia no se cargo ningun pasajero\n");
		system("pause");
	}

}


/**
 * \fn void Listar(Passenger[], int)
 * \brief muestra por pantalla a los pasajeros ordenados por apellido de maneda descendiente,
 * calcula promedio de precio y muestra por pantalla
 * \param list
 * \param tam
 */
void Listar(Passenger list[], int tam)
{
	if(banderaAlta==0)
	{
		sortPassengers(list,tam,1);
		imprimirPasajeros(list,tam);
		calcularPromediosPasajeros(list,tam);
		system("pause");
	}
	else
	{
		printf("Todavia no se cargo ningun pasajero\n");
		system("pause");
	}
}


/**
 * \fn void altaForzada(Passenger[], int)
 * \brief alta forzada de cierta cantidad de pasajeros, estan hardcodeados
 * \param list
 * \param tam
 */
void altaForzada(Passenger list[],int tam)
{
	int i;

	Passenger aux[]={{1245,"Kike","Acevedo",2.5,"EA1TR5",2,TRUE,1},
					 {1002,"Jorge","Bauler",3.5,"TY3CV7",1,TRUE,1},
					 {1055,"Maria","Acarosi",7.1,"BN7KJ9",3,TRUE,2},
					 {1004,"Armaldo","Caseres",2.1,"FG1CC6",2,TRUE,1},
					 {1025,"Alexa","DiMarco",6.8,"QW7YT0",1,TRUE,1},
					 {1980,"Enrique","Baxter",7.9,"GB9NT2",1,TRUE,3}};



	for(i=0;i<6;i++)
	{
		addPassenger(list,tam,aux[i].id,aux[i].name,aux[i].lastName,aux[i].price,aux[i].typePassenger,aux[i].flycode,aux[i].statusFlight);
	}
	banderaAlta=0;
	printf("carga forzada exitosa!\n");
	system("pause");
}

