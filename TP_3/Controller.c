#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "input.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int validacion;
	FILE* pFile;

	pFile = fopen(path, "r");

	if (pFile == NULL)
	{
		printf("[ERROR] - NO SE HA PODIDO ABRIR EL ARCHIVO CORRECTAMENTE.");
		exit(1);
	}

	validacion = parser_PassengerFromText(pFile, pArrayListPassenger);

	fclose(pFile);

    return validacion;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int validacion;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if (pFile == NULL)
	{
		printf("[ERROR] - NO SE HA PODIDO ABRIR EL ARCHIVO CORRECTAMENTE.");
		exit(1);
	}

	validacion = parser_PassengerFromBinary(pFile, pArrayListPassenger);

	fclose(pFile);

    return validacion;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int validacion = 0;
	Passenger* this;

	int auxId;
	char auxIdStr[10];
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxPrecioStr[40];
	char auxCodigoVuelo[8];
	int auxTipoPasajero;
	char auxTipoPasajeroStr[30];
	int auxEstadoVuelo;
	char auxEstadoVueloStr[20];

	//-----------------[PEDIR NOMBRE]--------------------
	printf("||----< | [MENU] | >---||\n\n"
			"[1] | Ingrese el [NOMBRE]:\n");

	fflush(stdin);
	gets(auxNombre);

	validacion = validateCharacter(auxNombre);

	while (validacion == 0)
	{
		printf("[1] |[ERROR] -> Ingrese el [NOMBRE]:\n");

		fflush(stdin);
		gets(auxNombre);
	}

	//-----------------[PEDIR APELLIDO]--------------------
	printf("[2] | Ingrese el [APELLIDO]\n");

	fflush(stdin);
	gets(auxApellido);

	validacion = validateCharacter(auxApellido);

	while (validacion == 0)
	{
		printf("[2] |[ERROR] -> Ingrese el [APELLIDO]\n");

		fflush(stdin);
		gets(auxNombre);
	}

	//-----------------[PEDIR PRECIO]--------------------
	auxPrecio = orderFloat("[3] | Ingrese el [PRECIO] | (500 - 100.000)\n");

	while (auxPrecio < 500 || auxPrecio > 100000)
	{
		auxPrecio = orderFloat("[3] |[ERROR] -> Ingrese el [PRECIO] | (500 - 100.000)\n");
	}

	//-----------------[PEDIR CODIGO DE VUELO]--------------------
	printf("[4] | Ingrese el [CODIGO DE VUELO] | (7 Caracteres)");

	fflush(stdin);
	gets(auxCodigoVuelo);
	toMayus(auxCodigoVuelo);

	while (strlen(auxCodigoVuelo) != 7)
	{
		printf("[4] |[ERROR] -> Ingrese el [CODIGO DE VUELO] | (7 Caracteres)");

		fflush(stdin);
		gets(auxCodigoVuelo);
		toMayus(auxCodigoVuelo);
	}

	//-----------------[PEDIR TIPO DE PASAJERO]--------------------
	auxTipoPasajero = orderInteger("[5] | Ingrese el [TIPO DE PASAJERO]\n\n"
									"[1] - FirstClass\n"
									"[2] - ExecutiveClass\n"
									"[3] - EconomyClass");

	while (auxTipoPasajero < 1 || auxTipoPasajero > 3)
	{
		auxTipoPasajero = orderInteger("[5] |[ERROR] -> Ingrese el [TIPO DE PASAJERO]\n\n"
											"[1] - FirstClass\n"
											"[2] - ExecutiveClass\n"
											"[3] - EconomyClass");
	}

	//-----------------[PEDIR ESTADO VUELO]--------------------
	auxEstadoVuelo = orderInteger("[6] | Ingrese el [ESTADO DE VUELO]\n\n"
								"[1] - En Horario\n"
								"[2] - Demorado\n"
								"[3] - Aterrizado");

	while(auxEstadoVuelo < 1 || auxEstadoVuelo > 3)
	{
		auxEstadoVuelo = orderInteger("[6] | Ingrese el [ESTADO DE VUELO]\n\n"
										"[1] - En Horario\n"
										"[2] - Demorado\n"
										"[3] - Aterrizado");
	}

	//-----------------[ELVAUA OPCION ELEGIDA]--------------------
	switch (auxEstadoVuelo)
	{
		case 1:
			strcpy(auxEstadoVueloStr, "En Horario");
		break;

		case 2:
			strcpy(auxEstadoVueloStr, "Demorado");
		break;

		default:
			strcpy(auxEstadoVueloStr, "Aterrizado");
		break;
	}

	auxId = 1001;

	sprintf(auxIdStr, "%d", auxId);
	sprintf(auxPrecioStr, "%f", auxPrecio);
	sprintf(auxTipoPasajeroStr, "%d", auxTipoPasajero);

	this = Passenger_newParametros(auxIdStr, auxNombre, auxApellido, auxPrecioStr, auxTipoPasajeroStr, auxCodigoVuelo, auxEstadoVueloStr);
	if (this != NULL)
	{
		ll_add(pArrayListPassenger, this);
		validacion = 1;
	}
	else
	{
		printf("[ERROR] - NO HAY ESPACIO EN MEMORIA");
		Passenger_delete(this);
	}


    return validacion;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int longitud;
	int i;
	Passenger* this;

	longitud = ll_len(pArrayListPassenger);
	printf("||===========================================================================================================================||\n"
			"||---[ID]---||----[NOMBRE]----||----[APELLIDO]----||--[PRECIO]--||--[CODIGO VUELO]--||--[TIPO PASAJERO]--||--[ESTADO VUELO]--||\n"
			"||===========================================================================================================================||\n");

	for (i = 0; i < longitud; i++)
	{
		this = (Passenger*) ll_get(pArrayListPassenger, i);
		Passenger_list(this);
		printf("||===========================================================================================================================||\n");
	}


    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int validacion = 0;
	int opcion;
	int criterio;

	if (pArrayListPassenger != NULL)
	{
		printf("||----< | [ORDENAR PASAJEROS] | >---||\n\n"

		"[1] | Ordenar por [NOMBRE]\n"
		"[2] | Ordenar por [APELLIDO]\n"
		"[3] | Ordenar por [PRECIO]\n\n"

		"||--->[INGRESAR OPCION]:");

		fflush(stdin);
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				criterio = criterioOrdenamiento();
				ll_sort(pArrayListPassenger, Passenger_compareByName, criterio);
				validacion = 1;
			break;

			case 2:
				criterio = criterioOrdenamiento();
				ll_sort(pArrayListPassenger, Passenger_compareByApellido, criterio);
				validacion = 1;
			break;

			case 3:
				criterio = criterioOrdenamiento();
				ll_sort(pArrayListPassenger, Passenger_compareByPrecio, criterio);
				validacion = 1;
			break;
		}
	}
    return validacion;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int validacion;
	FILE* pFile;

	pFile = fopen(path, "w");

	if (pFile == NULL)
	{
		printf("[ERROR] - NO SE HA PODIDO ABRIR EL ARCHIVO CORRECTAMENTE.");
		exit(1);
	}

	validacion = SaveTxt(pFile, pArrayListPassenger);

	fclose(pFile);

    return validacion;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int validacion;
	FILE* pFile;

	pFile = fopen(path, "wb");

	if (pFile == NULL)
	{
		printf("[ERROR] - NO SE HA PODIDO ABRIR EL ARCHIVO CORRECTAMENTE.");
		exit(1);
	}

	validacion = SaveBinary(pFile, pArrayListPassenger);

	fclose(pFile);

	return validacion;
}


