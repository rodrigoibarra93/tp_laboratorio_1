#include "input.h"


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float pedirFlotante(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int pedirEntero(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario, lo pasa a mayuscula y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char pedirCaracterUPPER(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    auxiliar=toupper(auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char pedirCaracter(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   int rtn=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
    	   rtn=0;
       i++;
   }
   return rtn;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void pedirCadena(char mensaje[],char input[])
{

    printf("%s",mensaje);
    scanf ("%s", input);
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int pedirTexto(char mensaje[],char input[])
{
    char aux[256];
    int i;
    pedirCadena(mensaje,aux);
    if(esSoloLetras(aux))
    {
    	for(i=0;i<256;i++)
    		{
    		aux[i]=tolower(aux[i]);
    		}
    	aux[0]=toupper(aux[0]);
    	strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int pedirCadenaNumerica(char mensaje[],char input[])
{
    char aux[256];
    pedirCadena(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int pedirCadenaNumericaFlotante(char mensaje[],char input[])
{
    char aux[256];
    pedirCadena(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int pedirEnteroPositivoVALIDO(char requestMessage[],char errorMessage[], int lowLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!pedirCadenaNumerica(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit)
        {
            printf ("El numero debe ser mayor a %d\n",lowLimit);
            continue;
        }
        return auxInt;
    }
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int pedirEnteroVALIDO(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!pedirCadenaNumerica(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}


/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int pedirFlotanteVALIDO(char requestMessage[],char errorMessage[], int lowLimit)
{
    char auxStr[256];
    float auxInt;
    while(1)
    {
        if (!pedirCadenaNumericaFlotante(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit)
        {
            printf ("El numero debe ser mayor a %d\n",lowLimit);
            continue;

        }
        return auxInt;
    }
}


/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void pedirCadenaVALIDA(char requestMessage[],char errorMessage[], char input[])
{


    while(1)
    {
        if (!pedirTexto(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        clean_stdin();
        break;
    }

}


/**
 * \brief Solicita un texto al usuario y lo devuelve en mayusculas solo si es ALFANUMERICO
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void pedirCadenaMayusculaALFANUVALIDA(char mensaje[],char mensajeERROR[],char input[])
{
	int len;
	int exit=0;

	do{
		printf("%s",mensaje);
		scanf ("%s", input);

		if(esAlfaNumerico(input)==1)
		{
			len=strlen(input);
			for(int i=0;i<len;i++)
			{
				input[i]=toupper(input[i]);
			}
			exit=1;
		}
		else
		{
			printf(mensajeERROR);
		}
	}while(exit!=1);
}


/**
 * \brief Detiene la ejecucion y muestra un mensaje
 * \param message Mensaje
 * \return -
 *
 */
void pause(char message[])
{
	pedirCaracter(message);
    clean_stdin();
}
