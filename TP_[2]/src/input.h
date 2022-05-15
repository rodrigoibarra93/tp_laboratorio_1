/*
 * input.h
 *
 *  Created on: 13 may. 2022
 *      Author: ibarr
 */

#ifndef INPUT_H_
#define INPUT_H_

int pedirEntero(char mensaje[]);

float pedirFlotante(char mensaje[]);

char pedirCaracter(char mensaje[]);

char pedirCaracterUPPER(char mensaje[]);

int esNumerico(char str[]) ;

int esAlfaNumerico(char str[]);

int esSoloLetras(char str[]);

int esNumericoFlotante(char str[]);

void pedirCadena(char mensaje[],char input[]);

int pedirTexto(char mensaje[],char input[]);

int pedirCadenaNumerica(char mensaje[],char input[]);

int pedirCadenaNumericaFlotante(char mensaje[],char input[]);

int pedirFlotanteVALIDO(char requestMessage[],char errorMessage[], int lowLimit);

int pedirEnteroVALIDO(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

void pedirCadenaVALIDA(char requestMessage[],char errorMessage[], char input[]);

int pedirEnteroPositivoVALIDO(char requestMessage[],char errorMessage[], int lowLimit);

void pedirCadenaMayusculaALFANUVALIDA(char mensaje[],char mensajeERROR[],char input[]);

void clean_stdin(void);

void pause(char message[]);


#endif /* INPUT_H_ */
