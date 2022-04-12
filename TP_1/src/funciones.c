/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: patri
 */

#include <stdio.h>
#include <stdlib.h>

void Separador()
{
	printf("\n|-------------------------------------|\n");
}

void Clear()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void Error(char tipoError [], char mensaje [])
{
	printf("|--- ERROR (invalid %s) %s ---|\n\n", tipoError, mensaje);
}

void OpcionElegida(int opcionIngresada)
{
	printf("|---------- OPCION >%d< ----------|\n\n", opcionIngresada);
}

float ValidarNumero(char mensaje [], float numeroMin, float numeroMax)
{
	float kilometrosIngresados;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &kilometrosIngresados);

	while(kilometrosIngresados < numeroMin || kilometrosIngresados > numeroMax)
	{
		Error("number range", "INGRESE UN RANGO NUMERICO VALIDO");
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &kilometrosIngresados);
	}

	return kilometrosIngresados;
}

void SystemPause(char mensaje [])
{
	printf("%s", mensaje);
	system("pause");
	Clear();
}

float CalcularPrecioDebito(float precioBruto)
{
	int descuento;
	float precioDescuento;
	float precioFinal;

	descuento = 10;

	precioDescuento = precioBruto * descuento / 100;

	precioFinal = precioBruto - precioDescuento;

	printf("%f\n%f\n%d\n", precioFinal, precioBruto, descuento);

	return precioFinal;
}


