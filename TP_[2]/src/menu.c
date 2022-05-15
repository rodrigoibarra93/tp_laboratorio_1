#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "input.h"
/**
 * \fn int menuPrincipal()
 * \brief menu principal
 * \return
 */
int menuPrincipal ()
{
		int rtn;
		system("cls");
		 printf("+------+-------------------+\n");
		 printf("|        PROGRAMA          |\n");
		 printf("+------+-------------------+\n");
		 printf("+------+-------------------+\n");
		 printf("|  1   |     ALTAS         |\n");
		 printf("+------+-------------------+\n");
		 printf("|  2   |     MODIFICAR     |\n");
		 printf("+------+-------------------+\n");
		 printf("|  3   |     BAJA          |\n");
		 printf("+------+-------------------+\n");
		 printf("|  4   |     LISTAR        |\n");
		 printf("+------+-------------------+\n");
		 printf("|  5   |     ALTA FORZADA  |\n");
		 printf("+------+-------------------+\n");
		 printf("|  6   |     SALIR         |\n");
		 printf("+------+-------------------+\n");
		 rtn=pedirEnteroVALIDO("+------->","ingreso ERRONEO\n", 1,6);
		 return rtn;
}


/**
 * \fn int menuModificar()
 * \brief menu para indicar al usuario las opciones a modificar
 * \return
 */
int menuModificar()
{

	int rtn;
	system("cls");
			 printf("+------+----------------------+\n");
			 printf("|Ingrese la Opcion a Modificar|\n");
			 printf("+------+----------------------+\n");
			 printf("+------+----------------------+\n");
			 printf("|  1   |        NOMBRE        |\n");
			 printf("+------+----------------------+\n");
			 printf("|  2   |       APELLIDO       |\n");
			 printf("+------+----------------------+\n");
			 printf("|  3   |        PRECIO        |\n");
			 printf("+------+----------------------+\n");
			 printf("|  4   |   TIPO DE PASAJERO   |\n");
			 printf("+------+----------------------+\n");
			 printf("|  5   |    CODIGO DE VUELO   |\n");
			 printf("+------+----------------------+\n");
			 printf("|  6   |    ESTADO DE VUELO   |\n");
			 printf("+------+----------------------+\n");
			 printf("|  7   |        VOLVER        |\n");
			 printf("+------+----------------------+\n");
			 rtn=pedirEnteroVALIDO("+------->","ingreso ERRONEO\n", 1,7);
	         return rtn;
}
