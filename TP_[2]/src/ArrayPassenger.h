/*
 * ArrayPassenger.h
 *
 *  Created on: 12 may. 2022
 *      Author: ibarr
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define TRUE 0
#define FALSE 1
#define T 51
typedef struct
{
	int statusFlight;
	char status[T];

}eStatusFlight;

typedef struct{
	int typePassenger;
	char clase[T];
}etypePassenger;

typedef struct{
	int id;
	char name[T];
	char lastName[T];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
	int statusFlight;
}Passenger;

int initPassengers(Passenger* list, int len);

void pedirPasajero (Passenger* list);

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight);

int imprimirPasajeros(Passenger array[],int tam);

int findPassengerById(Passenger* list, int len,int id);

void modificarPasajero(Passenger list[],int tam);

void bajarPasajero(Passenger list[],int tam);

int removePassenger(Passenger* list, int len, int id);

int sortPassengers(Passenger list[], int len, int order);

void calcularPromediosPasajeros(Passenger list[],int tam);

void cargarEstados(eStatusFlight array[],int tam);

#endif /* ARRAYPASSENGER_H_ */
