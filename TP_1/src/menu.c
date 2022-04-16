
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "validaciones.h"
#include "entradaysalida.h"


int Menu(float x, float y, float z){

	int retorno;




	system("cls");

	printf("1. Ingresar Kilometros\n");
	printf("   - Km: %.2f\n\n",x);
	printf("2. Ingresar Precio de Vuelos\n");
	printf("   - Precio vuelo Aerolineas: %.2f\n",y);
	printf("   - Precio vuelo Latam:      %.2f\n\n",z);
	printf("3. Calcular todos los costos\n\n");
	printf("4. Informar Resultados\n\n");
	printf("5. Carga forzada de datos\n\n");
	printf("6. Salir\n\n");

	retorno=pedirInt("ingrese opcion ----> ");



	return retorno;
}


