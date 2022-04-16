
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "validaciones.h"
#include "entradaysalida.h"

int ValidarNumero(int numero, int a, int b){
	 int retorno=0;
	if(numero<a || numero>b)
	{
		retorno=1;
	}
	return retorno;
}
int ValidarNumeroFloat (float numero, int a, int b){
	 int retorno=0;
	if(numero<a || numero>b)
	{
		retorno=1;
	}
	return retorno;
}
