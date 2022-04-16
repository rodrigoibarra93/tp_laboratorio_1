/*
 * calculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: ibarr
 */

#include "calculos.h"

float multiplicar(float a, float b){

	float r=0;
	r=a*b;
	return r;
	}

float multiplicar3(float a, float b,float c){

	float r=0;

	r=multiplicar(a,b)*c;
	return r;
	}

float dividir(float a, float b){
	float r=0;
	r=a/b;
	return r;
}
