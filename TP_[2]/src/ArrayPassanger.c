#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "menu.h"
#include <ctype.h>

static int idIncremental = 1;
static int Passenger_obtenerID();
/**

 * \brief funcion estatica para funcionamiento interno
 * \return devuelve un numero de id unico
 */
static int Passenger_obtenerID()
{
	return idIncremental++;
}



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len)
{
	int rtn=-1;
	int i;

	if (list != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			//INICIALIZO ESTRUCTURA - TRUE 0 - FALSE 1
			(list + i)->isEmpty = TRUE;
		}

		rtn = 0;
	}
	return rtn;
}



/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param flycode[] char
* \param typePassenger int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight)
{
	int i;
	int rtn=-1;
	if (list != NULL && len >= 0)
	{
		for(i=0;i<len; i++)
		{
			if((list+i)->isEmpty == TRUE)
			{
				(list+i)->id=id;
				strcpy((list+i)->name,name);
				strcpy((list+i)->lastName,lastName);
				(list+i)->price=price;
				(list+i)->typePassenger=typePassenger;
				strcpy((list+i)->flycode,flycode);
				(list+i)->statusFlight=statusFlight;
				(list+i)->isEmpty = FALSE;
				rtn=0;
				break;
			}
		}
	}


	return rtn;
}


/**
 * \fn void pedirPasajero(Passenger*)
 * \brief funcion para pedir al usuario datos de tipo de dato Passenger, completa uno solo
 * \param list puntero con la direccion de memoria del array de pasajeros
 */
void pedirPasajero (Passenger* list)
{
	pedirCadenaVALIDA("ingrese el NOMBRE del pasajero: ","ERROR\n",list->name);
	pedirCadenaVALIDA("ingrese el APELLIDO del pasajero: ","ERROR\n",list->lastName);
	list->typePassenger=pedirEnteroVALIDO("ingrese el TIPO DE PASAJERO\n\t1 TURISTA\t2 EJECUTIVO\t3 PRIMERA CLASE\n","ERROR",1,3);
	list->price=pedirFlotanteVALIDO("ingrese el precio del vuelo\n","ERROR\n",0);
	pedirCadenaMayusculaALFANUVALIDA("ingrese codigo del vuelo\n","ERROR\n", list->flycode);
	list->statusFlight=pedirEnteroVALIDO("ingrese el ESTADO DEL VUELO\n\t1 ACTIVO\t2 DEMORADO\t3 CANCELADO\n","ERROR",1,3);
	list->id=Passenger_obtenerID();
}


/**
 * \fn int imprimirPasajeros(Passenger[], int, int)
 * \brief muestra por pantalla un array de pasajeros
 * \param array
 * \param tam
 * \return retorna -1 si error, retorna 0 si ok
 */
int imprimirPasajeros(Passenger array[], int tam) {
	int rtn = -1;
	int i;
	eStatusFlight status[]={{1,"ACTIVO"},{2,"DEMORADO"},{3,"CANCELADO"}};
	etypePassenger tipo[]={{1,"TURISTA"},{2,"EJECUTIVO"},{3,"PRIMERA CLASE"}};
	if (array != NULL && tam >= 0)
	{
		printf("+----------+----------+----------+----------+----------+------------+---------------+\n");
		printf("|ID        |NOMBRE    |APELLIDO  |PRECIO    |FLYCODE   |ESTADO      |CLASE          |\n");
		printf("+----------+----------+----------+----------+----------+------------+---------------+\n");
			for (i = 0; i < tam; i++)
			{
				if(array[i].isEmpty == FALSE)
				{

					printf("|%10d|%10s|%10s|%10.2f|%10s",array[i].id,array[i].name,array[i].lastName,array[i].price,array[i].flycode);

					if(array[i].statusFlight==1)
					{
						printf("|%12s",status[0].status);
					}
					if(array[i].statusFlight==2)
					{
						printf("|%12s",status[1].status);
					}
					if(array[i].statusFlight==3)
					{
						printf("|%12s",status[2].status);
					}


					if(array[i].typePassenger==1)
					{
						printf("|%15s|",tipo[0].clase);
					}
					if(array[i].typePassenger==2)
					{
						printf("|%15s|",tipo[1].clase);
					}
					if(array[i].typePassenger==3)
					{
						printf("|%15s|",tipo[2].clase);
					}
					printf("\n");
				}
			}
			rtn = 0;

	}

	return rtn;
}



