/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* unPasajero;

	unPasajero = (Passenger*) malloc(sizeof(Passenger));

	return unPasajero;

}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* isEmptyStr)
{
	Passenger* unPasajero;
	unPasajero=Passenger_new();
	if(unPasajero!=NULL)
	{
		Passenger_setId(unPasajero,atoi(idStr));
		Passenger_setNombre(unPasajero,nombreStr);
		Passenger_setApellido(unPasajero,apellidoStr);

		unPasajero->precio=atof(precioStr);
		strcpy(unPasajero->tipoPasajero, tipoPasajeroStr);
		strcpy(unPasajero->codigoVuelo, codigoVueloStr);
		unPasajero->isEmpty= atoi(isEmptyStr);
	}
		return unPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	 int retorno = -1;

	 if(this != NULL && id > 0)
	 {
	    this->id = id;
	    retorno = 0;
	 }
	 return retorno;

}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno=-1;

	    if(this != NULL && id!=NULL)
	    {
	        *id = this->id;
	        retorno=0;
	    }
	    return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	 int retorno = -1;

	 if(this != NULL && nombre != NULL)
	 {
		 strcpy(this->nombre, nombre);
	 	 retorno = 0;
	 }
	 return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

		 if(this != NULL && nombre != NULL)
		 {
			 strcpy(nombre,this->nombre);
		 	 retorno = 0;
		 }
		 return retorno;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

		 if(this != NULL && apellido != NULL)
		 {
			 strcpy(this->nombre, apellido);
		 	 retorno = 0;
		 }
		 return retorno;
}
/*
int Passenger_getApellido(Passenger* this,char* apellido);
int Passenger_setPrecio(Passenger* this,float precio);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_getPrecio(Passenger* this,float* precio);
*/
