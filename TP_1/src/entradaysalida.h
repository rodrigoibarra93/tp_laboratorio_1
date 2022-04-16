/*
 * entradaysalida.h
 *
 *  Created on: 14 abr. 2022
 *      Author: ibarr
 */

#ifndef ENTRADAYSALIDA_H_
#define ENTRADAYSALIDA_H_

float pedirFloatAcotado(char mensaje[], int minimo, int maximo,char mensajeError[]);
float pedirFloat(char mensaje[]);
int pedirInt(char mensaje[]);
void informarResultado(float a,float b,float c,float d,float e,char mensaje[]);

#endif /* ENTRADAYSALIDA_H_ */
