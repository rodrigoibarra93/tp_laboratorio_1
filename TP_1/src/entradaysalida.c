/*
 * entradaysalida.c
 *
 *  Created on: 14 abr. 2022
 *      Author: ibarr
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "entradaysalida.h"
#include "validaciones.h"


float pedirFloatAcotado(char mensaje[], int minimo, int maximo,char mensajeError[]){

	float respuesta;
	int aux=0;

	respuesta=pedirFloat(mensaje);
	aux=ValidarNumeroFloat(respuesta,minimo,maximo);

	if(aux==1)
	{
		printf(mensajeError);
		return 0;
	}
	else
	{
	 return respuesta;
	}



}

float pedirFloat(char mensaje[]){

	float respuesta;
	printf(mensaje);
	scanf("%f", &respuesta);
	return respuesta;
}

int pedirInt(char mensaje[]){

	int respuesta;
	printf(mensaje);
	scanf("%d", &respuesta);
	return respuesta;
}
void informarResultado(float a,float b,float c,float d,float e,char mensaje[]){

	printf("\nPrecio %s: $%.2f\n",mensaje, a);
	printf("a) Precio con tarjeta de debito: $%.2f\n",b);
	printf("b) Precio con tarjeta de credito:$%.2f\n",c);
	printf("c) Precio pagando con bitcoin :  $%f\n",d);
	printf("d) Precio unitario: $%.2f\n", e);


}