/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int i;
	int r=-1;

	for(i=0;i<len;i++)
	{
		if((list+i)->id==id && (list + i)->isEmpty == FALSE)
		{

			r=i;
			return r;
			break;
		}
	}
	return r;
}


/**
 * \fn void modificarPasajero(Passenger[], int)
 * \brief modifica un tipo de dato selecionado por consola
 * \param list array de pasajeros
 * \param tam tamaño del array
 */
void modificarPasajero(Passenger list[],int tam)
{
	int id;
	int r;
	short int exit=0;

	id=pedirEnteroPositivoVALIDO("ingrese numero de id del PASAJERO a MODIFICAR\n","ERROR\n",0);



	r=findPassengerById(list,tam,id);
	if(r!=-1)
	{
			do
			{
					switch(menuModificar())
					{
						case 1:
							pedirCadenaVALIDA("ingrese el NOMBRE del pasajero: ","ERROR\n",list[r].name);
							printf("Se modifico con exito\n");
							system("pause");
							break;
						case 2:
							pedirCadenaVALIDA("ingrese el APELLIDO del pasajero: ","ERROR\n",list[r].lastName);
							printf("Se modifico con exito\n");
							system("pause");
							break;
						case 3:
							list[r].price=pedirFlotanteVALIDO("ingrese el PRECIO del vuelo\n","ERROR\n",0);
							printf("Se modifico con exito\n");
							system("pause");
							break;
						case 4:
							list[r].typePassenger=pedirEnteroVALIDO("ingrese el TIPO DE PASAJERO\n\t1 TURISTA\t2 EJECUTIVO\t3 PRIMERA CLASE\n","ERROR",1,3);
							printf("Se modifico con exito\n");
							system("pause");
							break;
						case 5:
							pedirCadenaMayusculaALFANUVALIDA("ingrese codigo del vuelo\n","ERROR\n", list[r].flycode);
							printf("Se modifico con exito\n");
						    system("pause");
							break;
						case 6:
							list[r].statusFlight=pedirEnteroVALIDO("ingrese el ESTADO DEL VUELO\n\t1 ACTIVO\t2 DEMORADO\t3 CANCELADO\n","ERROR",1,3);
							printf("Se modifico con exito\n");
							system("pause");
							break;
						case 7:
							exit=1;
							break;
					}
			}while(exit!=1);
	}
	else
	{
		printf("No se encontro el Pasajero\n");
		system("pause");
	}


}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int index;
	char rspta;
	short int exit=0;
	int rtn = -1;

	index=findPassengerById(list,len,id);

	if(index!=-1)
	{
		do
		{
			printf("usted esta por dar de baja al PASAJERO con el ID: %d\n",id);
			rspta=pedirCaracterUPPER("\tEsta Usted Seguro? (S/N)");
				if(rspta=='S')
				{
					(list+index)->isEmpty=TRUE;
					exit=1;
					rtn=0;

				}
				else if(rspta=='N')
				{
					exit=1;
				}
				else
				{
					printf("opcion incorrecta\n");
					system("pause");
				}
		}while(exit!=1);
	}

	return rtn;
}


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger list[], int len, int order)
{
	Passenger Aux;
	    int i,j;
	    int rtn=-1;


	   for(i=0;i<len-1;i++)
	   {
		   if(list[i].isEmpty==FALSE)
		   {
			   for(j=i+1;j<len;j++)
			   {
				   if(list[j].isEmpty==FALSE)
				   {
					   if(strcmp(list[i].lastName,list[j].lastName)<order)
					   {
						   Aux=list[i];
						   list[i]=list[j];
						   list[j]=Aux;


					   }
				   }
		   }
	   }


	   }
	   return rtn;
}


/**
 * \fn void calcularPromediosPasajeros(Passenger[], int)
 * \brief calcula el promedio de precio de los boletos e imprime por pantalla los resultados
 *
 * \param list
 * \param tam
 */
void calcularPromediosPasajeros(Passenger list[],int tam)
{
	int contador=0;
	int contadorPasajeros=0;
	float acumulador=0;
	int i;
	float promedio=0;
	for(i=0;i<tam;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
			acumulador=list[i].price+acumulador;
			contador++;
			promedio=acumulador/contador;
		}
	}
	promedio=acumulador/contador;
	for(i=0;i<tam;i++)
	{
		if(list[i].price>promedio && list[i].isEmpty==FALSE)
		{
			contadorPasajeros++;
		}
	}
	printf("\nel precio total es %.2f\nel promedio es %.2f\nLa cantidad de pasajeros que superan el precio promedio son %d\n",acumulador,promedio,contadorPasajeros);
}
