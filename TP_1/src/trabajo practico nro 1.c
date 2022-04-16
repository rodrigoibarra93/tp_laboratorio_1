/*
 ============================================================================
 Name        : trabajo practico nro 1.c
 Author      : Rodrigo Ibarra
 Version     : v1.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "validaciones.h"
#include "entradaysalida.h"
#include "calculos.h"

int main(void) {

	setbuf(stdout,NULL);
	int exit=0;
	float x=0;
	float y=0;
	float z=0;
	float ay=0;
	float by=0;
	float cy=0;
	float dy=0;
	float az=0;
	float bz=0;
	float cz=0;
	float dz=0;
	float e=0;
	int bandera1=0;
	int bandera2=0;
	int bandera3=0;
	int bandera5=0;

	do
	{
		switch(Menu(x,y,z))
		{


		case 1:
			x=pedirFloatAcotado("Ingrese cantidad de kilometros: ", 0,999999999,"ingreso un numero no valido");
			bandera1=1;
		break;


		case 2:
			y=pedirFloatAcotado("Ingrese el precio de Aerolineas:",0,999999999,"ingreso un numero no valido");
			z=pedirFloatAcotado("Ingrese el precio de Latam:",0,999999999,"ingreso un numero no valido");
			bandera2=1;
		break;


		case 3:
			if(y == 0 && z == 0){
				printf("no se ingresaron vuelos\n");
				system("pause");
			}
			else if(x==0){
				printf("no se ingresaron kilometros\n");
				system("pause");
			}
			else{
				ay=multiplicar(y,0.9);
				by=multiplicar(y,1.25);
				cy=dividir(y,4606354.55);
				dy=dividir(y,x);

				az=multiplicar(z,0.9);
				bz=multiplicar(z,1.25);
				cz=dividir(z,4606354.55);
				dz=dividir(z,x);
				e=y-z;
				if(e<0){
					e=e*-1;
				}
				printf("\ncalculando");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf("Listo!\nPresione 4 para informar");
				Sleep(3000);
				bandera3=1;
				}
		break;


		case 4:
			if(bandera3==1){
				system("cls");
				printf("\nKms Ingresados: %.2f\n", x);
				informarResultado(y,ay,by,cy,dy,"Aerolineas");
				informarResultado(z,az,bz,cz,dz,"Latam");
				printf("\nla diferencia de precio es: $%.2f\n",e);
			}
			else{
				printf("no hay resultados a informar\n");
			}
			system("pause");
		break;


		case 5:
			if(bandera1==0 && bandera2==0){
				x=7090;
				y=162965;
				z=159339;
				bandera5=1;
			}
			else{
				printf("ya se ingresaron datos\n");
				system("pause");
			}
			if(bandera5==1){
				system("cls");
				ay=multiplicar(y,0.9);
				by=multiplicar(y,1.25);
				cy=dividir(y,4606354.55);
				dy=dividir(y,x);

				az=multiplicar(z,0.9);
				bz=multiplicar(z,1.25);
				cz=dividir(z,4606354.55);
				dz=dividir(z,x);
				e=y-z;
				if(e<0){
				e=e*-1;
				}
				printf("\nKms Ingresados: %.2f\n", x);
				informarResultado(y,ay,by,cy,dy,"Aerolineas");
				informarResultado(z,az,bz,cz,dz,"Latam");
				printf("\nla diferencia de precio es: $%.2f\n",e);
				bandera3=1;
				system("pause");
			}
		break;


		case 6:
			printf("\n\nadios!\n\n");
			system("pause");
			exit=1;
		break;
		default:
			printf("Se equivoco de opcion de menu\n");
			system("pause");
		}

	}while(exit!=1);


	return 0;
}


